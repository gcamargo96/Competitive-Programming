#include <bits/stdc++.h>
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
using namespace std;

const int N=2e5+1;
char str[N];
int len,gap;
int sa[N], rank[N], tmp[N], lcp[N], lcpt[N][21], l2[N];

bool cmp(int i, int j) {
	if (rank[i]!=rank[j])
		return rank[i]<rank[j];
	i+=gap;
	j+=gap;
	return (i<len && j<len)?rank[i]<rank[j]:i>j;
}

void build() {
	For(i,0,len) sa[i]=i,rank[i]=str[i];
	for(gap=1;;gap*=2) {
		sort(sa, sa+len, cmp);
		For(i,0,len-1) tmp[i+1]=tmp[i]+cmp(sa[i], sa[i+1]);
		For(i,0,len) rank[sa[i]]=tmp[i];
		if (tmp[len-1]==len-1) break;
	}
}

void build_lcp() {
	int px = 1;
	l2[0]=0;
	for (int i=0,k=0;i<len;++i)if(rank[i]!=len-1) {
		for(int j=sa[rank[i] + 1]; str[i+k]==str[j+k];)
			++k;

		if (i > 0) l2[i] = l2[i-1];
		if (px * 2 <= i) {px <<= 1; l2[i]++;}
		lcp[rank[i]] = k;
		lcpt[rank[i]][0] = k;
		if (k)--k;
	}
	for (int j = 1; j<21; j++)
	for (int i=0;i < len - (1<<j);i ++) 
		lcpt[i][j] = min (lcpt[i][j-1], lcpt[i+(1<<(j-1))][j-1]);
}
int getlcp (int l, int r) {
	--r;
	int j = l2[r-l+1];
	return min(lcpt[l][j], lcpt[r-(1<<j)+1][j]);
}

int main () {
	scanf ("%s", str);
	len = strlen(str);

	build();
	build_lcp();

	For(i,0,len){
		for(int j = sa[i]; j < len; j++){
			printf("%c", str[j]);
		}
		printf("\n");
	}

	return 0;
}
