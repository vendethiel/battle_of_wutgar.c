#include "main.h"

t_char* char_create(t_class* class, char* name) {
  t_char* character;

  character = xmalloc(sizeof(t_char));
  character->hp = class->hp_pool;
  character->mp = class->mp_pool;
  character->potions = 5;
  character->ethers = 5;
  character->class = class;
  character->name = name;
  return character;
}

// thief: more crit
int char_crit(int* nb, t_char* character, int special) {
  int crit;
  float crit_dmg;
  int divby;
  int max;

  divby = (special ? 4 : 5);
  max = strcmp("Thief", character->class->name) ? 9 : 10;
  crit = rand_between(1, max) == 1;
  crit_dmg = crit ? (*nb / divby) : 0;
  *nb += crit_dmg;
  printf("%i", *nb);
  return crit;
}

void char_poison(t_char* character, t_poison* poison) {
  if (character->poison)
    return;
  character->poison = poison;
  printf("You're suffering from : " COLOR_PURPLE "%s" COLOR_CLEAR ".\n\n",
         poison->name);
}

// used for class caps
void char_add_hp(t_char* character, int nb) {
  character->hp += nb;
  if (character->hp > character->class->hp_pool)
    character->hp = character->class->hp_pool;
}

void char_add_mp(t_char* character, int nb) {
  character->mp += nb;
  if (character->mp > character->class->mp_pool)
    character->mp = character->class->mp_pool;
}
