#include "classes.h"

Course::Course(): name(""), ECTS(0), mandatory(0), semester(0){}

Course::Course(const string nam, const int ects, bool mand, const int sem):
 name(nam), ECTS(ects), mandatory(mand), semester(sem){}

Course::Course(const Course& course): 
 name(course.name), ECTS(course.ECTS), mandatory(course.mandatory), semester(course.semester){}

Course::~Course(){}

string Course::get_name() const{
    return name;
}

int Course::get_ECTS() const{
    return ECTS;
}
bool Course::is_mandatory() const{
    return mandatory;
}
int Course::get_semester() const{
    return semester;
}

void Course::set_name(string nam){
    name = nam;
}

void Course::set_ECTS(int ects){
    ECTS = ects;
}
void Course::set_mandatory(bool value){
    mandatory = value;
}
void Course::set_semester(int sem){
    semester = sem;
}

