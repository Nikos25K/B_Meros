#include "classes.h"

Student::Student() : Person("", "", "", 0, ""), AM(0), ECTS(0), semester(0), subjects({}){}

//basic constructor
Student::Student(const string in_name = " ", const string in_surname = " ", const string in_mail = " ", 
const int in_age = 0, const int am = 0, const int ects = 0, const int sem = 0, const map<Course*, double> sub = {}):
Person(in_name, in_surname, in_mail, in_age, true),
AM(am), ECTS(ects), semester(sem), subjects(sub){}

//copy contructor
Student::Student(const Student& student):
Person(student), AM(student.AM), ECTS(student.ECTS), semester(student.semester), subjects(student.subjects) {}

Student::~Student(){}

int Student::get_ECTS() const{
    return ECTS;
}
int Student::get_AM() const{
    return AM;
}
int Student::get_semester() const{
    return semester;
}
map<Course*, double> Student::get_map() const{
    return subjects;
}

void Student::set_ECTS(int ects){
    ECTS = ects;
}
void Student::set_AM(int am){
    AM = am;
}
void Student::set_semester(int sem){
    semester = sem;
}

Student& Student::operator+=(Course* course){
    subjects[course] = 0.0;
    // subjects.insert(make_pair(course,0.0));
    return *this;
}

Student& Student::operator-=(Course* course){
    auto check = subjects.find(course);             //add ECTS
    if (check != subjects.end()) 
        subjects.erase(check);
        
    return *this;
}

double& Student::operator[](Course* course){           //check if new???
    if (subjects.find(course) == subjects.end()) {
        subjects[course] = 0.0;
    }
    return subjects[course];
}

bool Student::gets_degree() const{

    if(ECTS < 240 || semester < 8)
        return false;

    for (auto it = subjects.begin(); it != subjects.end(); ++it) {
        Course* course = it->first;
        double grade = it->second;
        if(course->is_mandatory() && grade < 5)
            return false;
    }

    return true;
}
