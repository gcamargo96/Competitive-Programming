#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

struct state{
	ll cost;
	int cnt1, cnt2;

	state(){
		cost = cnt1 = cnt2 = 0;
	}

	state(ll _cost, int _cnt1, int _cnt2){
		cost = _cost;
		cnt1 = _cnt1;
		cnt2 = _cnt2;
	}

	bool operator<(const state& b) const{
		if(cost == b.cost){
			return cnt2 > b.cnt2;
		}
		return cost < b.cost;
	}

	state operator+(const state& b) const{
		return state(cost+b.cost, cnt1+b.cnt1, cnt2+b.cnt2);
	}

	bool operator==(const state& b) const{
		return (cost == b.cost and cnt1 == b.cnt1 and cnt2 == b.cnt2);
	}
};

const int N = 300002;
int n, m;
vector<ll> v[4];
state dp[N];
ll maior[N];

int main(void){
	scanf("%d%d", &n, &m);

	int w;
   	ll c;
	For(i,0,n){
		scanf("%d%lld", &w, &c);
		v[w].pb(c);
	}

	sort(v[1].begin(), v[1].end(), greater<ll>());
	sort(v[2].begin(), v[2].end(), greater<ll>());
	sort(v[3].begin(), v[3].end(), greater<ll>());

	for(int i = 1; i <= m; i++){
		state a;
		if(dp[i-1].cnt1 < v[1].size()){
			a = (dp[i-1] + state(v[1][dp[i-1].cnt1], 1, 0));
		}

		state b;
		int cnt1 = dp[i-2].cnt1;
		int cnt2 = dp[i-2].cnt2;
		if(i >= 2){
			state b1, b2;
			if(cnt1 < (int)v[1].size()-1){
				//printf("entrou aqui\n");
				b1 = dp[i-2] + state(v[1][cnt1]+v[1][cnt1+1], 2, 0);
			}
			if(cnt2 < v[2].size()){
				b2 = dp[i-2] + state(v[2][cnt2], 0, 1);
			}
			b = max(b1, b2);
		}

		dp[i] = max(a, b);
	}

	for(int i = 1; i <= m; i++){
		maior[i] = max(maior[i-1], dp[i].cost);
	}

	ll res = dp[0].cost, sum = 0;
	for(int i = 0; i < v[3].size() and 3*(i+1) <= m; i++){
		res = max(res, sum + v[3][i] + maior[m-3*(i+1)]);
		sum += v[3][i];
	}

	For(i,0,m+1){
		res = max(res, dp[i].cost);
		//printf("dp[%d] = %lld, %lld, %lld\n", i, dp[i].cost, dp[i].cnt1, dp[i].cnt2);
	}
	//printf("\n");
	

	printf("%lld\n", res);

	return 0;
}

