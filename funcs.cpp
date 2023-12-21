#include "classes.h"
#include "funcs.h"

void check_lines(int count,int temp_count){
    if(count != temp_count){
        cerr << "Error: Something wrong with reading." << endl;
        exit(1);
    }
}

void check_open(ifstream& fin){
    if (!fin.is_open()) {
        cerr << "Error: Could not open input file." << endl;
        exit(1);
    }
}

int count_lines(string name){
    ifstream fin(name);
    check_open(fin);
    int count=0;
    string line;
    while(getline(fin, line))       //counts lines of file
        count++;
    fin.close();
    return count;
}

void check_num(int choice, int low, int upp){    //bounds check
    if(choice<low || choice>upp){
        cerr << "Error: Number out of bounds" << endl;
        exit(1);
    }
}

bool check_resp(bool numeric){       //to check yes/no
    if(!numeric){    //char
        char resp;
        while(resp != 'y' && resp != 'Y' && resp != 'n' && resp != 'N')
            cin>>resp;
        if(resp == 'y' || resp == 'Y')
            return true;
        return false;
    }
    int resp;
    while(resp != 1 && resp != 0)
        cin>>resp;
    if(resp)
        return true;
    return false;
}

inline void check_ptr(void* ptr){
    if(!ptr){
        cerr << "Error: Person/Course not found" << endl;
        exit(1);
    }
}

Person* get_person(Secretary& sec, string name="", string surname=""){
    if(name == ""){
        cout<<"Give name"<<endl;
        cin >> name;
    }
    if(surname == ""){
        cout<<"Give surname"<<endl;
        cin >> surname;
    }
    Person* p = sec.find(name, surname);
    check_ptr(p);
    return p;
}

Course* read_course(Secretary& sec, string cour=""){      //exists, so will not crash
    if(cour == ""){
        cout<<"Give the course"<<endl;
        cin>>cour;
    }
    Course* course = sec.find(cour);
    check_ptr(course);
    return course;
}

// void add_courses(Secretary& sec, Person& per){
//     while(1){
//         Course* course = read_course(sec);
//         per += course;
//         *course += &per;
//         cout<<"Do you want to add another course? (y/n)"<<endl;
//         bool reply = check_resp(0);
//         if(!reply)
//             break;
//     }
// }

void add_courses(Secretary& sec, string name="", string surname=""){
    Course* course;
    Person* person;
    if(name == "")          //exception
        return;             
    if(surname == "")   //is about course
        course = read_course(sec,name);
    else
        person = get_person(sec,name,surname);
    while(1){
        if(surname != "")       //is about person
            course = read_course(sec,"");
        else
            person = get_person(sec,"","");
        *person += course;
        *course += person;
        if(surname != "")
            cout<<"Do you want to add another course? (y/n)"<<endl;
        else
            cout<<"Do you want to add another person? (y/n)"<<endl;
        bool reply = check_resp(0);
        if(!reply)
            break;
    }
}

// void delete_courses(Secretary& sec, Person& per){
//     while(1){
//         Course* course = read_course(sec);
//         per -= course;
//         *course -= &per;
//         cout<<"Do you want to delete another course? (y/n)"<<endl;
//         bool reply = check_resp(0);
//         if(!reply)
//             break;
//     }
// }

void delete_courses(Secretary& sec, string name="", string surname=""){
    Course* course;
    Person* person;
    if(name == "")          //exception
        return;             
    if(surname == "")   //is about course
        course = read_course(sec,name);
    else
        person = get_person(sec,name,surname);
    while(1){
        if(surname != "")       //is about person
            course = read_course(sec,"");
        else
            person = get_person(sec,"","");
        *person += course;
        *course += person;
        if(surname != "")
            cout<<"Do you want to delete another course? (y/n)"<<endl;
        else
            cout<<"Do you want to delete another person? (y/n)"<<endl;
        bool reply = check_resp(0);
        if(!reply)
            break;
    }
}

//flag: 1 for student and 0 for professor
void create_person(Secretary& sec, bool flag, string name, string surname){
    Person* per;
    if(flag){
        per = new Student;
        per->edit(1,1,1,1,1);
    }
    else{
        per = new Professor;
        per->edit(1,1);
    }

    check_ptr(per);     //if error allocating

    per->set_name(name);
    per->set_surname(surname);
    per->set_type(flag);

    cout<<"Do you want to give courses? (Y/N)"<<endl;
    bool answer = check_resp(0);
    if(answer)
        add_courses(sec,name,surname);

    sec += per;
}

void create_course(Secretary& sec){
    Course* course = new Course;
    check_ptr(course);          //if error allocating
    course->edit(1,1,1,1,1,1);
    cout<<"Do you want to give people? (Y/N)"<<endl;
    bool answer = check_resp(0);
    if(answer)
        add_courses(sec,course->get_name());
    sec += course;
}