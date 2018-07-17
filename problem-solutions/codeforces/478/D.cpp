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

const int N = 200002;
int n;
ll a, b;
ll x, vx, vy;
map<ll, ll> cnt;
map<pair<ll,ll> ,ll> same;
int pos = 0, neg = 0;

int main(void){
	scanf("%d%lld%lld", &n, &a, &b);

	ll ans = 0;
	for(int i = 0; i < n; i++){
		scanf("%lld%lld%lld", &x, &vx, &vy);

		ll val = a*vx - vy;
		ans += cnt[val] - same[{vx,vy}];
		cnt[val]++;
		same[{vx,vy}]++;
	}

	printf("%lld\n", 2LL*ans);

	return 0;
}