#include "classes.h"

Professor::Professor(const string in_name="", const string in_surname="", const string in_mail="",
const int in_age=0, const vector<Course*> in_courses={}):
Person(in_name, in_surname, in_mail, in_age), courses(in_courses){}

Professor::Professor(): Person() {}

Professor::Professor(const Professor& prof) : Person(prof), courses(prof.get_courses()) {}

Professor::~Professor() {}

vector<Course*> Professor::get_courses() const{
    return courses;
}

Professor& Professor::operator+=(const Course* course){
    courses.push_back(new Course(*course));
    return *this;
}