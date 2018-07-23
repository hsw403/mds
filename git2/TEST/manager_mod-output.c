#line 3 "vcast_preprocess.6652.10.c"                                                                                                                           
# 1 "vcast_preprocess.6652.8.c" 1

typedef int VECTORCAST_MARKER__UNIT_PREFIX_START;

typedef int VECTORCAST_MARKER__UNIT_PREFIX_END;
# 1 "C:/VCAST/Tutorial/c/manager.c" 1
# 1 "C:/VCAST/Tutorial/c/ctypes.h" 1
# 14 "C:/VCAST/Tutorial/c/ctypes.h"
typedef float FLOAT;






enum boolean { v_false, v_true };
enum soups { NO_SOUP, ONION, CHOWDER };
enum salads { NO_SALAD, CAESAR, GREEN };
enum entrees { NO_ENTREE, STEAK, CHICKEN, LOBSTER, PASTA };
enum desserts { NO_DESSERT, CAKE, PIE, FRUIT };
enum beverages { NO_BEVERAGE, WINE, BEER, MIXED_DRINK, SODA };

struct order_type
{
  enum soups Soup;
  enum salads Salad;
  enum entrees Entree;
  enum desserts Dessert;
  enum beverages Beverage;
};

typedef unsigned short seat_index_type;
typedef unsigned short table_index_type;

struct table_data_type
{
  enum boolean Is_Occupied;
  seat_index_type Number_In_Party;
  char Designator;
  char Wait_Person[10];
  struct order_type Order[4];
  FLOAT Check_Total;
};

typedef char name_type[32];
# 2 "C:/VCAST/Tutorial/c/manager.c" 2
# 1 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/../../../../include/stdio.h" 1 3
/*
 * stdio.h
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is a part of the mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within the package.
 *
 * Definitions of types and prototypes of functions for standard input and
 * output.
 *
 * NOTE: The file manipulation functions provided by Microsoft seem to
 * work with either slash (/) or backslash (\) as the directory separator.
 *
 */




/* All the headers include this file. */
# 1 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/../../../../include/_mingw.h" 1 3

/*
 * _mingw.h
 *
 * Mingw specific macros included by ALL include files.
 *
 * This file is part of the Mingw32 package.
 *
 * Contributors:
 *  Created by Mumit Khan  <khan@xraylith.wisc.edu>
 *
 *  THIS SOFTWARE IS NOT COPYRIGHTED
 *
 *  This source code is offered for use in the public domain. You may
 *  use, modify or distribute it freely.
 *
 *  This code is distributed in the hope that it will be useful but
 *  WITHOUT ANY WARRANTY. ALL WARRANTIES, EXPRESS OR IMPLIED ARE HEREBY
 *  DISCLAIMED. This includes but is not limited to warranties of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 */
# 32 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/../../../../include/_mingw.h" 3
       
# 33 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/../../../../include/_mingw.h" 3



/* These are defined by the user (or the compiler)
   to specify how identifiers are imported from a DLL.

   __DECLSPEC_SUPPORTED            Defined if dllimport attribute is supported.
   __MINGW_IMPORT                  The attribute definition to specify imported
                                   variables/functions.
   _CRTIMP                         As above.  For MS compatibility.
   __MINGW32_VERSION               Runtime version.
   __MINGW32_MAJOR_VERSION         Runtime major version.
   __MINGW32_MINOR_VERSION         Runtime minor version.
   __MINGW32_BUILD_DATE            Runtime build date.

   Macros to enable MinGW features which deviate from standard MSVC
   compatible behaviour; these may be specified directly in user code,
   activated implicitly, (e.g. by specifying _POSIX_C_SOURCE or such),
   or by inclusion in __MINGW_FEATURES__:

   __USE_MINGW_ANSI_STDIO          Select a more ANSI C99 compatible
                                   implementation of printf() and friends.

   Other macros:

   __int64                         define to be long long.  Using a typedef
                                   doesn't work for "unsigned __int64"

   All headers should include this first, and then use __DECLSPEC_SUPPORTED
   to choose between the old ``__imp__name'' style or __MINGW_IMPORT
   style declarations.  */


/* Manifest definitions identifying the flag bits, controlling activation
 * of MinGW features, as specified by the user in __MINGW_FEATURES__.
 */

