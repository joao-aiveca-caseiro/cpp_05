/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 23:17:01 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/07/29 23:37:40 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat alfred("Alfred", 20);
	std::cout << alfred << std::endl;
	
	std::cout << std::endl;
	
	std::cout << "-- Attempting to create William, a bureaucrat with grade 0. --" << std::endl;
	try
	{
		Bureaucrat william("William", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "-- Attempting to create Jenkins, a bureaucrat with grade 200. --" << std::endl;
	try
	{
		Bureaucrat jenkins("Jenkins", 200);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "-- Attempting to increment Alfred's grade above the limit. --" << std::endl;	
	try
	{
		for (int i = 0; i < 20; i++)
		{
			alfred.incrementGrade();
			std::cout << alfred << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	Bureaucrat dennis("Dennis", 142);
	std::cout << dennis << std::endl;
	std::cout << "-- Attempting to decrement Dennis's grade below the limit. --" << std::endl;	
	try
	{
		for (int i = 0; i < 9; i++)
		{
			dennis.decrementGrade();
			std::cout << dennis << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}