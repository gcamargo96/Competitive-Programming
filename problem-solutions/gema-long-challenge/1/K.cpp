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
int m, n;
vector<string> text;
vector<int> toposort;
unordered_map<string, int> word_to_node;
unordered_map<int, string> node_to_word;
unordered_map<int, ii> node_info, scc_info;
vi adj[N], rev[N], adj_scc[N];
int cnt_nodes = 0, cnt_scc = 1;
int vis[N], scc[N];

void to_lower(string& s){
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= 'A' and s[i] <= 'Z'){
			s[i] -= 'A';
			s[i] += 'a';
		}
	}
}

int count_r(string& s){
	int cnt = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'r')
			cnt++;
	}
	return cnt;
}

void add_node(string& s){
	if(!word_to_node.count(s))
		word_to_node[s] = ++cnt_nodes;

	int u = word_to_node[s];

	if(!node_to_word.count(u)){
		node_to_word[u] = s;
	}

	node_info[u] = ii(count_r(s), s.size());
}

void add_edge(string& a, string& b){
	int u = word_to_node[a];
	int v = word_to_node[b];
	adj[u].pb(v);
	rev[v].pb(u);
}

void dfs(int u){
	vis[u] = 1;

	for(int v : adj[u]){
		if(!vis[v])
			dfs(v);
	}

	toposort.pb(u);
}

void dfs_rev(int u){
	scc[u] = cnt_scc;

	if(scc_info.count(cnt_scc)){
		scc_info[cnt_scc] = min(scc_info[cnt_scc], node_info[u]);
	}
	else{
		scc_info[cnt_scc] = node_info[u];
	}

	for(int v : rev[u]){
		if(scc[v] == 0){
			dfs_rev(v);
		}
		else if(scc[u] != scc[v]){
			adj_scc[scc[v]].pb(scc[u]);
		}
	}
}

int main(void){
	fastcin;
	cin >> m;

	string s;
	for(int i = 0; i < m; i++){
		cin >> s;
		to_lower(s);
		text.pb(s);
	}

	cin >> n;

	string a, b;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		to_lower(a);
		to_lower(b);
		add_node(a);
		add_node(b);
		add_edge(a, b);
	}

	// gerando SCCs:

	for(int u = 1; u <= cnt_nodes; u++){
		if(!vis[u])
			dfs(u);
	}

	reverse(toposort.begin(), toposort.end());

	for(int i = 0; i < toposort.size(); i++){
		int u = toposort[i];

		if(scc[u] == 0){
			dfs_rev(u);
			cnt_scc++;
		}
	}

	// a resposta para um nó será o mínimo entre a resposta de seu SCC
	// e a resposta dos SCCs que alcança

	for(int u = cnt_scc-1; u >= 1; u--){
		for(int v : adj_scc[u]){
			scc_info[u] = min(scc_info[u], scc_info[v]);
		}
	}

	pair<ll,ll> ans(0,0);
	for(int i = 0; i < m; i++){
		if(word_to_node.count(text[i])){
			int u = word_to_node[text[i]];
			ans.fi += scc_info[scc[u]].fi;
			ans.se += scc_info[scc[u]].se;
		}
		else{
			ans.fi += count_r(text[i]);
			ans.se += text[i].size();
		}
	}

	cout << ans.fi << " " << ans.se << endl;

	return 0;
}