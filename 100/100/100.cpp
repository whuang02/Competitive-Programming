#include <iostream>
using namespace std;

unsigned getCycle(unsigned num){
	unsigned cycle = 1;		
	while(num != 1){
		num = (num % 2 == 0) ? (num / 2) : (3*num + 1);
		cycle++;
	}
	return cycle;
}

int main(){
	unsigned i, j, max;
	while(cin >> i >> j ){	
		max = 0;
		cout << i << " " << j << " ";
		if(i > j)
		{
			swap(i, j);
		}
		for(unsigned num = i; num <= j; num++){
			unsigned x = getCycle(num);
			if(x > max)
				max = x;
		}
		cout << max << endl;
	}
}