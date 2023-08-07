/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 00:17:16 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/08/07 01:50:38 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include <iostream>
#include <exception>
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class AForm;

class	Intern
{
	public:
		
		Intern();
		Intern(const Intern &target);
		~Intern();

		Intern	&operator=(const Intern &target);
		AForm	*makeForm(const std::string &name, const std::string &target);
		AForm	*makePPForm(const std::string &target);
		AForm	*makeRRForm(const std::string &target);
		AForm	*makeSCForm(const std::string &target);
};

#endif