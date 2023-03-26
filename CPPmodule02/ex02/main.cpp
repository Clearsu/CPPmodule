/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 17:38:02 by jincpark          #+#    #+#             */
/*   Updated: 2023/03/26 16:04:06 by jincpark         ###   ########.fr       */
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
	std::cout << "a: " << a << ", b: " << b << std::endl;
	std::cout << "max(a, b): " << Fixed::max( a, b ) << std::endl;
	std::cout << "min(a, b): " << Fixed::min( a, b ) << std::endl;
	return 0;
}
