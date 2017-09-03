#ifndef TRAININGS_DRIVINGCOURSE_H
#define TRAININGS_DRIVINGCOURSE_H

#include "Course.h"

class DrivingCourse : public Course {
    std::string m_car_type;

public:
    DrivingCourse(std::string name,
                  std::string car_type);

    virtual std::string get_full_name()const;
};


#endif //TRAININGS_DRIVINGCOURSE_H
