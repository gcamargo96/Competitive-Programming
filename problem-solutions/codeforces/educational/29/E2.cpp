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

const int N = 2502;
string s[N];
int k, n;
int cnt1[26], cnt2[26];

int main(void){
	fastcin;
	cin >> k >> n;

	for(int i = 0; i < k; i++){
		cin >> s[i];
	}

	bool repetido = 0;
	for(int i = 0; i < n; i++){
		cnt1[s[0][i]-'a']++;
		if(cnt1[s[0][i]-'a'] > 1)
			repetido = 1;
	}

	// checking if the strings have the same characters
	for(int i = 1; i < k; i++){
		memset(cnt2, 0, sizeof cnt2);
		for(int j = 0; j < n; j++){
			cnt2[s[i][j]-'a']++;
		}

		for(int l = 0; l < 26; l++){
			if(cnt1[l] != cnt2[l]){
				cout << -1 << endl;
				return 0;
			}
		}
	}

	set<int> diff;
	bool hasdiff = 0;
	for(int i = 0; i < k; i++){
		for(int j = i+1; j < k; j++){
			int cnt = 0;
			for(int l = 0; l < n; l++){
				if(s[i][l] != s[j][l]){
					cnt++;
					diff.insert(l);
					hasdiff = 1;
				}
			}
			if(cnt == 1 or cnt > 4){
				cout << -1 << endl;
				return 0;
			}
		}
	}

	// if all the strings are the same
	if(!hasdiff){
		swap(s[0][0], s[0][1]);
		cout << s[0] << endl;
		return 0;
	}

	map<string, int> words;
	for(int l : diff){
		for(int r = 0; r < n; r++){
			if(l != r){
				swap(s[0][l], s[0][r]);
				words[s[0]] = 0;
				swap(s[0][l], s[0][r]);
			}
		}
	}

	// for(auto it = words.begin(); it != words.end(); it++){
	// 	cout << it->fi << endl;
	// }

	for(int i = 0; i < k; i++){
		for(auto it = words.begin(); it != words.end(); it++){
			int cnt = 0;
			for(int j = 0; j < n; j++){
				if(s[i][j] != it->fi[j]){
					cnt++;
				}
			}

			if(cnt == 2 or (cnt == 0 and repetido)){
				it->se++;
			}
		}
	}


	string ans;
	for(auto it = words.begin(); it != words.end(); it++){
		if(it->se == k){
			ans = it->fi;
			break;
		}
	}

	if(ans.size() == 0){
		cout << -1 << endl;
	}
	else{
		cout << ans << endl;
	}

	return 0;
}