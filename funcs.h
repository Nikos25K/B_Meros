#ifndef FUNCS_H
#define FUNCS_H

#include "classes.h"

inline void check_lines(int count,int temp_count);
inline void check_open(ifstream& fin);
inline int count_lines(string name);
inline void check_num(int choice, int low, int upp);
bool check_resp(bool numeric);
inline void check_ptr(void* ptr);

Person* get_person(Secretary& sec, string name, string surname);
Course* read_course(Secretary& sec);
void add_courses(Secretary& sec, Person& per);
void delete_courses(Secretary& sec, Person& per);
void edit_person(Secretary& sec, Person& per, bool mail, bool age, int courses);
void create_person(Secretary& sec, bool flag, string name, string surname);
void edit_course(Secretary& sec, Course& course, bool name, bool ects, 
bool mand, bool sem, bool people, bool passed, bool failed);
void create_course(Secretary& sec);

#endif