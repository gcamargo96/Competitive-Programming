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

map<string, int> m;
int n;

int main(void){
	ios_base::sync_with_stdio(false);

	while(cin >> n and n != 0){
		m.clear();
			
		For(i,0,n){
			string v[5];
			int x;
			
			For(i,0,5){
				cin >> v[i];
			}

			sort(v, v+5);
			
			string s;
			For(j,0,5){
				s += v[j];
			}

			//cout << s << endl;
			m[s]++;
		}

		int maior = 0, res = 0;
		for(auto it = m.begin(); it != m.end(); it++){
			maior = max(maior, it->se);
		}

		for(auto it = m.begin(); it != m.end(); it++){
			if(it->se == maior) res += maior;
		}

		cout << res << endl;
	}

	return 0;
}
