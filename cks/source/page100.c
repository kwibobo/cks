#include <allfunc.h>

void page100(int *idx)
{
	struct bottom b1,b2,b3;
	int flag=0;
	
	draw_bg(0);
	
	draw_str(0.5,0.25,0xffff,"华中科技大学电动车管理系统");
    b1=draw_bottom(0.35,0.6,0x1234,"登录");
    b2=draw_bottom(0.65,0.6,0x1234,"注册");
    b3=draw_bottom(0.15,0.05,0x1234,"退出系统");
    
    update_mouse(&mouse);
    
	while(!flag)   
	{
		mouse_show(&mouse);	
		if(click(&b1)) flag=101;
		else if(click(&b2)) flag=102;
		else if(click(&b3)) flag=-1;
	}
	*idx=flag;
}
