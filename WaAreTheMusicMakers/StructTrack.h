#pragma once
#ifndef GUARDIAN_StructTrack
#define GUARDIAN_StructTrack

#include<vector>

struct Track {
	std::vector<const char*> names;
	std::vector<const char*>::size_type number;
	const char* plus = "+";
};

#endif
