#include "library_organizer_imp.h"


#include <fstream>
#include <string>
#include <iostream>

using namespace std;

spellbook* create_spellbooks(int num){
    spellbook* spellbook_list = new spellbook[num];
    return spellbook_list;
}

void get_spellbook_data(spellbook* library, int num, ifstream& input){
    for(int i = 0; i < num; i++){
        input >> library[i].title;
        input >> library[i].author;
        input >> library[i].num_pages;
        input >> library[i].edition;
        input >> library[i].num_spells;
        int num_spells = library[i].num_spells;
        library[i].s = create_spells(num_spells);
        get_spell_data(library[i].s, num_spells, input);
        library[i].avg_success_rate = get_average(library[i].s, num_spells);
    }
}

spell* create_spells(int num){
    spell* spell_list = new spell[num];
    return spell_list;
}

void get_spell_data(spell* book, int num, ifstream& input){
    for(int i = 0; i < num; i++){
        input >> book[i].name;
        input >> book[i].success_rate;
        input >> book[i].effect;
    }
}

float get_average(spell* book, int num){
    float avg_num = 0.00;
    for(int i = 0; i < num; i++){
        avg_num += (book[i].success_rate / num);
    }
    avg_num = avg_num * 100 + 0.5;
    int rounded_num = int(avg_num);
    return rounded_num / 100.00;
}

string pick_operation(){
    string input = "0";
    do{
        cout << "Which option would you like to choose?\n\tSort spellbooks by number of pages (Press 1)\n\tGroup spells by their effect (Press 2)\n\tSort spellbooks by average success rate (Press 3)\n\tQuit (Press 4)" << endl;
        cin >> input;
        if(!(input == "1" || input == "2" || input == "3" || input == "4"))
            cout << "\nError | Must be a number between 1 and 4\n" << endl;
    }while(!(input == "1" || input == "2" || input == "3" || input == "4"));
    return input;
}

void swap_spellbooks(spellbook* library, int num1, int num2){
    spellbook unsorted_spellbook;
    unsorted_spellbook = library[num1];
    library[num1] = library[num2];
    library[num2] = unsorted_spellbook;
}

void sort_by_pages(spellbook* library, int num){
    bool unsorted = true;
    while(unsorted == true){
        unsorted = false;
        for(int i = 0; i < num - 1; i++)
            if(library[i].num_pages > library[i + 1].num_pages){
                unsorted = true;
                swap_spellbooks(library, i, i + 1);
            }
    }
}

string string_of_pages(spellbook* library, int num){
    string output;
    for(int i = 0; i < num; i++){
        output += library[i].title;
        output += " ";
        int pages = library[i].num_pages;
        output += to_string(pages);
        output += "\n";
    }
    return output;
}

void sort_by_effect(string* output, string name, string effect){
    *output += effect;
    *output += " ";
    *output += name;
    *output += "\n";
}

string string_of_effects(spellbook* library, int num){
    string output;
    for(int k = 0; k < 5; k++)
        for(int i = 0; i < num; i++){
            int num_spells = library[i].num_spells;
            for(int j = 0; j < num_spells; j++){
                if(k == 0 && library[i].s[j].effect == "bubble")
                    sort_by_effect(&output, library[i].s[j].name, library[i].s[j].effect);
                if(k == 1 && library[i].s[j].effect == "death")
                    sort_by_effect(&output, library[i].s[j].name, library[i].s[j].effect);
                if(k == 2 && library[i].s[j].effect == "fire")
                    sort_by_effect(&output, library[i].s[j].name, library[i].s[j].effect);
                if(k == 3 && library[i].s[j].effect == "memory_loss")
                    sort_by_effect(&output, library[i].s[j].name, library[i].s[j].effect);
                if(k == 4 && library[i].s[j].effect == "poison")
                    sort_by_effect(&output, library[i].s[j].name, library[i].s[j].effect);
            }
        }
    return output;
}

void sort_avg_success_rate(spellbook* library, int num){
    bool unsorted = true;
    while(unsorted == true){
        unsorted = false;
        for(int i = 0; i < num - 1; i++)
            if(library[i].avg_success_rate < library[i + 1].avg_success_rate){
                unsorted = true;
                swap_spellbooks(library, i, i + 1);
            }
    }
}

string string_of_avg_success_rate(spellbook* library, int num){
    string output;
    for(int i = 0; i < num; i++){
        output += library[i].title;
        output += " ";
        float asr = library[i].avg_success_rate;
        output += to_string(asr);
        output += "\n";
    }
    return output;
}

string pick_ouput(){
    string input = "0";
    do{
        cout << "How would you like the information displayed?\n\tPrint to screen (Press 1)\n\tPrint to file (Press 2)\n- file will be cleared -" << endl;
        cin >> input;
        if(!(input == "1" || input == "2"))
            cout << "\nError | Must be a number between 1 and 2\n" << endl;
    }while(!(input == "1" || input == "2"));
    return input;
}

void output_to_terminal(string results){
    cout << results;
}

bool output_to_file(string results){
    char file_name[50];
    cout << "Please provide desired filename: ";
    cin >> file_name;
    ofstream output(file_name, ios::out);
    if(output.fail()){
        cout << "\nError | File does not exist\n" << endl;
        return false;
    }
    output << results;
    return true;
}

void delete_spellbook_data(spellbook* library, int num){
    for(int i = 0; i < num; i++)
        delete[] library[i].s;
    delete[] library;
}