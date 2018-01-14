#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

ll n, m;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;

	if(m >= n){
		cout << n << endl;
		return 0;
	}

	ll day = m;
	ll filled = n-m;

	//cout << "day = " << day << " filled = " << filled << endl;

	ll l = 1, r = 1000000000LL, ans;
	while(l < r){
		ll mid = (l+r)/2;
		ans = mid;
		ll sn = ((1+mid)*mid)/2;
	
		if(sn == filled) break;	
		if(sn < filled){
			l = mid+1;
		}
		else{
			r = mid;
		}
	}
	
	//cout << "ans = " << ans << endl;
	//ll sn = ((1+ans)*ans)/2;
	//cout << "sn = " << sn << endl;

	ll sn = ((1LL+ans)*ans)/2LL;
	if(sn < filled) ans++;	

	ans += day;
	cout << ans << endl;

	return 0;
}

