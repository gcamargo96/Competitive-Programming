#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		if(a > b) cout << ">";
		else if(a < b) cout << "<";
		else cout << "=";
		cout << endl;
	}
	
	return 0;
}
