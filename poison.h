#pragma once

// para/10 chance to stun
typedef struct s_poison {
	char	*name;
	int	dmg;
	int	para;
	int	len;
} t_poison;

int	poison_stun(t_poison *);
t_poison	*poison_get(char *);

