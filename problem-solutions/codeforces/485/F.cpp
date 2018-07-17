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

const int N = (1<<23);
int n, m;
int fullmask;
int a[N], vis[N];
set<int> s;

void dfs(int u){
	if(vis[u]) return;
	vis[u] = 1;

	if(s.count(u)){
		dfs(u ^ fullmask);
	}

	for(int i = 0; i < n; i++){
		if(u & (1<<i)){
			dfs(u ^ (1<<i));
		}
	}
}

int main(void){
	scanf("%d%d", &n, &m);
	fullmask = (1 << n) - 1;

	for(int i = 0; i < m; i++){
		scanf("%d", &a[i]);
		s.insert(a[i]);
	}

	sort(a, a+m);

	int ans = 0;
	for(int i = 0; i < m; i++){
		if(vis[a[i]]) continue;
		dfs(a[i]);
		ans++;
	}

	printf("%d\n", ans);

	return 0;
}