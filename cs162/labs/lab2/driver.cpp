#include "./student_db.h"

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main(){
    ifstream unsorted_list("inputs.txt", ios::in);
    ofstream sorted_list("outputs.txt", ios::out);

    int num;
    unsorted_list >> num;
    student* student_list = create_student_db(num);
    get_student_db_info(student_list, num, unsorted_list);

    sort_by_id(student_list, num);
    append_to_file(student_list, num, sorted_list);

    sort_by_last_name(student_list, num);
    append_to_file(student_list, num, sorted_list);

    delete_student_db_info(student_list);
    return 0;
}