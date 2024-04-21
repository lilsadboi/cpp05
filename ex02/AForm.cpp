/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <gmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:38:33 by gmorelli          #+#    #+#             */
/*   Updated: 2024/04/10 16:33:23 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("Bureaucrat"), _signed(false), _executed(false), _gradeToSign(150), _gradeToExec(150)
{
	// std::cout << "Default AForm " << _name << " has been created" << std::endl;
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw AForm::GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExec > 150)
		throw AForm::GradeTooLowException();
	return ;
}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExec) : _name(name), _signed(false), _executed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	// std::cout << "Parameter AForm " << _name << " has been created" << std::endl;
	if (gradeToSign < 1 || gradeToExec < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw AForm::GradeTooLowException();
	return ;
}

AForm::AForm(const AForm &obj) : _name(obj.getName()), _signed(obj.getSigned()), _executed(obj.getExecuted()), _gradeToSign(obj.getGradeToSign()), _gradeToExec(obj.getGradeToExec())
{
	// std::cout << "AForm copy " << _name << " has been created" << std::endl;
	*this = obj;
	return ;
}

AForm::~AForm(void)
{
	// std::cout << "AForm " << _name << " has been destroyed" << std::endl;
	return ;
}

AForm &AForm::operator=(const AForm &src)
{
	if (this != &src)
	{
		_signed = src.getSigned();
		_executed = src.getExecuted();
	}
	return (*this);
}

const std::string AForm::getName(void) const
{
	return (_name);
}

bool AForm::getSigned(void) const
{
	return (_signed);
}

bool AForm::getExecuted(void) const
{
	return (_executed);
}

const std::string AForm::isSigned(void) const
{
	if (_signed)
		return ("signed");
	else
		return ("not signed");
}


const std::string AForm::isExecuted(void) const
{
	if (_executed)
		return ("executed");
	else
		return ("not executed");
}

int AForm::getGradeToSign(void) const
{
	return (_gradeToSign);
}


int AForm::getGradeToExec(void) const
{
	return (_gradeToExec);
}

void AForm::beSigned(const Bureaucrat &obj)
{
	try
	{
		if (obj.getGrade() <= _gradeToSign)
			_signed = true;
		else
			throw AForm::GradeTooLowException();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void AForm::beExecuted(const Bureaucrat &obj)
{
	if (obj.getGrade() <= _gradeToExec)
		_executed = true;
}

void AForm::execute(const Bureaucrat &obj) const
{
	try
	{
		if (obj.getGrade() > _gradeToExec)
			throw AForm::TooLowToExec();
		if (!_signed)
			throw AForm::FormNotSignedException();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}


const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}


const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed");
}

const char *AForm::TooLowToSign::what() const throw()
{
	return ("Grade too low to sign");
}

const char *AForm::TooLowToExec::what() const throw()
{
	return ("Grade too low to execute");
}

std::ostream &operator<<(std::ostream &os, const AForm &src)
{
	os << "Form: " << src.getName() << std::endl;
	os << "Signed: " << src.isSigned() << std::endl;
	os << "Executed: " << src.isExecuted() << std::endl;
	os << "Grade to sign: " << src.getGradeToSign() << std::endl;
	os << "Grade to execute: " << src.getGradeToExec() << std::endl;
	return (os);
}