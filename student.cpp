#include "classes.h"

Student::Student() : Person("","","",0), AM(0), ECTS(0){}

//basic constructor
Student::Student(const int am, const int ects, const string in_name, const string in_surname,
const string in_mail, const int in_age):
Person(in_name, in_surname, in_mail, in_age),
AM(am), ECTS(ects) {}

//copy contructor
Student::Student(const Student& student):
Person(student), AM(student.AM), ECTS(student.ECTS) {}

Student::~Student(){}

void Student::set_AM(int am){
    AM = am;
}

void Student::set_ECTS(int ects){
    ECTS = ects;
}

int Student::get_AM() const{
    return AM;
}
int Student::get_ECTS() const{
    return ECTS;
}