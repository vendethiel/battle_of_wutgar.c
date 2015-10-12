#include "main.h"

t_poison* poison_build(char* name, int dmg, int para, int len) {
  t_poison* poison;

  poison = xmalloc(sizeof(t_poison));
  poison->name = name;
  poison->dmg = dmg;
  poison->para = para;
  poison->len = len;
  return poison;
}

t_poison* poison_get(char* name) {
  if (!strcmp("curse", name))
    return poison_build("curse", 5, 0, 7);
  if (!strcmp("stun", name))
    return poison_build("stun", 0, 10, 1);
  if (!strcmp("paralytic", name))
    return poison_build("paralytic poison", 5, 9, 3);
  if (!strcmp("major bleed", name))
    return poison_build("major bleed", 15, 0, 8);
  return poison_build("weakness", 1, 0, 15);
}

/* returns true if the player must be poison-stunned */
int poison_stun(t_poison* poison) {
  return 1; /* TEMPO */
  if (!poison->para)
    return 0;
  if (poison->para == 10)
    return 1;
  return rand_between(poison->para, 10) == 10;
}
