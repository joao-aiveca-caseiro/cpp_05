/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:42:57 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/07/30 16:44:22 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class	Form
{
	public:
		
		Form();
		Form(const Form &target);
		Form(std::string name, int grade_to_sign, int grade_to_execute);
		~Form();

		Form		&operator=(const Form &target);
		std::string	getName() const;
		bool		getIsSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		void		beSigned(Bureaucrat &target);

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
		bool				_is_signed;
		const int			_grade_to_sign;
		const int			_grade_to_execute;
};

std::ostream	&operator<<(std::ostream &os, const Form &target);

#endif