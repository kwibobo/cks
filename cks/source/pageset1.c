#include <allfunc.h>

void pageset1(int *idx)
{        
	switch(*idx)
	{
		case 100:                 //��ҳ��
		{
			mouse_off(&mouse);
			page100(idx);
			break;
		}
		case 101:                 //��¼ҳ��
		{
			mouse_off(&mouse);
			page101(idx);
			break;
		}
		case 102:                 //ע��ҳ��
		{
			mouse_off(&mouse);
			page102(idx);
			break;
		}
		case 103:                 //�û���¼
		{
			mouse_off(&mouse);
			page103(idx);
			break;
		}
		case 104:                 //����Ա��¼
		{
			mouse_off(&mouse);
			page104(idx);
			break;
		}
		case 105:                 //�û�ע��
		{
			mouse_off(&mouse);
			page105(idx);
			break;
		}
		case 106:                 //����Աע��
		{
			mouse_off(&mouse);
			page106(idx);
			break;
		}
		case 110:                 //�û�����������
		{
			mouse_off(&mouse);
			page110(idx);
			break;
		}
		case 111:                 //����Ա����������
		{
			mouse_off(&mouse);
			page111(idx);
			break;
		}
		case 190:                 //��ŵ��
		{
			mouse_off(&mouse);
			page190(idx);
			break;
		}
		case 191:                 //˵��
		{
			mouse_off(&mouse);
			page191(idx);
			break;
		}
	}
}
