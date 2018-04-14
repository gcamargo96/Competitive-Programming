#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
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

int n;
string s;
vi adj[28];

int main(void){
	fastcin;
	cin >> n >> s;

	for(int i = 0; i < s.size(); i++){
		adj[s[i]-'a'].pb(i);
	}

	int dif = 0;
	for(int i = 0; i < 26; i++){
		if(adj[i].size() > 0){
			dif++;
		}
	}

	if(dif == 1){
		cout << 0 << endl;
		return 0;
	}

	int ans = 0;
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < 26; j++){
			if(i != j and adj[i].size() > 0 and adj[j].size() > 0){
				int a = 0, b = 0;
				vi v;
				while(a < adj[i].size() or b < adj[j].size()){
					if(a == adj[i].size()){
						v.pb(-1);
						b++;
					}
					else if(b == adj[j].size()){
						v.pb(1);
						a++;
					}
					else if(adj[i][a] < adj[j][b]){
						v.pb(1);
						a++;
					}
					else{
						v.pb(-1);
						b++;
					}
				}

				// cout << "v.size() = " << v.size() << endl;

				int cnta = 0, cntb = 0;
				for(int k = 0; k < v.size(); k++){
					// cout << v[k] << " ";
					if(v[k] == 1){
						cnta++;
					}
					else{
						cntb++;
					}

					if(cnta - cntb < 0){
						cnta = 0;
						cntb = 0;
					}

					// cout << cnta << " " << cntb << endl;

					if(cntb > 0)
						ans = max(ans, cnta-cntb);
					else
						ans = max(ans, cnta-cntb-1);
				}
				// cout << endl;
			}
		}
	}

	cout << ans << endl;

	return 0;
}