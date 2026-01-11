#include "quiz_factory.h"
#include <algorithm>
#include <random>
#include <iostream>
#include <fstream>
#include "../learn/grammar_lesson_manager.h"

using namespace std;

QuizFactory::QuizFactory(VocabManager& vm, GrammarLessonManager&gm) : vocab(vm), grammar(gm){}

QuizQuestion* QuizFactory::createMCQuestion()
{
    auto allWords = vocab.getAll();
    if(allWords.size() < 4) return nullptr;

    static random_device rd;
    static mt19937 gen(rd());

    uniform_int_distribution<> dist(0, allWords.size() - 1);
    Word correct = allWords[dist(gen)];

    vector<string> choices;
    choices.push_back(correct.definition);

    while(choices.size() < 4)
    {
        Word w = allWords[dist(gen)];
        if(w.word != correct.word && find(choices.begin(), choices.end(), w.definition) == choices.end())
        {
            choices.push_back(w.definition);
        }
    }

    shuffle(choices.begin(), choices.end(), gen);
    int correctIndex = distance(choices.begin(), find(choices.begin(), choices.end(), correct.definition));
    return new MCQuestion(correct.word + " (" + correct.pinyin + ")", choices, correctIndex);
}

QuizQuestion* QuizFactory::createGrammarQuestion()
{
    auto allGQ = grammar.getAllGQ();
    if(allGQ.size() == 0) return nullptr;

    static random_device rd;
    static mt19937 gen(rd());

    uniform_int_distribution<> dist(0, allGQ.size() - 1);
    size_t index = dist(gen);

    const GrammarQ& gq = allGQ[index];
    return new GrammarQuestion(gq.prompt, gq.correctAnswer);
}