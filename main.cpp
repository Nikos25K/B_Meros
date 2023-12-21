#include "classes.h"
#include "funcs.h"
// Course c1("AI",8,1,5,{},0,0);

// void incr(Person& per){
//     per += &c1;
// }

int main(){
    cout<<"Geia sou kouklaki\n";
    int choice, sem, y, z, in_age;
    string x, n, s, c, in_mail;
    char answer;

    Secretary sec;
    // vector<Person*> TO_DELETE;


    // Student std1("name","sur","mail",19,83,123,2,{});

    // Student* ss = &std1;

    // *ss += &c1;

    // incr(std1);
    // // std1.add_course(&c1);

    // map<Course*,double> map1 = std1.get_map();

    // cout<<map1[&c1]<<endl;

    // Professor prof1("name","sur","mail",19,{});
    // incr(prof1);

    // vector<Course*> vec1 = prof1.get_courses();

    // cout<<vec1[0]->get_ECTS()<<endl;


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
            cout<<"Do you want to add, edit or delete a person?"<<endl;
            cin>>x;
            //////////////////checkkkkkkkkkkkkkkkkkkkk
            cout<<"What's the name of the person you want to "<<x<<"?"<<endl;
            cin>>n;
            cout<<"What's the surname of the person you want to "<<x<<"?"<<endl;
            cin>>s;
            Person* person;
            if(x != "add")
                person = get_person(sec,n,s);   //updates
            if (x == "add" && choice == 1)      //create prof
                create_person(sec,0,n,s);
            else if(x == "add" && choice == 2)  //create stud
                create_person(sec,1,n,s);
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
                    person->edit(t_mail, t_age, t_am, t_ects, t_sem);
                else
                    person->edit(t_mail, t_age);   //Prof
                if(t_courses)
                    add_courses(sec, n,s);
                else
                    delete_courses(sec, n,s);
            }
            else 
                sec -= person;
        }
        else if (choice == 3){
            cout<<"Do you want to add, edit or delete a course?"<<endl;
            cin>>x;
            Course* course = read_course(sec,"");
            if (x == "add")
                create_course(sec);
            else if (x == "edit"){
                cout<<"Do you want to change the name? (y,n)"<<endl;
                bool t_name = check_resp(0);
                cout<<"Do you want to change the ects? (y,n)"<<endl;
                bool t_ects = check_resp(0);
                cout<<"Do you want to change the mandatory? (y,n)"<<endl;           //ENGLISHHH
                bool t_mand = check_resp(0);
                cout<<"Do you want to change the semester? (y,n)"<<endl;
                bool t_sem = check_resp(0);
                cout<<"Do you want to change the people? (y,n)"<<endl;
                bool t_people = check_resp(0);
                cout<<"Do you want to change the passed? (y,n)"<<endl;
                bool t_pass = check_resp(0);
                cout<<"Do you want to change the failed? (y,n)"<<endl;
                bool t_fail = check_resp(0);
                course->edit(t_name,t_ects,t_mand,t_sem,t_pass,t_fail);
                if(t_people)
                    add_courses(sec,course->get_name(),"");
            }
            else 
                sec -= course;
        }
        else if (choice == 4 || choice == 5){
            Course* course = read_course(sec,"");
            Person* p = get_person(sec,"","");
            if(p->get_type())
                add_courses(sec,p->get_name(),p->get_surname());            //ELSE??????????
        }
        else if (choice == 6){
            Course* course = read_course(sec,"");
            vector<Person*> people = course->get_people();
            for(Person* per: people){
                if(!per->get_type())
                    continue;
                Student* student = dynamic_cast<Student*>(per);
                check_ptr(student);
                if(student->passed_course(course))
                    continue;           //print to file
            }
        }
        else if (choice == 7){
            Person* p = get_person(sec,"","");
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
            Person* p = get_person(sec,"","");
            Student* student = dynamic_cast<Student*>(p); 
            check_ptr(student);
            map<Course*, double> m = student->get_map();
            int curr = student->get_semester();

            cout<<"The grades of "<<n + " " + s<<" for the previous semesters are:"<<endl;
            for(int i=1; i<=curr; i++){
                if(i==curr)
                    cout<<"The grades of "<<n + " " + s<<" for this semester are:"<<endl;
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

    cout<<sec;


    // Professor prof("Makis", "Dhmakis", "mail", 34, vec);

    // map<Course*, double> subjects;
    // subjects [&arch] = 9.3; 

    // Student lenia_kouklaki("Lenia", "Triantafyllia", "mail", 120, 133, 220, 3, subjects);
    // cout<<"Type"<<lenia_kouklaki.get_type()<<endl;

    // sec += prof;
    // sec += lenia_kouklaki;

    // prof += &arch;

    // cout<<sec;

    

    // int count = count_lines("files/students.txt");
    // ifstream fin("files/students.txt");
    // check_open(fin);


    // string name, surname, mail, course, line;
    // int age, am, ECTS, sem, temp_count;
    // float grade;
    // //type
    // map<Course*,double> mathimata;
    
    // temp_count=0;
    // vector<Person*> people;
    // while(getline(fin, line)){
    //     temp_count++;
    //     istringstream fin(line);
    //     fin>>name>>surname>>mail>>age>>am>>ECTS>>sem;
    //     mathimata.clear();      //sets for new student
    //     Course* tmp;
    //     while(fin>>course>>grade){
    //         tmp = sec.find(course);
    //         mathimata[tmp] = grade;
    //     }

    //     Student* student = new Student(name,surname,mail,age,am,ECTS,sem,mathimata);
    //     people.push_back(student);

    // }

    //     //na kano apodesmefsi

    // fin.close();
    // check_lines(count,temp_count);


    // count = count_lines("files/professors.txt");
    // fin.open("files/professors.txt");
    // check_open(fin);
    // temp_count=0;
    // while(getline(fin, line)){
    //     temp_count++;
    //     istringstream fin(line);
    //     fin>>name>>surname>>mail>>age;
    //     Course* tmp;
    //     vector<Course*> tmp_courses;
    //     while(fin>>course>>grade){
    //         tmp = sec.find(course);     //finds course in sec
    //         tmp_courses.push_back(tmp);
    //     }
    //     Professor* professor = new Professor(name,surname,mail,age,tmp_courses);
    //     people.push_back(professor);
    // }
    // fin.close();            //na kano apodesmefsi
    // check_lines(count,temp_count);

    // count = count_lines("files/courses.txt");
    // fin.open("files/courses.txt");
    // check_open(fin);
    // vector<Course*> courses;
    // temp_count=0;
    // string check;       //mandatory course or not
    // while(getline(fin, line)){
    //     temp_count++;
    //     istringstream fin(line);
    //     fin>>name>>ECTS>>check>>sem;

    //     string tmp_name,tmp_surname;
    //     vector<Person*> tmp_people;
    //     Person* tmp;
    //     while(fin>>tmp_name>>tmp_surname){
    //         tmp = sec.find(tmp_name,tmp_surname);   //finds Person in sec
    //         tmp_people.push_back(tmp);
    //     }
    //     Course* course;
    //     if(check == "mandatory")
    //         course = new Course(name,ECTS,1,sem,tmp_people,0,0); 
    //     else
    //         course = new Course(name,ECTS,0,sem,tmp_people,0,0);
    //     courses.push_back(course);

    // }
    // fin.close();
    // check_lines(count,temp_count);

    // for(Course* cour: courses)
    //     cout<<cour->get_name()<<endl;


    return 0;
}
