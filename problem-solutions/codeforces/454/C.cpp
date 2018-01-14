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

set<char> canbe;
int n;
char op;
string s;

int main(void){
	fastcin;
	cin >> n;

	for(int i = 'a'; i <='z'; i++){
		canbe.insert(i);
	}

	bool ok = 0;
	int ans = 0;
	for(int i = 0; i < n; i++){
		cin >> op >> s;

		if(ok and (op == '!' or op == '?') and i != n-1){
			ans++;
		}
		else if(op == '.'){
			for(int j = 0; j < s.size(); j++){
				if(canbe.count(s[j])){
					canbe.erase(s[j]);
				}
			}
		}
		else if(op == '!'){ // interseccao
			set<char> aux;
			for(int j = 0; j < s.size(); j++){
				if(canbe.count(s[j])){
					aux.insert(s[j]);
				}
			}
			canbe = aux;
		}
		else if(op == '?'){
			if(canbe.count(s[0])){
				canbe.erase(s[0]);
			}
		}

		if(canbe.size() == 1){
			ok = 1;
		}
	}

	cout << ans << endl;

	return 0;
}