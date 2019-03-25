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
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

int n, k;
priority_queue<int, vector<int>, greater<int> > pq;

int main(void){
	scanf("%d%d", &n, &k);

	int x;
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		pq.push(x);
	}

	int sub = 0;
	for(int i = 0; i < k; i++){
		while(!pq.empty() and pq.top()-sub <= 0){
			pq.pop();
		}

		if(!pq.empty()){
			x = pq.top()-sub;
			printf("%d\n", x);
			sub += x;
		}
		else{
			printf("0\n");
		}
	}

	return 0;
}