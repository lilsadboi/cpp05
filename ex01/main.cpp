/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <gmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:26:26 by gmorelli          #+#    #+#             */
/*   Updated: 2024/04/08 17:26:24 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{
		Bureaucrat b1("Berlusconi", 2);
		Bureaucrat b2("Aldo Moro", 149);
		Form f1("Form1", 1, 1);
		Form f2("Form2", 148, 148);
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		b1.signForm(f1);
		b2.signForm(f2);
		b1.executeForm(f1);
		b2.executeForm(f2);
		std::cout << std::endl;
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
		b1.incGrade();
		b2.incGrade();
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		b1.signForm(f1);
		b2.signForm(f2);
		b1.executeForm(f1);
		b2.executeForm(f2);
		std::cout << std::endl;
		std::cout << f1 << std::endl;
		std::cout << f2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}