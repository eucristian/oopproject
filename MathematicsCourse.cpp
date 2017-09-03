#include "MathematicsCourse.h"

MathematicsCourse::MathematicsCourse(std::string name,
                                     std::string type) :
        Course(name),
        m_type(type) {}


std::string MathematicsCourse::get_full_name()const{
    return "[Mate] " + m_type;
}