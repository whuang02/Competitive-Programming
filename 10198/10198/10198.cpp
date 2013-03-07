#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

class BigInt{
public:
	vector<int> integer;
	BigInt(){
		integer.reserve(110);
	}
	BigInt(const string& n){
		integer.resize(n.size());
		for(int i = 0, j = n.size()-1; i < n.size(); i++, j--){
			integer[i] = n[j]-'0';
		}
	}
	BigInt& operator+=(BigInt& rhs){
		vector<int> sum;
		int carryOver = 0, stepSum, a, b;
		sum.resize(max(rhs.integer.size(), integer.size()), 0);
		for(int i = 0 ; i < sum.size(); i++){
			a = (i >= rhs.integer.size()) ? 0 : rhs.integer[i];
			b = (i >= integer.size()) ? 0 : integer[i];
			stepSum = (a + b);
			sum[i] = (stepSum + carryOver) % 10;
			carryOver = (stepSum + carryOver)/10;
			if(i == sum.size() -1 && carryOver != 0)
			{	
				sum.push_back(carryOver);
				break;
			}
		}
		integer = sum;
		return *this;
	}
};

ostream& operator<<(ostream& os, const BigInt& rhs){
	for(int i = rhs.integer.size()-1; i >= 0; i--){
		os << rhs.integer[i];
	}
	return os;
}

BigInt gustavo[1001];

int main(){
	gustavo[0] = BigInt("1");
	gustavo[1] = BigInt("2");
	gustavo[2] = BigInt("5");
	for(int n = 3; n < 1001; n++){
		gustavo[n] += gustavo[n-1]; 
		gustavo[n] += gustavo[n-1];
		gustavo[n] += gustavo[n-2];
		gustavo[n] += gustavo[n-3];
	}
	int n;
	while(cin >> n){
		cout << gustavo[n] << endl;
	}
}