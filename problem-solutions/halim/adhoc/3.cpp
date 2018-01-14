#include <bits/stdc++.h>
using namespace std;

int main(void){
	int t;

	cin >> t;

	for(int k = 0; k < t; k++){
		int v[3];
		for(int i = 0; i < 3; i++) cin >> v[i];

		sort(v, v+3);
		cout << "Case " << k+1 << ": " << v[1] << endl;
	}

	return 0;
}