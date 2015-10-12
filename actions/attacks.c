#include "../main.h"
#define MESSAGE_CRITICAL_HIT (COLOR_CLEAR " (CRITICAL HIT ! +20%% !) ")

int	attack_attack(t_char *character, t_enemy *enemy)
{
	int	dmg;

	dmg = 7;
	printf("You attack the enemy and inflict him " COLOR_RED);
	if (char_crit(&dmg, character, 0))
		printf(MESSAGE_CRITICAL_HIT);
	printf(COLOR_CLEAR " damage\n");
	enemy->hp -= dmg;
	return CONSUME_TURN;
}

int	attack_slash(t_char *character, t_enemy *enemy)
{
	int	dmg;

	dmg = 10;
	printf("You slash the enemy, doing " COLOR_RED);
	if (char_crit(&dmg, character, 0))
		printf(MESSAGE_CRITICAL_HIT);
	printf(COLOR_CLEAR " damage");
	if (!strcmp("Warrior", character->class->name) && rand_between(1, 10) == 1)
	{
		printf(" ... and then valiantly tackle him down, inflicting him two times that damage !\n");
		enemy->hp -= dmg;
	}
	else
	{
		character->hp -= 2;
		printf(", but also hurt yourself in the process and lose "
        COLOR_RED "2" COLOR_CLEAR " HP !\n");
	}
	enemy->hp -= dmg;
	return CONSUME_TURN;
}

int	attack_fire(t_char *character, t_enemy *enemy)
{
	int	dmg;

	if (character->mp >= 2)
	{
		dmg = 10;
		printf("You throw a fireball, doing " COLOR_RED);
		if (char_crit(&dmg, character, 0))
			printf(MESSAGE_CRITICAL_HIT);
		printf(COLOR_CLEAR " damages, costing you " COLOR_BLUE "3" COLOR_CLEAR " mana.\n");
		character->mp -= 3;
		enemy->hp -= dmg;
		return CONSUME_TURN;
	}
	printf("You don't have enough mana to throw a fireball !\n");
	return CONTINUE_TURN;
}

int	attack_thunder(t_char *character, t_enemy *enemy)
{
	int	dmg;

	if (character->mp >= 5)
	{
		dmg = 15;
		printf("You cast thunder, inflicting " COLOR_RED);
		if (char_crit(&dmg, character, 0))
			printf(MESSAGE_CRITICAL_HIT);
		printf(COLOR_CLEAR " damages to your enemy, costing you "COLOR_BLUE"5"COLOR_CLEAR" mana.\n");
		if (!strcmp("Mage", character->class->name) && rand_between(1, 10) == 1)
		{
			printf(". The hit is so strong, the enemy is stunned and can't play !\n");
			return CONTINUE_TURN; /* TODO: remove this hack */
		}
		character->mp -= 5;
		enemy->hp -= dmg;
		return CONSUME_TURN;
	}
	printf("You don't have enough mana to cast thunder !\n");
	return CONTINUE_TURN;
}
