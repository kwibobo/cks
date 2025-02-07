#include <allfunc.h>

void page111(int *idx)
{
    struct bottom b1, b2, b3;
    struct textbox t1, t2, t3, t4;
    struct str s;
    struct admin p = {0};
    char temp[20];
    int flag = 0, t = 0;

    draw_bg(0);

    draw_str(0.5, 0.12, 0xffff, "创建新密码");
    draw_str(0.3, 0.25, 0xffff, "用户名：");
    draw_str(0.3, 0.4, 0xffff, "联系方式：");
    draw_str(0.3, 0.55, 0xffff, "新密码：");
    draw_str(0.3, 0.7, 0xffff, "确认密码：");

    t1 = draw_textbox(0.52, 0.25, 0x3456, 5);  
    t2 = draw_textbox(0.52, 0.4, 0x3456, 5);
    t3= draw_textbox(0.52, 0.55, 0x3456, 5);  
    t4 = draw_textbox(0.52, 0.7, 0x3456, 5);   

    b1 = draw_bottom(0.15, 0.05, 0x1234, "返回上一级");
    b2 = draw_bottom(0.85, 0.05, 0x1234, "前往登录");
    b3 = draw_bottom(0.5, 0.85, 0xe000, "完成");

    update_mouse(&mouse);

    while (!flag)
    {
        mouse_show(&mouse);
        input(&t1);
        input(&t2);
        input(&t3);
        input(&t4);

        if (click(&b1)) flag = 104; // 返回上一级
        else if (click(&b2)) flag = 104; // 前往登录
        else if (click(&b3))  // 完成
        {
            hide_str(s);

            strcpy(p.username, t1.str);
            strcpy(p.phone, t2.str);
            strcpy(p.password, t3.str);
            strcpy(temp, t4.str);

            if (strlen(p.username) == 0)
                s = draw_str(0.52, 0.33, 0xe000, "用户名不存在");
            else if (strlen(p.phone) == 0)
                s = draw_str(0.52, 0.48, 0xe000, "联系方式不能为空");
            else if (strlen(p.password) == 0)
                s = draw_str(0.52, 0.63, 0xe000, "密码不能为空");
            else if (strcmp(p.password, temp))
                s = draw_str(0.52, 0.78, 0xe000, "两次密码不一致");
            else
            {
                t = find_admin_code(p);
                if (t == 1) 
                    s = draw_str(0.52, 0.48, 0xe000, "联系方式错误");
                else if (t == 2) 
                {
                    t = change_admin_code(p);
                    if(t == 2) s=draw_str(0.5, 0.95, 0x2345, "新密码创建成功");
                }
                else 
                {
                   s = draw_str(0.52, 0.33, 0xe000, "用户名不存在");
                }
            }
        }
    }

    *idx = flag;
}
