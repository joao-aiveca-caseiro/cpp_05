/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:23:34 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/08/07 00:47:57 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _grade(150){}

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(150)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &target)
{
	this->_grade = target.getGrade();
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &target)
{
	if (this != &target)
	{
		this->_grade = target.getGrade();
	}
	return (*this);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

void	Bureaucrat::decrementGrade()
{
	if (this->getGrade() >= 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		this->_grade = this->getGrade() + 1;
}

void	Bureaucrat::incrementGrade()
{
	if (this->getGrade() <= 1)
		throw (Bureaucrat::GradeTooHighException());
	else
		this->_grade = this->getGrade() - 1;
}

void	Bureaucrat::signForm(AForm &target)
{
	if (!target.getIsSigned())
	{
		try
		{
			target.beSigned(*this);
			std::cout << this->getName() << " signed " << target.getName() << "." << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << this->getName() << " couldn't sign " << target.getName() 
			<< " because... " << e.what() << std::endl;
		}		
	}
	else
		std::cerr << this->getName() << " couldn't sign " << target.getName()
		<< " because it is already signed." << std::endl;
}

void	Bureaucrat::executeForm(AForm const &target)
{
	try
	{
		target.execute(*this);
		std::cout << this->getName() << " executed " << target.getName() << "." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->getName() << " couldn't execute " << target.getName() 
		<< " because... " << e.what() << std::endl;
	}		
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Error: Grade too low. The minimum grade is 150.");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Error: Grade too high. The maximum grade is 1.");
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &target)
{
	os << target.getName() << ", bureaucrat grade " << target.getGrade() << ".";
	return (os);
}