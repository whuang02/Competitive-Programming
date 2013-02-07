/*
	Solution to problem 10205
		by: Wei Wei Huang
	Language: C++
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define numCards 52
string cardValue[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
string cardSuits[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};
int shuffles[100][numCards];

void initDeck(vector<int>& deck){
	for(int i = 0; i < numCards; i++){
		deck[i] = i;
	}
}

void readShuffles(int numShuffles){	
	for(int i = 0; i < numShuffles; i++){
		for(int j = 0; j < numCards; j++){
			cin >> shuffles[i][j];
		}
	}
}

void applyShuffle(vector<int>& deck, int shuffleKey){
	vector<int> tempDeck = vector<int>(deck);
	for(int i = 0; i < numCards; i++){
		deck[i] = tempDeck[shuffles[shuffleKey][i] - 1];
	}
}

void printDeck(const vector<int>& deck){
	for(int i = 0; i < numCards; i++){
		cout << cardValue[deck[i] % 13] << " of " << cardSuits[deck[i] / 13] << endl;
	}
}

int main(){
	int cases, numShuffles, shuffleKey;
	vector<int> deck = vector<int>(numCards);

	cin >> cases;

	for(int i = 0; i < cases; i++){
		initDeck(deck);

		cin >> numShuffles;

		readShuffles(numShuffles);

		for(int k = 0; k < numShuffles; k++){
			cin >> shuffleKey;
			applyShuffle(deck, shuffleKey-1);
		}

		printDeck(deck);

		if(i < cases - 1)
			cout << endl;
	}
	
}