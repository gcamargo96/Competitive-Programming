#include <cstdio>
#include <algorithm>
#include <cstring>
#include <complex>
#include <vector>
#include <cassert>
 
using namespace std;
 
const int N = 265100;
const double PI = acos(-1);
 
 
vector <int> pos1[5];
vector <int> pos2[5];
 
struct base{
	double real, imag;
	base(){}
	base(double r, double i){
		real = r;
		imag = i;
	}
 	base operator + (const base& a) const { return base(real+a.real, imag+a.imag); }
 	base operator - (const base& a) const { return base(real-a.real, imag-a.imag); }
  	base operator * (const base& a) const { return base(real*a.real - imag*a.imag, real*a.imag+imag*a.real); }
	base operator / (const double& a) const { return base(real/a,imag/a); }
};
 
 
int poly1[5][N];
int poly2[5][N];
int s1[5];
int s2[5];
base fa[N],fb[N];
 
int res[N];
 
int dp[6][6][50500];
 
 
int la;
 
int rev[N];
base wlen_pw[N];
 
void fft (base *a, int n, bool invert) {
	for (int i=0; i<n; ++i)
		if (i < rev[i])
			swap (a[i], a[rev[i]]);
 
	for (int len=2; len<=n; len<<=1) {
		double ang = 2*PI/len * (invert?-1:+1);
		int len2 = len>>1;
 
		base wlen (cos(ang), sin(ang));
		wlen_pw[0] = base (1, 0);
		for (int i=1; i<len2; ++i)
			wlen_pw[i] = wlen_pw[i-1] * wlen;
 
		for (int i=0; i<n; i+=len) {
			base t,
				*pu = a+i,
				*pv = a+i+len2, 
				*pu_end = a+i+len2,
				*pw = wlen_pw;
			for (; pu!=pu_end; ++pu, ++pv, ++pw) {
				t = *pv * *pw;
				*pv = *pu - t;
				*pu = *pu + t;
			}
		}
	}
 
	if (invert)
		for (int i=0; i<n; ++i)
			a[i] = a[i]/n;
}
 
void calc_rev (int n, int log_n) {
	for (int i=0; i<n; ++i) {
		rev[i] = 0;
		for (int j=0; j<log_n; ++j)
			if (i & (1<<j))
				rev[i] |= 1<<(log_n-1-j);
	}
}
int multiply (int a, int b, int d1, int d2) {
	int n = 1;
	while (n < max (d1, d2))  n <<= 1;
	n <<= 1;
	for(int i = 0; i < n; i++){
		fa[i]=base(poly1[a][i],0);
	}
 	for(int i = 0; i < n; i++){
		fb[i]=base(poly2[b][i],0);
	}	
	calc_rev(n,log2(n));
	fft (fa, n, false),  fft (fb, n, false);
	for (int i=0; i<n; ++i)
		fa[i] = fa[i] * fb[i];
	fft (fa, n, true);
 
	for (int i = la-1; i < 2*la -1; ++i)
		dp[a][b][i-la+1] = (int)round(fa[i].real);
 
	return n;
}
 
int c[6]={0,1,2,3,4};
 
char a[50500];
char b[50500];
 
int main(){
	scanf(" %s %s",a,b);
	la = strlen(a);
	for(int i = 0; i < la; i++){
		poly1[a[i] - 'A'][i]=1;
		poly1[a[i] - 'A'][i+la]=1;
		s1[a[i]-'A'] = max(s1[a[i]-'A'],i+la);
		poly2[b[i] - 'a'][la-1-i]=1;
		s2[b[i]-'a'] = max(s2[b[i]-'a'],la-1-i);
	}
	int d;
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			d=multiply(i,j,s1[i],s2[j]);
			/*for(int k = la-1; k < 2*la - 1; k++){
 
				dp[i][j][k-la+1]=res[k];
				//printf("%d %d %d == %d\n",i,j,k-(int)la+1,r[k]);
			}*/
		}
		
	}
	int ans=0;
	do{
		for(int i = 0; i < la; i++){
			int aux = dp[0][c[0]][i] + dp[1][c[1]][i] + dp[2][c[2]][i] + dp[3][c[3]][i]+ dp[4][c[4]][i];
			ans = max(ans,aux);
		}
	}while(next_permutation(c,c+5));
	//for(int i = 0; i < la; i++) ans = max(ans,dfs(i, 0));
 
	printf("%d\n",la-ans);
 
}