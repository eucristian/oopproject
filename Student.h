#ifndef TRAININGS_STUDENT_H
#define TRAININGS_STUDENT_H

#include <string>
#include "Course.h"
#include "Program.h"

class EvaluationChart;

class Student {
private:
    std::string m_name;
    std::map<const Course*, double> m_done_courses_with_grades;
    std::vector<const Course*> m_done_courses;
    std::vector<EvaluationChart> m_done_programs;
public:
    Student(const std::string&);

    //Adauga un curs facut
    void add_course(const Course*, double);

    //Adauga o fisa de evaluare (un program facut)
    void add_evaluation_chart(EvaluationChart);

    //Get-ere
    std::string get_name();
    int get_next_pres_number(const Program*) const;
    double get_grade_of_course(const Course*)const;
    std::vector<EvaluationChart> get_charts_by_program(const Program*) const;
    std::vector<const Course*> get_done_courses()const;
    std::vector<EvaluationChart> get_all_charts();
};

#endif //TRAININGS_STUDENT_H
