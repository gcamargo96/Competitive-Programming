#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
//#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

int n, q;
int a, b;
int x;
vector<int> road;

int main(void){
	freopen("haybales.in", "r", stdin);
	freopen("haybales.out", "w", stdout);
	scanf("%d%d", &n, &q);

	road.pb(-1);
	road.pb(1000000002);
	For(i,0,n){
		scanf("%d", &x);
		road.pb(x);
	}

	sort(road.begin(), road.end());

	For(i,0,q){
		scanf("%d%d", &a, &b);
		auto r = upper_bound(road.begin(), road.end(), b);
		auto l = lower_bound(road.begin(), road.end(), a);
		int res = r-l;
		printf("%d\n", res);
	}

	return 0;
}

