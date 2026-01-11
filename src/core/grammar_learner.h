#ifndef GRAMMAR_LEARNER_H
#define GRAMMAR_LEARNER_H

#include "../quiz/quiz_factory.h"
#include "../learn/grammar_lesson_manager.h"

class GrammarLearner
{
    private:
    GrammarLessonManager& factory;
    public:
    GrammarLearner(GrammarLessonManager& factory);
    void startLearning();
};

#endif