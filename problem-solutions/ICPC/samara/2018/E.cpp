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

string s, t;

int main(void){
	fastcin;
	cin >> s >> t;

	if(s == t){
		cout << "YES" << endl;
		return 0;
	}

	int l = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] != t[i]){
			l = i;
			break;
		}
	}

	int r = int(s.size())-1;
	for(int i = r; i >= 0; i--){
		if(s[i] != t[i]){
			r = i;
			break;
		}
	}

	// cout << l << " " << r << endl;

	for(int i = 0; i < r-l+1; i++){
		if(s[l+i] != t[r-i]){
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;

	return 0;
}