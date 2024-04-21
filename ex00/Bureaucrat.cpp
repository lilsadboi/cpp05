/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <gmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:26:19 by gmorelli          #+#    #+#             */
/*   Updated: 2024/04/04 15:25:28 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150)
{
	// std::cout << "Default Bureaucrat " << _name << " has been created" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	// std::cout << "Bureaucrat " << _name << " has been created" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : _name(obj.getName()), _grade(obj.getGrade())
{
	// std::cout << "Bureaucrat copy" << _name << " has been created" << std::endl;
	*this = obj;
	return ;
}

Bureaucrat::~Bureaucrat(void)
{
	// std::cout << "Bureaucrat " << _name << " has been destroyed" << std::endl;
	return ;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &src)
{
	_grade = src.getGrade();
	return(*this);
}

const std::string Bureaucrat::getName(void) const
{
	return (_name);
}

int  Bureaucrat::getGrade(void)	const
{
	return (_grade);
}

void Bureaucrat::incGrade(void)
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}

void Bureaucrat::decGrade(void)
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &src)
{
	os << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return (os);
}