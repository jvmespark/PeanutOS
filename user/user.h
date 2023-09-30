#ifndef USER_H
#define USER_H

#include "../cpu/isr.h"
#include "../drivers/screen.h"
#include "../kernel/kernel.h"
#include "./libc/string.h"

void parseUser(char *command, char *str);
// void echo();

#endif