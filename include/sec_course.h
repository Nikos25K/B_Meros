#ifndef SEC_COURSES_H
#define SEC_COURSES_H

#include "utils.h"

class Secretary{
    private:
        vector<Person*> data;
        vector<Course*> courses;

    public:
        Secretary();
        Secretary(vector<Person*> in_vec);
        Secretary(Secretary& secretary);
        ~Secretary();

        vector<Person*> get_people();
        vector<Course*> get_courses();
        int get_count() const;

        Secretary &operator=(Secretary secretary);

        friend ostream &operator<<(ostream &left, Secretary &secretary);
        friend istream &operator>>(istream &in, Secretary &secretary);

        Person* find(const string in_name, const string in_surname);
        Person* find(Person person);                 //find based on different args
        Person* find(Person* person);

        vector<Student*> students_graduate();

        Secretary& operator+=(Person* person);
        Secretary& operator-=(Person* person);

        Secretary& operator+=(Course* course);
        Secretary& operator-=(Course* course);

        Course* find(string in_name);

        void add_courses_to_person(Person* person);
        void add_courses_to_person(Course* course);
        void add_courses_to_person(Course* course, Person* per);
        void add_courses_to_person(vector<Course*> vec, Person* per);

        void delete_courses_from_person(Person* per);
        void delete_courses_from_person(Course* course);
        void delete_courses_from_person(Course* course, Person* per);

        Person* get_person(string name, string surname);    //read and check
        Course* get_course(string cour);

        void create_course();
        void create_person(bool flag);
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
        const int in_passed, const int in_failed);
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

        double get_avg_grade();

        Course& operator+=(Person* per);
        Course& operator-=(Person* per);

        void edit(bool name, bool ects, bool mand, bool sem, bool passed, bool failed);
};

#endif