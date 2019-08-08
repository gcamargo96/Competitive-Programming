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

const int N = 505;
// bool vis[N][N][N];
string s[N];
bool alive[N];
int aliveCount;
int n, tests;

char beat(char play){
	if(play == 'R') return 'P';
	if(play == 'P') return 'S';
	if(play == 'S') return 'R';
}

void kill_players(int turn, char play){
	for(int i = 0; i < n; i++){
		if(!alive[i]) continue;
		int t = turn%s[i].size();

		if(play == beat(s[i][t])){
			alive[i] = 0;
			aliveCount--;
		}
	}
}

int main(void){
	fastcin;
	cin >> tests;

	for(int caso = 1; caso <= tests; caso++){
		cin >> n;

		memset(alive, 1, sizeof alive);
		// memset(vis, 0, sizeof vis);

		for(int i = 0; i < n; i++){
			cin >> s[i];
		}

		bool ok = 1;
		string ans;
		aliveCount = n;

		for(int turn = 0; ok ; turn++){ // para cada turno
			set<char> plays;
			
			for(int i = 0; i < n; i++){ // para cada player vivo
				if(!alive[i]) continue;

				int relativeTurn = turn%s[i].size();

				// if(vis[i][aliveCount][relativeTurn]){
				// 	ok = 0;
				// 	break;
				// }

				plays.insert(s[i][relativeTurn]);
			}
			// if(ok == 0) break;

			if(plays.size() == 3){
				ok = 0;
			}
			else if(plays.size() == 1){
				char p = *(plays.begin());
				ans += beat(p);
				break;
			}
			else{ // plays.size() == 2
				char p1 = *(plays.begin());
				plays.erase(p1);
				char p2 = *(plays.begin());

				char play;
				if(beat(p1) == p2){
					play = p2;
				}
				else{
					play = p1;
				}
				ans += play;

				kill_players(turn, play);
			}

			// if(!check(turn)){
			// 	ok = 0;
			// }
		}

		if(ok){
			cout << "Case #" << caso << ": " << ans << endl;
		}
		else{
			cout << "Case #" << caso << ": " << "IMPOSSIBLE" << endl;
		}
	}

	return 0;
}