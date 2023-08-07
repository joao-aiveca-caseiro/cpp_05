/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:54:58 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/08/01 15:25:20 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	public:
	
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &target);
		PresidentialPardonForm(std::string name);
		~PresidentialPardonForm();

		PresidentialPardonForm	&operator=(const PresidentialPardonForm &target);
		void					execute(Bureaucrat const &executor) const;
		std::string				getTarget() const;

	private:
	
		std::string	_target;
};

#endif