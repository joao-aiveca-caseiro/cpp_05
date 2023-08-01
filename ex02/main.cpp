/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 23:17:01 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/08/01 18:43:45 by jaiveca-         ###   ########.fr       */
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
	std::cout << alfred << std::endl;
	std::cout << std::endl;
	std::cout << thomas << std::endl;
	std::cout << std::endl;
	std::cout << formP << std::endl;
	
	alfred.executeForm(formP);
	alfred.signForm(formP);
	thomas.executeForm(formP);
	alfred.executeForm(formP);

	alfred.signForm(formR);
	alfred.executeForm(formR);
	alfred.executeForm(formR);
	alfred.executeForm(formR);
	
}