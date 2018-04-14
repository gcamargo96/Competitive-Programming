#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

struct contest{
	int id, a, b, c;

	bool operator<(const contest& x) const{
		if(a == x.a)
			return b < x.b;
		return a < x.a;
	}
};

const int N = 200002;
int n;
contest v[N];
pair<ll,ll> dp1[N];
int choice[N];

bool cmp(contest a, contest b){
	return a.b <= b.a;
}

pair<ll,ll> solve1(int i){
	if(i == n)
		return mp(0LL, 0LL);

	if(dp1[i] != mp(-1LL,-1LL))
		return dp1[i];

	int nxt = upper_bound(v, v+n, v[i], cmp) - v;
	// printf("nxt[%d] = %d\n", i, nxt);
	pair<ll,ll> A = solve1(nxt);
	A.fi += v[i].c, A.se += v[i].b-v[i].a;
	pair<ll,ll> B = solve1(i+1);

	pair<ll,ll> best;
	if(A.fi == B.fi){
		if(A.se < B.se){
			choice[i] = 1;
			best = A;
		}
		else{
			choice[i] = 2;
			best = B;
		}
	}
	else if(A.fi > B.fi){
		choice[i] = 1;
		best = A;
	}
	else{
		choice[i] = 2;
		best = B;
	}

	// printf("%d: (%lld,%lld), (%lld,%lld)\n", i, A.fi, A.se, B.fi, B.se);
	return dp1[i] = best;
}

vi path;
void get_path(int i){
	if(i == n)
		return;

	if(choice[i] == 1){
		path.pb(v[i].id);
		int nxt = upper_bound(v, v+n, v[i], cmp) - v;
		get_path(nxt);
	}
	else{
		get_path(i+1);
	}
}

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d%d%d", &v[i].a, &v[i].b, &v[i].c);
		v[i].id = i+1;
	}

	sort(v, v+n);

	for(int i = 0; i < N; i++){
		dp1[i].fi = -1;
		dp1[i].se = -1;
	}
	pair<ll,ll> ans = solve1(0);
	get_path(0);

	printf("%d %lld %lld\n", int(path.size()), ans.fi, ans.se);
	for(int i = 0; i < path.size(); i++){
		printf("%d ", path[i]);
	}
	printf("\n");

	return 0;
}