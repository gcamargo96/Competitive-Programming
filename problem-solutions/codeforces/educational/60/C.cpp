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

const int N = 100005;
unordered_map<char, int> d;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
ll ax[N], ay[N];
ll X1, Y1, X2, Y2, X3, Y3;
ll n;
string s;

ll dist(ll xa, ll ya, ll xb, ll yb){
	return abs(xa-xb) + abs(ya-yb);
}

bool check(ll k){
	ll ciclos = k/n;
	ll resto = k%n;

	ll X3 = X1 + ciclos*ax[n] + ax[resto];
	ll Y3 = Y1 + ciclos*ay[n] + ay[resto];

	// printf("mid = %lld x3 = %lld, y3 = %lld\n", k, X3, Y3);

	if(dist(X2, Y2, X3, Y3) <= k) return 1;
	return 0;
}

int main(void){
	fastcin;

	d['U'] = 0;
	d['D'] = 1;
	d['L'] = 2;
	d['R'] = 3;

	cin >> X1 >> Y1;
	cin >> X2 >> Y2;
	cin >> n;
	cin >> s;

	for(int i = 1; i <= n; i++){
		ax[i] = ax[i-1] + dx[d[s[i-1]]];
		ay[i] = ay[i-1] + dy[d[s[i-1]]];
	}

	// for(int i = 1; i <= n; i++){
	// 	printf("%lld ", ax[i]);
	// }
	// printf("\n");

	// for(int i = 1; i <= n; i++){
	// 	printf("%lld ", ay[i]);
	// }
	// printf("\n");

	ll l = 0, r = 1000000000000000LL, ans = -1;
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