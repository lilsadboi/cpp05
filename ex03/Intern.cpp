/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <gmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:26:50 by gmorelli          #+#    #+#             */
/*   Updated: 2024/03/25 11:33:46 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	return ;
}

Intern::Intern(const Intern &obj)
{
	*this = obj;
	return ;
}

Intern::~Intern()
{
	return ;
}

Intern &Intern::operator=(const Intern &src)
{
	(void)src;
	return (*this);
}

AForm *Intern::makeForm(std::string name, std::string target) const
{
	if (name == "shrubbery creation")
	{
		std::cout << "Intern creates " << name << std::endl;
		return (new ShrubberyCreationForm(target));
	}
	else if (name == "robotomy request")
	{
		std::cout << "Intern creates " << name << std::endl;
		return (new RobotomyRequestForm(target));
	}
	else if (name == "presidential pardon")
	{
		std::cout << "Intern creates " << name << std::endl;
		return (new PresidentialPardonForm(target));
	}
	else
	{
		std::cout << "Intern can't create " << name << " because it doesn't exist" << std::endl;
		return (NULL);
	}
}