#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

ll n, x;
vector<ll> multiplos;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;

	x = 1;
	for(int i = 1; x < 100000000000000LL; i++){
		x *= 2;
		multiplos.pb(x);
	}

	auto it = lower_bound(multiplos.begin(), multiplos.end(), n);
	if(*it == n){
		cout << "TAK" << endl;
	}
	else cout << "NIE" << endl;

	return 0;
}
