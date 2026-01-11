#ifndef GRAMMAR_QUESTION_H
#define GRAMMAR_QUESTION_H

#include "quiz_question.h"
#include <string>

class GrammarQuestion : public QuizQuestion
{
private:
    std::string prompt;
    std::string correctAnswer;

public:
    GrammarQuestion(const std::string& prompt,
                    const std::string& correctAnswer);

    bool ask() override;
};

#endif
