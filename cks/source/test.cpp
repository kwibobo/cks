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
char* to_string(int x,char *str)
{
	char ch[2]="",temp;
	int len,i;
	strcpy(str,"\0");
	if(x==0)
	{
		strcpy(str,"0");
		return str;
	}
	while(x)
	{
		ch[0]=x%10+'0';
		strcat(str,ch);
		x/=10;
	}
	len=strlen(str);
	for(i=0;i<len/2;i++)
	{
		temp=str[i];
		str[i]=str[len-i-1];
		str[len-i-1]=temp;
	}
	return str;
}
int main()
{
	int cnt,i,j;
	FILE *data=fopen("..\\data\\userdata.dat","wt");
	char str[80];
	int flag=1,ans=-1;
	
	rewind(data);
	
	for(i=0;i<1;i++)
	{
		for(j=0;j<10;j++)
		{

			change(str);
			fputs("2",data);
			fputs("\n",data);
		}
	}
	
	fclose(data);
}