/*
 * The following three are not yet formally supported; they are
 * included here, to document anticipated future usage.
 */




/* Try to avoid problems with outdated checks for GCC __attribute__ support.  */
# 123 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/../../../../include/_mingw.h" 3
   /* Note the extern. This is needed to work around GCC's
      limitations in handling dllimport attribute.  */
# 142 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/../../../../include/_mingw.h" 3
/*
 * The next two defines can cause problems if user code adds the
 * __cdecl attribute like so:
 * void __attribute__ ((__cdecl)) foo(void); 
 */
# 232 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/../../../../include/_mingw.h" 3
/* Attribute `nonnull' was valid as of gcc 3.3.  We don't use GCC's
   variadiac macro facility, because variadic macros cause syntax
   errors with  --traditional-cpp.  */
# 254 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/../../../../include/_mingw.h" 3
/* TODO: Mark (almost) all CRT functions as __MINGW_NOTHROW.  This will
allow GCC to optimize away some EH unwind code, at least in DW2 case.  */


/*  High byte is the major version, low byte is the minor. */



/* Activation of MinGW specific extended features:
 */

/*
 * If user didn't specify it explicitly...
 */
# 279 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/../../../../include/_mingw.h" 3
   /*
    * otherwise use whatever __MINGW_FEATURES__ specifies...
    */
# 20 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/../../../../include/stdio.h" 2 3






# 1 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/include/stddef.h" 1 3 4
/* Copyright (C) 1989, 1997, 1998, 1999, 2000, 2002, 2004, 2009
   Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  7.17  Common definitions  <stddef.h>
 */






/* Any one of these symbols __need_* means that GNU libc
   wants us just to define one data type.  So don't define
   the symbols that indicate this file's entire job has been done.  */
# 49 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/include/stddef.h" 3 4
/* This avoids lossage on SunOS but only if stdtypes.h comes first.
   There's no way to win with the other order!  Sun lossage.  */

/* On 4.3bsd-net2, make sure ansi.h is included, so we have
   one less case to deal with in the following.  */



/* On FreeBSD 5, machine/ansi.h does not exist anymore... */




/* In 4.3bsd-net2, machine/ansi.h defines these symbols, which are
   defined if the corresponding type is *not* defined.
   FreeBSD-2.1 defines _MACHINE_ANSI_H_ instead of _ANSI_H_ */
# 94 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/include/stddef.h" 3 4
/* Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it.  */




/* On VxWorks, <type/vxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected.  */
# 119 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/include/stddef.h" 3 4
/* In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2.  */

/* Signed type of difference of two pointers.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 164 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/include/stddef.h" 3 4
/* Unsigned type of `sizeof' something.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 211 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/include/stddef.h" 3 4
typedef unsigned int size_t;
# 237 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/include/stddef.h" 3 4
/* Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 278 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/include/stddef.h" 3 4
/* On BSD/386 1.1, at least, machine/ansi.h defines _BSD_WCHAR_T_
   instead of _WCHAR_T_, and _BSD_RUNE_T_ (which, unlike the other
   symbols in the _FOO_T_ family, stays defined even after its
   corresponding type is defined).  If we define wchar_t, then we
   must undef _WCHAR_T_; for BSD/386 1.1 (and perhaps others), if
   we undef _WCHAR_T_, then we must also define rune_t, since 
   headers like runetype.h assume that if machine/ansi.h is included,
   and _BSD_WCHAR_T_ is not defined, then rune_t is available.
   machine/ansi.h says, "Note that _WCHAR_T_ and _RUNE_T_ must be of
   the same type." */
# 305 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/include/stddef.h" 3 4
/* FreeBSD 5 can't be handled well using "traditional" logic above
   since it no longer defines _BSD_RUNE_T_ yet still desires to export
   rune_t in some cases... */
# 323 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/include/stddef.h" 3 4
typedef short unsigned int wchar_t;
# 352 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/include/stddef.h" 3 4
typedef short unsigned int wint_t;




/*  In 4.3bsd-net2, leave these undefined to indicate that size_t, etc.
    are already defined.  */
