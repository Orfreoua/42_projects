/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:53:12 by orfreoua          #+#    #+#             */
/*   Updated: 2023/01/23 23:52:07 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        for (int    i = 1; i < argc; ++i)
        {
            for (char *str = argv[i]; *str != '\0'; ++str)
                std::cout << static_cast<char>(toupper(*str));
        }
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
	return (0);
}