/*
 Solution to problem 706
	by: Wei Wei Huang
 Language: C++
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//print all '-'
void printHorizontal(int s, const vector<bool>& hor){
	int size = hor.size();
	for(int i = size-1; i >= 0; i--){
		cout << " ";
		if(hor[i] == true){
			for(int j = 0; j < s; j++)
				cout << "-";
		}
		else{
			for(int j = 0; j < s; j++)
				cout << " ";
		}
		if(i > 0) cout << "  ";
		else cout << " ";
	}
}

//print all '|'
void printVertical(int s, const vector<bool>& vertLeft, const vector<bool>& vertRight){
	int size = vertLeft.size();
	for(int k = 0; k < s; k++){
		for(int i = size-1; i >= 0; i--){
			if(vertLeft[i] == true)	cout << "|";
			else cout << " ";
		
			for(int j = 0; j < s; j++)
				cout << " ";
		
			if(vertRight[i] == true) cout << "|";
			else cout << " ";
			
			if(i > 0) cout << " ";
		}
		if(k < s-1) cout << endl;
	}
}

int main(){
	int s;
	string n;

	vector<bool> top = vector<bool>();
	vector<bool> left_1 = vector<bool>();
	vector<bool> right_1 = vector<bool>();
	vector<bool> middle = vector<bool>();
	vector<bool> left_2 = vector<bool>();
	vector<bool> right_2 = vector<bool>();
	vector<bool> bottom = vector<bool>();

	while (cin >> s >> n){
		//initialize sides
		for(int i = n.size(); i > 0; i--)
		{
			char digit = n.at(i-1);

			switch(digit){
				case '0':
					top.push_back(true);
					left_1.push_back(true);
					right_1.push_back(true);
					middle.push_back(false);
					left_2.push_back(true);
					right_2.push_back(true);
					bottom.push_back(true);
					break;
				case '1':
					top.push_back(false);
					left_1.push_back(false);
					right_1.push_back(true);
					middle.push_back(false);
					left_2.push_back(false);
					right_2.push_back(true);
					bottom.push_back(false);
					break;
				case '2':
					top.push_back(true);
					left_1.push_back(false);
					right_1.push_back(true);
					middle.push_back(true);
					left_2.push_back(true);
					right_2.push_back(false);
					bottom.push_back(true);
					break;
				case '3':
					top.push_back(true);
					left_1.push_back(false);
					right_1.push_back(true);
					middle.push_back(true);
					left_2.push_back(false);
					right_2.push_back(true);
					bottom.push_back(true);
					break;
				case '4':
					top.push_back(false);
					left_1.push_back(true);
					right_1.push_back(true);
					middle.push_back(true);
					left_2.push_back(false);
					right_2.push_back(true);
					bottom.push_back(false);
					break;
				case '5':
					top.push_back(true);
					left_1.push_back(true);
					right_1.push_back(false);
					middle.push_back(true);
					left_2.push_back(false);
					right_2.push_back(true);
					bottom.push_back(true);
					break;
				case '6':
					top.push_back(true);
					left_1.push_back(true);
					right_1.push_back(false);
					middle.push_back(true);
					left_2.push_back(true);
					right_2.push_back(true);
					bottom.push_back(true);
					break;
				case '7':
					top.push_back(true);
					left_1.push_back(false);
					right_1.push_back(true);
					middle.push_back(false);
					left_2.push_back(false);
					right_2.push_back(true);
					bottom.push_back(false);
					break;
				case '8':
					top.push_back(true);
					left_1.push_back(true);
					right_1.push_back(true);
					middle.push_back(true);
					left_2.push_back(true);
					right_2.push_back(true);
					bottom.push_back(true);
					break;
				case '9':
					top.push_back(true);
					left_1.push_back(true);
					right_1.push_back(true);
					middle.push_back(true);
					left_2.push_back(false);
					right_2.push_back(true);
					bottom.push_back(true);
					break;
				default:
					break;
			}			
		}
		if(s == 0 && n == "0"){
			break;
		}
		else{
			printHorizontal(s, top);
			cout << endl;
			printVertical(s, left_1, right_1);
			cout << endl;
			printHorizontal(s, middle);
			cout << endl;
			printVertical(s, left_2, right_2);
			cout << endl;
			printHorizontal(s, bottom);
			cout << endl;
		}
		cout << endl;

		top.clear();
		left_1.clear();
		right_1.clear();
		middle.clear();
		left_2.clear();
		right_2.clear();
		bottom.clear();
	}
}