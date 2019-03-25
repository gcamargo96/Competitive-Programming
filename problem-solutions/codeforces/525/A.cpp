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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int x;

int main(void){
	scanf("%d", &x);

	for(int a = 1; a <= x; a++){
		for(int b = 1; b <= x; b++){
			if(a%b == 0 and a*b > x and a/b < x){
				printf("%d %d\n", a, b);
				return 0;
			}
		}
	}

	printf("-1\n");

	return 0;
}