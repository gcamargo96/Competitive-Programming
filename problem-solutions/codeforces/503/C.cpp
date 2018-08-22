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
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

#define INF 1000000000000000000LL;

const int N = 3005;
int n, m;
vi votes[N];

ll calc(int lim){
	int cnt = votes[1].size();
	ll ret = 0;
	priority_queue<int, vi, greater<int> > pq;

	for(int i = 2; i <= m; i++){
		for(int j = 0; j < int(votes[i].size())-lim; j++){
			cnt++;
			ret += votes[i][j];
		}

		for(int j = max(0, int(votes[i].size())-lim); j < votes[i].size(); j++){
			pq.push(votes[i][j]);
		}
	}

	while(cnt <= lim){
		ret += pq.top();
		cnt++;
		pq.pop();
	}

	return ret;
}

int main(void){
	scanf("%d%d", &n, &m);

	int p, c;
	for(int i = 0; i < n; i++){
		scanf("%d%d", &p, &c);
		votes[p].pb(c);
	}

	for(int i = 1; i <= m; i++){
		sort(votes[i].begin(), votes[i].end());
	}

	ll ans = INF;
	for(int i = 0; i < n; i++){
		ans = min(ans, calc(i));
	}

	printf("%lld\n", ans);

	return 0;
}