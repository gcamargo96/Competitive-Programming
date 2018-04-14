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

int n;

int main(void){
	scanf("%d", &n);

	int ans = 0;
	for(int a = 1; a <= n; a++){
		for(int b = a; b <= n; b++){
			int c = a ^ b;
			if(c >= b and c <= n and a+b>c and b+c>a and a+c>b){
				// printf("%d %d %d\n", a, b, c);
				ans++;
			}
		}
	}

	printf("%d\n", ans);

	return 0;
}