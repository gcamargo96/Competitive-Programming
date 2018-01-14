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

const int N = 2002;
int n;
int p[N], lv[N], mem[N];

int dfs(int u){
	if(p[u] == -1) return mem[u] = 1;
	if(mem[u] != -1) return mem[u];
	return mem[u] = 1 + dfs(p[u]);
}

int main(void){
	scanf("%d", &n);

	int x;
	for(int i = 1; i <= n; i++){
		scanf("%d", &p[i]);
	}

	memset(mem, -1, sizeof mem);

	for(int i = 1; i <= n; i++){
		dfs(i);
	}

	int res = 0;
	for(int i = 1; i <= n; i++){
		res = max(res, mem[i]);
	}

	printf("%d\n", res);

	return 0;
}

