#include <iostream>
#include <string>
using namespace std;

class Computer{
public:
	Computer(){
		registers = new int[10];		
		ram = new int[1000];
		end = false;
		numInstructionsExecuted = 0;
	}

	~Computer(){
		delete [] registers;
		delete [] ram;
	}

	bool getEnd(){
		return end;
	}

	void runProgram(){
		int ramLocation = 0;
		bool moved = false;
		while(end == false){
			int instruction = ram[ramLocation];

			int firstDigit = instruction / 100;
			int secondDigit = (instruction % 100) / 10;
			int thirdDigit = (instruction % 100) % 10;

			numInstructionsExecuted++;
			//cout << "firstDigit: " << firstDigit << " second: " << secondDigit << " third: " << thirdDigit<< endl;
			switch(firstDigit){
				case 0:
					if(registers[thirdDigit] != 0){
						ramLocation = registers[secondDigit];
						moved = true;
					}
					break;
				case 1:
					end = true;
					break;
				case 2:
					registers[secondDigit] = thirdDigit;
					break;
				case 3:
					registers[secondDigit] = (registers[secondDigit] + thirdDigit) % 1000;
					break;
				case 4:
					registers[secondDigit] = (registers[secondDigit] * thirdDigit) % 1000;
					break;
				case 5:
					registers[secondDigit] = registers[thirdDigit];
					break;
				case 6:
					registers[secondDigit] = (registers[secondDigit] + registers[thirdDigit]) % 1000;
					break;
				case 7:
					registers[secondDigit] = (registers[secondDigit] * registers[thirdDigit]) % 1000;
					break;
				case 8:
					registers[secondDigit] = ram[registers[thirdDigit]];
					break;
				case 9: 
					ram[registers[thirdDigit]] = registers[secondDigit];
					break;
				default:
					break;
			}
			if(moved == false)
				ramLocation++;
			else
				moved = false;
		}
	}

	void runCase(int cases){
		for(int i = 0; i < cases; i++){
			numInstructionsExecuted = 0;
			memset(registers, 0, sizeof(int) * 10);
			memset(ram, 0, sizeof(int) * 1000);
			string input;

			if(i == 0){
				getline(cin, input);
				getline(cin, input);
			}
			int ramLocation = 0;
			while(getline(cin, input)){
				if(input == ""){
					break;
				}
				int instruction = atoi(input.c_str());
				ram[ramLocation] = instruction;
				ramLocation++;
			}

			runProgram();
			
			cout << numInstructionsExecuted << endl;
			if(i+1 < cases)
				cout << endl;
		}		
	}
private:
	int* registers;
	int* ram;
	int numInstructionsExecuted;
	bool end;
};

int main(){
	int cases;

	Computer comp = Computer();
	while(cin >> cases){
		comp.runCase(cases);
	}
}