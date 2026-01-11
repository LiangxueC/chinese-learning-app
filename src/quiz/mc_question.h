#ifndef MC_QUESTION_H
#define MC_QUESTION_H

#include "quiz_question.h"
#include <string>
#include <vector>

class MCQuestion : public QuizQuestion
{
    public: 
    MCQuestion(const std::string& prompt,
               const std::vector<std::string>& choices,
               int correctIndex);
    bool ask() override;
    private:
    std::string prompt;
    std::vector<std::string> choices;
    int correctIndex;
};

#endif