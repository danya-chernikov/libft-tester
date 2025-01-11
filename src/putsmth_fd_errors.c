#include "../include/libft_tester.h"
#include "../include/putsmth_fd.h"

void	form_common_err_msg(char *buf, t_char_c *fname, t_char_c *msg)
{
	strncpy(buf, fname, MAX_ERR_BUF_SIZE);
	strncat(buf, "_test(): ", MAX_ERR_BUF_SIZE);
	strncat(buf, msg, MAX_ERR_BUF_SIZE);
}

void	form_common_file_err_msg(char *buf, t_char_c *fname, t_char_c *msg)
{
	strncpy(buf, fname, MAX_ERR_BUF_SIZE);
	strncat(buf, "_test(): ", MAX_ERR_BUF_SIZE);
	strncat(buf, msg, MAX_ERR_BUF_SIZE);
	strncat(buf, " ", MAX_ERR_BUF_SIZE);
	strncat(buf, TEMP_FILE_NAME, MAX_ERR_BUF_SIZE);
}
