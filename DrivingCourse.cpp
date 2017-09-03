#include "DrivingCourse.h"

DrivingCourse::DrivingCourse(std::string name,
                             std::string car_type) :
        Course(name), m_car_type(car_type) {}

std::string DrivingCourse::get_full_name()const{
    return "[DrivingCourse] " + m_car_type;
}