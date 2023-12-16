#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Course;

class Person{
    protected:
        string name;
        string surname;
        string mail;
        int age;

    public:
        Person();
        Person(const Person *ptr);
        Person(const string in_name, const string in_surname, const string mail ,const int in_age);
        Person(const Person& person);
        ~Person();

        static int count;

        string get_name() const;
        string get_surname() const;
        string get_mail() const;
        int get_age() const;

        friend ostream &operator<<(ostream &left, const Person person);
        friend istream &operator>>(istream &in, Person &person);
};

class Secretary{
    private:
        vector<Person*> data;

    public:
        Secretary();
        Secretary(const vector<Person> in_vec);     //constructors based on vectors
        Secretary(const vector<Person*> in_vec);
        Secretary(const Secretary& secretary);
        ~Secretary();

        vector<Person*> get_data() const;
        int get_count() const;

        Secretary& operator+(const Person person);     //adds Person or Person*
        Secretary& operator+(const Person* person);
        Secretary& operator+=(const Person person);
        Secretary& operator+=(const Person* person);

        Secretary &operator=(const Secretary secretary);

        friend ostream &operator<<(ostream &left, const Secretary &secretary);
        friend istream &operator>>(istream &in, Secretary &secretary);

        bool find(const string in_name, const string in_surname);
        bool find(const Person person);                 //find based on different args
        bool find(const Person* person);
};

class Student: public Person{
    private:
	int AM;
	int ECTS;
    int semester;
    //map apo mathimata
    map<Course*, int> subjects;


	public:
		Student();
		Student(const int am, const int ects, const string in_name, const string in_surname,
        const string mail, const int in_age);
		Student(const Student& student);
        ~Student();
		
		int get_ECTS() const;
		int get_AM() const;
        int get_sem() const;

		void set_ECTS(int ects);
		void set_AM(int am);            //isos fygei
        void set_sem(void);     //++
        // or friend function that sets sem++
};

class Professor: public Person{
	private:
        vector<Course*> cources;

    public:
        Professor();
        ~Professor();
};

class Course{
	private:
        string name;
        int ECTS;
        bool mandatory;
        int semester;
        vector<Person*> people;     //both students and profs
        int passed;
        int kophkan;
        //na prosthetoume ton vathmo

    public:
        Course();
        Course(const string name, const int ects, bool mand, const int sem,
        const vector<Person*> in_people, const int in_passed, const int in_kophkan);
        Course(const Course *ptr);
        ~Course();

        int get_ECTS() const;
        string get_name() const;
        bool is_mandatory() const;
        int get_semester() const;
        vector<Person*> get_people() const;
        int get_passed() const;
        int get_kophkan() const;

        void set_name(string nam);
        void set_ECTS(int ects);
        void set_mandatory(bool value);
        void set_semester(int sem);

        void set_professors(vector<Professor*> in_profs);

        void incr_passed();
        void incr_kophkan();

        Course& operator+=(const Student* in_student);
        Course& operator+=(const Professor* prof);
};

class Semester{
    private:
        vector<Course*> cources;

    public:
        Semester();
        Semester(const vector<Course*> courses);
        ~Semester();

        vector<Course*> get_cources() const;

        Semester& operator+=(const Course* course);
};