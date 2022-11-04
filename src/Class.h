#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include "Schedule.h"

using namespace std;

class Class {
    private:
        string classCode_;
        vector<pair<int, string>> students_; // ordenado por código
        Schedule schedule_;
        map<string, int> occupation_;

    public:
        // constructor
        Class(string classCode, Schedule schedule);

        // methods
        string get_classCode() const;
        vector<pair<int, string>> get_students() const;
        Schedule get_schedule() const;
        map<string, int> get_occupation() const;

        void print_students(bool by_code, bool descending) const;
        void add_student(int studentCode, string studentName, string ucCode);
        void remove_student(string studentName);//por implementar
        int size() const;

        bool equals(Class anime);
        bool operator<(const Class& c) const; // overloading
};

#endif