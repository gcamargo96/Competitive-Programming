#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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

struct participant{
	int id, bid;

	participant() {}

	participant(int _id, int _bid){
		id = _id;
		bid = _bid;
	}

	bool operator<(const participant& b) const{
		return bid < b.bid;
	}
};

const int N = 200002;
int n, q;
set<participant> best, aux;
vector<int> bids[N];

int main(void){
	scanf("%d", &n);

	int a, b;
	For(i,0,n){
		scanf("%d%d", &a, &b);
		bids[a].pb(b);
	}

	for(int i = 1; i < N; i++){
		sort(bids[i].begin(), bids[i].end());
		if(bids[i].size() > 0){
			best.insert(participant(i, bids[i][bids[i].size()-1]));
		}
	}

	scanf("%d", &q);

	For(i,0,q){
		scanf("%d", &n);
		
		For(j,0,n){
			scanf("%d", &a);
			if(bids[a].size() > 0){ // se a fez alguma aposta
				participant p = participant(a, bids[a][bids[a].size()-1]);
				aux.insert(p);
				best.erase(p);
			}
		}

		if(best.size() == 0){
			printf("0 0\n");
		}
		else if(best.size() == 1){
			int id = (best.begin())->id;
			printf("%d %d\n", id, bids[id][0]);
		}
		else{
			auto it = best.end();
			it--;
			int ultimo = it->id;
			it--;
			int penultimo = it->id;
			int low = bids[penultimo][bids[penultimo].size()-1];
			auto up = upper_bound(bids[ultimo].begin(), bids[ultimo].end(), low);
			int quanto = *up;
			printf("%d %d\n", ultimo, quanto);
		}

		for(auto it = aux.begin(); it != aux.end(); it++){
			best.insert(participant(it->id, it->bid));
		}

		aux.clear();
	}

	return 0;
}

