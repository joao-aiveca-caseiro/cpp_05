/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 23:17:01 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/08/07 12:10:33 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void)
{
	Bureaucrat alfred("Alfred", 5);
	Bureaucrat thomas("Thomas", 10);
	PresidentialPardonForm	formP("Criminal Mastermind");
	RobotomyRequestForm	formR("Mr. Human");
	ShrubberyCreationForm formS("Street");
	
	std::cout << alfred << std::endl;
	std::cout << std::endl;
	std::cout << thomas << std::endl;
	std::cout << std::endl;
	std::cout << formP << std::endl;
	std::cout << formR << std::endl;
	std::cout << formS << std::endl;
	
	std::cout << std::endl;
	alfred.executeForm(formP);
	alfred.signForm(formP);
	thomas.executeForm(formP);
	alfred.executeForm(formP);
	
	std::cout << std::endl;
	alfred.signForm(formR);
	alfred.executeForm(formR);
	alfred.executeForm(formR);
	alfred.executeForm(formR);
	
	std::cout << std::endl;
	thomas.signForm(formS);
	thomas.executeForm(formS);
	
}