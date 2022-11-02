#ifndef HELPY_H
#define HELPY_H

#include "Student.h"
#include "UC.h"
#include "Class.h"
#include "Schedule.h"
#include "Request.h"
#include <queue>

class Helpy {
    private:
        set<Student> all_students;
        vector<UC> all_UCs;
        vector<Class> all_classes;

        // mapas usados para processar comandos
        static map<string, int> command, target, what;

        // fila para guardar pedidos
        queue<Request> queuer;
        
    public:
        // constructor
        Helpy(set<Student>& students, vector<UC>& UCs, vector<Class>& classes);

        // methods
        void terminal();
        void advanced_mode();
        void guided_mode();

        void processQueue();
        void rewrite_file();
        
        void display_uc_schedule(bool& valid) const;
        void display_uc_classes(bool& valid) const;
        void display_uc_students(bool& valid) const;

        void display_class_schedule(bool& valid) const;
        void display_class_students(bool& valid) const;

        void display_student_schedule(bool& valid) const;
        void display_student_classes(bool& valid) const;
        void display_student_ucs(bool& valid) const;
        
        void display_all_students() const;

        void add(Request sub);
        void rem(Request sub);
        void change(Request sub);

;
};

#endif