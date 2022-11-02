#include<stdio.h>
#define ull unsigned long long
int main(){
	ull n, k;
	scanf("%llu%llu", &n, &k);
	n >>= k - 1;
	printf("%llu\n",n & 1);
	return 0;
}
