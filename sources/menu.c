/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 02:16:49 by ede-sous          #+#    #+#             */
/*   Updated: 2017/10/14 22:40:44 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

static void		Ft_Pause_Extra(t_fun *fun)
{
	system("osascript -e \"set Volume 0\" &>/dev/null&");
	if (Fhs.score)
		system("mail -s highscore/$USER hollowbodies.25@gmail.com < .img/.highscore");
	SDL_RenderClear(FRendering);
	SDL_RenderCopyEx(FRendering, fun->pause_back.texture, NULL, &fun->pause_back.pos, 0, NULL, 0);
	SDL_RenderCopyEx(FRendering, fun->pause_center.texture, NULL, &fun->pause_center.pos, 0, NULL, 0);
	SDL_RenderPresent(FRendering);
	SDL_Delay(50);
	Ft_Pause(fun, SDL_SCANCODE_SPACE);
	system ("osascript -e \"set Volume 2\" &>/dev/null&");
}

void			Ft_Pause(t_fun *fun, int key)
{
	while (1)
	{
		SDL_PollEvent(&fun->event);
		SDL_WaitEvent(&fun->event);
		if (fun->event.type == SDL_KEYDOWN && FKeys[key])
			break;
		if (fun->event.type == SDL_KEYDOWN && FKeys[SDL_SCANCODE_ESCAPE])
			First_Screen(*fun, 0);
	}
}

static void		Exec_Event(t_fun fun)
{
	char		*puta;

    system("killall sh | killall afplay");
    system ("while :;do afplay .sound/game_music.mp3; done &>/dev/null &");
	while (FEvent.type != SDL_QUIT)
	{
		SDL_Delay(Give_Delay);
		SDL_PollEvent(&FEvent);
		if (FEvent.type == SDL_KEYDOWN && FKey[SDL_SCANCODE_SPACE])
			Ft_Pause_Extra(&fun);
        if (FKey[SDL_SCANCODE_BACKSPACE] || FKey[SDL_SCANCODE_ESCAPE])
			First_Screen(fun, 0);
		Snake_Movement(&fun);
		Get_Good_Texture(&fun);
		SDL_RenderCopyEx(FRender, fun.back.texture, NULL, &fun.back.pos, 0, NULL, 0);
		SDL_RenderCopyEx(FRender, FMouseText, NULL, &FMousePos, 0, NULL, 0);
		SDL_RenderCopyEx(FRender, FSnakeText, NULL, &FSnakePos, 0, NULL, 0);
		Set_Body_Render;
		Set_Text_Render;
		SDL_RenderCopyEx(FRender, Ftext.texture, NULL, &Ftext.pos, 0, NULL, 0);
		if (FHs.highscore < Mouses_Eaten(2) && (FHs.highscore = Mouses_Eaten(2)) && (FHs.score = 1))
			Get_Highscores(&fun);
		SDL_RenderCopyEx(FRender, FHsInGame.texture, NULL, &FHsInGame.pos, 0, NULL, 0);
		SDL_RenderPresent(FRender);
		SDL_RenderClear(FRender);
	}
}

void				Ft_Menu(t_fun fun)
{
	static t_fun 	what;

	what.boo = 1;
    if (fun.boo)
    {
        Snake_Movement(NULL);
		Exec_Event(what);
    }
    else
		what = fun;
}

static void         Activate_Menu_Background(t_fun fun)
{
	SDL_RenderCopyEx(FRender, FMenuTextBack, NULL, &FMenuPosBack, 0, NULL, 0);
	SDL_RenderCopyEx(FRender, FHsMenu.texture, NULL, &FHsMenu.pos, 0, NULL, 0);
	SDL_RenderCopyEx(FRender, (!FMenuI ? FMenu.text1_slct : FMenu.text1), NULL, &FMenu.pos1, 0, NULL, 0);
	SDL_RenderCopyEx(FRender, (FMenuI ? FMenu.text2_slct : FMenu.text2), NULL, &FMenu.pos2, 0, NULL, 0);
    SDL_RenderPresent(FRender);
}

void	    		First_Screen(t_fun tmp, int value)
{
    static t_fun    fun;

    if (value)
		fun = tmp;
	else
		fun.hs = tmp.hs;
	fun.hs.score = 0;
	FKey = SDL_GetKeyboardState(NULL);
	system("killall sh | killall afplay");
	system ("while :;do afplay .sound/menu.mp3; done &>/dev/null &");
	Activate_Menu_Background(fun);
	FMenuI = 0;
    while (1)
    {
		SDL_WaitEvent(&FEvent);
        Activate_Menu_Background(fun);
		if (FMenuI == 0 && FKey[SDL_SCANCODE_RETURN])
	    {
            SDL_RenderClear(FRender);
		    fun.boo = 0;
		    Ft_Menu(fun);
            fun.boo++;
            Ft_Menu(fun);
        }
        else if ((FMenuI == 1 && FKey[SDL_SCANCODE_RETURN]) || FKey[SDL_SCANCODE_ESCAPE])
			Get_The_Fuck_Out_Of_This_Game(fun);
        if (FKey[SDL_SCANCODE_UP] || FKey[SDL_SCANCODE_DOWN])
			FMenuI = (FMenuI == 0 ? 1 : 0);
    }
}