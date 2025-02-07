#include <allfunc.h>

static int check_phone(char*s);

void page106(int *idx)
{
    struct bottom b1, b2, b3;
    struct textbox t1, t2, t3;
    struct str s;
    struct admin p = {0};
    int flag = 0, t = 0;

    draw_bg(0);

    draw_str(0.5, 0.17, 0xffff, "����Աע��");
    draw_str(0.3, 0.30, 0xffff, "�û�����");
    draw_str(0.3, 0.45, 0xffff, "���룺");
    draw_str(0.3, 0.6, 0xffff, "��ϵ��ʽ��");
    

    t1 = draw_textbox(0.52, 0.3, 0x3456, 5);  
    t2 = draw_textbox(0.52, 0.45, 0x3456, 5);   
    t3 = draw_textbox(0.52, 0.6, 0x3456, 5);  

    b1 = draw_bottom(0.15, 0.05, 0x1234, "������һ��");
    b2 = draw_bottom(0.85, 0.05, 0x1234, "ǰ����¼");
    b3 = draw_bottom(0.5, 0.8, 0xe000, "���ע��");

    update_mouse(&mouse);

    while (!flag)
    {
        mouse_show(&mouse);
        input(&t1);
        input(&t2);
        input(&t3);

        if (click(&b1)) flag = 102; // ������һ��
        else if (click(&b2)) flag = 104; // ǰ����¼
        else if (click(&b3))  // ���ע��
        {
            hide_str(s);

            strcpy(p.username, t1.str);
            strcpy(p.password, t2.str);
            strcpy(p.phone, t3.str);

            if (strlen(p.username) == 0)
                s = draw_str(0.52, 0.38, 0xe000, "�û�������Ϊ��");
            else if (strlen(p.password) == 0)
                s = draw_str(0.52, 0.53, 0xe000, "���벻��Ϊ��");
            else if (strlen(p.phone) == 0)
                s = draw_str(0.52, 0.68, 0xe000, "��ϵ��ʽ����Ϊ��");
            else if(check_phone(p.phone)==0)
				s = draw_str(0.52,0.68,0xe000,"����ȷ��д��ϵ�绰");
			else if(strlen(p.phone)!=11)
				s = draw_str(0.50,0.68,0xe000,"����д�й���½ʮһλ�ֻ���");
            else
            {
                t = find_admin_list(p);
                if (t == -1) exit(0);
                else if (t > 0)
                    s = draw_str(0.52, 0.38, 0xe000, "�û����Ѵ���");
                else
                {
                    t = add_admin_list(p);
                    if (t == 1) s=draw_str(0.75,0.8,0x2345,"ע��ɹ�");
                }
            }
        }
    }

    *idx = flag;
}

static int check_phone(char*s)
{
	int i;
	for(i=0;i<strlen(s);i++)
		if(s[i]>'9' || s[i]<'0') return 0;
	return 1;
}
