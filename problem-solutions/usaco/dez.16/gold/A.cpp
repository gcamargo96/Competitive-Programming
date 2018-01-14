#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
//#define endl "\n"
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;

const int N = 1002;
int n;

struct cow{
	ll x, y;
};

cow cows[N];

int main(void){
	//freopen("moocast.in", "r", stdin);
	//freopen("moocast.out", "w", stdout);
	
	scanf("%d", &n);

	For(i,0,n){
		scanf("%d%d", &cows[i].x, &cows[i].y);
	}

	ll res = 0;
	For(i,0,n){
		ll menor = 1000000000000000;
		For(j,0,n){
			if(i != j){
				ll dist = (cows[i].x-cows[j].x)*(cows[i].x-cows[j].x) + (cows[i].y-cows[j].y)*(cows[i].y-cows[j].y);
				menor = min(menor, dist);
			}
		}
		res = max(res, menor);
	}

	if(n > 1) printf("%lld\n", res);
	else printf("0\n");

	return 0;
}

