#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

const int N = 100002;
ll sz, p;
vector<ll> sqr;

void init(){
	for(ll i = 1; i < N; i+=2){
		sqr.pb(i*i);
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	init();

	while(cin >> sz >> p, sz != 0 and p != 0){
		auto it = upper_bound(sqr.begin(), sqr.end(), p);
		ll nxt = *it, tam = sqrt(*it);
		it--;
		ll ant = *it, relativo = it-sqr.begin();
		ll lin = sz/2+1 +relativo;
		ll col = lin;

		//cout << lin << " " << col << endl;
		//cout << "ant = " << ant << " tam = " << tam << endl;
		
		//cout << "relativo = " << relativo << endl;
		//cout << "lin = " << lin << endl;
		//cout << "ant = " << ant << endl;
		//cout << "tam = " << tam << endl;

		if(ant + tam-1 < p){
			ant += tam-1;
			lin++;
			//col = 1;
			col -= tam-2;
		}
		else if(ant < p){
			lin++;
			//col = tam-(p-ant);
			col = col-(p-ant) + 1;
			ant = p;
		}

		if(ant + tam-1 < p){
			ant += tam-1;
			lin -= tam-1;
			//col = 1;
		}
		else if(ant < p){
			lin -= (p-ant);
			ant = p;
		}

		if(ant + tam-1 < p){
			ant += tam-1;
			col += tam-1;
		}
		else if(ant < p){
			col += p-ant;
			ant = p;
		}

		if(ant < p){
			//col = p-ant+1;
			lin += p-ant;
			ant = p;
		}

		cout << "Line = " << lin << ", column = " << col << "." << endl;
	}

	return 0;
}
