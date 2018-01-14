#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

const ll MAX = 30000000000;
set<ll> cities, towers;
int n, m;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;

	ll x;
	For(i,0,n){
		cin >> x;
		cities.insert(x);
	}

	For(i,0,m){
		cin >> x;
		towers.insert(x);
	}

	ll res = 0;
	for(auto it = cities.begin(); it != cities.end(); it++){
		auto lb = towers.lower_bound(*it);
		ll mindist = MAX;
		if(lb != towers.end()){
			mindist = *lb - *it;
		}
		if(lb != towers.begin()){
			lb--;
			mindist = min(mindist, *it-*lb);
		}

		res = max(res, mindist);
	}
	
	cout << res << endl;

	return 0;
}
