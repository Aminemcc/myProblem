#include<stdio.h>
int main(){
	char input[102];
	int T, i, cmd, k, reset = 26;
	scanf("%d",&T);
	while(T--){
		scanf("%d %d ",&cmd, &k);
		gets(input);
		k %= 26;
		if(k == 0){
			puts(input);
			continue;
		}
		if(cmd == 2){
			k *= -1;
			reset *= -1;
		}
		i = -1;
		while(input[++i] != '\0'){
			if( ('a' <= input[i] && input[i] <= 'z') || ('A' <= input[i] && input[i] <= 'Z') ){
				input[i] += k;
				if( !('a' <= input[i] && input[i] <= 'z') && !('A' <= input[i] && input[i] <= 'Z') ){
					input[i] -= reset;
				}
			}
		}
		puts(input);
		//continue;
	}
	return 0;
}
