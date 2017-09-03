#ifndef TRAININGS_PROGRAM_H
#define TRAININGS_PROGRAM_H

#include <string>
#include <cassert>
#include <map>
#include <cmath>
#include "Course.h"

class Program {
private:
    std::string m_name;
    std::vector<const Course*> m_courses;
    std::vector<const Program*> m_programs;
public:
    Program(std::string, std::vector<const Course*>, std::vector<const Program*>);

    //Calculeaza media notelor de la fiecare curs
    double calculate_grade(const std::map<const Course*, int>&) const;

    //Get-ere
    std::string get_full_name() const;
    std::vector<const Course*> get_courses()const;
    std::vector<const Program*> get_programs()const;

    void add_program(const Program*);
};



#endif //TRAININGS_PROGRAM_H
