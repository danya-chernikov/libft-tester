CC=cc
NAME=libft_tester.a
CFLAGS=-Wall -Werror -Wextra -O0 -g3
BSDOBJS=bsd_strlcpy.o bsd_strlcat.o bsd_strnstr.o

OBJS=common_tester.o alg.o print.o cprint.o alloc.o packer.o \
	 libft_tester.o \
	 isalpha.o isdigit.o isalnum.o isascii.o isprint.o \
	 strlen.o memset.o bzero.o memcpy.o memmove.o \
	 strlcpy.o strlcpy_regular.o strlcpy_special.o \
	 strlcat.o strlcat_regular.o strlcat_special.o \
	 toupper.o tolower.o strchr.o strrchr.o strncmp.o memchr.o \
	 memcmp.o memcmp_regular.o memcmp_special.o \
	 strnstr.o atoi.o calloc.o strdup.o \
	 substr.o strjoin.o strtrim.o \
	 split.o split_aux.o \
	 itoa.o strmapi.o striteri.o \
	 putchar_fd.o putstr_fd.o putendl_fd.o putnbr_fd.o \
	 putsmth_fd_aux.o putsmth_fd_regular.o \
	 putsmth_fd_special.o putsmth_fd_write.o putsmth_fd_print.o \
	 putsmth_fd_errors.o


$(NAME) : $(OBJS) $(BSDOBJS)
	cd .. && $(MAKE) all # First let's build the Libft
	ar rcs $(NAME) $(OBJS) $(BSDOBJS) # Building Libft tester library

# first we build libft.a and then libft_tester.a
all : $(NAME)

