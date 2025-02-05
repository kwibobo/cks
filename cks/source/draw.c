#include <allfunc.h>
#include <stdio.h>
#include <conio.h>

void draw_bg(int col)
{
	if(col==0) col=0x5678;
	bar1(0,0,MX_W,MX_H,col);
}

struct str draw_str(float px,float py,int col,char* str)
{
	int x=px*MX_W,y=py*MX_H;
	int len=strlen(str)/2;
	int w=len*MX_W/36,h=MX_H/27;
	int x1=x-w,x2=x+w,y1=y-h,y2=y+h;
	
	struct str b={0};
	b.x1=x1,b.x2=x2,b.y1=y1,b.y2=y2;
	b.flag=1,b.len=len,b.col=col;
	strcpy(b.str,str);
	
	prt_hz16_size(x1+13*len, y1+12, 2, 2, str, col, "HZK\\HZK16s");
	
	return b;
}

void hide_str(struct str b)
{
	bar1(b.x1+11*b.len,b.y1+10,b.x2-11*b.len,b.y2-10,0x5678);
	b.flag=0;
}

void show_str(struct str b)
{
	prt_hz16_size(b.x1+13*b.len, b.y1+12, 2, 2, b.str, b.col, "HZK\\HZK16s");
	b.flag=1;
}
struct textbox draw_textbox(float px,float py,int col,int len)
{
	int x=px*MX_W,y=py*MX_H;
	int w=len*MX_W/36,h=MX_H/27;
	int x1=x-w,x2=x+w,y1=y-h,y2=y+h;
	
	struct textbox b={0};
	b.x1=x1,b.x2=x2,b.y1=y1,b.y2=y2;
	b.len=len;
	b.col=col;
	
	Line_Thick(x2+2,y1,x2+2,y2+2,1,0xffff);
	Line_Thick(x1+1,y2+2,x2+1,y2+2,1,0xffff);
	
	bar1(x1,y1,x2,y2,col);
	bar1(x1,y1,x2,y2,col);
	
	return b;
}

void show_textbox(struct textbox b)
{
	int x1=b.x1,x2=b.x2,y1=b.y1,y2=b.y2;
	int col=b.col;
	
	Line_Thick(x2+2,y1,x2+2,y2+2,1,0xffff);
	Line_Thick(x1+1,y2+2,x2+1,y2+2,1,0xffff);
	
	bar1(x1,y1,x2,y2,col);
	bar1(x1,y1,x2,y2,col);
	
	/*
		void put_asc16_size(int cx,int cy,int xsize,int ysize,char *s,unsigned int color );
	*/
	put_asc16_size(x1+8,y1+12,2,2,b.str,0xffff);
}


struct bottom draw_bottom(float px,float py,int col,char* str)
{	
	int x=px*MX_W,y=py*MX_H;
	int len=strlen(str)/2;
	int w=len*MX_W/36,h=MX_H/27;
	int x1=x-w,x2=x+w,y1=y-h,y2=y+h;
	char ts[80];
	
	struct bottom b={0};
	b.x1=x1,b.x2=x2,b.y1=y1,b.y2=y2,b.len=len;
	b.col=col;
	b.flag=0;
	strcpy(b.str,str);
	
	Line_Thick(x1-2,y1-2,x1-2,y2+2,1,0xffff);
	Line_Thick(x2+2,y1-2,x2+2,y2+2,1,0xffff);
	Line_Thick(x1-2,y1-2,x2+2,y1-2,1,0xffff);
	Line_Thick(x1-2,y2+2,x2+2,y2+2,1,0xffff);
	
	bar1(x1,y1,x2,y2,col);
	if(str[0]=='/' && str[strlen(str)-1]=='/')
	{
		strcpy(ts,str+1);
		strcpy(ts+strlen(ts)-1,"");
		put_asc16_size(x1+13*len, y1+12, 2, 2 , ts,0xffff);
	}	
	else prt_hz16_size(x1+13*len, y1+12, 2, 2, str, 0xffff, "HZK\\HZK16s");
	return b;
}

struct selectbox draw_selectbox(float px,float py,int col,int len,char *str)
{	
	int x=px*MX_W,y=py*MX_H;
	int w=len*MX_W/36,h=MX_H/27;
	int x1=x-w,x2=x+w,y1=y-h,y2=y+h;
	int i,slen;
	char s[80];
	
	struct selectbox b;
	
	b.x1=x1,b.x2=x2,b.y1=y1,b.y2=y2;
	b.len=len;
	b.col=col;
	
	b.l.y1=b.r.y1=y1;
	b.l.y2=b.r.y2=y2;
	b.l.x1=x1;
	b.l.x2=x1+6*len-4;
	b.r.x1=x2-6*len+4;
	b.r.x2=x2;
	b.l.col=b.r.col=col;
	b.l.len=b.r.len=0;
	b.l.flag=b.r.flag=0;
	
	strcpy(b.l.str,"/</");
	strcpy(b.r.str,"/>/");

	b.cnt=b.p=0;
	strcpy(s,str);
	slen=strlen(s);
	for(i=slen-1;i>=0;i--)
		if(s[i]=='/')
		{
			strcpy(b.str[b.cnt++],s+i+1);
			strcpy(s+i,"\0");
		}

	Line_Thick(x1-2,y1-2,x1-2,y2+2,1,0xffff);
	Line_Thick(x2+2,y1-2,x2+2,y2+2,1,0xffff);
	Line_Thick(x1-2,y1-2,x2+2,y1-2,1,0xffff);
	Line_Thick(x1-2,y2+2,x2+2,y2+2,1,0xffff);
	
