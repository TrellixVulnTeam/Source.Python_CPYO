/**
* =============================================================================
* Source Python
* Copyright (C) 2012-2015 Source Python Development Team.  All rights reserved.
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

#ifndef _CONVERSIONS_H
#define _CONVERSIONS_H

//-----------------------------------------------------------------------------
// Includes.
//-----------------------------------------------------------------------------
#include "utilities/wrap_macros.h"
#include "modules/memory/memory_tools.h"
#include "basehandle.h"
#include "eiface.h"
#include "public/game/server/iplayerinfo.h"
#include "utilities/baseentity.h"


//-----------------------------------------------------------------------------
// External variables.
//-----------------------------------------------------------------------------
extern IVEngineServer *engine;
extern CGlobalVars *gpGlobals;
extern IPlayerInfoManager *playerinfomanager;


//-----------------------------------------------------------------------------
// Constants.
//-----------------------------------------------------------------------------
#define WORLD_ENTITY_INDEX 0


//-----------------------------------------------------------------------------
// Invalid results.
//-----------------------------------------------------------------------------
#define INVALID_ENTITY_INDEX -1
#define INVALID_PLAYER_USERID -1


//-----------------------------------------------------------------------------
// EdictFrom* declarations
//-----------------------------------------------------------------------------
bool EdictFromIndex( unsigned int iEntityIndex, edict_t*& output );
bool EdictFromUserid( unsigned int iUserID, edict_t*& output );
bool EdictFromPlayerInfo( IPlayerInfo *pPlayerInfo, edict_t*& output );
bool EdictFromBaseEntity( CBaseEntity *pBaseEntity, edict_t*& output );
bool EdictFromBaseHandle( CBaseHandle hBaseHandle, edict_t*& output );
bool EdictFromIntHandle( unsigned int iEntityHandle, edict_t*& output );
bool EdictFromPointer( CPointer *pEntityPointer, edict_t*& output );


//-----------------------------------------------------------------------------
// IntHandleFrom* declarations
//-----------------------------------------------------------------------------
bool IntHandleFromBaseHandle( CBaseHandle hBaseHandle, unsigned int& output );
bool IntHandleFromIndex( unsigned int iEntityIndex, unsigned int& output );
bool IntHandleFromEdict( edict_t *pEdict, unsigned int& output );
bool IntHandleFromBaseEntity( CBaseEntity *pBaseEntity, unsigned int& output );
bool IntHandleFromPointer( CPointer *pEntityPointer, unsigned int& output );
bool IntHandleFromUserid( unsigned int iUserID, unsigned int& output );
bool IntHandleFromPlayerInfo( IPlayerInfo *pPlayerInfo, unsigned int& output );


//-----------------------------------------------------------------------------
// BaseEntityFrom* declarations
//-----------------------------------------------------------------------------
bool BaseEntityFromEdict( edict_t *pEdict, CBaseEntity*& output );
bool BaseEntityFromPointer( CPointer *pEntityPointer, CBaseEntity*& output );
bool BaseEntityFromIndex( unsigned int iEntityIndex, CBaseEntity*& output );
bool BaseEntityFromIntHandle( unsigned int iEntityHandle, CBaseEntity*& output );
bool BaseEntityFromBaseHandle( CBaseHandle hBaseHandle, CBaseEntity*& output );
bool BaseEntityFromUserid( unsigned int iUserID, CBaseEntity*& output );
bool BaseEntityFromPlayerInfo( IPlayerInfo *pPlayerInfo, CBaseEntity*& output );


//-----------------------------------------------------------------------------
// UseridFrom* declarations
//-----------------------------------------------------------------------------
bool UseridFromPlayerInfo( IPlayerInfo *pPlayerInfo, unsigned int& output );
bool UseridFromIndex( unsigned int iEntityIndex, unsigned int& output );
bool UseridFromEdict( edict_t *pEdict, unsigned int& output );
bool UseridFromBaseHandle( CBaseHandle hBaseHandle, unsigned int& output );
bool UseridFromIntHandle( unsigned int iEntityHandle, unsigned int& output );
bool UseridFromBaseEntity( CBaseEntity *pBaseEntity, unsigned int& output );
bool UseridFromPointer( CPointer *pEntityPointer, unsigned int& output );


//-----------------------------------------------------------------------------
// PlayerInfoFrom* declarations
//-----------------------------------------------------------------------------
bool PlayerInfoFromIndex( unsigned int iEntityIndex, IPlayerInfo*& output );
bool PlayerInfoFromBaseEntity( CBaseEntity *pBaseEntity, IPlayerInfo*& output );
bool PlayerInfoFromPointer( CPointer *pEntityPointer, IPlayerInfo*& output );
bool PlayerInfoFromEdict( edict_t *pEdict, IPlayerInfo*& output );
bool PlayerInfoFromBaseHandle( CBaseHandle hBaseHandle, IPlayerInfo*& output );
bool PlayerInfoFromIntHandle( unsigned int iEntityHandle, IPlayerInfo*& output );
bool PlayerInfoFromUserid( unsigned int iUserID, IPlayerInfo*& output );


//-----------------------------------------------------------------------------
// IndexFrom* declarations
//-----------------------------------------------------------------------------
bool IndexFromEdict( edict_t *pEdict, unsigned int& output );
bool IndexFromBaseEntity( CBaseEntity *pBaseEntity, unsigned int& output );
bool IndexFromPointer( CPointer *pEntityPointer, unsigned int& output );
bool IndexFromBaseHandle( CBaseHandle hBaseHandle, unsigned int& output );
bool IndexFromIntHandle( unsigned int iEntityHandle, unsigned int& output );
bool IndexFromUserid( unsigned int iUserID, unsigned int& output );
bool IndexFromPlayerInfo( IPlayerInfo *pPlayerInfo, unsigned int& output );


//-----------------------------------------------------------------------------
// BaseHandleFrom* declarations
//-----------------------------------------------------------------------------
bool BaseHandleFromIndex( unsigned int iEntityIndex, CBaseHandle& output );
bool BaseHandleFromIntHandle( unsigned int iEntityHandle, CBaseHandle& output );
bool BaseHandleFromBaseEntity( CBaseEntity *pBaseEntity, CBaseHandle& output );
bool BaseHandleFromPointer( CPointer *pEntityPointer, CBaseHandle& output );
bool BaseHandleFromUserid( unsigned int iUserID, CBaseHandle& output );
bool BaseHandleFromPlayerInfo( IPlayerInfo *pPlayerInfo, CBaseHandle& output );
bool BaseHandleFromEdict( edict_t *pEdict, CBaseHandle& output );


//-----------------------------------------------------------------------------
// PointerFrom* declarations
//-----------------------------------------------------------------------------
bool PointerFromIndex( unsigned int iEntityIndex, CPointer& output );
bool PointerFromBaseEntity( CBaseEntity *pBaseEntity, CPointer& output );
bool PointerFromBaseHandle( CBaseHandle hBaseHandle, CPointer& output );
bool PointerFromIntHandle( unsigned int iEntityHandle, CPointer& output );
bool PointerFromUserid( unsigned int iUserID, CPointer& output );
bool PointerFromPlayerInfo( IPlayerInfo *pPlayerInfo, CPointer& output );
bool PointerFromEdict( edict_t *pEdict, CPointer& output );


//-----------------------------------------------------------------------------
// Helper macro to avoid some redundant typing...
//-----------------------------------------------------------------------------
#define EXPORT_CONVERSION_FUNCTION(to_type, to_name, from_type, from_name, result_wrapper) \
	class to_name##From##from_name##Wrapper \
	{ \
	public: \
		static object wrapper(from_type from) { \
			to_type result; \
			if (!to_name##From##from_name(from, result)) \
				return object();\
			\
			return result_wrapper; \
		} \
	}; \
	def(extract<const char *>(str(XSTRINGIFY(to_name##_from_##from_name)).lower().ptr()), \
		&to_name##From##from_name##Wrapper::wrapper, \
		XSTRINGIFY(Return the to_name (of type `#to_type`) from the given from_name (of type `#from_type`).), \
		args(XSTRINGIFY(from_name)) \
	)


#endif // _CONVERSIONS_H
