#ifndef FUNCS_H
#define FUNCS_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void check_lines(int count,int temp_count);
void check_open(ifstream& fin);
void check_open(ofstream& fin);
int count_lines(string name);
void check_num(int choice, int low, int upp);
bool check_resp(bool numeric);
void check_ptr(void* ptr);

// class Person;
// class Course;
// class Secretary;

// Person* get_person(Secretary& sec, string name, string surname);
// Course* read_course(Secretary& sec, string cour);
// void add_courses(Secretary& sec, string name, string surname);
// void delete_courses(Secretary& sec, string name, string surname);
// void create_person(Secretary& sec, bool flag, string name, string surname);
// void create_course(Secretary& sec);

#endif