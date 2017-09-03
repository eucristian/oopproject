#include "EvaluationChart.h"

EvaluationChart::EvaluationChart(Student *student,
                                 const Program *program,
                                 int pres) :
        m_student(student),
        m_program(program),
        m_pres(pres) {}

void EvaluationChart::add_grades() {
    auto courses = m_program->get_courses();
    auto programs = m_program->get_programs();
    for (auto course : courses)
        m_grades.emplace_back(m_student->get_grade_of_course(course));
    for (auto prg : programs) {
        std::vector<EvaluationChart> charts = m_student->get_charts_by_program(prg);
        m_grades.emplace_back(charts[charts.size() - 1].get_final_grade());
    }
}

void EvaluationChart::compute_final_grade_and_qualification() {
    m_final_grade = 0;
    for (auto grade : m_grades)
        m_final_grade += grade;
    m_final_grade = m_final_grade / m_grades.size();
    if (m_final_grade < 5)
        m_passed = false;
    else {
        m_passed = true;
        m_qualification = m_program->get_full_name();

        if (m_final_grade <= 6)
            m_level = "mic";
        else
            if (m_final_grade <= 8)
                m_level = "mediu";
            else m_level = "mare";

    }
}

const Program* EvaluationChart::get_program()const{
    return m_program;
}

int EvaluationChart::get_pres()const {
    return m_pres;
}

double EvaluationChart::get_final_grade() const {
    return m_final_grade;
}

std::string EvaluationChart::get_qualification() {
    return m_qualification;
}

std::string EvaluationChart::get_level() {
    return m_level;
}

bool EvaluationChart::get_passed() const {
    return m_passed;
}
