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
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

struct stuff{
	int t, d, p, id;

	stuff() {}

	stuff(int _t, int _d, int _p, int _id){
		t = _t;
		d = _d;
		p = _p;
		id = _id;
	}

	bool operator<(const stuff& b) const{
		return d < b.d;
	}
};

int n;
int dp[102][2002], choose[102][2002];
vector<stuff> v;
vector<int> ans;

int solve(int i, int tempo){
	if(i == v.size()){
		return 0;
	}
	if(dp[i][tempo] != -1) return dp[i][tempo];

	int a, b = 0;
	a = solve(i+1, tempo);
	if(tempo + v[i].t < v[i].d){
		b = solve(i+1, tempo + v[i].t) + v[i].p;
	}

	if(a < b){
		choose[i][tempo] = 1;
	}

	return dp[i][tempo] = max(a, b);
}

void get_path(int i, int tempo){
	if(i == v.size()) return;

	if(choose[i][tempo] == 0){
		get_path(i+1, tempo);
	}
	else{
		ans.pb(v[i].id);
		get_path(i+1, tempo + v[i].t);
	}
}

int main(void){
	scanf("%d", &n);

	int t, d, p;
	for(int i = 0; i < n; i++){
		scanf("%d%d%d", &t, &d, &p);
		if(d-t > 0){
			v.pb(stuff(t,d,p,i+1));
		}
	}

	sort(v.begin(), v.end());

	memset(dp, -1, sizeof dp);
	int tot = solve(0, 0);
	get_path(0, 0);

	printf("%d\n", tot);
	printf("%d\n", (int)ans.size());
	// sort(ans.begin(), ans.end());
	for(int i = 0; i < ans.size(); i++){
		printf("%d ", ans[i]);
	}
	printf("\n");

	return 0;
}