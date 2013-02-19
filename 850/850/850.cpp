/*
	Solution to problem 850
		by: Wei Wei Huang
	Language: C++
*/
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;

const string decryptionStr = "the quick brown fox jumps over the lazy dog";
vector<string> lines = vector<string>(100);
char mapping[26];
bitset<26> foundChars;
bool foundDecrypt = false;

void findDecrypt(string& line){
	if(line[3] == ' ' && line[9] == ' ' && line[15] == ' ' && line[19] == ' ' 
		&& line[25] == ' ' && line[30] == ' ' && line[34] == ' ' && line[39] == ' '){
		for(int i = 0; i < decryptionStr.size(); i++){
			//create mapping of characters
			if(line[i]-97 > -1 && line[i]-97 < 26){
				mapping[line[i]-97] = decryptionStr[i];
				foundChars[(int)line[i]-97] = 1;
			}
		}
		if(foundChars.count() == 26)
			foundDecrypt = true;
	}
}

void readLines(){	
	string line;
	bool started = false;

	//read the lines and try to find the decryption line
	while(getline(cin, line)){
		if(line.size() > 0){
			started = true;
			lines.push_back(line);
			if(foundDecrypt == false && line.size() == decryptionStr.size())
				findDecrypt(line);
		}
		else{
			if(started == true)
				break;
		}
	}
}

void printLines(){
	for(int i = 0; i < lines.size(); i++){
		string line = lines[i];
		//print the characters
		for(int j = 0; j < line.size(); j++){
			if(line[j]-97 > -1 && line[j]-97 < 26){
				cout << mapping[(int)line[j]-97];
			}
			else{
				cout << line[j];
			}
		}
		cout << endl;
	}
}

int main(){
	int cases;

	cin >> cases;

	for(int i = 0; i < cases; i++){
		lines.clear();
		foundChars.reset();
		foundDecrypt = false;

		readLines();		
		if(foundDecrypt == true)
			printLines();
		else
			cout << "No solution." << endl;
		
		if(i < cases-1)
			cout << endl;
	}
}