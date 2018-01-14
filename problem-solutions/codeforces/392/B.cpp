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

string s;
map<char,int> cnt;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> s;
	
	For(i,0,s.size()){
		if(s[i] != '!'){
			for(int j = i+4; j < s.size(); j += 4){
				if(s[j] == '!'){
					s[j] = s[i];
					cnt[s[i]]++;
				}
			}
		}
	}
	for(int i = s.size()-1; i >= 0; i--){
		if(s[i] != '!'){
			for(int j = i-4; j >= 0; j -= 4){
				if(s[j] == '!'){
					s[j] = s[i];
					cnt[s[i]]++;
				}
			}
		}
	}

	cout << cnt['R'] << " " << cnt['B'] << " " << cnt['Y'] << " " << cnt['G'] << endl;

	return 0;
}

