#include <allfunc.h>

void page104(int *idx)
{
	struct bottom b1,b2,b3;
	int flag=0;
	
	draw_bg(0);
	
	draw_str(0.5,0.25,0xffff,"����Ա��¼");
    draw_str(0.3,0.4,0xffff,"�û�����");
    draw_str(0.3,0.55,0xffff,"���룺");
    
    b1=draw_bottom(0.35,0.7,0x1234,"��������"); 
    b2=draw_bottom(0.65,0.7,0x1234,"�����¼");
    b3=draw_bottom(0.15,0.05,0x1234,"������һ��");
    
    update_mouse(&mouse);
    
	while(!flag)   
	{
		mouse_show(&mouse);
		if(click(&b1)) flag=103;
		else if(click(&b2)) flag=104;
		else if(click(&b3)) flag=101;
	}
	*idx=flag;
}
