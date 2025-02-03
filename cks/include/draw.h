#ifndef _DRAW_H_
#define _DRAW_H_

struct bottom
{
	int x1,y1,x2,y2;
};
struct textbox
{
	int x1,y1,x2,y2;
	int col;
	char str[20];
};


void draw_bg(int col);

void draw_str(float px,float py,int col,char* str);

struct textbox draw_textbox(float px,float py,int col,int len);

struct bottom draw_bottom(float px,float py,int col,char* str);

int click(struct bottom b);

int input(struct textbox *b);


#endif
