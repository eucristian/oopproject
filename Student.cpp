#include <algorithm>
#include "Student.h"
#include "EvaluationChart.h"

Student::Student(const std::string &name) : m_name(name) {}

void Student::add_course(const Course* new_course, double grade) {
    m_done_courses_with_grades[new_course] = grade;
    auto res = std::find(m_done_courses.begin(), m_done_courses.end(), new_course);
    if (res == m_done_courses.end())
       m_done_courses.push_back(new_course);
}


void Student::add_evaluation_chart(EvaluationChart new_chart) {
    m_done_programs.emplace_back(new_chart);
}

std::string Student::get_name() {
    return m_name;
}

int Student::get_next_pres_number(const Program* program) const {
    int id = 1;
    for (auto chart : m_done_programs) {
        if (chart.get_program() == program)
            id = std::max(id, chart.get_pres() + 1);
    }
    return id;
}

double Student::get_grade_of_course(const Course* course) const{
    return m_done_courses_with_grades.find(course)->second;
}

std::vector<EvaluationChart> Student::get_charts_by_program(const Program* program) const {
    std::vector<EvaluationChart> charts;
    for (auto chart : m_done_programs) {
        if (chart.get_program() == program)
            charts.emplace_back(chart);
    }
    return charts;
}

std::vector<const Course*> Student::get_done_courses() const {
    return m_done_courses;
}

std::vector<EvaluationChart> Student::get_all_charts() {
    return m_done_programs;
}
