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

map<char,bool> good;
string pat;
int q;

int main(void){
	ios_base::sync_with_stdio(false);
	string aux;
	cin >> aux;
	For(i,0,aux.size()){
		good[aux[i]] = 1;
	}

	for(int i = 0; i < 26; i++){
		if(!good.count(i+'a')){
			good[i+'a'] = 0;
		}
	}

	cin >> pat >> q;

	bool ANS = 1;
	for(int i = 0; i < pat.size(); i++){
		if(pat[i] >= 'a' and pat[i] <= 'z' and !good[pat[i]]){
			ANS = 0;
		}
	}

	string s;
	while(q--){
		cin >> s;

		if(!ANS){
			cout << "NO" << endl;
			continue;
		}

		bool ans = 1;
		/*for(i = 0; i < s.size(); i++){
			if(s[i] >= 'a' and s[i] <= 'z' and good[s[i]] == 0){
				ans = 0;
			}
		}
		if(ans == 0){
			// cout << "aqui" << endl;
			cout << "NO" << endl;
			continue;
		}*/

		int i = 0;
		int j = 0;
		//string s;
		for(i = 0; i < pat.size(); i++){
			// cout << "i = " <<  i << " / j = " << j << endl;
			if(pat[i] == '?'){
				if(j >= s.size()){
					// cout << "aqui" << endl;
					ans = 0;
					break;
				}
				if(good[s[j]]){
					j++;
					// continue;
				}
				else{
					// cout << "aqui" << endl;
					ans = 0;
					break;
				}
			}
			else if(pat[i] == '*'){
				for(; j < s.size() and good[s[j]] == 0; j++){

				}
			}
			else{
				if(j >= s.size()){
					// cout << "aqui" << endl;
					ans = 0;
					break;
				}
				if(pat[i] == s[j]){
					j++;
					// continue;
				}
				else{
					// cout << "aqui" << endl;
					ans = 0;
					break;
				}
			}
		}

		cout << "i = " << i << " j = " << j << endl;
		if(i < pat.size() or j < s.size()){
			// cout << "aqui" << endl;
			ans = 0;
		}

		if(ans) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}