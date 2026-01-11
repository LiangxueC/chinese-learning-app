#ifndef QUIZ_FACTORY_H
#define QUIZ_FACTORY_H

#include "../core/vocab_manager.h"
#include "quiz_question.h"
#include "mc_question.h"
#include "grammar_question.h"
#include "../learn/grammar_lesson_manager.h"

class QuizFactory
{
    private:
    VocabManager& vocab;
    GrammarLessonManager& grammar;
    public:
    QuizFactory(VocabManager& vm, GrammarLessonManager& gm);
    QuizQuestion* createMCQuestion();
    QuizQuestion* createGrammarQuestion();
};
#endif