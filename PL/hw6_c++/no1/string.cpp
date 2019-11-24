#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	string str1 = "I liek ";
	cout<<str1<<endl;

	string str2;
	cout<<"문자열 입력";
	cin>>str2;
        cout<<str2;


	char *s[] = "agsdgg";
	string str3 = s;
	cout<<str3;
	return 0;


}
