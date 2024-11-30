#!/bin/bash

make
cd examples/ && cc -Wall -Wextra -Werror -O0 -g3 tester.c ../libft_tester.a ../../libft.a -o tester
./tester
cd ..
