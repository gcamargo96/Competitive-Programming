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

const int N = 100002;
map<ll,int> cnt;
int n;

int main(void){
	ios_base::sync_with_stdio(false);

	cin >> n;

	ll x, res = 0;
	For(i,0,n){
		cin >> x;

		For(j,0,34){
			ll need = (1LL << j);
			need -= x;
			if(cnt.count(need)){
				res += cnt[need];
			}
		}

		cnt[x]++;
	}
	
	cout << res << endl;
	
	return 0;
}
