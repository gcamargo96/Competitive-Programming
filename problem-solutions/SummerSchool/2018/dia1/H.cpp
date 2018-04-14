#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 102;
int n, m, p, q, X1, Y1, X2, Y2;
bool vis[N][N];
int dist[N][N];
map<ii, ii> pai;

void bfs(){
	queue<ii> Q;
	Q.push(ii(X1, Y1));
	vis[X1][Y1] = 1;
	dist[X1][Y1] = -1;
	pai[ii(X1,Y1)] = ii(X1, Y1);


	while(!Q.empty()){
		int x = Q.front().fi;
		int y = Q.front().se;
		Q.pop();
		
		// printf("%d %d\n", x, y);

		int px = pai[ii(x,y)].fi;
		int py = pai[ii(x,y)].se;

		dist[x][y] = dist[px][py] + 1;

		if(x == X2 and y == Y2)
			break;

		if(x+p >= 1 and x+p <= n and y+q >= 1 and y+q <= m and !vis[x+p][y+q]){
			Q.push(ii(x+p, y+q));
			pai[ii(x+p, y+q)] = ii(x,y);
			vis[x+p][y+q] = 1;
		}
		if(x-p >= 1 and x-p <= n and y+q >= 1 and y+q <= m and !vis[x-p][y+q]){
			Q.push(ii(x-p, y+q));
			pai[ii(x-p, y+q)] = ii(x,y);
			vis[x-p][y+q] = 1;		
		}
		if(x+p >= 1 and x+p <= n and y-q >= 1 and y-q <= m and !vis[x+p][y-q]){
			Q.push(ii(x+p, y-q));
			pai[ii(x+p, y-q)] = ii(x,y);
			vis[x+p][y-q] = 1;
		}
		if(x-p >= 1 and x-p <= n and y-q >= 1 and y-q <= m and !vis[x-p][y-q]){		
			Q.push(ii(x-p, y-q));
			pai[ii(x-p, y-q)] = ii(x,y);
			vis[x-p][y-q] = 1;
		}
	}
}

int main(void){
	scanf("%d%d%d%d%d%d%d%d", &n, &m, &p, &q, &X1, &Y1, &X2, &Y2);

	memset(dist, INF, sizeof dist);
	bfs();

	// for(int i = 1; i <= n; i++){
	// 	for(int j = 1; j <= m; j++){
	// 		printf("%d ", dist[i][j]);
	// 	}
	// 	printf("\n");
	// }

	if(dist[X2][Y2] < INF){
		printf("%d\n", dist[X2][Y2]);
		
		vector<ii> ans;
		int x = X2, y = Y2;
		while(!(x == X1 and y == Y1)){
			ans.pb(ii(x,y));
			ii aux = pai[ii(x,y)];
			x = aux.fi;
			y = aux.se;
		}

		printf("%d %d\n", X1, Y1);
		for(int i = ans.size()-1; i >= 0; i--){
			printf("%d %d\n", ans[i].fi, ans[i].se);
		}
	}
	else{
		printf("-1\n");
	}

	return 0;
}