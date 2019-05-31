#include <stdio.h>

int quick_mod(int a, int b, int c);

int main(){
	int a,b,c,d,j;
	int i = 0;
	int store[10][3] = {0};
	while (scanf("%d%d%d", &a, &b, &c) != EOF && (a || b || c) != 0){
		store[i][0] = a;
		store[i][1] = b;
		store[i][2] = c;
		i++;
    }
	for(j = 0; j < 10; j++){
		if(store[j][0] + store[j][1] + store[j][2] == 0) break;
		d = quick_mod(store[j][0],store[j][1],store[j][2]);             
		printf("%d\n",d);
	}
	return 0;
}


int quick_mod(int a, int b, int c)
{
    int ans = 1;
    a = a % c;
    while (b > 0)
    {
        if(b % 2 == 1)
            ans = (ans * a) % c;
        b = b / 2;
        a = (a * a) % c;
    }
    return ans;
}
/*
int quick_mod(int a, int b, int c){
	if (b == 0) return 1;
	if (b % 2 == 0) return quick_mod(a,b/2,c)*quick_mod(a,b/2,c)%c;
	else return quick_mod(a,b/2,c)*quick_mod(a,b/2,c)*(a % c)%c;
}
*/
/*递归算法将问题分解为规模为原来的一半的两个子问题，最终的时间复杂度还是O(n)。
而快速幂算法判断b的每个二进制位，b有多少个二进制位循环就进行多少次，时间复杂度为log(n)*/