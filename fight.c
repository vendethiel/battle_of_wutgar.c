#include "main.h"
#define CP COLOR_PURPLE
#define CC COLOR_CLEAR
#define PSN_STUN CP"\nThe poison is too strong, you can't move !\n"CC

fight_check_state fight_check_end(t_char *character, t_enemy *enemy)
{
	if (character->hp < 1)
	{
		printf("You're dead !\n" COLOR_RED "GAME OVER\n" COLOR_CLEAR);
		return YOU_DEAD;
	}
	if (enemy->hp < 1)
	{
		printf("%s died!\n\n", enemy->name);
		return YOU_KILLED;
	}
	return YOU_KEEP_PLAYING;
}

void	fight_enemy_turn(t_char *character, t_enemy *enemy)
{
	static int total_enemy_actions;
	static t_action **enemy_actions;
	int enemy_atk;

	if (!total_enemy_actions)
	{
		total_enemy_actions = enemy_attack_count(enemy);
		enemy_actions = actions_enemy_get(enemy, total_enemy_actions);
	}
	enemy_atk = rand_between(0, total_enemy_actions - 1);
	message_fight_enemy_turn(enemy);
	enemy_actions[enemy_atk]->fn(character, enemy);
	attack_enemy_chimaera(enemy, character->chim);
}

int	fight_poison_tick(t_char *character, t_enemy *enemy)
{
	if (character->poison)
	{
		if (character->poison->dmg)
		{
			printf("You suffer from " COLOR_PURPLE "%s" COLOR_CLEAR " and lose "
          COLOR_RED "%i" COLOR_CLEAR " HP.\n",
          character->poison->name, character->poison->dmg);
			character->hp -= character->poison->dmg;
		}
		--character->poison->len; /* reduce duration */
		if (character->poison->len)
			message_poison_len(character->poison);
		else
		{
			message_poison_fade(character->poison);
			character->poison = 0;
		}
	}
	return fight_check_end(character, enemy);
}

t_action	*fight_get_action()
{
	static t_action	**actions;
	t_action	*action = NULL;

	if (!actions)
		actions = actions_get();
	printf("\nYour turn> ");
  fflush(stdout);
	while (!(action = action_find_free(actions, readLine()))) {
		printf("Invalid command.\nYour turn> ");
    fflush(stdout);
  }
	return action;
}

int	fight_start(t_char *character, t_enemy *enemy)
{
	t_action	*action;
	int	ret;

	message_fight_against(enemy, chim_for(character));
	for (;;)
	{
    action = NULL;
    message_fight_turn_start();
		if (character->poison && poison_stun(character->poison))
			printf(PSN_STUN);
		else
			action = fight_get_action();

		if (YOU_KEEP_PLAYING != (ret = fight_check_end(character, enemy)))
			return ret;
		if (action && special_disallow(action, character))
			printf("You can only use your class' special attack !\n");
		else if (action
        ? (ret = action->fn(character, enemy))
        : (ret = CONSUME_TURN)) /* poisoned => skip turn */
		{
			if (QUIT_GAME == ret
          || YOU_KEEP_PLAYING != (ret = chim_play(character, enemy)))
				return ret;
			if (YOU_KEEP_PLAYING != (ret = fight_poison_tick(character, enemy)))
				return ret;
			fight_enemy_turn(character, enemy);
		}
		if (YOU_KEEP_PLAYING != (ret = fight_check_end(character, enemy)))
			return ret;
	}
}
