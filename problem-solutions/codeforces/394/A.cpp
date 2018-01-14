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

int a, b;

int main(void){
	scanf("%d%d", &a, &b);

	if(a == 0 and b == 0) printf("NO\n");
	else if(abs(a-b) >= 0 and abs(a-b) <= 1) printf("YES\n");
	else printf("NO\n");

	return 0;
}

