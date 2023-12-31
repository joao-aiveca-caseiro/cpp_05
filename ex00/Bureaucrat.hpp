/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:28:49 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/07/30 14:05:25 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class	Bureaucrat
{
	public:
		
		Bureaucrat();
		Bureaucrat(const Bureaucrat &target);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();

		Bureaucrat	&operator=(const Bureaucrat &target);
		std::string	getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();

		class GradeTooLowException: public std::exception
		{
			virtual const char* what() const throw();
		};

		class GradeTooHighException: public std::exception
		{
			virtual const char* what() const throw();
		};

	private:
	
		const std::string	_name;
		int					_grade;
};

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &target);

#endif