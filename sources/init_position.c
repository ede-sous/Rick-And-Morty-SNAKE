/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-sous <ede-sous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 02:19:01 by ede-sous          #+#    #+#             */
/*   Updated: 2017/10/13 05:51:22 by ede-sous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

SDL_Rect		Init_Snake_Position(t_fun *fun)
{
	SDL_Rect	pos;

	pos.x = W_WIDTH / 2 + (W_WIDTH / 2) % SNAKESQ;
	pos.y = W_HEIGHT / 2;
	pos.w = SNAKESQ;
	pos.h = SNAKESQ;
	return (pos);
}

SDL_Rect        Init_Mouse_Position(t_fun *fun)
{
    SDL_Rect	pos;

    pos.x = rand() % (W_WIDTH - MOUSESQ);
    pos.y = rand() % (W_HEIGHT - MOUSESQ);
    pos.w = MOUSESQ;
    pos.h = MOUSESQ;
    return (pos);
}

SDL_Rect        Init_Back_Position(t_fun *fun)
{
    SDL_Rect	pos;

    pos.x = 0;
    pos.y = 0;
    pos.w = W_WIDTH;
    pos.h = W_HEIGHT;
    return (pos);
}
