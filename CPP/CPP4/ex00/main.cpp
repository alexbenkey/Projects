/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avon-ben <avon-ben@student.codam.nl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 00:18:33 by avon-ben          #+#    #+#             */
/*   Updated: 2025/07/24 00:18:36 by avon-ben         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;


	std::cout << "the animal type of j = " << j->getType() << " " << std::endl;
	std::cout << "the animal type of i = " << i->getType() << " " << std::endl;
	std::cout << std::endl;


	i->makeSound(); //will output the cat sound!
	j->makeSound(); //will output the dog sound!
	meta->makeSound();
	std::cout << std::endl;
	std::cout << std::endl;
	
	
	const WrongAnimal* ani = new WrongAnimal();
	const WrongAnimal* c = new WrongCat();
	std::cout << std::endl;


	std::cout << "the animal type of i = " << c->getType() << " " << std::endl;
	std::cout << std::endl;


	c->makeSound(); //will output the 'wrong' cat sound!
	ani->makeSound();
	std::cout << std::endl;


	delete meta;
	delete ani;
	delete i;
	delete j;
	delete c;
	return 0;
}