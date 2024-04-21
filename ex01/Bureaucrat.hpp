/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <gmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:26:22 by gmorelli          #+#    #+#             */
/*   Updated: 2024/04/05 15:13:13 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "Form.hpp"
#include <stdexcept>
#include <iostream>

class Form;

class Bureaucrat
{
	private:
		Bureaucrat(void);
		
		const std::string	_name;
		int					_grade;
	
	public:
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &obj);
		~Bureaucrat(void);

		Bureaucrat &operator=(const Bureaucrat &src);

		const std::string	getName(void) const;
		int					getGrade(void) const;
		void				incGrade(void);
		void				decGrade(void);
		void				signForm(Form &form);
		void				executeForm(Form &form);
		
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &src);

#endif