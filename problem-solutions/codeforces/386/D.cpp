#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

#define G 0
#define B 1

int n,k, g, b;

int main(void){
	scanf("%d%d%d%d", &n, &k, &g, &b);

	int cur;
	string res;
	if(g > b){
		res += 'G';
		cur = G;
		g--;
	}
	else{
		res += 'B';
		cur = B;
		b--;
	}

	int cnt = 1;
	For(i,1,n){
		if(g > b){
			if(res[i-1] == 'G'){
				if(cnt < k){
					res += 'G';
					g--;
					cnt++;
				}
				else{
					if(b > 0){
						res += 'B';
						b--;
						cnt = 1;
					}
					else break;
				}
			}
			else{
				res += 'G';
				g--;
				cnt = 1;
			}
		}
		else{ // b >= g
			if(res[i-1] == 'B'){
				if(cnt < k){
					res += 'B';
					b--;
					cnt++;
				}
				else{
					if(g > 0){
						res += 'G';
						g--;
						cnt = 1;
					}
					else break;
				}
			}
			else{
				res += 'B';
				b--;
				cnt = 1;
			}
		}
	}

	if(res.size() == n){
		cout << res << endl;
	}
	else{
		cout << "NO" << endl;
	}

	return 0;
}

