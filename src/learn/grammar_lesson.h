#ifndef GRAMMAR_LESSON_H
#define GRAMMAR_LESSON_H

#include <string>
#include <vector>
using namespace std;

struct GrammarQ{
    string prompt;
    string correctAnswer;
};

struct GrammarLesson {
    int index;
    string concept;
    string explanation;
    string pattern;
    vector<string> examples;
    vector<GrammarQ> questions;
};


#endif