#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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

const int N = 100002;
int n, k, m;
map<string, int> group;
int cost[N], mincost[N];
string s[N];

int main(void){
	fastcin;
	cin >> n >> k >> m;

	for(int i = 1; i <= n; i++){
		cin >> s[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> cost[i];
	}

	memset(mincost, INF, sizeof mincost);

	int x, id;
	for(int i = 1; i <= k; i++){
		cin >> x;
		for(int j = 0; j < x; j++){
			cin >> id;
			group[s[id]] = i;
			mincost[i] = min(mincost[i], cost[id]);
		}
		// cout << "m " << i << " = " << mincost[i] << endl;
	}

	string t;
	ll ans = 0;
	for(int i = 0; i < m; i++){
		cin >> t;
		// cout << "t = " << t << " ";
		// cout << "g = " << group[t] << endl;
		ans += mincost[group[t]];
	}

	cout << ans << endl;

	return 0;
}