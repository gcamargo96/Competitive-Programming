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

const int N = 102;

struct Score{
	int id, solved, penalty;
	int time[10];
	bool probs[10];
	bool submitted;

	bool operator<(const Score& b) const{
		if(solved == b.solved and penalty == b.penalty) return id < b.id;
		if(solved == b.solved) return penalty < b.penalty;
		return solved > b.solved;
	}
};

Score score[N];
int n;

void init(){
	For(i,0,N){
		score[i].id = i;
		score[i].solved = 0;
		score[i].penalty = 0;
		score[i].submitted = 0;
		For(j,0,10){
			score[i].time[j] = 0;
			score[i].probs[j] = 0;
		}
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;
	cin.get();
	cin.get();

	int c, p, t;
	char L;

	string s;
	stringstream ss;
	For(i,0,n){
		init();
		if(i > 0) cout << endl;
		
		while(getline(cin, s) and s.size() > 0){
			ss << s;
			ss >> c >> p >> t >> L;
			if(L == 'C' and score[c].probs[p] == 0){
				/*if(c == 68){
					cout << "AQUI: " << "p = " << p << "t = " << t << "L = " << L << endl;
				}*/
				score[c].solved++;
				score[c].penalty += t + score[c].time[p];
				score[c].time[p] = 0;
				score[c].probs[p] = 1;
			}
			else if(L == 'I'){
				score[c].time[p] += 20;
			}
			score[c].submitted = 1;
		}
		sort(score, score+N);

		For(i,0,N){
			if(score[i].submitted){
				//printf("%d %d %d\n", score[i].id, score[i].solved, score[i].penalty);
				cout << score[i].id << " " << score[i].solved << " " << score[i].penalty << endl;
			}
		}
	}

	return 0;
}
