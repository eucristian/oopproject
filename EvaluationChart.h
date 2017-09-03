#ifndef TRAININGS_EVALUATIONCHART_H
#define TRAININGS_EVALUATIONCHART_H


#include "Student.h"
#include "Program.h"

class EvaluationChart {
private:
    Student* m_student;
    const Program* m_program;
    int m_pres;
    double m_final_grade;
    bool m_passed;
    std::vector<double> m_grades;
    std::string m_level;
    std::string m_qualification;
public:
    EvaluationChart(Student* student,
                    const Program* program,
                    int pres);

    //Adauga note finale a cursurilor/programelor din care este alcatuit programul
    void add_grades();

    //Calculeaza nota finala a programului urmat si seteaza competenta
    void compute_final_grade_and_qualification();

    //Get-ere
    const Program* get_program() const;
    int get_pres() const;
    double get_final_grade() const;
    std::string get_level();
    std::string get_qualification();
    bool get_passed()const;
};


#endif //TRAININGS_EVALUATIONCHART_H
