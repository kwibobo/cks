#include <allfunc.h>

void pageset1(int *idx)
{        
	switch(*idx)
	{
		case 100:                 //主页面
		{
			mouse_off(&mouse);
			page100(idx);
			break;
		}
		case 101:                 //登录页面
		{
			mouse_off(&mouse);
			page101(idx);
			break;
		}
		case 102:                 //注册页面
		{
			mouse_off(&mouse);
			page102(idx);
			break;
		}
		case 103:                 //用户登录
		{
			mouse_off(&mouse);
			page103(idx);
			break;
		}
		case 104:                 //管理员登录
		{
			mouse_off(&mouse);
			page104(idx);
			break;
		}
		case 105:                 //用户注册
		{
			mouse_off(&mouse);
			page105(idx);
			break;
		}
		case 106:                 //管理员注册
		{
			mouse_off(&mouse);
			page106(idx);
			break;
		}
		case 110:                 //用户创建新密码
		{
			mouse_off(&mouse);
			page110(idx);
			break;
		}
		case 111:                 //管理员创建新密码
		{
			mouse_off(&mouse);
			page111(idx);
			break;
		}
		case 190:                 //承诺书
		{
			mouse_off(&mouse);
			page190(idx);
			break;
		}
		case 191:                 //说明
		{
			mouse_off(&mouse);
			page191(idx);
			break;
		}
	}
}
