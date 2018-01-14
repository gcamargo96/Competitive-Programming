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

int n, m, z;

int main(void){
	scanf("%d%d%d", &n, &m, &z);

	int res= 0;
	for(int t = 1; t <= z; t++){
		if(t%n == 0 and t%m == 0) res++;
	}

	printf("%d\n", res);

	return 0;
}

