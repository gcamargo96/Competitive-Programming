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

struct node{
	ll next, charge, usage;

	node() {}

	node(ll last, ll next, ll charge, ll usage){
		this->next = next;
		this->charge = charge;
		this->usage = usage;
	}

	void print(){
		printf("next = %lld, charge = %lld, usage = %lld\n", next, charge, usage);
	}

	bool operator<(const node& b) const{
		return next > b.next;
	}
};

const ll INF = 10000000000000LL;
const int N = 200005;
int n, k;
node v[N];

bool check(ll x){
	// printf("\n\n\nx = %lld\n", x);
	priority_queue<node> pq;
	for(int i = 0; i < n; i++){
		pq.push(v[i]);
	}

	for(int i = 0; i < k; i++){
		node cur = pq.top();
		pq.pop();


		if(cur.next < i) return 0;
		if(cur.next >= k) return 1;

		cur.charge += x;
		cur.next = cur.charge/cur.usage;

		pq.push(cur);
	}

	return 1;
}

int main(void){
	scanf("%d%d", &n, &k);

	for(int i = 0; i < n; i++){
		scanf("%lld", &v[i].charge);
	}

	for(int i = 0; i < n; i++){
		scanf("%lld", &v[i].usage);
		v[i].next = v[i].charge/v[i].usage;
	}

	ll l = 0, r = INF, ans = -1;
	while(l <= r){
		ll mid = (l+r)/2LL;
		if(check(mid)){
			ans = mid;
			r = mid-1;
		}
		else{
			l = mid+1;
		}
	}

	printf("%lld\n", ans);

	return 0;
}