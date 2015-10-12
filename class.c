#include "main.h"

t_class* class_build(int hp, int mp, char* specialname, special_fn special) {
  t_class* class;

  class = xmalloc(sizeof(t_class));
  class->hp_pool = hp;
  class->mp_pool = mp;
  class->specialname = specialname;
  class->special = special;
  return class;
}

t_class* class_get(char* name) {
  if (!strcmp("Warrior", name))
    return class_build(125, 25, "execute", special_execute);
  else if (!strcmp("Mage", name))
    return class_build(100, 35, "meteor", special_meteor);
  else if (!strcmp("Thief", name))
    return class_build(110, 30, "stealfist", special_stealfist);
  else {
    printf("You have to select a class.\n");
    return 0;
  }
}
