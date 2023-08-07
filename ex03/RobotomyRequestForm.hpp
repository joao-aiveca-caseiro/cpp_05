/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:53:44 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/08/01 18:23:08 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <ctime>
#include <cstdlib>

class RobotomyRequestForm: public AForm
{
	public:
	
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &target);
		RobotomyRequestForm(std::string name);
		~RobotomyRequestForm();

		RobotomyRequestForm	&operator=(const RobotomyRequestForm &target);
		void					execute(Bureaucrat const &executor) const;
		std::string				getTarget() const;

	private:
	
		std::string	_target;	
};

#endif