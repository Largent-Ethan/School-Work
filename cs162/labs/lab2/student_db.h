#ifndef STUDENT_DB_H
#define STUDENT_DB_H

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

struct student{
    int student_id;
    string first_name;
    string last_name;
    string major;
} ;

student* create_student_db(int); 

void get_student_db_info(student*, int, ifstream&);

void append_to_file(student*, int, ofstream&);

void swap_students(student*, int, int);

void sort_by_id(student*, int);

void sort_by_last_name(student*, int);

void delete_student_db_info(student*); 

#endif