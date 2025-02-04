#include <allfunc.h>

void page191(int *idx)
{
	struct bottom b1,b2,b3;
	int flag=0;
	
	draw_bg(0);
	/*
说明
根据学校电动自行车实名登记管理工作方案，每人仅可登记一辆电动自行车。
若因特殊原因确需登记第二辆电动自行车的，请直接致电保卫处咨询。
咨询电话：87543764
	*/ 
	
	draw_str(0.5,0.25,0xffff,"说明");
	draw_str(0.5,0.35,0xffff,"根据学校电动自行车实名登记管理工");
	draw_str(0.5,0.40,0xffff,"作方案，每人仅可登记一辆电动自行");
	draw_str(0.5,0.45,0xffff,"车。若因特殊原因确需登记第二辆电");
	draw_str(0.5,0.50,0xffff,"动自行车的，请前往保卫处咨询。");
    
    b1=draw_bottom(0.15,0.05,0x1234,"返回上一级");
    b2=draw_bottom(0.35,0.75,0x1234,"上一步");
    b3=draw_bottom(0.65,0.75,0xe000,"下一步");  
    
    update_mouse(&mouse);
    
    while(!flag)   
	{
		mouse_show(&mouse);	
		if(click(&b1)) flag=102;
		else if(click(&b2)) flag=190;
		else if(click(&b3)) flag=105;
	}
	*idx=flag;
}
