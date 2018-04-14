#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

ll a, b;

int main(void){
	scanf("%lld%lld", &a, &b);

	while(a > 0 and b > 0){
		// printf("x %lld %lld\n", a, b);
		if(a == 2LL*b){
			a -= 2LL*b;
		}
		else if(b == 2LL*a){
			b -= 2LL*a;
		}
		else if(a >= 2LL*b){
			ll k = (a-2LL*b)/(2LL*b);
			ll r = (a-2LL*b)%(2LL*b);
			if(r != 0)
				k++;

			a -= 2LL*b*k;
		}
		else if(b >= 2LL*a){
			ll k = (b-2LL*a)/(2LL*a);
			ll r = (b-2LL*a)%(2LL*a);
			if(r != 0)
				k++;

			b -= 2LL*a*k;
		}
		else{
			break;
		}
	}

	printf("%lld %lld\n", a, b);

	return 0;
}