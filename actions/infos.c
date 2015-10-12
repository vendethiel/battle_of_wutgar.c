#include "../main.h"

void	info_stat_items(t_char *character)
{
	printf("You still have %i health potion(s) and %i ether(s) remaining.\n",
      character->potions, character->ethers);
}

int	info_stat(t_char *character, t_enemy *enemy)
{
  (void)enemy;
	printf("Data : You're called %s, you're a %s. "
      "You got " COLOR_RED "%i" COLOR_CLEAR "/" COLOR_RED "%i" COLOR_CLEAR " HP and "
      COLOR_BLUE "%i" COLOR_CLEAR "/" COLOR_BLUE "%i" COLOR_CLEAR " mana.\n",
      character->name, character->class->name,
      character->hp, character->class->hp_pool,
      character->mp, character->class->mp_pool);
	info_stat_items(character);
	if (character->poison) {
		printf("You're suffering from %s", character->poison->name);
    if (character->poison->dmg) {
      printf(", inflicting %i damage per turn", character->poison->dmg);
    }
    printf(".\n");
	}
	return CONTINUE_TURN;
}

int	info_libra(t_char *character, t_enemy *enemy)
{
	if (character->mp == 0)
	{
		printf("You don't have enough mana to use libra.\n");
		return CONTINUE_TURN;
	}
	--character->mp;
	printf("Enemy data : enemy's name is %s, with "
      COLOR_RED "%i" COLOR_CLEAR " HP and "
      COLOR_BLUE "%i" COLOR_CLEAR " mana",
      enemy->name, enemy->hp, enemy->mp);
	if (enemy->dmg_mult > 1)
	{
		printf(" and his damages get mutliplied by %i", enemy->dmg_mult);
	}
	printf(".\n");
	return CONSUME_TURN;
}

#define CB COLOR_BLUE
#define CR COLOR_RED
#define CG COLOR_GREEN
#define CC COLOR_CLEAR
int	info_help(t_char *character, t_enemy *enemy)
{
  (void)character, (void)enemy;
	printf("Available commands : \nAttacks :\n- attack : basic attack, \
deals "CR"7"CC" dmg.\n- slash : does "CR"10"CC" damage, hurts you for "CR"2\
"CC". If you're a warrior, you have 10%% chance to double your dmg and not get\
 hurt.\n- fire : costs "CB"2"CC" mana, does "CR"10"CC" dmg.\n- thunder : does \
"CR"15"CC" dmg, "CB"5"CC" mp. If you're a mage, 10%% chance that you stun the \
enemy.\nItems :\n- Potion : heals you for "CG"30"CC"HP. Be careful, you might \
break it. You have 5 of these when you start your quest.\n- Ether : gives you \
"CB"12"CC" mana back.\nDefensive spells :\n- heal : heals you for "CG"25%%\
"CC" of your base mana. costs "CB"3"CC" mp.\n- roar : motivates your chimaeras\
, giving them power/mana ... Maybe ;). Costs "CB"10"CC" mana.\nSpecials :\n\
- execute (warrior) : deals "CR"25"CC" dmg to your enemy, "CR"8"CC" to you\n\
- meteor (mage) : costs "CB"10"CC" mana, deals "CR"25"CC" dmg.\n\
- stealfist (thief) : deals "CR"15"CC" damage and steals "CB"4"CC" mana\n\
Other commands :\n- info : infos about you. Does not 'use' your turn.\n\
- libra : infos about your enemy. Uses your turn and costs "CB"1"CC" mana\
\n- quit : quit the program.\n- help : display this message\n\n\
Thieves bonus is +20%% crit (mage is in thunder, warrior in slash).\n\
Class stats (HP|MP) : Warrior (125|25, execute). Mage (100|35,\
 meteor). Thief (100|30, stealfist).\n\n\
You're helped by 1-3 chimaeras, some will do more \
heal and some more attack (they have limited in mana). The enemy can scare \
them off.\nThe enemy can also poison you or do DoT (damage over time), which \
might stun you (each poison have different chance). Your chimaeras won't \
attack if you're stunned. They last for N turns.\n");
  return CONTINUE_TURN;
}

int	info_quit(t_char *character, t_enemy *enemy)
{
  (void)character, (void)enemy;
	printf("You're running away from your quest ! Coward !\n");
	return QUIT_GAME;
}
