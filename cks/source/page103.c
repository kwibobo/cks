#include <allfunc.h>

void page103(int *idx)
{
	struct bottom b1,b2,b3;
	struct textbox t1,t2;
	int flag=0;
	
	draw_bg(0);
	
	draw_str(0.5,0.25,0xffff,"用户登录");
    draw_str(0.3,0.4,0xffff,"用户名：");
    draw_str(0.3,0.55,0xffff,"密码：");
    
    t1=draw_textbox(0.6,0.4,0x3456,6);
    t2=draw_textbox(0.6,0.55,0x3456,6);
    
    b1=draw_bottom(0.35,0.7,0x1234,"忘记密码"); 
    b2=draw_bottom(0.65,0.7,0x1234,"点击登录");
    b3=draw_bottom(0.15,0.05,0x1234,"返回上一级");
    
    update_mouse(&mouse);
    
	while(!flag)   
	{
		mouse_show(&mouse);
		if(click(b1)) flag=103;
		else if(click(b2)) flag=104;
		else if(click(b3)) flag=101;
		else if(input(&t1)) ;
		else if(input(&t2)) ;
	}
	*idx=flag;
}
