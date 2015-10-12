#pragma once

typedef enum { 
	NORMAL = 0,
	BOSS = 1
} enemy_type;

typedef struct s_enemy {
	int	hp;
	int	mp;
	int	dmg_mult;
	enemy_type type;
	char	*name;
} t_enemy;

t_enemy	*enemy_create(enemy_type);
int	enemy_crit(int *, t_enemy *);
int enemy_attack_count(t_enemy*);
