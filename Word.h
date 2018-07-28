#include <string>
using namespace std;

class Word {

	private: 	string theword;
				int count;
				int total;

	public: 	Word(string str) {
				theword = str;
				count = 0;
				total = 0;
	}

	void increaseTotal(int amount) {
		total = total + amount;
		count++;
	}

	double calculateScore() {
		if (count == 0) {
			return 0;
		}
		return (double) total / (double) count;
	}

	int getCount() {
		return count;
	}

	string getWord() const {
		return theword;
	}

};


