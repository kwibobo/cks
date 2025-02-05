#ifndef _FILEFUNC_H_
#define _FILEFUNC_H_

struct car
{
	char id[20],p[20],time[20];
	char lid[20];
};

struct user
{
	char username[20],password[20];
	char id[20],phone[20];
	struct car a;
};

char* to_string(int x,char *str);

void change(char*str);

int add_user_list(struct user p);

int find_user_list(struct user p);

#endif
