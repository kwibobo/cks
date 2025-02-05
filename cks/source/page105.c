#include <allfunc.h>

void creat_time(char*yy,char*mm,char*dd,char*str);

void page105(int *idx)
{
	struct bottom b1,b2,b3,b4;
	struct textbox t1,t2,t3,t4,t5,t6,t7,t8,t9_1,t9_2,t9_3,t10;
	struct str s1,s2,s3,s4,s5;
	struct user p={0};
	int flag=0,t=0;
	char tt[80]={0};
	
	draw_bg(0);
	
	draw_str(0.5,0.1,0xffff,"用户注册");
    draw_str(0.1,0.2,0xffff,"用户名：");
    draw_str(0.6,0.2,0xffff,"密码：");
    draw_str(0.1,0.35,0xffff,"姓名：");
    draw_str(0.6,0.35,0xffff,"院系：");
    draw_str(0.1,0.5,0xffff,"学号：");
    draw_str(0.6,0.5,0xffff,"联系电话：");
    draw_str(0.1,0.65,0xffff,"车牌号：");
    draw_str(0.6,0.65,0xffff,"车辆品牌：");
    draw_str(0.1,0.8,0xffff,"购买时间：");
    draw_str(0.58,0.8,0xffff,"行驶证编号：");
    
    draw_str(0.295,0.8,0xffff,"年");
    draw_str(0.385,0.8,0xffff,"月");
    draw_str(0.47,0.8,0xffff,"日");
    
    s1=draw_str(0.9,0.9,0xe000,"注册成功");
    s2=draw_str(0.9,0.9,0xe000,"用户名已存在");
    
    #ifdef HIDE
	#undef HIDE
	#endif 
	
    #define HIDE \
		hide_str(s1),hide_str(s2);
    
	HIDE
    
    t1=draw_textbox(0.32,0.2,0x3456,5);
    t2=draw_textbox(0.82,0.2,0x3456,5);
    t3=draw_textbox(0.32,0.35,0x3456,5);
    t4=draw_textbox(0.82,0.35,0x3456,5);
    t5=draw_textbox(0.32,0.5,0x3456,5);
    t6=draw_textbox(0.82,0.5,0x3456,5);
    t7=draw_textbox(0.32,0.65,0x3456,5);
    t8=draw_textbox(0.82,0.65,0x3456,5);
    
    t9_1=draw_textbox(0.225,0.8,0x3456,2);
    t9_2=draw_textbox(0.34,0.8,0x3456,1);
    t9_3=draw_textbox(0.425,0.8,0x3456,1);
    
    t10=draw_textbox(0.82,0.8,0x3456,5);
    
    b1=draw_bottom(0.35,0.92,0x1234,"上一步"); 
    b2=draw_bottom(0.65,0.92,0xe000,"点击注册");
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
		input(&t6);
		input(&t7);
		input(&t8);
		input(&t9_1);
		input(&t9_2);
		input(&t9_3);
		input(&t10);
		if(click(&b1)) flag=191;
		else if(click(&b2))
		{	
			HIDE	
			creat_time(t9_1.str,t9_2.str,t9_3.str,tt);
			
			strcpy(p.username,t1.str);
			strcpy(p.password,t2.str);
			strcpy(p.name,t3.str);
			strcpy(p.school,t4.str);
			strcpy(p.id,t5.str);
			strcpy(p.phone,t6.str);
			strcpy(p.a.id,t7.str);
			strcpy(p.a.p,t8.str);		
			strcpy(p.a.time,tt);
			strcpy(p.a.lid,t10.str);
			t=find_user_list(p);
			if(t==-1) exit(0);
			else if(t>0)
				show_str(s2);
			else
			{
				t=add_user_list(p);
				if(t==1) show_str(s1);
			}		
		}
		else if(click(&b3)) flag=105;
		else if(click(&b4)) flag=103; 
	}
	*idx=flag;
	
	#ifdef HIDE
	#undef HIDE
	#endif 
}

void creat_time(char*yy,char*mm,char*dd,char*str)
{
	strcpy(str,yy);
	strcat(str,mm);
	strcat(str,dd);
}
