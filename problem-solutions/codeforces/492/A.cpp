#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back 
#define fi first
#define se second
#define endl "\n"
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

int n;

int main(void){
	scanf("%d", &n);

	int ans = 0;

	ans += n/100;
	n %= 100;

	ans += n/20;
	n %= 20;

	ans += n/10;
	n %= 10;

	ans += n/5;
	n %= 5;

	ans += n;
	n = 0;

	printf("%d\n", ans);

	return 0;
}