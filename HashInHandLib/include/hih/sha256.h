#pragma once

#ifndef HIH_SHA256_H
#define HIH_SHA256_H

#include "hih/result.h"
#include "hih/type.h"

namespace hih {
	namespace sha {
		state get_file_sha256(std::string& hash, const fs::path& source);
	}

	namespace utility
	{
		
	}
}


#endif //HIH_SHA256_H