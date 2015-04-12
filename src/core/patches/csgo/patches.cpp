/**
* =============================================================================
* Source Python
* Copyright (C) 2012 Source Python Development Team.  All rights reserved.
* =============================================================================
*
* This program is free software; you can redistribute it and/or modify it under
* the terms of the GNU General Public License, version 3.0, as published by the
* Free Software Foundation.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
* FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
* details.
*
* You should have received a copy of the GNU General Public License along with
* this program.  If not, see <http://www.gnu.org/licenses/>.
*
* As a special exception, the Source Python Team gives you permission
* to link the code of this program (as well as its derivative works) to
* "Half-Life 2," the "Source Engine," and any Game MODs that run on software
* by the Valve Corporation.  You must obey the GNU General Public License in
* all respects for all other code used.  Additionally, the Source.Python
* Development Team grants this exception to all derivative works.
*/

#include "KeyValues.h"
#ifndef PATCH_KEYVALUES_DESTRUCTOR
#error "Make KeyValues::~KeyValues() public."
#endif

#include "eiface.h"
#ifndef PATCH_SEND_USER_MESSAGE
#error "Make IVEngineServer::SendUserMessage pure virtual."
#endif

#include "utilities/baseentity.h"
#ifndef PATCH_NETWORK_HANDLE_BASE_DEFINITION
#error "We need the CNetworkHandle definition..."
#endif

#include "functors.h"
#ifndef PATCH_FUNCTOR_CALLBACK0_RETURN_VALUE_CONVERSION
#error "Convert return value of CFunctorCallback0::GetTarget() to void*."
#endif

#include "datacache/imdlcache.h"
#ifndef PATCH_IMDL_CACHE_NOTIFY_VTABLE
#error "Update virtual functions of IMDLCacheNotify."
#endif