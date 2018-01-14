#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
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

int t, n;

int main(void){
	fastcin;
	cin >> t;

	while(t--){
		map<string, int> cnt;
		cin >> n;

		if(n == 0){
			cout << "Draw" << endl;
			continue;
		}
		
		string s;
		for(int i = 0; i < n; i++){
			cin >> s;
			cnt[s]++;
		}

		bool draw = 0;
		int last = -1, best = -1;
		string ans;
		for(auto team : cnt){
			if(team.se > best){
				draw = 0;
				best = team.se;
				ans = team.fi;
			}
			else if(team.se == best){
				draw = 1;
			}
		}

		if(draw){
			cout << "Draw" << endl;
		}
		else{
			cout << ans << endl;
		}
	}

	return 0;
}