/*  BSD/OS 3.1 and FreeBSD [23].x require the MACHINE_ANSI_H check here.  */
# 392 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/include/stddef.h" 3 4
/* A null pointer constant.  */
# 27 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/../../../../include/stdio.h" 2 3

# 1 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/include/stdarg.h" 1 3 4
/* Copyright (C) 1989, 1997, 1998, 1999, 2000, 2009 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  7.15  Variable arguments  <stdarg.h>
 */
# 36 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/include/stdarg.h" 3 4
/* Define __gnuc_va_list.  */



typedef __builtin_va_list __gnuc_va_list;


/* Define the standard macros for the user,
   if this invocation was from the user program.  */
# 29 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/../../../../include/stdio.h" 2 3



/* Flags for the iobuf structure  */





/*
 * The three standard file pointers provided by the run time library.
 * NOTE: These will go to the bit-bucket silently in GUI applications!
 */




/* Returned by various functions on end of file condition or error. */


/*
 * The maximum length of a file name. You should use GetVolumeInformation
 * instead of this constant. But hey, this works.
 * Also defined in io.h.
 */




/*
 * The maximum number of files that may be open at once. I have set this to
 * a conservative number. The actual value may be higher.
 */


/* After creating this many names, tmpnam and tmpfile return NULL */

/*
 * Tmpnam, tmpfile and, sometimes, _tempnam try to create
 * temp files in the root directory of the current drive
 * (not in pwd, as suggested by some older MS doc's).
 * Redefining these macros does not effect the CRT functions.
 */






/*
 * The maximum size of name (including NUL) that will be put in the user
 * supplied buffer caName for tmpnam.
 * Inferred from the size of the static buffer returned by tmpnam
 * when passed a NULL argument. May actually be smaller.
 */
# 97 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/../../../../include/stdio.h" 3
/*
 * The buffer size as used by setbuf such that it is equivalent to
 * (void) setvbuf(fileSetBuffer, caBuffer, _IOFBF, BUFSIZ).
 */


/* Constants for nOrigin indicating the position relative to which fseek
 * sets the file position.  Defined unconditionally since ISO and POSIX
 * say they are defined here.  */
# 120 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/../../../../include/stdio.h" 3
/*
 * The structure underlying the FILE type.
 *
 * Some believe that nobody in their right mind should make use of the
 * internals of this structure. Provided by Pedro A. Aranda Gutiirrez
 * <paag@tid.es>.
 */


typedef struct _iobuf
{
 char* _ptr;
 int _cnt;
 char* _base;
 int _flag;
 int _file;
 int _charbuf;
 int _bufsiz;
 char* _tmpfname;
} FILE;



/*
 * The standard file handles
 */
# 154 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/../../../../include/stdio.h" 3
extern __attribute__ ((__dllimport__)) FILE _iob[]; /* An array of FILE imported from DLL. */
# 166 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/../../../../include/stdio.h" 3
/*
 * File Operations
 */
 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fopen (const char*, const char*);
 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) freopen (const char*, const char*, FILE*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fflush (FILE*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fclose (FILE*);
/* MS puts remove & rename (but not wide versions) in io.h  also */
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) remove (const char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) rename (const char*, const char*);
 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) tmpfile (void);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) tmpnam (char*);


 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _tempnam (const char*, const char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _rmtmp(void);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _unlink (const char*);


 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) tempnam (const char*, const char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) rmtmp(void);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) unlink (const char*);



 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) setvbuf (FILE*, char*, int, size_t);

 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) setbuf (FILE*, char*);

/*
 * Formatted Output
 *
 * MSVCRT implementations are not ANSI C99 conformant...
 * we offer these conforming alternatives from libmingwex.a
 */



