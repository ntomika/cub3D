#include "header.h"

//void		check_key(t_all *all, int i, int k)
//{
//	if (all->conf[i][0] == ' ' || all->conf[i][0] == '1')
//	{
//		int j = -1;
//		int l = -1;
//		all->map[k] = (char *)malloc(sizeof(char) * (ft_strlen(all->conf[i]) + 1));
//		while (all->conf[i][++j])
//			all->map[k][++l] = all->conf[i][j];
//	}
//	else if (all->conf[i][0] == 'R' && all->conf[i][1] == ' ')
//		all->key.Rkey = ft_strdup(all->conf[i]);
//	else if (all->conf[i][0] == 'S' && all->conf[i][1] == ' ')
//		all->key.Skey = ft_strdup(all->conf[i]);
//	else if (all->conf[i][0] == 'F' && all->conf[i][1] == ' ')
//		all->key.Fkey = ft_strdup(all->conf[i]);
//	else if (all->conf[i][0] == 'C' && all->conf[i][1] == ' ')
//		all->key.Ckey = ft_strdup(all->conf[i]);
//	else if (all->conf[i][0] == 'N' && all->conf[i][1] == 'O')
//		all->key.NOkey = ft_strdup(all->conf[i]);
//	else if (all->conf[i][0] == 'S' && all->conf[i][1] == 'O')
//		all->key.SOkey = ft_strdup(all->conf[i]);
//	else if (all->conf[i][0] == 'W' && all->conf[i][1] == 'E')
//		all->key.WEkey = ft_strdup(all->conf[i]);
//	else if (all->conf[i][0] == 'E' && all->conf[i][1] == 'A')
//		all->key.EAkey = ft_strdup(all->conf[i]);
//	else
//	{
//		get_error("Invalid configuration file \"*.cub\"");
//		return ;
//	}
//}

void		check_valid(t_all *all)
{
	int i = -1;
	int k = 0;
	int l;

	if (!(all->map = (char **)malloc(sizeof(char *) * (all->sizemap + 1))))
	{
		get_error("Failed to allocate memory");
		return ;
	}
	while (all->conf[++i])
	{
		int j = -1;
		while (all->conf[i][++j])
		{
			if (all->conf[i][0] == ' ' || all->conf[i][0] == '1')
			{
				j = -1;
				l = -1;
				if (!(all->map[k] = (char *)malloc(sizeof(char) * (ft_strlen
						(all->conf[i]) + 1))))
				{
					get_error("Failed to allocate memory");
					return ;
				}
				while (all->conf[i][++j])
					all->map[k][++l] = all->conf[i][j];
				k++;
			}
			else if (all->conf[i][0] == 'R' && all->conf[i][1] == ' ')
				all->key.Rkey = ft_strdup(all->conf[i]);
			else if (all->conf[i][0] == 'F' && all->conf[i][1] == ' ')
				all->key.Fkey = ft_strdup(all->conf[i]);
			else if (all->conf[i][0] == 'C' && all->conf[i][1] == ' ')
				all->key.Ckey = ft_strdup(all->conf[i]);
			else if (all->conf[i][0] == 'S' && all->conf[i][1] == ' ')
				all->key.Skey = ft_strdup(all->conf[i]);
			else if (all->conf[i][0] == 'N' && all->conf[i][1] == 'O')
				all->key.NOkey = ft_strdup(all->conf[i]);
			else if (all->conf[i][0] == 'S' && all->conf[i][1] == 'O')
				all->key.SOkey = ft_strdup(all->conf[i]);
			else if (all->conf[i][0] == 'W' && all->conf[i][1] == 'E')
				all->key.WEkey = ft_strdup(all->conf[i]);
			else if (all->conf[i][0] == 'E' && all->conf[i][1] == 'A')
				all->key.EAkey = ft_strdup(all->conf[i]);
			else
			{
				get_error("Invalid configuration file");
				return ;
			}
//			check_key(all->conf[i][++j], i, k);
		}
	}

//	printf("keyR = %s\n", all->key.Rkey);
//	printf("keyS = %s\n", all->key.Skey);
//	printf("keyF = %s\n", all->key.Fkey);
//	printf("keyC = %s\n", all->key.Ckey);
//	printf("keyNO = %s\n", all->key.NOkey);
//	printf("keySO = %s\n", all->key.SOkey);
//	printf("keyWE = %s\n", all->key.WEkey);
//	printf("keyEA = %s\n\n", all->key.EAkey);

	k = -1;
	printf("map : \n");
	while (all->map[++k])
		printf("%s\n", all->map[k]);
}