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

const int N = 100002;
int n;
pair<int, ii> v[N];

int main(void){
	scanf("%d", &n);

	v[0].fi = 0;
	v[0].se.fi = 0;
	v[0].se.se = 0;

	for(int i = 1; i <= n; i++){
		scanf("%d%d%d", &v[i].fi, &v[i].se.fi, &v[i].se.se);
	}

	bool ans = 1;
	for(int i = 0; i < n; i++){
		int t = abs(v[i+1].fi - v[i].fi);
		int d = abs(v[i+1].se.fi - v[i].se.fi) + abs(v[i+1].se.se - v[i].se.se);

		if(!(t == d or (t > d and t%2 == d%2))){
			ans = 0;
			break;
		}
	}

	if(ans){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}

	return 0;
}