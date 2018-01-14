#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define pb push_back
#define mp make_pair
#define endl "\n"
#define fi first
#define se second

const int N = 100002;
int n, m, cnt;
vector<int> adj[N], rev[N];
int in[N], out[N], label[N];

void toposort(){
	// priority_queue<int, vector<int>, greater<int> > pq;
	priority_queue<int> pq;

	for(int i = 1; i <= n; i++){
		if(out[i] == 0){
			pq.push(i);
		}
	}

	while(!pq.empty()){
		int u = pq.top();
		// printf("node = %d\n", u);
		pq.pop();

		label[u] = cnt--;

		for(int i = 0; i < rev[u].size(); i++){
			int v = rev[u][i];
			// in[v]--;
			out[v]--;
			if(out[v] == 0) pq.push(v);
		}
	}
}

int main(void){
	scanf("%d%d", &n, &m);
	cnt = n;

	int u, v;
	for(int i = 0; i < m; i++){
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		rev[v].pb(u);
		in[v]++;
		out[u]++;
	}

	toposort();

	for(int i = 1; i <= n; i++){
		printf("%d ", label[i]);
	}
	printf("\n");

	return 0;
}