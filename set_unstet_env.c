#include "main.h"
void setenv_condition(char **single_command)
{
if (single_command[1] && single_command[2])
{
_setenv(single_command[1], single_command[2]);
}
else
{
perror("./hsh: Invalid syntax\n");
}
}