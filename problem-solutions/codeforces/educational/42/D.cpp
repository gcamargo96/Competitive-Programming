#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000000LL
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

const int N = 150002;
int n;
map<ll, set<ll> > m;

int main(void){
	scanf("%d", &n);

	ll x;
	for(int i = 0; i < n; i++){
		scanf("%lld", &x);
		m[x].insert(i);
	}

	for(auto it = m.begin(); it != m.end(); ++it){
		set<ll>& s = it->se;

		for(auto x = s.begin(); x != s.end(); ){
			auto y = x;
			++y;

			if(y != s.end()){
				m[2LL*(it->fi)].insert(*y);
				x = s.erase(x);
				x = s.erase(x);
			}
			else{
				++x;
			}
		}
	}

	set<pair<ll,ll> > ans;
	// reorganize
	for(auto it = m.begin(); it != m.end(); ++it){
		set<ll>& s = it->se;
		if(s.size() == 0)
			continue;


		ans.insert(mp(*s.begin(), it->fi));
	}

	printf("%d\n", int(ans.size()));
	for(auto it = ans.begin(); it != ans.end(); ++it){
		printf("%lld ", it->se);
	}
	printf("\n");

	return 0;
}