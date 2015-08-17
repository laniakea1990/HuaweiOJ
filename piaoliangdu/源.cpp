#include<iostream>
#include<string>
#include<algorithm>

using namespace std;


int getBeauty(char str[])
{
	int numChr[26] = { 0 };
	int beauty = 0;
	
	for (int i = 0; str[i] != '\0'; i++)
	{
		str[i] = tolower(str[i]);
	}
	for (int i = 0; str[i] != '\0'; i++)
	{
		numChr[str[i] - 97]++;
	}

	sort(numChr, numChr + 26);
	
	for (int i = 25; i >= 0; i--)
	{
		beauty += (i+1) * numChr[i];
	}

	return beauty;
}


int main()
{
	int numStr;
	char str[100][100];
	scanf_s("%d", &numStr);	//number of string

	for (int i = 0; i < numStr; i++)
	{
		cin >> str[i];
		cout << getBeauty(str[i]) << endl;
	}

	return 0;
}