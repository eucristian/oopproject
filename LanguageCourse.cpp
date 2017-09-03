#include "LanguageCourse.h"

LanguageCourse::LanguageCourse(std::string name,
                               std::string language) :
        Course(name),
        m_language(language) {}


std::string LanguageCourse::get_full_name()const{
    return "[Limba] " + m_language;
}