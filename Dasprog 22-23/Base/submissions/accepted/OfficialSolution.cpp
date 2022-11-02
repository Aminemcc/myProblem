#include<stdio.h>
#define ull unsigned long long
ull base, num_ori, num_pre, isPalindrom, count;

void solve(ull num_pos){
	if(num_pos == 0) return;
	solve(num_pos / base);
	if(num_pos % base != num_pre % base) isPalindrom = 0;
	num_pre /= base;
	printf("%llu",num_pos % base);
	if(num_pos != num_ori) printf("-");
}

int main(){
	count = 1;
	while(1){
		scanf("%llu%llu",&num_ori, &base);
		if(num_ori == -1 && base == -1) break;
		num_pre = num_ori;
		isPalindrom = 1;
		printf("Case %llu : ", count++);
		solve(num_ori);
		puts("");
		printf("%llu %llu : ",num_ori, base);
		if(isPalindrom) printf("Ya\n");
		else printf("Tidak\n");
	}
	return 0;
}
