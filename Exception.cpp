#include <iostream>
#include <string>
#include "Exception.h"

ArrayException::ArrayException(std::string error_, const int code_error_)
{
	m_error = error_;
	code_error = code_error_;
}

const std::string ArrayException::GetError()
{
	return m_error.c_str();
}

const int ArrayException::GetCodeError()
{
	return code_error;
}