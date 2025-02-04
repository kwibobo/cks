#include <allfunc.h>

void pageset1(int *idx)
{        
	switch(*idx)
	{
		case 100:
		{
			mouse_off(&mouse);
			page100(idx);
			break;
		}
		case 101:
		{
			mouse_off(&mouse);
			page101(idx);
			break;
		}
		case 102:
		{
			mouse_off(&mouse);
			page102(idx);
			break;
		}
		case 103:
		{
			mouse_off(&mouse);
			page103(idx);
			break;
		}
		case 104:
		{
			mouse_off(&mouse);
			page104(idx);
			break;
		}
		case 105:
		{
			mouse_off(&mouse);
			page105(idx);
			break;
		}
		
		case 190:
		{
			mouse_off(&mouse);
			page190(idx);
			break;
		}
		case 191:
		{
			mouse_off(&mouse);
			page191(idx);
			break;
		}
	}
}
