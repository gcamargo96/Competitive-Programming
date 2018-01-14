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

string s, t;
map<char,char> m;
map<char,bool> foi;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> s >> t;

	bool ok = 1;
	For(i,0,s.size()){
		if(!m.count(s[i]) and !m.count(t[i])){
			m[s[i]] = t[i];
			m[t[i]] = s[i];
		}
		else if(m.count(s[i]) and !m.count(t[i])){
			ok = 0;
		}
		else if(!m.count(s[i]) and m.count(t[i])){
			ok = 0;
		}
		else if(m[s[i]] != t[i] or m[t[i]] != s[i]){
			ok = 0;
		}
	}

	if(ok){
		int cnt = 0;
		for(auto it = m.begin(); it != m.end(); it++){
			if(it->fi != it->se and !foi[it->fi] and !foi[it->se]){
				cnt++;
				foi[it->fi] = 1;
				foi[it->se] = 1;
			}
		}
		foi.clear();
		cout << cnt << endl;
		for(auto it = m.begin(); it != m.end(); it++){
			if(it->fi != it->se and !foi[it->fi] and !foi[it->se]){
				cout << it->fi << " " << it->se << endl;
				foi[it->fi] = 1;
				foi[it->se] = 1;
			}
		}
	}
	else{
		cout << "-1" << endl;
	}
	
	return 0;
}

