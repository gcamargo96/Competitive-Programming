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

#define INF 0x3f3f3f3f

const int N = 1002;
int n, t;
vi tree[N], sub[N], nodes, lin;
int in[N], out[N], pai[N];

bool cmp(int u, int v){
	if(sub[u].size() == sub[v].size())
		return u < v;
	return sub[u].size() < sub[v].size();
}

void no(){
	printf("NO\n");
	exit(0);
}

void dfs(int u, int p){
	lin.pb(u);
	in[u] = t++;
	for(int v : tree[u]){
		if(v == p) continue;
		dfs(v, u);
	}
	out[u] = t-1;
}

int main(void){
	scanf("%d", &n);

	int m;
	for(int u = 1; u <= n; u++){
		scanf("%d", &m);
		
		int v;
		for(int j = 0; j < m; j++){
			scanf("%d", &v);
			sub[u].pb(v);
		}
		sort(sub[u].begin(), sub[u].end());
		nodes.pb(u);
	}


	// ordena da menor para a maior subtree
	sort(nodes.begin(), nodes.end(), cmp);

	// construindo a arvores
	for(int i = 0; i < n; i++){
		int u = nodes[i];

		for(int v : sub[u]){
			if(sub[v].size() >= sub[u].size()){ // self loops são pegos aqui
				no();
			}
			if(pai[v] == 0){
				tree[u].pb(v);
				pai[v] = u;
			}
		}
	}

	// preenchendo um vetor com a arvore linearizada
	dfs(nodes.back(), 0);

	// checando se a árvore é conexa
	if(lin.size() != n){
		no();
	}

	// verificando se as subtrees criadas batem com as do input
	for(int u = 1; u <= n; u++){
		vi subi;
		for(int i = in[u]+1; i <= out[u]; i++){
			int v = lin[i];
			subi.pb(v);
		}
		
		sort(subi.begin(), subi.end());

		if(sub[u] != subi){
			no();
		}
	}

	printf("YES\n");
	for(int u = 1; u <= n; u++){
		if(pai[u] != 0){
			printf("%d %d\n", pai[u], u);
		}
	}

	return 0;
}