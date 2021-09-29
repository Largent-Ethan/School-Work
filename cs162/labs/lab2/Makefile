CC = g++
exe_file = student_db
$(exe_file): student_db.o driver.o
    $(CC) student_db.o driver.o -o $(exe_file)
student_db.o: student_db.cpp
    $(CC) -c student_db.cpp
driver.o: driver.cpp
    $(CC) -c driver.cpp