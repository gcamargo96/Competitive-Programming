#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int n, k;
string s, t;
vector<char> v;

int main(void){
	fastcin;
	cin >> n >> k >> s;


	for(int i = 0; i < s.size(); i++){
		v.pb(s[i]);
	}

	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	int sz = v.size();

	int pos = 0;
	string ans;
	if(n < k){
		cout << s;
		for(int i = s.size(); i < k; i++){
			cout << v[0];
		}
		cout << endl;
	}
	else{ // n >= k
		bool flag = 0;
		for(int i = k-1; i >= 0; i--){
			if(!flag){
				if(s[i] < v[sz-1]){
					auto it = upper_bound(v.begin(), v.end(), s[i]);
					// cout << *it;
					ans += *it;
					pos = i;
					flag = 1;
				}
				else{
					// cout << s[i];
					ans += v[0];
				}
			}
			else{
				// cout << v[0];
				ans += s[i];
			}
		}

		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}

	return 0;
}