/******************************************************************************
 * Assignment: Assignment 3: smallsh
 * Name: Ethan Largent
 * Class: Operating Systems 1 with Benjamin Brewster
 * Due date: 11/7/2022
 * Description: A small shell script that opperates similar to the linux terminal
 * 
 * ASSIGNMENT CHECKLIST
 * X - Command Prompt
 * X - Comments and Blank Lines
 * X - Expansion of Variable $$
 * X - Built-in Command exit
 * X - Built-in Command cd
 * X - Built-in Command status
 * X - Executing Other Commands (fork,exec,waitpid)
 * X - Input and Output Redirection
 * X - Foreground Commands
 * X - Background Commands
 * X - Signal SIGINT
 * X - Singal SIGTSTP
******************************************************************************/
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

int fg_process = 0;

/*****************************************
 * Parses user input into arguments and checks for input/output redirection and background processing
*****************************************/
void parse_line(char *line, char *pid, char *args[], char *in, char *out, int *backgrnd) {
    int arg_ct = 0;
    const char lastchar = line[strlen(line) - 2];
    char *ptr;
    char* item = strtok(line, " \n");
    while(item != NULL) {
        switch(*item) {
            //Check for input redirection
            case '<':
                item = strtok(NULL, " \n");
                strcpy(in, item);
                break;
            //Check for output redirection
            case '>':
                item = strtok(NULL, " \n");
                strcpy(out, item);
                break;
            //Check for background processing
            case '&':
                if(*item == lastchar)
                    *backgrnd = 1;
                break;
            //Otherwise, save value as an argument
            default:
                //Check for pid expansion variable
                if(strstr(item, "$$")) {
                    ptr = strstr(item, "$$");
                    *ptr = '%';
                    ptr++;
                    *ptr = 'd';
                    sprintf(pid, item, getpid());
                    args[arg_ct++] = pid;
                }
                //Add argument
                else
                    args[arg_ct++] = item;
        }
        item = strtok(NULL, " \n");
    }
    return;
}

/*****************************************
 * Changes working directory
*****************************************/
void smallsh_cd(char **args) {   
    if(args[1] != NULL)
        chdir(args[1]);
    else
        chdir(getenv("HOME"));
    return;
}

/*****************************************
 * Display that exit status of the process
*****************************************/
void smallsh_status(int exit_status) {
    if(WIFEXITED(exit_status)) {
        printf("exit value %d\n", WEXITSTATUS(exit_status));
        fflush(stdout);
    } else{
        printf("terminated by signal %d\n", WTERMSIG(exit_status));
        fflush(stdout);
    }
    return;
}

/*****************************************
 * Displays the exit status of all child processes
*****************************************/
void check_background() {
    int signal;
    pid_t cpid = waitpid(-1, &signal, WNOHANG);
    while(cpid > 0) {
        smallsh_status(signal);
        cpid = waitpid(-1, &signal, WNOHANG);
    }
    return;
}

/*****************************************
 * Toggles foreground only mode
*****************************************/
void catchSIGTSTP(int signo) {
    char *foreground_on = "\nEntering foreground-only mode (& is now ignored)\n";
    char *foreground_off = "\nExiting foreground-only mode\n";
    //Turn foreground only mode on
    if(fg_process == 0) {
        write(STDOUT_FILENO, foreground_on, 50);
        fflush(stdout);
        fg_process = 1;
    //Turn foreground only mode off
    } else{
        write(STDOUT_FILENO, foreground_off, 30);
        fflush(stdout);
        fg_process = 0;
    }
}


/*****************************************
 * Display a command line prompt to the user and checks if the comment is entered
*****************************************/
int cmdprompt(char *line) {
    printf(" : ");
    fflush(stdout);
    line[0] = '\0';
    fgets(line, 2048, stdin);
    //Check for comment
    if(line[0] == '#' || line[0] == '\n' || line[0] == '\0')
        return 0;
    else return 1;
}

