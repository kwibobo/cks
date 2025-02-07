#include <allfunc.h>

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

/*
1 注册成功
2 修改成功 
*/
int add_user_list(struct user p)
{
	int cnt,i,j;
	FILE *data=fopen("data\\userdata.dat","rt");
	FILE *temp=fopen("data\\temp.dat","wt");
	char str[80];
	int flag=1,ans=-1;
	if(data==NULL) return -1;
	rewind(data);
	rewind(temp);
	fgets(str,80,data);
	fputs("\n",temp);
	cnt=atoi(str);
	
	for(i=0;i<cnt;i++)
	{
		flag=1;
		for(j=0;j<10;j++)
		{
			fgets(str,80,data);
			change(str);
			if(j==0)
				flag&=(strcmp(str,p.username)==0);
			else if(j==1)
			{
				flag&=(strcmp(str,p.password)==0);
				if(flag)
				{
					strcpy(str,p.password);
					ans=2;
				}
			}
			fputs(str,temp);
			fputs("\n",temp);
		}
	}
	if(ans==-1)
	{
		fputs(p.username,temp);
		fputs("\n",temp);
		fputs(p.password,temp);
		fputs("\n",temp);
		fputs(p.id,temp);
		fputs("\n",temp);
		fputs(p.phone,temp);
		fputs("\n",temp);
		fputs(p.a.id,temp);
		fputs("\n",temp);
		fputs(p.a.p,temp);
		fputs("\n",temp);
		fputs(p.a.loc,temp);
		fputs("\n",temp);
		fputs(p.a.col,temp);
		fputs("\n",temp);
		fputs(p.a.time,temp);
		fputs("\n",temp);
		fputs(p.a.lid,temp);
		fputs("\n",temp);
		rewind(temp);
		to_string(cnt+1,str);
		fputs(str,temp);
		ans=1;
	}
	else
	{
		rewind(temp);
		to_string(cnt,str);
		fputs(str,temp);
	}
	fclose(data);
	fclose(temp);
	remove("data\\userdata.dat");
	rename("data\\temp.dat","data\\userdata.dat");
	return ans;
}

int add_admin_list(struct admin p)
{
	int cnt,i,j;
	FILE *data=fopen("data\\admin.dat","rt");
    FILE *temp=fopen("data\\temp.dat","wt");
	char str[80];
	int flag=1,ans=-1;
	if(data==NULL) return -1;
	rewind(data);
	rewind(temp);
	fgets(str,80,data);
	fputs("\n",temp);
	cnt=atoi(str);

	for(i=0;i<cnt;i++)
	{
		flag=1;
		for(j=0;j<3;j++)
		{
			fgets(str,80,data);
			change(str);
			if(j==0)
				flag&=(strcmp(str,p.username)==0);
			else if(j==1)
			{
				flag&=(strcmp(str,p.password)==0);
				if(flag)
				{
					strcpy(str,p.password);
					ans=2;
				}
			}
			fputs(str,temp);
			fputs("\n",temp);
		}
	}
	if(ans==-1)
	{
		fputs(p.username,temp);
		fputs("\n",temp);
		fputs(p.password,temp);
		fputs("\n",temp);
		fputs(p.phone,temp);
		fputs("\n",temp);
		rewind(temp);
		to_string(cnt+1,str);
		fputs(str,temp);
		ans=1;
	}
	else
	{
		rewind(temp);
		to_string(cnt,str);
		fputs(str,temp);
	}
	fclose(data);
	fclose(temp);
	remove("data\\admin.dat");
	rename("data\\temp.dat","data\\admin.dat");
	return ans;
}
/*
-1 出错 
0 未找到
1 找到但是密码不对
2 正确配对 
*/
int find_user_list(struct user p)
{
	int cnt,i,j;
	FILE *data=fopen("data\\userdata.dat","rt");
	char str[80];
	int ans=0,flag=0;
	
	if(data==NULL) return -1;
	
	rewind(data);
	fgets(str,80,data);
	change(str);
	cnt=atoi(str);
	if(cnt==0) return 0;
	for(i=0;i<cnt;i++)
	{
		flag=0;
		for(j=0;j<10;j++)
		{
			fgets(str,80,data);
			change(str);
			if(j==0 && (strcmp(str,p.username)==0))
				flag=1,ans=1;
			else if(j==1 && (strcmp(str,p.password)==0) && flag==1)
			{
				fclose(data);
				return 2;
			}
		}
	}
	
	fclose(data);
	
	return ans;
}

