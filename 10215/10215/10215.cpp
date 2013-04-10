/*
	Solution to problem 10215
		By: Wei Wei Huang
	Language: C++
*/
#include<iostream>
#include<math.h>
using namespace std;

#define eps 1e-8

int main(){
	double L, W, x1, x2, vol1, vol2, left, right, min;

	while(cin >> L >> W){
		left = L + W;
		right = sqrt(L*L - L*W + W*W);		
        x1 = (left - right)/6.0;
		x2 = (left + right)/6.0;
        vol1=(L-2*x1)*(W-2*x1)*(x1);
        vol2=(L-2*x2)*(W-2*x2)*(x2);

		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(3);
		min = (L - W) > eps ? W : L;

		if(vol1 > vol2)
			cout << x1+eps << " 0.000 " << (min*0.5)+eps << endl;
		else
			cout << x2+eps << " 0.000 " << (min*0.5)+eps << endl;
	}
}