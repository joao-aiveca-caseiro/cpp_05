/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:25:45 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/07/30 17:27:15 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _is_signed(false), _grade_to_sign(150), _grade_to_execute(150){}

Form::~Form(){}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute): 
_name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	this->_is_signed = false;
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw (Form::GradeTooHighException());
	else if (grade_to_sign > 150 || grade_to_execute > 150)
		throw (Form::GradeTooLowException());
}

Form::Form(const Form &target): 
_name(target.getName()), _grade_to_sign(target.getGradeToSign()), _grade_to_execute(target.getGradeToExecute())
{
	this->_is_signed = target.getIsSigned();
}

Form &Form::operator=(const Form &target)
{
	if (this != &target)
	{
		this->_is_signed = target.getIsSigned();
	}
	return (*this);
}

std::string	Form::getName() const
{
	return(this->_name);
}

int	Form::getGradeToSign() const
{
	return(this->_grade_to_sign);
}

int	Form::getGradeToExecute() const
{
	return(this->_grade_to_execute);
}

bool Form::getIsSigned() const
{
	return(this->_is_signed);
}

void	Form::beSigned(Bureaucrat &target)
{
	if (target.getGrade() <= this->getGradeToSign())
		this->_is_signed = true;
	else
		throw(Form::GradeTooLowException());
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Error: Grade too low.");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Error: Grade too high.");
}

std::ostream	&operator<<(std::ostream &os, const Form &target)
{
	os << "Form name: " << target.getName() << std::endl
	<< "Signed: " << (target.getIsSigned() ? "Yes" : "No") << std::endl
	<< "Grade required to sign: " << target.getGradeToSign() << std::endl
	<< "Grade required to execute: " << target.getGradeToExecute() << std::endl;
	return (os);
}