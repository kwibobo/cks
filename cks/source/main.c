#include <allfunc.h>

void main()
{        
	int idx=100; 
    SetSVGA64k();//����SVGA��ͼ����

    mouse_init();
    
//    mouse_on(mouse);
    
	while(idx>0)   
	{
		mouse_show(&mouse);
		switch(idx/100)
		{
			case 1:
			{
				pageset1(&idx);
				break;
			}
//			case 2:
//			{
//				pageset2(&idx);
//				break;
//			}
//			case 3:
//			{
//				pageset3(&idx);
//				break;
//			}
		}
	}
	CloseSVGA();//�ر�ͼ�ν��� 
}