extern int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __mingw_fprintf(FILE*, const char*, ...);
extern int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __mingw_printf(const char*, ...);
extern int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __mingw_sprintf(char*, const char*, ...);
extern int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __mingw_snprintf(char*, size_t, const char*, ...);
extern int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __mingw_vfprintf(FILE*, const char*, __gnuc_va_list);
extern int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __mingw_vprintf(const char*, __gnuc_va_list);
extern int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __mingw_vsprintf(char*, const char*, __gnuc_va_list);
extern int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __mingw_vsnprintf(char*, size_t, const char*, __gnuc_va_list);
# 290 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/../../../../include/stdio.h" 3
/*
 * Default configuration: simply direct all calls to MSVCRT...
 */
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fprintf (FILE*, const char*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) printf (const char*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) sprintf (char*, const char*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vfprintf (FILE*, const char*, __gnuc_va_list);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vprintf (const char*, __gnuc_va_list);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vsprintf (char*, const char*, __gnuc_va_list);


/*
 * Regardless of user preference, always offer these alternative
 * entry points, for direct access to the MSVCRT implementations.
 */



 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __msvcrt_fprintf(FILE*, const char*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __msvcrt_printf(const char*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __msvcrt_sprintf(char*, const char*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __msvcrt_vfprintf(FILE*, const char*, __gnuc_va_list);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __msvcrt_vprintf(const char*, __gnuc_va_list);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __msvcrt_vsprintf(char*, const char*, __gnuc_va_list);



/* The following pair ALWAYS refer to the MSVCRT implementations...
 */
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _snprintf (char*, size_t, const char*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _vsnprintf (char*, size_t, const char*, __gnuc_va_list);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _vscprintf (const char*, __gnuc_va_list);


/*
 * Microsoft does not provide implementations for the following,
 * which are required by C99.  Note in particular that the corresponding
 * Microsoft implementations of _snprintf() and _vsnprintf() are *not*
 * compatible with C99, but the following are; if you want the MSVCRT
 * behaviour, you *must* use the Microsoft uglified names.
 */
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) snprintf (char *, size_t, const char *, ...);
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vsnprintf (char *, size_t, const char *, __gnuc_va_list);

int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vscanf (const char * __restrict__, __gnuc_va_list);
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vfscanf (FILE * __restrict__, const char * __restrict__,
       __gnuc_va_list);
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vsscanf (const char * __restrict__,
       const char * __restrict__, __gnuc_va_list);



/*
 * Formatted Input
 */

 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fscanf (FILE*, const char*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) scanf (const char*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) sscanf (const char*, const char*, ...);
/*
 * Character Input and Output Functions
 */

 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fgetc (FILE*);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fgets (char*, int, FILE*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fputc (int, FILE*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fputs (const char*, FILE*);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) gets (char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) puts (const char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) ungetc (int, FILE*);

/* Traditionally, getc and putc are defined as macros. but the
   standard doesn't say that they must be macros.
   We use inline functions here to allow the fast versions
   to be used in C++ with namespace qualification, eg., ::getc.

   _filbuf and _flsbuf  are not thread-safe. */
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _filbuf (FILE*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _flsbuf (int, FILE*);



extern __inline__ int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) getc (FILE* __F)
{
  return (--__F->_cnt >= 0)
    ? (int) (unsigned char) *__F->_ptr++
    : _filbuf (__F);
}

extern __inline__ int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) putc (int __c, FILE* __F)
{
  return (--__F->_cnt >= 0)
    ? (int) (unsigned char) (*__F->_ptr++ = (char)__c)
    : _flsbuf (__c, __F);
}

extern __inline__ int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) getchar (void)
{
  return (--(&_iob[0])->_cnt >= 0)
    ? (int) (unsigned char) *(&_iob[0])->_ptr++
    : _filbuf ((&_iob[0]));
}

extern __inline__ int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) putchar(int __c)
{
  return (--(&_iob[1])->_cnt >= 0)
    ? (int) (unsigned char) (*(&_iob[1])->_ptr++ = (char)__c)
    : _flsbuf (__c, (&_iob[1]));}
# 408 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/../../../../include/stdio.h" 3
/*
 * Direct Input and Output Functions
 */

 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fread (void*, size_t, size_t, FILE*);
 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fwrite (const void*, size_t, size_t, FILE*);

/*
 * File Positioning Functions
 */

 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fseek (FILE*, long, int);
 long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) ftell (FILE*);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) rewind (FILE*);
# 445 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/../../../../include/stdio.h" 3
/*
 * An opaque data type used for storing file positions... The contents of
 * this type are unknown, but we (the compiler) need to know the size
 * because the programmer using fgetpos and fsetpos will be setting aside
 * storage for fpos_t structres. Actually I tested using a byte array and
 * it is fairly evident that the fpos_t type is a long (in CRTDLL.DLL).
 * Perhaps an unsigned long? TODO? It's definitely a 64-bit number in
 * MSVCRT however, and for now `long long' will do.
 */

