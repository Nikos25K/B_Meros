#include "classes.h"

Semester::Semester(): courses({}) {}

Semester::Semester(const vector<Course*> courses): courses(courses) {}

Semester::~Semester() {}

vector<Course*> Semester::get_courses() const{
    return courses;
}

Semester& Semester::operator+=(const Course* course){
    courses.push_back(new Course(*course));
    return *this;
}