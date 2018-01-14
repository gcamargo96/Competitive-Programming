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

const int N = 10002;
ll v1[N], v2[N];
ll x;

int main(void){
	int tam = 0;
	while(scanf("%lld", &x) != EOF){
		bool pois = 0;

		int j = 0;
		For(i,0,tam){
			if(v1[i] < x) v2[j] = v1[i];
			else if(!pois){
				v2[j] = x;
				j++;
				v2[j] = v1[i];
				pois = 1;
			}
			else{
				v2[j] = v1[i];
			}
			j++;
		}

		if(!pois) v2[tam] = x;
		
		tam++;

		//For(i,0,tam) printf("%d ", v2[i]);
		//printf("\n");
		
		if(tam%2 == 1){
			printf("%lld\n", v2[tam/2]);
		}
		else{
			printf("%lld\n", (v2[tam/2]+v2[tam/2-1])/2);
		}
		For(i,0,tam){
			v1[i] = v2[i];
			v2[i] = 0;
		}
	}

	return 0;
}
