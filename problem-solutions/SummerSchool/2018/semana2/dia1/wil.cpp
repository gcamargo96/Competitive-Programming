#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
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

struct minqueue{
	int t;
	queue<pair<ll,ll> > qu;
	deque<pair<ll,ll> > mi;

	minqueue(){
		t = 0;
	}

	void push(ll x){
		t++;
		while(!mi.empty() and mi.back().fi > x)
			mi.pop_back();

		mi.push_back(mp(x, t));
		qu.push(mp(x, t));
	}

	void pop(){
		if(!mi.empty() and mi.front().se == qu.front().se)
			mi.pop_front();

		qu.pop();
	}

	ll mini(){
		if(mi.empty()) return 0;
		return mi.front().fi;
	}
};

const int N = 2000002;
int n, d;
ll p;
int w[N];
ll acum[N];

int main(void){
	scanf("%d%lld%d", &n, &p, &d);

	for(int i = 1; i <= n; i++){
		scanf("%d", &w[i]);
		acum[i] = acum[i-1] + w[i];
	}

	minqueue q;
	q.push(-acum[d]);
	int ans = 0;
	for(int l = 1, r = d; r <= n; l++){
		while(r+1 <= n and acum[r+1]-acum[l-1] - max(-q.mini(), acum[r+1]-acum[r+1-d]) <= p){
			r++;
			q.push(-(acum[r]-acum[r-d]));
		}
		// printf("l = %d, r = %d\n", l, r);
		// printf("soma do intervalo = %lld\n", acum[r]-acum[l-1]+q.mini());

		ans = max(ans, r-l+1);
		if(r-l+1 == d){
			r++;
			q.push(-(acum[r]-acum[r-d]));
		}
		q.pop();
	}

	printf("%d\n", ans);

	return 0;
}