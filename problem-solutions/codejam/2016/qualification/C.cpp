#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int N = 1000005;
int T, n, J;
int numeros[N];
set <ll> primos;

void crivo(){
	for(ll i = 2; i < N; i++){
		if(numeros[i] == 0){
			numeros[i] = 1;
			primos.insert(i);
			for(ll j = i+i; j < N; j += i){
				numeros[j] = i;
			}
		}	
	}
}

ll exp(int b, int e){
	if(e == 1) return b;
	if(e == 0) return 1;

	if(e%2 == 0){
		return exp(b, e/2) * exp(b, e/2);
	}
	else{
		return b*exp(b, e/2)*exp(b,e/2);
	}
}

ll exp2(ll b, ll e){
	if(e == 0) return 1;

	ll res = 1;
	for(int i = 0; i < e; i++){
		res *= b;
	}
	return res;
}

void flip(string &s){
	for(int i = 0, j = s.size()-1; i < j; i++, j--){
		swap(s[i], s[j]);
	}
}

void solve(){
	int cntres = 0;
	//cout << "imprimiu aqui" << endl;
	for(ll bitmask = (1LL << (n-1)); bitmask < (1LL << n); bitmask++){
		//cout << "entrou aqui\n";
		int flag = 0, notprimos = 0;
		vector <int> divisores;
		if((bitmask & 1) == 1){
			cout << "===============================\n";
			for(int i = 2; i <= 10; i++){
				ll aux = bitmask;
				ll ibased = 0;
				//cout << "base " << i << ": ";
				ll j = 0;
				string novo;
				while(aux != 0){
					int digit = aux%i;
					//cout << digit << endl;
					//ibased = ibased + (digit * exp2(10LL,j));
					novo += digit+'0';
					aux /= i;
					j++;
				}
				flip(novo);
				//cout <<"novo = " << novo << endl;
				ibased = stoi(novo);
				cout << ibased << endl;
				if(numeros[ibased] != 1){
					cout << "base nao prima " <<ibased << endl;
					divisores.pb(numeros[ibased]);
					notprimos++;
				}
			}
			//cout << "=================\n";
			if(notprimos == 9){
				cout << "deu bom" << endl;
				vector <int> bitres;
				ll aux = bitmask;
				for(int i = 0; i < n; i++){
					int digit = aux%2;
					bitres.pb(digit);
					aux /= 2;
				}
				for(int i = n-1; i >= 0; i--){
					cout << bitres[i];
				}
				cout << " ";
				for(int i = 0; i < 9; i++){
					cout << divisores[i] << " ";
				}
				cout << '\n';
				cntres++;
				cout << "contou" << endl;
			}
		}
		if(cntres == J){
			break;
		}
		//cout << "i" << endl;
	}	
}	

int main(void){
	int t;
	ios_base::sync_with_stdio(false);
	crivo();
	cin >> t;

	for(int k = 1; k <= t; k++){
		cin >> n >> J;
		solve();
	}

	return 0;
}
