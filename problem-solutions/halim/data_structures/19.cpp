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
int l, m, T;
queue<int> esq, dir;
int res[N];
int tempo;

int main(void){
	scanf("%d", &T);

	For(i,0,T){
		tempo = 0;
		scanf("%d%d", &l, &m);
		
		l *= 100;
		int tam;
		char side[10];
		For(j,0,m){
			scanf("%d", &tam);
			scanf("%s", side);
			if(strcmp(side, "left") == 0){
				esq.push(tam);
			}
			else{
				dir.push(tam);
			}
		}

		bool cur = ESQ;
		int cnt = 0, res = 0;
		while(!(esq.empty() and dir.empty())){	
			int boat = 0;
			if(cur == ESQ){
				while(!esq.empty() and boat + esq.front() <= l){
					boat += esq.front();
					esq.pop();
				}
			}
			else{
				while(!dir.empty() and boat + dir.front() <= l){
					boat += dir.front();
					dir.pop();
				}
			}

			cur = !cur;
			res++;
		}
		printf("%d\n", res);
	}

	return 0;
}
