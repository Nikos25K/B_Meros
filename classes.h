#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person{
    protected:
        string name;
        string surname;
        string mail;
        int age;
        vector<string> subjects;    //subjects that teaches or studies
        
    public:
        Person();
        Person(const Person *ptr);
        Person(const string in_name, const string in_surname, const string mail ,const int in_age, const vector<string> in_subjects);
        Person(const Person& person);
        ~Person();
        
        static int count;

        string get_name() const;
        string get_surname() const;
        string get_mail() const;
        int get_age() const;
        vector<string> get_subjects() const;

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
	float ECTS;

	public:
		Student();
		Student(const int am, const float ects, const string in_name, const string in_surname,
        const string mail, const int in_age, const vector<string> in_subjects);
		Student(const Student& student);
        ~Student();
		
		float get_ECTS() const;
		int get_AM() const;

		void set_AM(int am);
		void set_ECTS(float ects);
};

class Professor{
	
};

class Course{
	
};