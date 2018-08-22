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

const int N = 1002;
int n;
map<int, vector<int>> cx, cy;
bool vis[N][N];

void dfs(int x, int y){
	vis[x][y] = 1;

	int nx = x, ny;
	For(i,0,cx[x].size()){
		ny = cx[x][i];
		if(!vis[nx][ny]) dfs(nx, ny);
	}
	
	ny = y;
	For(i,0,cy[y].size()){
		nx = cy[y][i];
		if(!vis[nx][ny]) dfs(nx, ny);
	}
}

int main(void){
	scanf("%d", &n);

	int x, y;
	For(i,0,n){
		scanf("%d%d", &x, &y);
		cx[x].pb(y);
		cy[y].pb(x);
	}

	int cnt = 0;
	for(auto it = cx.begin(); it != cx.end(); it++){
		vector<int> v = it->se;
		x = it->fi;
		For(i,0,v.size()){
			y = v[i];
			if(!vis[x][y]){
				cnt++;
				dfs(x, y);
			}
		}
	}

	printf("%d\n", cnt-1);

	return 0;
}

