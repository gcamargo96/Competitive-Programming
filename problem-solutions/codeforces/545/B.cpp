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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int C, A, C1, A1, C2, A2, ambos, nenhum;
int n;
string s, t;
bool vis[5005];

int main(void){
	fastcin;
	cin >> n >> s >> t;

	for(int i = 0; i < n; i++){
		if(s[i] == '0' and t[i] == '0'){
			nenhum++;
		}
		else if(s[i] == '1' and t[i] == '1'){
			ambos++;
		}
		else if(s[i] == '0' and t[i] == '1'){
			A++;
		}
		else{
			C++;
		}
	}

	for(int c1 = 0; c1 <= C; c1++){
		for(int a1 = 0; a1 <= A; a1++){
			int c2 = C - c1;
			int a2 = A - a1;

			// cout << a1 << " " << c1 << " " << a2 << " " << c2 << endl;

			if(c1 + a1 <= n/2 and c2 + a2 <= n/2 and abs(c1-a2)%2 == ambos%2){
				vi ans;
				int points = (c1 + a2 + ambos)/2;
				int both = points - c1;
				int none = n/2 - c1 - a1 - both;

				for(int i = 0; i < n; i++){
					if(s[i] == '1' and t[i] == '0' and c1 > 0){
						ans.pb(i+1);
						c1--;
						vis[i] = 1;
					}
					else if(s[i] == '0' and t[i] == '1' and a1 > 0){
						ans.pb(i+1);
						a1--;
						vis[i] = 1;
					}
					else if(s[i] == '1' and t[i] == '1' and both > 0){
						ans.pb(i+1);
						both--;
						vis[i] = 1;
					}
					else if(s[i] == '0' and t[i] == '0' and none > 0){
						ans.pb(i+1);
						none--;
						vis[i] = 1;
					}
				}

				for(int i = 0; i < n and ans.size() < n/2; i++){
					if(!vis[i] and s[i] == '0'){
						ans.pb(i+1);
					}
				}

				for(int i = 0; i < ans.size(); i++){
					cout << ans[i] << " ";
				}
				cout << endl;

				return 0;
			}
		}
	}

	// if(C== 0 and A == 0 and ambos%2 == 0){
	// 	int cnt1 = ambos/2;
	// 	int cnt2 = n/2 - cnt1;

	// 	vi ans;
	// 	for(int i = 0; i < n; i++){
	// 		if(s[i] == '1' and t[i] == '1' and cnt1 > 0){
	// 			ans.pb(i+1);
	// 			cnt1--;
	// 		}
	// 		else if(s[i] == '0' and t[i] == '0' and cnt2 > 0){
	// 			ans.pb(i+1);
	// 			cnt2--;
	// 		}
	// 	}

	// 	for(int i = 0; i < ans.size(); i++){
	// 		cout << ans[i] << " ";
	// 	}
	// 	cout << endl;

	// 	return 0;
	// }

	cout << -1 << endl;

	return 0;
}