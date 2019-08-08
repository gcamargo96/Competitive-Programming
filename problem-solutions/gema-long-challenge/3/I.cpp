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

const int N = 100005;
int t, n, m;
vi adj[N];
string s;
int pos_comp[N];
int comp_id[N];
string comp[N];
int cnt = 0;

void init(){
	memset(pos_comp, 0, sizeof pos_comp);
	memset(comp_id, -1, sizeof comp_id);

	for(int i = 0; i < N; i++){
		adj[i].clear();
		comp[i].clear();
	}

	cnt = 0;
}

void dfs(int u){
	comp_id[u] = cnt;
	comp[cnt] += s[u];

	for(int v : adj[u]){
		if(comp_id[v] == -1){
			dfs(v);
		}
	}
}

int main(void){
	fastcin;
	
	cin >> t;

	while(t--){
		init();

		cin >> s;
		n = s.size();

		cin >> m;

		int u, v;
		for(int i = 0; i < m; i++){
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}

		for(int u = 0; u < n; u++){
			if(comp_id[u] == -1){
				dfs(u);
				cnt++;
			}
		}

		for(int i = 0; i < cnt; i++){
			sort(comp[i].begin(), comp[i].end());
		}

		string ans;
		for(int i = 0; i < n; i++){
			// cout << comp_id[i] << " " << pos_comp[i] << endl;
			int id = comp_id[i];
			int pos = pos_comp[id]++;
			ans += comp[id][pos];
		}

		cout << ans << endl;
	}


	return 0;
}