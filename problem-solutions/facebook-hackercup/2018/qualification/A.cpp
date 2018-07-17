#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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

const int N = 82;
int t;
ll n, k, v;
string s[N];

int main(void){
	fastcin;
	cin >> t;

	for(int caso = 1; caso <= t; caso++){
		cin >> n >> k >> v;

		for(int i = 0; i < n; i++){
			cin >> s[i];
		}

		ll id = ((v-1LL)*k)%n;

		vector<string> ans1, ans2;
		bool flag = 0;
		for(int i = id, cnt = 0; cnt < k; i++, cnt++){
			if(i%n == 0) flag = 1;

			if(flag){
				ans1.pb(s[i%n]);
			}
			else{
				ans2.pb(s[i%n]);
			}
		}

		vector<string> ans = ans1;
		for(int i = 0; i < ans2.size(); i++) ans.pb(ans2[i]);
		int len = ans.size();

		cout << "Case #" << caso << ": ";
		for(int i = 0; i < len; i++){
			cout << ans[i];
			if(i < len-1) cout << " ";
		}
		cout << endl;
	}

	return 0;
}