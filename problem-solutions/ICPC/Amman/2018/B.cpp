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
int t;
ll x, n;
ll v[N];

int main(void){
	scanf("%d", &t);

	while(t--){
		scanf("%lld%lld", &x, &n);

		if(n == 1){
			printf("%lld\n", x);
			continue;
		}

		ll q = x/(2LL*n - 2);
		ll r = x%(2LL*n - 2);

		v[0] = v[n-1] = q;
		for(int i = 1; i < n-1; i++){
			v[i] = 2LL*q;
		}

		for(int i = 0; i < n and r > 0; i++){
			v[i]++;
			r--;
		}
		for(int i = n-2; i >= 0 and r > 0; i--){
			v[i]++;
			r--;
		}

		for(int i = 0; i < n; i++){
			printf("%lld ", v[i]);
		}
		printf("\n");
	}

	return 0;
}