int main() {
    //Defining and setting variables for handling signals
    struct sigaction SIGINT_action = {0}, SIGTSTP_action = {0};
    SIGINT_action.sa_handler = SIG_IGN;
    sigfillset(&SIGINT_action.sa_mask);
    SIGINT_action.sa_flags = 0;
    sigaction(SIGINT, &SIGINT_action, NULL);
    SIGTSTP_action.sa_handler = catchSIGTSTP;
    sigfillset(&SIGTSTP_action.sa_mask);
    SIGTSTP_action.sa_flags = 0;
    sigaction(SIGTSTP, &SIGTSTP_action, NULL);
    sigset_t signals;
    sigemptyset(&signals);
    sigaddset(&signals, SIGTSTP);
    //Defining and setting variables for dealing with commands
    char *user_input = malloc(sizeof(char) * 2048);
    char *pid = malloc(sizeof(char) * 10);
    char *args[512];
    char in_file[2048], out_file[2048];
    int infile = -1, outfile = -1, devnull = -1;
    int exit_status, exit_shell = 0;
    int run_in_backgrnd, valid = 0, result, i;
    pid_t cpid, exit_pid;
    //Running the shell script
    while(!exit_shell) {
        //Get user input
        while(!valid)
            valid = cmdprompt(user_input);
        //Clear input values
        memset(in_file, '\0', sizeof(in_file));
        memset(out_file, '\0', sizeof(out_file));
        for(i = 0; i < 512; i++) {
            args[i] = NULL;
        }
        //Process input
        parse_line(user_input, pid, args, in_file, out_file, &run_in_backgrnd);
        //Run command
        if(strcmp(args[0], "status") == 0)   
            smallsh_status(exit_status);
        else if(strcmp(args[0], "cd") == 0)
            smallsh_cd(args);
        else if(strcmp(args[0], "exit") == 0)
            exit_shell = 1;
        else {
            cpid = fork();
            switch(cpid) {
                //Good fork
                case 0:
                    SIGTSTP_action.sa_handler = SIG_IGN;
                    sigaction(SIGTSTP, &SIGTSTP_action, NULL);
                    //Foreground process handling
                    if(run_in_backgrnd == 0 || fg_process == 1) {
                        SIGINT_action.sa_handler = SIG_DFL;
                        sigaction(SIGINT, &SIGINT_action, NULL);
                    }
                    //Input file handling
                    if(strcmp(in_file, "") != 0 && in_file != NULL) {
                        infile = open(in_file, O_RDONLY);
                        if(infile == -1)
                            exit(1);
                        result =  dup2(infile, 0);
                        if(result == -1)
                            exit(2);
                        close(infile);
                    } else if(run_in_backgrnd == 1 && fg_process == 0) {
                        devnull = open("/dev/null", O_WRONLY);
                        if(devnull == -1)
                            exit(1);
                        result = dup2(devnull, 0);
                        if(result == -1)
                            exit(2);
                    }
                    //Output file handling
                    if(strcmp(out_file, "") != 0 && out_file != NULL) {
                        outfile = open(out_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
                        if(outfile == -1)
                            exit(1);
                        result = dup2(outfile, 1);
                        if(result == -1)
                            exit(2);
                        close(outfile);
                    } else if(run_in_backgrnd == 1 && fg_process == 0) {
                        devnull = open("/dev/null", O_WRONLY);
                        if(devnull == -1)
                            exit(1);
                        result = dup2(devnull, 1);
                        if(result == -1)
                            exit(2);
                    }
                    //Command execution
                    execvp(args[0], args);
                    perror(args[0]);
                    exit(1);
                    break;
                //Bad fork
                case -1:
                    exit(1);
                    break;
                //Foreground/Background handling
                default:
                    //Print background pid
                    if(run_in_backgrnd == 1 && fg_process == 0) {
                        printf("background process id is: %d\n", cpid);
                        fflush(stdout);
                    // Wait for froeground processes
                    } else {
                        sigprocmask(SIG_BLOCK, &signals, NULL);
                        exit_pid = waitpid(cpid, &exit_status, 0);
                        if(exit_pid > 0 && WIFSIGNALED(exit_status)) {
                            printf("Terminated by signal %d\n", WTERMSIG(exit_status));
                            fflush(stdout);
                        }
                    }
                    sigprocmask(SIG_UNBLOCK, &signals, NULL);
            }
        }
        valid = 0;
        run_in_backgrnd = 0;
        check_background();
    }
    //Free memory
    free(user_input);
    free(pid);
    
    return 0;
}