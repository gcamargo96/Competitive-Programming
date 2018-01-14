#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

//map<string, map<ll,ll> > m;
map<string, int> m;
int n;
ll x;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;

	char op;
	For(i,0,n){
		cin >> op;
		
		string s;

		if(op == '+'){
			cin >> x;
			ll aux = x;

			while(aux != 0){
				//s += aux%10 + '0';
				int digit = aux%10;
				if(digit%2 == 0) s += '0';
				else s += '1';
				aux /= 10;
			}

			string zeros;
			for(int i = s.size(); i <= 18; i++) zeros += '0';
			string id = zeros;
			for(int i = s.size()-1; i >= 0; i--) id += s[i];
			//cout << "add " << id << endl;

			m[id]++;
		}
		if(op == '-'){
			cin >> x;
			ll aux = x;

			while(aux != 0){
				int digit = aux%10;
				if(digit%2 == 0) s += '0';
				else s += '1';
				aux /= 10;
			}	
			
			string zeros;
			for(int i = s.size(); i <= 18; i++) zeros += '0';
			string id = zeros;
			for(int i = s.size()-1; i >= 0; i--) id += s[i];
			//cout << "rem " << id << endl;

			m[id]--;
		}
		if(op == '?'){
			cin >> s;
			
			string zeros;
			for(int i = s.size(); i <= 18; i++) zeros += '0';
			string id = zeros + s;

			int res = m[id];
			cout << res << endl;
		}
	}

	return 0;
}
