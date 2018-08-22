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

int h, m;
char c;

bool test(int h, int m){
	vi v;
	v.pb(h/10);
	v.pb(h%10);
	v.pb(m/10);
	v.pb(m%10);

	if(v[0] == v[3] and v[1] == v[2]) return 1;
	return 0;
}

int main(void){
	cin >> h >> c >> m;

	int ans = 0;
	while(!test(h, m)){
		m++;

		if(m == 60){
			h++;
			m = 0;
		}

		if(h == 24){
			h = 0;
		}

		ans++;
	}

	cout << ans << endl;

	return 0;
}