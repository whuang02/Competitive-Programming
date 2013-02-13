/*
	Solution to problem 10252
		By: Wei Wei Huang
	Language: C++
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	string str1, str2;
	string strX;

	while(getline(cin, str1)){
		getline(cin, str2);
		sort(str1.begin(), str1.end());
		sort(str2.begin(), str2.end());

		strX = "";
		for(int i = 0; i < str1.size(); i++)
		{
			int index = str2.find(str1[i]);
			if(index != -1){
				strX += str1[i];
				str2.erase(index, 1);
			}
		}
		cout << strX << endl;
	}
}