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

const int N = 10005;
int n, m;
map<string, int> toi;
vi is[N], has[N];
int vis[N][3], cnt = 1;
int target;

void dfs(int u, int flag){
	vis[u][flag] = cnt;
	// cout << "u = " << u << " flag = " << flag << " cnt = " << cnt << endl;

	for(int v : is[u]){
		if(vis[v][flag] != cnt){
			dfs(v, flag);
		}
	}

	for(int v : has[u]){
		if(vis[v][1] != cnt){
			dfs(v, 1);
		}
	}
}

int main(void){
	fastcin;
	cin >> n >> m;

	string a, r, b;
	for(int i = 0; i < n; i++){
		cin >> a >> r >> b;

		if(!toi.count(a)){
			toi[a] = toi.size()+1;
		}
		if(!toi.count(b)){
			toi[b] = toi.size()+1;
		}
		
		int u = toi[a], v = toi[b];

		if(r == "is-a"){
			is[u].pb(v);
		}
		else{
			has[u].pb(v);
		}
	}

	for(int i = 1; i <= m; i++){
		cin >> a >> r >> b;
		int u = toi[a];
		target = toi[b];

		int tipo;
		if(r == "is-a")
			tipo = 0;
		else
			tipo = 1;

		dfs(u, 0);

		cout << "Query " << i << ": ";
		if(vis[target][tipo] == cnt){
			cout << "true" << endl;
		}
		else{
			cout << "false" << endl;
		}
		cnt++;
	}

	return 0;
}