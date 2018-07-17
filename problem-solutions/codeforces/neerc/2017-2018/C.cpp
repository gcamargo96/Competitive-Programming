#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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

#define LOWER 1
#define UPPER 2

struct Edge{
	int u, v, w;

	Edge () {}

	Edge(int _u, int _v, int _w){
		u = _u;
		v = _v;
		w = _w;
	}

	bool operator<(const Edge& b) const{
		return w > b.w;
	}
};

const int N = 30;
vector<Edge> e;
vector<int> mst[N], peso_mst[N];
set<char> cons;
int peso[N][N];
int pai[N], Rank[N], label[N], vis[N];
string s;

void init(){
	for(char c = 'a'; c <= 'z'; c++){
		if(c != 'a' and c != 'e' and c != 'i' and c != 'o' and c != 'u' and c != 'w' and c != 'y'){
			cons.insert(c);
		}
		pai[c-'a'] = c-'a';
		Rank[c-'a'] = 1;
	}
}

int find(int u){
	if(pai[u] == u) return u;
	return pai[u] = find(pai[u]);
}

void join(int u, int v){
	u = find(u);
	v = find(v);
	if(Rank[u] < Rank[v]) swap(u,v);
	if(u != v){
		if(Rank[u] == Rank[v]) Rank[u]++;
		pai[v] = u;
	}
}

void kruskal(){
	sort(e.begin(), e.end());

	for(int i = 0; i < e.size(); i++){
		if(find(e[i].u) != find(e[i].v)){
			mst[e[i].u].pb(e[i].v);
			mst[e[i].v].pb(e[i].u);
			peso_mst[e[i].u].pb(e[i].w);
			peso_mst[e[i].v].pb(e[i].w);
		}
	}
}

void dfs(int u, int ca){
	if(vis[u]) return;
	vis[u] = 1;
	label[u] = ca;

	for(int v : mst[u]){
		if(vis[v]) continue;

		if(ca == LOWER){
			dfs(v, UPPER);
		}
		else{
			dfs(v, LOWER);
		}
	}
}

int main(void){
	freopen("consonant.in", "r", stdin);
	freopen("consonant.out", "w", stdout);

	fastcin;
	init();
	cin >> s;

	for(int i = 0; i < int(s.size())-1; i++){
		if(cons.count(s[i]) and cons.count(s[i+1])){
			int u = s[i]-'a', v = s[i+1]-'a';
			peso[u][v]++;
			peso[v][u]++;
		}
	}

	for(int i = 0; i < 26; i++){
		for(int j = i+1; j < 26; j++){
			if(peso[i][j] > 0){
				e.emplace_back(i, j, peso[i][j]);
			}
		}
	}

	kruskal();

	for(int i = 0; i < s.size(); i++){
		if(!label[s[i]-'a']) dfs(s[i]-'a', LOWER);
		if(label[s[i]-'a'] == LOWER) cout << s[i]; // printf("%c", s[i]);
		else cout << char(s[i]-'a'+'A'); // printf("%c", s[i]-'a'+'A');		
	}
	cout << endl; // printf("\n");

	return 0;
}