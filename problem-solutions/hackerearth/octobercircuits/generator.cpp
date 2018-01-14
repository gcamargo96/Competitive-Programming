#include <bits/stdc++.h>
using namespace std;

#define M 100
int n, q;

int main(void){
	srand(time(NULL));
	n = rand()%10;
	q = rand()%10;

	printf("%d %d\n", n, q);

	for(int i = 0; i < n; i++){
		int x = rand()%M;
		int y = rand()%M;
		
		int a = rand()%2;
		int b = rand()%2;

		if(a) x *= -1;
		if(b) y *= -1;

		printf("%d %d\n", x, y);
	}

	for(int i = 0; i < q; i++){
		int sx = rand()%M;
		int sy = rand()%M;
		int fx = rand()%M;
		int fy = rand()%M;
		
		int a = rand()%2;
		int b = rand()%2;
		int c = rand()%2;
		int d = rand()%2;
	
		if(a) sx *= -1;
		if(b) sy *= -1;
		if(c) fx *= -1;
		if(d) fy *= -1;
	
		printf("%d %d %d %d\n", sx, sy, fx, fy);
	}

	return 0;
}