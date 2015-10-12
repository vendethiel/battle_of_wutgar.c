#pragma once

typedef int (*special_fn)(struct s_char* character, t_enemy* enemy);

typedef struct s_class {
  char* name;
  char* specialname;
  special_fn special;
  int hp_pool;
  int mp_pool;
} t_class;

t_class* class_get(char* name);
