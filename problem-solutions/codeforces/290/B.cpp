#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

const int N = 52;
char g[N][N];
int vis[N][N];
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int n, m;

bool dfs(int x, int y, int ax, int ay, char cor){
	if(vis[x][y] == 2) return 0;
	if(vis[x][y] == 1) return 1;
	vis[x][y] = 1;

	//printf("%c: %d %d\n", g[x][y], x, y);

	bool ret = 0;
	For(i,0,4){
		int nx = x+dir[i][0], ny = y+dir[i][1];
		//printf("ax/ay = %d/%d  nx/ny = %d/%d\n", ax, ay, nx, ny);
		if(nx >= 0 and nx < n and ny >= 0 and ny < m and (nx != ax or ny != ay) and g[nx][ny] == cor){
			ret = ret or dfs(nx, ny, x, y, cor);
		}
	}

	vis[x][y] = 2;
	return ret;
}

int main(void){
	scanf("%d%d", &n, &m);

	For(i,0,n){
		scanf("%s", g[i]);
	}

	bool res = 0;
	//memset(vis, -1, sizeof vis);
	For(i,0,n){
		For(j,0,m){
			if(vis[i][j] == 0){
				res = res or dfs(i, j, -1, -1, g[i][j]);
				//printf("\n");
			}
		}
	}

	if(res) printf("Yes\n");
	else printf("No\n");

	return 0;
}
