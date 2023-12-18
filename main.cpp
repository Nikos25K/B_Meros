#include "classes.h"

static inline int count_lines(string name){
    ifstream fin(name);
    if (!fin.is_open()) {
        cerr << "Error: Could not open input file." << endl;
        return 1;
    }
    int count=0;
    string line;
    while(getline(fin, line))       //counts lines of file
        count++;
    fin.close();
    return count;
}

int main(){
    //cout<<"Geia sou kouklaki\n";
    // int choice, sem;
    // string x, n, s, c;
    // char answer;
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
    //             vector<Course*> in_courses = {};
    //             cout<<"Do you want to give a professor's course (Y/N)"<<endl;
    //             cin>>answer;
    //             while (answer == 'Y' || answer == 'y'){
    //                 cout<<"Give the course"<<endl;
    //                 cin>>c;
    //                 in_courses.push_back(sec.find(c));
    //                 cout<<"Do you want to give another course (Y/N)?"
    //                 cin>>answer;
    //             }
    //             Professor prof(n, s, in_mail, in_age, in_courses);
    //             sec += prof;
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
    //     else if (choice == 4){
    //         cout<<"Which course's professors you want to define?"<<endl;
    //         cin>>c;
    //         do{
    //             cout<<"Give professor's name"<<endl;
    //             cin>>n;
    //             cout<<"Give professor's surname"<<endl;
    //             cin>>s;
    //             cout<<"Do you want to define another professor? (Y/N)"<<endl;
    //             cin>>answer;
    //         }while (answer == 'Y' || answer == 'y');
    //     }
    //     else if (choice == 5){
    //         cout<<"Give the course"<<endl;
    //         cin>>c;
    //         cout<<"Give the student's name"<<endl;
    //         cin>>n;
    //         cout<<"Give the student's surname"<<endl;
    //         cin>>s;
    //     }
    //     else if (choice == 6){
    //         cout<<"Give the course"<<endl;
    //         cin>>c;
    //         cout<<"Give the semester"<<endl;
    //         cin>>sem;
    //     }
    //     else if (choice == 7){
    //         cout<<"Give the semester"<<endl;
    //         cin>>sem;
    //         cout<<"Give professor's name"<<endl;
    //         cin>>n;
    //         cout<<"Give professor's surname"<<endl;
    //         cin>>s;
    //     }
    //     else if (choice == 8){
    //         cout<<"Give the semester"<<endl;
    //         cin>>sem;
    //         cout<<"Give the student's name"<<endl;
    //         cin>>n;
    //         cout<<"Give the student's surname"<<endl;
    //         cin>>s;
    //     }
    //     else if (choice == 9){
    //          cout<<"The students who can graduate are the following:"<<endl;

    //          void Course::set_professors(vector<Professor*> in_profs){
    //          for(Professor* prof_ptr : in_profs)
    //              people.push_back(prof_ptr);
    //          }


        // vector<Person*> vec1 = sec.get_data();

    //     for(Person* per : vec1)
    //         if (per->get_type() == 1){
    //             if (per->semester >= 8){
    //                 bool flag = 0;
    //             }
    //         }  

    //     }
    // }while (choice != 10);

    // Secretary sec;

    // Course arch("arch",8,1,4, {},12,13);

    // cout<<arch.is_mandatory()<<endl;

    // vector<Course*> vec;
    // vec.push_back(&arch);

    // Professor prof("Makis", "Dhmakis", "mail", 34, vec);

    // map<Course*, double> subjects;
    // subjects [&arch] = 9.3; 

    // Student lenia_kouklaki("Lenia", "Triantafyllia", "mail", 120, 133, 220, 3, subjects);
    // cout<<"Type"<<lenia_kouklaki.get_type()<<endl;

    // sec += prof;
    // sec += lenia_kouklaki;

    // prof += &arch;

    // cout<<sec;

    int count = count_lines("files/students.txt");

    ifstream fin("files/students.txt");
    if (!fin.is_open()) {
        cerr << "Error: Could not open input file." << endl;
        return 1;
    }

    string name, surname, mail, course, line;
    int age, am, ECTS, sem;
    float grade;
    //type
    map<string,float> mathimata;

    while(getline(fin, line)){
        istringstream fin(line);
        fin>>name>>surname>>mail>>age>>am>>ECTS>>sem;
        mathimata.clear();      //sets for new student
        while(fin>>course>>grade)
            mathimata[course] = grade;
    }

    fin.close();

    count = count_lines("files/professors.txt");

    fin.open("files/professors.txt");
    if (!fin.is_open()) {
        cerr << "Error: Could not open input file." << endl;
        return 1;
    }
    while(getline(fin, line)){
        istringstream fin(line);
        fin>>name>>surname>>mail>>age;
    }
    fin.close();

    count = count_lines("files/courses.txt");

    fin.open("files/courses.txt");
    if (!fin.is_open()) {
        cerr << "Error: Could not open input file." << endl;
        return 1;
    }
    string check;       //mandatory course or not
    while(getline(fin, line)){
        istringstream fin(line);
        fin>>name>>ECTS>>check>>sem;
        if(check == "mandatory")
            cout<<1111111<<endl;
        else
            cout<<000000<<endl;
    }
    fin.close();


    return 0;
}
