#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define PI acos(-1)
#define fastcin ios_base::sync_with_stdio(false);
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> ii;
typedef complex<double> base;

const int N = 10000005;

class LateProfessor {
public:
	int v[10000005];

	double getProbability(int waitTime, int walkTime, int lateTime, int bestArrival, int worstArrival){
		if(lateTime > walkTime) return 0;
		// set<int> late, in;

		int losing = walkTime - lateTime;


		int i = 0;
		while(i < N){
			for(int j = i; j < i+waitTime and j < N; j++){
				v[j] = 1;
			}
			// in.insert(i+waitTime);
			if(i+waitTime < N) v[i+waitTime] = 2;
			i += waitTime + losing;

			// late.insert(i);
			for(int j = i; j < i+lateTime and j < N; j++){
				v[j] = 1;
			}
			if(i < N) v[i] = 3;
			i += lateTime;
		}

		int den = worstArrival - bestArrival;
		int num = 0;

		// for(int i = 50; i <= 100; i++){
		// 	printf("%d ", v[i]);
		// }
		// printf("\n");

		if(den == 0){
			if(v[bestArrival] == 3) return 1;
			if(v[bestArrival] == 2) return 0;
			return 1-v[bestArrival];
		}

		for(int i = bestArrival; i < worstArrival; i++){
			if(v[i] == 0 or v[i] == 2) num++;
		}

		// printf("%d/%d\n", num, den);

		return double(num)/double(den);
	}
};

int main(void){
	LateProfessor *lp = new LateProfessor();


	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;

	double ans = lp->getProbability(a, b, c, d, e);
	delete lp;

	printf("%.10lf\n", ans);

	return 0;
}