#ifndef TRAININGS_MATHEMATICSCOURSE_H
#define TRAININGS_MATHEMATICSCOURSE_H


#include "Course.h"

class MathematicsCourse : public Course {
    std::string m_type;

public:
    MathematicsCourse(std::string name,
                      std::string type);

    std::string get_full_name() const;
};

#endif //TRAININGS_MATHEMATICSCOURSE_H
