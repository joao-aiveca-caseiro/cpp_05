/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:53:55 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/08/01 18:47:56 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45){}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form): AForm(form)
{
	this->_target = form._target;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &form)
{
	if (this != &form)
	{
		this->_target = form._target;	
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){}

std::string	RobotomyRequestForm::getTarget() const
{
	return(this->_target);
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (this->getIsSigned())
	{
		if (executor.getGrade() <= this->getGradeToExecute())
		{
			srand(((unsigned)time(NULL)));
			int	random = rand();
			static int increment = 1;
			if ((random + increment) % 2 == 0)
				std::cout << "🤖  " << this->getTarget() << " has been successfully robotomized! 🤖" << std::endl;
			else
				std::cout << "🤖❌  " << this->getTarget() << "'s robotomy has been unsuccessfull! ❌🤖" << std::endl;
			increment++;
		}
		else
			throw(AForm::GradeTooLowException());	
	}
	else
		throw(AForm::UnsignedException());
}