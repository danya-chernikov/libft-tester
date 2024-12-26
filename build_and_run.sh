#!/bin/bash

make
cd examples/
rm -f tester
cc -Wall -Wextra -Werror tester.c ../libft_tester.a ../../libft.a -o tester
./tester
cd ..
