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

int d, h;
map<vi, ll> pd;
set<vi> bases;
vi b;

void gerar_bases(int pos, int falta){
	if(pos == d){
		if(falta == 0)
			bases.insert(b);
		return;
	}
	if(falta == 0) return;
	
	for(int i = b[pos-1]; i <= falta; i++){
		b.pb(i);
		gerar_bases(pos+1, falta-i);
		b.pop_back();
	}
}

ll solve(vi& estado){
	bool zero = 1;
	For(i,0,estado.size()){
		if(estado[i] != 0) zero = 0;
	}
	if(zero) return 1;

	For(i,0,estado.size()){
		if(estado[i] == -1) return 0;
	}
	
	if(pd.count(estado)) return pd[estado];

	ll sum = 0;
	For(i,0,estado.size()){
		vi aux = estado;
		aux[i] -= 1;
		sort(aux.begin(), aux.end());
		sum += solve(aux);
	}

	return pd[estado] = sum;
}

int main(void){
	scanf("%d%d", &d, &h);

	vi estado;
	for(int i = 0; i <= h-1; i++){
		b.pb(i);
		gerar_bases(1, h-1-i);
		b.pop_back();
	}

	/*printf("%d\n", bases.size());
	for(auto it : bases){
		For(j,0,it.size()){
			printf("%d ", it[j]);
		}
		printf("\n");
	}
	printf("\n");
	*/

	set<ll> res;
	for(auto v : bases){
		estado = v;
		res.insert(solve(estado));
	}

	for(ll x : res){
		printf("%lld\n", x);
	}

	return 0;
}

