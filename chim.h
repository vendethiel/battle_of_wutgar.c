#pragma once

typedef enum e_chim_behavior { ATTACKING, HEALING, SCARED } chim_behavior;

typedef struct s_chim {
  char* name;
  int mp;
  int power;
  chim_behavior behavior;
  struct s_chim* next;
} t_chim;

int chim_for(struct s_char* character);
int chim_play(struct s_char* character, t_enemy* enemy);
