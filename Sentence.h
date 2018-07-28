#include <string>
using namespace std;

class Sentence {

	private: 	int score;
				string text;


	public: 	Sentence(int init1, string init2) {
				score = init1;
				text = init2;
	}

	int getScore() {
		return score;
	}

	string getText() {
		return text;
	}

};
