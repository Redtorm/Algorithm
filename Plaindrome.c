#include<stdio.h>
#include<string.h>
#define STLEN 100
#define NUM 100
#define true 1
#define flase 0
typedef int bool;

int longestPalindrome(char *str);

int main(void){
	int i = 0, n = 0;
	int m[NUM] = {0};
	char plain[NUM][STLEN];
	while((scanf("%d", &n) != EOF) && (n != 0)){
		scanf("%s", plain[i]);
		m[i] = n;
		i++;
	}
	for (int j = 0; j < i; j++){
		char* p = plain[j];
		int len = longestPalindrome(p); 
		m[j] = m[j] - len;
	}
	for (int j = 0; j < i; j++) printf("%d\n", m[j]);
	return 0;
}

int longestPalindrome(char *str){
	int len = strlen(str);
	int lps[len][len];
    for (int i = 0; i < len; i++){
		for (int j = 0; j < len; j++){
			if(i == j) lps[i][j] = 1;
			else lps[i][j] = 0;
		}
	}
	for (int i = 1; i < len; i++){
		for (int j = 0; j + i < len; j++){
			if (str[j] == str[i + j]) lps[j][i + j] = lps[j + 1][i + j - 1] + 2;
			else{
				if(lps[j][i + j - 1] < lps[j + 1][i + j]) lps[j][i + j] = lps[j + 1][i + j];
				else lps[j][i + j] = lps[j][i + j - 1];
			}
		}
	}
	return lps[0][len - 1];
}
