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

const int N = 1002;
int n;
int v[N];

int main(void){
	while(scanf("%d", &n), n != 0){
		while(scanf("%d", &v[1]), v[1] != 0){
			For(i,2,n+1){
				scanf("%d", &v[i]);
			}

			stack<int> p;
			int j = 1;
			bool ok = 1;
			For(i,1,n+1){
				while(j <= v[i]){
					p.push(j);
					j++;
				}
				if(!p.empty() and p.top() == v[i]){
					p.pop();
				}
				else{
					ok = 0;
					break;
				}
			}

			if(ok) printf("Yes\n");
			else printf("No\n");
		}
		printf("\n");
	}

	return 0;
}
