#include "classes.h"
#include "funcs.h"

int main(){

    Secretary sec;

    string name, surname, mail, course, line;
    int age, am, ECTS, sem, temp_count;
    float grade;

    int count = count_lines("files/courses.txt");
    ifstream fin("files/courses.txt");
    check_open(fin);
    
    temp_count=0;
    string check;       //mandatory course or not
    while(getline(fin, line)){
        temp_count++;
        istringstream fin(line);
        fin>>name>>ECTS>>check>>sem;

        // string tmp_name,tmp_surname;
        // vector<Person*> tmp_people;
        // Person* tmp;
        // while(fin>>tmp_name>>tmp_surname){
        //     tmp = sec.find(tmp_name,tmp_surname);   //finds Person in sec
        //     tmp_people.push_back(tmp);
        // }
        // Course* course;
        // if(check == "mandatory")
        //     course = new Course(name,ECTS,1,sem,tmp_people,0,0);
        // else
        //     course = new Course(name,ECTS,0,sem,tmp_people,0,0);
        // Course course(name,ECTS,0,sem,tmp_people,0,0);
        Course course(name,ECTS,0,sem,0,0);
        if(check == "mandatory")
            course.set_mandatory(1);
        
        sec += &course;
    }
    fin.close();
    check_lines(count,temp_count);

    count = count_lines("files/students.txt");
    fin.open("files/students.txt");
    check_open(fin);
    temp_count=0;
    map<Course*,double> mathimata;
    while(getline(fin, line)){
        temp_count++;
        istringstream fin(line);
        string name, surname, mail;
        fin>>name>>surname>>mail>>age>>am>>ECTS>>sem;
        mathimata.clear();      //sets for new student
        Course* tmp;
        while(fin>>course>>grade){
            tmp = sec.find(course);     //passed courses
            mathimata[tmp] = grade;
        }

        // Student* student = new Student(name,surname,mail,age,am,ECTS,sem,mathimata);
        // sec += student;

        //maybe a sec_func that puts the subjects and people
        Student student(mathimata,name,surname,mail,age,am,ECTS,sem);
        // Student student(name,surname,mail,age,am,ECTS,sem,mathimata);
        // Student student(name,surname,mail,age,am,ECTS,sem,mathimata);
        sec += &student;
    }
    fin.close();
    check_lines(count,temp_count);
    
    
    count = count_lines("files/professors.txt");
    fin.open("files/professors.txt");
    check_open(fin);
    temp_count=0;
    while(getline(fin, line)){
        temp_count++;
        istringstream fin(line);
        fin>>name>>surname>>mail>>age;
        Course* tmp;
        vector<Course*> tmp_courses;
        while(fin>>course>>grade){
            tmp = sec.find(course);     //finds course in sec
            check_ptr(tmp);
            tmp_courses.push_back(tmp);
        }
        Professor professor(name,surname,mail,age);
        // Professor professor(name,surname,mail,age,tmp_courses);
        // Professor* professor = new Professor(name,surname,mail,age,tmp_courses);
        sec += &professor;
        Person* prof = sec.find(name,surname);       //because creates new ptr
        sec.add_courses_to_person(tmp_courses, prof);
    }
    fin.close();
    check_lines(count,temp_count);

    // sec.show_courses();
    // cout<<sec;

    // Person* per = sec.find("Nikolaos","Kyriakakos");
    // Course* c = sec.find("Data_Structures");
    // check_ptr(c);
    // Student* student = dynamic_cast<Student*>(per);
    // check_ptr(student);
    // if(student->passed_course(c))
    //     cout<<*student;


    int choice;
    
    do{

        cout<<"---------------------------------------------------------------------------------------------"<<endl;
        cout<<"Choices:"<<endl;
        cout<<"1. Add, edit or delete a professor"<<endl;
        cout<<"2. Add, edit or delete a student"<<endl;
        cout<<"3. Add, edit or delete a course"<<endl;
        cout<<"4. Define a course's professors"<<endl;
        cout<<"5. Add a student in a course"<<endl;
        cout<<"6. Print and save in a file the students who succeeded in a specific course at a given semester"<<endl;
        cout<<"7. Print the statistics of a semester for all of a professor's courses"<<endl;
        cout<<"8. Print a student's marks for this semester and all the years in total"<<endl;
        cout<<"9. Print the students who can graduate"<<endl;
        cout<<"10. Exit"<<endl;
        cout<<"---------------------------------------------------------------------------------------------"<<endl;
        cin>>choice;
        check_num(choice,1,10);

        if (choice == 1 || choice == 2){
            string x;
            string is = (choice == 1) ? "professor" : "student";
            cout<<"Do you want to add, edit or delete a "<<is<<"?"<<endl;
            cin>>x;
            //////////////////checkkkkkkkkkkkkkkkkkkkk
            // cout<<"What's the name of the "<<is<< " you want to "<<x<<"?"<<endl;
            // cin>>n;
            // cout<<"What's the surname of the "<<is<< " you want to "<<x<<"?"<<endl;
            // cin>>s;
            Person* person;
            if(x != "add")
                person =sec.get_person("","");     //reads
            if (x == "add" && choice == 1)      //create prof
                sec.create_person(0);
            else if(x == "add" && choice == 2)  //create stud
                sec.create_person(1);
            else if (x == "edit"){
                cout<<"Do you want to change the mail? (y,n)"<<endl;
                bool t_mail = check_resp(0);
                cout<<"Do you want to change the age? (y,n)"<<endl;
                bool t_age = check_resp(0);
                bool t_am,t_ects,t_sem;
                if(person->get_type()){
                    cout<<"Do you want to change the AM? (y,n)"<<endl;
                    t_am = check_resp(0);
                    cout<<"Do you want to change the ECTS? (y,n)"<<endl;
                    t_ects = check_resp(0);
                    cout<<"Do you want to change the semester? (y,n)"<<endl;
                    t_sem = check_resp(0);
                }
                cout<<"Do you want to change the courses? (y,n)"<<endl;
                bool flag_courses = check_resp(0);
                bool t_courses=0;
                if(flag_courses){
                    cout<<"Do you want to add (0) or delete (1) courses?"<<endl;
                    t_courses = check_resp(1);                                  //checkkkkkkkkkkkkkkkkk
                }
                if(person->get_type())         //Student
                    person->edit(0,0,t_mail, t_age, t_am, t_ects, t_sem);
                else    //not eiditin name/surname
                    person->edit(0,0,t_mail, t_age);   //Prof
                if(flag_courses && !t_courses)
                    sec.add_courses_to_person(person);
                else if(flag_courses && t_courses)
                    sec.delete_courses_from_person(person);
            }
            else 
                sec -= person;
        }
        else if (choice == 3){
            string x;
            cout<<"Do you want to add, edit or delete a course?"<<endl;
            cin>>x;
                Course* course;
            if(x != "add")
                course = sec.get_course("");
            if (x == "add")
                sec.create_course();
            else if (x == "edit"){
                cout<<"Do you want to change the name? (y,n)"<<endl;
                bool t_name = check_resp(0);
                cout<<"Do you want to change the ects? (y,n)"<<endl;
                bool t_ects = check_resp(0);
                cout<<"Do you want to change the mandatory? (y,n)"<<endl;           //ENGLISHHH
                bool t_mand = check_resp(0);
                cout<<"Do you want to change the semester? (y,n)"<<endl;
                bool t_sem = check_resp(0);
                cout<<"Do you want to change the passed? (y,n)"<<endl;
                bool t_pass = check_resp(0);
                cout<<"Do you want to change the failed? (y,n)"<<endl;
                bool t_fail = check_resp(0);
                cout<<"Do you want to change the people? (y,n)"<<endl;
                bool flag_people = check_resp(0);
                bool t_people=0;
                if(flag_people){
                    cout<<"Do you want to add (0) or delete (1) people?"<<endl;
                    t_people = check_resp(1);
                }
                course->edit(t_name,t_ects,t_mand,t_sem,t_pass,t_fail);
                if(flag_people && !t_people)
                    sec.add_courses_to_person(course);
                else if(flag_people && t_people)
                    sec.delete_courses_from_person(course);
            }
            else 
                sec -= course;
        }
        else if (choice == 4 || choice == 5){
            Course* course = sec.get_course("");
            Person* p = sec.get_person("","");
            /////////////////check if choice and prof or student
            while(1){
                    sec.add_courses_to_person(course, p);

                cout << "Do you want to add another? (y/n)"<<endl;
                bool answer = check_resp(0);
                if(!answer)
                    break;
                if(choice == 4){     //set profs
                    p = sec.get_person("","");
                    //////////////////////check if professor
                }
                else                //add another course to student
                    course = sec.get_course("");
            }
        }        
        else if (choice == 6){
            Course* course = sec.get_course("");
            // vector<Person*> people = course->get_people();
            string file_to_open = "Results_"+course->get_name() + ".txt";


            vector<Person*> people = sec.get_data();

            ofstream fout;
            fout.open(file_to_open);
            check_open(fout);
            fout<<"The students that passed "<<course->get_name()<<" are:"<<endl<<endl;            
            for(Person* per: people){
                if(!per->get_type())
                    continue;
                Student* student = dynamic_cast<Student*>(per);
                check_ptr(student);
                if(student->passed_course(course)){
                    fout << *student;
                    fout << student->course_grade(course)<<endl;
                }
            }
            fout.close();
        }
        else if (choice == 7){
            Person* p = sec.get_person("","");
            //////////////////////check if student
            Professor* prof = dynamic_cast<Professor*>(p);          //check for func
            check_ptr(prof);
            vector<Course*> vec = prof->get_courses();
            for(Course* course : vec){
                cout<<"Course "<<course->get_name()<<endl;
                cout<<"Passed: "<<course->get_passed()<<"/"<<course->get_passed()+course->get_failed()<<
                " \t"<<"Avg grade: "<<course->get_avg_grade()<<endl;
            }
        }
        else if (choice == 8){
            Person* p = sec.get_person("","");
            //////////////////////check if professor
            Student* student = dynamic_cast<Student*>(p); 
            check_ptr(student);
            cout<< student->get_AM()<<endl;
            map<Course*, double> m = student->get_map();
            int curr = student->get_semester();

            cout<<"The grades of "<<p->get_name() + " " + p->get_surname()<<" for the previous semesters are:"<<endl;
            // cout<<"The grades of "<<n + " " + s<<" for the previous semesters are:"<<endl;
            for(int i=1; i<=curr; i++){
                if(i==curr)
                    cout<<"The grades of "<<p->get_name() + " " + p->get_surname()<<" for this semester are:"<<endl;
                    // cout<<"The grades of "<<n + " " + s<<" for this semester are:"<<endl;
                for (auto it = m.begin(); it != m.end(); ++it){
                    Course* course = it->first;
                    double grade = it->second;
                    if (course->get_semester() == i)
                        cout<<course->get_name()<<" : "<<grade<<endl;
                }
            }
        }
        else if (choice == 9){
            vector<Student*> vec1 = sec.students_graduate();
            if(vec1.empty()){
                cout<<"No students can graduate"<<endl;
                continue;
            }
            cout<<"The students who can graduate are the following:"<<endl;
            for(Student* stud : vec1)
                cout<<stud->get_name() + " " + stud->get_surname()<<endl;
        }
    }while (choice != 10);

    // sec.show_courses();
    // cout<<sec;

    // Person* per = sec.find("Anastasia","Lygizou");
    Course* c = sec.find("Cryptography");
    check_ptr(c);
    // Person* per = sec.find("Nikolaos", "Kyriakakos");
    // check_ptr(per);
    // *c += per;
    // *c -= per;
    vector<Person*> vec = c->get_people();
    for(Person* per: vec)
        cout<<*per;

    // Student* student = dynamic_cast<Student*>(per);
    // check_ptr(student);
    // cout<<student->course_grade(c)<<endl;

    // Person* per = sec.find("Nikolaos","Kyriakakos");
    // check_ptr(per);
    // Student* student = dynamic_cast<Student*>(per);
    // check_ptr(student);
    // map<Course*, double> m = student->get_map();
    // for (auto it = m.begin(); it != m.end(); ++it){
    //     Course* course = it->first;
    //     double grade = it->second;
    //     cout<<course->get_name()<<" : "<<grade<<endl;
    // }
    return 0;
}