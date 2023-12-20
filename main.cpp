#include "classes.h"
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

inline void check_ptr(void* ptr){
    if(!ptr){
        cerr << "Error: Person/Course not found" << endl;
        exit(1);
    }
}

Course c1("AI",8,1,5,{},0,0);

void incr(Person& per){
    per += &c1;
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
    char reply = 'y';
    while(reply == 'y' || reply == 'Y'){
        Course* course = read_course(sec);
        per += course;
        *course += &per;
        cout<<"Do you want to add another course? (y/n)"<<endl;
        cin>>reply;
    }
}

void delete_courses(Secretary& sec, Person& per){
    char reply = 'y';
    while(reply == 'y' || reply == 'Y'){
        Course* course = read_course(sec);
        per -= course;
        *course -= &per;
        cout<<"Do you want to delete another course? (y/n)"<<endl;
        cin>>reply;
    }
}

int main(){
    cout<<"Geia sou kouklaki\n";
    int choice, sem, y, z, in_age;
    string x, n, s, c, in_mail;
    char answer;

    Secretary sec;
    vector<Person*> TO_DELETE;

    

    Student std1("name","sur","mail",19,83,123,2,{});

    Student* ss = &std1;

    *ss += &c1;

    incr(std1);
    // std1.add_course(&c1);

    map<Course*,double> map1 = std1.get_map();

    cout<<map1[&c1]<<endl;

    Professor prof1("name","sur","mail",19,{});
    incr(prof1);

    vector<Course*> vec1 = prof1.get_courses();

    cout<<vec1[0]->get_ECTS()<<endl;


    // do{
    //     cout<<"Choices:"<<endl;
    //     cout<<"1. Add, edit or delete a professor"<<endl;
    //     cout<<"2. Add, edit or delete a student"<<endl;
    //     cout<<"3. Add, edit or delete a course"<<endl;
    //     cout<<"4. Define a course's professors"<<endl;
    //     cout<<"5. Add a student in a course"<<endl;
    //     cout<<"6. Print and save in a file the students who succeeded in a specific course at a given semester"<<endl;
    //     cout<<"7. Print the statistics of a semester for all of a professor's courses"<<endl;
    //     cout<<"8. Print a student's marks for this semester and all the years in total"<<endl;
    //     cout<<"9. Print the students who can graduate"<<endl;
    //     cout<<"10. Exit"<<endl;
    //     cin>>choice;
    //     check_num(choice,1,10);
    //     if (choice == 1){
    //         cout<<"Do you want to add, edit or delete a professor?"<<endl;
    //         cin>>x;
    //         cout<<"What's the name of the professor you want to "<<x<<"?"<<endl;
    //         cin>>n;
    //         cout<<"What's the surname of the professor you want to "<<x<<"?"<<endl;
    //         cin>>s;

    //         if (x == "add"){
    //             cout<<"Give the professor's mail"<<endl;
    //             cin>>in_mail;
    //             cout<<"Give the professor's age"<<endl;
    //             cin>>in_age;
    //             vector<Course*> in_courses;
    //             cout<<"Do you want to give a professor's course (Y/N)"<<endl;
    //             cin>>answer;
    //             if(answer != 'Y' && answer != 'y')
    //                 break;
                
    //             Professor* prof = new Professor(n, s, in_mail, in_age, in_courses);
    //             // Professor prof(n, s, in_mail, in_age, in_courses);
    //             sec += prof;
    //         }
    //         else if (x == "edit"){
    //             cout<<"Do you want to change the professor's mail (1), age (2) or courses (3)?"<<endl;
    //             cin>>y;
    //             check_num(y,1,3);
    //             Person* person = sec.find(n, s);
    //             check_ptr(person);
    //              if (y == 1){
    //                 cout<<"Give the new mail"<<endl;       //new mail
    //                 cin>>in_mail;
    //                 person->set_mail(in_mail);
    //              }
    //              else if (y == 2){
    //                 cout<<"Give the new age"<<endl;        //new age
    //                 cin>>in_age;   
    //                 check_num(in_age,18,80);
    //                 person->set_age(in_age);
    //              }
    //              else {                                     //new courses
    //                     cout<<"Do you want to add (1) or delete (2) professor's courses?"<<endl;
    //                     cin>>z;
    //                     check_num(z,1,2);
    //                     if(z == 1)         //add
    //                         add_courses(*person);
    //                     else               //delete
    //                         delete_courses(*person);
    //                 }
    //         }
    //         else {
    //             Person* person = sec.find(n, s)
    //             sec -= person;
    //         }    
    //     }
    //     else if (choice == 2){
    //         cout<<"Do you want to add, edit or delete a student?"<<endl;
    //         cin>>x;
    //         cout<<"What's the name of the student you want to "<<x<<"?"<<endl;
    //         cin>>n;
    //         cout<<"What's the surname of the student you want to "<<x<<"?"<<endl;
    //         cin>>s;
    //     }
    //     else if (choice == 3){
    //         cout<<"Do you want to add, edit or delete a course?"<<endl;
    //         cin>>x;
    //         cout<<"Which course you want to "<<x<<"?"<<endl;
    //         cin>>n;
    //     }
    //     else if (choice == 4 || choice == 5){
    //         cout<<"Give the course"<<endl;
    //         cin>>c;
    //         Course* course = sec.find(c);
    //         check_ptr(course);
    //         do{
    //             cout<<"Give name"<<endl;
    //             cin>>n;
    //             cout<<"Give surname"<<endl;
    //             cin>>s;
    //             Person* p = sec.find(n, s);
    //             check_ptr(p);
    //             if(p->get_type()){
    //                 Student* student = dynamic_cast<Student*>(p);
    //                 check_ptr(student);
    //                 course += student;
    //                 student += course;
    //                 break;      //only one student for question 5                   
    //             }
    //             Professor* prof = dynamic_cast<Professor*>(p);
    //             check_ptr(prof);
    //             course += prof;
    //             prof += course; 

    //             cout<<"Do you want to define another professor? (Y/N)"<<endl;
    //             cin>>answer;
    //         }while (answer == 'Y' || answer == 'y');
    //     }
    //     else if (choice == 6){
    //         cout<<"Give the course"<<endl;
    //         cin>>c; //string
    //         Course* course = sec.find(c);
    //         check_ptr(course);
    //         vector<Person*> people = course->get_people();
    //         for(Person* per: people){
    //             if(!per->get_type())
    //                 continue;
    //             Student* student = dynamic_cast<Student*>(per);
    //             check_ptr(student);
    //             if(student->passed_course(course))
    //                 continue;           //print to file
    //         }
    //     }
    //     else if (choice == 7){
    //         cout<<"Give professor's name"<<endl;
    //         cin>>n;
    //         cout<<"Give professor's surname"<<endl;
    //         cin>>s;
    //         Person* p = sec.find(n, s);
    //         check_ptr(p);
    //         Professor* prof = dynamic_cast<Professor*>(p);          //check for func
    //         check_ptr(prof); 
    //         vector<Course*> vec = prof->get_courses();
    //         for(Course* course : vec){
    //             cout<<"Course "<<course->get_name()<<endl;
    //             cout<<"Passed: "<<course->get_passed()<<"/"<<course->get_passed()+course->get_failed()<<
    //             " \t"<<"Avg grade: "<<course->get_avg_grade()<<endl;
    //         }
    //     }
    //     else if (choice == 8){
    //         cout<<"Give the student's name"<<endl;
    //         cin>>n;
    //         cout<<"Give the student's surname"<<endl;
    //         cin>>s;
    //         Person* p = sec.find(n, s);
    //         check_ptr(p);
    //         Student* student = dynamic_cast<Student*>(p); 
    //         check_ptr(student);
    //         map<Course*, double> m = student->get_map();
    //         int curr = student->get_semester();

    //         cout<<"The grades of "<<n + " " + s<<" for the previous semesters are:"<<endl;
    //         for(int i=1; i<=curr; i++){
    //             if(i==curr)
    //                 cout<<"The grades of "<<n + " " + s<<" for this semester are:"<<endl;
    //             for (auto it = m.begin(); it != m.end(); ++it){
    //                 Course* course = it->first;
    //                 double grade = it->second;
    //                 if (course->get_semester() == i)
    //                     cout<<course->get_name()<<" : "<<grade<<endl;
    //             }
    //         }
    //     }
    //     else if (choice == 9){
    //         vector<Student*> vec1 = sec.students_graduate();
    //         if(vec1.empty()){
    //             cout<<"No students can graduate"<<endl;
    //             continue;
    //         }
    //         cout<<"The students who can graduate are the following:"<<endl;
    //         for(Student* stud : vec1)
    //             cout<<stud->get_name() + " " + stud->get_surname()<<endl;
    //     }
    // }while (choice != 10);


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
