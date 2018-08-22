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

#define INF 0x3f3f3f3f

int n, m, d;
vector<vector<char> > g;
vector<vector<int> > dist;
queue<ii> q;
ii S, F;
int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0} };


void monsters_bfs(){
	while(!q.empty()){
		int x = q.front().fi;
		int y = q.front().se;
		q.pop();

		for(int i = 0; i < 4; i++){
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];

			if(nx >= 1 and nx <= n and ny >= 1 and ny <= m and dist[x][y]+1 <= d and dist[x][y]+1 < dist[nx][ny]){
				q.push(ii(nx,ny));
				dist[nx][ny] = dist[x][y]+1;
				g[nx][ny] = 'M';
			}
		}
	}
}

void bfs(){
	for(int i = 0; i < n+5; i++){
		for(int j = 0; j < m+5; j++){
			dist[i][j] = INF;
		}
	}

	queue<ii> q;
	q.push(S);
	dist[S.fi][S.se] = 0;

	while(!q.empty()){
		int x = q.front().fi;
		int y = q.front().se;
		q.pop();

		if(g[x][y] == 'M') continue;

		for(int i = 0; i < 4; i++){
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];

			if(nx >= 1 and nx <= n and ny >= 1 and ny <= m and g[nx][ny] != 'M' and dist[x][y]+1 < dist[nx][ny]){
				q.push(ii(nx,ny));
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
}

int main(void){
	scanf("%d%d%d", &n, &m, &d);

	g.resize(n+5);
	dist.resize(n+5);
	for(int i = 0; i < n+5; i++){
		g[i].resize(m+5);
		dist[i].resize(m+5, INF);
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf(" %c", &g[i][j]);
			if(g[i][j] == 'M'){
				q.push(ii(i,j));
				dist[i][j] = 0;
			}
			if(g[i][j] == 'S'){
				S = ii(i,j);
			}
			if(g[i][j] == 'F'){
				F = ii(i,j);
			}
		}
	}

	monsters_bfs();

	// printf("\n");
	// for(int i = 1; i <= n; i++){
	// 	for(int j = 1; j <= m; j++){
	// 		printf("%c", g[i][j]);
	// 	}
	// 	printf("\n");
	// }

	bfs();	

	if(dist[F.fi][F.se] != INF and g[F.fi][F.se] != 'M'){
		printf("%d\n", dist[F.fi][F.se]);
	}
	else{
		printf("-1\n");
	}

	return 0;
}