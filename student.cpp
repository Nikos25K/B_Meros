#include "classes.h"

Student::Student() : Person("", "", "", 0, ""), AM(0), ECTS(0), semester(0), subjects({}){}

//basic constructor
Student::Student(const string in_name = " ", const string in_surname = " ", const string in_mail = " ", 
const int in_age = 0, const string in_type = " ", const int am = 0, const int ects = 0, const int sem = 0, const map<Course*, int> sub = {}):
Person(in_name, in_surname, in_mail, in_age, in_type),
AM(am), ECTS(ects), semester(sem), subjects(sub){}

//copy contructor
Student::Student(const Student& student):
Person(student), AM(student.AM), ECTS(student.ECTS), semester(student.semester), subjects(student.subjects) {}

Student::~Student(){}

int Student::get_ECTS() const{
    return ECTS;
}
int Student::get_AM() const{
    return AM;
}
int Student::get_semester() const{
    return semester;
}

void Student::set_ECTS(int ects){
    ECTS = ects;
}
void Student::set_AM(int am){
    AM = am;
}
void Student::set_semester(int sem){
    semester = sem;
}
