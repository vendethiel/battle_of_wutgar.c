#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "poison.h"
#include "char.h"
#include "enemy.h"
#include "fight.h"
#include "class.h"
#include "chim.h"
#include "actions.h"
#include "messages.h"
#include "colors.h"

void* xmalloc(size_t);
char* readLine();
int rand_between(int a, int b);
void error_fatal(char* msg);
