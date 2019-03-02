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

int pos, neg, n;

int main(void){
	scanf("%d", &n);

	int x;
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		if(x > 0) pos++;
		if(x < 0) neg++;
	}

	if(pos >= (n+1)/2){
		printf("1\n");
	}
	else if(neg >= (n+1)/2){
		printf("-1\n");
	}
	else{
		printf("0\n");
	}

	return 0;
}