typedef long long fpos_t;




 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fgetpos (FILE*, fpos_t*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fsetpos (FILE*, const fpos_t*);

/*
 * Error Functions
 */

 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) feof (FILE*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) ferror (FILE*);
# 480 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/../../../../include/stdio.h" 3
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) clearerr (FILE*);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) perror (const char*);



/*
 * Pipes
 */
 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _popen (const char*, const char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _pclose (FILE*);


 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) popen (const char*, const char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) pclose (FILE*);


/*
 * Other Non ANSI functions
 */
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _flushall (void);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _fgetchar (void);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _fputchar (int);
 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _fdopen (int, const char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _fileno (FILE*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _fcloseall (void);
 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _fsopen (const char*, const char*, int);

 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _getmaxstdio (void);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _setmaxstdio (int);
# 522 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/../../../../include/stdio.h" 3
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fgetchar (void);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fputchar (int);
 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fdopen (int, const char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fileno (FILE*);
# 534 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/../../../../include/stdio.h" 3
# 1 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/../../../../include/sys/types.h" 1 3
/*
 * types.h
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is a part of the mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within the package.
 *
 * The definition of constants, data types and global variables.
 *
 */




/* All the headers include this file. */






# 1 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/include/stddef.h" 1 3 4
/* Copyright (C) 1989, 1997, 1998, 1999, 2000, 2002, 2004, 2009
   Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional
permissions described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and
a copy of the GCC Runtime Library Exception along with this program;
see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/*
 * ISO C Standard:  7.17  Common definitions  <stddef.h>
 */






/* Any one of these symbols __need_* means that GNU libc
   wants us just to define one data type.  So don't define
   the symbols that indicate this file's entire job has been done.  */
# 49 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/include/stddef.h" 3 4
/* This avoids lossage on SunOS but only if stdtypes.h comes first.
   There's no way to win with the other order!  Sun lossage.  */

/* On 4.3bsd-net2, make sure ansi.h is included, so we have
   one less case to deal with in the following.  */



/* On FreeBSD 5, machine/ansi.h does not exist anymore... */




/* In 4.3bsd-net2, machine/ansi.h defines these symbols, which are
   defined if the corresponding type is *not* defined.
   FreeBSD-2.1 defines _MACHINE_ANSI_H_ instead of _ANSI_H_ */
# 94 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/include/stddef.h" 3 4
/* Sequent's header files use _PTRDIFF_T_ in some conflicting way.
   Just ignore it.  */




/* On VxWorks, <type/vxTypesBase.h> may have defined macros like
   _TYPE_size_t which will typedef size_t.  fixincludes patched the
   vxTypesBase.h so that this macro is only defined if _GCC_SIZE_T is
   not defined, and so that defining this macro defines _GCC_SIZE_T.
   If we find that the macros are still defined at this point, we must
   invoke them so that the type is defined as expected.  */
# 119 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/include/stddef.h" 3 4
/* In case nobody has defined these types, but we aren't running under
   GCC 2.00, make sure that __PTRDIFF_TYPE__, __SIZE_TYPE__, and
   __WCHAR_TYPE__ have reasonable values.  This can happen if the
   parts of GCC is compiled by an older compiler, that actually
   include gstddef.h, such as collect2.  */

/* Signed type of difference of two pointers.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 149 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/include/stddef.h" 3 4
typedef int ptrdiff_t;
# 159 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/include/stddef.h" 3 4
/* If this symbol has done its job, get rid of it.  */




/* Unsigned type of `sizeof' something.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 237 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/include/stddef.h" 3 4
/* Wide character type.
   Locale-writers should change this as necessary to
   be big enough to hold unique values not between 0 and 127,
   and not (wchar_t) -1, for each defined multibyte character.  */

/* Define this type if we are doing the whole job,
   or if we want this type in particular.  */
# 357 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/include/stddef.h" 3 4
/*  In 4.3bsd-net2, leave these undefined to indicate that size_t, etc.
    are already defined.  */
/*  BSD/OS 3.1 and FreeBSD [23].x require the MACHINE_ANSI_H check here.  */
# 392 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/include/stddef.h" 3 4
/* A null pointer constant.  */
# 22 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/../../../../include/sys/types.h" 2 3





typedef long __time32_t;




typedef long long __time64_t;




/* FIXME __STRICT_ANSI__ ! */







typedef __time32_t time_t;






typedef long _off_t;


typedef _off_t off_t;







typedef unsigned int _dev_t;





typedef _dev_t dev_t;






typedef short _ino_t;


typedef _ino_t ino_t;






typedef int _pid_t;


typedef _pid_t pid_t;






typedef unsigned short _mode_t;


typedef _mode_t mode_t;






typedef int _sigset_t;


typedef _sigset_t sigset_t;





typedef int _ssize_t;


typedef _ssize_t ssize_t;





typedef long long fpos64_t;




typedef long long off64_t;



typedef unsigned int useconds_t;
# 535 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/../../../../include/stdio.h" 2 3
extern __inline__ FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fopen64 (const char* filename, const char* mode)
{
  return fopen (filename, mode);
}

int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fseeko64 (FILE*, off64_t, int);






extern __inline__ off64_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) ftello64 (FILE * stream)
{
  fpos_t pos;
  if (fgetpos(stream, &pos))
    return -1LL;
  else
   return ((off64_t) pos);
}




/* Wide  versions */


/*  also in wchar.h - keep in sync */
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fwprintf (FILE*, const wchar_t*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wprintf (const wchar_t*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _snwprintf (wchar_t*, size_t, const wchar_t*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vfwprintf (FILE*, const wchar_t*, __gnuc_va_list);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vwprintf (const wchar_t*, __gnuc_va_list);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _vsnwprintf (wchar_t*, size_t, const wchar_t*, __gnuc_va_list);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _vscwprintf (const wchar_t*, __gnuc_va_list);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fwscanf (FILE*, const wchar_t*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wscanf (const wchar_t*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) swscanf (const wchar_t*, const wchar_t*, ...);
 wint_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fgetwc (FILE*);
 wint_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fputwc (wchar_t, FILE*);
 wint_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) ungetwc (wchar_t, FILE*);

/* These differ from the ISO C prototypes, which have a maxlen parameter (like snprintf).  */

 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) swprintf (wchar_t*, const wchar_t*, ...);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vswprintf (wchar_t*, const wchar_t*, __gnuc_va_list);



 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fgetws (wchar_t*, int, FILE*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fputws (const wchar_t*, FILE*);
 wint_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) getwc (FILE*);
 wint_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) getwchar (void);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _getws (wchar_t*);
 wint_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) putwc (wint_t, FILE*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _putws (const wchar_t*);
 wint_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) putwchar (wint_t);
 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wfdopen(int, const wchar_t *);
 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wfopen (const wchar_t*, const wchar_t*);
 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wfreopen (const wchar_t*, const wchar_t*, FILE*);
 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wfsopen (const wchar_t*, const wchar_t*, int);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wtmpnam (wchar_t*);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wtempnam (const wchar_t*, const wchar_t*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wrename (const wchar_t*, const wchar_t*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wremove (const wchar_t*);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wperror (const wchar_t*);
 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wpopen (const wchar_t*, const wchar_t*);



int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) snwprintf (wchar_t* s, size_t n, const wchar_t* format, ...);
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vsnwprintf (wchar_t* s, size_t n, const wchar_t* format, __gnuc_va_list arg);





int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vwscanf (const wchar_t * __restrict__, __gnuc_va_list);
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vfwscanf (FILE * __restrict__,
         const wchar_t * __restrict__, __gnuc_va_list);
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) vswscanf (const wchar_t * __restrict__,
         const wchar_t * __restrict__, __gnuc_va_list);
# 625 "c:\\vcast\\mingw\\bin\\../lib/gcc/mingw32/4.5.2/../../../../include/stdio.h" 3
 FILE* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wpopen (const wchar_t*, const wchar_t*);



/*
 * Other Non ANSI wide functions
 */
 wint_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _fgetwchar (void);
 wint_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _fputwchar (wint_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _getw (FILE*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _putw (int, FILE*);


 wint_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fgetwchar (void);
 wint_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fputwchar (wint_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) getw (FILE*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) putw (int, FILE*);
# 3 "C:/VCAST/Tutorial/c/manager.c" 2
struct table_data_type Get_Table_Record(table_index_type Table);
void Update_Table_Record(table_index_type Table, struct table_data_type Data);

/* Allow 10 Parties to wait */
static name_type WaitingList[10];
static unsigned int WaitingListSize = 0;
static unsigned int WaitingListIndex = 0;

/* This function will add a free dessert to specific orders based on the 
   entree, salad, and beverage choice */
void Add_Included_Dessert(struct order_type* Order)
{/*vcast_internal_start*/
extern struct order_type *P_9_1_1

;
extern unsigned char SBF_9_1;
if(SBF_9_1) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_1
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_1
  if ( vcast_is_in_driver ) {
    P_9_1_1 = Order;
    vCAST_COMMON_STUB_PROC_9( 9, 1, 2, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_1
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_1
  vCAST_USER_CODE_TIMER_START();
  return;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/

  if(Order->Entree == STEAK &&
     Order->Salad == CAESAR &&
     Order->Beverage == MIXED_DRINK) {

    Order->Dessert = PIE;

  } else if(Order->Entree == LOBSTER &&
            Order->Salad == GREEN &&
            Order->Beverage == WINE) {

    Order->Dessert = CAKE;
  }
/*vcast_internal_start*/}/*vcast_internal_end*/
}

int Place_Order(table_index_type Table,
                seat_index_type Seat,
                struct order_type Order)
{/*vcast_internal_start*/
extern unsigned short P_9_2_1

;
extern unsigned short P_9_2_2

;
extern struct order_type P_9_2_3

;
extern int R_9_2;
extern unsigned char SBF_9_2;
if(SBF_9_2) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_2
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_2
  if ( vcast_is_in_driver ) {
    P_9_2_1 = Table;
    P_9_2_2 = Seat;
    P_9_2_3 = Order;
    vCAST_COMMON_STUB_PROC_9( 9, 2, 4, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_2
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_2
  vCAST_USER_CODE_TIMER_START();
  return R_9_2;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/

  struct table_data_type Table_Data;

printf("%d",-7%-3);
  Table_Data = Get_Table_Record(Table);
  Table_Data.Is_Occupied = v_true;
  Table_Data.Number_In_Party = Table_Data.Number_In_Party + 1;
  Table_Data.Order[Seat] = Order;

  /* Add a free dessert in some cases */
  Add_Included_Dessert(&Table_Data.Order[Seat]);

  switch(Order.Entree)
    {
    case NO_ENTREE :
       break;
    case STEAK :
       Table_Data.Check_Total = Table_Data.Check_Total + 14.0;
       break;
    case CHICKEN :
       Table_Data.Check_Total = Table_Data.Check_Total + 10.0;
       break;
    case LOBSTER :
       Table_Data.Check_Total = Table_Data.Check_Total + 18.0;
       break;
    case PASTA :
       Table_Data.Check_Total = Table_Data.Check_Total + 12.0;
       break;
    }

  Update_Table_Record(Table, Table_Data);
  return 0;
/*vcast_internal_start*/}/*vcast_internal_end*/
}

int Clear_Table(table_index_type Table)
{/*vcast_internal_start*/
extern unsigned short P_9_3_1

;
extern int R_9_3;
extern unsigned char SBF_9_3;
if(SBF_9_3) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_3
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_3
  if ( vcast_is_in_driver ) {
    P_9_3_1 = Table;
    vCAST_COMMON_STUB_PROC_9( 9, 3, 2, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_3
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_3
  vCAST_USER_CODE_TIMER_START();
  return R_9_3;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/

  struct table_data_type Table_Data;
  seat_index_type Seat;
  Table_Data = Get_Table_Record(Table);
  Table_Data.Is_Occupied = v_false;
  Table_Data.Number_In_Party = 1;

  for (Seat=0; Seat < 4; Seat++){
      Table_Data.Order[Seat].Soup = NO_SOUP;
      Table_Data.Order[Seat].Salad = NO_SALAD;
      Table_Data.Order[Seat].Entree = NO_ENTREE;
      Table_Data.Order[Seat].Dessert = NO_DESSERT;
      Table_Data.Order[Seat].Beverage = NO_BEVERAGE;
   }

  Table_Data.Check_Total = 0;

  Update_Table_Record(Table, Table_Data);
  return 0;
/*vcast_internal_start*/}/*vcast_internal_end*/
}

FLOAT Get_Check_Total(table_index_type Table)
{/*vcast_internal_start*/
extern unsigned short P_9_4_1

;
extern float R_9_4;
extern unsigned char SBF_9_4;
if(SBF_9_4) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_4
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_4
  if ( vcast_is_in_driver ) {
    P_9_4_1 = Table;
    vCAST_COMMON_STUB_PROC_9( 9, 4, 2, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_4
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_4
  vCAST_USER_CODE_TIMER_START();
  return R_9_4;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/

  struct table_data_type Table_Data;
  Table_Data = Get_Table_Record(Table);
  return (Table_Data.Check_Total);
/*vcast_internal_start*/}/*vcast_internal_end*/
}

void Add_Party_To_Waiting_List(char* Name)
{/*vcast_internal_start*/
extern char *P_9_5_1

;
extern unsigned char SBF_9_5;
if(SBF_9_5) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_5
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_5
  if ( vcast_is_in_driver ) {
    P_9_5_1 = Name;
    vCAST_COMMON_STUB_PROC_9( 9, 5, 2, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_5
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_5
  vCAST_USER_CODE_TIMER_START();
  return;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/

  int i = 0;
  if(WaitingListSize > 9)
    WaitingListSize = 0;

  while(Name && *Name) {
    WaitingList[WaitingListSize][i++] = *Name;
    Name++;
  }
  WaitingList[WaitingListSize++][i] = 0;
/*vcast_internal_start*/}/*vcast_internal_end*/
}

char* Get_Next_Party_To_Be_Seated(void)
{/*vcast_internal_start*/
extern char *R_9_6;
extern unsigned char SBF_9_6;
if(SBF_9_6) {
  vCAST_USER_CODE_TIMER_STOP();
#define BEGINNING_OF_STUB_USER_CODE_9_6
#include "vcast_configure_stub.c"
#undef BEGINNING_OF_STUB_USER_CODE_9_6
  if ( vcast_is_in_driver ) {
    vCAST_COMMON_STUB_PROC_9( 9, 6, 1, 0 );
  } /* vcast_is_in_driver */
#define END_OF_STUB_USER_CODE_9_6
#include "vcast_configure_stub.c"
#undef END_OF_STUB_USER_CODE_9_6
  vCAST_USER_CODE_TIMER_START();
  return R_9_6;
}
/*vcast_internal_end*/
/*vcast_internal_start*/{/*vcast_internal_end*/

  if(WaitingListIndex > 9)
    WaitingListIndex = 0;
  return WaitingList[WaitingListIndex++];
/*vcast_internal_start*/}/*vcast_internal_end*/
}
# 6 "vcast_preprocess.6652.8.c" 2

/*vcast_internal_start*/struct order_type *P_9_1_1

;
unsigned char SBF_9_1 = 0;

/*vcast_internal_end*/
/*vcast_internal_start*/unsigned short P_9_2_1

;
unsigned short P_9_2_2

;
struct order_type P_9_2_3

;
int R_9_2;
unsigned char SBF_9_2 = 0;

/*vcast_internal_end*/
/*vcast_internal_start*/unsigned short P_9_3_1

;
int R_9_3;
unsigned char SBF_9_3 = 0;

/*vcast_internal_end*/
/*vcast_internal_start*/unsigned short P_9_4_1

;
float R_9_4;
unsigned char SBF_9_4 = 0;

/*vcast_internal_end*/
/*vcast_internal_start*/char *P_9_5_1

;
unsigned char SBF_9_5 = 0;

/*vcast_internal_end*/
/*vcast_internal_start*/char *R_9_6;
unsigned char SBF_9_6 = 0;

/*vcast_internal_end*/
typedef int VECTORCAST_MARKER__UNIT_APPENDIX_START;

typedef int VECTORCAST_MARKER__UNIT_APPENDIX_END;
# 4 "vcast_preprocess.6652.10.c" 2

                                               
