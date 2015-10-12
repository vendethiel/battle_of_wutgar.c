#include "main.h"

t_enemy	*enemy_build(enemy_type t, char *name, int hp, int mp, int dmg_mult)
{
	t_enemy *enemy;

	enemy = xmalloc(sizeof(t_enemy));
	enemy->type = t;
	enemy->name = name;
	enemy->hp = hp;
	enemy->mp = mp;
	enemy->dmg_mult = dmg_mult;
	return enemy;
}

t_enemy	*enemy_create(enemy_type t)
{
	if (t == NORMAL)
		return enemy_build(NORMAL, "Abomination", 95, 20, 1);
	if (t == BOSS)
		return enemy_build(BOSS, "Le Mad Scientist", 200, 50, 2);
  return NULL;
}

// boss: more crits
int	enemy_crit(int *nb, t_enemy *enemy)
{
	int	crit;
	int	crit_dmg;
	int	max;

	max = enemy->type == BOSS ? 8 : 10;
	crit = rand_between(1, max) == 1;
	crit_dmg = crit ? (*nb / 4) : 0;
	*nb += crit_dmg;
	printf("%i", *nb);
	return crit;
}

int	enemy_attack_count(t_enemy *enemy)
{
	return 3 + (enemy->type == NORMAL ? 0 : 1);
}
