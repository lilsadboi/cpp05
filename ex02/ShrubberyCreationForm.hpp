/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <gmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:43:13 by gmorelli          #+#    #+#             */
/*   Updated: 2024/04/10 17:39:43 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm
{
	private:
		ShrubberyCreationForm(void);
		
		const std::string	_target;

	public:
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &obj);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

		void			execute(const Bureaucrat &obj) const;
		const std::string	getTarget(void) const;
};

#endif