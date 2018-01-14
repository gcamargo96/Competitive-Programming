#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>

const int N = 100005;
ll n, k, res;
ll precisa[N];
ll tem[N];

bool possivel(ll cakes){
	ll po = k;
	for(int i = 0; i < n; i++){
		ll ing = cakes * precisa[i];
		if(ing > tem[i]) ing = ing - tem[i];
		else ing = 0;
		po -= ing;
		if(po < 0) return false;
	}
	return po >= 0;
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n >> k;

	for(int i = 0; i < n; i++){
		cin >> precisa[i];
	}
	for(int i = 0; i < n; i++){
		cin >> tem[i];
	}

	ll lo = 0, hi = 2000000005, mid;
	while(lo < hi){
		mid = (lo+hi)/2;
		
		if(possivel(mid)){
			lo = mid+1;
			res = mid;
		}
		else{
			hi = mid;
		}
	}

	cout << res << endl;

	return 0;
}
