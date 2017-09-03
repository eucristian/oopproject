#include "Manager.h"

Student* Manager::student_by_name(const std::string &name) {
    auto it = std::find_if(
            m_students.begin(),
            m_students.end(),
            [&name](Student s) {
                return s.get_name() == name;
            }
    );
    if (it == m_students.end())
        return NULL;
    return &(*it);
};

const Course* Manager::course_by_name(const std::string &name) {
    auto it = std::find_if(
            m_courses.begin(),
            m_courses.end(),
            [&name](Course* c) {
                return c->get_full_name().substr(0, name.size()) == name;
            }
    );
    return (*it);
};

const Program* Manager::program_by_name(const std::string &name) {
    auto it = std::find_if(
            m_programs.begin(),
            m_programs.end(),
            [&name](Program p) {
                return p.get_full_name().substr(0, name.size()) == name;
            }
    );
    return &(*it);
};

Manager::Manager() {
    // Add courses
    m_programming_courses.emplace_back(ProgrammingCourse("Programare Elementara", "C++", {"OOP"}));
    m_programming_courses.emplace_back(ProgrammingCourse("Programare Elementara", "C++", {"OOP"}));
    m_programming_courses.emplace_back(ProgrammingCourse("Programare Elementara", "JAVA", {"OOP"}));
    m_programming_courses.emplace_back(ProgrammingCourse("Programare Elementara", "C", {"OOP"}));
    for (int i = 0; i < m_programming_courses.size(); ++i)
         m_courses.push_back(&m_programming_courses[i]);

    m_language_courses.emplace_back(LanguageCourse("Limba straina", "Engleza"));
    m_language_courses.emplace_back(LanguageCourse("Limba straina", "Turca"));
    for (int i = 0; i < m_language_courses.size(); ++i)
        m_courses.push_back(&m_language_courses[i]);

    m_math_courses.emplace_back(MathematicsCourse("Matematica", "Algebra"));
    m_math_courses.emplace_back(MathematicsCourse("Matematica", "Geometrie"));
    m_math_courses.emplace_back(MathematicsCourse("Matematica", "Analiza"));
    for (int i = 0; i < m_math_courses.size(); ++i)
        m_courses.push_back(&m_math_courses[i]);

    m_normal_courses.emplace_back(Course("Resurse umane"));
    m_normal_courses.emplace_back(Course("Financiar"));
    m_normal_courses.emplace_back(Course("Legislatie Auto"));
    m_normal_courses.emplace_back(Course("Comunicare NLP"));
    for (int i = 0; i < m_normal_courses.size(); ++i)
        m_courses.push_back(&m_normal_courses[i]);

    m_driving_courses.emplace_back(DrivingCourse("Sofat practic", "Tir"));
    m_driving_courses.emplace_back(DrivingCourse("Sofat practic", "Masina"));
    for (int i = 0; i < m_driving_courses.size(); ++i)
        m_courses.push_back(&m_driving_courses[i]);



    //Add programs
    m_programs.emplace_back(Program("Finantist",
                                  {course_by_name("[Mate] Algebra"),
                                   course_by_name("Financiar")},
                                  {}));
    m_programs.emplace_back(Program("Manager",
                                  {course_by_name("Resurse umane"),
                                   course_by_name("Financiar"),
                                   course_by_name("[Limba] Engleza")},
                                  {}));
    m_programs.emplace_back(Program("Programator",
                                  {course_by_name("[Mate] Algebra"),
                                   course_by_name("[Mate] Geometrie"),
                                   course_by_name("[Mate] Analiza"),
                                   course_by_name("[Programare]"),
                                   course_by_name("[Limba] Engleza"),},
                                  {}));
    m_programs.emplace_back(Program("Manager Echipa Programatori",
                                  {course_by_name("[Programare]"),
                                   course_by_name("Comunicare NLP")},
                                  {}));
    m_programs.emplace_back(Program("Sofer",
                                  {course_by_name("Legislatie Auto"),
                                   course_by_name("[DrivingCourse]")},
                                  {}));
    m_programs.emplace_back(Program("Manager echipa de turisti",
                                  {course_by_name("[Limba] Turca"),
                                   course_by_name("Legislatie Auto")},
                                  {}));
    m_programs[3].add_program(program_by_name("Manager"));
    m_programs[5].add_program(program_by_name("Manager"));
}

void Manager::print_program_list() {
    for (int i = 0; i < m_programs.size(); ++i) {
        std::cout << i << ". " << m_programs[i].get_full_name() << "\n";
    }
}

