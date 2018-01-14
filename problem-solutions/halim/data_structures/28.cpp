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

int n, x;

int main(void){
	while(scanf("%d", &n) != EOF){
		queue<int> q;
		stack<int> s;
		priority_queue<int> pq;

		int type;
		bool Q = 1, S = 1, PQ = 1;
		For(i,0,n){
			scanf("%d", &type);
			if(type == 1){
				scanf("%d", &x);
				q.push(x);
				s.push(x);
				pq.push(x);
			}
			else{
				scanf("%d", &x);
				if(q.empty() or q.front() != x){
					Q = 0;
				}
				if(s.empty() or s.top() != x){
					S = 0;
				}
				if(pq.empty() or pq.top() != x){
					PQ = 0;
				}

				if(!q.empty()) q.pop();
				if(!s.empty()) s.pop();
				if(!pq.empty()) pq.pop();
			}
		}

		if(!Q and !S and !PQ){
			printf("impossible\n");
		}
		else if(Q and !S and !PQ){
			printf("queue\n");
		}
		else if(!Q and S and !PQ){
			printf("stack\n");
		}
		else if(!Q and !S and PQ){
			printf("priority queue\n");
		}
		else{
			printf("not sure\n");
		}
	}

	return 0;
}
