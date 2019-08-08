#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;
 
const int N = 105;
string s, t, p;
int q;
 
int has[30], need[30];
 
int main(void){
	fastcin;
	cin >> q;
 
	while(q--){
		memset(has, 0, sizeof has);
		memset(need, 0, sizeof need);
		cin >> s >> t >> p;
	
		int i = 0, j = 0;
		for(i = 0; i < s.size(); i++){
			while(j < t.size() and t[j] != s[i]){
				need[t[j]-'a']++;
				j++;
 			}

			if(j < t.size()){
				// has[s[i]-'a']++;
				j++;
			}
			else{
				break;
			}
		}

		if(i < s.size()){
			cout << "NO" << endl;
			continue;
		}
 
		for(int i = 0; i < p.size(); i++){
			has[p[i]-'a']++;
		}
  
		for(int i = j; i < t.size(); i++){
			need[t[i]-'a']++;
		}
 
		bool ok = 1;
		for(int i = 0; i < 26; i++){
			if(has[i] < need[i]) ok = 0;
		}
 
		if(ok){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
 
	return 0;
}