#include <bits/stdc++.h>
using namespace std;

int n;
int v[105][105];
int sumr[105], sumc[105];

int main(void){
	cin >> n;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &v[i][j]);
		}
	}

	for(int i = 0; i < n; i++){
		int sum = 0;
		for(int j = 0; j < n; j++){
			sum += v[i][j];
		}
		sumr[i] = sum;
	}

	for(int j = 0; j < n; j++){
		int sum = 0;
		for(int i = 0; i < n; i++){
			sum += v[i][j];
		}
		sumc[j] = sum;
	}

	int res = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(sumc[j] > sumr[i]){
				res++;
			}
		}
	}

	printf("%d\n", res);

	return 0;
}
