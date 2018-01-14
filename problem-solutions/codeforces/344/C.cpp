#include <bits/stdc++.h>
using namespace std;

#define ll long long
//#define pb push_back
//#define mp make_pair

const int N = 200005;
int n;
vector <pair <ll,ll> > v;
//set <pair <ll,ll> > repet;
map <ll, ll> cntx;
map <ll, ll> cnty;
map <pair <ll, ll>, ll> repet;
ll res = 0;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;
	
	ll x, y;
	for(int i = 0; i < n; i++){
		cin >> x >> y;

		pair <ll, ll> par = make_pair(x,y);
		cntx[x]++;
		cnty[y]++;
		repet[par]++;
	}
	
	for(map<ll,ll>::iterator it = cntx.begin(); it != cntx.end(); it++){
		res += (it->second*(it->second-1))/2;
	}
	for(map<ll,ll>::iterator it = cnty.begin(); it != cnty.end(); it++){
		res += (it->second*(it->second-1))/2;
	}
	for(map<pair<ll,ll> ,ll>::iterator it = repet.begin(); it != repet.end(); it++){
		if(it->second > 1) res -= (it->second*(it->second-1))/2;
	}
	
	cout << res << endl;
	
	return 0;
}