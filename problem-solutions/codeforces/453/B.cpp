#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 10002;
vi adj[N];
int color[N], curcolor[N];
int n;

void paint(int u, int c){
	curcolor[u] = c;
	// printf("u = %d, c = %d\n", u, c);

	for(int v : adj[u]){
		paint(v, c);
	}
}

int main(void){
	scanf("%d", &n);

	int p;
	for(int i = 2; i <= n; i++){
		scanf("%d", &p);
		adj[p].pb(i);
	}

	for(int i = 1; i <= n; i++){
		scanf("%d", &color[i]);
	}

	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(curcolor[i] != color[i]){
			ans++;
			paint(i, color[i]);
			// printf("\n");
		}
	}

	printf("%d\n", ans);

	return 0;
}