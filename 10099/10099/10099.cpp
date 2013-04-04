/*
	Solution to problem 10003
		by: Wei Wei Huang
	Language: C++
	Algorithm based off of Flyod-Warshall's algorithm for graph paths comparison
*/

#include <iostream>
#include <string.h>
using namespace std;

int adjMatrix [101][101];
int numCities, numEdges, startCity, destCity, cost, numPeople;

void initializeMatrix(){	
	//intialize everything to -1 to denote no connecting edge
	memset(adjMatrix, -1, sizeof(adjMatrix[0][0]) * 101 * 101);
	for(int i = 1; i <= numCities; i++){
		adjMatrix[i][i] = 0; //Set itself to 0
	}
}

//Read all of the edges and set up the costs
void readEdgeInputs(){
	for(int i = 0; i < numEdges; i++){
		cin >> startCity >> destCity >> cost;

		adjMatrix[startCity][destCity] = cost - 1; //Subtract 1 for the driver 
		adjMatrix[destCity][startCity] = adjMatrix[startCity][destCity]; //Same edge
	}
}

//Find the maximum people that can travel from city j to city k
void traversePaths(){
	int minPath;
	for (int i = 1; i <= numCities; i++ ) {
        for (int j = 1; j <= numCities; j++ ) {
            if (adjMatrix [j][i] != -1 ) { //Check if the two cities are connected
                for (int k = 1; k <= numCities; k++ ) {
                    if (adjMatrix[i][k] != -1 && j != k ){
						minPath = min (adjMatrix [j][i], adjMatrix[i][k]);
						adjMatrix[j][k] = max(adjMatrix[j][k],minPath);
					}
                }
            }
        }
    }
}

int main(){
	int cases = 0, peopleTransported, numTrips;

	while(cin >> numCities >> numEdges){
		cases++;
		numTrips = 0;
		peopleTransported = 0;
		if(numCities == 0 && numEdges == 0)
			break;

		initializeMatrix();
		readEdgeInputs();		

		cin >> startCity >> destCity >> numPeople;

		traversePaths();
		    
		if(adjMatrix[startCity][destCity] != 0) {
			numTrips = numPeople/adjMatrix[startCity][destCity];
			if(numPeople % adjMatrix[startCity][destCity] != 0){
				numTrips++;
			}		
		}
		else{
			numTrips = 1;
		}

		cout << "Scenario #" << cases << endl;
		cout << "Minimum Number of Trips = " << numTrips << endl << endl;
	}
}