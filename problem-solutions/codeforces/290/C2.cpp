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

const int N = 102;
string s[N];
vector<int> g[28];
int cnt[28], vis[28];
int n;

bool dfs(int u){
	vis[u] = 1;

	int ret = 0;
	For(i,0,g[u].size()){
		int v = g[u][i];
		if(vis[v] == 1) return 1;
		if(!vis[v]) ret = ret or dfs(v);
	}

	vis[u] = 2;
	return ret;
}

int main(void){
	ios_base::sync_with_stdio(false);	
	cin >> n;

	For(i,0,n){
		cin >> s[i];
	}

	bool impossible = 0;
	For(i,0,n-1){
		For(j,0,min(s[i].size(),s[i+1].size())){
			if(s[i][j] != s[i+1][j]){
				g[s[i][j]-'a'].pb(s[i+1][j]-'a');
				break;
			}
			if(s[i].size() > s[i+1].size() and j == s[i+1].size()-1){
				impossible = 1;
				break;
			}
		}
	}

	if(impossible){
		cout << "Impossible" << endl;
		return 0;
	}

	For(i,0,26){
		sort(g[i].begin(), g[i].end());
		g[i].resize(unique(g[i].begin(), g[i].end()) - g[i].begin());
		For(j,0,g[i].size()) cnt[g[i][j]]++;
	}

	For(i,0,26){
		if(!vis[i] and dfs(i)){
			cout << "Impossible" << endl;
			return 0;
		}
	}

	queue<int> q;

	For(i,0,26){
		if(cnt[i] == 0) q.push(i);
	}

	string res;

	while(!q.empty()){
		int u = q.front();
		q.pop();
		res += u+'a';

		For(i,0,g[u].size()){
			int v = g[u][i];
			cnt[v]--;
			if(cnt[v] == 0){
				q.push(v);
			}
		}
	}

	if(res.size() == 26) cout << res << endl;
	else cout << "Impossible" << endl;

	return 0;
}
