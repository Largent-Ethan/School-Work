#include "./student_db.h"

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

student* create_student_db(int num){
    student* student_list = new student[num];
    return student_list;
}

void get_student_db_info(student* list, int num, ifstream& input){
    for(int i = 0; i < num; i++){
        input >> list[i].student_id;
        input >> list[i].first_name;
        input >> list[i].last_name;
        input >> list[i].major;
    }
}

void append_to_file(student* list, int num, ofstream& output){
    for(int i = 0; i < num; i++){
        output << list[i].student_id << ' ';
        output << list[i].first_name << ' ';
        output << list[i].last_name << ' ';
        output << list[i].major << '\n';
    }
    output << "\n";
}

void swap_students(student* list, int num1, int num2){
    student unsorted_student;
    unsorted_student = list[num1];
    list[num1] = list[num2];
    list[num2] = unsorted_student;
}

void sort_by_id(student* list, int num){
    bool unsorted = true;
    while(unsorted == true){
        unsorted = false;
        for(int i = 0; i < num - 1; i++)
            if(list[i].student_id > list[i + 1].student_id){
                unsorted = true;
                swap_students(list, i, i + 1);
            }
    }
}

void sort_by_last_name(student* list, int num){
    bool unsorted = true;
    while(unsorted == true){
        unsorted = false;
        for(int i = 0; i < num - 1; i++)
            if(list[i].last_name > list[i + 1].last_name){
                unsorted = true;
                swap_students(list, i, i + 1);
            }
    }
}

void delete_student_db_info(student* list){
    delete[] list;
}