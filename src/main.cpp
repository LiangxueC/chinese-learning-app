#include "learn/grammar_lesson_manager.h"
#include "learn/learn_mode.h"
#include "quiz/grammar_question.h"
#include "quiz/quiz_factory.h"
#include "quiz/mc_question.h"
#include "quiz/quiz_question.h"
#include "core/grammar_learner.h"
#include "core/battle_system.h"

#include <iostream>

using namespace std;

int main()
{
    cout << "Welcome to my first peoject!" << endl;
    VocabManager vm = VocabManager("data/vocab.txt");
    vm.load();
    GrammarLessonManager gm;
    gm.loadLessons("data/grammar.txt");
    QuizFactory qf = QuizFactory(vm, gm);
    BattleSystem bs = BattleSystem(qf);
    bs.chooseElement();
    cout << "Nice! Now you've chose the element for your hero. Let's start!" << endl;
    cout << "1. Learn" << endl;
    cout << "2. Fight" << endl;
    cout << "> ";
    int mode;
    cin >> mode;
    if(mode == 1)
    {
        startLearningMode(gm);
    }
    if(mode == 2)
    {
        // vector<Word> t = vm.getAll();
        // cout << t.size() << endl;
        bs.startBattle();
    }
    return 0;
}
