/*
	Solution to problem 846
	by: Wei Wei Huang
	Language: C++
*/
#include <iostream>
using namespace std;

int main(){
	int cases, x, y, steps, minSteps;
	unsigned stepsTaken, step;
	cin >> cases;

	for(int i = 0; i < cases; i++){
		cin >> x >> y;
		steps = y - x; //Number of steps between the start and end
		minSteps = 0; //minimum number of steps needed
		stepsTaken = 0;
		step = 2;
		
		//Loop until full step distance is reached
		while(steps > stepsTaken){ 
			stepsTaken += (step/2); //Each step has to be taken twice (from the start and the end, they will eventually reach at a midpoint)
			step++; //increase the number of steps 
			minSteps++; //loop until every step has been reached			
		}
		cout << minSteps << endl;
	}
}