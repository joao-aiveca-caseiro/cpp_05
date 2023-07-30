/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 23:17:01 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/07/30 18:23:05 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int	main(void)
{
	Bureaucrat alfred("Alfred", 20);
	Bureaucrat thomas("Thomas", 100);
	Form	   formX("FormX", 42, 42);
	std::cout << alfred << std::endl;
	std::cout << std::endl;
	std::cout << thomas << std::endl;
	std::cout << std::endl;
	std::cout << formX << std::endl;
	
	std::cout << "-- Attempting to create FormA, a form with a grade_to_sign of 200. --" << std::endl;
	try
	{
		Form formA("FormA", 200, 42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "-- Attempting to create FormB, a form with a grade_to_execute of 0. --" << std::endl;
	try
	{
		Form formA("FormA", 142, 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "-- Attempting to sign FormX with Thomas (it should fail). --" << std::endl;
	thomas.signForm(formX);
	std::cout << formX << std::endl;
	
	std::cout << "-- Attempting to sign FormX with Alfred (it should work fine). --" << std::endl;
	alfred.signForm(formX);
	std::cout << formX << std::endl;

	std::cout << "-- Attempting to sign FormX with Alfred (it should fail because it is already signed). --" << std::endl;
	alfred.signForm(formX);
	std::cout << formX << std::endl;

	
}