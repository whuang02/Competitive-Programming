/*
	Solution to problem 10003
	by: Wei Wei Huang
	Language: C++
*/
#include <iostream>
using namespace std;

int cuts[53];
int dp[53][53];

int Cut(int left, int right){
	int min = 9999999999, cutCost = 0;

	if(left + 1 == right) //break case no more cuts
		return 0;
	else if(dp[left][right] != 0)
		return dp[left][right];

	//Do every cut between the left and right side of the stick and get the total cost
	for(int i = left + 1; i < right; i++){
		cutCost = Cut(left, i) + Cut(i, right) + cuts[right] - cuts[left];
		min = (cutCost < min) ? cutCost : min;
	}
	dp[left][right] = min;

	return dp[left][right];
}

int main(){
	int cut, numCuts, length;

	while(cin >> length){
		if(length == 0)
			break;
		cin >> numCuts;

		cuts[0] = 0;
		cuts[numCuts+1] = length;
		for(int i = 1; i <= numCuts; i++){
			cin >> cuts[i];
		}
		
		for ( int i = 0; i < 53; i++ ) {
	        for ( int j = 0; j < 53; j++ )
	            dp[i][j] = 0;
	    }
			
		cout << "The minimum cutting is " << Cut(0, numCuts+1) << "." << endl;
	}
}