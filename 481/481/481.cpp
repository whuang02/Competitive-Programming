/*
	Solution to problem 481
	by: Wei Wei Huang
	Language: C++
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> numbers, longestSequence, comparable;

//The Longest Increasing Sequence Algorithm
void findLongestIncreasingSequence(){
	if(!numbers.empty()){
		comparable = vector<int>(numbers.size());
		int start, end;

		longestSequence.push_back(0);

		for(int i = 1; i < numbers.size(); i++){
			
			//If the current number is greater than the last number in the sequence thus far, just add it
			if(numbers[i] > numbers[longestSequence.back()]){
				comparable[i] = longestSequence.back();
				longestSequence.push_back(i);
				continue;
			}

			//Binary search to find the smallest number that is larger than the current number
			//The after the search, start will have the index of found number
			for(start = 0, end = longestSequence.size()-1; start < end;){
				int middle = (start + end) / 2;
				if(numbers[i] > numbers[longestSequence[middle]])
					start = middle + 1;
				else
					end = middle;
			}

			//Update the longestSequence if the new value is smaller than the previous value
			if(numbers[i] < numbers[longestSequence[start]]){
				if(start > 0)
					comparable[i] = longestSequence[start-1];
				longestSequence[start] = i;
			}
		}

		for (int i = longestSequence.size(), j = longestSequence.back(); i--; j = comparable[j]) 
			longestSequence[i] = j;

	}
}

int main(){
	int num;

	//input
	while(cin >> num){
		numbers.push_back(num);
	}

	//run algorithm
	findLongestIncreasingSequence();

	//output
	if(longestSequence.empty() == false){
		cout << longestSequence.size() << endl << '-' << endl;
		for(size_t i = 0; i < longestSequence.size(); i++){
			cout << numbers[longestSequence[i]] << endl;
		}
	}
}