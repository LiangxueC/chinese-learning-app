#include "grammar_lesson_manager.h"
#include <fstream>
#include <sstream>
using namespace std;

GrammarLessonManager::GrammarLessonManager()
    :currentLessonIndex(-1), currentQuestionIndex(0){}

void GrammarLessonManager::loadLessons(const string& filename)
{
    lessons.clear();
    ifstream ifile(filename);
    if(!ifile.is_open())
    {
        return;
    }
    string line;
    while(getline(ifile, line))
    {
        stringstream ss(line);
        GrammarLesson l;
        string i;
        getline(ss, i, '|');
        l.index = stoi(i);

        getline(ss,l.concept, '|');
        getline(ss, l.explanation, '|');
        getline(ss, l.pattern, '|');

        for(int i = 0; i < 2; i++)
        {
            string ex;
            getline(ss, ex, '|');
            l.examples.push_back(ex);
        }

        for(int i = 0; i < 3; i++)
        {
            GrammarQ q;
            getline(ss, q.prompt, '|');
            getline(ss, q.correctAnswer, '|');
            l.questions.push_back(q);
        }

        lessons.push_back(l);
    }
}

bool GrammarLessonManager::startLesson(int index)
{
    if(index < 0 || static_cast<size_t>(index) >= lessons.size()) return false;
    currentLessonIndex = index;
    currentQuestionIndex = 0;
    return true;
}

const GrammarLesson* GrammarLessonManager::getCurrentLesson() const
{
    if(currentLessonIndex < 0 || static_cast<size_t>(currentLessonIndex) >= lessons.size())
    {
        return nullptr;
    }
    return &lessons[currentLessonIndex];
}

bool GrammarLessonManager::hasNextQuestion() const
{
    if(currentLessonIndex < 0) return false;
    return static_cast<size_t>(currentLessonIndex) < lessons[currentLessonIndex].questions.size();
}

GrammarQ GrammarLessonManager::getNextQuestion()
{
    return lessons[currentLessonIndex].questions[currentQuestionIndex++];
}

vector<GrammarQ> GrammarLessonManager::getAllGQ()
{
    vector<GrammarQ> gq;
    for(size_t i = 0; i < lessons.size(); i++)
    {
        for(size_t j = 0; j < lessons[i].questions.size(); j++)
        {
            gq.push_back(lessons[i].questions[j]);
        }
    }
    return gq;
}