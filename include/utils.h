#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <new>
#include <iomanip>

#define MIN_SEMS 8
#define MIN_ECSTS 240

using namespace std;

int count_lines(string name);   //opens file and counts lines

bool check_resp(bool numeric);  //numeric->0: expects answer y/n else expects 0/1

class Course;
class Person;
class Secretary;
class Student;
class Professor;

class Err_Rpt{      //class for exceptions
    public:
        string msg;
        string file_name;
        string line;
        Err_Rpt(string in_msg, string in_file_name, string in_line):
        msg(in_msg),file_name(in_file_name),line(in_line){}
};

#endif