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

string a, b;
int n;
ll cnt00, cnt1x, cnt01, cnt10;
ll ans = 0;

int main(void){
	fastcin;
	cin >> n;
	cin >> a >> b;

	for(int i = 0; i < n; i++){
		if(a[i] == '1'){
			cnt1x++;
		}
		if(a[i] == '0' and b[i] == '0'){
			cnt00++;
		}
		if(a[i] == '0' and b[i] == '1'){
			cnt01++;
		}
		if(a[i] == '1' and b[i] == '0'){
			cnt10++;
		}
	}

	ans = cnt00*cnt1x + cnt01*cnt10;

	cout << ans << endl;

	return 0;
}