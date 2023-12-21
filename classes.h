#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>


using namespace std;

class Course;
class Student;

class Person{
    protected:
        string name;
        string surname;
        string mail;
        int age;
        bool type;

    public:
        Person();
        Person(Person *ptr);
        Person(const string in_name, const string in_surname, const string mail, const int in_age, const bool in_type);
        Person(Person& person);
        virtual ~Person();

        static int count;

        string get_name() const;
        string get_surname() const;
        string get_mail() const;
        int get_age() const;
        bool get_type() const;

        void set_name(string in_name);
        void set_surname(string in_surname);
        void set_mail(string in_mail);
        void set_age(int in_age);
        void set_type(bool in_type);

        friend ostream &operator<<(ostream &left, const Person person);
        friend istream &operator>>(istream &in, Person &person);

        virtual Person& operator+=(Course* course);
        virtual Person& operator-=(Course* course);

        virtual void edit(bool in_mail, bool in_age);
        virtual void edit(bool in_mail, bool in_age, bool in_am, bool in_ects, bool in_sem);

        virtual Person* clone();
};

class Secretary{
    private:
        vector<Person*> data;
        vector<Course*> courses;

    public:
        Secretary();
        Secretary(vector<Person> in_vec);     //constructors based on vectors
        Secretary(vector<Person*> in_vec);
        Secretary(Secretary& secretary);
        ~Secretary();

        vector<Person*> get_data();
        int get_count() const;

        Secretary& operator+(Person person);     //adds Person or Person*
        Secretary& operator+(Person* person);
        Secretary& operator+=(Person person);
        Secretary& operator+=(Person* person);

        Secretary &operator=(Secretary secretary);

        friend ostream &operator<<(ostream &left, Secretary &secretary);
        friend istream &operator>>(istream &in, Secretary &secretary);

        Person* find(const string in_name, const string in_surname);
        Person* find(Person person);                 //find based on different args
        Person* find(Person* person);

        vector<Student*> students_graduate();

        Secretary& operator-=(Person* person);

        Secretary& operator+=(Course* course);
        Secretary& operator-=(Course* course);

        Course* find(string in_name);

        void show_courses();

};

class Student: public Person{
    private:
        int AM;
        int ECTS;
        int semester;
        //map apo mathimata
        map<Course*, double> subjects;

	public:
		Student();
		Student(const string in_name, const string in_surname, const string mail, 
        const int in_age, const int am, const int ects, const int sem, map<Course*, double> sub);
		Student(Student& student);
        ~Student();
		
		int get_ECTS() const;
		int get_AM() const;
        int get_semester() const;
		map<Course*, double> get_map();

		void set_ECTS(int ects);
		void set_AM(int am);
        void set_semester(int sem);

        virtual Student& operator+=(Course* course) override;
        virtual Student& operator-=(Course* course) override;
        double& operator[](Course* course);

        bool passed_course(Course* course);
        double course_grade(Course* course);

        bool gets_degree() const;

        virtual void edit(bool in_mail, bool in_age, bool in_am, bool in_ects, bool in_sem) override;

        virtual Student* clone() override;
        void show_courses();
        friend ostream& operator<<(ostream& os, const Student& student) {
            os << "Name: " << student.name << "Surname: " << student.surname << ", Age: " << student.age;
            os << "AM: " << student.AM << endl;
            return os;
        }
};

class Professor: public Person{
	private:
        vector<Course*> courses;

    public:
        Professor();
        Professor(const string in_name, const string in_surname, const string in_mail,
        const int in_age, vector<Course*> in_courses);
        Professor(Professor& prof);
        ~Professor();

        vector<Course*> get_courses();

        virtual Professor& operator+=(Course* course) override;
        virtual Professor& operator-=(Course* course) override;

        virtual Professor* clone() override;

};

class Course{
    private:
        string name;
        int ECTS;
        bool mandatory;
        int semester;
        vector<Person*> people;     //both students and profs
        int passed;
        int failed;
        //na prosthetoume ton vathmo

    public:
        Course();
        Course(const string name, const int ects, bool mand, const int sem,
        vector<Person*> in_people, const int in_passed, const int in_failed);
        Course(Course *ptr);
        ~Course();

        int get_ECTS() const;
        string get_name() const;
        bool is_mandatory() const;
        int get_semester() const;
        vector<Person*> get_people();
        int get_passed() const;
        int get_failed() const;

        void set_name(string nam);
        void set_ECTS(int ects);
        void set_mandatory(bool value);
        void set_semester(int sem);
        void set_passed(int pass);
        void set_failed(int fail);


        void set_professors(vector<Professor*> in_profs);

        void incr_passed();
        void incr_failed();

        double get_avg_grade();

        Course& operator+=(Person* per);
        Course& operator-=(Person* per);

        void edit(bool name, bool ects, bool mand, bool sem, bool passed, bool failed);
};

#endif