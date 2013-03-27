/*
	Solution to problem 10004
	by: Wei Wei Huang
	Language: C++
*/
#include <iostream>
#include <vector>
using namespace std;

class node{
public:
	int color;
	vector<node*> neighbors;
};

vector<node> vertices;
int numVertices, numEdges, first, second, numColored = 0;

bool isGraphValid(int index){
	node curr = vertices[index];
	if(curr.color == -1)
		return true;

	for(int i = 0; i < curr.neighbors.size(); i++){
		if(curr.color == curr.neighbors[i]->color)
			return false;
	}
	return true;
}

void colorNeighbors(int index){
	node curr = vertices[index];
	int color = (curr.color == 0) ? 1 : 0;
	for(int i = 0; i < curr.neighbors.size(); i++){
		if(curr.neighbors[i]->color == -1){
			curr.neighbors[i]->color = color;
			numColored++;
		}
	}
}

bool isBicolorable(){
	bool bicolorable;
	for(int i = 0; i < numVertices; i++){
		colorNeighbors(i);
		bicolorable = isGraphValid(i);
		if(bicolorable == false)
			return bicolorable;
	}
	return bicolorable;
}

int main(){
	bool answer;
	while (cin >> numVertices)
	{
		if(numVertices == 0)
			break;
		else{
			vertices.clear();
			vertices = vector<node>(numVertices);
			numColored = 0;
			for(int i = 0; i < numVertices; i++)
			{
				vertices[i].color = -1;
			}
			
			cin >> numEdges;
			for(int j = 0; j < numEdges; j++){
				cin >> first >> second;
				vertices[first].neighbors.push_back(&vertices[second]);
				vertices[second].neighbors.push_back(&vertices[first]);
			}
			vertices[0].color = 0;
			numColored++;
			answer = isBicolorable();
			if(answer == true)
				cout << "BICOLORABLE." << endl;
			else 
				cout << "NOT BICOLORABLE." << endl;
		}
	}
}