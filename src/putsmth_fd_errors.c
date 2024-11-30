#include "../include/libft_tester.h"
#include "../include/putsmth_fd.h"

void	form_alloc_errbuf_err_msg(t_char_c *fname, char *buf)
{
	strlcpy(buf, fname, MAX_ERR_BUF_SIZE);
	strlcat(buf, "_test(): ", MAX_ERR_BUF_SIZE);
	strlcat(buf, MEM_ERR_BUF_MSG, MAX_ERR_BUF_SIZE);
}

void	form_alloc_readbuf_err_msg(t_char_c *fname, char *buf)
{
	strlcpy(buf, fname, MAX_ERR_BUF_SIZE);
	strlcat(buf, "_test(): ", MAX_ERR_BUF_SIZE);
	strlcat(buf, MEM_ERR_FILE_READ_BUF_MSG, MAX_ERR_BUF_SIZE);
}

void	form_delete_temp_file_err_msg(t_char_c *fname, char *buf)
{
	strlcpy(buf, fname, MAX_ERR_BUF_SIZE);
	strlcat(buf, "_test(): ", MAX_ERR_BUF_SIZE);
	strlcat(buf, FILE_DEL_ERR_MSG, MAX_ERR_BUF_SIZE);
	strlcat(buf, " ", MAX_ERR_BUF_SIZE);
	strlcat(buf, TEMP_FILE_NAME, MAX_ERR_BUF_SIZE);
}

void	form_create_temp_file_err_msg(t_char_c *fname, char *buf)
{
	strlcpy(buf, fname, MAX_ERR_BUF_SIZE);
	strlcat(buf, "_test(): ", MAX_ERR_BUF_SIZE);
	strlcat(buf, FILE_CREAT_ERR_MSG, MAX_ERR_BUF_SIZE);
	strlcat(buf, " ", MAX_ERR_BUF_SIZE);
	strlcat(buf, TEMP_FILE_NAME, MAX_ERR_BUF_SIZE);
}

void	form_open_temp_file_err_msg(t_char_c *fname, char *buf)
{
	strlcpy(buf, fname, MAX_ERR_BUF_SIZE);
	strlcat(buf, "_test(): ", MAX_ERR_BUF_SIZE);
	strlcat(buf, FILE_OPEN_ERR_MSG, MAX_ERR_BUF_SIZE);
	strlcat(buf, " ", MAX_ERR_BUF_SIZE);
	strlcat(buf, TEMP_FILE_NAME, MAX_ERR_BUF_SIZE);
}
