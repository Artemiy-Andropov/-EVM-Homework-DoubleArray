#pragma once
#include <iostream>
#include <string>

class ArrayException
{
	std::string m_error;

public:

	ArrayException(std::string error_);

	const std::string GetError();
};