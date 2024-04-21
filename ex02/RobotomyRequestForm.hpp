/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <gmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:43:10 by gmorelli          #+#    #+#             */
/*   Updated: 2024/04/10 17:20:30 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class AForm;

class RobotomyRequestForm : public AForm
{
	private:
		RobotomyRequestForm(void);
		
		const std::string	_target;

	public:
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &obj);
		~RobotomyRequestForm(void);

		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

		void			execute(const Bureaucrat &obj) const;
		const std::string	getTarget(void) const;
		class RobotomizedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif