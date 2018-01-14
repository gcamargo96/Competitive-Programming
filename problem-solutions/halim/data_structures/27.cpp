#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define endl "\n"
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))

priority_queue<int, vector<int>, greater<int> > pq;
int n, x;

int main(void){
	while(scanf("%d", &n) and n != 0){
		For(i,0,n){
			scanf("%d", &x);
			pq.push(x);
		}

		ll res = 0;
		while(pq.size() > 1){
			int a = pq.top();
			pq.pop();
			int b = pq.top();
			pq.pop();
			pq.push(a+b);
			res += a+b;
		}
		
		pq.pop();

		printf("%lld\n", res);
	}

	return 0;
}
