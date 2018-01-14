#include <bits/stdc++.h>
using namespace std;

int n, d, mx, cnt;
string s;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n >> d;

	cnt = 0, mx = 0;
	for(int i = 0; i < d; i++){
		cin >> s;
		int flag = 0;
		for(int j = 0; j < n; j++){
			if(s[j] == '0'){
				flag = 1;
			}
		}
		
		if(flag) cnt++;
		else cnt = 0;
		
		if(cnt > mx){
			mx = cnt;
		}
	}
	cout << mx << endl;

	return 0;
}
