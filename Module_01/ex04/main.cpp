/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:17:37 by dcorenti          #+#    #+#             */
/*   Updated: 2023/02/06 20:12:50 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

std::string replace_in_string(std::string line, std::string s1, std::string s2)
{
	std::string				new_string;
	unsigned long			i;

	i = 0;
	while (i < line.length())
	{
		if (line.substr(i, s1.length()) == s1)
		{
			new_string += s2;
			i += s1.length() - 1;
		}
		else
			new_string += line[i];
		i++;
	}
	return (new_string);
}

int main(int argc, char **argv)
{
	std::string		file_replace;
	std::string		input_string;
	std::string 	output_string;
	std::ifstream	input_file;
	std::ofstream	output_file;

	if (argc != 4)
		ft_print_error_param();
	ft_check_arg(argv[1], argv[2], argv[3]);
	input_file.open(argv[1]);
	if (!input_file)
		ft_print_error_file(argv[1]);
	file_replace = argv[1];
	file_replace += ".replace";
	output_file.open(file_replace);
	if (!output_file)
		ft_print_error_file(file_replace);
	while (std::getline(input_file, input_string))
		output_file << replace_in_string(input_string, argv[2], argv[3]) << std::endl;
}