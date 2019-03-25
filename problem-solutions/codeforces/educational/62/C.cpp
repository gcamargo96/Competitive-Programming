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

#define INF 1000000000000000LL

struct song{
	ll len, b;
};

const int N = 300005;
int n, k;
song v[N];

bool cmp(song a, song b){
	if(a.b == b.b){
		return a.len > b.len;
	}
	return a.b > b.b;
}

int main(void){
	scanf("%d%d", &n, &k);

	for(int i = 0; i < n; i++){
		scanf("%lld%lld", &v[i].len, &v[i].b);
	}

	sort(v, v+n, cmp);

	priority_queue<ll, vector<ll>, greater<ll> > pq;

	ll total_len = 0, min_beaty = INF, ans = 0;
	for(int i = 0; i < n; i++){
		min_beaty = min(min_beaty, v[i].b);
		
		if(pq.size() < k){
			total_len += v[i].len;
			pq.push(v[i].len);
			ans = max(ans, total_len * min_beaty);
		}
		else{
			if(v[i].len > pq.top()){
				total_len -= pq.top();
				total_len += v[i].len;

				pq.pop();
				pq.push(v[i].len);
			
				ans = max(ans, total_len * min_beaty);
			}
		}
	}

	printf("%lld\n", ans);

	return 0;
}