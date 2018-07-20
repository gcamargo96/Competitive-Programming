#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 100005;
int a[N];
int vis[N], dif[N];
int n;

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	for(int i = n-1; i >= 0; i--){
		dif[i] = dif[i+1];
		
		if(!vis[a[i]]){
			dif[i]++;
		}
		vis[a[i]] = 1;
	}

	ll ans = 0;
	memset(vis, 0, sizeof vis);
	for(int i = 0; i < n; i++){
		if(!vis[a[i]]){
			ans += dif[i+1];
		}
		vis[a[i]] = 1;
	}

	printf("%lld\n", ans);

	return 0;
}