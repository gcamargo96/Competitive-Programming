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

int t, n;
string a, b;
int cnt[30], cnt2[30];

bool check(int i, int j, int l, int r){
	for(int k = 0; k < 30; k++){
		if(cnt[k] != cnt2[k]) return 0;
	}
	return 1;
}

int main(void){
	fastcin;
	cin >> t;

	for(int caso = 1; caso <= t; caso++){
		cin >> n;
		cin >> a >> b;

		int ans = 0;
		for(int i = 0; i < n; i++){
			memset(cnt, 0, sizeof cnt);
			memset(cnt2, 0, sizeof cnt2);

			for(int j = i; j < n; j++){
				cnt[a[j]-'A']++;

				for(int k = 0; k < j-i+1; k++){
					cnt2[b[k]-'A']++;
				}

				for(int l = 0, r = j-i+1; r < n; l++, r++){
					if(check(i,j,l,r))
						ans++;
					cnt2[b[l]-'A']--;
					if(r+1 < n) cnt2[b[r+1]-'A']++;
				}
			}
		}

		cout << "Case #" << caso << ": " << ans << endl;
	}

	return 0;
}