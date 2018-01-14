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

int T, b, sg, sb;
multiset<int, greater<int> > green, blue;

int main(void){
	scanf("%d", &T);

	For(k,0,T){
		green.clear();
		blue.clear();
		scanf("%d%d%d", &b, &sg, &sb);
		
		int x;
		For(i,0,sg){
			scanf("%d", &x);
			green.insert(x);
		}

		For(i,0,sb){
			scanf("%d", &x);
			blue.insert(x);
		}

		int round = 1;
		while(!green.empty() and !blue.empty()){
			int cnt = 0;
			vector<multiset<int,greater<int> >::iterator>  eg, eb;
		    vector<int> ig, ib;
			//printf("round #%d\n", round);
			//printf("green.size() = %zu / blue.size() = %zu\n", green.size(), blue.size());
			for(auto itg = green.begin(), itb = blue.begin(); itg != green.end() and itb != blue.end(); itg++, itb++){
				if(cnt == b) break;
				
				//printf("%d x %d\n ", *itg, *itb);
				eg.pb(itg);
				eb.pb(itb);
				
				if(*itg > *itb){
					ig.pb(*itg-*itb);
				}
				else if(*itg < *itb){
					ib.pb(*itb-*itg);
				}
				cnt++;
			}

			For(i,0,eg.size()){
				green.erase(eg[i]);
			}
			For(i,0,eb.size()){
				blue.erase(eb[i]);
			}
			For(i,0,ig.size()){
				green.insert(ig[i]);
			}
			For(i,0,ib.size()){
				blue.insert(ib[i]);
			}

			//printf("-----------------------------------------------\n");
			//round++;
		}

		if(green.empty() and blue.empty()){
			printf("green and blue died\n");
		}
		else if(!green.empty()){
			printf("green wins\n");
			for(auto it = green.begin(); it != green.end(); it++){
				printf("%d\n", *it);
			}
		}
		else{
			printf("blue wins\n");
			for(auto it = blue.begin(); it != blue.end(); it++){
				printf("%d\n", *it);
			}
		}
		if(k < T-1) printf("\n");
	}

	return 0;
}
