#include "people.h"
#include "sec_course.h"

Course::Course(): name(""), ECTS(0), mandatory(0), semester(0),
people({}), passed(0), failed(0) {}

Course::Course(const string nam="", const int ects=0, bool mand=0, const int sem=0, 
const int in_passed=0, const int in_failed=0):
name(nam), ECTS(ects), mandatory(mand), semester(sem),
passed(in_passed), failed(in_failed) {}

//constructor based on Course*
Course::Course(Course *ptr) :name(ptr->get_name()), ECTS(ptr->get_ECTS()), mandatory(ptr->is_mandatory()),
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

vector<Person*> Course::get_people(){
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
void Course::set_passed(int pass=0){
    passed = pass;
}
void Course::set_failed(int fail=0){
    failed = fail;
}

void Course::set_professors(vector<Professor*> in_profs){
    for(Professor* prof_ptr : in_profs)
        people.push_back(prof_ptr);
}

double Course::get_avg_grade(){
    double sum=0.0;
    int count=0;
    for(Person* per: people){
        if(!per->get_type())     //Students only
            continue;
        count++;
        Student* student;
        student = dynamic_cast<Student*>(per);
        if(!student)
            throw Err_Rpt("Error casting to student\n","course.cpp","78");
        sum += student->course_grade(this);
    }
    if(count)
        return sum/count;
    return 0.0;
}

Course& Course::operator+=(Person* per){
    people.push_back(per);
    return *this;
}

Course& Course::operator-=(Person* per){
    vector<Person*>::iterator check;
    check = find(people.begin(), people.end(), per);
    if (check == people.end())
        throw Err_Rpt("Person not found\n","course.cpp","95");
    this->people.erase(check);
    return *this;
}

void Course::edit(bool name=0, bool ects=0, bool mand=0,
bool sem=0, bool passed=0, bool failed=0){
    if(name){
        string in_name;
        cout<<"Give the new name"<<endl;
        cin>>in_name;
        set_name(in_name);
    }
    if(ects){
        int in_ects;
        cout<<"Give the new ects"<<endl;
        cin>>in_ects;
        set_ECTS(in_ects);
    }
    if(mand){
        cout<<"Is it mandatory? (y/n)"<<endl;
        bool mand = check_resp(0);
        set_mandatory(mand);
    }
    if(sem){
        int in_sem;
        cout<<"Give the new semester"<<endl;
        cin>>in_sem;
        set_semester(in_sem);
    }
    if(passed){
        int in_passed;
        cout<<"Give people that passed"<<endl;
        cin>>in_passed;
        set_passed(in_passed);
    }
    if(failed){
        int in_failed;
        cout<<"Give people that failed"<<endl;
        cin>>in_failed;
        set_failed(in_failed);
    }
}

ofstream& operator<<(ofstream& ofs, const Course& course){
    ofs << setw(30) << course.get_name();
    ofs << setw(10) << course.get_ECTS();
    ofs << setw(15) << (course.is_mandatory() ? "Yes" : "No");
    ofs << setw(10) << course.get_semester() << endl;    
    return ofs;
}