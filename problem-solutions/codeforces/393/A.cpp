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

int n, d;

int main(void){
	scanf("%d%d", &n, &d);
	
	int total;
	if(n == 1 or n == 3 or n == 5 or n == 7 or n == 8 or n == 10 or n == 12){
		total = 31;
	}
	if(n == 4 or n == 6 or n == 9 or n == 11){
		total = 30;
	}
	if(n == 2) total = 28;

	int cnt = d-1, res = 1;
	if(cnt == 0) res--;

	for(int i = 1; i <= total; i++){
		if(cnt == 0){
			res++;
		}
		cnt = (cnt+1)%7;
	}

	printf("%d\n", res);
	
	return 0;
}

