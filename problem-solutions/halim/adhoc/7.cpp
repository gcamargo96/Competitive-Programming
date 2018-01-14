#include <bits/stdc++.h>
using namespace std;

int main(void){
	double h, u, d, f;
	while(scanf("%lf%lf%lf%lf", &h, &u, &d, &f)){
		if(h == 0) break;
		//else printf("\n");
		int res = 0;

		int day = 1;
		double curh = u, curant = 0, disant = u;
		if(curh > h){
			printf("success on day 1\n");
			continue;
		}
		curh -= d;
		if(curh < 0){
			printf("failure on day 1\n");
			continue;
		}
		//printf("curh = %lf\n", curh);

		while(curh >= 0 and curh <= h){
			day++;
			disant = disant-(u*(f/100));
			if(disant > 0) curh += disant;
			//cout << "corner case" << endl;
			if(curh > h){
				res = 1;
				break;
			}
			curh -= d;
			if(curh < 0){
				res = -1;
				break	;
			}
			curant = curh;
			//printf("curh = %lf\n", curh);
		}

		if(res == 1){
			printf("success on day %d\n", day);
		}
		if(res == -1){
			printf("failure on day %d\n", day);
		}
		day++;
	}

	return 0;
}
