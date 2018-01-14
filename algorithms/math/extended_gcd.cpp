#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
typedef long long ll;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b)
{
    ll temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

pair<ll,ll> extended_gcd(ll a, ll b, ll &g) {
	ll y=0, x=1;
	ll yy=1, xx=0;
	
	while(b)
	{
		ll xn=x-(a/b)*xx, yn=y-(a/b)*yy;
		x=xx;y=yy;
		xx=xn;yy=yn;
		a%=b;
		swap(a,b);
	}
	g=a;
	return mp(x,y);
}
