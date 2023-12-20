#include "classes.h"

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
    str<<"Type: "<<person.type;
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