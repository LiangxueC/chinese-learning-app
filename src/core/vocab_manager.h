#ifndef VOCAB_MANAGER_H
#define VOCAB_MANAGER_H

#include <string>
#include <vector>

struct Word
{
    std::string word;
    std::string pinyin;
    std::string definition;
};

class VocabManager
{
    private:
    std::string path;
    std:: vector<Word> words;
    public:
    VocabManager(const std::string &path);
    void load();
    void save();
    const Word& getRandom();
    Word lookup(const std::string &target);
    std::vector<Word> searchByPinyin(const std::string &pinyin);
    bool addWord(const Word &w);
    const std::vector<Word>& getAll() const{
        return words;
    }

};
#endif