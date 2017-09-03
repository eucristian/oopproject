#ifndef TRAININGS_COURSE_H
#define TRAININGS_COURSE_H

#include <string>
#include <vector>

class Course {
protected:
    std::string m_name;

public:
    Course(std::string name);

    //Calculeaza nota finala
    virtual double calculate_final_grade(std::vector<double> practice, double exam) const;

    //??
    virtual std::pair<std::vector<double>, double> ask_for_grades() const;

    //Get-er
    virtual std::string get_full_name() const;
};


#endif //TRAININGS_COURSE_H
