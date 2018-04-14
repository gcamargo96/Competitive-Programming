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

int t, n;
ll d;
string s;

ll calc_dmg(){
	ll dmg = 0, beam = 1;
	
	for(int i = 0; i < n; i++){
		if(s[i] == 'S'){
			dmg += beam;
		}
		else{
			beam *= 2LL;
		}
	}

	return dmg;
}

int main(void){
	fastcin;
	cin >> t;

	for(int c = 1; c <= t; c++){
		cin >> d >> s;
		n = s.size();

		int ans = 0;
		ll dmg = calc_dmg();
		bool ok = 1;

		while(dmg > d){
			ll last = dmg;
			for(int i = n-1; i > 0; i--){
				if(s[i] == 'S' and s[i-1] == 'C'){
					swap(s[i-1], s[i]);
					break;
				}
			}

			dmg = calc_dmg();
			
			if(dmg == last){
				ok = 0;
				break;
			}

			ans++;
		}

		if(ok){
			cout << "Case #" << c << ": " << ans << endl;
		}
		else{
			cout << "Case #" << c << ": IMPOSSIBLE" << endl;
		}
	}

	return 0;
}