#include "classes.h"

Student::Student() : Person("","","",0,{}), AM(0), ECTS(0){}

//basic constructor
Student::Student(const int am, const float ects, const string in_name, const string in_surname,
const string in_mail, const int in_age, const vector<string> in_subjects):
Person(in_name, in_surname, in_mail, in_age, in_subjects),
AM(am), ECTS(ects) {}

//copy contructor
Student::Student(const Student& student):
Person(student), AM(student.AM), ECTS(student.ECTS) {}

Student::~Student(){}

void Student::set_AM(int am){
    AM = am;
}

void Student::set_ECTS(float ects){
    ECTS = ects;
}

int Student::get_AM() const{
    return AM;
}
float Student::get_ECTS() const{
    return ECTS;
}