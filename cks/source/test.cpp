#include<bits/stdc++.h>
void change(char*str)
{
	int len=strlen(str);
	int i;
	char temp;
	for(i=len-1;i>0;i--)
	{
		temp=str[i];
		if(!(('0'<=temp&&temp<='9')||('a'<=temp&&temp<='z')||temp=='_'||('A'<=temp&&temp<='Z')))
			str[i]='\0';
	}
}
int main()
{
	
	int cnt,i,j;
	FILE *data=fopen("..\\data\\userdata.dat","rt");
	char str[80];
	int ans=0,flag=0;
	
	if(data==NULL) exit(0);
	
	rewind(data);
	fgets(str,80,data);
	change(str);
	cnt=atoi(str);
	
	for(i=0;i<cnt;i++)
	{
		for(int j=0;j<10;j++)
		{
			fgets(str,80,data);
			change(str);
			puts(str);
		}
	}
	return 0;
}
