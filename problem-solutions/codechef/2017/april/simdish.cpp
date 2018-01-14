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
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int t;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> t;

	while(t--){
		vector<string> v1, v2;
		string s;
		
		For(i,0,4){
			cin >> s;
			v1.pb(s);
		}
		For(i,0,4){
			cin >> s;
			v2.pb(s);
		}

		int cnt = 0;
		For(i,0,4){
			For(j,0,4){
				if(v1[i] == v2[j]) cnt++;
			}
		}

		if(cnt >= 2) cout << "similar" << endl;
		else cout << "dissimilar" << endl;
	}

	return 0;
}
