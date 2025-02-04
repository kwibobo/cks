#include <allfunc.h>

void page105(int *idx)
{
	struct bottom b1,b2,b3,b4;
	struct textbox t1,t2,t3,t4,t5,t6,t7,t8,t9,t10;
	struct str s1,s2,s3,s4,s5;
	struct user p={0};
	int flag=0,t=0;
	
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
    
//    s1=draw_str(0.5,0.8,0xe000,"用户名未注册");
//    s2=draw_str(0.5,0.8,0xe000,"密码错误");
//    s3=draw_str(0.5,0.8,0xe000,"登录成功");
//    s4=draw_str(0.5,0.8,0xe000,"用户名不能为空");
//    s5=draw_str(0.5,0.8,0xe000,"密码不能为空");
    
//    #ifdef HIDE
//	#undef HIDE
//	#endif 
//	
//    #define HIDE \
//		hide_str(s1),hide_str(s2),hide_str(s3),hide_str(s4),hide_str(s5);
//    
//	HIDE
    
    t1=draw_textbox(0.32,0.2,0x3456,5);
    t2=draw_textbox(0.82,0.2,0x3456,5);
    t3=draw_textbox(0.32,0.35,0x3456,5);
    t4=draw_textbox(0.82,0.35,0x3456,5);
    t5=draw_textbox(0.32,0.5,0x3456,5);
    t6=draw_textbox(0.82,0.5,0x3456,5);
    t7=draw_textbox(0.32,0.65,0x3456,5);
    t8=draw_textbox(0.82,0.65,0x3456,5);
    t9=draw_textbox(0.32,0.8,0x3456,5);
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
		input(&t9);
		input(&t10);
		if(click(&b1)) flag=191;
		else if(click(&b2)) flag=105;
		else if(click(&b3)) flag=100;
		else if(click(&b4)) flag=103; 
	}
	*idx=flag;
	
	#ifdef HIDE
	#undef HIDE
	#endif 
}