int find_admin_list(struct admin p)
{
	int cnt,i,j;
	FILE *data=fopen("data\\admin.dat","rt");
	char str[80];
	int ans=0,flag=0;
	
	if(data==NULL) return -1;
	
	rewind(data);
	fgets(str,80,data);
	change(str);
	cnt=atoi(str);
	if(cnt==0) return 0;
	for(i=0;i<cnt;i++)
	{
		flag=0;
		for(j=0;j<3;j++)
		{
			fgets(str,80,data);
			change(str);
			if(j==0 && (strcmp(str,p.username)==0))
				flag=1,ans=1;
			else if(j==1 && (strcmp(str,p.password)==0) && flag==1)
			{
				fclose(data);
				return 2;
			}
		}
	}
	
	fclose(data);
	
	return ans;
}
/*
-1 出错 
0 未找到
1 找到但是联系方式不对
2 正确配对 
*/
int find_user_code(struct user p)
{
    int cnt, i, j;
    FILE *data = fopen("data\\userdata.dat", "rt");
    char str[80];
    int flag = 1, ans = 0;

    if (data == NULL) return -1;

    rewind(data);
    fgets(str, 80, data);  
    change(str);
    cnt = atoi(str);
    if (cnt == 0) return 0;

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

    fclose(data);
    return ans;  
}
int find_admin_code(struct admin p)
{
    int cnt, i;
    FILE *data = fopen("data\\admin.dat", "rt");
    char str[80];
    int ans = 0;

    if (data == NULL) return -1;

    rewind(data);
    fgets(str, 80, data);  
    change(str);
    cnt = atoi(str);
    if (cnt == 0) return 0;

    for (i = 0; i < cnt; i++)
    {
        char username[80], phone[80];

        fgets(username, 80, data); // 读取用户名
        change(username);
        fgets(str, 80, data);    
        fgets(phone, 80, data); // 读取联系方式
        change(phone);  

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

    fclose(data);
    return ans;  
}

int change_user_code(struct user p)
{
    int cnt, i, j;
    FILE *data = fopen("data\\userdata.dat", "rt");
    FILE *temp = fopen("data\\temp.dat", "wt");
    char str[80];
    int flag = 0, ans = -1; 
    if (data == NULL) return -1; 

    rewind(data);
    rewind(temp);

    fgets(str, 80, data);
	fputs("\n",temp);
    change(str);
    cnt = atoi(str);

    for (i = 0; i < cnt; i++)
    {
        flag = 1; 
        for (j = 0; j < 10; j++)
        {
            fgets(str, 80, data);
            change(str);

            if (j == 0) 
                flag&=(strcmp(str, p.username) == 0);
            else if (j == 1) 
            {
                if (flag)
                {
                    strcpy(str, p.password); 
                    ans = 2;  // 标记密码修改成功
                }
            }
            fputs(str, temp);
            fputs("\n", temp);
        }
    }

    rewind(temp);
    to_string(cnt, str); 
    fputs(str, temp);

    fclose(data);
    fclose(temp);
    remove("data\\userdata.dat");
    rename("data\\temp.dat", "data\\userdata.dat");

    return ans; 
}
int change_admin_code(struct admin p)
{
    int cnt, i, j;
    FILE *data = fopen("data\\admin.dat", "rt");
    FILE *temp = fopen("data\\temp.dat", "wt");
    char str[80];
    int flag = 0, ans = -1; 
    if (data == NULL) return -1; 

    rewind(data);
    rewind(temp);

    fgets(str, 80, data);
	fputs("\n",temp);
    change(str);
    cnt = atoi(str);

    for (i = 0; i < cnt; i++)
    {
        flag = 1; 
        for (j = 0; j < 3; j++)
        {
            fgets(str, 80, data);
            change(str);

            if (j == 0) 
                flag&=(strcmp(str, p.username) == 0);
            else if (j == 1) 
            {
                if (flag)
                {
                    strcpy(str, p.password); 
                    ans = 2;  // 标记密码修改成功
                }
            }
            fputs(str, temp);
            fputs("\n", temp);
        }
    }

    rewind(temp);
    to_string(cnt, str); 
    fputs(str, temp);

    fclose(data);
    fclose(temp);
    remove("data\\admin.dat");
    rename("data\\temp.dat", "data\\admin.dat");

    return ans; 
}


