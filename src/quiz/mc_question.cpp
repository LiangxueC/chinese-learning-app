#include "mc_question.h"
#include <iostream>

using namespace std;

MCQuestion::MCQuestion(const string& prompt,
                       const vector<string>& choices,
                       int correctIndex)
    : prompt(prompt),
      choices(choices),
      correctIndex(correctIndex)
{
}
bool MCQuestion::ask()
{
    cout << "Multiple Choice Question" << endl;
    cout << prompt << endl;
    for(size_t i = 0; i < choices.size(); ++i)
    {
        cout << i + 1 << ". " << choices[i] << endl;
    }
    cout << "> ";
    int answer;
    cin >> answer;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return (answer - 1) == correctIndex;
}