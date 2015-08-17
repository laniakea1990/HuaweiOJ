#include<iostream>
#include<string>
using namespace std;

int lastWordLen(string str)
{
	if (str == "")
		return 0;

	if (str.find(" ") == -1)
		return str.size();
	string::iterator end = str.end();
	int count = 0;
	--end;

	while (*end != ' ' && end != str.begin())
	{
		++count;
		--end;
	}
		

	return count;
}

int main()
{
	string str;
	int length = 0;

	getline(cin,str);

	cout << str << endl;

	if (str.length() >= 128)
		return -1;
	length = lastWordLen(str);
	
	cout << length << endl;

	getchar();
	return 0;
}