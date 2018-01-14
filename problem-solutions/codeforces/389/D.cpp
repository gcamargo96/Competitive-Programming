#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000000
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

#define NENHUM 0
#define MEIO 1

const int N = 100002;
int k, n, b;
string s;
map<string, vector<int>> words;
ll dp[N][2];
vector<pair<ll,ll>> par;

bool cmp(int a, int b){
	return a > b;
}

ll solve(int i, bool foi){
	if(i == par.size()) return 0;
	if(dp[i][foi] > -INF) return dp[i][foi];

	ll ret1 = -INF;
	if(!foi){
		ret1 = par[i].fi + solve(i+1, 1);
	}
	ll ret2 = par[i].fi + par[i].se + solve(i+1, foi);
	ll ret3 = solve(i+1, foi);

	return dp[i][foi] = max(ret1, max(ret2, ret3));
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> k >> n;

	For(i,0,k){
		cin >> s >> b;
		words[s].pb(b);
	}

	for(auto it = words.begin(); it != words.end(); it++){
		vector<int>& v = it->se;
		sort(v.begin(), v.end(), cmp);
	}

	ll res = 0;
	for(auto it = words.begin(); it != words.end(); it++){
		vector<int>& v = it->se;
		string s = it->fi;
		string t;
		For(i,0,n){
			t += s[n-i-1];
		}

		if(s != t and words.count(t)){
			vector<int>& v2 = words[t];
			For(i,0,min(v.size(), v2.size())){
				if(v[i] + v2[i] > 0){
					res += v[i] + v2[i];
					//cout << s << " " << t << endl;
				}
			}
		}
	}

	res /= 2;

	for(auto it = words.begin(); it != words.end(); it++){
		string s = it->fi;
		string t;
		For(i,0,n){
			t += s[n-i-1];
		}
		if(s == t){
			vector<int>& v = it->se;
			for(int i = 0; i < v.size(); i += 2){
				if(i < v.size()-1){
					if(v[i] > 0 and v[i+1] > 0){
						res += v[i] + v[i+1];
					}
					else if(v[i] > 0){
						par.pb(mp(v[i], v[i+1]));
					}
				}
				else if(v[i] > 0){
					par.pb(mp(v[i], -INF));
				}
			}
		}
	}

	For(i,0,N){
		For(j,0,2){
			dp[i][j] = -INF;
		}
	}

	res += solve(0,0);

	cout << res << endl;

	return 0;
}

