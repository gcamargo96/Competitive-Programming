#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int n;
map<string, set<string> > friends, ban;

int main(void){
	fastcin;
	cin >> n;

	string s;
	int m;
	for(int i = 0; i < n; i++){
		cin >> s >> m;

		string num;
		for(int j = 0; j < m; j++){
			cin >> num;
			friends[s].insert(num);
		}
	}

	// para cada amigo
	for(auto it = friends.begin(); it != friends.end(); ++it){
		// para cada numero do amigo atual
		for(auto it2 = it->se.begin(); it2 != it->se.end(); ++it2){
			// para cada numero do amigo atual
			for(auto it3 = it->se.begin(); it3 != it->se.end(); ++it3){
				// se nao for o mesmo numero
				if(*it2 != *it3){
					string s = *it2;
					string t = *it3;

					// t tem que ser a menor string
					if(s.size() < t.size())
						swap(s, t);

					bool suffix = 1; 	
					// virifica so o sufixo
					for(int i = s.size()-t.size(); i < s.size(); i++){
						// se alguma letra nao bater, t nao eh sufixo de s
						if(s[i] != t[i - (s.size()-t.size())]){
							suffix = 0;
							break;
						}
					}
					// cout << endl;

					if(suffix){
						// insere t nos numeros banidos do amigo atual
						ban[it->fi].insert(t);
						// break;
					}
				}
			}
		}
	}

	// nro de amigos
	cout << friends.size() << endl;

	// para cada amigo
	for(auto it = friends.begin(); it != friends.end(); ++it){
		// nome do amigo, total de numeros - nro de banidos
		cout << it->fi << " " << it->se.size() - ban[it->fi].size() << " ";
		// para cada numero do amigo atual
		for(auto it2 = it->se.begin(); it2 != it->se.end(); ++it2){
			// se o nro atual nao estiver banido
			if(!(ban[it->fi].count(*it2)))
				cout << *it2 << " ";
		}
		cout << endl;
	}

	return 0;
}