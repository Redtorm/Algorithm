#include<stdio.h>
#include<string.h>
#define STLEN 1001
#define NUM 1000
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

int longestPalindrome(char* s)
	{
		int len = strlen(s);
		if (len <= 1) { return 1; }
		int start = 0;
		int maxlen = 0;
		for (int i = 1; i < len; i++)
		{
			int low = i - 1;
			int high = i;
			while (low >= 0 && high < len && s[low] == s[high])
			{
				low--;
				high++;
			}
			if (high - low - 1 > maxlen)
			{
				maxlen = high - low - 1;
				start = low + 1;
			}
			low = i - 1; high = i + 1;
			while (low >= 0 && high < len && s[low] == s[high])
			{
				low--;
				high++;
			}
			if (high - low - 1 > maxlen)
			{
				maxlen = high - low - 1;
				start = low + 1;
			}
		}
		return maxlen;
	}