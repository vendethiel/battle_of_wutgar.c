#include "main.h"

t_action* action_build(char* name, action_type type, action_fn fn) {
  t_action* action;

  action = malloc(sizeof(t_action));
  action->name = name;
  action->type = type;
  action->fn = fn;
  return action;
}

t_action** actions_get(void) {
  t_action** actions;

  actions = xmalloc(sizeof(t_action) * ACTION_COUNT);
  actions[0] = action_build("attack", ATTACK, attack_attack);
  actions[1] = action_build("slash", ATTACK, attack_slash);
  actions[2] = action_build("fire", ATTACK, attack_fire);
  actions[3] = action_build("thunder", ATTACK, attack_thunder);
  actions[4] = action_build("Potion", ITEM, item_potion);
  actions[5] = action_build("Ether", ITEM, item_ether);
  actions[6] = action_build("heal", SPELL, spell_heal);
  actions[7] = action_build("execute", SPECIAL, special_execute);
  actions[8] = action_build("meteor", SPECIAL, special_meteor);
  actions[9] = action_build("stealfist", SPECIAL, special_stealfist);
  actions[10] = action_build("stat", INFO, info_stat);
  actions[11] = action_build("libra", INFO, info_libra);
  actions[12] = action_build("quit", INFO, info_quit);
  actions[13] = action_build("help", INFO, info_help);
  actions[14] = action_build("roar", SPELL, spell_roar);
  return actions;
}

t_action** actions_enemy_get(t_enemy* enemy, int total) {
  t_action** actions;

  actions = xmalloc(sizeof(t_action) * total);
  actions[0] = action_build("bite", ENEMY_ATTACK, attack_enemy_bite);
  actions[1] =
      action_build("earthquake", ENEMY_ATTACK, attack_enemy_earthquake);
  actions[2] = action_build("doom", ENEMY_ATTACK, attack_enemy_doom);
  if (enemy->type == BOSS) {
    actions[3] = action_build("death", ENEMY_ATTACK, attack_enemy_death);
  }
  return actions;
}
