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

int w1, h1, w2, h2;

int main(void){
	scanf("%d%d%d%d", &w1, &h1, &w2, &h2);

	printf("%d\n", 2*(h1+h2) + 2*max(w1, w2) + 4);

	return 0;
}