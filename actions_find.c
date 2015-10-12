#include "main.h"

t_action* action_find(t_action** actions, char* action) {
  for (int i = 0; i < ACTION_COUNT; ++i) {
    if (!strcmp(actions[i]->name, action))
      return actions[i];
  }
  return NULL;
}

/* Finds an action by name, then frees the name */
t_action* action_find_free(t_action** actions, char* action) {
  t_action* res;

  res = action_find(actions, action);
  free(action);
  return res;
}
