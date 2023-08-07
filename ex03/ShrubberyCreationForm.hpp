/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:52:18 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/08/06 22:54:46 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm: public AForm
{
	public:
	
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &target);
		ShrubberyCreationForm(std::string name);
		~ShrubberyCreationForm();

		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &target);
		void					execute(Bureaucrat const &executor) const;
		std::string				getTarget() const;

	private:
	
		std::string	_target;	
};

#endif