void Manager::start() {
    std::string student_name, qualification, level;
    int program_id, n, stats;
    Student* student;
    const Program* program;

    std::cout << "Cati cursanti sosesc? ";
    std::cin >> n;
    while(n--) {
        // Adauga un student nou sau vine un student vechi
        std::cout << "Introdu numele studentului: ";
        std::cin >> student_name;
        auto added = add_student(student_name);
        if (!added) {
            std::cout << "Bine ai revenit " << student_name << "\n";
        }
        student = student_by_name(student_name);

        // Citeste program
        do {
            std::cout << "Alege un program pe care vrei sa-l urmezi selectand numarul corespunzator:\n";
            print_program_list();
            std::cin >> program_id;
            if (!(0 <= program_id && program_id < m_programs.size())) {
                std::cout << "Nr invalid\n";
            }
        }while (!(0 <= program_id && program_id < m_programs.size()));
        program = &m_programs[program_id];


        //Inscrie studentul
        std::unordered_set<const Course*> done_courses;
        auto cs = student->get_done_courses();
        for (auto c : cs)
            done_courses.insert(c);
        auto chart = enroll_student(student, program, done_courses);

        if (chart.get_pres() != -1) {
            //Afiseaza nota finala + competenta
            if (chart.get_passed() == true) {
                std::cout << "Nota finala: " << chart.get_final_grade() << " Competenta: " << chart.get_qualification()
                          <<" Nivel: " << chart.get_level() << "\n";
            }
            else {
                std::cout << "Nota finala: " << chart.get_final_grade() << ". Din pacate nu ai promovat acest program.\n";
            }
        }
    }

    while (true) {
        std::cout << "Statistici oferite: \n";
        std::cout << "0.Statistica per cursant\n1.Statistica per competenta\n";
        std::cin >> stats;
        if (stats != 0 && stats != 1)
            break;
        if (stats == 0) {
            std::cout << "Introdu numele cursantului: ";
            std::cin >> student_name;
            student = student_by_name(student_name);
            if (student == NULL) {
                std::cout << "Nu exista niciun student cu acest nume\n";
                continue;
            }
            statistic_by_cursant(student);
        }
        else {
            std::cout << "Introdu numele competentei: ";
            std::cin >> qualification;
            std::cout << "Introdu nivelul: ";
            std::cin >> level;
            statistics_by_qualification(qualification, level);
        }
    }
}

bool Manager::verify_enrollment(const Student* student, const Program* program) {
    std::vector<EvaluationChart> charts = student->get_charts_by_program(program);
    if (charts.size() == 0) { return true; }
    double min_grade = charts[0].get_final_grade(), max_grade = charts[0].get_final_grade();
    for (auto chart : charts) {
        double grade = chart.get_final_grade();
        if (grade < min_grade)
            min_grade = grade;
        if (grade > max_grade)
            max_grade = grade;
    }
    //Verifica daca studentul a picat programul dar totusi la fiecare prezentare are mai mult de nota 3
    if (min_grade >= 3 && max_grade < 5)
        return true;
    return false;
}

EvaluationChart Manager::enroll_student(Student* student, const Program* program, std::unordered_set<const Course*>& done_courses) {
    if (!verify_enrollment(student, program)) {
        std::cout << "Imi pare rau dar deja ai facut programul acesta si din cauza notelor nu-l poti reface\n";
        auto charts = student->get_charts_by_program(program);
        return charts.back();
    }
    EvaluationChart evaluationChart(student, program, student->get_next_pres_number(program));
    ask_for_grades(student, program, done_courses);
    evaluationChart.add_grades();
    evaluationChart.compute_final_grade_and_qualification();
    student->add_evaluation_chart(evaluationChart);
    return evaluationChart;
}

void Manager::ask_for_grades(Student* student, const Program* program, std::unordered_set<const Course*>& done_courses) {
    std::vector<const Course*> courses = program->get_courses();
    for (const Course* course : courses) {
        if (done_courses.find(course) == done_courses.end()) {
            auto grades = course->ask_for_grades();
            double gr = course->calculate_final_grade(grades.first, grades.second);
            student->add_course(course, gr);
            done_courses.insert(course);
            std::cout << "Nota curs " << course->get_full_name() << ": " << gr << "\n";
        }
        else {
            std::cout << "Ai mai facut cursul " << course->get_full_name() << " si ai obtinut nota: "
                      << student->get_grade_of_course(course) << ". Doresti sa refaci cursul? (da/nu)\n";
            std::string ans;
            std::cin >> ans;
            if (ans == "nu") {
                done_courses.insert(course);
                continue;

            } else {
                auto grades = course->ask_for_grades();
                double gr = course->calculate_final_grade(grades.first, grades.second);
                student->add_course(course, gr);
                done_courses.insert(course);
                std::cout << "Nota curs " << course->get_full_name() << ": " << gr << "\n";
            }
        }
    }

    std::vector<const Program*> programs = program->get_programs();
    for (const Program* prg : programs) {
        auto charts = student->get_charts_by_program(program);
        if (charts.size() == 0) {
            enroll_student(student, prg, done_courses);
        }
        else {
            ask_for_grades(student, prg, done_courses);
        }
    }
}

bool Manager::add_student(std::string name) {
    Student* student = student_by_name(name);
    if (student != NULL)
        return false;
    m_students.emplace_back(name);
    return true;
}

void Manager::statistic_by_cursant(Student* student) {
    auto charts = student->get_all_charts();
    int cnt = 0;
    std::cout << student->get_name() << ": ";
    for (auto chart : charts) {
        if (chart.get_passed()) {
            std::cout << chart.get_qualification() << " la nivel " << chart.get_level() << "\n";
            ++cnt;
        }
    }
    std::cout << "Nu are competente\n";
}

void Manager::statistics_by_qualification(std::string& q, std::string& l) {
    int cnt = 0;
    if (l != "mic" && l != "mare" && l != "mediu") {
        std::cout << "Eroare\n";
        return;
    }
    for (auto student : m_students) {
        auto qualifications = student.get_all_charts();
        for (auto chart : qualifications) {
            if (chart.get_passed()) {
                if (chart.get_qualification() == q) {
                    if (l == "mic")
                        ++cnt;
                    if (l == "mediu" && chart.get_level() != "mic")
                        ++cnt;
                    if (l == "mare" && chart.get_level() == "mare")
                        ++cnt;
                }
            }
        }
    }
    std::cout << cnt << " student(i) au competenta " << q << " la un nivel mai mare ca " << l << "\n";
}
