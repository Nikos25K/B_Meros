#include "classes.h"

Professor::Professor(): Person() {}

Professor::Professor(const string in_name="", const string in_surname="", const string in_mail="",
const int in_age=0, vector<Course*> in_courses={}):
Person(in_name, in_surname, in_mail, in_age, false), courses(in_courses){}

Professor::Professor(Professor& prof) : Person(prof), courses(prof.get_courses()) {}

Professor::~Professor() {}

vector<Course*> Professor::get_courses(){
    return courses;
}

Professor& Professor::operator+=(Course* course){
    courses.push_back(new Course(*course));
    return *this;
}

Professor& Professor::operator-=(Course* course) {
    auto check = find(courses.begin(), courses.end(), course);
    if (check != courses.end()) 
        courses.erase(check);
        
    return *this;
}

void Professor::edit(bool mail=0, bool age=0){
    if(mail){
        string in_mail;
        cout<<"Give the new mail"<<endl;
        cin>>in_mail;
        per.set_mail(in_mail);
    }
    if(age){
        int in_age;
        cout<<"Give the new age"<<endl;
        cin>>in_age;
        check_num(in_age,18,80);
        per.set_age(in_age);
    }
}