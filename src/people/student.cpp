#include "people.h"
#include "sec_course.h"

Student::Student() : Person("", "", "", 0, ""), AM(0), ECTS(0), semester(0), subjects({}){}

//basic constructor
Student::Student( map<Course*, double> &sub, const string in_name = " ", const string in_surname = " ", const string in_mail = " ", 
const int in_age = 0, const int am = 0, const int ects = 0, const int sem = 0):
Person(in_name, in_surname, in_mail, in_age, true),
AM(am), ECTS(ects), semester(sem), subjects(sub) {}

//copy contructor
Student::Student(Student& student):
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
map<Course*, double> Student::get_map(){
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
    subjects.insert(make_pair(course,0.0));
    return *this;
}

Student& Student::operator-=(Course* course){
    map<Course*, double>::iterator check;
    check = subjects.find(course);
    if (check == subjects.end())
        throw Err_Rpt("Course not found\n","student.cpp","50");

    subjects.erase(check);
    return *this;
}

double& Student::operator[](Course* course){
    if (subjects.find(course) == subjects.end()) {      //creates
        subjects[course] = 0.0;
    }
    return subjects[course];
}

bool Student::gets_degree(vector<Course*> mand_courses){

    if(ECTS < MIN_ECSTS || semester < MIN_SEMS)
        return false;

    for(Course* course: mand_courses)
        if(!this->passed_course(course))
            return false;

    return true;
}

bool Student::passed_course(Course* course){
    auto check = subjects.find(course);
    if (check == subjects.end())
        return false;

    return subjects[course] >= 5 ? true : false;
}

double Student::course_grade(Course* course){
    auto check = subjects.find(course);
    if (check == subjects.end())
        throw Err_Rpt("Course not found\n","student.cpp","86");
    return subjects[course];
}

void Student::edit(bool in_name=0, bool in_surname=0, bool in_mail=0, bool in_age=0, 
bool in_am=0, bool in_ects=0, bool in_sem=0){
    Person::edit(in_name,in_surname,in_mail,in_age);
    if(in_am){
        int in;
        cout<<"Give the new AM: ";
        cin>>in;
        set_AM(in);
    }
    if(in_ects){
        int in;
        cout<<"Give the new ects: ";
        cin>>in;
        set_ECTS(in);
    }
    if(in_sem){
        int in;
        cout<<"Give the new semester: ";
        cin>>in;
        set_semester(in);
    }
}

Student* Student::clone(){
    Student* st;
    try{
        st =  new Student(*this);
    }
    catch(bad_alloc& e){
        throw;
    }
    return st;
}

ofstream& operator<<(ofstream& ofs, const Student& student){
    ofs<<student.name << " "<< student.surname <<" "<<student.AM<< " ";
    return ofs;
}

ostream& operator<<(ostream& os, const Student& student){
    os<<student.name << " "<< student.surname <<" "<<student.AM<< " ";
    return os;
}