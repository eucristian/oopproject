#include "Program.h"

Program::Program(std::string name,
                 std::vector<const Course*> courses,
                 std::vector<const Program*> programs) :
        m_name(name),
        m_courses(courses),
        m_programs(programs) {}

double Program::calculate_grade(const std::map<const Course*, int>& final_grade_for_courses) const {
    int sum = 0, cnt = 0;
    for (auto course : m_courses) {
        assert(final_grade_for_courses.count(course) == 1);
        sum += final_grade_for_courses.at(course);
        ++cnt;
    }
    for (auto prog : m_programs) {
        sum += prog->calculate_grade(final_grade_for_courses);
        ++cnt;
    }
    assert(cnt);
    return sum/cnt;
}

std::string Program::get_full_name() const {
    return m_name;
}

std::vector<const Course*> Program::get_courses()const {
    return m_courses;
}

std::vector<const Program *> Program::get_programs()const {
    return m_programs;
}


void Program::add_program(const Program* program) {
    m_programs.push_back(program);
}

