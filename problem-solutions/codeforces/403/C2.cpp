#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 200002;
vi adj[N];
int n;

int main(void){
	scanf("%d", &n);

	int u, v;
	For(i,0,n-1){
		scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}

	int res = 0;
	for(int i = 1; i <= n; i++){
		res = max(res, (int)adj[i].size()+1);
	}



	return 0;
}

