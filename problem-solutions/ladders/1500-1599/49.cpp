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

const int N = 505;
int n, m, k, points, cnt;
char g[N][N];
bool vis[N][N], ans[N][N];

void bfs(int x, int y){
	vis[x][y] = 1;
	queue<ii> q;
	q.push(mp(x,y));

	cnt = 0;
		while(!q.empty()){
		x = q.front().fi;
		y = q.front().se;
		ans[x][y] = 1;
		//printf("%d %d\n", x, y);
		q.pop();

		if(++cnt == points-k){
			return;
		}

		if(g[x+1][y] == '.' and !vis[x+1][y]){
			vis[x+1][y] = 1;
			q.push(mp(x+1,y));
		}
		if(g[x-1][y] == '.' and !vis[x-1][y]){
			vis[x-1][y] = 1;
			q.push(mp(x-1,y));
		}
		if(g[x][y+1] == '.' and !vis[x][y+1]){
			vis[x][y+1] = 1;
			q.push(mp(x,y+1));
		}
		if(g[x][y-1] == '.' and !vis[x][y-1]){
			vis[x][y-1] = 1;
			q.push(mp(x,y-1));
		}
	}
}

int main(void){
	scanf("%d%d%d", &n, &m, &k);

	int x, y;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf(" %c", &g[i][j]);
			if(g[i][j] == '.'){
				points++;
				x = i;
				y = j;
			}
		}
	}


	for(int i = 0; i <= n+1; i++){
		g[i][0] = '#';
		g[i][m+1] = '#';
	}
	for(int j = 0; j <= m+1; j++){
		g[0][j] = '#';
		g[n+1][j] = '#';
	}

	bfs(x, y);
	//printf("%d\n", cnt);

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(g[i][j] == '.' and !ans[i][j]) printf("X");
			else printf("%c", g[i][j]);
		}
		printf("\n");
	}

	/*for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			printf("%d", vis[i][j]);
		}
		printf("\n");
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			printf("%c", g[i][j]);
		}
		printf("\n");
	}*/

	return 0;
}

