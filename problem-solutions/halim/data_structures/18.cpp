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
#define ESQ 0
#define DIR 1

const int N = 10002;
int n, t, m, T;
queue<ii> esq, dir;
int res[N];
int tempo;

int main(void){
	scanf("%d", &T);

	For(i,0,T){
		tempo = 0;
		scanf("%d%d%d", &n, &t, &m);
		
		int tmp;
		char side[10];
		For(j,0,m){
			scanf("%d", &tmp);
			scanf("%s", side);
			if(strcmp(side, "left") == 0){
				esq.emplace(j, tmp);
			}
			else{
				dir.emplace(j, tmp);
			}
		}

		bool cur = ESQ;
		queue<int> boat;
		int cnt = 0;
		while(!(esq.empty() and dir.empty() and boat.empty())){
			int nxt;
			if(!esq.empty() and !dir.empty()){
				nxt = min(esq.front().se, dir.front().se);
			}
			else if(esq.empty() and !dir.empty()){
				nxt = dir.front().se;
			}
			else if(!esq.empty() and dir.empty()){
				nxt = esq.front().se;
			}
			else{
				//nxt = -1;
				break;
			}

			if(nxt > tempo){
				tempo = nxt;
				continue;
			}
			
			if(cur == ESQ){
				while(!esq.empty() and esq.front().se <= tempo and boat.size() < n){
					boat.push(esq.front().fi);
					esq.pop();
				}
			}
			else{
				while(!dir.empty() and dir.front().se <= tempo and boat.size() < n){
					boat.push(dir.front().fi);
					dir.pop();
				}
			}

			cur = !cur;
			tempo += t;

			while(!boat.empty()){
				res[boat.front()] = tempo;
				boat.pop();
			}
		}

		For(j,0,m){
			printf("%d\n", res[j]);
		}

		if(i < T-1) printf("\n");
	}

	return 0;
}
