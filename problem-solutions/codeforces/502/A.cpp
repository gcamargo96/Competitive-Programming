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

const int N = 1005;
int n;
vector<ii> v;

bool cmp(ii a, ii b){
	if(a.fi == b.fi){
		return a.se < b.se;
	}
	return a.fi > b.fi;
}

int main(void){
	cin >> n;

	int a, b, c, d;
	for(int i = 0; i < n; i++){
		cin >> a >> b >> c >> d;
		int sum = a+b+c+d;
		v.eb(sum, i);
	}

	sort(v.begin(), v.end(), cmp);

	for(int i = 0; i < n; i++){
		// cout << v[i].fi << " " << v[i].se << endl;
		if(v[i].se == 0){
			cout << (i+1) << endl;
			return 0;
		}
	}

	return 0;
}