/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprofett <mprofett@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:29:43 by mprofett          #+#    #+#             */
/*   Updated: 2023/12/05 11:59:44 by mprofett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
# define AForm_HPP

# include "Bureaucrat.hpp"
# include <string>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_grade_to_sign;
		const int			_grade_to_execute;

	public:

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class	UnsignedFormException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		AForm();
		~AForm();
		AForm(const AForm &copy);
		AForm(std::string name, bool signature, int grade_to_sign, int grade_to_execute);

		std::string		getName(void) const;
		bool			getSignature(void) const;
		int				getGradeToSign(void) const;
		int				getGradeToExecute(void) const;
		void			beSigned(Bureaucrat &bureaucrat);
		virtual void	execute(Bureaucrat &bureaucrat) const = 0;
};

std::ostream	&operator<<(std::ostream &o, AForm const &AForm);

#endif
