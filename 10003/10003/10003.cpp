#include <iostream>
#include <string>
using namespace std;

int cuts[52];
int dp[52][52];
int length, numCuts;

int cost(int left,int  right){
	return left - right;
}

string Cut(int left, int right){
	int min, cutCost;
	for(int a = 2; a <= numCuts; a++){
		for(int left = 0, right = a; right <= numCuts; left++, right++){
			min = INT_MAX;
			for(int k = left+1; k < right; k++){
				cutCost = cost(cuts[right], cuts[left]) + dp[left][k] + dp[k][right];
				min = (cutCost < min) ? cutCost : min;
			}
			dp[left][right] = min;
		}
	}
	return "The minimum cutting is " + dp[0][numCuts];
}

int main(){
	int cut, min;

	while(cin >> length){
		if(length == 0)
			break;
		else{
			cin >> numCuts;
			for(int i = 1; i < numCuts; i++){
				cin >> cuts[i];
				cuts[i] = length;
			}
			
			cout << Cut(0, length) << "." << endl;
		}
	}
}