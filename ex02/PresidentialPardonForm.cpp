/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiveca- <jaiveca-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 17:55:10 by jaiveca-          #+#    #+#             */
/*   Updated: 2023/07/30 18:33:53 by jaiveca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("", 25, 5){}

PresidentialPardonForm::PresidentialPardonForm(std::string name): AForm("Name", 25, 5){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &target): AForm(target)
{
	*this = target;
}