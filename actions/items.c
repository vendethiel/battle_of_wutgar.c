#include "../main.h"

int item_potion(t_char* character, t_enemy* enemy) {
  (void)enemy;
  if (character->hp == character->class->hp_pool) {
    printf("You're full health already !\n");
    return CONTINUE_TURN;
  } else if (character->potions) {
    --character->potions;
    if (rand_between(1, 10) == 1)
      printf("You try to get a health potion out of your bag, but you "
             "accidentally break it! It's unusable!\n");
    else {
      int heal = 30;
      printf("You drink a potion, regaining " COLOR_GREEN "%i" COLOR_CLEAR
             " HP.\n",
             heal);
      char_add_hp(character, heal);
    }
    return CONSUME_TURN;
  } else {
    printf("You don't have any health potions remaining !\n");
    return CONTINUE_TURN;
  }
}

int item_ether(t_char* character, t_enemy* enemy) {
  (void)enemy;
  if (character->mp == character->class->mp_pool) {
    printf("You're full mana already !\n");
    return CONTINUE_TURN;
  } else if (character->ethers) {
    --character->ethers;
    int mana = 12;
    printf("You use an ether, regaining " COLOR_BLUE "%i" COLOR_CLEAR
           " mana.\n",
           mana);
    char_add_mp(character, mana);
    return CONSUME_TURN;
  } else {
    printf("You don't have any ethers remaining !\n");
    return CONTINUE_TURN;
  }
}
