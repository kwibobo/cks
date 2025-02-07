#ifndef _FILEFUNC_H_
#define _FILEFUNC_H_

struct car
{
	char id[20],p[20],time[20];
	char col[20],loc[20];
	char lid[20];
};

struct user
{
	char username[20],password[20];
	char id[20],phone[20];
	struct car a;
};

struct admin
{
	char username[20],password[20];
	char phone[20];
};

char* to_string(int x,char *str);

void change(char*str);

int add_user_list(struct user p);
int find_user_list(struct user p);

int add_admin_list(struct admin p);
int find_admin_list(struct admin p);

int find_user_code(struct user p);
int find_admin_code(struct admin p);

int change_user_code(struct user p);
int change_admin_code(struct admin p);

#endif
