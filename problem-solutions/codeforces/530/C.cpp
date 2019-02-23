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
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

string s;
int k;

int main(void){
	fastcin;
	cin >> s >> k;

	int len = 0;
	int candy = 0, flake = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] != '?' and s[i] != '*'){
			len++;
		}
		if(s[i] == '?')
			candy++;
		if(s[i] == '*')
			flake++;
	}

	if(len == k){
		for(int i = 0; i < s.size(); i++){
			if(s[i] != '?' and s[i] != '*'){
				cout << s[i];
			}
		}
		cout << endl;
	}
	else if(len < k){
		if(flake > 0){

			int need = k-len;
			for(int i = 0; i < s.size(); i++){
				while(s[i] == '*' and need > 0){
					cout << s[i-1];
					need--;
				}
				if(s[i] != '?' and s[i] != '*'){
					cout << s[i];
				}
			}
			cout << endl;

		}
		else{
			cout << "Impossible" << endl;
		}
	}
	else{ // len > k
		s += '#';
		string ans;
		if(len - candy - flake <= k){
			int need = len-k;
			for(int i = 0; i < s.size(); i++){
				if((s[i+1] == '?' or s[i+1] == '*') and need > 0){
					need--;
				}
				else if(s[i] != '?' and s[i] != '*' and s[i] != '#'){
					ans += s[i];
				}

			}
			cout << ans << endl;
		}
		else{
			cout << "Impossible" << endl;
		}
	}

	return 0;
}