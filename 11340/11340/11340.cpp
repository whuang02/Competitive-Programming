#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char, int> paidCharacters;
map<char, int>::iterator charIter;

void readCharacters(){
	paidCharacters = map<char, int>();
	int numCharacters, cost;
	char character;

	cin >> numCharacters;
	
	for(int i = 0; i < numCharacters; i++){
		cin >> character >> cost;
		paidCharacters[character] = cost;
	}
}

int sumArticleCost(){
	int numLines, cost = 0;
	string line;
	char character;

	cin >> numLines;
	getline(cin, line); //get rid of "" line

	for(int i = 0; i < numLines; i++){		
		getline(cin, line);
		for(int j = 0; j < line.size(); j++)
		{
			character = line.at(j);
			if(paidCharacters[character])
				cost += paidCharacters[character];
		}
	}
	return cost;
}

void printCost(int cost){
	int dollars = cost / 100;
	int cents = cost % 100;
	
	if(cents < 10)
		cout << dollars << "." << "0" << cents << "$" << endl;
	else
		cout << dollars << "." << cents << "$" << endl;;
}

int main(){
	int cases, totalCost;

	cin >> cases;

	for(int i = 0; i < cases; i++){
		readCharacters();

		totalCost = sumArticleCost();

		printCost(totalCost);
	}
}