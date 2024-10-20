#pragma once
#include "ZGM/Core.h"

namespace ZGM_EXCEPTION {

	class ZGM_API ZGMException : public std::exception {
		virtual const char* what() const noexcept = 0;
	};


	class ZGM_API FileNotFoundError : ZGMException {
	private:
		std::string m_errorMessage;
	public:
		FileNotFoundError(const char* errorMessage);
		const char* what() const noexcept override;
		inline static const char* GetExceptionName();
	};
}