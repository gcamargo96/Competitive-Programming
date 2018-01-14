#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

int g[4][4];

int main(void){
	For(i,0,4){
		For(j,0,4){
			scanf(" %c", &g[i][j]);
		}
	}

	bool ok = 0;
	For(i,0,4){
		For(j,0,2){
			int x = 0, p = 0;
			For(k,j,j+3){
				if(g[i][k] == 'x') x++;
				if(g[i][k] == '.') p++;
			}
			if(x == 2 and p == 1) ok = 1;
		}
	}

	For(j,0,4){
		For(i,0,2){
			int x = 0, p = 0;
			For(k,i,i+3){
				if(g[k][j] == 'x') x++;
				if(g[k][j] == '.') p++;
			}
			if(x == 2 and p == 1) ok = 1;
		}
	}

	For(i,0,2){
		For(j,0,2){
			int x = 0, p = 0;
			For(k,0,3){
				if(g[i+k][j+k] == 'x') x++;
				if(g[i+k][j+k] == '.') p++;
			}
			if(x == 2 and p == 1) ok = 1;
		}
	}

	For(i,0,2){
		For(j,2,4){
			int x = 0, p = 0;
			For(k,0,3){
				if(g[i+k][j-k] == 'x') x++;
				if(g[i+k][j-k] == '.') p++;
			}
			if(x == 2 and p == 1) ok = 1;
		}
	}

	if(ok) printf("YES\n");
	else printf("NO\n");

	return 0;
}

