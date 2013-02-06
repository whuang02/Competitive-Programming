#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

bool isJolly(const vector<int> listNum, int upper_bound){
	int diff;
	bool isJolly = true;

	for(int i = 1; i < listNum.size(); i++){
		diff = abs(listNum[i] - listNum[i-1]);
		if(diff > upper_bound || diff < 1){
			isJolly = false;
			break;
		}		
	}
	return isJolly;
}

int main(){
	vector<int> listNum;
	int numNumbers, num;
	while(cin >> numNumbers){
		listNum = vector<int>();

		if(numNumbers == 1){
			cout << "Jolly" << endl;			
		}
		else{
			for(int i = 0; i < numNumbers; i++){
				cin >> num;		
				listNum.push_back(num);
			}
			if(isJolly(listNum, numNumbers))
				cout << "Jolly" << endl;
			else
				cout << "Not jolly" << endl;
		}
	}
}