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

#define M 1000000007

const int N = 100005;
int t, n;
int a[N];
ll lr[N], rl[N];

ll mul(ll a, ll b){
	return (a*b)%M;
}

ll add(ll a, ll b){
	return (a+b)%M;
}

ll sub(ll a, ll b){
	return (a-b+M)%M;
}

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);

		ll tot = 1;
		for(int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
			tot = mul(tot, a[i]);
		}

		lr[0] = rl[n+1] = 1;

		for(int i = 1; i <= n; i++){
			lr[i] = mul(lr[i-1], a[i]);
		}

		for(int i = n; i >= 1; i--){
			rl[i] = mul(rl[i+1], a[i]);
		}

		ll ans = mul(tot, n);
		for(int i = 1; i <= n; i++){
			ans = sub(ans, mul(lr[i-1], rl[i+1]));
		}

		printf("%lld\n", ans);
	}

	return 0;
}