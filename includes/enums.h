/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 23:12:01 by lraggio           #+#    #+#             */
/*   Updated: 2025/01/03 23:12:02 by lraggio          ###   ########.fr       */
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
	FALSE = 3
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

#endif
