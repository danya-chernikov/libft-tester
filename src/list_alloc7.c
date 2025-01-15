#include "../include/list.h"

char	*alloc_string(char *val)
{
	return (strndup(val, MAX_TEST_STR_LEN));
}
