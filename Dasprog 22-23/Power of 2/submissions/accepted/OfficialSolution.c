#include<stdio.h>
/*
Karena bilangan pangkat 2 dalam basis 2 adalah
100000..., hanya ada 1 bit yang on, sehingga jika
di & kan dengan n -1 nya, hasilnya selalu 0
*/
int main(){
	unsigned long long number;
	scanf("%llu",&number);
	if(number & (number - 1))
		puts("Tidak");
	else puts("Ya");
	return 0;
}

