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

#define L 0
#define O 1

const int T = 1000002, N = 102;
int n, q;
int t, k, d;

struct server{
	int status, t;
};

server s[N];

int main(void){
	scanf("%d%d", &n, &q);
	
	for(int i = 1; i <= n; i++){
		s[i].status = L;
	}
	
	For(i,0,q){
		scanf("%d%d%d", &t, &k, &d);
		
		int livres = 0;
		for(int i = 1; i <= n; i++){
			if(s[i].status == O and s[i].t < t){
				s[i].status = L;
			}
			if(s[i].status == L) livres++;
		}
		
		if(livres >= k){
			int cnt = 0, sum = 0;
			for(int i = 1; i <= n and cnt < k; i++){
				if(s[i].status == L){
					s[i].status = O;
					s[i].t = t+d-1;
					cnt++;
					sum += i;
				}
			}
			printf("%d\n", sum);
		}
		else{
			printf("-1\n");
		}
	}

	return 0;
}

