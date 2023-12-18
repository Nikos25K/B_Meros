#include "classes.h"

Secretary::Secretary(): data({}) {}

//in case initialized with a vec of Person
Secretary::Secretary(const vector<Person> in_vec){
    for(Person per: in_vec)
        data.push_back(new Person(&per));
}

//in case initialized with a vec of Person*
Secretary::Secretary(const vector<Person*> in_vec){
    for(Person* per: in_vec)
        data.push_back(new Person(per));
}

//copy constructor
Secretary::Secretary(const Secretary& secretary){
    for(Person* per: secretary.get_data())
        data.push_back(new Person(per));
}

Secretary::~Secretary(){
    for (Person* person : data) 
        delete person;

    data.clear();
}

vector<Person*> Secretary::get_data() const{
    return data;
}

int Secretary::get_count() const{
    return data.size();
}
//in case of adding Person
Secretary& Secretary::operator+(const Person person){
    data.push_back(new Person(person));
    return *this;
}

//in case of adding Person*
Secretary& Secretary::operator+(const Person* person){
    data.push_back(new Person(*person));
    return *this;
}

//in case of adding Person
Secretary& Secretary::operator+=(const Person person) {
    data.push_back(new Person(person));
    return *this;
}

//in case of adding Person*
Secretary& Secretary::operator+=(const Person* person) {
    data.push_back(new Person(*person));
    return *this;
}

Secretary& Secretary::operator=(const Secretary secretary){
    if(this == &secretary)
        return *this;
    for (Person* person : data) 
        delete person;
    data.clear();

    for (const Person* person : secretary.data) 
        data.push_back(new Person(*person));

    return *this;
}

ostream &operator<<(ostream &str, const Secretary &secretary){
    str<<"Containing "<<secretary.get_count()<<" members"<<endl;
    for(const Person* person: secretary.data)
        str<<*person;
    return str;
}

istream &operator>>(istream &str, Secretary &secretary){
    int num;
    cout<<"Give number of persons:";
    str>>num;

    for(int i=0;i<num;i++){
        cout<<"Give data of person "<<i+1<<":"<<endl;
        Person person;
        str>> person;
        secretary = secretary + person;
    }
    return str;
}

//given a name and surname checks if inside
bool Secretary::find(const string in_name, const string in_surname){
    for(Person* person: data)
        if(in_name == person->get_name() && 
           in_surname == person->get_surname())
            return true;
    return false;
}
//given a Person
bool Secretary::find(const Person person){
    return find(person.get_name(), person.get_surname());
}

//given a Person*
bool Secretary::find(const Person *person){
    return find((*person).get_name(), (*person).get_surname());
}

vector<Student*> Secretary::students_graduate() const{
    vector<Student*> degreeee;
    for(Person* person : data){
        if(!person->get_type())     //skips professors
            continue;
        Student* student = dynamic_cast<Student*>(person); 
        if(!student)
            exit(1);
        if(student->gets_degree())
            degreeee.push_back(student);
    }
    return degreeee;
}




Secretary& Secretary::operator-=(const Person* person){

    return *this;
}

Secretary& Secretary::operator+=(const Course* course){
    // sems[course->get_semester()] += course;
    return *this;
}

Secretary& Secretary::operator-=(const Course* course){
    // sems[course->get_semester()] -= course;
    return *this;
}