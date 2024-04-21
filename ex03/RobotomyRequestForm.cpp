/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <gmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:43:07 by gmorelli          #+#    #+#             */
/*   Updated: 2024/04/10 17:37:08 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("default", 72, 45)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm(target, 72, 45)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &obj) : AForm(obj)
{
	*this = obj;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	(void)src;
	return (*this);
}

void 	RobotomyRequestForm::execute(const Bureaucrat &obj) const
{
	try
	{
		srand(static_cast<unsigned int>(time(0)));
		if (obj.getGrade() > getGradeToExec())
			throw AForm::GradeTooLowException();
		else if (!getSigned())
			throw AForm::FormNotSignedException();
		else
		{
			if (rand() % 2 == 0)
			{
				std::cout << getTarget() << " has been executed" << std::endl;
				std::cout << "Bzzz... Bzzz... Bzzz..." << getName() << " has been robotomized successfully" << std::endl;
			}
			else
				throw RobotomizedException();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

const std::string RobotomyRequestForm::getTarget(void) const
{
	return (AForm::getName());
}

const char* RobotomyRequestForm::RobotomizedException::what() const throw()
{
	return ("Bzzz... Bzzz... Bzzz... Robotomization failed");
}