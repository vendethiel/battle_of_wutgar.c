#include "../main.h"

int	spell_heal(t_char *character, t_enemy *enemy)
{
  (void)enemy;
	int	done;
  int mana = 3;

	if (character->hp == character->class->hp_pool)
	{
		printf("You're all healthy already !\n");
		return CONTINUE_TURN;
	}
	else if (character->mp >= mana)
	{
		done = character->class->hp_pool / 4;
		printf("You heal yourself for " COLOR_GREEN);
		if (char_crit(&done, character, 0))
			printf(COLOR_CLEAR " (CRITICAL ! +20%% !)");
		printf(COLOR_CLEAR " hp.\n");
		character->mp -= mana;
		char_add_hp(character, done);
		return CONSUME_TURN;
	}
	else
	{
		printf("You don't have enough mana to heal !\n");
		return CONTINUE_TURN;
	}
}

int	spell_roar(t_char *character, t_enemy *enemy)
{
  (void)enemy;
	int	power;
	int	mana;

  return CONTINUE_TURN; /* TODO */
	if (character->mp >= 10)
	{
		power = rand_between(1, 3);
    mana = 3; //rand_between();
    /* TODO */
		printf("You shout to your chimaeras, giving them %i power and " COLOR_BLUE "%i" COLOR_CLEAR " mana\
        (+2 for defensive chimaeras) ... but it fails because the dev is lazy!",
        power, mana);
	}
}
