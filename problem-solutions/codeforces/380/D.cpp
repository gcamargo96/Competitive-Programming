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

int n, a, b, k;
string s;
int total;

int main(void){
	ios_base::sync_with_stdio(false);
	cin >> n >> a >> b >> k;
	cin >> s;

	For(i,0,n){
		int j;
		if(s[i] == '0'){		
			for(j = i; j < n; j++){
				if(s[j] == '1') break;
			}
			int tam = j-i;
			if(tam >= k) total += tam;
			i = j;
		}
	}

	total -= b*k;
	if(b%2 == 0) b++;

	int res = total/b;
	if(total%b == 0) res++;

	cout << "total = " << total << endl;
	cout << res << endl;

	return 0;
}

