#include <bits/stdc++.h>
using namespace std;
#define pb push_back

const int N = 100002;
int n, m;
vector<int> adj[N];
int color[N];
int res = 1;
vector<int> cover1, cover2;

void dfs(int x, int c){
	color[x] = c;
	if(c == 0) cover1.pb(x);
	if(c == 1) cover2.pb(x);

	for(int i = 0; i < adj[x].size(); i++){
		int nxt = adj[x][i];
		if(color[nxt] == -1){
			dfs(nxt, !c);
		}
		else if(color[nxt] == c){
			res = 0;
			return;
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;

	int u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	res = 1;
   	int flag = 0;
	memset(color, -1, sizeof color);

	for(int i = 1; i <= n; i++){
		if(color[i] == -1 and adj[i].size() > 0){
			dfs(i, 0);
		}
		/*if(color[i] == -1 and !flag){
			flag = 1;
			dfs(i, 0);
		}*/
		//if(color[i] == -1 and adj[i].size() > 0 and flag) res = 0;
	}

	if(!res or cover1.size() == 0 or cover2.size() == 0){
		cout << "-1" << endl;
	}
	else{
		cout << cover1.size() << endl;
		for(int i = 0; i < cover1.size(); i++){
			cout << cover1[i] << " ";
		}
		cout << endl;
		cout << cover2.size() << endl;
		for(int i = 0; i < cover2.size(); i++){
			cout << cover2[i] << " ";
		}
		cout << endl;
	}

	return 0;
}
