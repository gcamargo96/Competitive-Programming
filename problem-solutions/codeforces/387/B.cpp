#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
//#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

int n;
string s;
map<char,int> cnt;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n;
	cin >> s;

	cnt['?'] = 0;
	For(i,0,s.size()){
		cnt[s[i]]++;
	}

	int maior = n/4;
	
	For(i,0,s.size()){
		if(s[i] == '?'){
			if(cnt['A'] < maior){
				s[i] = 'A';
				cnt['A']++;
				cnt['?']--;
			}
			else if(cnt['C'] < maior){
				s[i] = 'C';
				cnt['C']++;
				cnt['?']--;
			}
			else if(cnt['G'] < maior){
				s[i] = 'G';
				cnt['G']++;
				cnt['?']--;
			}
			else if(cnt['T'] < maior){
				s[i] = 'T';
				cnt['T']++;
				cnt['?']--;
			}
		}
	}

	if(cnt['A'] == maior and cnt['C'] == maior and cnt['G'] == maior and cnt['T'] == maior and cnt['?'] == 0){
		cout << s << endl;
	}
	else{
		cout << "===" << endl;
	}

	return 0;
}

