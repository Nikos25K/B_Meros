#include "classes.h"

Course::Course(): name(""), ECTS(0), mandatory(0), semester(0),
people({}), passed(0), failed(0) {}

Course::Course(const string nam="", const int ects=0, bool mand=0, const int sem=0,
const vector<Person*> in_people={}, const int in_passed=0, const int in_failed=0):
name(nam), ECTS(ects), mandatory(mand), semester(sem),
people(in_people), passed(in_passed), failed(in_failed) {}

//constructor based on Course*
Course::Course(const Course *ptr) :name(ptr->get_name()), ECTS(ptr->get_ECTS()), mandatory(ptr->is_mandatory()),
semester(ptr->get_semester()), people(ptr->get_people()),  passed(ptr->get_passed()), failed(ptr->get_failed()) {}

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

vector<Person*> Course::get_people() const{
    return people;
}

int Course::get_passed() const{
    return passed;
}

int Course::get_failed() const{
    return failed;
}


void Course::set_name(string nam=""){
    name = nam;
}
void Course::set_ECTS(int ects=0){
    ECTS = ects;
}
void Course::set_mandatory(bool value=0){
    mandatory = value;
}
void Course::set_semester(int sem=0){
    semester = sem;
}
void Course::set_professors(vector<Professor*> in_profs){
    for(Professor* prof_ptr : in_profs)
        people.push_back(prof_ptr);
}
void Course::incr_passed(void){
    passed++;
}
void Course::incr_failed(void){
    failed++;
}

Course& Course::operator+=(const Student* in_student){
    people.push_back(new Student(*in_student));
    return *this;
}

Course& Course::operator+=(const Professor* prof){
    people.push_back(new Professor(*prof));
    return *this;
}
