#include "learn_mode.h"
#include "grammar_lesson_manager.h"
#include <iostream>
using namespace std;

void practiceQuestion(const GrammarQ& q)
{
    string input;
    while (true)
    {
        cout << endl << q.prompt << endl;
        cout << "> ";
        getline(cin, input);

        if (input == q.correctAnswer)
        {
            cout << "Correct!" << endl;
            break;
        }
        else
        {
            cout << "Try again. Hint: think about the pattern." << endl;
        }
    }
}

void startLearningMode(GrammarLessonManager& manager)
{
    cout << "Learning Mode" << endl;
    cout << "-------------" << endl;

    cout << "Enter lesson index (number): ";
    int choice;
    cin >> choice;
    cin.ignore();

    manager.startLesson(choice);
    const GrammarLesson* lesson = manager.getCurrentLesson();
    if(!lesson)
    {
        cout << "Lesson not found." << endl;
        return;
    }

    cout << "\nConcept: " << lesson->concept << endl;
    cout << "\nExplanation: " << lesson->explanation << endl;
    cout << "\nPattern: " << lesson->pattern << endl;

    cout << "\nExamples:\n";
    for (const auto& ex : lesson->examples)
    {
        cout << "- " << ex << endl;
    }
    cout << "\nPractice (type 'q' to quit)\n";

    for (const auto& q : lesson->questions)
    {
        practiceQuestion(q);

        cout << "\nContinue? (enter to continue, q to quit): ";
        string input;
        getline(cin, input);
        if (input == "q")
            break;
    }

    cout << "\nLesson complete!\n";

}