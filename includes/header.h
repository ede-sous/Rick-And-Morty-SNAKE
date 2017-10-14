/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 02:19:01 by ede-sous          #+#    #+#             */
/*   Updated: 2017/10/15 00:11:08 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../Libft/libft.h"
# include "../.sdl2/SDL.h"
# include "../.sdl2/SDL_image.h"
# include "../.sdl2/SDL_ttf.h"
# include "const_vars.h"

typedef	struct			s_surs
{
	SDL_Surface			*SurU;
	SDL_Texture			*TextU;
	SDL_Surface			*SurD;
	SDL_Texture			*TextD;
	SDL_Surface			*SurR;
	SDL_Texture			*TextR;
	SDL_Surface			*SurL;
	SDL_Texture			*TextL;
	SDL_Surface			*SurH;
	SDL_Texture			*TextH;
	SDL_Surface			*SurV;
	SDL_Texture			*TextV;
}						t_surs;

typedef struct			s_mouse
{
	SDL_Surface			*surface;
	SDL_Texture			*texture;
	SDL_RWops			*wops;
	SDL_Rect			pos;
}						t_mouse;

typedef struct          s_body
{
	SDL_Surface			*surface;
    SDL_Texture			*texture;
    SDL_Rect			pos;
    int                 wait;
    struct s_body       *next;
    struct s_body       *prev;
}                       t_body;

typedef struct			s_back
{
	SDL_Surface			*surface;
	SDL_Texture			*texture;
	SDL_Rect			pos;
}						t_back;

typedef struct			s_snake
{
	SDL_Surface			*surface;
	SDL_Texture			*texture;
	SDL_Rect			pos;
    t_body              *body;
    t_body              *tmp;
	t_body              *save;
}						t_snake;

typedef struct			s_text
{
	SDL_Surface			*surface;
	SDL_Texture			*texture;
	TTF_Font			*font;
	TTF_Font			*font2;
	SDL_Rect			pos;
	SDL_Color			color;
	SDL_Color			black;
	SDL_Color			yellow;
	SDL_Color			red;
	SDL_Color			lava;
}						t_text;

typedef struct			s_pause
{
	SDL_Surface			*surface;
	SDL_Texture			*texture;
	SDL_Rect			pos;
	SDL_Color			color;
}						t_pause;

typedef struct			s_gameover
{
	SDL_Surface			*sur;
	SDL_Texture			*text;
	SDL_Rect			pos;
	SDL_Surface			*sur_back;
	SDL_Texture			*text_back;
	SDL_Rect			pos_back;
}						t_gameover;

typedef struct			s_menu
{
	int					i;
	SDL_Surface			*sur1;
	SDL_Surface			*sur1_slct;
	SDL_Surface			*sur2;
	SDL_Surface			*sur2_slct;
	SDL_Surface			*sur_back;
	SDL_Texture			*text1;
	SDL_Texture			*text1_slct;
	SDL_Texture			*text2;
	SDL_Texture			*text2_slct;
	SDL_Texture			*text_back;
	SDL_Rect			pos_back;
	SDL_Rect			pos1;
	SDL_Rect			pos2;
	t_text				options;
}						t_menu;

typedef struct			s_highscore
{
	t_pause				menu;
	t_pause				ingame;
	t_pause				gameover;
	t_pause				newhighscore;
	int					score;
	int					highscore;
	int					fd;
	char				*line;
}						t_highscore;

typedef struct			s_fun
{
	SDL_Window			*window;
	SDL_Renderer		*render;
	SDL_Event			event;
	t_mouse				mouse;
	t_snake				snake;
	t_surs				surs;
	t_back				back;
	t_text				text;
	t_pause				pause_center;
	t_pause				pause_back;
	t_gameover			ww;
	t_menu				menu;
	t_highscore			hs;
	int					width;
	int					height;
	const Uint8			*keys;
	int					mouvement;
	int					i;
	int					x;
	int					scan[5];
	int					boo;
	int					delay;
	int					fd;
	char				*line;
}						t_fun;

int                     Mouses_Eaten(int val);

void	    			First_Screen(t_fun fun, int value);
void					Ft_Menu(t_fun fun);
void					Ft_Pause(t_fun *fun, int key);
void					Init_Animals(t_fun *fun);
void					Snake_Movement(t_fun *fun);
void                    Expand_Snake(t_fun *fun);
void              		Get_Good_Texture(t_fun *fun);
void              		Get_Highscores(t_fun * fun);
void                    Get_The_Fuck_Out_Of_This_Game(t_fun fun);

SDL_Rect				Init_Snake_Position(t_fun *fun);
SDL_Rect				Init_Mouse_Position(t_fun *fun);
SDL_Rect        		Init_Back_Position(t_fun *fun);

void                	Random_Boost(t_fun *fun);
void                	Boost_Speed(int value, t_fun *fun);
void               		Expand_One(t_fun *fun);

#endif
