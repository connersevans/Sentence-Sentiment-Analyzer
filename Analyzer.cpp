#include "Sentence.h"
#include "Word.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <boost/algorithm/string.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
using namespace std;
using namespace boost;


vector<Sentence*>* readFile(char* filename) {

	string line;
	vector<Sentence*>* allsentences = new vector<Sentence*>;

	ifstream myfile(filename);

	if (myfile.is_open()) {
	//file opened correctly	
		while (getline(myfile, line)) {

			if (isdigit(line[0])) {
			// Positive number
				// get score
				string space = line.substr(0, 1);
				int score = stoi(space, nullptr, 10);
				if (isalpha(line[2])) {
					string text = line.substr(2, string::npos);
					Sentence *asentence = new Sentence(score, text);
					allsentences->push_back(asentence);
				}
			}
			else if (isdigit(line[1]) && line[0] == '-') {
			// Negative numer
				//get score
				string space = line.substr(1, 2);
				int score = stoi(space, nullptr, 10);
				score = score * (-1);
				if (isalpha(line[3])) {
					string text = line.substr(3, string::npos);
					Sentence *asentence = new Sentence(score, text);
					allsentences->push_back(asentence);
				}
			}
			else {
			// No number, not formatted correctly, ignore

			}
		}
		myfile.close();
		return allsentences;
	}
	else {
	// file failed to open
		printf("Could not open file");
		return NULL;
	}

}





struct wordComparator {
  bool operator() (const Word* lhs, const Word* rhs) const
  {return lhs->getWord() < rhs->getWord();}
};




set<Word*, wordComparator>* allWords(vector<Sentence*>& sentences) {

  // create the set using the wordComparator struct like this:
  set<Word*, wordComparator>* words = new set<Word*, wordComparator>;


  set<Word*>::iterator it;

  for (Sentence* sentence : sentences) {
  	string sent = sentence->getText();
  	vector<string> sentwords;
  	split(sentwords, sent, is_any_of(" ") );

  	for (string str : sentwords) {
  		to_lower(str);
  		if (isalpha(str[0])) {
  		// is a word
  			Word *newword = new Word(str);

  			if (words->find(newword) != words->end()) {
  			// update word in set
  				it = words->find(newword);
  				int score = sentence->getScore();
  				(*it)->increaseTotal(score);

  			}
  			else {
  			// add word to set
  				newword->increaseTotal(sentence->getScore());
  				words->insert(newword);
  			}
  		}
  		else {
  		// ignore	
  		}
  	}
  }

  return words;

}



map<string, double>* calculateScores(set<Word*>& words) {
  

	map<string, double>* wordmap = new map<string, double>;

	set<Word*>::iterator it;

	for (it = words.begin(); it != words.end(); it++) {
		string text = (*it)->getWord();
		double score = (*it)->calculateScore();

		wordmap->insert({text, score});
	}

	return wordmap;
}




double calculateSentenceScore(map<string, double>& scores, string sentence) {


	double totalscore = 0;
	double count = 0;

	vector<string> words;
	split(words, sentence, is_any_of(" ") );

	map<string, double>::iterator it;

	for (string str : words) {
		to_lower(str);

		if (isalpha(str[0])) {
		// is a properly formatted word
			it = scores.find(str);
			if (it != scores.end()) {
			// word is in the map
				totalscore += it->second;
				count++;	
			}
			else {
			// word is not in the map
				totalscore += 0;
				count++;	
			}
		}
		else {
		// not properly formatted word	
		}
	}

	cout << (totalscore / count) << endl;
	return (totalscore / count);
}

