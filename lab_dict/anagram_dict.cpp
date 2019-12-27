/**
 * @file anagram_dict.cpp
 * Implementation of the AnagramDict class.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "anagram_dict.h"

#include <algorithm> /* I wonder why this is included... */
#include <fstream>

using std::string;
using std::vector;
using std::ifstream;

/**
 * Constructs an AnagramDict from a filename with newline-separated
 * words.
 * @param filename The name of the word list file.
 */
AnagramDict::AnagramDict(const string& filename)
{
    /* Your code goes here! */
    ifstream wordsFile(filename);
    string word;
    if (wordsFile.is_open()) {
    /* Reads a line from `wordsFile` into `word` until the file ends. */
      while (getline(wordsFile, word)) {
        string sortedWord=word;
        sort(sortedWord.begin(),sortedWord.end());
        dict[sortedWord].push_back(word);
      }
    }

}

/**
 * Constructs an AnagramDict from a vector of words.
 * @param words The vector of strings to be used as source words.
 */
AnagramDict::AnagramDict(const vector<string>& words)
{
    /* Your code goes here! */
    for(string word:words){
      string sortedWord=word;
      sort(sortedWord.begin(),sortedWord.end());
      dict[sortedWord].push_back(word);
    }
}

/**
 * @param word The word to find anagrams of.
 * @return A vector of strings of anagrams of the given word. Empty
 * vector returned if no anagrams are found or the word is not in the
 * word list.
 */
vector<string> AnagramDict::get_anagrams(const string& word) const
{
    /* Your code goes here! */
    string sortedWord=word;
    sort(sortedWord.begin(),sortedWord.end());
    std::map<std::string, std::vector<std::string>>::const_iterator lookup=dict.find(sortedWord);
    if(lookup==dict.end()){
      return vector<string>();
    }
    else{
      return lookup->second;
    }
    // return vector<string>();
}

/**
 * @return A vector of vectors of strings. Each inner vector contains
 * the "anagram siblings", i.e. words that are anagrams of one another.
 * NOTE: It is impossible to have one of these vectors have less than
 * two elements, i.e. words with no anagrams are ommitted.
 */
vector<vector<string>> AnagramDict::get_all_anagrams() const
{
    /* Your code goes here! */
    vector<vector<string>> ret;
    for(std::pair<std::string, std::vector<std::string>> pair:dict){
      if(pair.second.size()>=2){
        ret.push_back(pair.second);
      }
    }
    return ret;
    // return vector<vector<string>>();
}
