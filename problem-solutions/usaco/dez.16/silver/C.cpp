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

const int N = 202;
int n;
vector<int> adj[N];
int vis[N];

struct cow{
	double x, y, p;
};

cow cows[N];

int dfs(int u){
	vis[u] = 1;

	int ret = 0;
	For(i,0,adj[u].size()){
		int v = adj[u][i];
		if(!vis[v]){
			ret += dfs(v);
		}
	}

	return ret+1;
}

int main(void){
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);

	scanf("%d", &n);

	For(i,0,n){
		scanf("%lf%lf%lf", &cows[i].x, &cows[i].y, &cows[i].p);
	}

	For(i,0,n){
		For(j,0,n){
			if(i != j){
				double dist = (cows[i].x-cows[j].x)*(cows[i].x-cows[j].x) + (cows[i].y-cows[j].y)*(cows[i].y-cows[j].y);
				if(dist < cows[i].p*cows[i].p){
					adj[i].pb(j);
				}
			}
		}
	}

	int res = 0;
	For(i,0,n){
		memset(vis, 0, sizeof vis);
		res = max(res, dfs(i));
	}

	cout << res << endl;

	return 0;
}

