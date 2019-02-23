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

int x;

bool check(int n){
	int quadrados = 4 * (((n/2)*(n/2)+1)/2);
	int meio = 4*(n/4);
	int centro = 1;
	int total = quadrados + meio + centro;

	// printf("n = %d, total = %d\n", n, total);

	if(total < x) return 0;

	int k = x%4;

	if(k == 3 and n <= 3) return 0;
	return 1;
}

int main(void){
	scanf("%d", &x);

	int n = 1;
	while(!check(n)){
		n += 2;
	}

	printf("%d\n", n);

	return 0;
}