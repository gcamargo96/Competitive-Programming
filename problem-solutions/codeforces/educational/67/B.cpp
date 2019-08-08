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

const int N = 200005;
int t, n, m;
string s;
int cnts[N][30];
int cntt[30];

bool check(int pos){
	for(int i = 0; i < 26; i++){
		if(cnts[pos][i] < cntt[i]){
			// printf("deu ruim em pos = %d, letra = %c\n", pos, char(i+'a'));
			return 0;
		}
	}
	return 1;
}

int solve(){
	int lo = 0, hi = n-1, ans = n;

	while(lo <= hi){
		int mid = (lo+hi)/2;

		if(check(mid)){
			ans = mid+1;
			hi = mid-1;
		}
		else{
			lo = mid+1;
		}
	}

	return ans;
}

int main(void){
	fastcin;
	cin >> n >> s >> m;

	cnts[0][s[0]-'a']++;
	for(int i = 1; i < n; i++){
		for(int j = 0; j < 26; j++){
			cnts[i][j] = cnts[i-1][j];
		}
		cnts[i][s[i]-'a']++;
	}

	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < 26; j++){
	// 		printf("%d ", cnts[i][j]);
	// 	}
	// 	printf("\n");
	// }

	string t;
	for(int i = 0; i < m; i++){
		cin >> t;

		memset(cntt, 0, sizeof cntt);

		for(int j = 0; j < t.size(); j++){
			cntt[t[j]-'a']++;
		}

		// for(int j = 0; j < 26; j++){
		// 	printf("%d ", cntt[j]);
		// }
		// printf("\n");

		int ans = solve();
		printf("%d\n", ans);
	}

	return 0;
}