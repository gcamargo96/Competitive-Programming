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

ll n, h, a, b, k;

int main(void){
	fastcin;
	cin >> n >> h >> a >> b >> k;

	ll ta, fa, tb, fb;
	for(int i = 0; i < k; i++){
		cin >> ta >> fa >> tb >> fb;
	
		if(ta == tb){ // same tower
			cout << abs(fa-fb) << endl;
		}
		else{
			ll ans;
			ll bridge, dist1, dist2, dist3;
			if(fa >= a and fa <= b){ // the floor has a passage
				ans = abs(ta-tb) + abs(fa-fb);
			}
			else{
				if(abs(fa-a) < abs(fa-b)){
					bridge = a;
					dist1 = abs(fa-a);
				}
				else{
					bridge = b;
					dist1 = abs(fa-b);
				}

				dist2 = abs(ta-tb);
				dist3 = abs(bridge-fb);
				ans = dist1 + dist2 + dist3;
			}

			cout << ans << endl;
		}
	}

	return 0;
}