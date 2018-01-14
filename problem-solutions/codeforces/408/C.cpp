#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 300002;
int n;
int a[N];
vi adj[N];

void solve()

int main(void){
	scanf("%d", &n);

	int maior = -1000000002, id = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if(a[i] > maior){
			maior = a[i];
			id = i;
		}
	}

	if(i == 1){
		printf("%d\n", a[1]);
		return 0;
	}

	int u, v;
	For(i,0,n-1){
		scanf("%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}

	solve(id);

	return 0;
}

