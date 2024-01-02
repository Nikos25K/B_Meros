#include "utils.h"

int count_lines(string name){
    ifstream fin(name);
    if(!fin.is_open())
        throw Err_Rpt("Error: Could not open file: " + name + "\n","funcs.cpp","6");
    int count=0;
    string line;
    while(getline(fin, line))       //counts lines of file
        count++;
    fin.close();
    return count;
}

bool check_resp(bool numeric){       //to check yes/no or 0/1
    string resp="init";
    if(!numeric){    // wants user to give char
        while(resp != "y" && resp != "Y" && resp != "n" && resp != "N")
            cin>>resp;
        return (resp == "y" || resp == "Y");
    }
    int choice = 2;
    do{
        cin>>resp;
        choice = std::stoi(resp);   //if exception, will be handled in end of main
    }while(choice != 1 && choice != 0);
    
    return choice;
}