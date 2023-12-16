#include "classes.h"

int Person::count=0;

Person::Person() : name(""), surname(""), mail(""), age(0){
    count++;
}

//constructor based on Person*
Person::Person(const Person *ptr) :name(ptr->get_name()), surname(ptr->get_surname()), mail(ptr->get_mail()),
age(ptr->get_age()){
    count++;
}

//basic constructor
Person::Person(const string in_name, const string in_surname, const string in_mail,
const int in_age):
name(in_name), surname(in_surname), mail(in_mail), age(in_age){
    count++;
}

//copy contructor
Person::Person(const Person& person):
name(person.name), surname(person.surname), mail(person.mail), 
age(person.age){
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


ostream &operator<<(ostream &str, const Person person){
    str<<"------------------"<<endl;
    str<<"Name: "<<person.name <<" "<<person.surname<<endl;
    str<<"Mail: "<<person.mail<<endl;
    str<<"Age: "<<person.age<<endl;
    str<<"Subjects: ";
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

    return str;
}