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

const int N = 52;
int n;
string s[N];
map<string,int> m[N];

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;

	For(i,0,n){
		cin >> s[i];
	}

	For(i,0,n){
		For(j,0,s[i].size()){
			string aux;
			//cout << s[i].size() << endl;
			For(k,0,s[i].size()){
				aux += s[i][(j+k)%s[i].size()];
			}
			//cout << aux << endl;
			if(!m[i].count(aux)) m[i][aux] = j;
		}
	}

	int ans = INF;
	//For(i,0,s[0].size()){
		for(auto it = m[0].begin(); it != m[0].end(); it++){
			string t = it->fi;
			int res = it->se;
			//cout << t << endl;
			for(int j = 1; j < n; j++){
				if(!m[j].count(t)){
					cout << -1 << endl;
					return 0;
				}
				res += m[j][t];
			}
			ans = min(ans, res);
		}
	//}

	cout << ans << endl;

	return 0;
}

