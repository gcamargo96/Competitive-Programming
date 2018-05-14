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

ll a[15], b[15];

void cpy(){
	for(int i = 0; i < 14; i++){
		b[i] = a[i];
	}
}

int main(void){
	for(int i = 0; i < 14; i++){
		scanf("%lld", &a[i]);
	}

	ll best = 0;
	for(int i = 0; i < 14; i++){
		cpy();

		ll x = a[i]/14, y = a[i]%14;
		b[i] = 0;

		// printf("x = %lld, y = %lld\n", x, y);

		for(int j = 0; j < 14; j++){
			b[(i+1+j)%14] += x;
		}
		for(int j = 0; j < y; j++){
			b[(i+1+j)%14]++;
		}

		ll ans = 0;
		for(int i = 0; i < 14; i++){
		// 	printf("%lld ", b[i]);
			if(b[i]%2 == 0){
				ans += b[i];
			}
		}

		best = max(ans, best);
		// printf("\n");
	}

	printf("%lld\n", best);

	return 0;
}