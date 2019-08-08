#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define endl "\n"
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

#define ODD 0
#define EVEN 1
#define M 1000000007

ll l, r;
ll curOdd = 1, curEven = 2, curSize = 1;

ll add(ll a, ll b){
	a %= M;
	b %= M;
	return (a+b)%M;
}

ll sub(ll a, ll b){
	a %= M;
	b %= M;
	return (a-b+M)%M;
}

ll mul(ll a, ll b){
	a %= M;
	b %= M;
	return (a*b)%M;
}

ll fastpow(ll b, ll e){
	if(e == 0) return 1;

	ll x = fastpow(b, e/2);
	if(e%2 == 0){
		return mul(x,x);
	}
	else{
		return mul(b, mul(x,x));
	}
}

ll Div(ll a, ll b){
	return mul(a, fastpow(b, M-2));
}

ll getSum(ll x){
	ll pos = 0;
	ll sum = 0;
	bool turn = ODD;
	curOdd = 1, curEven = 2, curSize = 1;

	for(curSize = 1; pos + curSize <= x; pos += curSize, curSize *= 2LL){
		ll a0;
		if(turn == ODD){
			a0 = curOdd%M;
		}
		else{ // EVEN
			a0 = curEven%M;
		}

		ll an = add(a0, mul(sub(curSize,1), 2));
		ll sn = Div(mul(add(a0,an), curSize), 2);
		sum = add(sum, sn);
		// pos += curSize;
		// printf("sn = %lld\n", sn);

		if(turn == ODD){
			curOdd = add(an,2);
		}
		else{
			curEven = add(an,2);
		}

		turn = !turn;
	}

	// printf("pos = %lld, curSize = %lld, pos+curSize = %lld\n", pos, curSize, pos+curSize);

	if(pos < x){
		ll a0 = (turn == ODD ? curOdd : curEven);
		ll n = sub(x, pos);
		ll an = add(a0, mul(sub(n,1), 2));
		ll sn = Div(mul(add(a0,an), n), 2);
		sum = add(sum, sn);

		// printf("cur = %lld\n", cur);
		// for(ll i = pos; i < x; i++){
		// 	sum += cur;
		// 	cur += 2;
		// }
	}

	return sum;
}

int main(void){
	scanf("%lld%lld", &l, &r);

	ll suml = getSum(l-1);
	ll sumr = getSum(r);
	ll ans = sub(sumr, suml);

	printf("%lld\n", ans);

	return 0;
}