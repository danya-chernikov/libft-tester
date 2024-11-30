#include "../include/libft_tester.h"
#include "../include/putsmth_fd.h"

void	form_read_temp_file_err_msg(t_char_c *fname, char *buf)
{
	strlcpy(buf, fname, MAX_ERR_BUF_SIZE);
	strlcat(buf, "_test(): ", MAX_ERR_BUF_SIZE);
	strlcat(buf, FILE_READ_ERR_MSG, MAX_ERR_BUF_SIZE);
	strlcat(buf, " ", MAX_ERR_BUF_SIZE);
	strlcat(buf, TEMP_FILE_NAME, MAX_ERR_BUF_SIZE);
}
