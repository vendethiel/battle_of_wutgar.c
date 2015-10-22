#pragma once

int fight_start(t_char* character, t_enemy* enemy);
int fight_poison_tick(t_char*, t_enemy*);

/* make sure they're disjoint from actions.h's action_return */
typedef enum {
  YOU_DEAD = 1,
  YOU_KILLED = 2,
  YOU_KEEP_PLAYING = 3,
} fight_check_state;

fight_check_state fight_check_end(t_char*, t_enemy*);
