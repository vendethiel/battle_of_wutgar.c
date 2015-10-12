#include "../main.h"

void	chim_behavior_attack(t_chim *chim, t_char *character, t_enemy *enemy)
{
	int	dmg = chim->power;

  (void)character;
	printf("Your chimaera attacks %s for " COLOR_RED "%i" COLOR_CLEAR ".\n",
      enemy->name, dmg);
}

void	chim_behavior_heal(t_chim *chim, t_char *character, t_enemy *enemy)
{
  (void)enemy;
	--chim->mp;
	char_add_hp(character, chim->power);
	printf("Your chimaera heals you for " COLOR_GREEN "%i" COLOR_CLEAR " HP.\n",
      chim->power);
}
