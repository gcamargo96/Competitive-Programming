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

int n;
string s;

int main(void){
	fastcin;
	cin >> s;
	n = s.size();

	string ans;
	int mid = n/2;;

	if(n%2 == 0){
		mid--;
	}

	ans += s[mid];
	int l = mid-1, r = mid+1;
	
	while(l >= 0 and r < n){
		ans += s[r];
		ans += s[l];
		l--;
		r++;
	}
	if(r < n){
		ans += s[r];
	}

	cout << ans << endl;

	return 0;
}