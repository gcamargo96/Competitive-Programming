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
int n, k;
ll acum[N];

int main(void){
	scanf("%d%d", &n, &k);

	int x;
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		acum[i] = acum[i-1] + x;
	}

	ll maxb = 0, res = 0;
	int a = 0, b = 0, bb = 0;
	for(int i = n-2*k+1; i >= 1; i--){
		int j = i+k-1;
		int l = j+1, m = l + k - 1;
		
		ll suma = acum[j] - acum[i-1];
		ll sumb = acum[m] - acum[l-1];

		if(sumb >= maxb){
			maxb = sumb;
			bb = l;
		}

		if(suma + maxb >= res){
			res = suma + maxb;
			a = i;
			b = bb;
		}

	}

	printf("%d %d\n", a, b);

	return 0;
}

