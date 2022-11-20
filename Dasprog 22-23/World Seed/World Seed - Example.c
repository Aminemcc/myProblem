#include<stdio.h>

void WorldSeed(int level[], int n, long long seed, int multiplier, int max_diff){
	int i;
	for(i = 0; i < n; i++){
		seed = seed * multiplier % max_diff + 1;
		multiplier = (multiplier + seed) % max_diff + 1;
		level[i] = seed;
	}
}

int main(){
	int n, i, multiplier, max_diff;
	long long seed;
	scanf("%d%lld%d%d", &n, &seed, &multiplier, &max_diff);
	int level[n];
	WorldSeed(level, n, seed, multiplier, max_diff);
	//Code starting from here
	
	return 0;
}
