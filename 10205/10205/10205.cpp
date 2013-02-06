//10205
#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include <vector>
using namespace std;

void initDeck(vector<int>& deck){
	for(int i = 1; i < 53; i++){
		deck.push_back(i);
	}
}
void applyShuffle(vector<int>& deck, vector<int>& shuffle){
	vector<int> tempDeck = vector<int>(deck);
	for(int i = 0; i < 52; i++){
		deck[shuffle[i]-1] = tempDeck[i];
	}
}

void printDeck(const vector<int>& deck){
	for(int i = 0; i < 52; i++){
		if(deck[i] == 10 || deck[i] == 23 || deck[i] == 36 || deck[i] == 49)
			cout << "Jack";
		else if(deck[i] == 11 || deck[i] == 24 || deck[i] == 37 || deck[i] == 50)
			cout << "Queen";
		else if(deck[i] == 12 || deck[i] == 25 || deck[i] == 38 || deck[i] == 51)
			cout << "King";
		else if(deck[i] == 13 || deck[i] == 26 || deck[i] == 39 || deck[i] == 52)
			cout << "Ace";
		else
			cout << deck[i]+1;


		if(deck[i] <= 13)
		{
			cout << " of Clubs" << endl;
		}
		else if(deck[i] <= 26)
		{
			cout << " of Diamonds" << endl;
		}
		else if(deck[i] <= 39)
		{
			cout << " of Hearts" << endl;
		}
		else if(deck[i] <= 52)
		{
			cout << " of Spades" << endl;
		}
	}
}

int main(){
	int cases, position;
	bool first = true;
	string numShuffles;
	map< int, vector<int> > shuffles;
	vector<int> deck;
	string line;
	while(cin >> cases){
		shuffles = map< int, vector<int> >();
		deck = vector<int>();
		initDeck(deck);
		for(int i = 0; i < cases; i++){
			if(i == 0)
			{
				getline(cin, line);
				getline(cin, line);
			}

			while(cin >> numShuffles){
				if(numShuffles == ""){
					break;
				}
				else{
					if(!first)
						cout << endl;
					else
						first = false;
					deck = vector<int>();
					initDeck(deck);
					int numShuff = atoi(numShuffles.c_str());
					vector<int> positions = vector<int>();
					for(int i = 1; i <= numShuff; i++){
						shuffles.insert(make_pair(i, positions));
						for(int j = 0; j < 52; j++){
							cin >> position;
							shuffles.at(i).push_back(position);
						}
					}
					for(int k = 1; k <= numShuff; k++){
						int key;
						cin >> key;
						applyShuffle(deck, shuffles.at(key));
					}
					printDeck(deck);
				}
			}
		}
	}
}