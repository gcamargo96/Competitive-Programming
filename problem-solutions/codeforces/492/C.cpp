#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define Endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 55;
int g[7][N];
int n, k;
set<int> cars;
ii pai[7][N];
int vis[7][N];
int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1} };
ii beg[N], End[N];

bool bfs(int car){
	queue<ii> q;
	q.push(beg[car]);

	while(!q.empty()){
		int x = q.front().fi;
		int y = q.front().se;
		q.pop();

		// printf("%d %d\n", x, y);

		for(int i = 0; i < 4; i++){
			int nx = x + d[i][0];
			int ny = y + d[i][1];

			if((nx == 1 or nx == 4) and g[nx][ny] == car){
				pai[nx][ny] = ii(x,y);
				return 1;
			}

			if((nx == 2 or nx == 3) and !vis[nx][ny] and g[nx][ny] == 0){
				vis[nx][ny] = 1;
				pai[nx][ny] = ii(x, y);
				q.push(ii(nx, ny));
			}
		}
	}

	return 0;
}

int main(void){
	scanf("%d%d", &n, &k);

	for(int i = 1; i <= k; i++){
		cars.insert(i);
	}

	for(int i = 1; i <= 4; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &g[i][j]);

			if(i == 1 or i == 4){
				End[g[i][j]] = ii(i, j);
			}
			else{
				beg[g[i][j]] = ii(i, j);
			}
		}
	}

	// for(int i = 1; i <= k; i++){
	// 	printf("car = %d, beg = (%d,%d), end = (%d,%d)\n", i, beg[i].fi, beg[i].se, End[i].fi, End[i].se);
	// }

	vector<pair<int, ii> > ans;

	while(cars.size() > 0){
		bool flag = 0;
		vi to_erase;

		for(int car : cars){
			memset(vis, 0, sizeof vis);
			bool ok = bfs(car);
			// printf("car = %d, ok = %d\n", car, int(ok));

			if(ok){
				// printf("OK %d\n", car);

				vector<ii> path;
				ii cur = End[car];
				while(cur != beg[car]){
					// printf("%d %d\n", cur.fi, cur.se);
					path.pb(ii(cur.fi, cur.se));
					cur = pai[cur.fi][cur.se];
				}

				for(int i = int(path.size())-1; i >= 0; i--){
					ans.pb(mp(car, ii(path[i].fi, path[i].se)));
				}

				g[beg[car].fi][beg[car].se] = 0;
				to_erase.pb(car);
				flag = 1;
			}
		}

		if(flag == 0){
			printf("-1\n");
			return 0;
		}

		for(int car : to_erase){
			cars.erase(car);
		}
	}

	printf("%d\n", int(ans.size()));

	for(int i = 0; i < ans.size(); i++){
		printf("%d %d %d\n", ans[i].fi, ans[i].se.fi, ans[i].se.se);
	}

	return 0;
}