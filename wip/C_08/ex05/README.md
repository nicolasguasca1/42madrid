gcc -Wall -Wextra -Werror -c ft_strs_to_tab.c -o ft_strs_to_tab.o
gcc -Wall -Wextra -Werror -c ft_show_tab.c -o ft_show_tab.o
gcc -Wall -Wextra -Werror -c main.c -o main.o

gcc -Wall -Wextra -Werror -o test main.o ft_strs_to_tab.o ft_show_tab.o

./test

