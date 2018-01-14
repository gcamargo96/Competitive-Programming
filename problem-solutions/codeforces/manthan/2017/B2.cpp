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
#define fast_cin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 100005;
int n;
ll p, q, r;
ll v[N], min1[N], max1[N], min2[N], max2[N];

int main(void){
	scanf("%d%lld%lld%lld", &n, &p, &q, &r);

	for(int i = 1; i <= n; i++){
		scanf("%lld", &v[i]);
	}

	max1[0] = -1000000010;
	for(int i = 1; i <= n; i++){
		max1[i] = max(max1[i-1], v[i]);
	}

	max2[n+1] = -1000000010;
	for(int i = n; i >= 1; i--){
		max2[i] = max(max2[i+1], v[i]);
	}

	min1[0] = 1000000010;
	for(int i = 1; i <= n; i++){
		min1[i] = min(min1[i-1], v[i]);
	}

	min2[n+1] = 1000000010;
	for(int i = n; i >= 1; i--){
		min2[i] = min(min2[i+1], v[i]);
	}

	ll ans = -4000000000000000000LL;
	for(int i = 1; i <= n; i++){
		ll cur = 0;
		if(p < 0){
			cur += p * min1[i];
		}
		else{
			cur += p * max1[i];
		}

		cur += q * v[i];

		if(r < 0){
			cur += r*min2[i];
		}
		else{
			cur += r*max2[i];
		}
		ans = max(ans, cur);
	}

	printf("%lld\n", ans);

	return 0;
}