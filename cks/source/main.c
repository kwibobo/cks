#include <allfunc.h>

void main()
{        
	int idx=100; 
    SetSVGA64k();//启动SVGA画图界面

    mouse_init();
    
//    mouse_on(mouse);
    
	while(idx>0)   
	{
		mouse_show(&mouse);
		switch(idx)
		{
			case 100:
			{
				mouse_off(&mouse);
				page100(&idx);
				break;
			}
			case 101:
			{
				mouse_off(&mouse);
				page101(&idx);
				break;
			}
			case 102:
			{
				mouse_off(&mouse);
				page102(&idx);
				break;
			}
			case 103:
			{
				mouse_off(&mouse);
				page103(&idx);
				break;
			}
			case 104:
			{
				mouse_off(&mouse);
				page104(&idx);
				break;
			}
		}
	}
	CloseSVGA();//关闭图形界面 
}
