#ifndef BATTLE_SYSTEM_H
#define BATTLE_SYSTEM_H

#include "battle_character.h"
#include "../quiz/quiz_factory.h"

class BattleSystem {
private:
    BattleCharacter player;
    BattleCharacter monster;
    QuizFactory& factory;

public:
    BattleSystem(QuizFactory& factory);
    void chooseElement();
    void startBattle();
};

#endif
