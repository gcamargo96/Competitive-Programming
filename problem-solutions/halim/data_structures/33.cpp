#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

const int N = 26;
int n, m;
string s;
bool awake[N];
vector<int> g[N];

void init(){
	For(i,0,N){
		g[i].clear();
		awake[i] = 0;
	}
}

bool finished(){
	int cnt = 0;
	
	For(i,0,N){
		if(awake[i] == 1) cnt++;
	}

	if(cnt == n) return 1;
	else return 0;
}

int main(void){
	ios_base::sync_with_stdio(false);

	while(cin >> n){
		init();
		cin >> m;
		cin >> s;

		For(i,0,s.size()){
			awake[s[i]-'A'] = 1;
		}

		For(i,0,m){
			cin >> s;
			g[s[0]-'A'].pb(s[1]-'A');
			g[s[1]-'A'].pb(s[0]-'A');
		}

		int res = 0;
		while(!finished()){
			vector<int> v;
			For(i,0,N){
				if(!awake[i]){
					int cnt = 0;
					For(j,0,g[i].size()){
						int v = g[i][j];
						if(awake[v]){
							cnt++;
						}
					}
					if(cnt >= 3){
						v.pb(i);
					}
				}
			}

			if(v.size() == 0){
				res = -1;
				break;
			}
			else{
				For(j,0,v.size()){
					awake[v[j]] = 1;
				}
			}
			res++;
		}

		if(res != -1){
			cout << "WAKE UP IN, " << res << ", YEARS" << endl;
		}
		else{
			cout << "THIS BRAIN NEVER WAKES UP" << endl;
		}
	}

	return 0;
}
