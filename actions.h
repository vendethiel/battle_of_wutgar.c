#pragma once
#define ACTION_COUNT 14

typedef int (*action_fn)(t_char*, t_enemy*);

typedef enum {
  ATTACK,
  INFO,
  ITEM,
  SPELL,
  SPECIAL,
  ENEMY_ATTACK,
} action_type;

/* make sure they're disjoint from fight.h's fight_check_state */
typedef enum {
  CONTINUE_TURN = 100,
  CONSUME_TURN = 101,
  QUIT_GAME = 102,
} action_return;

typedef struct s_action {
  char* name;
  action_type type;
  action_fn fn;
} t_action;

t_action* action_find(t_action**, char*);
t_action* action_find_free(t_action**, char*);

t_action** actions_get(void);
t_action** actions_enemy_get(t_enemy*, int);
t_action** actions_chim_get(void);

t_action* action_find(t_action** actions, char* action);

t_action* action_find_free(t_action** actions, char* action);

#include "actions/attacks.h"
#include "actions/items.h"
#include "actions/spells.h"
#include "actions/specials.h"
#include "actions/infos.h"
#include "actions/enemy.h"
#include "actions/chim.h"
