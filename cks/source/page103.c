#include <allfunc.h>

void page103(int *idx)
{
	struct bottom b1,b2,b3,b4;
	struct textbox t1,t2;
	struct str s;
	struct user p={0};
	int flag=0,t=0;
	
	draw_bg(0);
	
	draw_str(0.5,0.25,0xffff,"�û���¼");
    draw_str(0.3,0.4,0xffff,"�û�����");
    draw_str(0.3,0.55,0xffff,"���룺");
    
    s=draw_str(0.5,0.8,0x2345,"��¼�ɹ�");
    
    hide_str(s); 
    
    t1=draw_textbox(0.55,0.4,0x3456,6);
    t2=draw_textbox(0.55,0.55,0x3456,6);
    
    b1=draw_bottom(0.35,0.7,0x1234,"��������"); 
    b2=draw_bottom(0.65,0.7,0xe000,"�����¼");
    b3=draw_bottom(0.15,0.05,0x1234,"������һ��");
    b4=draw_bottom(0.85,0.05,0x1234,"ǰ��ע��");
    
    update_mouse(&mouse);
    
	while(!flag)   
	{
		mouse_show(&mouse);
		
		input(&t1);
		input(&t2);
		
		if(click(&b1)) flag=103;
		else if(click(&b2))
		{
			hide_str(s);
			strcpy(p.username,t1.str);
			strcpy(p.password,t2.str);
			
			if(strlen(p.username)==0)
				s=draw_str(0.5,0.48,0xe000,"�û�������Ϊ��");
			else if(strlen(p.password)==0)
				s=draw_str(0.5,0.63,0xe000,"���벻��Ϊ��");
			else
			{
				t=find_user_list(p);
				if(t==-1) exit(0); 
				else if(t==0) s=draw_str(0.5,0.48,0xe000,"�û���δע��");
				else if(t==1) s=draw_str(0.5,0.63,0xe000,"�������");
				else if(t==2) s=draw_str(0.5,0.8,0x2345,"��¼�ɹ�");
			}
		}
		else if(click(&b3)) flag=100;
		else if(click(&b4)) flag=105;
	}
	*idx=flag;
}
