#include "ProgrammingCourse.h"

ProgrammingCourse::ProgrammingCourse(std::string name,
                                     std::string language,
                                     std::vector<std::string> tags) :
        Course(name),
        m_language(language),
        m_tags(tags) {}

std::string ProgrammingCourse::get_full_name()const{
    std::string name = "[Programare] (" + m_language;
    for (auto str : m_tags)
        name = name + "#" + str;
    name = name + ")";
    return name;
}

double ProgrammingCourse::calculate_final_grade(std::vector<double> practice, double exam) {
    double average = 0;

    std::sort(practice.begin(), practice.end());
    average = ((practice[0] + practice[practice.size() - 1]) * 3 / 2 + exam) / 4;
    return (average);
}