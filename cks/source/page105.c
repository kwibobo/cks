#include <allfunc.h>
#include <time.h>

int creat_time(char*yy,char*mm,char*dd,char*str);

int check_date(int y,int m,int d);

int check_phone(char*s);

void page105(int *idx)
{
	struct bottom b1,b2,b3,b4;
	struct textbox t1,t2,t3,t4,t5,t9_1,t9_2,t9_3,t10;
	struct selectbox t6,t7,t8;
	struct str s;
	struct user p={0};
	int flag=0,t=0;
	int ch6=0,ch7=0,ch8=0; 
	char tt[80]={0};
	
	draw_bg(0);
	
	draw_str(0.5,0.1,0xffff,"用户注册");
	
    draw_str(0.1,0.2,0xffff,"用户名：");
    draw_str(0.6,0.2,0xffff,"密码：");
    
    draw_str(0.1,0.35,0xffff,"学号：");
    draw_str(0.6,0.35,0xffff,"联系电话：");
    
    draw_str(0.1,0.5,0xffff,"车牌号：");
    draw_str(0.6,0.5,0xffff,"车辆品牌：");
    
    draw_str(0.1,0.65,0xffff,"本地车辆：");
    draw_str(0.6,0.65,0xffff,"车辆颜色：");
    
    draw_str(0.1,0.8,0xffff,"购买时间：");
    draw_str(0.58,0.8,0xffff,"行驶证编号：");
    
    draw_str(0.295,0.8,0xffff,"年");
    draw_str(0.385,0.8,0xffff,"月");
    draw_str(0.47,0.8,0xffff,"日");
       
    s=draw_str(0.88,0.93,0x2345,"注册成功");
    
    hide_str(s);
    
    t1=draw_textbox(0.32,0.2,0x3456,5);
    t2=draw_textbox(0.82,0.2,0x3456,5);
    
    t3=draw_textbox(0.32,0.35,0x3456,5);
    t4=draw_textbox(0.82,0.35,0x3456,5);
    
    t5=draw_textbox(0.32,0.5,0x3456,5);
    t6=draw_selectbox(0.82,0.5,0x3453,5,"/雅迪/爱玛/九号/凤凰/新日/飞鸽/小刀/绿源/小牛电动/台铃/五羊/其他");
    
    t7=draw_selectbox(0.32,0.65,0x3453,5,"/是/否");
    t8=draw_selectbox(0.82,0.65,0x3453,5,"/红色/橙色/黄色/绿色/蓝色/紫色/黑色/白色/金色/银色/青色/粉色/彩色/其他");
    
    t9_1=draw_textbox(0.225,0.8,0x3456,2);
    t9_2=draw_textbox(0.34,0.8,0x3456,1);
    t9_3=draw_textbox(0.425,0.8,0x3456,1);
    
    t10=draw_textbox(0.82,0.8,0x3456,5);
    
    b1=draw_bottom(0.35,0.95,0x1234,"上一步"); 
    b2=draw_bottom(0.65,0.95,0xe000,"点击注册");
    b3=draw_bottom(0.15,0.05,0x1234,"返回上一级");
    b4=draw_bottom(0.85,0.05,0x1234,"前往登录");
    
    update_mouse(&mouse);
    
	while(!flag)   
	{
		mouse_show(&mouse);		
		input(&t1);
		input(&t2);
		input(&t3);
		input(&t4);
		input(&t5);
		ch6|=choose(&t6);
		ch7|=choose(&t7);
		ch8|=choose(&t8);
		
		input(&t9_1);
		input(&t9_2);
		input(&t9_3);
		input(&t10);
		
		if(click(&b1)) flag=191;
		else if(click(&b2))
		{	
			hide_str(s);
			
			strcpy(p.username,t1.str);
			strcpy(p.password,t2.str);
			strcpy(p.id,t3.str);
			strcpy(p.phone,t4.str);
			strcpy(p.a.id,t5.str);
			strcpy(p.a.p,to_string(t6.p,tt));
			strcpy(p.a.loc,to_string(t7.p,tt));
			strcpy(p.a.col,to_string(t8.p,tt));
			t=creat_time(t9_1.str,t9_2.str,t9_3.str,tt);	
			strcpy(p.a.time,tt);
			strcpy(p.a.lid,t10.str);
			
			if(strlen(p.username)==0)
				s=draw_str(0.32,0.28,0xe000,"用户名不能为空");	
			else if(strlen(p.password)==0)
				s=draw_str(0.82,0.28,0xe000,"密码不能为空");
			else if(strlen(p.id)==0)
				s=draw_str(0.32,0.43,0xe000,"学号不能为空");
			else if(strlen(p.phone)==0)
				s=draw_str(0.82,0.43,0xe000,"联系电话不能为空");
			else if(check_phone(p.phone)==0)
				s=draw_str(0.82,0.43,0xe000,"请正确填写联系电话");
			else if(strlen(p.phone)!=11)
				s=draw_str(0.83,0.43,0xe000,"请填写中国大陆十一位手机号");
			else if(strlen(p.a.id)==0)
				s=draw_str(0.32,0.58,0xe000,"车牌号不能为空");
			else if(ch6==0)
				s=draw_str(0.82,0.58,0xe000,"请选择车辆品牌");
			else if(ch7==0)
				s=draw_str(0.3,0.73,0xe000,"请选择是否为本地车辆");
			else if(ch8==0)
				s=draw_str(0.82,0.73,0xe000,"请选择车辆颜色");	
			else if(t==-1)
				s=draw_str(0.32,0.88,0xe000,"购买时间不能为空");
			else if(t==0)
				s=draw_str(0.32,0.88,0xe000,"请正确填写购买时间");
			else if(strlen(p.a.lid)==0)
				s=draw_str(0.82,0.88,0xe000,"行驶证编号不能为空");
			else
			{
				t=find_user_list(p);
				if(t==-1) exit(0);
				else if(t>0)
					s=draw_str(0.32,0.28,0xe000,"用户名已存在");
				else
				{
					t=add_user_list(p);
					if(t==1) s=draw_str(0.88,0.95,0x2345,"注册成功");
				}
			}
			
					
		}
		else if(click(&b3)) flag=102;
		else if(click(&b4)) flag=103; 
	}
	*idx=flag;
}

int check_phone(char*s)
{
	int i;
	for(i=0;i<strlen(s);i++)
		if(s[i]>'9' || s[i]<'0') return 0;
	return 1;
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

int creat_time(char*yy,char*mm,char*dd,char*str)
{
	int i;
	
	if(strlen(yy)==0 || strlen(mm)==0 || strlen(dd)==0) return -1;
	
	for(i=0;i<strlen(yy);i++)
		if(yy[i]>'9' || yy[i]<'0') return 0;
	for(i=0;i<strlen(mm);i++)
		if(mm[i]>'9' || mm[i]<'0') return 0;
	for(i=0;i<strlen(dd);i++)
		if(dd[i]>'9' || dd[i]<'0') return 0;
		
	if(check_date(atoi(yy),atoi(mm),atoi(dd))==0) return 0;

	strcpy(str,yy);
	if(strlen(mm)==1)
		strcat(str,"0");
	strcat(str,mm);
	if(strlen(dd)==1)
		strcat(str,"0");
	strcat(str,dd);
	
	return 1;
}
