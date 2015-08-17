#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

int main()
{

	int init[2] = { 0, 0 };
	scanf_s("%d%d", &init[0], &init[1]);
	//fflush(stdin);

	//      printf("%d\t%d", init[0], init[1]);
	int *N = new int[init[0] + 1];
	int i = 1;

	while (scanf_s("%d", &N[i++]) && (i <= init[0]))
		;

	int *begin = new int[init[1]];
	int *end = new int[init[1]];
	char *opt = new char[init[1]];
	//const int  tmp = init[1];
	//char opt[tmp + 1];

	int j = 0;
	int highscore = 0;

	while (j < init[1])
	{
		fflush(stdin);
		scanf_s("%c",&opt[j]);
		scanf_s("%d%d",&begin[j], &end[j]);
		//scanf("%d%d",&begin[j],&end[j]);
		fflush(stdin);
		//fflush(stdin);
		//      printf("%c, %d, %d\n", opt[j], begin[j], end[j]);

		if (opt[j] == 'U' || opt[j] == 'u')
			N[begin[j]] = end[j];
		else if (opt[j] == 'Q' || opt[j] == 'q')
		{
			highscore = N[begin[j]];
			for (int k = begin[j] + 1; k <= end[j]; k++)
			if (highscore < N[k])
				highscore = N[k];
			printf("highscore=%d\n", highscore);

		}
		j = j + 1;
		printf("j=%d.\n", j);
	}
}