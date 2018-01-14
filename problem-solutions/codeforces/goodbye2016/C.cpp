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

const int N = 200002;
int n;
int c[N], d[N];
int rating, divs;
bool inf;

int main(void){
	scanf("%d", &n);

	For(i,0,n){
		scanf("%d%d", &c[i], &d[i]);
	}

	divs = d[n-1];
	if(divs == 1){
		rating = INF;
		inf = 1;
	}
	else rating = 1899;
	
	int res = rating;
	bool ok = 1;
	int sum = 1899;
	for(int i = n-2; i >= 0; i--){
		rating -= c[i];
		sum += c[i];

		if(d[i] == 1 and rating < 1900){
			ok = 0;
		}
		if(d[i] == 2 and inf == 1){
			inf = 0;
			//res = min(res, 1899 + c[i]); <=========== BUG
			/*int sum = 1899;
			for(int j = i; j <= n-2; j++){
				sum += c[j];
			}*/
			res = sum;
			rating = 1899;
		}
		if(d[i] == 2 and rating >= 1900){
			res -= rating - 1899;
			rating = 1899;
		}
		divs = d[i];
	}

	res += c[n-1];

	if(ok and !inf){
		cout << res << endl;
	}
	else if(ok and inf){
		cout << "Infinity" << endl;
	}
	else{
		cout << "Impossible" << endl;
	}

	return 0;
}

