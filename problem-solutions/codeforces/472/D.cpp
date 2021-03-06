#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000000000LL
#define M 1000000007
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
typedef complex<double> base;

int n;

int main(void){
	scanf("%d", &n);

	stack<int> s;
	int a, tot = 0;
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a);

		s.push(i);
		while(a >= tot){
			ans += i - s.top(); // "consertando" colocando +1 submerso nas posicoes anteriores
			s.pop();
			tot++;
		}

		ans += tot-a-1; // somando os submersos da posicao atual
	}

	printf("%lld\n", ans);

	return 0;
}