#include "../include/list.h"

/* It accepts the string representing an
 * argument data type, and returns its code */
t_cnt_type	determine_data_type(char *type)
{
	t_cnt_type	res1;
	t_cnt_type	res2;

	res1 = check_numeric_data_types(type);
	if (res1 == INVALID_TYPE)
	{
		res2 = check_non_numeric_data_types(type);
		if (res2 == INVALID_TYPE)
			return (INVALID_TYPE);
		else
			return (res2);
	}
	return (res1);
}

t_cnt_type	check_numeric_data_types(char *type)
{
	if (strcmp(type, AT_SHORT) == 0)
		return (SHORT);
	if (strcmp(type, AT_USHORT) == 0)
		return (U_SHORT);
	if (strcmp(type, AT_INT) == 0)
		return (INT);
	if (strcmp(type, AT_UINT) == 0)
		return (U_INT);
	if (strcmp(type, AT_LONG) == 0)
		return (LONG);
	if (strcmp(type, AT_ULONG) == 0)
		return (U_LONG);
	if (strcmp(type, AT_LONGLONG) == 0)
		return (LONG_LONG);
	if (strcmp(type, AT_ULONGLONG) == 0)
		return (U_LONG_LONG);
	if (strcmp(type, AT_FLOAT) == 0)
		return (FLOAT);
	if (strcmp(type, AT_DOUBLE) == 0)
		return (DOUBLE);
	if (strcmp(type, AT_LONGDOUBLE) == 0)
		return (LONG_DOUBLE);
	return (INVALID_TYPE);
}

t_cnt_type	check_non_numeric_data_types(char *type)
{

	if (strcmp(type, AT_CHAR) == 0)
		return (CHAR);
	if (strcmp(type, AT_UCHAR) == 0)
		return (U_CHAR);
	if (strcmp(type, AT_STRING) == 0)
		return (STRING);
	if (strcmp(type, AT_VOID) == 0)
		return (VOID);
	return (INVALID_TYPE);
}
