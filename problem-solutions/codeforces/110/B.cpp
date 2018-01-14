#include <bits/stdc++.h>
using namespace std;

const int N = 102;
int n;
int v[N];

int main(void){
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}

	sort(v, v+n);

	double res = 0;
    int cnt = 0;
	for(int i = n-1; i >= 0; i--){
		if(cnt%2 == 0){
			res += acos(-1)*v[i]*v[i];
		}
		else{
			res -= acos(-1)*v[i]*v[i];
		}
		cnt++;
	}

	printf("%.10lf\n", res);

	return 0;
}
