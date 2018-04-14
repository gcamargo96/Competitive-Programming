#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
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

const int N = 100005;
vi adj[N];
int n;
set<ii> ans;
string s1, s2;
bool vis[N];

void dfs(int u) {
	vis[u] = 1;

	for(int v : adj[u]){
		if(!vis[v]){
			// cout << "u = " << u << " v = " << v << endl;
			ans.insert(ii(u,v));
			dfs(v);
		}
	}
}

int main(void){
	fastcin;
	cin >> n;
	cin >> s1 >> s2;

	for(int i = 0; i < n; i++){
		int u = s1[i]-'a';
		int v = s2[i]-'a';
		adj[u].pb(v);
		adj[v].pb(u);
	}

	for(int i = 0; i < 26; i++){
		if(!vis[i]){
			dfs(i);
		}
	}

	cout << ans.size() << endl;

	for(ii e : ans){
		cout << char(e.fi+'a') << " " << char(e.se+'a') << endl;
	}

	return 0;
}