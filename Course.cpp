#include <iostream>
#include "Course.h"

Course::Course(std::string name) : m_name(name) {}

std::string Course::get_full_name() const {
    return m_name;
}


double Course::calculate_final_grade(std::vector<double> practice, double exam) const {
    double average = 0;

    for (auto grade : practice)
        average += grade;
    average /= practice.size();

    return (average * 3 + exam) / 4;
}

std::pair<std::vector<double>, double> Course::ask_for_grades() const {
    std::pair<std::vector<double>, double> ans = std::make_pair(std::vector<double>(3), 0.0);
    std::cout << "Introdu cele 3 note de la Lucrarile Practice pentru cursul " << get_full_name() << ":\n";
    for (int i = 0; i < 3; i++) {
        while (true) {
            std::cin >> ans.first[i];
            if (ans.first[i] >= 0 && ans.first[i] <= 10)
                break;
            std::cout << "\nEroare: nota trebuie sa fie un nr zecimal intre 1 si 10. Reintrodu nota: ";
        }
    }
    std::cout << "Introdu nota de la examenul final: ";
    while (true) {
        std::cin >> ans.second;
        if (ans.second >= 0 && ans.second <= 10)
            break;
        std::cout << "\nEroare: nota trebuie sa fie intre 1 si 10. Reintrodu nota: ";
    }
    return ans;
}
