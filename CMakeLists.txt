cmake_minimum_required(VERSION 3.8)
project(trainings)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Student.cpp Student.h Course.cpp Course.h ProgrammingCourse.cpp ProgrammingCourse.h LanguageCourse.cpp LanguageCourse.h MathematicsCourse.cpp MathematicsCourse.h DrivingCourse.cpp DrivingCourse.h Program.cpp Program.h EvaluationChart.cpp EvaluationChart.h Manager.cpp Manager.h)
add_executable(trainings ${SOURCE_FILES})