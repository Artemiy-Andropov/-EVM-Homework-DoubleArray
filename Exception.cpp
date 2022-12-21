#include <iostream>
#include <string>
#include "Exception.h"

ArrayException::ArrayException(std::string error_)
{
	m_error = error_;
}

const std::string ArrayException::GetError()
{
	return m_error.c_str();
}