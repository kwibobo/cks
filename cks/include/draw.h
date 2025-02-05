#ifndef _DRAW_H_
#define _DRAW_H_

struct str
{
	int x1,y1,x2,y2;
	char str[80];
	int flag,len,col;
};

struct bottom
{
	int x1,y1,x2,y2;
	int len,col;
	char str[80];
	int flag;
};

struct textbox
{
	int x1,y1,x2,y2;
	int col,len;
	char str[80];
};

struct selectbox
{
	int x1,y1,x2,y2;
	int col,len;
	char str[20][10];
	int cnt,p;
	struct bottom l,r;
}; 


void draw_bg(int col);

struct str draw_str(float px,float py,int col,char* str);

void hide_str(struct str b);

void show_str(struct str b);

struct textbox draw_textbox(float px,float py,int col,int len);

struct bottom draw_bottom(float px,float py,int col,char* str);

struct selectbox draw_selectbox(float px,float py,int col,int len,char *str);

int click(struct bottom *b);

int to_len(int x);

int input(struct textbox *b);

int choose(struct selectbox *b);


#endif
