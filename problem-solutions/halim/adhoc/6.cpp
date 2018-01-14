#include <bits/stdc++.h>
using namespace std;

int main(void){
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	cin.get();

	for(int i = 1; i <= t; i++){
		int x, res = 0;
		string s;
		getline(cin, s);
		stringstream ss;
	   	ss << s;
		while(ss >> x){
			if(x > res) res = x;
		}

		cout << "Case " << i << ": " << res << endl;
	}
}
