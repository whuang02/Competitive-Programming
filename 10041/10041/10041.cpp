/*
	Solution to problem 10041
		by: Wei Wei Huang
	Language: C++
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(){
	int cases, numRelatives, houseNum;
	vector<int> allRelatives = vector<int>();
	cin >> cases;

	for(int i = 0; i < cases; i ++){
		cin >> numRelatives;

		allRelatives.clear();
		for(int j = 0; j < numRelatives; j++){
			cin >> houseNum;
			allRelatives.push_back(houseNum);
		}

		sort(allRelatives.begin(), allRelatives.end());
		int sum = 0, median = allRelatives[allRelatives.size()/2];
		for(int k = 0; k < allRelatives.size(); k++){
			sum += abs(median - allRelatives[k]);
		}
		cout << sum << endl;
	}
}