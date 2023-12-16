#include <iostream>
#include <string>
#include "classes.h"

int main(){
    //cout<<"Geia sou kouklaki\n";
    int choice;
    string x, n, s;
    do{
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
        cin>>choice;
        if (choice == 1){
            cout<<"Do you want to add, edit or delete a professor?"<<endl;
            cin>>x;
            cout<<"What's the name of the professor you want to "<<x<<"?"<<endl;
            cin>>n;
            cout<<"What's the surname of the professor you want to "<<x<<"?"<<endl;
            cin>>s;
        }
        else if (choice == 2){
            cout<<"Do you want to add, edit or delete a student?"<<endl;
            cin>>x;
            cout<<"What's the name of the student you want to "<<x<<"?"<<endl;
            cin>>n;
            cout<<"What's the surname of the student you want to "<<x<<"?"<<endl;
            cin>>s;
        }
        else if (choice == 3){
            cout<<"Do you want to add, edit or delete a course?"<<endl;
            cin>>x;
            cout<<"Which course you want to "<<x<<"?"<<endl;
            cin>>n;
        }
    }while (choice != 10);
    return 0;
}
