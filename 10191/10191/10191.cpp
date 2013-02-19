/*
	Solution to problem 10191
		by: Wei Wei Huang
	Language: C++
*/
#include <iostream>
#include <bitset>
#include <string>
#include <stdlib.h>
using namespace std;

bitset<480> dayMins;
int day = 1;

void printLongestNap();

void findLongestNap(int numEvents){
	string start, end, evnt;
	int startHour, startMin, endHour, endMin;
	dayMins.reset();
	for(int i = 0; i < numEvents; i++){		
		cin >> start >> end;
		getline(cin, evnt);
		startHour = atoi(start.substr(0, start.find(":")).c_str());
		endHour = atoi(end.substr(0, start.find(":")).c_str());
		startMin = atoi(start.substr(start.find(":")+1).c_str());
		endMin = atoi(end.substr(start.find(":")+1).c_str());

		int startMinIndex = 0, endMinIndex = 0; 
		if(startHour >= 10){
			startMinIndex = (startHour - 10) * 60 + startMin;
			endMinIndex = (endHour - 10)*60 + endMin;
		}
		for(int j = startMinIndex; j < endMinIndex; j++){
			dayMins[j] = 1;
		}
	}
	printLongestNap();
}

void printLongestNap(){
	int longestSeq = 0, longestSeqIdx = -1, seq = 0, seqIdx = -1;

	for(int i = 0; i < 480; i++){
		if(dayMins[i] == 0){
			if(seqIdx == -1){
				seqIdx = i; //found start of sequence
				seq++;
				if(longestSeqIdx == -1){
					longestSeqIdx = seqIdx;
					longestSeq = seq;
				}
			}
			else{ 
				seq++;
				if(seq > longestSeq){
					longestSeqIdx = seqIdx;
					longestSeq = seq;
				}
			}
		}
		else{ //found end of sequence
			seqIdx = -1;
			seq = 0;
		}
	}

	int hour = longestSeqIdx/60 + 10, minute = longestSeqIdx % 60;
	string extraStr = (minute < 10) ? "0" : "";

	if(longestSeq >= 60){
		cout << "Day #" << day << ": the longest nap starts at " << hour << ":" << extraStr << minute
			<< " and will last for " << longestSeq/60 << " hours and " << longestSeq % 60 << " minutes." << endl;
	}
	else{
		cout << "Day #" << day << ": the longest nap starts at " << hour << ":" << extraStr << minute
			<< " and will last for " << longestSeq << " minutes." << endl;
	}
	day++;
}

int main(){
	int numEvents;

	while(cin >> numEvents){
		findLongestNap(numEvents);		
	}
}