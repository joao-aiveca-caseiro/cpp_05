/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 00:48:45 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/08/07 02:01:18 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(const Intern &target)
{
	*this = target;
}

Intern &Intern::operator=(const Intern &target)
{
	(void)target;
	return (*this);
}

AForm	*Intern::makePPForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeRRForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));	
}

AForm	*Intern::makeSCForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));	
}


AForm	*Intern::makeForm(const std::string &name, const std::string &target)
{
	std::string	available_forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	AForm	*(Intern::*f_ptr[])(const std::string &target) = {&Intern::makePPForm, &Intern::makeRRForm, &Intern::makeSCForm};

	for (int i = 0; i < 3; i++)
	{
		if (available_forms[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return((this->*f_ptr[i])(target));		
		}
	}
	std::cout << "Error: Intern cannot create a form matching the specified name." << std::endl;
	return (NULL);
}
