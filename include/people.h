#ifndef PEOPLE_H
#define PEOPLE_H

#include "utils.h"

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

        friend ostream &operator<<(ostream &left, Person person);
        friend ofstream &operator<<(ofstream &ofs, Person person);
        friend istream &operator>>(istream &in, Person &person);

        virtual Person& operator+=(Course* course);
        virtual Person& operator-=(Course* course);

        virtual void edit(bool in_name, bool in_surname, bool in_mail, bool in_age);
        virtual void edit(bool in_name, bool in_surname, bool in_mail, bool in_age,
        bool in_am, bool in_ects, bool in_sem);

        virtual Person* clone();
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
		Student(map<Course*, double> &sub, const string in_name, const string in_surname, const string mail, 
        const int in_age, const int am, const int ects, const int sem);
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

        bool gets_degree(vector<Course*> mand_courses);

        virtual void edit(bool in_name, bool in_surname, bool in_mail, bool in_age,
        bool in_am, bool in_ects, bool in_sem) override;

        virtual Student* clone() override;

        friend ofstream& operator<<(ofstream& ofs, const Student& student);
        friend ostream& operator<<(ostream& os, const Student& student);
};

class Professor: public Person{
	private:
        vector<Course*> courses;

    public:
        Professor();
        Professor(const string in_name, const string in_surname, const string in_mail, const int in_age);
        Professor(Professor& prof);
        ~Professor();

        vector<Course*> get_courses();

        virtual Professor& operator+=(Course* course) override;
        virtual Professor& operator-=(Course* course) override;

        virtual Professor* clone() override;
};

#endif