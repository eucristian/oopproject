#ifndef TRAININGS_PROGRAMMINGCOURSE_H
#define TRAININGS_PROGRAMMINGCOURSE_H

#include <algorithm>
#include "Course.h"

class ProgrammingCourse : public Course {
    std::string m_language;
    std::vector<std::string> m_tags;

public:
    ProgrammingCourse(std::string,
                      std::string,
                      std::vector<std::string>);

    //Rescrie modul in care se calculeaza nota finale a cursului
    double calculate_final_grade(std::vector<double>, double);
    virtual std::string get_full_name()const;

};

#endif //TRAININGS_PROGRAMMINGCOURSE_H
