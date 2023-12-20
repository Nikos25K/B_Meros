#include "classes.h"

Secretary::Secretary(): data({}) {}

//in case initialized with a vec of Person
Secretary::Secretary(vector<Person> in_vec){
    for(Person per: in_vec)
        data.push_back(new Person(&per));
}

//in case initialized with a vec of Person*
Secretary::Secretary(vector<Person*> in_vec){
    for(Person* per: in_vec)
        data.push_back(new Person(per));
}

//copy constructor
Secretary::Secretary(Secretary& secretary){
    for(Person* per: secretary.get_data())
        data.push_back(new Person(per));
}

Secretary::~Secretary(){
    for (Person* person : data) 
        delete person;

    data.clear();
}

vector<Person*> Secretary::get_data(){
    return data;
}

int Secretary::get_count() const{
    return data.size();
}
//in case of adding Person
Secretary& Secretary::operator+(Person person){
    data.push_back(new Person(person));
    return *this;
}

//in case of adding Person*
Secretary& Secretary::operator+(Person* person){
    data.push_back(new Person(*person));
    return *this;
}

//in case of adding Person
Secretary& Secretary::operator+=(Person person) {
    data.push_back(new Person(person));
    return *this;
}

//in case of adding Person*
Secretary& Secretary::operator+=(Person* person) {
    data.push_back(new Person(*person));
    return *this;
}

Secretary& Secretary::operator=(Secretary secretary){
    if(this == &secretary)
        return *this;
    for (Person* person : data) 
        delete person;
    data.clear();

    for (Person* person : secretary.data) 
        data.push_back(new Person(*person));

    return *this;
}

ostream &operator<<(ostream &str, Secretary &secretary){
    str<<"Containing "<<secretary.get_count()<<" members"<<endl;
    for(Person* person: secretary.data)
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
Person* Secretary::find(const string in_name, const string in_surname){
    for(Person* person: data)
        if(in_name == person->get_name() && 
           in_surname == person->get_surname())
            return person;
    return NULL;
}
//given a Person
Person* Secretary::find(Person person){
    return find(person.get_name(), person.get_surname());
}

//given a Person*
Person* Secretary::find(Person *person){
    return find((*person).get_name(), (*person).get_surname());
}

vector<Student*> Secretary::students_graduate(){
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

Secretary& Secretary::operator-=(Person* person){
    for (auto it = data.begin(); it != data.end(); ++it){
        if (*it == person){
            data.erase(it);
        }
    }
    return *this;
}

Secretary& Secretary::operator+=(Course* course){
    courses[course->get_semester()].push_back(new Course(*course));
    // sems[course->get_semester()] += course;
    return *this;
}

Secretary& Secretary::operator-=(Course* course){
    int semest = course->get_semester();
    for (auto it = courses[semest].begin(); it != courses[semest].end(); ++it){
        if (*it == course){
            courses[semest].erase(it);
        }
    }
    // sems[course->get_semester()] -= course;
    return *this;
}

Course* Secretary::find(const string in_name){
    for (const auto sem : courses)
        for(Course* curr : sem)
            if(in_name == curr->get_name())
                return curr;
    return NULL;
}