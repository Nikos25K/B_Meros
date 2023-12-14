#include "classes.h"

//Student functions
Student::Student() : AM(0), ECTS(0){}

Student::Student(const int am, const float ects, const string in_name, const string mail, const int in_age, const vector<string> in_subjects) :Person(in_name, mail, in_age, vector<string> in_subjects) {
    AM = am;
    ECTS = ects;
}

Student::Student(const Student& student){
    AM = student.AM;
    ECTS = student.ECTS;
}

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