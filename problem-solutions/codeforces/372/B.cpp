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

string s;
int cnt[26];
int falta, tem;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> s;

	char def;
	For(i,0,s.size()){
		if(s[i] != '?' and cnt[s[i]-'A'] == 0){
			tem++;
			cnt[s[i]-'A']++;
		}
		else if(s[i] == '?'){
			falta++;
		}
	}

	string need;
	For(i,0,26){
		if(cnt[i] == 0){
			need += i+'A';
			//def = i+'A';
		}
	}

	int j = 0;

	if(tem == 26){
		cout << s << endl;
	}
	else if(tem + falta >= 26){
		For(i,0,s.size()){
			if(s[i] != '?') cout << s[i];
			else{
				if(j < need.size()){
					cout << need[j];
					j++;
				}
				else cout << 'A';
			}
		}
	}
	else{
		cout << "-1";
	}
	cout << endl;

	return 0;
}

