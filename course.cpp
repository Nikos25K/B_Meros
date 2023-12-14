#include "classes.h"

Course::Course() : ECTS(0), mandatory(0), semester(0){}

Course::Course(const int ects, bool mand, const int sem):
ECTS(ects), mandatory(mand), semester(sem){}

Course::Course(const Course& course): 
ECTS(course.ECTS), mandatory(course.mandatory), semester(course.semester){}

Course::~Course(){}

int Course::get_ECTS() const{
    return ECTS;
}
bool Course::is_mandatory() const{
    return mandatory;
}
int Course::get_semester() const{
    return semester;
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

