#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int s, g;

int main(void){
	scanf("%d%d", &s, &g);

	if(s > g and s%g == 0){		
		int a = g;
		int b = s-g;

		printf("%d %d\n", a, b);
	}
	else{
		printf("-1\n");
	}

	return 0;
}