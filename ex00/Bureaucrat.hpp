/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <gmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:26:22 by gmorelli          #+#    #+#             */
/*   Updated: 2024/04/04 15:22:30 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <stdexcept>
#include <iostream>

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
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &src);

#endif