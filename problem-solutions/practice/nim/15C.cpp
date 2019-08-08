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
		ll aux = 0;

		if(x == 1){
			if(m == 1){
				aux ^= 1;
			}
			else if(m == 2){
				aux ^= 1^2;
			}
			else{
				ll a = (m-3)/4LL;
				ll r = (m-3)%4LL;

				x = 3 + 4LL*a;
				while(r--){
					x++;
					aux ^= x;
				}
			}
		}
		else if(x%2 == 0){
			if(m <= 3){
				while(m--){
					aux ^= x;
					x++;
				}
			}
			else{
				ll a = (m-4)/4LL;
				ll r = (m-4)%4LL;

				x = x+4 + 4LL*a;
				while(r--){
					x++;
					aux ^= x;
				}
			}
		}
		else{
			ll a = (m-1)/4LL;
			ll r = (m-1)%4LL;

			aux = x;
			x = x + 4LL*a;
			while(r--){
				x++;
				aux ^= x;
			}
		}

		xorsum ^= aux;
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