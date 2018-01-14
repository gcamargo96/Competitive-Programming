#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
//#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

#define H 0
#define V 1

const int N = 100002;
int n, lx, ly, bx, by;

map<int,vector<int>> cx, cy;
map<pair<ii,int> , bool> vis;

int bfs(int x, int y, int dir){
	queue<pair<ii, ii> > q;
	q.push(mp(mp(x,y), mp(dir,0)));

	int cnt;
	while(!q.empty()){
		x = q.front().fi.fi;
		y = q.front().fi.se;
		dir = q.front().se.fi;
		cnt = q.front().se.se;
		vis[mp(mp(x,y), dir)] = 1;
		q.pop();

		//cout << x << " " << y << " " << dir << endl;
		//if(x == bx and y == by) return cnt;
		if(x == bx or y == by) return cnt;

		if(dir == V){
			For(i,0,cx[x].size()){
				int nx = x, ny = cx[x][i];
				if(ny != y and !vis[mp(mp(nx,ny), H)]){
					q.push(mp(mp(nx,ny), mp(H, cnt+1)));
				}
			}
		}
		if(dir == H){
			For(i,0,cy[y].size()){
				int nx = cy[y][i], ny = y;
				if(nx != x and !vis[mp(mp(nx,ny), V)]){
					q.push(mp(mp(nx,ny), mp(V, cnt+1)));
				}
			}
		}
	}

	return -1;
}

int main(void){
	freopen("lasers.in", "r", stdin);
	freopen("lasers.out", "w", stdout);
	scanf("%d%d%d%d%d", &n, &lx, &ly, &bx, &by);

	int x, y;
	For(i,0,n){
		scanf("%d%d", &x, &y);
		cx[x].pb(y);
		cy[y].pb(x);
	}
	//cx[bx].pb(by);
	//cy[by].pb(bx);

	int res1 = bfs(lx, ly, H);
   	int res2 = bfs(lx, ly, V);

	if(res1 != -1 and res2 != -1) printf("%d\n", min(res1, res2));
	if(res1 == -1 and res2 != -1) printf("%d\n", res2);
	if(res1 != -1 and res2 == -1) printf("%d\n", res1);
	if(res1 == -1 and res2 == -1) printf("-1\n");
	
	return 0;
}

