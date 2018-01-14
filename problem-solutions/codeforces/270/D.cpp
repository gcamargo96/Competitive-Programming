#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define enld "\n"
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

const int N = 2002;
int n;
int mat[N][N];
bool vis[N];

void dfs(int x){
	vis[x] = 1;

	For(i,1,n+1){
		if(mat[x][i] != 0 and !vis[i]){
			dfs(i);
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);

	cin >> n;

	For(i,1,n+1){
		For(j,1,n+1){
			cin >> mat[i][j];
		}
	}

	bool res = 1;
	For(i,1,n+1){
		if(mat[i][i] != 0){
			res = 0;
			break;
		}
	}

	bool tudo1 = 1;
	For(i,2,n+1){
		For(j,1,i){
			if(mat[i][j] != mat[j][i] or mat[i][j] < 0){
				res = 0;
				break;
			}
			if(mat[i][j] != 1) {
				tudo1 = 0;
			}
		}
		if(!res) break;
	}

	if(tudo1) res = 0;

	dfs(1);

	For(i,1,n+1){
		if(!vis[i]) res = 0;
	}

	if(res) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}
