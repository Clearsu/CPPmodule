/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:38:02 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/27 22:49:32 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Fixed.hpp>

int main(void) {
	std::cout << "***testing pre / post increment / decrement***" << std::endl;
	Fixed a;
	std::cout << "a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "--a: " << --a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a--: " << a-- << std::endl;
	std::cout << "a: " << a << '\n' << std::endl;

	std::cout << "***testing arithmetic operators***" << std::endl;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "Fixed(5.05f) * Fixed(2): " << b << std::endl;
	Fixed const c( Fixed( 5.05f ) / Fixed( 2 ) );
	std::cout << "Fixed(5.05f) / Fixed(2): " << c << std::endl;
	Fixed const d( Fixed( 5.05f ) + Fixed( 2 ) );
	std::cout << "Fixed(5.05f) + Fixed(2): " << d << std::endl;
	Fixed const e( Fixed( 5.05f ) - Fixed( 2 ) );
	std::cout << "Fixed(5.05f) - Fixed(2): " << e << '\n' << std::endl;

	std::cout << "***testing max and min***" << std::endl;
	Fixed f(-100), g(50.5f);
	std::cout << "f: " << f << ", g: " << g << std::endl;
	std::cout << "max(f, g): " << Fixed::max( f, g ) << std::endl;
	std::cout << "min(f, g): " << Fixed::min( f, g ) << std::endl;
	return 0;
}
