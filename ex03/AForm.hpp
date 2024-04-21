/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <gmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:38:36 by gmorelli          #+#    #+#             */
/*   Updated: 2024/04/10 16:33:41 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"

#include <stdexcept>
#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		AForm(void);
		
		const std::string	_name;
		bool				_signed;
		bool				_executed;
		const int			_gradeToSign;
		const int			_gradeToExec;

	public:
		AForm(const std::string name, int gradeToSign, int gradeToExec);
		AForm(const AForm &obj);
		~AForm(void);

		AForm &operator=(const AForm &src);

		const std::string	getName(void) const;
		bool				getSigned(void) const;
		const std::string	isSigned(void) const;
		bool				getExecuted(void) const;
		const std::string	isExecuted(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExec(void) const;
		void				beSigned(const Bureaucrat &obj);
		void 				beExecuted(const Bureaucrat &obj);
		virtual void		execute(const Bureaucrat &obj) const = 0;
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class FormNotSignedException : public std::exception
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
};

std::ostream &operator<<(std::ostream &os, const AForm &src);

#endif