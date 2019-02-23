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

ll n, k;

int main(void){
	fastcin;
	cin >> n >> k;

	ll l = 1, r = n;
	string res;
	while(l <= r){
		ll mid = (l+r)/2LL;
		cout << l << " " << mid << endl;
		cin >> res;

		if(res == "Bad")
			return 0;

		if(res == "Yes"){
			if(l == mid) return 0;
			r = mid;
		}
		else{ // res == "No"
			cout << max(l-k, 1LL) << " " << l << endl;
			cin >> res;

			if(res == "Bad")
				return 0;

			if(res == "Yes"){
				l = max(l-k, 1LL);
				r = l;
				if(l == r)
					return 0;
			}
			else{
				l = r;
				r = min(r+2*k, n);
			}
		}
	}

	return 0;
}