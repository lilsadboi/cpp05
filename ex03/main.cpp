/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <gmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:26:26 by gmorelli          #+#    #+#             */
/*   Updated: 2024/04/10 18:37:36 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Bureaucrat b1("Bureaucrat1", 133);
		Bureaucrat b2("Bureaucrat2", 56);
		Bureaucrat b3("Bureaucrat3", 25);
		// ShrubberyCreationForm f1("ShrubberyCreationForm1");
		// RobotomyRequestForm f2("RobotomyRequestForm1");
		// PresidentialPardonForm f3("PresidentialPardonForm1");
		Intern intern;
		AForm *f1 = intern.makeForm("shrubbery creation", "ShrubberyCreationForm1");
		AForm *f2 = intern.makeForm("robotomy request", "RobotomyRequestForm1");
		AForm *f3 = intern.makeForm("presidential pardon", "PresidentialPardonForm1");
		f1->beSigned(b1);
		f2->beSigned(b2);
		f3->beSigned(b3);
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		std::cout << b3 << std::endl;
		std::cout << *f1 << std::endl;
		std::cout << *f2 << std::endl;
		std::cout << *f3 << std::endl;
		b1.signForm(*f1);
		b2.signForm(*f2);
		b3.signForm(*f3);
		b1.executeForm2(*f1);
		b2.executeForm2(*f2);
		b3.executeForm2(*f3);
		std::cout << *f1 << std::endl;
		std::cout << *f2 << std::endl;
		std::cout << *f3 << std::endl;
		// b1.incGrade();
		// b2.incGrade();
		// f1.beSigned(b1);
		// f2.beSigned(b2);
		// std::cout << b1 << std::endl;
		// std::cout << b2 << std::endl;
		// std::cout << f1 << std::endl;
		// std::cout << f2 << std::endl;
		// b1.signForm(f1);
		// b2.signForm(f2);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}