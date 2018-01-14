#include <bits/stdc++.h>
using namespace std;

const int N = 1000002;
int n, m;

int main(void){
	ios_base::sync_with_stdio(false);

	while(cin >> n >> m){
		int res = 0;
		for(int i = min(n,m); i <= max(n,m); i++){
			int aux = i;
			int cnt = 0;
			while(aux != 1){
				if(aux%2 == 1) aux = aux*3+1;
				else aux /= 2;
				cnt++;
			}
			res = max(res, cnt);
		}
		cout << n << " " << m << " " << res+1 << endl;
	}

	return 0;
}
