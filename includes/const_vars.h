/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_vars.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 02:19:01 by ede-sous          #+#    #+#             */
/*   Updated: 2017/10/13 05:50:07 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_VARS_H
# define CONST_VARS_H

# include "header.h"

# define WIDTH		    fun.width
# define HEIGHT		    fun.height
# define W_WIDTH		fun->width
# define W_HEIGHT		fun->height
# define SNAKESQ	    50
# define MOUSESQ	    50
# define Give_Delay     fun.delay
# define GIVE_Delay     fun->delay

# define SDLERR			0
# define WINERR			1
# define RENDERERR		2

# define NO_MOVE		0
# define GO_UP			1
# define GO_DOWN		2
# define GO_RIGHT		3
# define GO_LEFT		4
# define KEY_ESC		5

# define FWindow		fun.window
# define FRender        fun.render
# define FEvent			fun.event
# define FKey           fun.keys

# define FMenu          fun.menu
# define FMenuI         FMenu.i
# define FMenuSur       fun.menu.sur
# define FMenuText      fun.menu.text
# define FMenuPos       fun.menu.pos
# define FMenuSurBack   fun.menu.sur_back
# define FMenuTextBack  fun.menu.text_back
# define FMenuPosBack   fun.menu.pos_back
# define FMenuOpt       FMenu.options

# define FPMenu          fun->menu
# define FPMenuOpt       FPMenu.options

# define FRendering     fun->render
# define FKeys          fun->keys
# define FScan          fun->scan

# define FSnake			fun->snake
# define FSnakeSurface	FSnake.surface
# define FSnakeTexture  FSnake.texture
# define FSnakePosition FSnake.pos

# define FSnakeText     fun.snake.texture
# define FSnakePos      fun.snake.pos

# define FMouse          fun->mouse
# define FMouseSurface   FMouse.surface
# define FMouseTexture   FMouse.texture
# define FMousePosition  FMouse.pos

# define FMouseText      fun.mouse.texture
# define FMousePos       fun.mouse.pos

# define FSnakeXA        FSnakePosition.x
# define FSnakeXB        (FSnakeXA + SNAKESQ)
# define FSnakeYA        FSnakePosition.y
# define FSnakeYB        (FSnakeYA + SNAKESQ)

# define FMouseXA        (FMousePosition.x + (MOUSESQ / 4))
# define FMouseXB        (FMousePosition.x + ((3 * MOUSESQ) / 4))
# define FMouseYA        (FMousePosition.y + (MOUSESQ / 4))
# define FMouseYB        (FMousePosition.y + ((3 * MOUSESQ) / 4))

# define FBody           fun->snake.body
# define FBodyTmp        FSnake.tmp
# define FBodySave       FSnake.save
# define FBodySurface    FBody->surface
# define FBodyTexture    FBody->texture
# define FBodyPosition   FBody->pos
# define FBodyNext       FBody->next
# define FBodyPrev       FBody->prev

# define FBodyDot        fun.snake.body
# define FBodyDTmp       fun.snake.tmp
# define FBodyText       FBodyDot->texture
# define FBodyPos        FBodyDot->pos
# define FBodyN          FBodyDot->next

# define FSurU           fun->surs.SurU
# define FTextU          fun->surs.TextU
# define FSurD           fun->surs.SurD
# define FTextD          fun->surs.TextD
# define FSurR           fun->surs.SurR
# define FTextR          fun->surs.TextR
# define FSurL           fun->surs.SurL
# define FTextL          fun->surs.TextL
# define FSurH           fun->surs.SurH
# define FTextH          fun->surs.TextH
# define FSurV           fun->surs.SurV
# define FTextV          fun->surs.TextV

# define Fttf            fun->text
# define Ftext           fun.text

# define Fhs             fun->hs
# define FhsMenu         Fhs.menu
# define FhsInGame       Fhs.ingame
# define FhsGameOver     Fhs.gameover
# define FhsNHS          Fhs.newhighscore

# define FHs             fun.hs
# define FHsMenu         FHs.menu
# define FHsInGame       FHs.ingame
# define FHsGameOver     FHs.gameover
# define FHsNHS          FHs.newhighscore

# define Set_Body_Render FBodyDTmp = FBodyDot; \
                         while (FBodyDTmp && !FBodyDTmp->wait) \
                         { SDL_RenderCopyEx(FRender, FBodyDTmp->texture, NULL, &FBodyDTmp->pos, 0, NULL, 0); \
                         FBodyDTmp = FBodyDTmp->next;}

# define Set_Text_Render if (!(Ftext.surface = TTF_RenderText_Solid(Ftext.font, \
                            (puta = ft_strjoin("Meeseeks Created : ", ft_itoa(Mouses_Eaten(2)), 0)), Ftext.color)))\
                            Get_The_Fuck_Out_Of_This_Game(fun);\
                         Ftext.texture = SDL_CreateTextureFromSurface(FRender, Ftext.surface);

# define Verify_Snake_M  ((FMouseXA >= FSnakeXA && FMouseXA <= FSnakeXB) \
                            || (FMouseXB >= FSnakeXA && FMouseXB <= FSnakeXB)) \
                            && (((FMouseYA >= FSnakeYA && FMouseYA <= FSnakeYB) \
                            || (FMouseYB >= FSnakeYA && FMouseYB <= FSnakeYB)))

# define Verify_Body_M   (((FMouseXA >= FBodyTmp->pos.x && FMouseXA <= FBodyTmp->pos.x + SNAKESQ) \
                            || (FMouseXB >=FBodyTmp->pos.x && FMouseXB <= FBodyTmp->pos.x + SNAKESQ)) \
                            && (((FMouseYA >= FBodyTmp->pos.y && FMouseYA <= FBodyTmp->pos.y + SNAKESQ) \
                            || (FMouseYB >= FBodyTmp->pos.y && FMouseYB <= FBodyTmp->pos.y + SNAKESQ)))) \
                            || (((FMouseXA >= FSnakeXA && FMouseXA <= FSnakeXB) \
                            || (FMouseXB >= FSnakeXA && FMouseXB <= FSnakeXB)) \
                            && (((FMouseYA >= FSnakeYA && FMouseYA <= FSnakeYB) \
                            || (FMouseYB >= FSnakeYA && FMouseYB <= FSnakeYB))))

# define Verify_Eaten       (((FMouseXA >= FSnakeXA && FMouseXA <= FSnakeXB) \
                            || (FMouseXB >= FSnakeXA && FMouseXB <= FSnakeXB)) \
                            && (((FMouseYA >= FSnakeYA && FMouseYA <= FSnakeYB) \
                            || (FMouseYB >= FSnakeYA && FMouseYB <= FSnakeYB)))) \
                            || (((FSnakeXA >= FMouseXA && FSnakeXA <= FMouseXB) \
                            || (FSnakeXB >= FMouseXA && FSnakeXB <= FMouseXB)) \
                            && (((FSnakeYA >= FMouseYA && FSnakeYA <= FMouseYB) \
                            || (FSnakeYB >= FMouseYA && FSnakeYB <= FMouseYB))))

# define Ate_Himself        (((FBodyTmp->pos.x >= FSnakeXA \
                            && FBodyTmp->pos.x <= FSnakeXB \
                            && FBodyTmp->pos.y >= FSnakeYA \
                            && FBodyTmp->pos.y <= FSnakeYB)) \
                            || ((FSnakeXA >= FBodyTmp->pos.x  \
                            && FSnakeXA <= FBodyTmp->pos.x + SNAKESQ \
                            && FSnakeYA >= FBodyTmp->pos.y \
                            && FSnakeYA <= FBodyTmp->pos.y + SNAKESQ)))


#endif
