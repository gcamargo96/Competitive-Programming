#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

const int N = 1002;
char g[N][N];
int n, m;
int lin[N], col[N];

int main(void){
	scanf("%d%d", &n, &m);

	For(i, 0, n){
		scanf("%s", g[i]);
	}

	int cnt = 0;
	For(i, 0, n){
		For(j, 0, m){
			if(g[i][j] == '*') cnt++;
		}
	}

	For(i,0,n){
		For(j,0,m){
			if(g[i][j] == '*') lin[i]++;
		}
	}

	For(j,0,m){
		For(i,0,n){
			if(g[i][j] == '*') col[j]++;
		}
	}

	bool res = 0;
	int l,c;
	For(i,0,n){
		For(j,0,m){
			if(g[i][j] == '.' and lin[i]+col[j] == cnt){
				res = 1;
				l = i, c = j;
				break;
			}
			if(g[i][j] == '*' and lin[i]+col[j] == cnt+1){
				res = 1;
				l = i, c = j;
				break;
			}
		}
		if(res) break;
	}

	if(res) printf("YES\n%d %d\n", l+1, c+1);
	else printf("NO\n");

	return 0;
}
