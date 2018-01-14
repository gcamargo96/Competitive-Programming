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

const int N = 100002;
int n;
//int v[N];
priority_queue<int> pq;

int main(void){
	scanf("%d", &n);

	int x, last = n+1;
	for(int i = n; i >= 1; i--){
		scanf("%d", &x);
		pq.push(x);
		while(!pq.empty() and pq.top() == last-1){
			printf("%d ", pq.top());
			last = pq.top();
			pq.pop();
		}
		printf("\n");
	}

	return 0;
}

