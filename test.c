#include <stdio.h>

typedef enum list_cnt_type
{
	CHAR,
	U_CHAR,
	SHORT,
	U_SHORT,
	INT,
	U_INT,
	LONG,
	U_LONG,
	LONG_LONG,
	U_LONG_LONG,
	FLOAT,
	DOUBLE,
	LONG_DOUBLE,
	STRING,
	VOID
}	t_cnt_type;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct list_debug
{
    t_cnt_type  *types;
    t_list      *head;
    int         type_cnt;
} t_list_debug;

int main()
{
	t_list_debug my_list;
	t_list_debug *my_list_ptr = &my_list;
	t_list **head_address = &my_list_ptr->head;
}
