#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define endl "\n"

const int N = 12;
char g[N][N];

int main(void){
	ios_base::sync_with_stdio(false);

	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			cin >> g[i][j];
		}
	}

	bool ans = 0;
	for(int i = 0; i < 10; i++){
		for(int j = 0; j <= 10-5; j++){
			int cntX = 0, cntO = 0;
			for(int k = 0; k < 5; k++){
				if(g[i][j+k] == 'X') cntX++;
				if(g[i][j+k] == 'O') cntO++;
			}
			if(cntX == 4 and cntO == 0){
				ans = 1;
			}
		}
	}

	for(int i = 0; i <= 10-5; i++){
		for(int j = 0; j < 10; j++){
			int cntX = 0, cntO = 0;
			for(int k = 0; k < 5; k++){
				if(g[i+k][j] == 'X') cntX++;
				if(g[i+k][j] == 'O') cntO++;
			}
			if(cntX == 4 and cntO == 0){
				ans = 1;
			}
		}
	}

	for(int i = 0; i <= 10-5; i++){
		for(int j = 0; j <= 10-5; j++){
			int cntX = 0, cntO = 0;
			for(int k = 0; k < 5; k++){
				if(g[i+k][j+k] == 'X') cntX++;
				if(g[i+k][j+k] == 'O') cntO++;
			}
			if(cntX == 4 and cntO == 0){
				ans = 1;
			}
		}
	}

	for(int i = 0; i <= 10-5; i++){
		for(int j = 9; j >= 4; j--){
			int cntX = 0, cntO = 0;
			for(int k = 0; k < 5; k++){
				if(g[i+k][j-k] == 'X') cntX++;
				if(g[i+k][j-k] == 'O') cntO++;
			}
			if(cntX == 4 and cntO == 0){
				ans = 1;
			}
		}
	}

	if(ans) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}