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
ll n;
int k;
ll a[N];

int main(void){
	scanf("%lld%d", &n, &k);

	for(int i = 1; i <= k; i++){
		scanf("%lld", &a[i]);
	}

	pair<ll,ll> ans(1LL, 0LL);
	ll best = 0;
	for(int i = 1; i <= k; i++){
		ll q = n/a[i];
		if(q*a[i] > best){
			ans.fi = i;
			ans.se = q;
			best = q*a[i];
		}
	}

	printf("%lld %lld\n", ans.fi, ans.se);

	return 0;
}