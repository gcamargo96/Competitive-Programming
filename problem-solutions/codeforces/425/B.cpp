#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

map<char, bool> good;
string aux, pat, s;
int n;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> aux;

	For(i,0,aux.size()){
		good[aux[i]] = 1;
	}

	cin >> pat >> n;
	bool tem = 0;
	For(i,0,pat.size()){
		if(pat[i] == '*') tem = 1;
	}
	
	string pre, pos;
	int i = 0;
	for(i = 0; i < pat.size() and pat[i] != '*'; i++){
		pre += pat[i];
	}

	i++;
	for(; i < pat.size(); i++){
		pos += pat[i];
	}

	// cout << "pre / pos = " << pre << " " << pos << endl;

	while(n--){
		cin >> s;

		bool ans = 1;
		if(!tem){
			if(s.size() == pat.size()){
				For(i,0,s.size()){
					if(!good[s[i]]) ans = 0;
					if(pat[i] != '?' and pat[i] != s[i]) ans = 0;
				}
			}
			else{
				ans = 0;
			}
		}
		else{
			if(s.size() < pre.size() + pos.size()){
				// ans = 0;
				cout << "NO" << endl;
				continue;
			}

			for(int i = 0; i < pre.size(); i++){
				if(pre[i] != '?'){
					if(s[i] != pre[i]) ans = 0;
				}
				else{
					if(!good[s[i]]) ans = 0;
				}
			}

			for(int i = pos.size()-1, j = s.size()-1; i >= 0; i--, j--){
				if(pos[i] != '?'){
					if(s[j] != pos[i]) ans = 0;
				}
				else{
					if(!good[s[j]]) ans = 0;
				}
			}

			for(int i = pre.size(); i < s.size() - pos.size(); i++){
				if(good[s[i]]) ans = 0;
				// cout << "entrou" << endl;
			}
		}

		if(ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}