#include <bits/stdc++.h>
using namespace std;
#define INF 0X3f3f3f3f
#define M 1000000007
#define fastcin ios_base::sync_with_stdio(false);
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

#define B 33

const int N = 50005;
string s;
int a, b, c, d;
ll mod[2] = {1000000007, 1000000009};
ll h[2][N], hr[2][N];
ll pot[2][N], potr[2][N];
int t, n;

void precalc(string& s){
    for(int k = 0; k < 2; k++){
        h[k][0] = s[0]/* - 'A' + 1*/;
        pot[k][0] = 1;

        for(int i = 1; i < s.size(); i++){
            h[k][i] = ((h[k][i-1]*B)%mod[k] + (s[i]/* - 'A' + 1*/))%mod[k];
            pot[k][i] = (pot[k][i-1]*B)%mod[k];
        }
    }
}

ll calcHash(int i, int j, int k){
    if(i == 0) return h[k][j];
    return (h[k][j] - (h[k][i-1]*pot[k][j-i+1])%mod[k] + mod[k])%mod[k];
}

int main(void){
	fastcin;
	cin >> t;

	for(int caso = 1; caso <= t; caso++){
		cin >> s;
		n = s.size();
		precalc(s);

		int l1 = 0, r1 = 0;
		int l2 = n-1, r2 = n-1;
		int ans = 0;
		while(r1 <= l2){
			if(calcHash(l1,r1,0) == calcHash(l2,r2,0) and calcHash(l1,r1,1) == calcHash(l2,r2,1)){
				if(l1 == l2 and r1 == r2) ans++;
				else ans += 2;
				r1++;
				l1 = r1;
				l2--;
				r2 = l2;
			}
			else{
				r1++;
				l2--;
			}
		}
		if(l1 < r1){
			ans++;
		}

		cout << "Case #" << caso << ": " << ans << endl;
	}

	return 0;
}