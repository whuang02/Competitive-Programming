/*
	Solution to problem 10050
		by: Wei Wei Huang
	Language: C++
*/
#include <iostream>
#include <bitset>
using namespace std;

bitset<3650> days; //0->3569

int main(){
	int numCases, numDays, numParties, hartel;

	cin >> numCases;

	for(int i = 0; i < numCases; i++){
		days.reset();
		cin >> numDays;
		cin >> numParties;
		for(int j = 0; j < numParties; j++){
			cin >> hartel;
			for(int k = hartel; k <= numDays; k+=hartel){
				days[k-1] = (k % 7 != 0 && k % 7 != 6) ? 1 : 0;
			}
		}
		cout << days.count() << endl;
	}
}