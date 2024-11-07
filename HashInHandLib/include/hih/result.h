#pragma once

#ifndef HIH_RESULT_H
#define HIH_RESULT_H

namespace hih {
	enum class state:int
	{
		Unknown = -1,
		Successful = 0,
		FileNotExists = 2,
		FileOpenFailed = 4,
		FileAccessDenied = 5,
		BadContent = 13,
	};
}

#endif //HIH_RESULT_H