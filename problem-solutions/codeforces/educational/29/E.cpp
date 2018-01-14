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

int k, n;
set<string> words;

int main(void){
	fastcin;
	cin >> k >> n;

	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		for(int j = i+1; j < s.size(); j++){
			swap(s[i], s[j]);
			words.insert(s);
			swap(s[i],  s[j]);
		}
	}

	for(int i = 1; i < k; i++){
		cin >> s;
		set<string> aux;
		for(int j = 0; j < s.size(); j++){
			for(int l = j+1; l < s.size(); l++){
				swap(s[j], s[l]);
				aux.insert(s);
				swap(s[j], s[l]);
			}
		}

		vector<string> to_erase;
		for(string x : words){
			if(!aux.count(x)){
				to_erase.pb(x);
			}
		}
		for(string x : to_erase){
			words.erase(x);
		}
	}

	if(words.size() == 0){
		cout << -1 << endl;
	}
	else{
		cout << *(words.begin()) << endl;
	}

	return 0;
}