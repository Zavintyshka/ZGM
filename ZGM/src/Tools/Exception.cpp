#include "zgmpch.h"
#include "Exception.h"

namespace ZGM_EXCEPTION {
	FileNotFoundError::FileNotFoundError(const char* errorMessage)
		: m_errorMessage(errorMessage) {}

	const char* FileNotFoundError::what() const noexcept{
		return m_errorMessage.c_str();
	}

	inline const char* FileNotFoundError::GetExceptionName()
	{
		return "FileNotFoundError";
	}
}