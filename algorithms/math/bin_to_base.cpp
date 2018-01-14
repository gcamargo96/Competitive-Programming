#include <bits/stdc++.h>
using namespace std;

long long bin_to_base(int x, int base){
	if(x == 0) return 0;
	return base * bin_to_base(x/2, base) + (x%2);
}

int main(void){
	int x;
	//cout << "Type a number in decimal base" << endl;
	cin >> x;
	int bin = bin_to_base(x, 2);
	//cout << "Number in decimal base:" << endl;
	cout << bin << endl;
	
	return 0;
}
