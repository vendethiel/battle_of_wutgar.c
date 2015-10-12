#include "../main.h"

#define MESSAGE_CRITICAL_SPE (COLOR_CLEAR " (CRITICAL SPECIAL ! +25%% !) ")

int	special_disallow(t_action *action, t_char *character)
{
	if (action->type != SPECIAL)
		return 0;
	return strcmp(action->name, character->class->specialname);
}

int	special_execute(t_char *character, t_enemy *enemy)
{
	int	dmg;

	dmg = 25;
	printf("You execute the enemy for " COLOR_RED);
	if (char_crit(&dmg, character, 1))
		printf(MESSAGE_CRITICAL_SPE);
	printf(COLOR_CLEAR ".\n");
	enemy->hp -= dmg;
	character->hp -= 8;
	return CONSUME_TURN;
}

int	special_meteor(t_char *character, t_enemy *enemy)
{
	int	dmg = 25;
  int mana = 10;

	printf("You cast a meteor onto the enemy for " COLOR_RED);
	if (char_crit(&dmg, character, 1))
		printf(MESSAGE_CRITICAL_SPE);
	printf(COLOR_CLEAR " HP, costing you "COLOR_BLUE "%i" COLOR_CLEAR" mana.\n",
      mana);
	enemy->hp -= dmg;
	character->mp -= mana;
	return CONSUME_TURN;
}

int	special_stealfist(t_char *character, t_enemy *enemy)
{
	int	dmg = 15;
  int mana = 4;

	printf("You steal the enemy's fist, dealing " COLOR_RED);
	if (char_crit(&dmg, character, 1))
		printf(MESSAGE_CRITICAL_SPE);
	printf(COLOR_CLEAR " damage and stealing him %i mana.\n", mana);
	enemy->hp -= dmg;
	enemy->mp -= mana;
	character->mp += mana;
	return CONSUME_TURN;
}
