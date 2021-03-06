/* $Id: dbglocal.cpp,v 1.10 2004-01-11 11:42:08 sandervl Exp $ */

/*
 * debug logging functions for OS/2
 *
 *
 * Copyright 2000 Sander van Leeuwen
 * Project Odin Software License can be found in LICENSE.TXT
 */
#include <os2wrap.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "dbglocal.h"

#ifdef DEBUG

USHORT DbgEnabledGDI32[DBG_MAXFILES] = {0};
USHORT DbgEnabledLvl2GDI32[DBG_MAXFILES] = {0};

static const char *DbgFileNames[DBG_MAXFILES] =
{
"gdi32",
"opengl",
"callback",
"dibsect",
"initterm",
"resource",
"oslibgdi",
"font",
"text",
"palette",
"line",
"oslibgpi",
"region",
"metafile",
"dibitmap",
"blit",
"rgbcvt",
"objhandle",
"transform",
"printer",
"icm",
"trace",
"fontres",
"devcontext"
};
//******************************************************************************
//******************************************************************************
void ParseLogStatusGDI32()
{
 char *envvar = getenv(DBG_ENVNAME);
 char *envvar2= getenv(DBG_ENVNAME_LVL2);
 char *dbgvar;
 int   i;

    for(i=0;i<DBG_MAXFILES;i++) {
        DbgEnabledGDI32[i] = 1;
    }

    if(!envvar)
        return;

    dbgvar = strstr(envvar, "dll");
    if(dbgvar) {
        if(*(dbgvar-1) == '-') {
            for(i=0;i<DBG_MAXFILES;i++) {
                DbgEnabledGDI32[i] = 0;
            }
        }
    }
    for(i=0;i<DBG_MAXFILES;i++) {
	int len = strlen(DbgFileNames[i]);
        dbgvar = strstr(envvar, DbgFileNames[i]);
        if(dbgvar && !islower(dbgvar[len])) {
            if(*(dbgvar-1) == '-') {
                    DbgEnabledGDI32[i] = 0;
            }
            else    
            if(*(dbgvar-1) == '+') {
		DbgEnabledGDI32[i] = 1;
	    }
        }
    }
    if(envvar2) {
    	dbgvar = strstr(envvar2, "dll");
	if(dbgvar) {
	        if(*(dbgvar-1) == '+') {
	            for(i=0;i<DBG_MAXFILES;i++) {
	                DbgEnabledLvl2GDI32[i] = 1;
	            }
	        }
	}
	for(i=0;i<DBG_MAXFILES;i++) {
		int len = strlen(DbgFileNames[i]);
	        dbgvar = strstr(envvar2, DbgFileNames[i]);
	        if(dbgvar && !islower(dbgvar[len])) {
	            if(*(dbgvar-1) == '-') {
	                    DbgEnabledLvl2GDI32[i] = 0;
	            }
	            else    
	            if(*(dbgvar-1) == '+') {
			DbgEnabledLvl2GDI32[i] = 1;
		    }
		}
        }
    }
}
//******************************************************************************
//******************************************************************************

#endif
