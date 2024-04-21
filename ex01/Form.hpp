/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <gmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:38:36 by gmorelli          #+#    #+#             */
/*   Updated: 2024/04/08 17:35:24 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <stdexcept>
#include <iostream>

class Bureaucrat;

class Form
{
	private:
		Form(void);
		
		const std::string	_name;
		bool				_signed;
		bool				_executed;
		const int			_gradeToSign;
		const int			_gradeToExec;

	public:
		Form(const std::string name, int gradeToSign, int gradeToExec);
		Form(const Form &obj);
		~Form(void);

		Form &operator=(const Form &src);

		const std::string	getName(void) const;
		bool				getSigned(void) const;
		const std::string	isSigned(void) const;
		bool				getExecuted(void) const;
		const std::string	isExecuted(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExec(void) const;
		void				beSigned(const Bureaucrat &obj);
		void 				beExecuted(const Bureaucrat &obj);
		void 				execute(const Bureaucrat &obj) const;
		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class TooLowToSign : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class TooLowToExec : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NotSigned : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Form &src);

#endif