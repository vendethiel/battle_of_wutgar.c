#pragma once

typedef struct s_char {
	int	hp;
	int	mp;
	int	potions;
	int	ethers;
	char	*name;
	struct s_class	*class;
	struct s_chim	*chim;
	t_poison	*poison;
} t_char;

t_char	*char_create(struct s_class *, char *);
int	char_crit(int *, t_char *, int);
void	char_poison(t_char *, t_poison *);
void	char_add_hp(t_char *, int);
void	char_add_mp(t_char *, int);
