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
# define LOOSE_GAME "You loose!\n"
# define XPM_CONVERT_FAIL_ENEMY "Error:\nMissing sprite asset for [ENEMY]\n"
# define XPM_CONVERT_FAIL_WALL "Error:\nMissing sprite asset for [WALL]\n"
# define XPM_CONVERT_FAIL_EMPTY "Error:\nMissing sprite asset for [EMPTY]\n"
# define XPM_CONVERT_FAIL_PLAYER "Error:\nMissing sprite asset for [PLAYER]\n"
# define XPM_CONVERT_FAIL_KEY "Error:\nMissing sprite asset for [KEY]\n"
# define XPM_CONVERT_FAIL_EXIT "Error:\nMissing sprite asset for [EXIT]\n"
# define INVALID_MAP "Error:\nInvalid map passed as an argumaent.\n"
# define INVALID_TERM_CALL "Error:\nCannot open the given map!\n"

#endif
