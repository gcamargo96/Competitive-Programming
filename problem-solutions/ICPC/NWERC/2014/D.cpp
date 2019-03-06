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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 500005;
ll n;
int m;
vi adj[N];
int dir[N];
int vis[N];
ll balls[N];
vi v;

void toposort(int u){
	if(u == 0) return;
	vis[u] = 1;
	
	for(int v : adj[u]){
		if(!vis[v])
			toposort(v);
	}

	v.pb(u);
}

int L(int u){
	return adj[u][0];
}

int R(int u){
	return adj[u][1];
}

int main(void){
	fastcin;
	cin >> n >> m;

	char c;
	int l, r;
	for(int i = 1; i <= m; i++){
		cin >> c >> l >> r;
		dir[i] = (c == 'R');
		adj[i].pb(l);
		adj[i].pb(r);
	}

	toposort(1);
	reverse(v.begin(), v.end());

	balls[1] = n;
	for(int i = 0; i < v.size(); i++){
		int u = v[i];

		balls[L(u)] += balls[u]/2;
		balls[R(u)] += balls[u]/2;

		if(balls[u]&1){
			if(dir[u] == 0) balls[L(u)]++;
			else balls[R(u)]++;
			dir[u] = !dir[u];
		}
	}

	for(int u = 1; u <= m; u++){
		cout << (dir[u] == 0 ? 'L' : 'R');
	}
	cout << endl;

	return 0;
}