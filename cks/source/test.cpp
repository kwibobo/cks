#include<bits/stdc++.h>
using namespace std;
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
int check_date(int y,int m,int d)
{
	time_t p;
	struct tm *t;
	int flag=0,a[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int ty,tm,td;
	
	if(y==0 || m==0 || d==0) return 0;
	
	time(&p);
	t=gmtime(&p);
	
	ty=1900+t->tm_year;
	tm=t->tm_mon+1;
	td=t->tm_mday;
	
	if(y>ty) return 0;
	else if(y==ty)
	{
		if(m>tm) return 0;
		else if(m==tm)
		{
			if(d>td) return 0;
		}
	}
	if(y%4==0)
	{
		if(y%100==0)
		{
			if(y%400==0) flag=1;
			else flag=0;
		}
		else flag=1;
	}
	else flag=0;
	a[2]+=flag;
	
	if(y<1900 || m>12 || d>a[m]) return 0;
	return 1;
	
}
int main()
{
	cout<<check_date(2001,1,13);
}

 for (i = 0; i < cnt; i++)
    {
		flag = 1;
		for(j = 0; j < 10; j++)
		{
			fgets(str, 20, data);
			change(str);
			if(j==0)
			    flag&=(strcmp(str,p.username)==0);
			else if(j==3)
			{
				if(flag && (strcmp(str,p.phone)==0))
				{
					fclose(data);
                    return 2; 
				}
				else if(flag){
					ans = 1;
				}
			}
		}
    }
for (i = 0; i < cnt; i++)
    {
        char username[80], phone[80];

        fgets(username, 80, data); // 读取用户名
        change(username);
        fgets(str, 80, data);  
        fgets(str, 80, data);  
        fgets(phone, 80, data); // 读取联系方式
        change(phone);
        fgets(str, 80, data);  
        fgets(str, 80, data);  
        fgets(str, 80, data);  
        fgets(str, 80, data);  

        if (strcmp(username, p.username) == 0)
        {
            if(strcmp(phone, p.phone))
                ans = 1;       
            else{
            fclose(data);
            return 2; 
            }
        }
    }