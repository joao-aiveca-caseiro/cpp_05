/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:42:57 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/07/30 17:48:50 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class	AForm
{
	public:
		
		AForm();
		AForm(const AForm &target);
		AForm(std::string name, int grade_to_sign, int grade_to_execute);
		virtual ~AForm();

		AForm				&operator=(const AForm &target);
		std::string			getName() const;
		void				setName(std::string name);
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				beSigned(Bureaucrat &target);
		virtual void		execute(Bureaucrat const &executor) const = 0;

		class GradeTooLowException: public std::exception
		{
			virtual const char* what() const throw();
		};

		class GradeTooHighException: public std::exception
		{
			virtual const char* what() const throw();
		};

		class UnsignedException: public std::exception
		{
			virtual const char* what() const throw();
		};

	private:
	
		const std::string	_name;
		bool				_is_signed;
		const int			_grade_to_sign;
		const int			_grade_to_execute;
};

std::ostream	&operator<<(std::ostream &os, const AForm &target);

#endif