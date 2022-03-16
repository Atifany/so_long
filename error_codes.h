/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_codes.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atifany <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 18:35:58 by atifany           #+#    #+#             */
/*   Updated: 2022/03/11 18:35:59 by atifany          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_CODES_H
# define ERROR_CODES_H

# define ESC_PRESSED "Exit program on ESC pressed.\n"
# define EXIT_PRESSED "Exit program on X pressed.\n"
# define WIN_GAME "You won!\n"
# define XPM_CONVERT_FAIL_ENEMY "Error:\nMissing sprite asset for [ENEMY]\n"
# define XPM_CONVERT_FAIL_WALL "Error:\nMissing sprite asset for [WALL]\n"
# define XPM_CONVERT_FAIL_EMPTY "Error:\nMissing sprite asset for [EMPTY]\n"
# define XPM_CONVERT_FAIL_PLAYER "Error:\nMissing sprite asset for [PLAYER]\n"
# define XPM_CONVERT_FAIL_KEY "Error:\nMissing sprite asset for [KEY]\n"
# define XPM_CONVERT_FAIL_EXIT "Error:\nMissing sprite asset for [EXIT]\n"
# define INVALID_MAP_SYMBOLS "Error:\nInvalid map passed as an argumaent\n"\
	"There are unexpected symbols on the map!\n"
# define INVALID_MAP_LINES "Error:\nInvalid map passed as an argumaent\n"\
	"Map isn't rectangular!\n"
# define INVALID_MAP_DUPLICATE "Error:\nInvalid map passed as an argumaent.\n"\
	"There are two players or exits!\n"
# define INVALID_MAP_WALLS "Error:\nInvalid map passed as an argumaent.\n"\
	"Map borders are not walls!\n"
# define INVALID_TERM_CALL "Error:\nInvalid filename passed as an argument.\n"\
	"Usage: ./so_long [map_filename.ber]\nMap file has to be in a maps folder!\n"

#endif
