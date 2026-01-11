#include "grammar_learner.h"
#include <iostream>

using namespace std;

GrammarLearner::GrammarLearner(GrammarLessonManager& factory)
    : factory(factory)
{
}

void GrammarLearner::startLearning()
{
    cout << "\nGrammar Learning Mode" << endl;
    cout << "Type 'q' at any time to quit. " << endl;
    factory.loadLessons("grammar.txt");
    // while(true)
    // {
    //     if(!q)
    //     {
    //         cout << "No grammar questions available." << endl;
    //         break;
    //     }

    //     bool correct = q->ask();
    //     delete q;

    //     if (correct)
    //         cout << "Correct!\n";
    //     else
    //         cout << "Incorrect. Try to understand why.\n";

    //     cout << "Continue learning? (y/q): ";
    //     char choice;
    //     cin >> choice;

    //     if (choice == 'q')
    //     {
    //         cout << "Exiting Grammar Learning Mode.\n";
    //         break;
    //     }
    // }
}