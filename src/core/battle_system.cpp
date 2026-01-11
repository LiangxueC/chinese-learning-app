#include "battle_system.h"
#include <iostream>

using namespace std;

BattleSystem::BattleSystem(QuizFactory& factory) : factory(factory)
{
    monster = {"Monster", 100, 15};
}

void BattleSystem::chooseElement()
{
    cout << "Choose your element:" << endl;
    cout << "1. Fire (High Damage, Low HP)" << endl;
    cout << "2. Water (Balanced)" << endl;
    cout << "3. Earth (High HP, Low Damage)" << endl;
    cout << "> ";

    int choice;
    cin >> choice;

    if(choice == 1)
    {
        player = {"Fire Hero", 80, 25};
    }
    else if(choice == 2)
    {
        player = {"Water Hero", 100, 18};
    }
    else
    {
        player = {"Earth Hero", 120, 14};
    }
}

void BattleSystem::startBattle()
{
    cout << "\nBattle Start!\n";
    while(player.hp > 0 && monster.hp > 0)
    {
        QuizQuestion* q;
        if (rand() % 2 == 0)
            q = factory.createMCQuestion();
        else
            q = factory.createGrammarQuestion();
        if(!q)
        {
            cout << "Not enough words to continue battle." << endl;
            return;
        }
        bool correct = q->ask();
        delete q;

        if(correct)
        {
            monster.hp -= player.damage;
            cout << "Hit! Monster HP: " << monster.hp << endl;
        }
        else 
        {
            cout << "Miss! Monster attacks!" << endl;
            if(player.hp > 0)
            {
                cout << "Attempt to dodge? (y/n): ";
                char dodge;
                cin >> dodge;

                if(dodge == 'y')
                {
                    QuizQuestion* dodgeQ = factory.createGrammarQuestion();
                    if(dodgeQ && dodgeQ->ask())
                    {
                        cout << "Dodge successful!" << endl;
                    }
                    else
                    {
                        cout << "Dodge failed!" << endl;
                        player.hp -= monster.damage;
                    }
                    delete dodgeQ;
                }
            }
            cout << "Your HP: " << player.hp << endl;
        }
        cout << endl;
    }

    if(player.hp > 0)
    {
        cout << "You defeated the monster!" << endl;
    }
    else
    {
        cout << "You were defeated..." << endl;
    }
}