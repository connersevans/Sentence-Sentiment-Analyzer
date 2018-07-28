#include "Sentence.h"
#include "Word.h"
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <set>
#include <map>
using namespace std;


/*
 Declarations of functions declared in Analyzer.cpp
*/

vector<Sentence*>* readFile(char*);
set<Word*>* allWords(vector<Sentence*>&); 
map<string, double>* calculateScores(set<Word*>&);
double calculateSentenceScore(map<string, double>&, string);

int main(int argc, char* argv[]) {


	if (argc != 2) {
		printf("Incorrect amount of arguments");
		return 0;
	}

	char* filename = argv[1];

	vector<Sentence*>* allsentences = readFile(filename);

	set<Word*>* wordset = allWords(*allsentences);

	map<string, double>* wordmap = calculateScores(*wordset);

	
	while (1) {
		cout << "Enter a sentence" << endl;

		string sentence;

		getline(cin, sentence);

		const char* str = sentence.c_str();

		const char* quit = "quit";

		if (strcmp(str, quit) == 0) {
			break;
		}

		calculateSentenceScore(*wordmap, sentence);

	}

	return 0;


}
