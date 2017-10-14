/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_animals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 02:19:01 by ede-sous          #+#    #+#             */
/*   Updated: 2017/10/13 06:12:28 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void          Init_Snake(t_fun *fun)
{
    FSnakePosition = Init_Snake_Position(fun);
    FBody = NULL;
}


static void          Init_Mouse(t_fun *fun)
{
    FMousePosition = Init_Mouse_Position(fun);
    FMouseSurface = IMG_Load(".img/mouse.png");
    FMouseTexture = SDL_CreateTextureFromSurface(FRendering, FMouseSurface);
}

static void        Init_Scan(t_fun *fun)
{
    FScan[GO_UP - 1] = SDL_SCANCODE_UP;
    FScan[GO_DOWN - 1] = SDL_SCANCODE_DOWN;
    FScan[GO_RIGHT - 1] = SDL_SCANCODE_RIGHT;
    FScan[GO_LEFT - 1] = SDL_SCANCODE_LEFT;
    FScan[KEY_ESC - 1] = SDL_SCANCODE_ESCAPE;
    FSurU = IMG_Load(".img/snake_head.png");
    FSurD = IMG_Load(".img/snake_head_1.png");
    FSurR = IMG_Load(".img/snake_head_2.png");
    FSurL = IMG_Load(".img/snake_head_3.png");
    FSurV = IMG_Load(".img/snake_body.png");
    FTextU = SDL_CreateTextureFromSurface(FRendering, FSurU);
    FTextD = SDL_CreateTextureFromSurface(FRendering, FSurD);
    FTextR = SDL_CreateTextureFromSurface(FRendering, FSurR);
    FTextL = SDL_CreateTextureFromSurface(FRendering, FSurL);
    FTextV = SDL_CreateTextureFromSurface(FRendering, FSurV);
    FTextH = FTextV;
}

static void       Init_Back(t_fun *fun)
{
    fun->back.pos = Init_Back_Position(fun);
    fun->back.surface = IMG_Load(".img/background.jpg");
    fun->back.texture = SDL_CreateTextureFromSurface(FRendering, fun->back.surface);
}

static void       Init_Text(t_fun *fun)
{
    SDL_Color	color={255, 255, 255};
    SDL_Color	black={0, 0, 0, 255};
    SDL_Color	yellow={255, 255, 102, 255};
    SDL_Color	red={255, 0, 0, 255};
    SDL_Color	lava={227, 77, 40, 255};

    if (!(Fttf.font = TTF_OpenFont(".img/Arial.ttf", 150))
    || !(Fttf.font2 = TTF_OpenFont(".img/AmericanTypewriter.ttc", 150)))
    {
        PEFD("Not finding fonts...\n", 2);
        Get_The_Fuck_Out_Of_This_Game(*fun);
    }
    Fttf.pos.x = 10;
    Fttf.pos.y = 5;
    Fttf.pos.w = 200;
    Fttf.pos.h = 20;
    Fttf.color = color;
    Fttf.black = black;
    Fttf.yellow = yellow;
    Fttf.red = red;
    Fttf.lava = lava;
}

static void       Init_Pause(t_fun *fun)
{
    fun->pause_center.surface = IMG_Load(".img/pause.png");
    fun->pause_center.texture = SDL_CreateTextureFromSurface(FRendering, fun->pause_center.surface);
    fun->pause_center.pos.w = 851;
    fun->pause_center.pos.h = 477;
    fun->pause_center.pos.x = (W_WIDTH / 2) - ((851 / 2) + (851 % 2));
    fun->pause_center.pos.y = (W_HEIGHT / 2) - ((477 / 2) + (477 % 2));
    fun->pause_back.surface = IMG_Load(".img/pause_back.jpg");
    fun->pause_back.texture = SDL_CreateTextureFromSurface(FRendering, fun->pause_back.surface);
    fun->pause_back.pos.w = W_WIDTH;
    fun->pause_back.pos.h = W_HEIGHT;
    fun->pause_back.pos.x = 0;
    fun->pause_back.pos.y = 0;
}

static void       Init_Menu(t_fun *fun)
{
    FPMenu.pos_back.w = W_WIDTH;
    FPMenu.pos_back.h = W_HEIGHT;
    FPMenu.pos_back.x = 0;
    FPMenu.pos_back.y = 0;
    FPMenu.sur_back = IMG_Load(".img/menu_back.jpg");
    FPMenu.text_back = SDL_CreateTextureFromSurface(FRendering, fun->menu.sur_back);
    TTF_SizeText(Fttf.font2, "Start", &FPMenu.pos1.w, &FPMenu.pos1.h);
    TTF_SizeText(Fttf.font2, "Quit", &FPMenu.pos2.w, &FPMenu.pos2.h);
    FPMenu.pos1.x = (W_WIDTH / 2) - (FPMenu.pos1.w / 2);
    FPMenu.pos1.y = (W_HEIGHT / 2) - (FPMenu.pos1.h);
    FPMenu.pos2.x = (W_WIDTH / 2) - (FPMenu.pos2.w / 2);
    FPMenu.pos2.y = (W_HEIGHT / 2) + (FPMenu.pos2.h / 2);
    if (!(FPMenu.sur1 = TTF_RenderText_Blended(Fttf.font2, "Start", Fttf.color)))
        Get_The_Fuck_Out_Of_This_Game(*fun);
    if (!(FPMenu.sur2 = TTF_RenderText_Blended(Fttf.font2, "Quit", Fttf.color)))
        Get_The_Fuck_Out_Of_This_Game(*fun);
    if (!(FPMenu.sur1_slct = TTF_RenderText_Shaded(Fttf.font2, "Start", Fttf.color, Fttf.yellow)))
        Get_The_Fuck_Out_Of_This_Game(*fun);
    if (!(FPMenu.sur2_slct = TTF_RenderText_Shaded(Fttf.font2, "Quit", Fttf.color, Fttf.yellow)))
        Get_The_Fuck_Out_Of_This_Game(*fun);
    FPMenu.text1 = SDL_CreateTextureFromSurface(FRendering, FPMenu.sur1);
    FPMenu.text2 = SDL_CreateTextureFromSurface(FRendering, FPMenu.sur2);
    FPMenu.text1_slct = SDL_CreateTextureFromSurface(FRendering, FPMenu.sur1_slct);
    FPMenu.text2_slct = SDL_CreateTextureFromSurface(FRendering, FPMenu.sur2_slct);
}

static void       Init_GameOver(t_fun *fun)
{
    fun->ww.pos.w = 800;
    fun->ww.pos.h = 300;
    fun->ww.pos.x = (W_WIDTH / 2) - 400;
    fun->ww.pos.y = (W_HEIGHT / 3) - 200;
    fun->ww.sur = IMG_Load(".img/game_over.png");
    fun->ww.text = SDL_CreateTextureFromSurface(FRendering, fun->ww.sur);
    fun->ww.pos_back.w = W_WIDTH;
    fun->ww.pos_back.h = W_HEIGHT;
    fun->ww.pos_back.x = 0;
    fun->ww.pos_back.y = 0;
    fun->ww.sur_back = IMG_Load(".img/game_over_back.jpg");
    fun->ww.text_back = SDL_CreateTextureFromSurface(FRendering, fun->ww.sur_back);
}

static void       Init_HighScore(t_fun *fun)
{
    fun->hs.score = 0;

    if (access(".img/.highscore", F_OK) == -1)
        system("echo 0 > .img/.highscore");
    if ((Fhs.fd = open(".img/.highscore", O_RDWR)) == -1)
        Get_The_Fuck_Out_Of_This_Game(*fun);
    if ((get_next_line(Fhs.fd, &Fhs.line) == -1))
        Get_The_Fuck_Out_Of_This_Game(*fun);
    close(Fhs.fd);
    Fhs.highscore = ft_atoi(Fhs.line);
    ft_strdel(&Fhs.line);
    Fhs.score = 0;
    FhsMenu.color = Fttf.color;
    FhsInGame.color = Fttf.color;
    FhsGameOver.color = Fttf.red;
    FhsNHS.color = Fttf.lava;
    FhsMenu.pos.x = 10;
    FhsMenu.pos.y = 5;
    FhsMenu.pos.w = 500;
    FhsMenu.pos.h = 100;
    FhsInGame.pos.x = 10;
    FhsInGame.pos.y = 25;
    FhsInGame.pos.w = 100;
    FhsInGame.pos.h = 20;
    FhsGameOver.pos.x = 10;
    FhsGameOver.pos.y = 5;
    FhsGameOver.pos.w = 500;
    FhsGameOver.pos.h = 100;
    Get_Highscores(fun);
}

void              Init_Animals(t_fun *fun)
{
    if (IMG_Init(~0) == -1 || TTF_Init() == -1)
        Get_The_Fuck_Out_Of_This_Game(*fun);
    Init_Snake(fun);
    Init_Text(fun);
    srand(time(NULL));
    Init_Mouse(fun);
    while (Verify_Snake_M)
        FMousePosition = Init_Mouse_Position(fun);
    Init_Scan(fun);
    Init_Back(fun);
    Init_Pause(fun);
    Init_Menu(fun);
    Init_GameOver(fun);
    Init_HighScore(fun);
    GIVE_Delay = 50;
}