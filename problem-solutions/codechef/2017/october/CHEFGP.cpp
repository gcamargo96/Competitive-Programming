#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
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

#define A 0
#define B 1

int t, x, y;
string s;

int main(void){
	ios_base::sync_with_stdio(false);

	cin >> t;

	while(t--){
		cin >> s;
		cin >> x >> y;

		int a = 0, b = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == 'a') a++;
			else b++;
		}

		string ans;
		int cnta = 0, cntb = 0;
		while(a or b){
			// cout << a << " " << b << endl;
			if(a >= b){
				if(a > 0 and cnta < x){
					ans += 'a';
					a--;
					cnta++;
					cntb = 0;
				}
				else if(b > 0 and cntb < y){
					ans += 'b';
					b--;
					cntb++;
					cnta = 0;
				}
				else{
					ans += '*';
					cnta = 0;
					cntb = 0;
				}
			}
			else{
				if(b > 0 and cntb < y){
					ans += 'b';
					b--;
					cntb++;
					cnta = 0;
				}
				else if(a > 0 and cnta < x){
					ans += 'a';
					a--;
					cnta++;
					cntb = 0;
				}
				else{
					ans += '*';
					cnta = 0;
					cntb = 0;
				}
			}
		}

		cout << ans << endl;
	}

	return 0;
}