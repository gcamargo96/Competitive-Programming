#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int n, m;
string s, t;

int main(void){
	cin >> n >> m;
	cin >> s >> t;

	vi ans;
	int mn = INT_MAX;
	for(int i = 0; i <= m-n; i++){
		vi v;
		for(int j = 0; j < n; j++){
			if(s[j] != t[i+j]){
				v.pb(j+1);
			}
		}

		if(v.size() < mn){
			mn = v.size();
			ans = v;
		}
	}

	cout << mn << endl;
	for(int i = 0; i < mn; i++){
		cout << ans[i] << " ";
	}
	cout << endl;

	return 0;
}