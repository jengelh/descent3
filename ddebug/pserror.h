/*
* Descent 3 
* Copyright (C) 2024 Parallax Software
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.

--- HISTORICAL COMMENTS FOLLOW ---

 * $Logfile: /DescentIII/Main/lib/pserror.h $
 * $Revision: 25 $
 * $Date: 3/20/00 12:26p $
 * $Author: Matt $
 *
 * error functions
 *
 * $Log: /DescentIII/Main/lib/pserror.h $
 *
 * 25    3/20/00 12:26p Matt
 * Merge of Duane's post-1.3 changes.
 * Mac include and assert changes
 *
 * 24    10/21/99 9:28p Jeff
 * B.A. Macintosh code merge
 *
 * 23    7/28/99 3:13p Kevin
 * Mac
 *
 * 22    5/10/99 10:53p Ardussi
 * changes to compile on Mac
 *
 * 21    4/14/99 10:46a Kevin
 * Removed OutrageMessageBox from release builds
 *
 * 20    4/01/99 4:50p Matt
 * Took out Warning() function, chaning those calls to mprintf()
 *
 * 19    1/09/99 4:39p Jeff
 * added some ifdefs and fixes to get files to compile under Linux
 *
 * 18    10/18/98 8:52p Matt
 * Revamped debug/error system.
 *
 * 17    10/13/98 12:03p Kevin
 * Changed use of preprocessors for debug, etc.
 *
 * 16    10/12/98 10:20a Samir
 * added parameter to debug init.
 *
 * 15    6/23/98 2:40p Matt
 * Added Yes/No/Cancel type to OutrageMessageBox() and
 * Debug_MesssageBox(), and changed return value from a bool to an
 * integer.
 *
 * 14    6/01/98 4:28p Samir
 * added HEAPCHECK macro.
 *
 * 13    4/23/98 4:14a Samir
 * added warning system.
 *
 * 12    4/08/98 7:19p Samir
 * Added runtime debugging option.
 *
 * 11    4/07/98 9:20p Samir
 * Changes to debug stuff.
 *
 * 10    4/03/98 5:15p Samir
 * Implemented simple debug message filtering.
 *
 * 9     3/20/98 2:43p Samir
 * Some better Int3 support.
 *
 * 8     3/19/98 11:27a Samir
 * Better error checking.
 *
 * 7     3/17/98 2:37p Samir
 * Added debug callback support for assert.
 *
 * 6     3/10/98 5:16p Samir
 * Got debug callbacks working when you hit an Int3.
 *
 * 5     2/20/98 12:11p Matt
 * Changed ASSERT() to print its own mono message and call debug_break
 * directly, instead of using Int3().
 *
 * 4     12/01/97 2:12p Samir
 * Int3 for assertions.
 *
 * 3     9/16/97 5:07p Matt
 * Disable Int3() when _DEBUG not set
 *
 * 2     9/04/97 12:02p Matt
 * Changed the simple form OutrageMessageBox() to be void (instead of
 * bool) since it wasn't returning a meaningful value anyway
 *
 * 19    6/11/97 1:11p Samir
 * Implemented new Debug system
 *
 * 18    3/14/97 4:15p Matt
 * Changed title of OutrageMessageBox() dialogs
 *
 * 17    3/10/97 11:13a Samir
 * Changes made to reflect deletion of OSDebug class from system
 *
 * 16    3/04/97 1:00p Samir
 * Fixed return type prototype errors.
 *
 * 15    3/04/97 12:55p Samir
 * Added yesno and ok messageboxes.
 *
 * 14    3/03/97 5:22p Samir
 * Pass debug object to error_init.
 *
 * 13    2/26/97 7:06p Samir
 * call err_Break instead of Int3 to keep PC code out of pserror.h
 *
 * 12    2/26/97 4:49 PM Jeremy
 * Put "assert.h" as <assert.h> since it's an ANSI file not one of ours.
 *
 * 11    2/06/97 6:32p Samir
 * Int3 now tells us where we broke.
 *
 * 10    2/06/97 11:28a Matt
 * Put do..while around Int3 definition so Int3() acts like a normal
 * statement.
 *
 * 9     1/31/97 2:12p Samir
 * Fixed prototype for error_init
 *
 * 8     1/31/97 1:52p Samir
 * added error_init function
 *
 * 7     1/30/97 6:02p Samir
 * Added DEBUG_STACK macro
 *
 * $NoKeywords: $
 */

#ifndef PSERROR_H
#define PSERROR_H

#include <SDL3/SDL_assert.h>

#include "debug.h"
#include "log.h"

//	initializes error handler.
bool error_Init(bool debugger, const char *app_title);
//	exits the application and prints out a standard error message
void Error(const char *fmt, ...);
//	prints out an assertion error
void AssertionFailed(const char *expstr, const char *file, int line);
// Brings up an error message for an int3
void Int3MessageBox(const char *file, int line);
//	Message box functions

#define MBOX_OK 1
#define MBOX_YESNO 2
#define MBOX_YESNOCANCEL 3
#define MBOX_ABORTRETRYIGNORE 4

//	prints out a standard OS messagebox
void OutrageMessageBox(const char *str, ...);
int OutrageMessageBox(int type, const char *str, ...);
// Sets the title for future OutrageMessageBox() dialogs
void SetMessageBoxTitle(const char *title);
// Write a block of text to the system clipboard
void DumpTextToClipboard(char *text);

//////////////////////////////////////////////////////////////////////////////
//	development debugging functions
//	adds a function to be called when a debug break occurs.
//	undefine any ASSERT macro previously defined.
#ifdef ASSERT
#undef ASSERT
#endif

//	this callback is invoked when a DEBUG_BREAK macro is used.
//		arguments
//			style = 1 if ASSERT
//					= 0 if Int3 debugger break.
extern void (*DebugBreak_callback_stop)();
extern void (*DebugBreak_callback_resume)();

//	set DEBUG_BREAK callback
static inline void SetDebugBreakHandlers(void (*stop)(), void (*resume)()) {
  DebugBreak_callback_stop = stop;
  DebugBreak_callback_resume = resume;
}

#ifndef RELEASE

#include <cstdlib>

// Calls the SDL_assert(false) macro surrounded by calls to the debug callbacks (to turn off & on graphics)
#define DEBUG_BREAK()                                                                                                  \
  do {                                                                                                                 \
    if (DebugBreak_callback_stop)                                                                                      \
      (*DebugBreak_callback_stop)();                                                                                   \
    SDL_assert(false);                                                                                                 \
    if (DebugBreak_callback_resume)                                                                                    \
      (*DebugBreak_callback_resume)();                                                                                 \
  } while (0)

// Does a DEBUG_BREAK() if debugging is turned on.
#define Int3()                                                                                                         \
  do {                                                                                                                 \
    LOG_ERROR.printf("Fatal error at %s:%d.", __FILE__, __LINE__);                                                     \
    DEBUG_BREAK();                                                                                                     \
  } while (0)

// Like the standard C assert(), but if the condition failed and debugging on does a SDL_assert() with debug window.
#define ASSERT(x)                                                                                                      \
  do {                                                                                                                 \
    if (!(x)) {                                                                                                        \
      LOG_ERROR.printf("Assertion failed (%s) in %s:%d.", #x, __FILE__, __LINE__);                                     \
      SDL_assert(x);                                                                                                   \
    }                                                                                                                  \
  } while (0)

#else
#define DEBUG_BREAK()
#define ASSERT(x)
#define Int3()
#endif
#endif
