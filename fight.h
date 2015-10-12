#pragma once

int	fight_start(t_char *character, t_enemy *enemy);
int	fight_poison_tick(t_char *, t_enemy *);

typedef enum {
  YOU_DEAD,
  YOU_KILLED,
  YOU_KEEP_PLAYING,
} fight_check_state;

fight_check_state fight_check_end(t_char*, t_enemy*);
