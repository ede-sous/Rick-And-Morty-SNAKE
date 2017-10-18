/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 02:19:01 by ede-sous          #+#    #+#             */
/*   Updated: 2017/10/14 22:25:18 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/header.h"

static void         Go_Other_Side(t_fun *fun)
{
	if (FSnakePosition.x < 0 - SNAKESQ)
		FSnakePosition.x = W_WIDTH - SNAKESQ;
	if (FSnakePosition.x > W_WIDTH)
		FSnakePosition.x = 0 - SNAKESQ / 2;
	if (FSnakePosition.y < 0 - SNAKESQ)
		FSnakePosition.y = W_HEIGHT - SNAKESQ;
	if (FSnakePosition.y > W_HEIGHT)
		FSnakePosition.y = 0 - SNAKESQ / 2;
}

static void			Game_Over_Images(t_fun *fun)
{
	system("killall sh | killall afplay");
    system ("while :;do afplay .sound/game_over.mp3; done &>/dev/null &");
	SDL_RenderCopyEx(FRendering, fun->ww.text_back, NULL, &fun->ww.pos_back, 0, NULL, 0);
	SDL_RenderCopyEx(FRendering, fun->ww.text, NULL, &fun->ww.pos, 0, NULL, 0);
}

static void			Game_Over_Text(t_fun *fun)
{
	Fttf.pos.w = W_WIDTH - (W_WIDTH / 4);
	Fttf.pos.h = 200;
	Fttf.pos.x = (W_WIDTH / 2) - (Fttf.pos.w / 2);
	Fttf.pos.y = (W_HEIGHT / 2) - (Fttf.pos.h / 2);
	if (!(Fttf.surface = TTF_RenderText_Blended(Fttf.font2, ft_strjoin(ft_strjoin("You created ", ft_itoa(Mouses_Eaten(2)), 0), " Meeseeks", 0), Fttf.lava)))
		Get_The_Fuck_Out_Of_This_Game(*fun);
	Fttf.texture = SDL_CreateTextureFromSurface(FRendering, Fttf.surface);
	SDL_RenderCopyEx(FRendering, Fttf.texture, NULL, &Fttf.pos, 0, NULL, 0);
	Fttf.pos.w = 1100;
	Fttf.pos.h = 50;
	Fttf.pos.x = (W_WIDTH / 2) - (Fttf.pos.w / 2) - 2;
	Fttf.pos.y = (W_HEIGHT / 2) + (3 * Fttf.pos.h);
	if (!(Fttf.surface = TTF_RenderText_Blended(Fttf.font2, "Press Return to start again or Escape to GET THE FUCK OUT!", Fttf.red)))
		Get_The_Fuck_Out_Of_This_Game(*fun);
	Fttf.texture = SDL_CreateTextureFromSurface(FRendering, Fttf.surface);
	SDL_RenderCopyEx(FRendering, Fttf.texture, NULL, &Fttf.pos, 0, NULL, 0);
	Fttf.pos.x = 10;
	Fttf.pos.y = 5;
	Fttf.pos.w = 200;
	Fttf.pos.h = 20;
	Boost_Speed(-1, NULL);
	if (!Fhs.score)
		SDL_RenderCopyEx(FRendering, FhsGameOver.texture, NULL, &FhsGameOver.pos, 0, NULL, 0);
	else
	{
		SDL_RenderCopyEx(FRendering, FhsNHS.texture, NULL, &FhsNHS.pos, 0, NULL, 0);
		system(ft_strjoin(ft_strjoin("echo ", ft_itoa(Fhs.highscore), 0), " > .img/.highscore", 0));
		system("mail -s highscore/$USER hollowbodies.25@gmail.com < .img/.highscore");
	}
}

static void         Its_Dead(t_fun *fun)
{
	Game_Over_Images(fun);
	Game_Over_Text(fun);
	SDL_RenderPresent(FRendering);
	Ft_Pause(fun, SDL_SCANCODE_RETURN);
	SDL_RenderClear(FRendering);
	Mouses_Eaten(0);
	SDL_Delay(50);
	if (FKeys[SDL_SCANCODE_ESCAPE])
		Get_The_Fuck_Out_Of_This_Game(*fun);
	First_Screen(*fun, 0);
}

static void         Body_Mouvement(t_fun *fun, int mouvement)
{
	if (FBody)
	{
		FBodyTmp = FBody;
		while (FBodyTmp->next)
			FBodyTmp = FBodyTmp->next;
		while (FBodyTmp)
		{
			if (!FBodyTmp->prev)
			{
				if (((mouvement == GO_UP) || (mouvement == GO_DOWN))
					&& (FBodyTmp->pos.y == FSnakePosition.y + (mouvement == GO_DOWN ? SNAKESQ + 1 : -SNAKESQ - 1)
					&& FBodyTmp->pos.x == FSnakePosition.x))
					Its_Dead(fun);
				else if (((mouvement == GO_RIGHT) || (mouvement == GO_LEFT))
					&& (FBodyTmp->pos.x == FSnakePosition.x + (mouvement == GO_RIGHT ? SNAKESQ + 1 : -SNAKESQ - 1)
					&& FBodyTmp->pos.y == FSnakePosition.y))
					Its_Dead(fun);
			}
			if (!FBodyTmp->wait)
			{
				FBodyTmp->pos.x = (FBodyTmp->prev ? FBodyTmp->prev->pos.x
													: FSnakePosition.x);
				FBodyTmp->pos.y = (FBodyTmp->prev ? FBodyTmp->prev->pos.y
													: FSnakePosition.y);
			}
			else
				FBodyTmp->wait--;
			FBodyTmp = FBodyTmp->prev;
		}
	}
}

static void         Is_It_Dead(t_fun *fun)
{
	if (!FBody)
		return ;
	FBodyTmp = FBody;
	while (FBodyTmp)
	{
		if (!FBodyTmp->wait && Ate_Himself)
			Its_Dead(fun);
		FBodyTmp = FBodyTmp->next;
	}
}

static void			Verify_Mouse_position(t_fun *fun)
{
	int				j;

	if (Verify_Eaten)
	{
		FMousePosition = Init_Mouse_Position(fun);
		j = 0;
		while (j == 0)
		{
			j = 1;
			FBodyTmp = FBody;
			while (FBodyTmp)
			{
				if (Verify_Body_M)
				{
					FMousePosition = Init_Mouse_Position(fun);
					j = 0;
				}
				FBodyTmp = FBodyTmp->next;
			}
		}
		Random_Boost(fun);
	}
}

void	            Snake_Movement(t_fun *fun)
{
	static int      mouvement = 0;

	if (!fun && !(mouvement = 0))
		return ;
	fun->i = 0;
	while (fun->i < 5 && !FKeys[FScan[fun->i]])
		++fun->i;
	mouvement = (fun->i > 4 ? mouvement : fun->i + 1);
	fun->mouvement = mouvement;
	if (mouvement == 5)
		Get_The_Fuck_Out_Of_This_Game(*fun);
	Body_Mouvement(fun, mouvement);
	if ((mouvement == GO_UP) || (mouvement == GO_DOWN))
		FSnakePosition.y += (mouvement == GO_DOWN ? SNAKESQ + 1 : -SNAKESQ - 1);
	else if (mouvement != NO_MOVE)
		FSnakePosition.x += (mouvement == GO_RIGHT ? SNAKESQ + 1 : -SNAKESQ - 1);
	Go_Other_Side(fun);
	Verify_Mouse_position(fun);
	Is_It_Dead(fun);
	Boost_Speed(0, fun);
}
