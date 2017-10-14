/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 02:16:49 by ede-sous          #+#    #+#             */
/*   Updated: 2017/10/15 00:07:32 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/header.h"

void            Get_The_Fuck_Out_Of_This_Game(t_fun fun)
{
	if (FHs.score)
		system("mail -s highscore/$USER hollowbodies.25@gmail.com < .img/.highscore");
	system("killall sh | killall afplay");
	system("rm -rf .img .sound");
    SDL_DestroyRenderer(FRender);
	SDL_DestroyWindow(FWindow);
	IMG_Quit();
	TTF_Quit();
	SDL_Quit();
    exit(EXIT_SUCCESS);
}

static int		Ft_Error(int value)
{
	if (value == SDLERR)
		ft_putendl_fd("SDL: init error", 2);
	if (value == WINERR)
		ft_putendl_fd("SDL: error creating the window", 2);
	if (value == RENDERERR)
		ft_putendl_fd("SDL: error creating the renderer", 2);
	return (-1);
}

static void			Put_Info(void)
{
	PE("The box can do different stuff, randomly !");
	PE("The box can :");
	PE("->>   Give you a Meeseeks                            == ` I'm Mr.Meeseks `");
	PE("->>   Give you 3 Meeseeks                            == ` You gotta get Schwifty `");
	PE("->>   Give you half of your current Meeseeks         == ` Wubba lubba dub dub `");
	PE("->>   Give you a freaking speed boost                == ` Pickle Rick Remix `");
	PE("->>   Give you a really fucking slow boost           == ` Tiny Rick Song `");
	PE("->>   Take out one Meeseeks                          == ` Existence is Pain `");
	PE("->>   Take out HALF of your FREAKING current Meeseks == ` I just Want to die, We all want to die`");
	PE(NULL);
	PE("`OMG I gotta keep my volume in max to hear it ....`");
	PE("FUCK YOU, SUFFER IN PEACE ! This game was done to make you suffer !");
	PE("`OMG The back key isn't blocked !!`");
	PE("Read My last FUCKING ANSWER, Think about and fuck out ! SUFFER IN PEACE !");
	PE(NULL);
	PE("The goal of this game it to create the much many Meeseeks you can, your highscore is always going to be updated !");
	PE("If you make another Highscore different than what it is written on my GitHub, contact me and send me a video of you doing it");
	PE("I don't believe in screenshots; Anyway, I'll update it !");
	PE("Now stop reading and play !! Get rekted, suffer in peace, and suffer !");
	PE(NULL);
	PE("PS: Something not working ? Re git clone... Still ? Contact me.");
}

static void			Get_Display(t_fun *fun)
{
	system("system_profiler SPDisplaysDataType | grep Resolution: | cut -f 12 -d ' ' > width\
	&& system_profiler SPDisplaysDataType | grep Resolution: | cut -f 14 -d ' ' > height");
	if (access("width", F_OK) || access("height", F_OK))
		exit(-1);
	fun->fd = open("width", O_RDONLY);
	get_next_line(fun->fd, &fun->line);
	W_WIDTH = ft_atoi(fun->line);
	ft_strdel(&fun->line);
	close(fun->fd);
	fun->fd = open("height", O_RDONLY);
	get_next_line(fun->fd, &fun->line);
	W_HEIGHT = ft_atoi(fun->line);
	ft_strdel(&fun->line);
	close(fun->fd);
	system("rm -rf height width");
	if (W_WIDTH > 2560)
		W_WIDTH = 2560;
	if (W_HEIGHT > 1440)
		W_HEIGHT = 1440;
}

static void		 Download_Everything(void)
{
	system("mkdir .img && mkdir .sound && chmod 777 .img && chmod 777 .sound");
	system("curl -O https://raw.githubusercontent.com/ede-sous/Rick-and-Morty-Snake-Stock/master/.sound/expand_half.mp3 \
	-O https://raw.githubusercontent.com/ede-sous/Rick-and-Morty-Snake-Stock/master/.sound/expand_more.mp3 \
	-O https://raw.githubusercontent.com/ede-sous/Rick-and-Morty-Snake-Stock/master/.sound/game_music.mp3 \
	-O https://raw.githubusercontent.com/ede-sous/Rick-and-Morty-Snake-Stock/master/.sound/game_over.mp3 \
	-O https://raw.githubusercontent.com/ede-sous/Rick-and-Morty-Snake-Stock/master/.sound/half_out.mp3 \
	-O https://raw.githubusercontent.com/ede-sous/Rick-and-Morty-Snake-Stock/master/.sound/menu.mp3 \
	-O https://raw.githubusercontent.com/ede-sous/Rick-and-Morty-Snake-Stock/master/.sound/one_out.mp3 \
	-O https://raw.githubusercontent.com/ede-sous/Rick-and-Morty-Snake-Stock/master/.sound/slow_speed.mp3 \
	-O https://raw.githubusercontent.com/ede-sous/Rick-and-Morty-Snake-Stock/master/.sound/speed_boost.mp3 \
	-O https://raw.githubusercontent.com/ede-sous/Rick-and-Morty-Snake-Stock/master/.sound/turtle.mp3 \
	");
	system("mv *.mp3 .sound/");
	system("curl -O https://raw.githubusercontent.com/ede-sous/Rick-and-Morty-Snake-Stock/master/.img/.highscore \
	-O https://raw.githubusercontent.com/ede-sous/Rick-and-Morty-Snake-Stock/master/.img/AmericanTypewriter.ttc \
	-O https://raw.githubusercontent.com/ede-sous/Rick-and-Morty-Snake-Stock/master/.img/Arial.ttf \
	-O https://raw.githubusercontent.com/ede-sous/Rick-and-Morty-Snake-Stock/master/.img/background.jpg \
	-O https://raw.githubusercontent.com/ede-sous/Rick-and-Morty-Snake-Stock/master/.img/game_over.png \
	-O https://raw.githubusercontent.com/ede-sous/Rick-and-Morty-Snake-Stock/master/.img/game_over_back.jpg \
	-O https://raw.githubusercontent.com/ede-sous/Rick-and-Morty-Snake-Stock/master/.img/menu_back.jpg \
	-O https://raw.githubusercontent.com/ede-sous/Rick-and-Morty-Snake-Stock/master/.img/mouse.png \
	-O https://raw.githubusercontent.com/ede-sous/Rick-and-Morty-Snake-Stock/master/.img/pause.png \
	-O https://raw.githubusercontent.com/ede-sous/Rick-and-Morty-Snake-Stock/master/.img/pause_back.jpg \
	-O https://raw.githubusercontent.com/ede-sous/Rick-and-Morty-Snake-Stock/master/.img/snake_body.png \
	-O https://raw.githubusercontent.com/ede-sous/Rick-and-Morty-Snake-Stock/master/.img/snake_head.png \
	-O https://raw.githubusercontent.com/ede-sous/Rick-and-Morty-Snake-Stock/master/.img/snake_head_1.png \
	-O https://raw.githubusercontent.com/ede-sous/Rick-and-Morty-Snake-Stock/master/.img/snake_head_2.png \
	-O https://raw.githubusercontent.com/ede-sous/Rick-and-Morty-Snake-Stock/master/.img/snake_head_3.png \
	");
	system("mv *.jpg *.png *.ttc *.ttf .highscore .img/");
	system("chmod 777 .img/* && chmod 777 .sound/*");
}

int					main(void)
{
	t_fun			fun;

	Download_Everything();
	Get_Display(&fun);
	Put_Info();
	if ((SDL_Init(SDL_INIT_VIDEO)) != 0)
		return (Ft_Error(SDLERR));
	if (!(FWindow = SDL_CreateWindow("What The Fuck ?!?",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT,
		SDL_WINDOW_FULLSCREEN)))
		return (Ft_Error(WINERR));
	if (!(FRender = SDL_CreateRenderer(FWindow, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)))
		return (Ft_Error(RENDERERR));
	SDL_SetRenderDrawColor(FRender, 0, 0, 0, 0);
	Init_Animals(&fun);
	First_Screen(fun, 1);
    Get_The_Fuck_Out_Of_This_Game(fun);
}
