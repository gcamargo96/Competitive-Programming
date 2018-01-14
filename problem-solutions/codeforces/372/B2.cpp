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

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> s;

	int i = 0, j = 0;
	bool ok = 0;
	while(j < s.size()){
		if(s[j] != '?'){
			if(cnt[s[j]-'A'] == 0){
				cnt[s[j]-'A']++;
				j++;
			}
			else{
				while(cnt[s[j]-'A'] == 1){
					cnt[s[i]-'A']--;
					i++;
					//cout << "andou o i" << endl;
				}
				cnt[s[j]-'A']++;
				j++;
			}
		}
		else{
			j++;
		}
		if(j-i == 26){
			//cout << "de " << i << " a " << j << endl;
			ok = 1;
			break;
		}
	}

	string need;
	int p = 0;
	For(k,0,26){
		if(cnt[k] == 0) need += k+'A';
	}

	if(ok){
		For(k,0,s.size()){
			if(s[k] != '?'){
				cout << s[k];
			}
			else{
				if(i <= k and k <= j and p < need.size()){
					cout << need[p];
					p++;
				}
				else{
					cout << 'A';
				}
			}
		}
	}
	else{
		cout << "-1";
	}
	cout << endl;

	return 0;
}

