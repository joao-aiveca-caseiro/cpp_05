/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 23:17:01 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/08/07 12:17:46 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Bureaucrat	alfred("Alfred", 5);
	Intern		bob;
	
	AForm *created = bob.makeForm("PresidentialPardonForm", "Evil Wizard");
	AForm *created1 = bob.makeForm("RobotomyRequestForm", "Me");
	AForm *created2 = bob.makeForm("ShrubberyCreationForm", "Plaza");
	std::cout << std::endl;
	std::cout << *created << std::endl;
	std::cout << std::endl;
	std::cout << *created1 << std::endl;
	std::cout << std::endl;
	std::cout << *created2 << std::endl;
	
	alfred.signForm(*created);
	alfred.executeForm(*created);
	
	std::cout << std::endl;
	std::cout << "-- Attempting to create a form with an unsupported type --" << std::endl;
	AForm *failure = bob.makeForm("SomethingSomethingForm", "Evil Wizard");
	
	delete(created);
	delete(created1);
	delete(created2);
	delete(failure);
}