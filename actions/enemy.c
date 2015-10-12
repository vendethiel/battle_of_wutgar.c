#include "../main.h"

#define ENEMY_RETURN 1 /* meaningless */
#define MESSAGE_CRITICAL " (CRITICAL HIT !)"

void attack_enemy_chimaera(t_enemy* enemy, t_chim* chim) {
  while (chim) {
    if (chim->behavior == SCARED)
      chim->behavior = ATTACKING;
    else if (rand_between(1, 5) == 1) {
      printf("%s scares your %s off! She's paralized by terror!\n", enemy->name,
             chim->name);
      chim->behavior = SCARED;
      return;
    }
    chim = chim->next;
  }
}

// -------

int attack_enemy_bite(t_char* character, t_enemy* enemy) {
  int dmg;

  dmg = enemy->dmg_mult * 6;
  printf("%s bites you for " COLOR_RED, enemy->name);
  if (enemy_crit(&dmg, enemy))
    printf(MESSAGE_CRITICAL);
  printf(COLOR_CLEAR ".\n");
  character->hp -= dmg;
  if (!rand_between(0, 5))
    char_poison(character, poison_get("paralytic"));
  return ENEMY_RETURN;
}

int attack_enemy_earthquake(t_char* character, t_enemy* enemy) {
  int dmg;
  int owndmg;

  dmg = enemy->dmg_mult * 15;
  owndmg = enemy->dmg_mult * 3;
  printf("%s casts an earthquake, hitting himself for " COLOR_RED
         "%i" COLOR_CLEAR " HP and hurting you for " COLOR_RED,
         enemy->name, owndmg);
  if (enemy_crit(&dmg, enemy))
    printf(MESSAGE_CRITICAL);
  printf(COLOR_CLEAR " HP.\n");
  character->hp -= dmg;
  enemy->hp -= owndmg;
  if (!rand_between(0, 5))
    char_poison(character, poison_get("stun"));
  return ENEMY_RETURN;
}

int attack_enemy_doom(t_char* character, t_enemy* enemy) {
  int dmg;

  printf(enemy->name);
  if (enemy->mp >= 5) {
    dmg = enemy->dmg_mult * 11;
    character->hp -= dmg;
    enemy->mp -= 5;
    printf(" dooms you, inflicting " COLOR_RED);
    if (enemy_crit(&dmg, enemy))
      printf(MESSAGE_CRITICAL);
    printf(COLOR_CLEAR " damage. You get poisoned !\n");
  } else {
    printf(" tries to doom you but fails !\n");
    if (!rand_between(0, 5))
      char_poison(character, poison_get("major bleed"));
  }
  return ENEMY_RETURN;
}

// boss
int attack_enemy_death(t_char* character, t_enemy* enemy) {
  printf("%s sneakily moves behind you ", enemy->name);
  if (rand_between(1, 35) == 1) {
    printf("... and " COLOR_RED "slices your head off" COLOR_CLEAR " !\n");
    character->hp = 0;
  } else {
    printf("... but fails !\n");
  }
  return ENEMY_RETURN;
}
