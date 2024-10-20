#include "zgmpch.h"
#include "GeneralTools.h"

void IsFileExists(const char* filepath)
{
	try {
		if (!std::filesystem::exists(filepath)) {
			throw ZGM_EXCEPTION::FileNotFoundError(filepath);
		}
	}
	catch (ZGM_EXCEPTION::FileNotFoundError& e) {
		std::cerr << e.GetExceptionName() << ": " << e.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
}