clean :
	rm -rf $(OBJS) $(BSDOBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

# Let's compile the original strlcpy() from FreeBSD
bsd_strlcpy.o : libbsd/bsd_strlcpy.c libbsd/bsd_string.h
	$(CC) $(CFLAGS) -c libbsd/bsd_strlcpy.c

# Let's compile the original strlcat() from FreeBSD
bsd_strlcat.o : libbsd/bsd_strlcat.c libbsd/bsd_string.h
	$(CC) $(CFLAGS) -c libbsd/bsd_strlcat.c

# Let's compile the original strnstr() from FreeBSD
bsd_strnstr.o : libbsd/bsd_strnstr.c libbsd/bsd_string.h
	$(CC) $(CFLAGS) -c libbsd/bsd_strnstr.c

# Let's compile common tester library
common_tester.o : common_tester/common_tester.c common_tester/common_tester.h
	$(CC) $(CFLAGS) -c common_tester/common_tester.c

alg.o : common_tester/alg.c common_tester/common_tester.h
	$(CC) $(CFLAGS) -c common_tester/alg.c

print.o : common_tester/print.c common_tester/common_tester.h
	$(CC) $(CFLAGS) -c common_tester/print.c

cprint.o : common_tester/cprint.c common_tester/common_tester.h
	$(CC) $(CFLAGS) -c common_tester/cprint.c
alloc.o : common_tester/alloc.c common_tester/common_tester.h
	$(CC) $(CFLAGS) -c common_tester/alloc.c

packer.o : common_tester/packer.c common_tester/common_tester.h
	$(CC) $(CFLAGS) -c common_tester/packer.c

# Let's compile all the sources of libft_tester library
libft_tester.o : src/libft_tester.c include/libft_tester.h
	$(CC) $(CFLAGS) -c src/libft_tester.c

isalpha.o : src/isalpha.c include/libft_tester.h
	$(CC) $(CFLAGS) -c src/isalpha.c

isdigit.o : src/isdigit.c include/libft_tester.h
	$(CC) $(CFLAGS) -c src/isdigit.c

isalnum.o : src/isalnum.c include/libft_tester.h
	$(CC) $(CFLAGS) -c src/isalnum.c

isascii.o : src/isascii.c include/libft_tester.h
	$(CC) $(CFLAGS) -c src/isascii.c

isprint.o : src/isprint.c include/libft_tester.h
	$(CC) $(CFLAGS) -c src/isprint.c

strlen.o : src/strlen.c include/libft_tester.h
	$(CC) $(CFLAGS) -c src/strlen.c

memset.o : src/memset.c include/libft_tester.h
	$(CC) $(CFLAGS) -c src/memset.c

bzero.o : src/bzero.c include/libft_tester.h
	$(CC) $(CFLAGS) -c src/bzero.c

memcpy.o : src/memcpy.c include/libft_tester.h
	$(CC) $(CFLAGS) -c src/memcpy.c

memmove.o : src/memmove.c include/libft_tester.h
	$(CC) $(CFLAGS) -c src/memmove.c

strlcpy_regular.o : src/strlcpy_regular.c include/strlcpy.h include/libft_tester.h
	$(CC) $(CFLAGS) -c src/strlcpy_regular.c

strlcpy_special.o : src/strlcpy_special.c include/strlcpy.h include/libft_tester.h
	$(CC) $(CFLAGS) -c src/strlcpy_special.c

strlcpy.o : src/strlcpy.c include/strlcpy.h include/libft_tester.h
	$(CC) $(CFLAGS) -c src/strlcpy.c

strlcat_regular.o : src/strlcat_regular.c include/strlcat.h include/libft_tester.h
	$(CC) $(CFLAGS) -c src/strlcat_regular.c

strlcat_special.o : src/strlcat_special.c include/strlcat.h include/libft_tester.h
	$(CC) $(CFLAGS) -c src/strlcat_special.c

strlcat.o : src/strlcat.c include/strlcat.h include/libft_tester.h
	$(CC) $(CFLAGS) -c src/strlcat.c

toupper.o : src/toupper.c include/libft_tester.h
	$(CC) $(CFLAGS) -c src/toupper.c 

tolower.o : src/tolower.c include/libft_tester.h
	$(CC) $(CFLAGS) -c src/tolower.c 

strchr.o : src/strchr.c include/libft_tester.h
	$(CC) $(CFLAGS) -c src/strchr.c 

strrchr.o : src/strrchr.c include/libft_tester.h
	$(CC) $(CFLAGS) -c src/strrchr.c 

strncmp.o : src/strncmp.c include/libft_tester.h
	$(CC) $(CFLAGS) -c src/strncmp.c 

memchr.o : src/memchr.c include/libft_tester.h
	$(CC) $(CFLAGS) -c src/memchr.c

memcmp_regular.o : src/memcmp_regular.c include/memcmp.h include/libft_tester.h
	$(CC) $(CFLAGS) -c src/memcmp_regular.c

memcmp_special.o : src/memcmp_special.c include/memcmp.h include/libft_tester.h
	$(CC) $(CFLAGS) -c src/memcmp_special.c

memcmp.o : src/memcmp.c include/memcmp.h include/libft_tester.h
	$(CC) $(CFLAGS) -c src/memcmp.c

strnstr.o : src/strnstr.c include/libft_tester.h
	$(CC) $(CFLAGS) -c src/strnstr.c

atoi.o : src/atoi.c include/libft_tester.h
	$(CC) $(CFLAGS) -c src/atoi.c

calloc.o : src/calloc.c include/libft_tester.h
	$(CC) $(CFLAGS) -c src/calloc.c

strdup.o : src/strdup.c include/libft_tester.h
	$(CC) $(CFLAGS) -c src/strdup.c

substr.o : src/substr.c include/libft_tester.h
	$(CC) $(CFLAGS) -c src/substr.c

strjoin.o : src/strjoin.c include/libft_tester.h
	$(CC) $(CFLAGS) -c src/strjoin.c

strtrim.o : src/strtrim.c include/libft_tester.h
	$(CC) $(CFLAGS) -c src/strtrim.c

split_aux.o : src/split_aux.c include/split.h include/libft_tester.h
	$(CC) $(CFLAGS) -c src/split_aux.c

split.o : src/split.c include/split.h include/libft_tester.h
	$(CC) $(CFLAGS) -c src/split.c

itoa.o : src/itoa.c include/libft_tester.h
	$(CC) $(CFLAGS) -c src/itoa.c

strmapi.o : src/strmapi.c include/libft_tester.h
	$(CC) $(CFLAGS) -c src/strmapi.c

striteri.o : src/striteri.c include/libft_tester.h
	$(CC) $(CFLAGS) -c src/striteri.c

putchar_fd.o : src/putchar_fd.c include/putsmth_fd.h include/libft_tester.h
	$(CC) $(CFLAGS) -c src/putchar_fd.c

putstr_fd.o : src/putstr_fd.c include/putsmth_fd.h include/libft_tester.h
	$(CC) $(CFLAGS) -c src/putstr_fd.c

putendl_fd.o : src/putendl_fd.c include/putsmth_fd.h include/libft_tester.h
	$(CC) $(CFLAGS) -c src/putendl_fd.c

putnbr_fd.o : src/putnbr_fd.c include/putsmth_fd.h include/libft_tester.h
	$(CC) $(CFLAGS) -c src/putnbr_fd.c

putsmth_fd_aux.o : src/putsmth_fd_aux.c include/putsmth_fd.h include/libft_tester.h
	$(CC) $(CFLAGS) -c src/putsmth_fd_aux.c

putsmth_fd_regular.o : src/putsmth_fd_regular.c include/putsmth_fd.h include/libft_tester.h
	$(CC) $(CFLAGS) -c src/putsmth_fd_regular.c

putsmth_fd_special.o : src/putsmth_fd_special.c include/putsmth_fd.h include/libft_tester.h
	$(CC) $(CFLAGS) -c src/putsmth_fd_special.c

putsmth_fd_write.o : src/putsmth_fd_write.c include/putsmth_fd.h include/libft_tester.h
	$(CC) $(CFLAGS) -c src/putsmth_fd_write.c

putsmth_fd_print.o : src/putsmth_fd_print.c include/putsmth_fd.h include/libft_tester.h
	$(CC) $(CFLAGS) -c src/putsmth_fd_print.c

putsmth_fd_errors.o : src/putsmth_fd_errors.c include/putsmth_fd.h include/libft_tester.h
	$(CC) $(CFLAGS) -c src/putsmth_fd_errors.c

.PHONY: all clean fclean re
