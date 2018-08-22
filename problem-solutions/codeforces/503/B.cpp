#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 1005;
bool vis[N];
int p[N];
int n;

int main(void){
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", &p[i]);
	}

	for(int i = 1; i <= n; i++){
		memset(vis, 0, sizeof vis);

		int u = i;
		while(!vis[u]){
			vis[u] = 1;
			u = p[u];
		}
		printf("%d ", u);
	}
	printf("\n");

	return 0;
}