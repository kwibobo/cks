#include <allfunc.h>

void page101(int *idx)
{
	struct bottom b1,b2,b3;
	int flag=0;
	
	draw_bg(0);
	
	draw_str(0.5,0.25,0xffff,"��¼");
    b1=draw_bottom(0.35,0.6,0x1234,"�û���¼");
    b2=draw_bottom(0.65,0.6,0x1234,"����Ա��¼");
    b3=draw_bottom(0.15,0.05,0x1234,"������һ��");
    
    update_mouse(&mouse);
    
	while(!flag)   
	{
		mouse_show(&mouse);	
		if(click(b1)) flag=103;
		else if(click(b2)) flag=104;
		else if(click(b3)) flag=100;
	}
	*idx=flag;
}
