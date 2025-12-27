#include "push_swap.h"

void message(int fd, char *msg)
{
    write(fd, msg, ft_strlen(msg));
}
