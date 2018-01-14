#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

vector<int> adj[28];
bool tem[28];
int vis[28];
int n, trees, acorns;
string s;

void init(){
	trees = acorns = 0;
	
	For(i,0,28){
		adj[i].clear();
		tem[i] = 0;
		vis[i] = 0;
	}
}

int dfs(int u, int ant){
	vis[u] = 1;

	int ret = 1;
	For(i,0,adj[u].size()){
		int v = adj[u][i];
		if(v != ant and vis[v]){
			return 0;
		}
		else if(v != ant and !vis[v]){
			ret = ret and dfs(v, u);
		}
	}
	return ret;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;

	while(n--){
		init();
		while(cin >> s and s[0] != '*'){
			int u = s[1]-'A';
			int v = s[3]-'A';

			adj[u].pb(v);
			adj[v].pb(u);
		}

		cin >> s;

		For(i,0,s.size()){
			if(s[i] != ','){
				tem[s[i]-'A'] = 1;
			}
		}

		For(i,0,26){
			if(tem[i] and adj[i].size() == 0){
				acorns++;
				vis[i] = 1;
			}
			else if(tem[i] and !vis[i]){
				trees += dfs(i,-1);
			}
		}

		printf("There are %d tree(s) and %d acorn(s).\n", trees, acorns);
	}

	return 0;
}
