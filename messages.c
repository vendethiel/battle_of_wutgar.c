#include "main.h"

void message_fight_enemy_turn(t_enemy* enemy) {
  printf("It's time for %s to play\n", enemy->name);
}

void message_poison_len(t_poison* poison) {
  printf("%s is still ticking for %i turns\n", poison->name, poison->len);
}

void message_poison_fade(t_poison* poison) {
  printf("%s fades, you feel better\n", poison->name);
}

void message_fight_against(t_enemy* enemy, int chim_nbr) {
  printf("You're fighting against %s with %i chimaera%s",
      enemy->name, chim_nbr, chim_nbr > 1 ? "s" : "");
}

void message_otd(t_char* character) {
  printf("Bienvenue, %s, sur les terres de Midgar!", character->name);
}

void message_fight_turn_start(void) {
  static int i = 0;
  printf(COLOR_RED "\n#-------[ TURN #%i ]------" COLOR_CLEAR, ++i);
}
