#include <allfunc.h>

void page191(int *idx)
{
	struct bottom b1,b2,b3;
	int flag=0;
	
	draw_bg(0);
	/*
˵��
����ѧУ�綯���г�ʵ���Ǽǹ�����������ÿ�˽��ɵǼ�һ���綯���г���
��������ԭ��ȷ��Ǽǵڶ����綯���г��ģ���ֱ���µ籣������ѯ��
��ѯ�绰��87543764
	*/ 
	
	draw_str(0.5,0.25,0xffff,"˵��");
	draw_str(0.5,0.35,0xffff,"����ѧУ�綯���г�ʵ���Ǽǹ���");
	draw_str(0.5,0.40,0xffff,"��������ÿ�˽��ɵǼ�һ���綯����");
	draw_str(0.5,0.45,0xffff,"������������ԭ��ȷ��Ǽǵڶ�����");
	draw_str(0.5,0.50,0xffff,"�����г��ģ���ǰ����������ѯ��");
    
    b1=draw_bottom(0.15,0.05,0x1234,"������һ��");
    b2=draw_bottom(0.35,0.75,0x1234,"��һ��");
    b3=draw_bottom(0.65,0.75,0xe000,"��һ��");  
    
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
