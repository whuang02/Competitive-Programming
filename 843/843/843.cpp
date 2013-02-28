/*
	Solution to problem 843
		by: Wei Wei Huang
	Language: C++
*/
#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <vector>
using namespace std;

#define Key map<char, char>

map <int, vector<string> > dictionary;
Key decryption;
vector<string> encryptedWords;
istringstream iss;

void buildDictionary(){
	int numWords;
	string word;
	
	cin >> numWords;

	//map the vector of words of same length together
	for(int i = 0; i < numWords; i++){
		cin >> word;
		dictionary[word.size()].push_back(word);
	}
}

void parseLine(string line){
	string word;
	
	encryptedWords.clear();
	istringstream iss(line);
	while(iss >> word){
		encryptedWords.push_back(word);
	}
}

bool isValid(const string& encWord, const string& decWord, Key decrypt){
	for (int i=0; i < encWord.size(); ++i){
		if (decrypt.find(encWord[i]) ==  decrypt.end()){
			for (Key::iterator iter = decrypt.begin(); iter != decrypt.end(); iter++){
				if ((*iter).second == decWord[i]) return false;
			}
			decrypt[encWord[i]] = decWord[i];			
		}
		else{
			if(decrypt[encWord[i]] != decWord[i]) return false;
		}
	}
	return true;
}

bool backtrack(int index, map<char, char> decrypt){
	if(index < encryptedWords.size()){
		string encWord = encryptedWords[index];
		int wordLength = encWord.size();   
		vector<string> possibleMatches = dictionary[wordLength];
   
		for (int i = 0; i < possibleMatches.size(); i++){
			string decWord = possibleMatches[i];

			//check if the decryption key is valid
			if (isValid(encWord, decWord, decrypt) == true){
				Key temp = decrypt;
	   
				//update the decryption key with new word's letters
				for (int j = 0; j < wordLength; j++){
					temp[encWord[j]] = decWord[j];
				}

				//check the rest of the words
				if (backtrack(index+1, temp) == true){
					return true;
				}
			}
		}
		return false;
	}
	else{
		decryption = decrypt;
		return true;
	}
}

void findDecryption(){
	string line;

	while(getline(cin, line)){
		if(line.size() == 0){
			cout << endl;
		}
		else{
			parseLine(line);

			if(backtrack(0, Key()) == true){
				for (int i = 0; i < line.size(); i++){
					if (line[i] != ' ') cout << decryption[line[i]];
					else cout << line[i];
				}
				cout << endl;
			}
			else{      
				for (int i=0; i < line.size(); ++i){
					if (line[i] != ' ') cout << "*";
					else cout << line[i];
				}
				cout << endl;
			}
		}
	}
}

int main(){
	string endline;

	buildDictionary();
	getline(cin, endline);
	findDecryption();
}