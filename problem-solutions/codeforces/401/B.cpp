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

const int N = 10;
int n;
int a[N];
int sh[N], mo[N], ash[N], amo[N];

int main(void){
	scanf("%d", &n);

	char c;
	For(i,0,n){
		scanf(" %c", &c);
		sh[c-'0']++;
		ash[c-'0']++;
	}

	For(i,0,n){
		scanf(" %c", &c);
		mo[c-'0']++;
		amo[c-'0']++;
	}

	int res = 0;
	for(int i = 9; i >= 0; i--){
		for(int j = i; j <= 9; j++){
			int x = min(ash[i], amo[j]);
			ash[i] -= x;
			amo[j] -= x;
		}
	}
	For(i,0,10){
		res += amo[i];
	}
	printf("%d\n", res);

	res = 0;
	for(int i = 9; i >= 0; i--){
		for(int j = i+1; j <= 9; j++){
			int x = min(sh[i], mo[j]);
			res += x;
			sh[i] -= x;
			mo[j] -= x;
		}
	}
	printf("%d\n", res);
	
	return 0;
}

