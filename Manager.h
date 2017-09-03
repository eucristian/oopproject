#ifndef TRAININGS_MANAGER_H
#define TRAININGS_MANAGER_H


#include <iostream>
#include <set>
#include <unordered_set>
#include <bits/unique_ptr.h>
#include "Student.h"
#include "EvaluationChart.h"
#include "ProgrammingCourse.h"
#include "MathematicsCourse.h"
#include "DrivingCourse.h"
#include "LanguageCourse.h"

class Manager {
private:
    std::vector<Student> m_students;
    std::vector<Course*> m_courses;
    std::vector<Program> m_programs;
    std::vector<ProgrammingCourse> m_programming_courses;
    std::vector<MathematicsCourse> m_math_courses;
    std::vector<DrivingCourse> m_driving_courses;
    std::vector<LanguageCourse> m_language_courses;
    std::vector<Course> m_normal_courses;

    Student* student_by_name(const std::string&);
    const Course* course_by_name(const std::string&);
    const Program* program_by_name(const std::string&);

    bool add_student(std::string);
    void print_program_list();
    void ask_for_grades(Student*, const Program*, std::unordered_set<const Course*>&);
    bool verify_enrollment(const Student*, const Program*);
    EvaluationChart enroll_student(Student*, const Program*, std::unordered_set<const Course *>&);

public:
    Manager();
    void start();
    void statistic_by_cursant(Student*);
    void statistics_by_qualification(std::string&, std::string&);
};


#endif //TRAININGS_MANAGER_H
