# **Libft Tester**

## **Project Title**

This simple console program performs various tests on the Libft library,
which is the first project of the 42 Common Core. At this stage of its
development, the program launches each function located inside the tested
Libft library folder and passes different parameters to its input. Then,
the program does the same but for the corresponding 'original' function
in Glibc library (or, in some cases, for a function in a C library used by
FreeBSD), allowing the user to visually assess how close their implementation
is to the reference one.

This simple tester was developed primarily for learning purposes, though it
can be used or improved upon by other participants in the 42 program.

All the code in this tester complies with the Norm coding standard.

Test line

## **Installation and Usage**

1. The libft\_tester folder must be placed in the root directory of
   the Libft library being tested, for it to work correctly.

------------------------------------------------------------------------------------------------------
2. We must be inside libft\_tester directory so 'pwd' command must show
   us something like this:
```bash
$ pwd
 .../parent_dir/libft/libft_tester
```

The most common example of directory arrangement is shown below:
```
|parent_dir/
|    file1
|    ...
|    fileN
|    libft/ <------------------------ A directory containing our Libft source code
|    |    ft_atoi.c <---------------- A file containing our implementation of the
|    |    ft_bzero.c				  standard atoi() function
|    |    ft_calloc.c
|    |    ...
|    |    ft_tolower.c
|    |    ft_toupper.c
|    |    libft.h <------------------ The Libft header file
|    |    libft_tester/ <------------ This is our Libft library tester folder
|    |    |    src/
|    |    |        atoi.c <---------- A file containing the function that tests our ft_atoi()
|    |    |        bzero.c
|    |    |        calloc.c
|    |    |        isalnum.c <------- A file containing the function that tests
|    |    |        isalpha.c		  our ft_isalnum() function
|    |    |        isascii.c
|    |    |        isdigit.c
|    |    |        isprint.c
|    |    |        itoa.c
|    |    |        libft_tester.c
|    |    |        memchr.c
|    |    |        memcmp.c
|    |    |        ...
|    |    |        tolower.c
|    |    |        toupper.c
|    |    |    common_tester/ <------ A small library containing some common testing functions
|    |    |        common_tester.c
|    |    |        common_tester.h
|    |    |    include/
|    |    |        libft_tester.h <-- The header file of the Libft Tester library
|    |    |        split.h
|    |    |        strlcat.h
|    |    |        strlcpy.h
|    |    |        ...
|    |    |    libbsd/ <------------- A folder containing some FreeBSD's functions
|    |    |        bsd_string.h
|    |    |        bsd_strlcat.c
|    |    |        bsd_strlcpy.c
|    |    |        bsd_strnstr.c
|    |    |    examples/
|    |    |        tester.c <-------- A program that invokes lauch_tester()
|    |    |    Makefile <------------ A makefile that builds libft_tester.a
|    |    |Makefile <---------------- A makefile that builds libft.a
```
------------------------------------------------------------------------------------------------------
3. Then 'make' utility has to be run:
```bash
$ make
```

The Makefile located in the libft\_tester/ directory first builds the Libft
static library, producing libft.a in the parent libft/ directory. Then, it
builds the Libft library tester, producing libft\_tester.a in the current
directory.

------------------------------------------------------------------------------------------------------
4. Now we can start testing our Libft by invoking the launch\_tester()
function. For instance, we can create a small program, tester.c, located
in the libft\_tester/examples/ directory that launches the tester:

```c
// tester.c
#include "../include/libft_tester.h" 

int main(void)
{
	launch_tester();
	return(0);
}
```

------------------------------------------------------------------------------------------------------
5. The file tester.c may be compiled and launched:
```bash
$ cd examples/
$ cc -Wall -Wextra -Werror tester.c ../libft_tester.a ../../libft.a -o tester
$ ./tester
```

------------------------------------------------------------------------------------------------------
Files strlcpy.c, strlcat.c, and string.h from the FreeBSD system ([libbsd-0.12.2](https://sources.debian.org/src/libbsd/0.12.2-2))
were added to the libbsd/ folder under the names bsd\_strlcpy.c, bsd\_strlcat.c,
and bsd\_string.h for testing the strlcpy() and strlcat() functions,
allowing us to compare the execution of the original BSD functions with that of
our own implementations.

## **For developers**

This section serves to simplify the understanding of the project's source code.
Here is given a brief description of each file and the methods used to create it.

----------------------
common\_tester.c
alg.c
print.c
cprint.c
alloc.c
packer.c

----------------------

----------------------
libft\_tester.c
isalpha.c
isdigit.c
isalnum.c
isascii.c
isprint.c
strlen.c
memset.c
bze.c.c
memcpy.c
mem.cve.c
.cupper.c
.c.cwer.c
strchr.c
strrchr.c
strncmp.c
memchr.c
strnstr.c
a.ci.c
cal.cc.c
strdup.c
substr.c
str.cin.c
strtrim.c
i.ca.c
strmapi.c
striteri.c

----------------------
strlcpy.c
strlcpy\_regular.c
strlcpy\_special.c

----------------------

----------------------
strlcat.c
strlcat\_regular.c
strlcat\_special.c

----------------------

----------------------
memcmp.c
memcmp\_regular.c
memcmp\_special.c

----------------------

----------------------
split.c
split\_aux.c

----------------------

----------------------
putchar\_fd.c
putsmth\_fd\_aux.c
putsmth\_fd\_regular.c
putsmth\_fd\_special.c
putsmth\_fd\_write.c
putsmth\_fd\_print.c
putsmth\_fd\_er.crs.c

----------------------

## **License**

This work is published under the terms of [42 Unlicense](https://github.com/gcamerli/42unlicense).

The following files are included under thier original licenses:
- strlcpy.c: Copyright (c) 1998, 2015 Todd C. Miller <Todd.Miller@courtesan.com>. Licensed under a permissive license.
- strlcat.c: Copyright (c) 1998, 2015 Todd C. Miller <Todd.Miller@courtesan.com>. Licensed under a permissive license.
- strnstr.c: Copyright (c) 2001 Mike Barcroft <mike@FreeBSD.org>.
  Copyright (c) 1990, 1993 The Regents of the University of California All rights reserved.
  This code is derived from software contributed to Berkeley by Chris Torek. Licensed under a permissive license.
- string.h:  Copyright © 2004, 2005, 2009, 2011 Guillem Jover <guillem@hadrons.org>. Licensed under the BSD 3-Clause License.
