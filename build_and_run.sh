#!/bin/bash

make
cd examples/ && cc -Wall -Wextra -Werror tester.c ../libft-tester.a ../../libft.a -o tester
./tester
cd ..
