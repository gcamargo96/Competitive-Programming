#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 105;
int g[N][N];
bool vis[N][N];
int n, m;

int dir[8][2] = {{0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1} };

void dfs(int x, int y){
	vis[x][y] = 1;

	for(int i = 0; i < 8; i++){
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];

		if(nx >= 1 and nx <= n and ny >= 1 and ny <= m and g[nx][ny] == '#' and !vis[nx][ny]){
			dfs(nx, ny);
		}
	}
}

int main(void){
	scanf("%d%d", &n, &m);

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf(" %c", &g[i][j]);
		}
	}

	int ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(g[i][j] == '#' and !vis[i][j]){
				dfs(i,j);
				ans++;
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}