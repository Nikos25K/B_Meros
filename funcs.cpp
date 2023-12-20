#include "funcs.h"
inline void check_lines(int count,int temp_count){
    if(count != temp_count){
        cerr << "Error: Something wrong with reading." << endl;
        exit(1);
    }
}

inline void check_open(ifstream& fin){
    if (!fin.is_open()) {
        cerr << "Error: Could not open input file." << endl;
        exit(1);
    }
}

inline int count_lines(string name){
    ifstream fin(name);
    check_open(fin);
    int count=0;
    string line;
    while(getline(fin, line))       //counts lines of file
        count++;
    fin.close();
    return count;
}

inline void check_num(int choice, int low, int upp){    //bounds check
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

Person* get_person(Secretary& sec, string name, string surname){
    Person* p = sec.find(name, surname);
    check_ptr(p);
    return p;
}

Course* read_course(Secretary& sec){      //exists, so will not crash
    string c;
    cout<<"Give the course"<<endl;
    cin>>c;
    Course* course = sec.find(c);
    check_ptr(course);
    return course;
}

void add_courses(Secretary& sec, Person& per){
    while(1){
        Course* course = read_course(sec);
        per += course;
        *course += &per;
        cout<<"Do you want to add another course? (y/n)"<<endl;
        bool reply = check_resp(0);
        if(!reply)
            break;
    }
}

void delete_courses(Secretary& sec, Person& per){
    while(1){
        Course* course = read_course(sec);
        per -= course;
        *course -= &per;
        cout<<"Do you want to delete another course? (y/n)"<<endl;
        bool reply = check_resp(0);
        if(!reply)
            break;
    }
}

//is sec needed?????????????????????
void edit_person(Secretary& sec, Person& per, bool mail=0, bool age=0, int courses=0){

    if(!per.get_type())
        per.edit(mail,age);
    else
        per.edit()
    

    if(!courses)
        return;
    if(courses == 1)        //add
        add_courses(sec,per);
    else
        delete_courses(sec,per);
}

//flag: 1 for student and 0 for professor
void create_person(Secretary& sec, bool flag, string name, string surname){
    Person* per;
    if(flag)
        per = new Student;
    else
        per = new Professor;

    check_ptr(per);     //if error allocating

    per->set_name(name);
    per->set_surname(surname);
    per->set_type(flag);

    if(flag){

    }

    cout<<"Do you want to give courses? (Y/N)"<<endl;
    bool answer = check_resp(0);
    if(answer)
        edit_person(sec, *per, 1, 1, 1);
    else
        edit_person(sec, *per, 1, 1, 0);
    sec += per;
}

void edit_course(Secretary& sec, Course& course, bool name=0, bool ects=0, 
bool mand=0, bool sem=0, bool people=0 , bool passed=0, bool failed=0){
    if(name){
        string in_name;
        cout<<"Give the new name"<<endl;
        cin>>in_name;
        course.set_name(in_name);
    }
    if(ects){
        int in_ects;
        cout<<"Give the new ects"<<endl;
        cin>>in_ects;
        course.set_ECTS(in_ects);
    }
    if(mand){
        cout<<"Is it mandatory? (y/n)"<<endl;
        bool mand = check_resp(0);
        course.set_mandatory(mand);
    }
    if(sem){
        int in_sem;
        cout<<"Give the new semester"<<endl;
        cin>>in_sem;
        course.set_semester(in_sem);        
    }
    if(people){        
        while(1){
            cout<<"Do you want to add (0) or delete (1) people?"<<endl;
            int check = check_resp(1);
            string n,s,tmp;
            if(check)
                tmp = "delete";
            else
                tmp = "add";
            cout<<"What's the surname of the person you want to "<<tmp<<"?"<<endl;
            cin>>n;
            cout<<"What's the surname of the person you want to "<<tmp<<"?"<<endl;
            cin>>s;
            Person* per = get_person(sec, n, s);
            if(check == 1)
                course += per;
            else    
                course -= per;
            cout<<"Do you want to give another? (Y/N)"<<endl;
            bool answer = check_resp(0);
            if(!answer)
                break;
        }
    }
    if(passed){
        int in_passed;
        cout<<"Give people that passed"<<endl;
        cin>>in_passed;
        course.set_passed(in_passed);
    }
    if(failed){
        int in_failed;
        cout<<"Give people that failed"<<endl;
        cin>>in_failed;
        course.set_failed(in_failed);
    }
}

void create_course(Secretary& sec){
    Course* course = new Course;
    check_ptr(course);          //if error allocating
    cout<<"Do you want to give people? (Y/N)"<<endl;
    bool answer = check_resp(0);
    if(answer)
        edit_course(sec,*course,1,1,1,1,1,1,1);
    else
        edit_course(sec,*course,1,1,1,1,0,1,1);
    sec += course;
}