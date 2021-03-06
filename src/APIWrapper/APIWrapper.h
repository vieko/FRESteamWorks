/*
 *  APIWrapper.h
 *  This file is part of FRESteamWorks.
 *
 *  Created by Ventero <http://github.com/Ventero>
 *  Copyright (c) 2012-2013 Level Up Labs, LLC. All rights reserved.
 */

#ifndef APIWRAPPER_H
#define APIWRAPPER_H

#include <steam_api.h>

#include "CSteam.h"
#include "WrapperIO.h"

class CLISteam : public CSteam {
	void DispatchEvent(char* code, char* level);
};

void steamWarningMessageHook(int severity, const char* msg);

#define X(a) void a();
#include "functions.h"
#undef X

std::vector<std::function<void()>> apiFunctions {
#define X(a) std::function<void()>(a),
#include "functions.h"
#undef X
};

#endif
