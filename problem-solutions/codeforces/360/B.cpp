#include <bits/stdc++.h>
using namespace std;

string n;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;

	cout << n;

	for(int i = n.size()-1; i >= 0; i--){
		cout << n[i];
	}

	cout << endl;

	return 0;
}
