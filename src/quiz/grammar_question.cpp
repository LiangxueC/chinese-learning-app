#include "grammar_question.h"
#include <iostream>

using namespace std;

GrammarQuestion::GrammarQuestion(const string& prompt,
         const string& correctAnswer) : prompt(prompt), correctAnswer(correctAnswer) {}

bool GrammarQuestion::ask()
{
    cout << "Grammar Question:\n";
    cout << "Put the following words in correct order" << endl;
    cout << prompt << endl;
    cout << "> ";

    string userAnswer;
    cin >> userAnswer;

    return userAnswer == correctAnswer;
}