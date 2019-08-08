#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_wjh_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int q;
string s, t, p;
int cnt[30];

int main() {
	cin >> q;

	while(q--){
		cin >> s >> t >> p;
		
		memset(cnt, 0, sizeof cnt);
		
		for(int i = 0; i < p.size(); i++)
			cnt[p[i] - 'a']++;

		bool ok = 1;
		int i = 0, j = 0;
		while(i < s.size()){
			if(j == t.size()){
				ok = false;
				break;
			}
			
			if(s[i] == t[j]){
				++i, ++j;
				continue;
			}
			
			cnt[t[j] - 'a']++;
			j++;
		}

		// cout << cnt[0] << " " << cnt[1] << endl;

        while(j < t.size()){
            cnt[t[j] - 'a']--;
			++j;
        }
        
        for(int i = 0; i < 30; i++){
        	if(cnt[i] < 0) ok = 0;
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