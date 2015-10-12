#include "main.h"

void	clearscreen()
{
	printf("\033[2J\033[1;1H");
}

void	begin_quest(t_char *character)
{
	int	i;
	int	mob_count;

	mob_count = rand_between(1, 3);
	for (i = 0; i < mob_count; ++i)
	{
		if (YOU_DEAD == fight_start(character, enemy_create(NORMAL)))
			return;
	}
	fight_start(character, enemy_create(BOSS));
}

void	process(char *char_name, char *class_name)
{
	t_class *class;
	t_char	*character;

	if (!char_name || !class_name || !strcmp(char_name, ""))
	{
		printf("Usage : ./ragnarok -n 'Your name' -c <Warrior/Mage/Thief>\n");
		return;
	}
	if (!(class = class_get(class_name)))
		return;
	class->name = class_name;
	character = char_create(class, char_name);
	clearscreen();
	message_otd(character);
	begin_quest(character);
}

int	main(int argc, char **argv)
{
	char	*name;
	char	*class;
	int	i;

	for (i = 0; i < argc - 1; ++i)
	{
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == 'n')
				name = argv[++i];
			if (argv[i][1] == 'c')
				class = argv[++i];
		}
	}
	process(name, class);
	return 0;
}
