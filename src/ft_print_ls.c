
#include "ft_ls.h"

void
	ft_print_ls(t_ls_block b, int len, char *flag)
{
	int			total;
	int			i;
	char		*str;

	total = 0;
	i = -1;
	while (++i < len)
		total += b.info[i].buff.st_blocks * (b.info[i].name[0] != '.');
	if (len > 0 && is_flag_ls(flag, 'l'))
		ft_printf("total %d\n", total);
	if (len > 0)
		str = get_print_str(b.info, 0, len - 1);
	i = -1;
	while (++i < len)
	{
		if (is_flag_ls(flag, 'l'))
		{
			if (b.info[i].name[0] != '.' || is_flag_ls(flag, 'a'))
			{
				ft_printf(str, b.info[i].mode, b.info[i].buff.st_nlink,
					b.info[i].owner->pw_name, b.info[i].group->gr_name,
					b.info[i].buff.st_size, b.info[i].time, b.info[i].name);
				if (b.info[i].link_name != NULL)
					ft_printf(" -> %s", b.info[i].link_name);
				ft_printf("\n");
			}
		}
		else
		{
			if (b.info[i].name[0] != '.' || is_flag_ls(flag, 'a'))
				ft_printf("%s", b.info[i].name);
			if ((b.info[i].name[0] != '.' || is_flag_ls(flag, 'a')) &&
					b.error != ITS_FILE)
				ft_putchar('\n');
		}
	}
	if (len > 0)
		free(str);
}