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

const int N = 50002;
int t, n;
vi adj[N];
int pops[N];

struct planet{
	int id, population;

	planet() {}

	planet(int _id, int _population){
		id = _id;
		population = _population;
	}

	bool operator<(const planet& b) const{
		return population < b.population;
	}
	
	bool operator==(const planet& b) const{
		return id == b.id and population == b.population;
	}
};

set<planet> p, aux;

void init(){
	p.clear();
	aux.clear();

	For(i,0,n){
		adj[i].clear();
	}
}

int main(void){
	scanf("%d", &t);

	while(t--){
		init();
		scanf("%d", &n);
		
		for(int i = 1; i <= n; i++){
			scanf("%d", &pops[i]);
			p.insert(planet(i, pops[i]));
		}

		int u, v;
		For(i,0,n-1){
			scanf("%d%d", &u, &v);
			adj[u].pb(v);
			adj[v].pb(u);
		}

		for(int u = 1; u <= n; u++){
			aux.insert(planet(u, pops[u]));
			p.erase(planet(u, pops[u]));

			For(j,0,adj[u].size()){
				v = adj[u][j];
				aux.insert(planet(v, pops[v]));
				p.erase(planet(v, pops[v]));
			}

			if(!p.empty()){
				auto it = p.end();
				it--;
				printf("%d ", it->id);
			}
			else{
				printf("0 ");
			}
			
			for(auto it = aux.begin(); it != aux.end(); it++){
				p.insert(planet(*it));
			}
			aux.clear();
		}
		printf("\n");
	}

	return 0;
}

