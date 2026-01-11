#ifndef QUIZ_QUESTION_H
#define QUIZ_QUESTION_H

#include "../core/vocab_manager.h"

class QuizQuestion
{
    public:
    virtual ~QuizQuestion() {};
    virtual bool ask() = 0;
};

#endif