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

const int N = 200005;
int n, m, d;
ii v[N];
int coffee[N];

int main(void){
	scanf("%d%d%d", &n, &m, &d);

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i].fi);
		v[i].se = i;
	}

	sort(v, v+n);

	int ans = 0;
	priority_queue<ii, vector<pair<int, ii> >, greater<pair<int, ii> > > pq; 
	for(int i = 0; i < n; i++){
		if(!pq.empty() and v[i].fi - pq.top().fi > d){
			int day = pq.top().se.fi;
			int id = v[i].se;
			coffee[id] = day;
			pq.pop();
			pq.push(mp(v[i].fi, ii(day, v[i].se)));
		}
		else{
			int days = pq.size();
			int id = v[i].se;
			coffee[id] = days+1;
			pq.push(mp(v[i].fi, ii(days+1, id)));

		}
		ans = max(ans, int(pq.size()));
	}

	printf("%d\n", ans);

	for(int i = 0; i < n; i++){
		printf("%d ", coffee[i]);
	}
	printf("\n");

	return 0;
}