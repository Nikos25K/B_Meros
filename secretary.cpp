#include "classes.h"
#include "funcs.h"

Secretary::Secretary(): data({}) {}

//in case initialized with a vec of Person*
Secretary::Secretary(vector<Person*> in_vec){
    for(Person* per: in_vec)
        *this += per;
}

//copy constructor
Secretary::Secretary(Secretary& secretary){
    for(Person* per: secretary.get_people())
        *this += per;
}

Secretary::~Secretary(){
    for (Person* person : data) 
        delete person;
    for(Course* course: courses)
        delete course;

    data.clear();
    courses.clear();
}

vector<Person*> Secretary::get_people(){
    return data;
}

vector<Course*> Secretary::get_courses(){
    return courses;
}

int Secretary::get_count() const{
    return data.size();
}

Secretary& Secretary::operator+=(Person* person) {
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
    *this += person;

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
    cout<<"Give number of people:";
    str>>num;

    for(int i=0;i<num;i++){
        cout<<"Give data of person "<<i+1<<":"<<endl;
        Person person;
        str>> person;
        secretary += &person;
    }
    return str;
}

//given a name and surname checks if inside
Person* Secretary::find(const string in_name, const string in_surname){
    for(Person* person: data)
        if(in_name == person->get_name() &&
           in_surname == person->get_surname())
            return person;
    throw Err_Rpt("Error: Person not found\n");
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
        Student* student;
        student = dynamic_cast<Student*>(person);
        if(!student)
            throw Err_Rpt("Error casting to student\n");
        if(student->gets_degree())
            degreeee.push_back(student);
    }
    return degreeee;
}

Secretary& Secretary::operator-=(Person* person){
    vector<Person*>::iterator check;
    check = std::find(data.begin(), data.end(), person);
    if (check == data.end())
        throw Err_Rpt("Person not found\n");
    data.erase(check);
    return *this;
}

Secretary& Secretary::operator+=(Course* course){
    Course* cour;
    try{
        cour = new Course(course);
    }
    catch(bad_alloc& e){
        throw;
    }
    courses.push_back(cour);
    return *this;
}

Secretary& Secretary::operator-=(Course* course){
    vector<Course*>::iterator check;
        check = std::find(courses.begin(), courses.end(), course);
        if (check == courses.end())
            throw Err_Rpt("Course not found\n");

    courses.erase(check);
    return *this;
}

Course* Secretary::find(string in_name){
    for(Course* curr : courses)
        if(in_name == curr->get_name())
            return curr;
    throw Err_Rpt("Error: Course not found\n");
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
    
    Person* p = this->find(name, surname);
    return p;
}

Course* Secretary::get_course(string cour=""){      //exists, so will not crash
    if(cour == ""){
        cout<<"Give the course"<<endl;
        cin>>cour;
    }
    Course* course = find(cour);
    return course;
}

void Secretary::create_course(){
    Course course;
    course.edit(1,1,1,1,1,1);
    try{
        find(course.get_name());
    }
    catch(Err_Rpt& err){        //error == not in sec, so add
        cout<<"Do you want to give people? (Y/N)"<<endl;
        bool answer = check_resp(0);
        if(answer)
            add_courses_to_person(&course);
        *this+= &course;
        return;
    }
    cerr<<"Error: Course already exists\n";
    exit(1);
}

void Secretary::create_person(bool flag){
    Person* per;
    if(flag){
        try{
            per = new Student;
        }
        catch(bad_alloc& e){
            throw;
        }
        per->edit(1,1,1,1,1,1,1);
    }
    else{
        try{
            per = new Professor;
        }
        catch(bad_alloc& e){
            throw;
        }
        per->edit(1,1,1,1);
    }

    try{
        find(per->get_name(), per->get_surname());
    }
    catch(Err_Rpt& err){        //error == not in sec, so add
        per->set_type(flag);
        cout<<"Do you want to give courses? (Y/N)"<<endl;
        bool answer = check_resp(0);
        if(answer)
            this->add_courses_to_person(per);
        *this += per;
        delete per;
        return;
    }
    delete per;
    cerr<<"Error: Person already exists\n";
    exit(1);
}