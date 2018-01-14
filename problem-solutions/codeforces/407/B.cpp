#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 100002;
ll b1, q, l, m;
//int v[N];
set<ll> bad;

int digits(ll x){
	if(x == 0) return 0;
	int cnt = 0;
	while(x > 0){
		x /= 10;
		cnt++;
	}
	return cnt-1;
}

int main(void){
	scanf("%lld%lld%lld%lld", &b1, &q, &l, &m);

	int x;
	For(i,0,m){
		scanf("%lld", &x);
		bad.insert(x);
	}

	if(b1 == 0){
		if(!bad.count(0)) printf("inf\n");
		else printf("0\n");
		return 0;
	}
	if(q == 0){
		int res = 0;
		if(!bad.count(b1)) res++;
		if(!bad.count(0)) printf("inf\n");
		else printf("%d\n", res);
		return 0;
	}
	if(q == 1){
		if(!bad.count(b1)) printf("inf\n");
		else printf("0\n");
		return 0;
	}
	if(q == -1){
		if(bad.count(b1) and bad.count(-b1)) printf("0\n");
		else printf("inf\n");
		return 0;
	}

	ll b = b1, res = 0;
	while(abs(b) <= l){
		if(!bad.count(b)) res++;
		if(digits(b) + digits(q) > 9) break;
		b = b*q;
	}

	printf("%lld\n", res);

	return 0;
}

