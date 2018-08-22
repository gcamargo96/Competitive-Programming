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

const int N = 100005;
int x0, Y0, x1, Y1;
int n;
set<ii> g, vis;
int dir[8][2] = {{0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1} };
map<ii, int> dist;

bool bfs(int x, int y){
	queue<ii> q;
	q.push(ii(x,y));
	dist[ii(x,y)] = 0;

	while(!q.empty()){
		x = q.front().fi;
		y = q.front().se;
		q.pop();

		if(x == x1 and y == Y1)
			return 1;

		for(int i = 0; i < 8; i++){
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];

			if(g.count(ii(nx,ny)) and !vis.count(ii(nx,ny))){
				q.push(ii(nx,ny));
				vis.insert(ii(nx,ny));
				dist[ii(nx,ny)] = dist[ii(x,y)] + 1;
			}
		}
	}

	return 0;
}

int main(void){
	scanf("%d%d%d%d", &x0, &Y0, &x1, &Y1);
	scanf("%d", &n);

	int r, a, b;
	for(int i = 0; i < n; i++){
		scanf("%d%d%d", &r, &a, &b);

		for(int j = a; j <= b; j++){
			g.insert(ii(r,j));
		}
	}

	bool ok = bfs(x0, Y0);

	if(ok){
		printf("%d\n", dist[ii(x1,Y1)]);
	}
	else{
		printf("-1\n");
	}

	return 0;
}