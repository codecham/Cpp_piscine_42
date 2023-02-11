/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:44:41 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/06 20:12:30 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <string>
#include <fstream>

void	ft_print_error_file(std::string file_name);
void	ft_print_error_param();
void	ft_check_arg(std::string file, std::string s1, std::string s2);

#endif