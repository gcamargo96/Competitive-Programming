#include <bits/stdc++.h>
using namespace std;

int t, n;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> t;

	while(t--){
		cin >> n;

		int x, ant = 0, cnt = 1, maxcnt = 0;
		for(int i = 0; i < n; i++){
			cin >> x;
			if(x == ant){
				cnt++;
			}
			else{
				cnt = 1;
			}
			maxcnt = max(maxcnt, cnt);
			ant = x;
		}

		if(maxcnt >= 3) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}
