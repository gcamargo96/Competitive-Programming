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

const int N = 200005;
ll v[N], acum[N];
int n, q;

int main(void){
	scanf("%d%d", &n, &q);

	for(int i = 1; i <= n; i++){
		scanf("%lld", &v[i]);
	}

	int l, r;
	for(int i = 0; i < q; i++){
		scanf("%d%d", &l, &r);
		acum[l]++;
		acum[r+1]--;
	}

	for(int i = 1; i <= n; i++){
		acum[i] += acum[i-1];
	}

	sort(v+1, v+n+1);
	sort(acum+1, acum+n+1);

	ll ans = 0;
	for(int i = n; i >= 1; i--){
		ans += v[i] * acum[i];
	}

	printf("%lld\n", ans);

	return 0;
}