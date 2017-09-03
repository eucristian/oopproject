#ifndef TRAININGS_LANGUAGECOURSE_H
#define TRAININGS_LANGUAGECOURSE_H

#include "Course.h"

class LanguageCourse : public Course {
    std::string m_language;

public:
    LanguageCourse(std::string name,
                   std::string language);

    virtual std::string get_full_name() const;
};


#endif //TRAININGS_LANGUAGECOURSE_H
