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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int n;

int main(void){
	scanf("%d", &n);

	ll xorsum = 0;

	ll x, m;
	while(n--){
		scanf("%lld%lld", &x, &m);
		ll fm = 0, fx = 0;

		ll M = x+m-1;
		if(M == 1){
			fm ^= 1;
		}
		else if(M == 2){
			fm ^= 1^2;
		}
		else{
			ll a = (M-3)/4LL;
			ll r = (M-3)%4LL;

			ll X = 3 + 4LL*a;
			while(r--){
				X++;
				fm ^= X;
			}
		}

		x--;
		if(x == 1){
			fx ^= 1;
		}
		else if(x == 2){
			fx ^= 1^2;
		}
		else if(x >= 3){
			ll a = (x-3)/4LL;
			ll r = (x-3)%4LL;

			ll X = 3 + 4LL*a;
			while(r--){
				X++;
				fx ^= X;
			}
		}

		xorsum ^= (fm^fx);
	}

	// printf("%lld\n", xorsum);

	if(xorsum != 0){
		printf("tolik\n");
	}
	else{
		printf("bolik\n");
	}

	return 0;
}