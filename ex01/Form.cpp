/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <gmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:38:33 by gmorelli          #+#    #+#             */
/*   Updated: 2024/04/08 17:40:15 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("Bureaucrat"), _signed(false), _executed(false), _gradeToSign(150), _gradeToExec(150)
{
	// std::cout << "Default Form " << _name << " has been created" << std::endl;
	try
	{
		if (_gradeToSign < 1 || _gradeToExec < 1)
			throw Form::GradeTooHighException();
		else if (_gradeToSign > 150 || _gradeToExec > 150)
			throw Form::GradeTooLowException();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return ;
}

Form::Form(std::string const name, int gradeToSign, int gradeToExec) : _name(name), _signed(false), _executed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	// std::cout << "Parameter Form " << _name << " has been created" << std::endl;
	try
	{
		if (gradeToSign < 1 || gradeToExec < 1)
			throw Form::GradeTooHighException();
		else if (gradeToSign > 150 || gradeToExec > 150)
			throw Form::GradeTooLowException();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return ;
}

Form::Form(const Form &obj) : _name(obj.getName()), _signed(obj.getSigned()), _executed(obj.getExecuted()), _gradeToSign(obj.getGradeToSign()), _gradeToExec(obj.getGradeToExec())
{
	// std::cout << "Form copy " << _name << " has been created" << std::endl;
	*this = obj;
	return ;
}

Form::~Form(void)
{
	// std::cout << "Form " << _name << " has been destroyed" << std::endl;
	return ;
}

Form &Form::operator=(const Form &src)
{
	if (this != &src)
	{
		_signed = src.getSigned();
		_executed = src.getExecuted();
	}
	return (*this);
}

const std::string Form::getName(void) const
{
	return (_name);
}

bool Form::getSigned(void) const
{
	return (_signed);
}

const std::string Form::isSigned(void) const
{
	if (_signed)
		return ("signed");
	else
		return ("not signed");
}

bool Form::getExecuted(void) const
{
	return (_executed);
}

const std::string Form::isExecuted(void) const
{
	if (_executed)
		return ("executed");
	else
		return ("not executed");
}

int Form::getGradeToSign(void) const
{
	return (_gradeToSign);
}

int Form::getGradeToExec(void) const
{
	return (_gradeToExec);
}


void Form::beSigned(const Bureaucrat &obj)
{
	try
	{
		if (obj.getGrade() <= _gradeToSign)
			_signed = true;
		else
			throw Form::TooLowToSign();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void Form::beExecuted(const Bureaucrat &obj)
{
	if (obj.getGrade() <= _gradeToExec)
		_executed = true;
}

void Form::execute(const Bureaucrat &obj) const
{
	try
	{
		if (obj.getGrade() > _gradeToExec)
			throw Form::TooLowToExec();
		else if (!_signed)
			throw Form::NotSigned();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* Form::TooLowToSign::what() const throw()
{
	return ("Grade too low to sign");
}

const char* Form::TooLowToExec::what() const throw()
{
	return ("Grade too low to execute");
}

const char* Form::NotSigned::what() const throw()
{
	return ("Form is not signed");
}

std::ostream &operator<<(std::ostream &os, const Form &src)
{
	os << "Form: " << src.getName() << std::endl;
	os << "Signed: " << src.isSigned() << std::endl;
	os << "Executed: " << src.isExecuted() << std::endl;
	os << "Grade to sign: " << src.getGradeToSign() << std::endl;
	os << "Grade to execute: " << src.getGradeToExec() << std::endl;
	return (os);
}