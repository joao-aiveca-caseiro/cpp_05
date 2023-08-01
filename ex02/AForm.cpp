/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 14:25:45 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/07/30 17:27:15 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _is_signed(false), _grade_to_sign(150), _grade_to_execute(150){}

AForm::~AForm(){}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_execute): 
_name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	this->_is_signed = false;
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw (AForm::GradeTooHighException());
	else if (grade_to_sign > 150 || grade_to_execute > 150)
		throw (AForm::GradeTooLowException());
}

AForm::AForm(const AForm &target): 
_name(target.getName()), _grade_to_sign(target.getGradeToSign()), _grade_to_execute(target.getGradeToExecute())
{
	this->_is_signed = target.getIsSigned();
}

AForm &AForm::operator=(const AForm &target)
{
	if (this != &target)
	{
		this->_is_signed = target.getIsSigned();
	}
	return (*this);
}

std::string	AForm::getName() const
{
	return(this->_name);
}

int	AForm::getGradeToSign() const
{
	return(this->_grade_to_sign);
}

int	AForm::getGradeToExecute() const
{
	return(this->_grade_to_execute);
}

bool AForm::getIsSigned() const
{
	return(this->_is_signed);
}

void	AForm::beSigned(Bureaucrat &target)
{
	if (target.getGrade() <= this->getGradeToSign())
		this->_is_signed = true;
	else
		throw(AForm::GradeTooLowException());
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Error: Grade too low.");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Error: Grade too high.");
}

const char *AForm::UnsignedException::what() const throw()
{
	return ("Error: The form is unsigned.");
}

std::ostream	&operator<<(std::ostream &os, const AForm &target)
{
	os << "Type: " << target.getName() << std::endl
	<< "Signed: " << (target.getIsSigned() ? "Yes" : "No") << std::endl
	<< "Grade required to sign: " << target.getGradeToSign() << std::endl
	<< "Grade required to execute: " << target.getGradeToExecute() << std::endl;
	return (os);
}