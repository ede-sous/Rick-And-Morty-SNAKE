/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boosts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 02:19:01 by ede-sous          #+#    #+#             */
/*   Updated: 2017/10/13 07:07:48 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

void                Boost_Speed(int value, t_fun *fun)
{
	static int      boost = 200;
	static int      what = 0;

	if (value > 0 && what == 0)
	{
		Expand_One(fun);
		system("killall sh | killall afplay");
		system(value == 1 ? "afplay .sound/speed_boost.mp3 &>/dev/null &"
				: "afplay .sound/slow_speed.mp3 &>/dev/null &");
	}
	if (!fun)
	{
		boost = 200;
		what = 0;
		return ;
	}
	if (what == 0 && value && boost >= 200)
	{
		boost = 0;
		what = value;
	}
	else if (what == 1 && boost < 400)
		GIVE_Delay = 0;
	else if (what == 2 && boost < 200)
		GIVE_Delay = 120;
	else
		GIVE_Delay = 50;
	if ((boost >= 200 && what == 2) || (boost >= 400 && what == 1))
	{
		system("killall afplay");
		system ("while :;do afplay .sound/game_music.mp3; done &>/dev/null &");
		what = 0;
	}
	else
		boost++;
}

static void         Expand_More(t_fun *fun)
{
	int             i = 0;

	if (Mouses_Eaten(2) < 4)
	{
		Expand_One(fun);
		return ;
	}
	system("afplay .sound/expand_more.mp3 &>/dev/null &");
	while (++i < 4)
		Expand_Snake(fun);
}

static void         Take_Half_Body(t_fun *fun)
{
	int             suffer = Mouses_Eaten(2), i = 0;

	if (suffer < 4)
	{
		Expand_One(fun);
		return ;
	}
	system("afplay .sound/half_out.mp3 &>/dev/null &");
	Mouses_Eaten(0);
	suffer = (suffer / 2) + (suffer % 2);
	FBodyTmp = FBody;
	while (++i <= suffer)
	{
		Mouses_Eaten(1);
		FBodyTmp = FBodyTmp->next;
	}
	FBodyTmp = FBodyTmp->prev;
	FBodyTmp->next = NULL;
}

static void			Expand_Half(t_fun *fun)
{
	int				yey = Mouses_Eaten(2), i = 0;

	if (Fhs.highscore && (yey <= 1 || yey > (Fhs.highscore / 2)))
	{
		Expand_One(fun);
		return ;
	}
	system("afplay .sound/expand_half.mp3 &>/dev/null &");
	while (++i <= yey)
		Expand_Snake(fun);
	FBodyTmp->next = NULL;
}


static void         Take_One_Out(t_fun *fun)
{
	int             suffer = Mouses_Eaten(2), i = 0;

	if (suffer < 4)
	{
		Expand_One(fun);
		return ;
	}
	Mouses_Eaten(0);
	suffer -= 1;
	FBodyTmp = FBody;
	system("afplay .sound/one_out.mp3 &>/dev/null &");
	while (++i <= suffer)
	{
		Mouses_Eaten(1);
		FBodyTmp = FBodyTmp->next;
	}
	FBodyTmp = FBodyTmp->prev;
	FBodyTmp->next = NULL;
}

void               Expand_One(t_fun *fun)
{
	system("afplay .sound/turtle.mp3 &>/dev/null &");
	Expand_Snake(fun);
}

void				Random_Boost(t_fun *fun)
{
	int				random;
	int				fy;

	random = (rand() % 26);
	fy = Mouses_Eaten(2);
	if (random == 25 || (fy > (Fhs.highscore / 2) && random >= 20 && random <= 26))
		Boost_Speed(1, fun);
	else if (random == 16)
		Boost_Speed(2, fun);
	else if (random == 9 || (fy > ((2 * Fhs.highscore) / 3) && random < 8))
		Take_Half_Body(fun);
	else if (random == 8)
		Expand_More(fun);
	else if (random == 10)
		Take_One_Out(fun);
	else if (random == 22)
		Expand_Half(fun);
	else
		Expand_One(fun);
}
