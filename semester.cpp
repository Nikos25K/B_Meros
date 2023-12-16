#include "classes.h"

Semester::Semester(): cources({}) {}

Semester::Semester(const vector<Course*> courses): cources(cources) {}

Semester::~Semester() {}

vector<Course*> Semester::get_cources() const{
    return cources;
}

Semester& Semester::operator+=(const Course* course){
    cources.push_back(new Cource(*cource))
}