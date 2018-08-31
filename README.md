# Sentence-Sentiment-Analyzer
This is a C++ program that analyzes the sentiment of a sentence based on the words it contains.

The algorithm utilized in this program assigns a numeric value to any given word and then determines the overall sentiment of a sentence by averaging the values of the words it contains. 

To determine the value of a word, we were given a file of statements, each of which has a score depenending on how positive or negative the sentence is. Therefore, the value of a word is the average of the sentence scores in which the word appears. 

The sentence scores were applied as follows:
  •	-2: very negative
  •	-1: somewhat negative
  •	0: neutral
  •	1: somewhat positive
  •	2: very positive

To run the program, download all of the files and save them in the same directory. Additionally, you will need to download the Boost 1.60.0 file [here](https://www.boost.org/users/history/version_1_60_0.html) and save it in the same directory.

Next, open your terminal and find the folder you saved the files in. Enter the command `make all` and then run the program by entering `./a.out reviews.txt`.

Once the program finishes reading in the data, you will be prompted to enter a sentence. After you do so, the program will return the sentiment score of the sentence you entered. 
