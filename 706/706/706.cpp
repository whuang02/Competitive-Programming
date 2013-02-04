#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

ofstream myfile;

//print all '-'
void printHorizontal(int s, const vector<bool>& hor){
	int size = hor.size();
	for(int i = size-1; i >= 0; i--){
		myfile << " ";
		if(hor[i] == true){
			for(int j = 0; j < s; j++)
				myfile << "-";
		}
		else{
			for(int j = 0; j < s; j++)
				myfile << " ";
		}
		if(i > 0) myfile << "  ";
		else myfile << " ";
	}
}

//print all '|'
void printVertical(int s, const vector<bool>& vertLeft, const vector<bool>& vertRight){
	int size = vertLeft.size();
	for(int k = 0; k < s; k++){
		for(int i = size-1; i >= 0; i--){
			if(vertLeft[i] == true)	myfile << "|";
			else myfile << " ";
		
			for(int j = 0; j < s; j++)
				myfile << " ";
		
			if(vertRight[i] == true) myfile << "|";
			else myfile << " ";
			
			if(i > 0) myfile << " ";
		}
		if(k < s-1) myfile << endl;
	}
}

int main(){
	short s;
	unsigned n;
	bool first = true;

	vector<bool> top = vector<bool>();
	vector<bool> left_1 = vector<bool>();
	vector<bool> right_1 = vector<bool>();
	vector<bool> middle = vector<bool>();
	vector<bool> left_2 = vector<bool>();
	vector<bool> right_2 = vector<bool>();
	vector<bool> bottom = vector<bool>();
	myfile.open("C:/Users/Wei Wei/Desktop/output.txt");
	while (cin >> s >> n){
		if(s == 0 && n == 0){
			break;
		}
		//initialize sides
		while(n != 0)
		{
			int digit = n % 10;
			n /= 10;

			switch(digit){
				case 0:
					top.push_back(true);
					left_1.push_back(true);
					right_1.push_back(true);
					middle.push_back(false);
					left_2.push_back(true);
					right_2.push_back(true);
					bottom.push_back(true);
					break;
				case 1:
					top.push_back(false);
					left_1.push_back(false);
					right_1.push_back(true);
					middle.push_back(false);
					left_2.push_back(false);
					right_2.push_back(true);
					bottom.push_back(false);
					break;
				case 2:
					top.push_back(true);
					left_1.push_back(false);
					right_1.push_back(true);
					middle.push_back(true);
					left_2.push_back(true);
					right_2.push_back(false);
					bottom.push_back(true);
					break;
				case 3:
					top.push_back(true);
					left_1.push_back(false);
					right_1.push_back(true);
					middle.push_back(true);
					left_2.push_back(false);
					right_2.push_back(true);
					bottom.push_back(true);
					break;
				case 4:
					top.push_back(false);
					left_1.push_back(true);
					right_1.push_back(true);
					middle.push_back(true);
					left_2.push_back(false);
					right_2.push_back(true);
					bottom.push_back(false);
					break;
				case 5:
					top.push_back(true);
					left_1.push_back(true);
					right_1.push_back(false);
					middle.push_back(true);
					left_2.push_back(false);
					right_2.push_back(true);
					bottom.push_back(true);
					break;
				case 6:
					top.push_back(true);
					left_1.push_back(true);
					right_1.push_back(false);
					middle.push_back(true);
					left_2.push_back(true);
					right_2.push_back(true);
					bottom.push_back(true);
					break;
				case 7:
					top.push_back(true);
					left_1.push_back(false);
					right_1.push_back(true);
					middle.push_back(false);
					left_2.push_back(false);
					right_2.push_back(true);
					bottom.push_back(false);
					break;
				case 8:
					top.push_back(true);
					left_1.push_back(true);
					right_1.push_back(true);
					middle.push_back(true);
					left_2.push_back(true);
					right_2.push_back(true);
					bottom.push_back(true);
					break;
				case 9:
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
		if(first == false) myfile << endl;
		else first = false;

		printHorizontal(s, top);
		myfile << endl;
		printVertical(s, left_1, right_1);
		myfile << endl;
		printHorizontal(s, middle);
		myfile << endl;
		printVertical(s, left_2, right_2);
		myfile << endl;
		printHorizontal(s, bottom);
		myfile << endl;

		top.clear();
		left_1.clear();
		right_1.clear();
		middle.clear();
		left_2.clear();
		right_2.clear();
		bottom.clear();
	}
	myfile.close();
}