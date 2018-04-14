#include <bits/stdc++.h>
using namespace std;
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

const int N = 5002;
string s;
int n;
int cnt[26][26], ans[26], c[26];

int main(void){
	fastcin;
	cin >> s;

	n = s.size();
	for(int i = 0; i < n; i++){
		c[s[i]-'a']++;
	}
	s += s;

	for(int d = 1; d < n; d++){
		memset(cnt, 0, sizeof cnt);

		for(int i = 0; i < n; i++){
			cnt[s[i]-'a'][s[i+d]-'a']++;
		}

		for(int i = 0; i < 26; i++){
			int p = 0;
			for(int j = 0; j < 26; j++){
				if(cnt[i][j] == 1){
					p++;
				}
			}
			ans[i] = max(ans[i], p);
		}
	}

	double prob = 0;
	for(int i = 0; i < 26; i++){
		// double pi = double(ans[i])/double(c[i]);
		// double pif = double(c[i])/double(n);
		double aux = double(ans[i])/double(n);
		// cout << aux << endl;
		prob += aux;
	}
	
	cout << fixed << setprecision(10) << prob << endl;

	return 0;
}