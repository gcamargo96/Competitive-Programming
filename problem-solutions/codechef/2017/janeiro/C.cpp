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

const int N = 1005;
int t, n, m;
char g[N][N];

void fill(){
	For(j,0,m){
		g[0][j] = 'A';
		g[n+1][j] = 'B';
	}

	For(i,0,n){
		g[i][0] = 'A';
		g[i][m+1] = 'A';
	}
}

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%d%d", &n, &m);
		fill();

		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				scanf(" %c", &g[i][j]);
			}
		}

		bool ok = 1;
		for(int j = 1; j <= m; j++){
			if(g[n][j] == 'W') ok = 0;
		}
		for(int i = n-1; i >= 1; i--){
			for(int j = 1; j <= m; j++){
				if(g[i][j] == 'B'){
					if(g[i+1][j] == 'A') ok = 0;
				}
				if(g[i][j] == 'W'){
					if(g[i][j-1] == 'A' or g[i][j+1] == 'A') ok = 0;
					if(g[i+1][j] == 'A') ok = 0;
				}
			}
		}

		if(ok) printf("yes\n");
		else printf("no\n");
	}

	return 0;
}

