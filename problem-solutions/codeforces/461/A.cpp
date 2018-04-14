#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int c, o;

int main(void){
	scanf("%d%d", &c, &o);
	
	if(o == 0){
		printf("No\n");
		return 0;
	}
	if(o <= 1 and c > 0){
		printf("No\n");
		return 0;
	}

	int cpy = o-1;
	if(cpy <= c and cpy%2 == c%2){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}

	return 0;
}