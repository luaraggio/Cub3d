/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:12:01 by lraggio           #+#    #+#             */
/*   Updated: 2025/01/14 23:03:10 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

enum	e_errors
{
	ERROR = -1,
	NO_ERROR = 0
};

enum	e_flags
{
	OFF = 0,
	ON = 1,
	TRUE = 2,
	FALSE = 3,
	END = 4
};

enum	e_map
{
	NO = 1,
	SO = 2,
	WE = 3,
	EA = 4,
	F = 5,
	C = 6
};

enum	e_key_array
{
	W_INDEX = 0,
	A_INDEX = 1,
	S_INDEX = 2,
	D_INDEX = 3,
	LEFT_INDEX = 4,
	RIGHT_INDEX = 5,
	ESC_INDEX = 6,
	TOTAL_KEYS = 7
};

#endif
