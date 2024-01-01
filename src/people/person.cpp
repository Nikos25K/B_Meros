#include "people.h"
#include "sec_course.h"

int Person::count = 0;

Person::Person() : name(""), surname(""), mail(""), age(0), type(false){
    count++;
}

//constructor based on Person*
Person::Person(Person *ptr) :name(ptr->get_name()), surname(ptr->get_surname()), mail(ptr->get_mail()),
age(ptr->get_age()), type(ptr->get_type()){
    count++;
}

//basic constructor
Person::Person(const string in_name, const string in_surname, const string in_mail,
const int in_age, const bool in_type):
name(in_name), surname(in_surname), mail(in_mail), age(in_age), type(in_type){
    count++;
}

//copy contructor
Person::Person(Person& person):
name(person.name), surname(person.surname), mail(person.mail), 
age(person.age), type(person.type){
    count++;
}

Person::~Person(){
    count--;
}

string Person::get_name() const{
    return name;
}

string Person::get_surname() const{
    return surname;
}

string Person::get_mail() const{
    return mail;
}

int Person::get_age() const{
    return age;
}

bool Person::get_type() const{
    return type;
}

void Person::set_name(string in_name){
    name = in_name;
}
void Person::set_surname(string in_surname){
    surname = in_surname;
}
void Person::set_mail(string in_mail){
    mail = in_mail;
}
void Person::set_age(int in_age){
    if(in_age < 18 || in_age > 80)
        throw Err_Rpt("Error: Invalid age\n","person.cpp","65");
    age = in_age;
}
void Person::set_type(bool in_type){
    type = in_type;
}

ostream &operator<<(ostream &str, Person person){
    str<<"------------------"<<endl;
    str<<"Name: "<<person.name <<" "<<person.surname<<endl;
    str<<"Mail: "<<person.mail<<endl;
    str<<"Age: "<<person.age<<endl;
    string is = (person.type == 0) ? "Professor" : "Student";
    str<<"Is: "<<is;
    str<<endl<<"------------------"<<endl;

    return str;
}

istream &operator>>(istream &str, Person &person){
    cout<<"Give name:";
    str>>person.name;

    cout<<"Give surname:";
    str>>person.surname;

    cout<<"Give mail:";
    str>>person.mail;

    cout<<"Give age:";
    str>>person.age;

    cout<<"Give type:";
    str>>person.type;

    return str;
}

Person& Person::operator+=(Course* course){
    return *this;
}
Person& Person::operator-=(Course* course){
    return *this;
}

void Person::edit(bool in_name=0, bool in_surname=0, bool in_mail=0, bool in_age=0){
    if(in_name){
        string in_name;
        cout<<"Give name: ";
        cin>>in_name;
        set_name(in_name);
    }
    if(in_surname){
        string in_surname;
        cout<<"Give surname: ";
        cin>>in_surname;
        set_surname(in_surname);
    }
    if(in_mail){
        string in_mail;
        cout<<"Give the new mail: ";
        cin>>in_mail;
        set_mail(in_mail);
    }
    if(in_age){
        int in_age;
        cout<<"Give the new age: ";
        cin>>in_age;
        set_age(in_age);
    }
}

void Person::edit(bool in_name=0, bool in_surname=0,bool in_mail=0, bool in_age=0, 
bool in_am=0, bool in_ects=0, bool in_sem=0) {}

Person* Person::clone(){
    Person* per;
    try{
        per = new Person(*this);
    }
    catch(bad_alloc& e){
        throw;
    }
    return per;
}