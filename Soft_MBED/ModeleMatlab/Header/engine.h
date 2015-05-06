/*
 * @(#)engine.h    generated by: makeheader 5.1.5  Mon Jun 29 16:01:41 2009
 *
 *		built from:	../../src/include/copyright.h
 *				../../src/include/pragma_interface.h
 *				engapi.cpp
 *				fengapi.cpp
 *				fengapi_stdcall.cpp
 */

#if defined(_MSC_VER)
# pragma once
#endif
#if defined(__GNUC__) && (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ > 3))
# pragma once
#endif

#ifndef engine_h
#define engine_h


/*
 * Copyright 1984-2003 The MathWorks, Inc.
 * All Rights Reserved.
 */



/* Copyright 2003-2006 The MathWorks, Inc. */

/* Only define EXTERN_C if it hasn't been defined already. This allows
 * individual modules to have more control over managing their exports.
 */
#ifndef EXTERN_C

#ifdef __cplusplus
  #define EXTERN_C extern "C"
#else
  #define EXTERN_C extern
#endif

#endif


#include "matrix.h"     /* mx Routines used in module */


typedef struct engine Engine;	/* Incomplete definition for Engine */


/*
 * Execute matlab statement
 */
EXTERN_C int engEvalString(
	Engine	*ep,		/* engine pointer */
	const char *string	/* string for matlab t execute */
	);


/*
 * Start matlab process for single use.
 * Not currently supported on UNIX.
 */
EXTERN_C Engine *engOpenSingleUse(
			 const char *startcmd, /* exec command string used to start matlab */
			 void *reserved, /* reserved for future use, must be NULL */
			 int *retstatus /* return status */
);


/*
 * SetVisible, do nothing since this function is only for NT 
 */ 
EXTERN_C int engSetVisible( 
		  Engine *ep,        /* engine pointer */ 
		  bool newVal 
		  );


/* 
 * GetVisible, do nothing since this function is only for NT 
 */ 
EXTERN_C int engGetVisible( 
		  Engine *ep,        /* engine pointer */ 
		  bool* bVal 
		  );


/* 
 * Start matlab process
 */
EXTERN_C Engine *engOpen(
	const char *startcmd /* exec command string used to start matlab */
	);


/*
 * Close down matlab server
 */
EXTERN_C int engClose(
	Engine	*ep         /* engine pointer */
	);


/*
 * Get a variable with the specified name from MATLAB's workspace
 */
EXTERN_C mxArray *engGetVariable(
	Engine	*ep,		/* engine pointer */
	const char *name	/* name of variable to get */
	);


/*
 * Put a variable into MATLAB's workspace with the specified name
 */
EXTERN_C int engPutVariable(
		   Engine	*ep,        /* engine pointer */
		   const char *var_name,
		   const mxArray *ap   /* array pointer */
		   );


/*
 * register a buffer to hold matlab text output
 */
EXTERN_C int engOutputBuffer(
	Engine	*ep,		/* engine pointer */
	char	*buffer,	/* character array to hold output */
	int     buflen		/* buffer array length */
	);

#endif /* engine_h */
