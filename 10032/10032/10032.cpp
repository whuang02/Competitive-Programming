#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

#define maxPeople 100
#define maxWeight 450

int peopleWeights[maxPeople+1];
bool backtrack[maxPeople][maxPeople*maxWeight+1];
int total, numPeople, bestDifference, halfTotal, bestSum;

void readWeights(){
	cin >> numPeople;
	total = 0;
	for(int i = 0; i < numPeople; i++){
		cin >> peopleWeights[i];
		total += peopleWeights[i];
	}
	halfTotal = total * 0.5;
	bestDifference = 22500;
	bestSum = 0;
}

void backtrackTeams(){
	for(int i = 0; i < numPeople; i++){
		for(int j = numPeople; j > 0; j--){
			for(int k = total; k > 0; k--){
				if(backtrack[j][k] == false){
					if(k - peopleWeights[i] < 0)
						break;
					else
						backtrack[j][k] = backtrack[j-1][k-peopleWeights[i]];
				}
			}
		}
	}
}

int main(){
	int cases, difference, otherTeam;

	cin >> cases;

	for(int i = 0; i < cases; i++){
		readWeights();
		//Reset all the bools to false
		memset(backtrack, 0, sizeof(bool));
		//initialize the first person
		backtrack[0][0] = 1;
		backtrackTeams();

		for(int j = 1; j < total+1; j++){
			if(backtrack[numPeople/2][j] == true){
				difference = abs(halfTotal - j);
				//When you find a more balanced team change the bestSum to represent it
				if(difference < bestDifference){
					bestDifference = difference;
					bestSum = j;
				}
			}
		}

		otherTeam = total-bestSum;
		if(bestSum > halfTotal)
			cout << otherTeam << " " << bestSum << endl;
		else
			cout << bestSum << " " << otherTeam << endl;
	}

	return 0;
}