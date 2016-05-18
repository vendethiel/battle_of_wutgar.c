#include "main.h"

// stats are randoms
t_chim* chim_create() {
  static int i = 0;
  t_chim* chim;

  chim = xmalloc(sizeof(t_chim));
  chim->name = strdup("Chimaera #i");
  chim->name[10] = '0' + ++i; /* safe only because we know there are 3 chims max */
  chim->behavior = rand_between(0, 3) ? ATTACKING : HEALING;
  chim->mp = rand_between(3, chim->behavior == HEALING ? 15 : 5);
  chim->power = rand_between(3, 8);
  return chim;
}

int chim_for(t_char* character) {
  int i;
  int nb;
  t_chim* prev;

  nb = rand_between(1, 3);
  character->chim = prev = chim_create();
  for (i = 0; i < nb; ++i) {
    prev->next = chim_create();
    prev = prev->next;
  }
  prev->next = 0;
  return nb + 1;
}

void chim_behavior_play(t_chim* chim, t_char* character, t_enemy* enemy) {
  int r;
  int behavior_atk;
  int heal;

  r = rand_between(1, 5);
  behavior_atk = (chim->behavior == ATTACKING ? 1 : 4);
  heal = chim->mp && character->hp != character->class->hp_pool;
  if (r <= behavior_atk && heal)
    chim_behavior_heal(chim, character, enemy);
  else
    chim_behavior_attack(chim, character, enemy);
}

int chim_play(struct s_char* character, t_enemy* enemy) {
  t_chim* chim;

  chim = character->chim;
  while (chim) {
    printf("\nIt's time for your %s to play!\n", chim->name);
    if (chim->behavior == SCARED)
      printf("The chimaera is too scared to attack !\n");
    else
      chim_behavior_play(chim, character, enemy);
    chim = chim->next;
  }
  return fight_check_end(character, enemy);
}
