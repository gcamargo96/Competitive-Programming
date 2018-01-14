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

	string s, t, u;
	vi pos[27];

	int main(void){
		ios_base::sync_with_stdio(false);
		cin >> s;

		For(i,0,s.size()){
			pos[s[i]-'a'].pb(i);
		}
		For(i,0,26){
			sort(pos[i].begin(), pos[i].end());
		}
		
		int cur = 0;
		For(i,0,26){
			For(j,0,pos[i].size()){
				if(pos[i][j] >= cur){
					int k = pos[i][j];
					while(t.size() > 0 and k >= cur and t[t.size()-1] < s[k]){
					    u += t[t.size()-1];
					    t.pop_back();
					    k--;
					}
					
					for(int k = cur; k <= pos[i][j]; k++){
						t += s[k];
					}
					
					//u += t[t.size()-1];
					//t.pop_back();
					cur = pos[i][j]+1;
				}
			}
		}
		
		for(int i = t.size()-1; i >= 0; i--){
			u += t[i];
		}
		
		cout << u << endl;

		return 0;
	}
