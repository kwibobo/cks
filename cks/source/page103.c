#include <allfunc.h>

void page103(int *idx)
{
	struct bottom b1,b2,b3,b4;
	struct textbox t1,t2;
	struct str s1,s2,s3,s4,s5;
	struct user p={0};
	int flag=0,t=0;
	
	draw_bg(0);
	
	draw_str(0.5,0.25,0xffff,"�û���¼");
    draw_str(0.3,0.4,0xffff,"�û�����");
    draw_str(0.3,0.55,0xffff,"���룺");
    
    s1=draw_str(0.5,0.8,0xe000,"�û���δע��");
    s2=draw_str(0.5,0.8,0xe000,"�������");
    s3=draw_str(0.5,0.8,0xe000,"��¼�ɹ�");
    s4=draw_str(0.5,0.8,0xe000,"�û�������Ϊ��");
    s5=draw_str(0.5,0.8,0xe000,"���벻��Ϊ��");
    
    #ifdef HIDE
	#undef HIDE
	#endif 
	
    #define HIDE \
		hide_str(s1),hide_str(s2),hide_str(s3),hide_str(s4),hide_str(s5);
    
	HIDE
    
    t1=draw_textbox(0.6,0.4,0x3456,6);
    t2=draw_textbox(0.6,0.55,0x3456,6);
    
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
			HIDE
			strcpy(p.username,t1.str);
			strcpy(p.password,t2.str);
			if(strlen(p.username)==0)
				show_str(s4);
			else if(strlen(p.password)==0)
				show_str(s5);
			else
			{
				t=find_user_list(p);
				if(t==-1) exit(0); 
				else if(t==0) show_str(s1);
				else if(t==1) show_str(s2);
				else if(t==2) show_str(s3);
			}
		}
		else if(click(&b3)) flag=100;
		else if(click(&b4)) flag=105;
	}
	*idx=flag;
	
	#ifdef HIDE
	#undef HIDE
	#endif 
}
