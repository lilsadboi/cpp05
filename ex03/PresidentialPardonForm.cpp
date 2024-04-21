/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <gmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:43:02 by gmorelli          #+#    #+#             */
/*   Updated: 2024/04/10 17:38:21 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm(target, 25, 5)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj) : AForm(obj)
{
	*this = obj;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	(void)src;
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &obj) const
{
	try
	{
		if (obj.getGrade() > getGradeToExec())
			throw AForm::GradeTooLowException();
		else if (!getSigned())
			throw AForm::FormNotSignedException();
		else
		{
			std::cout << getTarget() << " has been executed" << std::endl;
			std::cout << obj.getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

const std::string PresidentialPardonForm::getTarget(void) const
{
	return (AForm::getName());
}