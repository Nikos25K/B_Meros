#include "classes.h"

int Person::count=0;

Person::Person() : name(""), surname(""), mail(""), age(0), subjects({}){
    count++;
}

//constructor based on Person*
Person::Person(const Person *ptr) :name(ptr->get_name()), surname(ptr->get_surname()), mail(ptr->get_mail()),
age(ptr->get_age()), subjects(ptr->get_subjects()) {
    count++;
}

//basic constructor
Person::Person(const string in_name, const string in_surname, const string in_mail,
const int in_age, const vector<string> in_subjects):
name(in_name), surname(in_surname), mail(in_mail), age(in_age), subjects(in_subjects) {
    count++;
}

//copy contructor
Person::Person(const Person& person):
name(person.name), surname(person.surname), mail(person.mail), 
age(person.age), subjects(person.subjects) {
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

vector<string> Person::get_subjects() const{
    return subjects;
}

ostream &operator<<(ostream &str, const Person person){
    str<<"------------------"<<endl;
    str<<"Name: "<<person.name <<" "<<person.surname<<endl;
    str<<"Mail: "<<person.mail<<endl;
    str<<"Age: "<<person.age<<endl;
    str<<"Subjects: ";

    auto current = person.subjects.begin();
    auto end = person.subjects.end();

    while(current != end){
        str<< *current;
        current++;
        if(current != end)
            str<<", ";
    }
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

    string in_subject = "end";
    getline(str,in_subject);        //consumes white char left from age

    while (1){      //giving "end" will stop the subject reading
        cout<<"Give subject:";
        getline(str,in_subject);
        if(in_subject == "end")
            break;
        person.subjects.push_back(in_subject);
    }

    return str;
}