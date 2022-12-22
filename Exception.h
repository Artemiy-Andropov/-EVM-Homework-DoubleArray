#pragma once
#include <iostream>
#include <string>

class ArrayException
{
	std::string m_error;
	int code_error;

public:

	ArrayException(std::string error_, const int code_error_);

	const std::string GetError();

	const int GetCodeError();
};