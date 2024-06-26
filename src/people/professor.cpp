#include "people.h"
#include "sec_course.h"

Professor::Professor(): Person() {}

Professor::Professor(const string in_name="", const string in_surname="", const string in_mail="",
const int in_age=0):
Person(in_name, in_surname, in_mail, in_age, false) {}

Professor::Professor(Professor& prof) : Person(prof), courses(prof.get_courses()) {}

Professor::~Professor() {}

vector<Course*> Professor::get_courses(){
    return courses;
}

Professor& Professor::operator+=(Course* course){
    courses.push_back(course);
    return *this;
}

Professor& Professor::operator-=(Course* course) {
    vector<Course*>::iterator check;
    check = find(courses.begin(), courses.end(), course);
    if (check == courses.end())
        throw Err_Rpt("Course not found\n","professor.cpp","27");

    courses.erase(check);
    return *this;
}

Professor* Professor::clone(){
    Professor* pr;
    try{
        pr = new Professor(*this);
    }
    catch(bad_alloc& e){
        throw;
    }    
    return pr;
}