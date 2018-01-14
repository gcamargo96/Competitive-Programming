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

int t, p, x, y;

int main(void){
	scanf("%d", &t);

	for(int caso = 1; caso <= t; caso++){
		scanf("%d%d%d", &p, &x, &y);

		int dist = (x-50)*(x-50) + (y-50)*(y-50);
		double ang = atan2(y-50, x-50);
		ang = (ang*180)/acos(-1);
		if(ang < 0) ang = 360+ang;

		if(p == 0){
			printf("Case #%d: white\n", caso);
			continue;
		}
		if(x == 50 and y >= 50 and y <= 100){
			printf("Case #%d: black\n", caso);
			continue;
		}
		if(p >= 360){
			if(dist <= 50*50) printf("Case #%d: black\n", caso);
			else printf("Case #%d: white\n", caso);
			continue;
		}

		//printf("ang = %.1lf\n", ang);

		bool ok = 0;
		if(dist <= 50*50){
			if(ang >= 0 and ang <= 90){
				if(p >= 25) ok = 1;
				else if(90 - (p/100.0)*360 <= ang) ok = 1;
			}
			else if(ang > 90 and ang < 180){
				if(p < 75) /*continue*/;
				else if(90 - ((p/100.0)*360 - 270) <= ang-90) ok = 1;
			}
			else if(ang >= 180 and ang < 270){
				if(p < 50) /*continue*/;
				else if(p >= 75) ok = 1;
				else if(90 - ((p/100.0)*360 - 180) <= ang-180) ok = 1;
			}
			else if(ang >= 270 and ang < 360){
				if(p < 25) /*continue*/;
				else if(p >= 50) ok = 1;
				else if(90 - ((p/100.0)*360 - 90) <= ang-270) ok = 1;
			}
		}

		if(ok) printf("Case #%d: black\n", caso);
		else printf("Case #%d: white\n", caso);
	}

	return 0;
}