	Line_Thick(x1+6*len-2,y1-2,x1+6*len-2,y2+2,1,0xffff);
	Line_Thick(x2-6*len+2,y1-2,x2-6*len+2,y2+2,1,0xffff);
	
	bar1(x1+6*len,y1,x2-6*len,y2,col);
	
	bar1(x1,y1,x1+6*len-4,y2,col);
	
	bar1(x2-6*len+4,y1,x2,y2,col);
	
	prt_hz16_size(x1+13*len, y1+12, 2, 2, "请选择", 0xffff, "HZK\\HZK16s");
	put_asc16_size(b.l.x1+2, y1+12, 2, 2 , "<",0xffff);
	put_asc16_size(b.r.x1+2, y1+12, 2, 2, ">",0xffff);
	return b;
}

int click(struct bottom *b)
{
	int x1=b->x1,y1=b->y1,x2=b->x2,y2=b->y2;
	int len=b->len;
	char *str=b->str,ts[80];
	if(mouse_press(x1,y1,x2,y2)>=1 && b->flag==0)
	{
		mouse_off(&mouse);
		bar1(x1,y1,x2,y2,0x4567);
		if(str[0]=='/' && str[strlen(str)-1]=='/')
		{
			strcpy(ts,str+1);
			strcpy(ts+strlen(ts)-1,"");
			put_asc16_size(x1+2+13*len, y1+12, 2, 2 , ts,0xffff);
		}	
		else prt_hz16_size(x1+13*len, y1+12, 2, 2, str, 0xffff, "HZK\\HZK16s");
		update_mouse(&mouse);
		mouse_show(&mouse);
		b->flag=1;
	}
	else if(mouse_press(x1,y1,x2,y2)==0 && b->flag==1)
	{
		mouse_off(&mouse);
		bar1(x1,y1,x2,y2,b->col);
		if(str[0]=='/' && str[strlen(str)-1]=='/')
		{
			strcpy(ts,str+1);
			strcpy(ts+strlen(ts)-1,"");
			put_asc16_size(x1+2+13*len, y1+12, 2, 2 , ts,0xffff);
		}	
		else prt_hz16_size(x1+13*len, y1+12, 2, 2, str, 0xffff, "HZK\\HZK16s");
		update_mouse(&mouse);
		mouse_show(&mouse);
		b->flag=0;
	}
	if(mouse_press(x1,y1,x2,y2)==1)
	{
		while(mouse_press(x1,y1,x2,y2)==1) mouse_show(&mouse);
		return 1;
	}
	else return 0;
}
int to_len(int x)
{
	return 0.4*x*x+0.8*x+1;
//	return 0.3*x*x+1.5*x+0.5;
}
int input(struct textbox *b)
{
	int x1=b->x1,y1=b->y1,x2=b->x2,y2=b->y2;
	int col=b->col,tlen=to_len(b->len);
	int t1=clock(),t2;
	int lst=0,temp,nx;
	int i,j,cnt=strlen(b->str);
	char ch[2]="1\0";
	if(mouse_press(x1,y1,x2,y2)==1)
	{
		while(bioskey(1))					//清空输入缓冲区
		{
			bioskey(0);
		}
		while(1)
		{
			if(!mouse_press(x1,y1,x2,y2) && MouseBut(&mouse))		//如果鼠标点击输入框外的部分，退出
			{
				show_textbox(*b);
				mouse_show(&mouse);
				break;
			}
			
			//鼠标闪烁 
			t2=clock();
			mouse_show(&mouse);
			nx=x1+12+strlen(b->str)*16;
			if(lst==0 && (t2-t1)/9%2==0)
				Line_Thick(nx,y1+6,nx,y2-7,1,0xffff),lst=1;
			else if(lst==1 && (t2-t1)/9%2)
				Line_Thick(nx,y1+6,nx,y2-7,1,col),lst=0;
			
			if (bioskey(1))	//如果有按键按下，则kbhit()函数返回真
			{		
            	temp = bioskey(0)&0x00ff;	//使用getch()函数获取按下的键值
				if(temp!='\r'&&temp!='\n')	//检测输入不为回车键，则继续，否则输入结束
				{
					if((('0'<=temp&&temp<='9')||('a'<=temp&&temp<='z')||temp=='_'||('A'<=temp&&temp<='Z'))&&cnt<tlen)	//检测为数字或字母或下划线，则记录
					{
						ch[0]=temp;
						strcat(b->str,ch);
						cnt++;
					}
					else if(temp=='\b'&&cnt>0)			//检测是否为退格键，是则消除前一个字符
					{
						strcpy(b->str+strlen(b->str)-1,"\0");
						cnt--;
					}
					show_textbox(*b);
					mouse_show(&mouse);
				}
				else
				{
					show_textbox(*b);
					mouse_show(&mouse);
					break;
				}
			}
		}
		return 1;
	}
	return 0;
}
int choose(struct selectbox *b)
{
	int x1=b->x1,x2=b->x2,y1=b->y1,y2=b->y2,cnt=b->cnt,len=b->len,col=b->col;
	if(click(&(b->l)))
	{
		b->p=(b->p+1)%cnt;
		bar1(x1+6*len,y1,x2-6*len,y2,col);	
		prt_hz16_size(x1+13*len, y1+12, 2, 2, b->str[b->p], 0xffff, "HZK\\HZK16s");
		return 1;
	}
	else if(click(&(b->r)))
	{
		b->p=(b->p-1+cnt)%cnt;
		bar1(x1+6*len,y1,x2-6*len,y2,col);	
		prt_hz16_size(x1+13*len, y1+12, 2, 2, b->str[b->p], 0xffff, "HZK\\HZK16s");
		return 1;
	}
	else return 0;

}

