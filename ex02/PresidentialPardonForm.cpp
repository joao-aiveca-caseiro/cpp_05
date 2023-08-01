/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:55:10 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/08/01 16:30:24 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5){}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5)
{
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form): AForm(form)
{
	this->_target = form._target;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &form)
{
	if (this != &form)
	{
		this->_target = form._target;	
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){}

std::string	PresidentialPardonForm::getTarget() const
{
	return(this->_target);
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (this->getIsSigned())
	{
		if (executor.getGrade() <= this->getGradeToExecute())
		{
			std::cout << "🏛️  " << this->getTarget() << " has been pardoned by Zaphod Beeblebrox! 🏛️" << std::endl;
		}
		else
			throw(AForm::GradeTooLowException());		
	}
	else
		throw(AForm::UnsignedException());
}