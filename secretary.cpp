#include "classes.h"
#include "funcs.h"

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
    for(Course* course: courses)
        delete course;

    data.clear();
    courses.clear();

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
    // data.push_back(new Person(*person));
    data.push_back(person->clone());
    return *this;
}

//in case of adding Person
Secretary& Secretary::operator+=(Person person) {
    data.push_back(new Person(person));
    return *this;
}

//in case of adding Person*
Secretary& Secretary::operator+=(Person* person) {
    // data.push_back(new Person(*person));
    data.push_back(person->clone());
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
    courses.push_back(new Course(*course));
    return *this;
}

Secretary& Secretary::operator-=(Course* course){
    auto it = std::find(courses.begin(), courses.end(), course);
    if (it != courses.end()) {
        courses.erase(it);
    }
    return *this;
}

Course* Secretary::find(string in_name){
    for(Course* curr : courses)
        if(in_name == curr->get_name())
            return curr;
    return NULL;
}

void Secretary::show_courses(){
    for(Course* cour: courses){
        cout<<cour->get_name()<<" ";
        cout<<cour->get_ECTS()<<" ";
        cout<<cour->is_mandatory()<<endl;
    }
}

void Secretary::add_courses_to_person(Course* course, Person* per){
    *course += per;
    *per += course;
}

void Secretary::add_courses_to_person(vector<Course*> vec, Person* per){
    for(Course* course : vec)
        add_courses_to_person(course, per); 
}

void Secretary::add_courses_to_person(Course* course){
    while(1){
        Person* per = this->get_person("","");    //reads
        this->add_courses_to_person(course, per);
        cout << "Do you want to add another? (y/n)"<<endl;
        bool answer = check_resp(0);
        if(!answer)
            break;
    }
}           //maybe one?????????????????????????

void Secretary::add_courses_to_person(Person* per){
    while(1){
        Course* course = this->get_course("");    //reads
        this->add_courses_to_person(course, per);
        cout << "Do you want to add another? (y/n)"<<endl;
        bool answer = check_resp(0);
        if(!answer)
            break;
    }
}

void Secretary::delete_courses_from_person(Course* course, Person* per){
    *per -= course;
    *course -= per;
}

void Secretary::delete_courses_from_person(Person* per){
    while(1){
        Course* course = this->get_course("");    //reads
        this->delete_courses_from_person(course, per);
        cout << "Do you want to delete another? (y/n)"<<endl;
        bool answer = check_resp(0);
        if(!answer)
            break;
    }
}

void Secretary::delete_courses_from_person(Course* course){
    while(1){
        Person* per = this->get_person("","");    //reads
        this->delete_courses_from_person(course, per);
        cout << "Do you want to delete another? (y/n)"<<endl;
        bool answer = check_resp(0);
        if(!answer)
            break;
    }
}

Person* Secretary::get_person(string name="", string surname=""){
    if(name == ""){
        cout<<"Give name"<<endl;
        cin >> name;
    }
    if(surname == ""){
        cout<<"Give surname"<<endl;
        cin >> surname;
    }
    Person* p = find(name, surname);
    check_ptr(p);
    return p;
}

Course* Secretary::get_course(string cour=""){      //exists, so will not crash
    if(cour == ""){
        cout<<"Give the course"<<endl;
        cin>>cour;
    }
    Course* course = find(cour);
    check_ptr(course);
    return course;
}

void Secretary::create_course(){
    Course course;
    course.edit(1,1,1,1,1,1);
    cout<<"Do you want to give people? (Y/N)"<<endl;
    bool answer = check_resp(0);
    if(answer)
        add_courses_to_person(&course);
    *this+= &course;

}

void Secretary::create_person(bool flag){
    Person* per;
    if(flag){
        per = new Student;
        per->edit(1,1,1,1,1,1,1);
    }
    else{
        per = new Professor;
        per->edit(1,1,1,1);
    }
    check_ptr(per);     //if error allocating

    per->set_type(flag);
    cout<<"Do you want to give courses? (Y/N)"<<endl;
    bool answer = check_resp(0);
    if(answer)
        this->add_courses_to_person(per);

    *this += per;    
    delete per;
}