/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorelli <gmorelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:43:05 by gmorelli          #+#    #+#             */
/*   Updated: 2024/04/10 16:00:44 by gmorelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class AForm;

class PresidentialPardonForm : public AForm
{
	private:
		PresidentialPardonForm(void);
		
		const std::string _target;

	public:
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &obj);
		~PresidentialPardonForm(void);

		PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

		void execute(const Bureaucrat &obj) const;
		const std::string getTarget(void) const;
};

#endif