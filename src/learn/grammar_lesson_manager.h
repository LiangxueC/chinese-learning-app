#pragma once
#include <vector>
#include <string>
#include "grammar_lesson.h"

class GrammarLessonManager
{
    private:
    vector<GrammarLesson> lessons;
    int currentLessonIndex;
    int currentQuestionIndex;


    public:
    GrammarLessonManager();

    void loadLessons(const string& filename);
    bool startLesson(int index);

    const GrammarLesson* getCurrentLesson() const;
    bool hasNextQuestion() const;
    GrammarQ getNextQuestion();
    vector<GrammarQ> getAllGQ();
};

