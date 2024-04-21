/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <gmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:26:26 by gmorelli          #+#    #+#             */
/*   Updated: 2024/04/04 16:33:38 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b1("Giovanni", 3);
		std::cout << b1;
		b1.incGrade();
		std::cout << b1;
		b1.incGrade();
		std::cout << b1;
		b1.incGrade();
		std::cout << b1;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b2("Giovanni", 150);
		std::cout << b2;
		b2.decGrade();
		std::cout << b2;
		b2.decGrade();
		std::cout << b2;
		b2.decGrade();
		std::cout << b2;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}