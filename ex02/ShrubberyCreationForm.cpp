/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <gmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:43:23 by gmorelli          #+#    #+#             */
/*   Updated: 2024/04/10 17:39:28 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("default", 145, 137)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm(target, 145, 137)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj)
{
	*this = obj;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	(void)src;
	return (*this);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &obj) const
{
	try
	{
		if (obj.getGrade() > getGradeToExec())
			throw AForm::GradeTooLowException();
		else if (getSigned() == false)
			throw AForm::FormNotSignedException();
		else if (getSigned() == true)
		{
			std::cout << getTarget() << " has been executed" << std::endl;
			std::string fileName = getTarget() + "_shrubbery";
			std::ofstream file(fileName.c_str());
			file << "      /\\      " << std::endl;
			file << "     /\\\\     " << std::endl;
			file << "    /\\O\\\\    " << std::endl;
			file << "   /*\\/\\/\\   " << std::endl;
			file << "  /\\/\\*\\/\\  " << std::endl;
			file << " /\\*\\/\\*\\/\\ " << std::endl;
			file << "/\\O\\/\\/*/\\/\\" << std::endl;
			file << "      ||      " << std::endl;
			file << "      ||      " << std::endl;
			file << "      ||      " << std::endl;
			file << "   __ || __   " << std::endl;
			file << "  \\______/  " << std::endl;
			file.close();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

const std::string ShrubberyCreationForm::getTarget(void) const
{
	return (AForm::getName());
}