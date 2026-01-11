#include "vocab_manager.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <random>
using namespace std;

VocabManager::VocabManager(const std::string& path)
: path(path)
{

}

void VocabManager::load()
{
    words.clear();
    ifstream ifile(path);
    if(!ifile.is_open())
    {
        //cout << "FAILED to open vocab file: " << path << endl;
        return;
    }
    string line;
    while(getline(ifile, line))
    {
        stringstream ss(line);
        Word w;
        getline(ss, w.word, '|');
        getline(ss, w.pinyin, '|');
        getline(ss, w.definition, '|');
        // cout << "Loaded: " << w.word << endl;
        words.push_back(w);
    }
}

const Word& VocabManager::getRandom()
{
    static const Word emptyWord{};
    if(words.empty())
    {
        return emptyWord;
    }
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(0, words.size() - 1);
    return words[dist(gen)];
}

Word VocabManager::lookup(const string& target)
{
    for(const auto& w : words)
    {
        if(w.word == target)
        {
            return w;
        }
    }
    return Word{};
}

bool VocabManager::addWord(const Word& w)
{
    for(const auto& existing : words)
    {
        if(existing.word == w.word)
        {
            return false;
        }
    }
    words.push_back(w);
    return true;
}

void VocabManager::save()
{
    ofstream ofile(path);
    if(!ofile.is_open())
    {
        return;
    }
    for(const auto& w : words)
    {
        ofile << w.word << "|" << w.pinyin << "|" 
        << w.definition << "\n";
    }
}