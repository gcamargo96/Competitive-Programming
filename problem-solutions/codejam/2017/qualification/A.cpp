#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int t, k;
string s;

void flip(int i){
	for(int j = i; j < i+k; j++){
		if(s[j] == '-') s[j] = '+';
		else s[j] = '-';
	}
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> t;

	for(int caso = 1; caso <= t; caso++){
		int res = 0;
		cin >> s >> k;
		For(i,0,(int)s.size()-k+1){
			if(s[i] == '-'){
				bool ok = 1;
				for(int j = i; j < i+k; j++){
					if(s[j] == '+'){
						ok = 0;
						break;
					}
				}
				if(ok){
					flip(i);
					res++;
				}
				else{
					int cnt = 0;
					for(int j = i+k-1; j >= i and s[j] == '+'; j--){
						cnt++;
					}
					for(int j = i+k; j < s.size() and s[j] == '-' and cnt < k; j++){
						cnt++;
					}
					
					if(cnt == k){
						flip(i);
						res++;
					}
					else{
						res = -1;
						break;
					}
				}
			}
		}

		for(int i = s.size()-k+1; i < s.size(); i++){
			if(s[i] == '-'){
				res = -1;
				break;
			}
		}
		
		cout << "Case #" << caso << ": ";
		if(res != -1){
			cout << res << endl;
		}
		else{
			cout << "IMPOSSIBLE" << endl;
		}
	}

	return 0;
}
