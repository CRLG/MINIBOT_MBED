/*
 * @(#)mcr.h    generated by: makeheader 5.1.5  Mon Jun 29 16:01:58 2009
 *
 *		built from:	../../src/include/copyright.h
 *				../../src/include/pragma_interface.h
 *				runtime/AutoInterpreterState.cpp
 *				runtime/DefaultPrintHandlerSinkFactory.cpp
 *				runtime/DepfunRules.cpp
 *				runtime/InterpreterThread.cpp
 *				runtime/InterpreterThreadFactory.cpp
 *				runtime/PutsFnSink.cpp
 *				runtime/PutsFnStreamBuffer.cpp
 *				runtime/StdCmdWinSink.cpp
 *				runtime/assert_guard.cpp
 *				runtime/context.cpp
 *				runtime/emergency_exit.cpp
 *				runtime/external_pragmas.cpp
 *				runtime/initterm.cpp
 *				runtime/lmgrsup.cpp
 *				runtime/lmgrsup_mac.cpp
 *				runtime/loginout.cpp
 *				runtime/mcrDepfun.cpp
 *				runtime/mcrFunctionSignature.cpp
 *				runtime/mcrInstance.cpp
 *				runtime/mcrInstanceCounter.cpp
 *				runtime/mcrInstanceInternal.cpp
 *				runtime/mcrInstantiationError.cpp
 *				runtime/mcrOptions.cpp
 *				runtime/mcr_instance_data.cpp
 *				runtime/mcr_mutex.cpp
 *				runtime/mwassert.cpp
 *				runtime/runtime.cpp
 *				runtime/shield.cpp
 *				runtime/shutdown.cpp
 *				runtime/sighndl.cpp
 *				runtime/thread_debug.cpp
 */

#if defined(_MSC_VER)
# pragma once
#endif
#if defined(__GNUC__) && (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ > 3))
# pragma once
#endif

#ifndef mcr_h
#define mcr_h


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

#endif /* mcr_h */
