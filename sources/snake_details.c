/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_details.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 02:19:01 by ede-sous          #+#    #+#             */
/*   Updated: 2017/10/12 02:24:17 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

int             Mouses_Eaten(int val)
{
    static int  mouses = 0;

    if (!val)
        mouses = 0;
    else if (val == 1)
        ++mouses;
    return (mouses);
}

static void     Fill_Body_Components(t_fun *fun, int val)
{ 
    FBodyTmp->pos.x = (val ? FBodySave->pos.x : FSnakePosition.x);
    FBodyTmp->pos.y = (val ? FBodySave->pos.y : FSnakePosition.y);
    FBodyTmp->pos.w = SNAKESQ;
    FBodyTmp->pos.h = SNAKESQ;
    FBodyTmp->wait = (!FBodyTmp->prev ? 1 : FBodyTmp->prev->wait + 1);
}

void            Expand_Snake(t_fun *fun)
{
    if (!FBody)
    {
        if (!(FBody = (t_body*)malloc(sizeof(t_body))))
            Get_The_Fuck_Out_Of_This_Game(*fun);
        FBodyTmp = FBody;
        FBodyTmp->prev = NULL;
        FBodyTmp->next = NULL;
        Fill_Body_Components(fun, 0);
        FBody = FBodyTmp;
        FBodySave = FBody;
    }
    else
    {
        FBodyTmp = FBody;
        while (FBodyTmp->next)
            FBodyTmp = FBodyTmp->next;
        FBodySave = FBodyTmp;
        FBodyTmp = FBodyTmp->next;
        if (!(FBodyTmp = (t_body*)malloc(sizeof(t_body))))
            Get_The_Fuck_Out_Of_This_Game(*fun);
        FBodyTmp->prev = FBodySave;
        FBodySave->next = FBodyTmp;
        Fill_Body_Components(fun, 1);
        FBodyTmp->next = NULL;
        FBodySave = FBodyTmp;
    }
    Mouses_Eaten(1);
}

void              Get_Good_Texture(t_fun *fun)
{
    FSnakeSurface = (fun->mouvement <= GO_UP ? FSurU : (fun->mouvement == GO_DOWN ? FSurD :
                    (fun->mouvement == GO_RIGHT ? FSurR : FSurL)));
    FSnakeTexture = (fun->mouvement <= GO_UP ? FTextU : (fun->mouvement == GO_DOWN ? FTextD :
                    (fun->mouvement == GO_RIGHT ? FTextR : FTextL)));
    FBodyTmp = FBody;
    while (FBodyTmp)
    {
        if (!FBodyTmp->prev)
        {
            FBodyTmp->surface = (FSnakeXA == FBodyTmp->pos.x ? FSurV : FSurH);
            FBodyTmp->texture = (FSnakeXA == FBodyTmp->pos.x ? FTextV : FTextH);
        }
        else
        {
            FBodyTmp->surface = (FBodyTmp->prev->pos.x == FBodyTmp->pos.x ? FSurV : FSurH);
            FBodyTmp->texture = (FBodyTmp->prev->pos.x == FBodyTmp->pos.x ? FTextV : FTextH);
        }
        FBodyTmp = FBodyTmp->next;
    }
}

void              Get_Highscores(t_fun * fun)
{
    if (!(FhsMenu.surface = TTF_RenderText_Blended(Fttf.font2, ft_strjoin("Highscore : ", ft_itoa(Fhs.highscore), 0), FhsMenu.color)))
        Get_The_Fuck_Out_Of_This_Game(*fun);
    if (!(FhsInGame.surface = TTF_RenderText_Blended(Fttf.font, ft_strjoin("Highscore : ", ft_itoa(Fhs.highscore), 0), FhsInGame.color)))
        Get_The_Fuck_Out_Of_This_Game(*fun);
    if (!(FhsGameOver.surface = TTF_RenderText_Blended(Fttf.font2, ft_strjoin("Highscore : ", ft_itoa(Fhs.highscore), 0), FhsGameOver.color)))
        Get_The_Fuck_Out_Of_This_Game(*fun);
    TTF_SizeText(Fttf.font2, ft_strjoin("Well Played ! New Highscore : ", ft_itoa(Fhs.highscore), 0), &FhsNHS.pos.w, &FhsNHS.pos.h);
    if (FhsNHS.pos.w > W_WIDTH)
        FhsNHS.pos.w -= (W_WIDTH / 3);
    FhsNHS.pos.x = (W_WIDTH / 2) - (FhsNHS.pos.w / 2);
    FhsNHS.pos.y = ((2 * W_HEIGHT) / 3) + 100;
    if (!(FhsNHS.surface = TTF_RenderText_Blended(Fttf.font2,
                                                    ft_strjoin("Well Played ! New Highscore : ", ft_itoa(Fhs.highscore), 0), FhsNHS.color)))
        Get_The_Fuck_Out_Of_This_Game(*fun);
    FhsMenu.texture = SDL_CreateTextureFromSurface(FRendering, FhsMenu.surface);
    FhsInGame.texture = SDL_CreateTextureFromSurface(FRendering, FhsInGame.surface);
    FhsGameOver.texture = SDL_CreateTextureFromSurface(FRendering, FhsGameOver.surface);
    FhsNHS.texture = SDL_CreateTextureFromSurface(FRendering, FhsNHS.surface);
}