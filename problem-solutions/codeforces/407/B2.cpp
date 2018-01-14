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
set<ll> bad;

int main(void){
	scanf("%lld%lld%lld%lld", &b1, &q, &l, &m);

	ll x;
	For(i,0,m){
		scanf("%lld", &x);
		bad.insert(x);
	}

	int cnt = 0;
	ll b = b1;
	int res = 0;
	while(abs(b) <= l and cnt < 100){
		if(!bad.count(b)) res++;	
		b = b*q;
		cnt++;
	}

	if(res > 30){
		printf("inf\n");
	}
	else{
		printf("%d\n", res);
	}

	return 0;
}

