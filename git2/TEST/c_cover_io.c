#ifndef VCAST_COVER_IO_SYSTEM_CODE
/* If the c_cover_io.c file is being compiled as a separate file instead
   of being appended to a unit, VCAST_COVER_IO_SYSTEM_CODE will not have
   a value yet. Assign it to 1 so the definitions which depend on system
   headers are reached. */
#define VCAST_COVER_IO_SYSTEM_CODE 1
#endif /* VCAST_COVER_IO_SYSTEM_CODE */

#ifndef VCAST_COVER_IO_COVER_CODE
/* If the c_cover_io.c file is being compiled as a separate file instead
   of being appended to a unit, VCAST_COVER_IO_COVER_CODE will not have
   a value yet. Assign it to 1 so the definitions which are independent of
   system headers (but may require vcast_c_options.h) are reached. */
#define VCAST_COVER_IO_COVER_CODE 1
#endif /* VCAST_COVER_IO_COVER_CODE */

#ifndef VCAST_ATTRIBUTE_CODE
/* The default attribute for the variables vcast_ascii_coverage_data_pool
   and vcast_avltree_data_pool is no attribute. */
#define VCAST_ATTRIBUTE_CODE
#endif /* VCAST_ATTRIBUTE_CODE */

/* we needed to add this define because some compilers, Code Warrior in 
 * particular, will interpret the number "1" as a signed int, which when
 * bit shifted as we do for capturing coverage data, into the 15th bit
 * position, will cause the sign bit to get sign extended into the 
 * the upper 16 bits, so instead of getting 0x00008000 when you perform 
 * (1<<15), you get 0xFFFF8000.
 */
#define VCAST_UNSIGNED_1 ((VCAST_MCDC_STORAGE_TYPE)1)

#if (VCAST_COVER_IO_SYSTEM_CODE == 1)
/* Include vcast_c_options.h for VCAST_CONDITION_TYP definition. */
#include "vcast_c_options.h"
#if (VCAST_COVER_IO_COVER_CODE == 0)
typedef int VECTORCAST_MARKER__C_COVER_H_START;
#endif /*VCAST_COVER_IO_COVER_CODE == 0*/
#include "c_cover.h"
#if (VCAST_COVER_IO_COVER_CODE == 0)
typedef int VECTORCAST_MARKER__C_COVER_H_END;
#endif /*VCAST_COVER_IO_COVER_CODE == 0*/

#ifdef VCAST_SIMULINK_OUTPUT
#include "target_io.h"
#endif /* VCAST_SIMULINK_OUTPUT */

#ifndef VCAST_UNIT_TEST_TOOL

/*Allow file operations*/
#ifndef VCAST_USE_STDIO_OPS
#define VCAST_USE_STDIO_OPS
#endif /* VCAST_USE_STDIO_OPS */

#endif /*VCAST_UNIT_TEST_TOOL*/

#ifdef VCAST_USE_BUFFERED_ASCII_DATA
/*Do not use file operations*/
#undef VCAST_USE_STDIO_OPS

extern char VCAST_ATTRIBUTE_CODE vcast_ascii_coverage_data_pool[];
int vcast_ascii_coverage_data_pos = 0;
int vcast_coverage_data_buffer_full = 0;
const char *VCAST_MAX_CAPTURED_ASCII_DATA_EXCEEDED_ERROR = "\nVCAST_MAX_CAPTURED_ASCII_DATA_EXCEEDED";
int vcast_max_captured_ascii_data_exceeded_error_size = 39;
void VCAST_WRITE_TO_BUFFER(const char *S);
#endif /* VCAST_USE_BUFFERED_ASCII_DATA */

#ifndef VCAST_UNIT_TEST_TOOL

#ifndef VCAST_USE_STATIC_MEMORY
/* In the unit test tool, this will use the VCAST_malloc
   already defined in the unit test harness. In the coverage
   tool, malloc is currently used. */
#define VCAST_malloc malloc
#define VCAST_free free
#endif /* VCAST_USE_STATIC_MEMORY */
#endif /* VCAST_UNIT_TEST_TOOL */

char *
vcast_strcat (char *VC_S, const char *VC_T)
{
   int vc_i,vc_j;
   vc_i = vc_j = 0;
   while ( VC_S[vc_i] != 0 )
      vc_i++;           /* find end of VC_S */
   while ( (VC_S[vc_i++] = VC_T[vc_j++]) != 0 ) ; /* copy VC_T */
   return VC_S;
}

int vcast_strlen(const char *VC_S);
int
vcast_strlen(const char *VC_S)
{
   int vc_result = 0;

   while(*VC_S) {
      vc_result++;
      VC_S++;
   }

   return vc_result;
}

char *
vcast_int_to_string (char *buf, VCAST_MCDC_STORAGE_TYPE vc_x)
{
   int vc_i;
   VCAST_MCDC_STORAGE_TYPE vc_cur = vc_x;
   int vc_size = 0;

   if (vc_x == 0) {
      buf[0] = '0';
      buf[1] = '\0';
      return buf;
   }

   while (vc_cur != 0) {
      vc_size++;
      vc_cur /= 10;
   }

   for (vc_i = 0; vc_x != 0; vc_i++){
      buf[vc_size-vc_i-1] = (char)((vc_x % 10) + '0');
      vc_x /= 10;
   }

   buf[vc_size] = 0;

   return buf;
}

#if defined(VCAST_DUMP_COVERAGE_AT_EXIT) || !defined(VCAST_USE_STATIC_MEMORY)
/* Contains atexit and malloc prototypes */
#include <stdlib.h>
#endif

#if defined(VCAST_APPEND_SECONDS_SINCE_EPOCH)
#include <time.h>
#endif

#ifndef VCAST_USE_GH_SYSCALL
#ifdef VCAST_USE_STDIO_OPS
#include <stdio.h>
#endif /* VCAST_USE_STDIO_OPS */
#endif /*VCAST_USE_GH_SYSCALL*/

#ifndef VCAST_USE_STDOUT
/* Normal case, uses a file for output */
#ifndef VCAST_UNIT_TEST_TOOL
#ifdef VCAST_USE_STDIO_OPS
#ifdef VCAST_SIMULINK_OUTPUT
unsigned short vCAST_SIMULINK_FILE_OPENED = 0;
#define VCAST_INST_FILE_TYPE unsigned short
#else
#define VCAST_INST_FILE_TYPE FILE*
#endif /* VCAST_SIMULINK_OUTPUT */
VCAST_INST_FILE_TYPE vCAST_INST_FILE = 0;
#endif /* VCAST_USE_STDIO_OPS */
#endif /* VCAST_UNIT_TEST_TOOL */
#endif /* VCAST_USE_STDOUT */

#ifdef VCAST_DUMP_COVERAGE_AT_EXIT
int vcast_has_registered_atexit = 0;
void vcast_register_atexit(void);
void vcast_register_atexit(void) {
   atexit(VCAST_DUMP_COVERAGE_DATA);
}
#endif /* VCAST_DUMP_COVERAGE_AT_EXIT */

#ifndef VCAST_UNIT_TEST_TOOL
#ifndef VCAST_USE_STDOUT
#ifdef VCAST_APPEND_WIN32_PID
#include <windows.h>
#elif defined VCAST_APPEND_POSIX_PID
#include <sys/types.h>
#include <unistd.h>
#endif /* end VCAST_APPEND_WIN32_PID */

void vCAST_CREATE_INST_FILE (void);
/**
 * function to open the file that will get all the coverage data 
 * written to it. 
 *
 * @param  void 
 * @return void
 */
void vCAST_CREATE_INST_FILE (void)
{
#ifdef VCAST_CUSTOM_FILE_OUTPUT
  /* Insert your code here using your API to create the TESTINSS.DAT */
  /* file.  For example: my_fopen("TESTINSS.DAT");  */
  
  /* Use the vCAST_CREATE_INST_FILE() code below after the #else */
  /* as a guideline for what your code should do, e.g. set       */
  /* the file pointer vCAST_INST_FILE accordingly, if it         */
  /* hasn't already been set, and open for writing ("w")         */
  /* or appending ("a"). Then you can remove the #error line.     */

  /* Also set the defined variable: VCAST_CUSTOM_FILE_OUTPUT */
  /* in the VectorCAST Tool Options Dialog -> C/C++ tab */

#error You need to insert code in vCAST_CREATE_INST_FILE() function

#else
#ifdef VCAST_SIMULINK_OUTPUT
  /* Output using MATLAN Simulink integration */
  char buf[100];
  char result_filename[32] = "TESTINSS.DAT";
  if (!vCAST_SIMULINK_FILE_OPENED) {
      vCAST_SIMULINK_FILE_OPENED = 1;
      vCAST_INST_FILE = targetFopen(result_filename);
  }
#else
  char result_filename[32] = "TESTINSS.DAT";
#ifdef VCAST_APPEND_WIN32_PID
  DWORD pid = GetCurrentProcessId();
  sprintf (result_filename,
           VCAST_PRINTF_STRING "-" VCAST_PRINTF_INTEGER "." VCAST_PRINTF_STRING,
           "TESTINSS",
           pid, 
           "DAT");
#elif defined VCAST_APPEND_POSIX_PID
   result_filename[0] = 0;
   vcast_strcat(result_filename, "TESTINSS-");
   vcast_int_to_string(result_filename+9, (int)getpid());
   vcast_strcat(result_filename, ".DAT");
#elif defined VCAST_APPEND_SECONDS_SINCE_EPOCH
   sprintf(result_filename,
           VCAST_PRINTF_STRING "-" VCAST_PRINTF_INTEGER "." VCAST_PRINTF_STRING,
           "TESTINSS",
           (int)time(0),
           "DAT");
#endif
#ifdef VCAST_USE_STDIO_OPS
   if (!vCAST_INST_FILE) {
#ifdef VCAST_APPEND_TO_TESTINSS
      vCAST_INST_FILE = fopen (result_filename, "a");
#else /* VCAST_APPEND_TO_TESTINSS */
      vCAST_INST_FILE = fopen (result_filename, "w");
#endif /* VCAST_APPEND_TO_TESTINSS */
   }
#endif /* VCAST_USE_STDIO_OPS */
#endif /* VCAST_SIMULINK_OUTPUT */
#endif /* VCAST_CUSTOM_FILE_OUTPUT */
}

void VCAST_CLOSE_FILE (void);
 /**
 * function to close the file that has all the coverage data 
 * written in it. default file name is TESTINSS.DAT 
 *
 * @param  void
 * @return void
 */
void VCAST_CLOSE_FILE (void)
{
#ifdef VCAST_CUSTOM_FILE_OUTPUT
  /* Insert code here using your API to close the TESTINSS.DAT */
  /* file.  For example: "my_fclose(vCAST_INST_FILE);  */
  
  /* Use the vCAST_CLOSE_FILE() code after the #else       */
  /* below as a guideline for what your function should do */
  /* Then you can remove the #error line.                  */

  /* Also set the defined variable: VCAST_CUSTOM_FILE_OUTPUT */
  /* in the VectorCAST Tool Options Dialog -> C/C++ tab */

#error You need to insert code in VCAST_CLOSE_FILE() function

#else
#ifdef VCAST_SIMULINK_OUTPUT
  /* File automatically closed by Simulink */
#else
#ifdef VCAST_USE_STDIO_OPS
   if (vCAST_INST_FILE > (FILE*)0 )
      fclose(vCAST_INST_FILE);
   vCAST_INST_FILE = (FILE*)0;
#endif /* VCAST_USE_STDIO_OPS */
#endif /* VCAST_SIMULINK_OUTPUT */
#endif /* VCAST_CUSTOM_FILE_OUTPUT */
}
#endif /* VCAST_USE_STDOUT */

#ifdef VCAST_CUSTOM_STD_OUTPUT_EXTERNAL
void VCAST_CUSTOM_STD_OUTPUT_EXTERNAL (const char *S, int flush);
#endif /* VCAST_CUSTOM_STD_OUTPUT_EXTERNAL */

#ifdef VCAST_USE_GH_SYSCALL

#ifdef __cplusplus
extern "C" int __ghs_syscall(int, ...);
#else /* __cplusplus */
extern int __ghs_syscall(int, ...);
#endif /* __cplusplus */

#endif /* end VCAST_USE_GH_SYS_CALL */

void VCAST_WRITE_TO_INST_FILE_COVERAGE (const char *S, int flush);

 /**
 * Original vcast_write_to_inst_file function.  Currently used by default 
 * when coverage optimizations are turned off. 
 *
 * @param const char S[] string with single line of coverage data 
 * @param int flush  flag to cause data flush for file i/o if flush != 0
 * @return void
 */
void VCAST_WRITE_TO_INST_FILE_COVERAGE (const char *S, int flush)
{
#ifdef VCAST_USE_BUFFERED_ASCII_DATA
  VCAST_WRITE_TO_BUFFER(S);
#else /* VCAST_USE_BUFFERED_ASCII_DATA */
#ifdef VCAST_CUSTOM_FILE_OUTPUT
  /* Insert your own call to an API to write "S" out of your target */
  /* Note that you should append a carriage return "/n" to the end */
  /*      of the "S" string before printing           */

  /* For example: see code snippet below ...          */

  /*    vCAST_CREATE_INST_FILE();                     */
  /*    my_fprintf ( vCAST_INST_FILE, "%s\n", S );    */
  /*    if (flush) {                                  */
  /*        my_fflush (vCAST_INST_FILE);              */
  /*    }                                             */

  /* Then you can remove the #error line below.       */

  /* Also set the defined variable: VCAST_CUSTOM_FILE_OUTPUT */
  /* in the VectorCAST Tool Options Dialog -> C/C++ tab */

#error Need to insert file i/o code in VCAST_WRITE_TO_INST_FILE_COVERAGE() 

#else
#ifdef VCAST_SIMULINK_OUTPUT
   vCAST_CREATE_INST_FILE();
   targetFprintf ( vCAST_INST_FILE, VCAST_PRINTF_STRING "\n", S );
#else
#ifdef VCAST_USE_STDIO_OPS
#ifdef VCAST_USE_STDOUT
#ifdef VCAST_USE_PUTCHAR

   int i, len;
   len = vcast_strlen( S );
   for( i=0; i<len; ++i ) {
      putchar( S[i] );
   }
   putchar( '\n' );

#else /* ndef VCAST_USE_PUTCHAR */
#ifdef VCAST_USE_GH_SYSCALL

   char Str[42];
   int  Len = vcast_strlen (S);
   Str[0] = 0;
   vcast_strcat (Str, S);
   vcast_strcat (Str, "\n");
   /* we hardcode stdout (1) as the file handle */
   __ghs_syscall(0x40001, 1, Str, Len+1);
     
#else /* ndef VCAST_USE_GH_SYSCALL */    
#ifdef VCAST_CUSTOM_STD_OUTPUT
  /* Insert user code here to write "S" out to serial port  */
  /* or STDOUT of your target,                              */
  /* then you can remove the #error line below.             */
  /* you will have to cut&paste this serial port data from  */
  /* the application receiving the data (e.g. HyperTerminal */
  /* and put into a file that can be imported into Cover    */
  /* environment   */

  /* Also set the defined variable: VCAST_CUSTOM_STD_OUTPUT */
  /* in the VectorCAST Tool Options Dialog -> C/C++ tab */

  /* Need to also define VCAST_USE_STDOUT to set the stdout flag */

#ifdef VCAST_CUSTOM_STD_OUTPUT_EXTERNAL
  VCAST_CUSTOM_STD_OUTPUT_EXTERNAL (S, flush);
#else  /* ndef VCAST_CUSTOM_STD_OUTPUT_EXTERNAL */
#ifdef VCAST_CUSTOM_STD_OUTPUT_INCLUDE
#include VCAST_CUSTOM_STD_OUTPUT_INCLUDE
#else /* ndef VCAST_CUSTOM_STD_OUTPUT_INCLUDE */
 #error Need to insert serial/std i/o code in VCAST_WRITE_TO_INST_FILE_COVERAGE()
#endif /* VCAST_CUSTOM_STD_OUTPUT_INCLUDE */
#endif /* end VCAST_CUSTOM_STD_OUTPUT_EXTERNAL */
#else
   puts( S );
#endif /* VCAST_CUSTOM_STD_OUTPUT */
     
#endif /* end VCAST_USE_GH_SYS_CALL */
#endif /* end VCAST_USE_PUTCHAR */

#else /* ndef VCAST_USE_STDOUT */

   vCAST_CREATE_INST_FILE();
   fprintf ( vCAST_INST_FILE, VCAST_PRINTF_STRING "\n", S );
   if (flush) {
     fflush (vCAST_INST_FILE);
   }
#ifdef VCAST_FLUSH_DATA
   else {
     fflush (vCAST_INST_FILE);
   }
#endif /* VCAST_FLUSH_DATA */
   
#endif /* end VCAST_USE_STDOUT */
#endif /* VCAST_USE_STDIO_OPS */
#endif /* VCAST_SIMULINK_OUTPUT */
#endif /* VCAST_CUSTOM_FILE_OUTPUT */
#endif /* VCAST_USE_BUFFERED_ASCII_DATA */
}
#endif /* end VCAST_UNIT_TEST_TOOL */

#endif /*VCAST_COVER_IO_SYSTEM_CODE*/

#if (VCAST_COVER_IO_COVER_CODE == 1)

/* Include vcast_c_options.h again, this time for the cover variables. */
#define VCAST_DEFINE_COVER_VARIABLES 1
#include "vcast_c_options.h"
#ifdef VCAST_USE_STATIC_MEMORY
#if defined (VCAST_COVERAGE_TYPE_MCDC) || defined(VCAST_COVERAGE_TYPE_STATEMENT_MCDC)

#ifdef VCAST_USE_STANDARD_MCDC_INSTRUMENTATION
struct vcast_mcdc_statement vcast_mcdc_statement_pool[VCAST_MAX_MCDC_STATEMENTS];
struct vcast_mcdc_statement *vcast_mcdc_statement_pool_ptr = vcast_mcdc_statement_pool;
struct vcast_mcdc_statement *vcast_mcdc_statement_end = vcast_mcdc_statement_pool + VCAST_MAX_MCDC_STATEMENTS;
#endif /* #ifdef VCAST_USE_STANDARD_MCDC_INSTRUMENTATION */

#endif /* defined (VCAST_COVERAGE_TYPE_MCDC) || defined(VCAST_COVERAGE_TYPE_STATEMENT_MCDC) */
#endif /* VCAST_USE_STATIC_MEMORY */

void vcast_fatal_error (const char *msg);

#if defined (VCAST_COVERAGE_TYPE_MCDC) || defined(VCAST_COVERAGE_TYPE_STATEMENT_MCDC)

#ifdef VCAST_USE_STANDARD_MCDC_INSTRUMENTATION
static int vcast_max_mcdc_statements_exceeded = 0;
struct vcast_mcdc_statement *vcast_get_mcdc_statement (void);
struct vcast_mcdc_statement *
vcast_get_mcdc_statement (void)
{
  struct vcast_mcdc_statement *ptr;
#ifdef VCAST_USE_STATIC_MEMORY
  if (vcast_mcdc_statement_pool_ptr < vcast_mcdc_statement_pool ||
      vcast_mcdc_statement_pool_ptr >= vcast_mcdc_statement_end)
  {
    if (vcast_max_mcdc_statements_exceeded == 0)
	   vcast_fatal_error ("VCAST_MAX_MCDC_STATEMENTS exceeded!");
    vcast_max_mcdc_statements_exceeded = 1;
    return 0;
  }
  ptr = vcast_mcdc_statement_pool_ptr++;
#else /* VCAST_USE_STATIC_MEMORY */
  ptr = (struct vcast_mcdc_statement*) 
    VCAST_malloc (sizeof (struct vcast_mcdc_statement));
#endif /* VCAST_USE_STATIC_MEMORY */

  return ptr;
}
#endif /* #ifdef VCAST_USE_STANDARD_MCDC_INSTRUMENTATION */

struct AVLNode
{
  VCAST_elementType element;
  AVLTree left;
  AVLTree right;
  int vcast_height;
};
#endif /* defined (VCAST_COVERAGE_TYPE_MCDC) || defined (VCAST_COVERAGE_TYPE_STATEMENT_MCDC) */

#ifdef VCAST_USE_STATIC_MEMORY
#if defined (VCAST_COVERAGE_TYPE_MCDC) || defined(VCAST_COVERAGE_TYPE_STATEMENT_MCDC)

#ifdef VCAST_USE_STANDARD_MCDC_INSTRUMENTATION
struct AVLNode vcast_avlnode_pool[VCAST_MAX_MCDC_STATEMENTS];
AVLTree vcast_avlnode_pool_ptr = vcast_avlnode_pool;
AVLTree vcast_avlnode_pool_end = vcast_avlnode_pool + VCAST_MAX_MCDC_STATEMENTS;
#endif /* #ifdef VCAST_USE_STANDARD_MCDC_INSTRUMENTATION */

#endif /* defined (VCAST_COVERAGE_TYPE_MCDC) || defined(VCAST_COVERAGE_TYPE_STATEMENT_MCDC) */
#endif /* VCAST_USE_STATIC_MEMORY */

#if defined (VCAST_COVERAGE_TYPE_MCDC) || defined(VCAST_COVERAGE_TYPE_STATEMENT_MCDC)

#ifdef VCAST_USE_STANDARD_MCDC_INSTRUMENTATION
AVLTree vcast_getAVLTree (void);
AVLTree
vcast_getAVLTree (void)
{
  AVLTree ptr;
#ifdef VCAST_USE_STATIC_MEMORY
  if (vcast_avlnode_pool_ptr < vcast_avlnode_pool || vcast_avlnode_pool_ptr >= vcast_avlnode_pool_end)
    return 0;
  ptr = vcast_avlnode_pool_ptr++;
#else /* VCAST_USE_STATIC_MEMORY */
  ptr = (struct AVLNode *)VCAST_malloc (sizeof (struct AVLNode));
#endif /* VCAST_USE_STATIC_MEMORY */

  return ptr;
}
#endif /* #ifdef VCAST_USE_STANDARD_MCDC_INSTRUMENTATION */

#endif /* defined (VCAST_COVERAGE_TYPE_MCDC) || defined (VCAST_COVERAGE_TYPE_STATEMENT_MCDC) */

#ifdef VCAST_USE_BUFFERED_ASCII_DATA
char VCAST_ATTRIBUTE_CODE vcast_ascii_coverage_data_pool[VCAST_MAX_CAPTURED_ASCII_DATA];

void VCAST_WRITE_TO_BUFFER(const char *S){
  if (!vcast_coverage_data_buffer_full) {
    int vc_size = vcast_strlen(S);
    if (vcast_ascii_coverage_data_pos + vc_size + 2 >= VCAST_MAX_CAPTURED_ASCII_DATA) {
       vcast_coverage_data_buffer_full = 1;
    } else {
       while (*S) {
         vcast_ascii_coverage_data_pool[vcast_ascii_coverage_data_pos++] = *S;
         ++S;
       }
    }

    /* if not enough room in the buffer for all the coverage data */
    if (vcast_coverage_data_buffer_full) {
      const char *vcast_cur = VCAST_MAX_CAPTURED_ASCII_DATA_EXCEEDED_ERROR;
      vcast_ascii_coverage_data_pos -= (vcast_max_captured_ascii_data_exceeded_error_size+2);
      for (; *vcast_cur; ++vcast_cur) {
        vcast_ascii_coverage_data_pool[vcast_ascii_coverage_data_pos++] = *vcast_cur;
      }
    }

    vcast_ascii_coverage_data_pool[vcast_ascii_coverage_data_pos++] = '\n';
    vcast_ascii_coverage_data_pool[vcast_ascii_coverage_data_pos] = '\0';
  }
}
#endif /* VCAST_USE_BUFFERED_ASCII_DATA */

#if defined VCAST_UNIT_TEST_TOOL
#define VCAST_WRITE_COVERAGE_DATA(string) { vCAST_CREATE_INST_FILE(); vectorcast_fprint_string_with_cr(vCAST_INST_FILE, string); }
#define VCAST_WRITE_COVERAGE_DATA_FLUSH(string) { vCAST_CREATE_INST_FILE(); vectorcast_fprint_string_with_cr(vCAST_INST_FILE, string); }
#else /* VCAST_UNIT_TEST_TOOL */
#define VCAST_WRITE_COVERAGE_DATA(string) (VCAST_WRITE_TO_INST_FILE_COVERAGE(string, 0))
#define VCAST_WRITE_COVERAGE_DATA_FLUSH(string) (VCAST_WRITE_TO_INST_FILE_COVERAGE(string, 1))
#endif /* VCAST_UNIT_TEST_TOOL */

/* The instrumentation code depends on this data, usually found in S2.c in a
 * test harness.  For standalone coverage, they need to be supplied here: */
#ifndef LONG_MAX
#define LONG_MAX 2147483647L
#endif /* LONG_MAX */

/*
   VCAST_UNIQUE_ID_BUF_SIZE        : The number of characters needed to print
                                     a unique id. The default is 6, which 
                                     supports 99,999 ids in a single unit.
   VCAST_UNIT_ID_BUF_SIZE          : The number of characters needed to print
                                     a unit id. The default is 5, which 
                                     supports 9,999 units in a project.
*/

/* The following defines will control the sizes of intermediate character 
 * strings that VectorCAST uses to output coverage data. Keeping these 
 * values close to the sizes needed results in less memory being used 
 * on the stack, during test execution.
 */
#define VCAST_UNIQUE_ID_BUF_SIZE 6
#define VCAST_UNIT_ID_BUF_SIZE 5

/* The user can never go above the maximum of the supported 64 bit 
   limit, which is 18446744073709551615. */
#if defined(VCAST_UNSIGNED_LONG_MCDC_STORAGE) || !defined(VCAST_HAS_LONGLONG)
#define VCAST_MCDC_ID_BUF_SIZE 11
#else
#define VCAST_MCDC_ID_BUF_SIZE 21
#endif

/* The amount of space needed to write a line of function call data is,
 * The size of the unit id, plus two spaces and a 'F' character, plus
 * the size of the unique id, plus the NUL character.
 */
#define VCAST_FN_CALL_DATA_BUF_SIZE 14

/* The amount of space needed to write a line of statement data is,
 * The size of the unit id, plus a space, plus the size of the 
 * unique id, plus the NUL character.
 */
#define VCAST_STATEMENT_DATA_BUF_SIZE 12

/* The branch data is the same as the statement data, except it has an
 * extra space, and then an extra character or two (T, F, TX, or FX) at
 * the end.
 */
#define VCAST_BRANCH_DATA_BUF_SIZE 15

/* The mcdc data is the same as the statement data, except that
 * it has an extra space, plus a mcdc bits number, plus a space,
 * plus an mcdc bits used number.
 */
#if defined(VCAST_UNSIGNED_LONG_MCDC_STORAGE) || !defined(VCAST_HAS_LONGLONG)
#define VCAST_MCDC_DATA_BUF_SIZE 36
#else
#define VCAST_MCDC_DATA_BUF_SIZE 56
#endif

int
VCAST_WRITE_FN_CALL_ID(short unit, int id)
{
   char vcast_out_str[VCAST_FN_CALL_DATA_BUF_SIZE];
   char id_buf[VCAST_UNIQUE_ID_BUF_SIZE];
   vcast_int_to_string(vcast_out_str, unit);
   vcast_int_to_string(id_buf, id);
   vcast_strcat(vcast_out_str, " ");
   vcast_strcat(vcast_out_str, id_buf);
   vcast_strcat(vcast_out_str, " C");
   VCAST_WRITE_COVERAGE_DATA(vcast_out_str);
   return 1;
}

#if defined(VCAST_COVERAGE_TYPE_STATEMENT) || defined (VCAST_COVERAGE_TYPE_STATEMENT_BRANCH )|| defined (VCAST_COVERAGE_TYPE_STATEMENT_MCDC)
int VCAST_WRITE_STATEMENT_ID(short unit, int id)
{
   char vcast_out_str[VCAST_STATEMENT_DATA_BUF_SIZE];
   char id_buf[VCAST_UNIQUE_ID_BUF_SIZE];
   vcast_int_to_string(vcast_out_str, unit);
   vcast_int_to_string(id_buf, id);
   vcast_strcat(vcast_out_str, " ");
   vcast_strcat(vcast_out_str, id_buf);
   VCAST_WRITE_COVERAGE_DATA(vcast_out_str);
   return 1;
}
#endif

#if defined(VCAST_COVERAGE_TYPE_BRANCH) || defined (VCAST_COVERAGE_TYPE_STATEMENT_BRANCH)
int VCAST_WRITE_BRANCH_ID(short unit, int id, const char *TorF)
{
   char vcast_out_str[VCAST_BRANCH_DATA_BUF_SIZE];
   char id_buf[VCAST_UNIQUE_ID_BUF_SIZE];
   vcast_int_to_string(vcast_out_str, unit);
   vcast_int_to_string(id_buf, id);
   vcast_strcat(vcast_out_str, " ");
   vcast_strcat(vcast_out_str, id_buf);
   vcast_strcat (vcast_out_str, " ");
   vcast_strcat (vcast_out_str, TorF);
   VCAST_WRITE_COVERAGE_DATA(vcast_out_str);
   return 1;
}
#endif

#if defined(VCAST_COVERAGE_TYPE_MCDC) || defined (VCAST_COVERAGE_TYPE_STATEMENT_MCDC)

#if defined(VCAST_USE_STANDARD_MCDC_INSTRUMENTATION) || defined(VCAST_COVERAGE_IO_ANIMATION)
int VCAST_WRITE_MCDC_ID(short unit, int id,
                        VCAST_MCDC_STORAGE_TYPE mcdc_bits, 
                        VCAST_MCDC_STORAGE_TYPE mcdc_bits_used);
int VCAST_WRITE_MCDC_ID(short unit, int id,
                        VCAST_MCDC_STORAGE_TYPE mcdc_bits, 
                        VCAST_MCDC_STORAGE_TYPE mcdc_bits_used)
{
   char vcast_out_str[VCAST_MCDC_DATA_BUF_SIZE];
   char id_buf[VCAST_UNIQUE_ID_BUF_SIZE]; 
   char mcdc_bits_buf[VCAST_MCDC_ID_BUF_SIZE]; 
   char mcdc_bits_used_buf[VCAST_MCDC_ID_BUF_SIZE];
   vcast_int_to_string (vcast_out_str, unit);
   vcast_int_to_string (id_buf, id);
#ifdef VCAST_USE_OPTIMIZED_MCDC_INSTRUMENTATION
   vcast_strcat (vcast_out_str, "V");
#else
   vcast_strcat (vcast_out_str, " ");
#endif
   vcast_strcat (vcast_out_str, id_buf);
   vcast_int_to_string (mcdc_bits_buf, mcdc_bits);
   vcast_strcat (vcast_out_str, " ");
   vcast_strcat (vcast_out_str, mcdc_bits_buf);
   vcast_int_to_string (mcdc_bits_used_buf, mcdc_bits_used);
   vcast_strcat (vcast_out_str, " ");
   vcast_strcat (vcast_out_str, mcdc_bits_used_buf);
   VCAST_WRITE_COVERAGE_DATA (vcast_out_str);
   return 1;
}
#endif /* #if defined(VCAST_USE_STANDARD_MCDC_INSTRUMENTATION) || defined(VCAST_COVERAGE_IO_ANIMATION) */

int VCAST_WRITE_OPTIMIZED_MCDC_ID(short unit, int id, char num_conditions,
                                  VCAST_MCDC_STORAGE_TYPE mcdc_bits, 
                                  VCAST_MCDC_STORAGE_TYPE mcdc_bits_used)
{
   char vcast_out_str[VCAST_MCDC_DATA_BUF_SIZE + 1];
   char id_buf[VCAST_UNIQUE_ID_BUF_SIZE]; 
   char num_cond_buf[2];
   char mcdc_bits_buf[VCAST_MCDC_ID_BUF_SIZE]; 
   char mcdc_bits_used_buf[VCAST_MCDC_ID_BUF_SIZE];
   vcast_int_to_string (vcast_out_str, unit);
   vcast_int_to_string (id_buf, id);
   num_cond_buf[0] = num_conditions;
   num_cond_buf[1] = '\0';
   vcast_strcat (vcast_out_str, num_cond_buf);
   vcast_strcat (vcast_out_str, id_buf);
   vcast_int_to_string (mcdc_bits_buf, mcdc_bits);
   vcast_strcat (vcast_out_str, " ");
   vcast_strcat (vcast_out_str, mcdc_bits_buf);
   vcast_int_to_string (mcdc_bits_used_buf, mcdc_bits_used);
   vcast_strcat (vcast_out_str, " ");
   vcast_strcat (vcast_out_str, mcdc_bits_used_buf);
   VCAST_WRITE_COVERAGE_DATA (vcast_out_str);
   return 1;
}
#endif /*mcdc*/

void
vcast_fatal_error (const char *msg)
{
  VCAST_WRITE_COVERAGE_DATA_FLUSH (msg);
}

#if defined (VCAST_COVERAGE_TYPE_MCDC) || defined(VCAST_COVERAGE_TYPE_STATEMENT_MCDC)

#ifdef VCAST_USE_STANDARD_MCDC_INSTRUMENTATION
int vcast_mcdc_statement_compare (struct vcast_mcdc_statement *ptr1,
                                  struct vcast_mcdc_statement *ptr2);
int
vcast_mcdc_statement_compare (struct vcast_mcdc_statement *ptr1,
                        struct vcast_mcdc_statement *ptr2)
{
  if (ptr1->mcdc_bits == ptr2->mcdc_bits)
  {
    if (ptr1->mcdc_bits_used == ptr2->mcdc_bits_used)
      return 0;
    else if (ptr1->mcdc_bits_used < ptr2->mcdc_bits_used)
      return -1;
    else
      return 1;
  } else if (ptr1->mcdc_bits < ptr2->mcdc_bits)
    return -1;
  else
    return 1;
}
#endif /* #ifdef VCAST_USE_STANDARD_MCDC_INSTRUMENTATION */

#endif /* defined (VCAST_COVERAGE_TYPE_MCDC) || defined(VCAST_COVERAGE_TYPE_STATEMENT_MCDC) */

#if defined (VCAST_COVERAGE_TYPE_MCDC) || defined (VCAST_COVERAGE_TYPE_STATEMENT_MCDC)
VCAST_CONDITION_TYP
VCAST_SAVE_MCDC_SUBCONDITION (struct vcast_mcdc_statement *mcdc_statement,
                              int bit_index, VCAST_CONDITION_TYP condition)
{
   /* This is a sub-condition for an MCDC expression, just record the bit */
  if (condition)
    mcdc_statement->mcdc_bits |= (VCAST_UNSIGNED_1 << bit_index);

  mcdc_statement->mcdc_bits_used |= (VCAST_UNSIGNED_1 << bit_index);

  return condition;
}
#endif /* defined (VCAST_COVERAGE_TYPE_MCDC) || defined (VCAST_COVERAGE_TYPE_STATEMENT_MCDC) */

#ifdef VCAST_COVERAGE_TYPE_STATEMENT_MCDC
VCAST_CONDITION_TYP
VCAST_SAVE_MCDC_STATEMENT_MCDC_SUBCONDITION ( 
                              struct vcast_mcdc_statement *mcdc_statement,
                              int bit_index, VCAST_CONDITION_TYP condition);
VCAST_CONDITION_TYP
VCAST_SAVE_MCDC_STATEMENT_MCDC_SUBCONDITION ( 
                              struct vcast_mcdc_statement *mcdc_statement,
                              int bit_index, VCAST_CONDITION_TYP condition)
{
   /* This is a sub-condition for an MCDC expression, just record the bit */
  if (condition)
    mcdc_statement->mcdc_bits |= (VCAST_UNSIGNED_1 << bit_index);

  mcdc_statement->mcdc_bits_used |= (VCAST_UNSIGNED_1 << bit_index);

  return condition;
}

#endif /* VCAST_COVERAGE_TYPE_STATEMENT_MCDC */

#ifdef VCAST_COVERAGE_IO_REAL_TIME
#if defined (VCAST_COVERAGE_TYPE_MCDC) || defined (VCAST_COVERAGE_TYPE_STATEMENT_MCDC)

#ifdef VCAST_USE_STANDARD_MCDC_INSTRUMENTATION
VCAST_CONDITION_TYP 
VCAST_MCDC_CONDITION_INSTRUMENTATION_POINT_REALTIME(AVLTree *vcast_mcdc_array,
                                                    struct vcast_mcdc_statement *mcdc_statement,
                                                    int unit, int id,
                                                    VCAST_CONDITION_TYP condition)
{
   /* Store the total expression */
   if (condition)
     mcdc_statement->mcdc_bits |= 1;
   mcdc_statement->mcdc_bits_used |= 1;

   /* Get the coverage data necessary */
   if (!vcast_find (mcdc_statement, vcast_mcdc_array[id]))
   {
      struct vcast_mcdc_statement *vcast_mcdc_statement = vcast_get_mcdc_statement();
      if (!vcast_mcdc_statement)
        return condition;
      *vcast_mcdc_statement = *mcdc_statement;

      vcast_mcdc_array[id] = 
         vcast_insert (vcast_mcdc_statement, vcast_mcdc_array[id]);

      VCAST_WRITE_MCDC_ID (unit, id,
            mcdc_statement->mcdc_bits,
            mcdc_statement->mcdc_bits_used);
   }

   mcdc_statement->mcdc_bits = 0;
   mcdc_statement->mcdc_bits_used = 0;

   return condition;
}
#endif /* #ifdef VCAST_USE_STANDARD_MCDC_INSTRUMENTATION */

#ifdef VCAST_USE_OPTIMIZED_MCDC_INSTRUMENTATION
#ifndef VCAST_COVERAGE_POINTS_AS_MACROS
VCAST_CONDITION_TYP 
VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_REALTIME_0(char* covdata,
                                                                int unit, int id,
                                                                VCAST_CONDITION_TYP condition)
{
   return condition ?
      (((covdata[id >> 2] & ((1 << ((id << 1) % 8)) | (1 << (((id << 1) + 1) % 8)))) == 0) ?
       (covdata[id >> 2] |= ((1 << ((id << 1) % 8)) | (1 << (((id << 1) + 1) % 8))),
        VCAST_WRITE_OPTIMIZED_MCDC_ID(unit, id, 'a', 1, 1), 1) : 1)
      :
      (((covdata[id >> 2] & ((1 << ((id << 1) % 8)) | (0 << (((id << 1) + 1) % 8)))) == 0) ?
       (covdata[id >> 2] |= ((1 << ((id << 1) % 8)) | (0 << (((id << 1) + 1) % 8))),
        VCAST_WRITE_OPTIMIZED_MCDC_ID(unit, id, 'a', 0, 1), 0) : 0);
}
#endif /* #ifndef VCAST_COVERAGE_POINTS_AS_MACROS */

VCAST_CONDITION_TYP 
VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_REALTIME_1(char* covdata,
                                                                struct vcast_mcdc_statement *mcdc_statement,
                                                                int unit, int id,
                                                                VCAST_CONDITION_TYP condition)
{
   int bits_needed = 4;
   int bit_offset = id * bits_needed;
   int cond_result_start = bit_offset + 2;
   int actual_result = 0;
   int cond_val = 0;

   /* Store the total expression */
   if (condition)
     mcdc_statement->mcdc_bits |= 1;
   mcdc_statement->mcdc_bits_used |= 1;

   actual_result = mcdc_statement->mcdc_bits & 1;
   cond_val = mcdc_statement->mcdc_bits >> 1;

   if (! (covdata[(bit_offset + cond_val) >> 3] & (1 << ((bit_offset + cond_val) % 8))))
   {
     covdata[(bit_offset + cond_val) >> 3] |= (1 << ((bit_offset + cond_val) % 8));
     covdata[(cond_result_start + cond_val) >> 3] |= (actual_result << ((cond_result_start + cond_val) % 8));

     VCAST_WRITE_OPTIMIZED_MCDC_ID (unit, id, 'b',
                               mcdc_statement->mcdc_bits,
                               mcdc_statement->mcdc_bits_used);
   }

   mcdc_statement->mcdc_bits = 0;
   mcdc_statement->mcdc_bits_used = 0;

   return condition;
}

VCAST_CONDITION_TYP 
VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_REALTIME(char* covdata,
                                                              struct vcast_mcdc_statement *mcdc_statement,
                                                              int unit, int id, int num_conditions,
                                                              VCAST_CONDITION_TYP condition)
{
   int bits_needed = (1 << num_conditions) * (num_conditions + 1);
   int bit_offset = 0;
   int cond_result_start = 0;
   int used_start = 0;
   int actual_result = 0;
   int cond_val = 0;
   int used_val = 0;
   int i;

   if (bits_needed == 1)
     bits_needed = 2;

   bit_offset = id * bits_needed;
   cond_result_start = bit_offset + (1 << num_conditions);

   if (bits_needed == 2)
     --cond_result_start;

   used_start = bit_offset + (1 << (num_conditions + 1));

   /* Store the total expression */
   if (condition)
     mcdc_statement->mcdc_bits |= 1;
   mcdc_statement->mcdc_bits_used |= 1;

   actual_result = mcdc_statement->mcdc_bits & 1;
   cond_val = mcdc_statement->mcdc_bits >> 1;
   used_val = mcdc_statement->mcdc_bits_used >> 2;

   if (! (covdata[(bit_offset + cond_val) >> 3] & (1 << ((bit_offset + cond_val) % 8))))
   {
     covdata[(bit_offset + cond_val) >> 3] |= (1 << ((bit_offset + cond_val) % 8));
     covdata[(cond_result_start + cond_val) >> 3] |= (actual_result << ((cond_result_start + cond_val) % 8));

     for (i = 0; i < num_conditions - 1; ++i)
       covdata[(used_start + cond_val + i * (1 << num_conditions)) >> 3] |= (((1 & (used_val >> i))) << ((used_start + cond_val + i * (1 << num_conditions)) % 8));

     VCAST_WRITE_OPTIMIZED_MCDC_ID (unit, id, (char)(num_conditions + 97),
                                    mcdc_statement->mcdc_bits,
                                    mcdc_statement->mcdc_bits_used);
   }

   mcdc_statement->mcdc_bits = 0;
   mcdc_statement->mcdc_bits_used = 0;

   return condition;
}
#endif /* VCAST_USE_OPTIMIZED_MCDC_INSTRUMENTATION */
#endif /* VCAST_COVERAGE_IO_REAL_TIME */
#endif /* defined (VCAST_COVERAGE_TYPE_MCDC) || defined (VCAST_COVERAGE_TYPE_STATEMENT_MCDC) */


/***************************** Functions for MCDC Coverage **************************************** */
/***************************** Functions for MCDC Coverage **************************************** */

#if defined(VCAST_COVERAGE_IO_ANIMATION)
#if defined (VCAST_COVERAGE_TYPE_MCDC) || defined (VCAST_COVERAGE_TYPE_STATEMENT_MCDC)
VCAST_CONDITION_TYP 
VCAST_MCDC_CONDITION_INSTRUMENTATION_POINT_ANIMATION(
                             struct vcast_mcdc_statement *mcdc_statement,
                             int unit_index,
                             int id, VCAST_CONDITION_TYP condition)
{
   /* Store the total expression */
   if (condition)
     mcdc_statement->mcdc_bits |= 1;
   mcdc_statement->mcdc_bits_used |= 1;

   VCAST_WRITE_MCDC_ID (unit_index, id, mcdc_statement->mcdc_bits,
                        mcdc_statement->mcdc_bits_used);

   mcdc_statement->mcdc_bits = 0;
   mcdc_statement->mcdc_bits_used = 0;

   return condition;
}

#ifdef VCAST_USE_OPTIMIZED_MCDC_INSTRUMENTATION
VCAST_CONDITION_TYP 
VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_ANIMATION(struct vcast_mcdc_statement *mcdc_statement,
                                                               int unit, int id,
                                                               int num_conditions,
                                                               VCAST_CONDITION_TYP condition)
{
   /* Store the total expression */
   if (condition)
     mcdc_statement->mcdc_bits |= 1;
   mcdc_statement->mcdc_bits_used |= 1;

   VCAST_WRITE_OPTIMIZED_MCDC_ID (unit, id, (char)(num_conditions + 97),
                             mcdc_statement->mcdc_bits,
                             mcdc_statement->mcdc_bits_used);

   mcdc_statement->mcdc_bits = 0;
   mcdc_statement->mcdc_bits_used = 0;

   return condition;
}
#endif /* VCAST_USE_OPTIMIZED_MCDC_INSTRUMENTATION */

#endif /* defined (VCAST_COVERAGE_TYPE_MCDC) || defined (VCAST_COVERAGE_TYPE_STATEMENT_MCDC) */
#endif /* VCAST_COVERAGE_IO_ANIMATION */

#if defined (VCAST_COVERAGE_IO_BUFFERED)
#if defined (VCAST_COVERAGE_TYPE_MCDC) || defined (VCAST_COVERAGE_TYPE_STATEMENT_MCDC)

#ifdef VCAST_USE_STANDARD_MCDC_INSTRUMENTATION
VCAST_CONDITION_TYP 
VCAST_MCDC_CONDITION_INSTRUMENTATION_POINT_BUFFERED(AVLTree *vcast_mcdc_array,
                                                    struct vcast_mcdc_statement *mcdc_statement,
                                                    int unit, int id,
                                                    VCAST_CONDITION_TYP condition)
{
   /* Store the total expression */
   if (condition)
     mcdc_statement->mcdc_bits |= 1;
   mcdc_statement->mcdc_bits_used |= 1;

   /* Get the coverage data necessary */
   if (!vcast_find (mcdc_statement, vcast_mcdc_array[id]))
   {
      struct vcast_mcdc_statement *vcast_mcdc_statement = vcast_get_mcdc_statement();
      if (!vcast_mcdc_statement)
        return condition;
      *vcast_mcdc_statement = *mcdc_statement;

      vcast_mcdc_array[id] = 
         vcast_insert (vcast_mcdc_statement, vcast_mcdc_array[id]);
   }

   mcdc_statement->mcdc_bits = 0;
   mcdc_statement->mcdc_bits_used = 0;

   return condition;
}
#endif /* #ifdef VCAST_USE_STANDARD_MCDC_INSTRUMENTATION */

#ifdef VCAST_USE_OPTIMIZED_MCDC_INSTRUMENTATION
#ifndef VCAST_COVERAGE_POINTS_AS_MACROS
VCAST_CONDITION_TYP 
VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_BUFFERED_0(char* covdata,
                                                                int unit, int id,
                                                                VCAST_CONDITION_TYP condition)
{
   return condition ?
      (covdata[id >> 2] |= ((1 << ((id << 1) % 8)) | (1 << (((id << 1) + 1) % 8))), 1)
      :
      (covdata[id >> 2] |= ((1 << ((id << 1) % 8)) | (0 << (((id << 1) + 1) % 8))), 0);
}
#endif /* #ifndef VCAST_COVERAGE_POINTS_AS_MACROS */

VCAST_CONDITION_TYP 
VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_BUFFERED_1(char* covdata,
                                                                struct vcast_mcdc_statement *mcdc_statement,
                                                                int unit, int id,
                                                                VCAST_CONDITION_TYP condition)
{
   int bits_needed = 4;
   int bit_offset = id * bits_needed;
   int cond_result_start = bit_offset + 2;
   int actual_result = 0;
   int cond_val = 0;

   /* Store the total expression */
   if (condition)
     mcdc_statement->mcdc_bits |= 1;
   mcdc_statement->mcdc_bits_used |= 1;

   actual_result = mcdc_statement->mcdc_bits & 1;
   cond_val = mcdc_statement->mcdc_bits >> 1;

   covdata[(bit_offset + cond_val) >> 3] |= (1 << ((bit_offset + cond_val) % 8));
   covdata[(cond_result_start + cond_val) >> 3] |= (actual_result << ((cond_result_start + cond_val) % 8));

   mcdc_statement->mcdc_bits = 0;
   mcdc_statement->mcdc_bits_used = 0;

   return condition;
}

VCAST_CONDITION_TYP 
VCAST_OPTIMIZED_MCDC_CONDITION_INSTRUMENTATION_POINT_BUFFERED(char* covdata,
                                                              struct vcast_mcdc_statement *mcdc_statement,
                                                              int unit, int id,
                                                              int num_conditions,
                                                              VCAST_CONDITION_TYP condition)
{
   int bits_needed = (1 << num_conditions) * (num_conditions + 1);
   int bit_offset = 0;
   int cond_result_start = 0;
   int used_start = 0;
   int actual_result = 0;
   int cond_val = 0;
   int used_val = 0;
   int i;

   /* Store the total expression */
   if (condition)
     mcdc_statement->mcdc_bits |= 1;
   mcdc_statement->mcdc_bits_used |= 1;

   if (bits_needed == 1)
     bits_needed = 2;
   bit_offset = id * bits_needed;

   cond_result_start = bit_offset + (1 << num_conditions);
   if (bits_needed == 2)
     --cond_result_start;
   used_start = bit_offset + (1 << (num_conditions + 1));
   actual_result = mcdc_statement->mcdc_bits & 1;

   cond_val = mcdc_statement->mcdc_bits >> 1;
   used_val = mcdc_statement->mcdc_bits_used >> 2;

   covdata[(bit_offset + cond_val) >> 3] |= (1 << ((bit_offset + cond_val) % 8));
   covdata[(cond_result_start + cond_val) >> 3] |= (actual_result << ((cond_result_start + cond_val) % 8));

   for (i = 0; i < num_conditions - 1; ++i)
     covdata[(used_start + cond_val + i * (1 << num_conditions)) >> 3] |= (((1 & (used_val >> i))) << ((used_start + cond_val + i * (1 << num_conditions)) % 8));

   mcdc_statement->mcdc_bits = 0;
   mcdc_statement->mcdc_bits_used = 0;

   return condition;
}
#endif /* VCAST_USE_OPTIMIZED_MCDC_INSTRUMENTATION */
#endif /* defined (VCAST_COVERAGE_TYPE_MCDC) || defined (VCAST_COVERAGE_TYPE_STATEMENT_MCDC) */
#endif /* VCAST_COVERAGE_IO_BUFFERED */

#if defined (VCAST_COVERAGE_TYPE_MCDC) || defined(VCAST_COVERAGE_TYPE_STATEMENT_MCDC)

#ifdef VCAST_USE_STANDARD_MCDC_INSTRUMENTATION
#ifdef VCAST_USE_STATIC_MEMORY
AVLTree VCAST_ATTRIBUTE_CODE vcast_avltree_data_pool[VCAST_NUMBER_AVLTREE_POINTERS];
#endif

int vcast_find_val;
VCAST_position
vcast_find (VCAST_elementType VCAST_X, AVLTree VCAST_T)
{
  if (VCAST_T == 0)
    return 0;
  vcast_find_val = vcast_mcdc_statement_compare (VCAST_X, VCAST_T->element);
  if (vcast_find_val < 0)
    return vcast_find (VCAST_X, VCAST_T->left);
  else if (vcast_find_val > 0)
    return vcast_find (VCAST_X, VCAST_T->right);
  else
    return VCAST_T;
}

static int
vcast_height (VCAST_position P)
{
  if (P == 0)
    return -1;
  else
    return P->vcast_height;
}

static int
vcast_avl_max (int Lhs, int Rhs)
{
  return Lhs > Rhs ? Lhs : Rhs;
}

	/* This function can be called only if K2 has a left child */
	/* Perform a rotate between a node (K2) and its left child */
	/* Update heights, then return new root */

static VCAST_position
vcast_singleRotateWithLeft (VCAST_position K2)
{
  VCAST_position K1;

  K1 = K2->left;
  K2->left = K1->right;
  K1->right = K2;

  K2->vcast_height = vcast_avl_max (vcast_height (K2->left), vcast_height (K2->right)) + 1;
  K1->vcast_height = vcast_avl_max (vcast_height (K1->left), K2->vcast_height) + 1;

  return K1;			/* New root */
}

	/* This function can be called only if K1 has a right child */
	/* Perform a rotate between a node (K1) and its right child */
	/* Update heights, then return new root */

static VCAST_position
vcast_singleRotateWithRight (VCAST_position K1)
{
  VCAST_position K2;

  K2 = K1->right;
  K1->right = K2->left;
  K2->left = K1;

  K1->vcast_height = vcast_avl_max (vcast_height (K1->left), vcast_height (K1->right)) + 1;
  K2->vcast_height = vcast_avl_max (vcast_height (K2->right), K1->vcast_height) + 1;

  return K2;			/* New root */
}

	/* This function can be called only if K3 has a left */
	/* child and K3's left child has a right child */
	/* Do the left-right double rotation */
	/* Update heights, then return new root */

static VCAST_position
vcast_doubleRotateWithLeft (VCAST_position K3)
{
  /* Rotate between K1 and K2 */
  K3->left = vcast_singleRotateWithRight (K3->left);

  /* Rotate between K3 and K2 */
  return vcast_singleRotateWithLeft (K3);
}

	/* This function can be called only if K1 has a right */
	/* child and K1's right child has a left child */
	/* Do the right-left double rotation */
	/* Update heights, then return new root */

static VCAST_position
vcast_doubleRotateWithRight (VCAST_position K1)
{
  /* Rotate between K3 and K2 */
  K1->right = vcast_singleRotateWithLeft (K1->right);

  /* Rotate between K1 and K2 */
  return vcast_singleRotateWithRight (K1);
}

int vcast_insert_val;
AVLTree
vcast_insert (VCAST_elementType VCAST_X, AVLTree VCAST_T)
{
  if (VCAST_T == 0)
    {
      /* Create and return a one-node tree */
      VCAST_T = vcast_getAVLTree ();
      if (VCAST_T == 0)
      {
        if (vcast_max_mcdc_statements_exceeded == 0)
	  vcast_fatal_error ("VCAST_MAX_MCDC_STATEMENTS exceeded!");
        vcast_max_mcdc_statements_exceeded = 1;
      }
      else
	{
	  VCAST_T->element = VCAST_X;
	  VCAST_T->vcast_height = 0;
	  VCAST_T->left = VCAST_T->right = 0;
	}
    }
  else if ((vcast_insert_val = vcast_mcdc_statement_compare (VCAST_X, VCAST_T->element)) < 0)
    {
      VCAST_T->left = vcast_insert (VCAST_X, VCAST_T->left);
      if (vcast_height (VCAST_T->left) - vcast_height (VCAST_T->right) == 2)
	{
	  if (vcast_mcdc_statement_compare (VCAST_X, VCAST_T->left->element) < 0)
	    VCAST_T = vcast_singleRotateWithLeft (VCAST_T);
	  else
	    VCAST_T = vcast_doubleRotateWithLeft (VCAST_T);
	}
    }
  else if (vcast_insert_val > 0)
    {
      VCAST_T->right = vcast_insert (VCAST_X, VCAST_T->right);
      if (vcast_height (VCAST_T->right) - vcast_height (VCAST_T->left) == 2)
	{
	  if (vcast_mcdc_statement_compare (VCAST_X, VCAST_T->right->element) > 0)
	    VCAST_T = vcast_singleRotateWithRight (VCAST_T);
	  else
	    VCAST_T = vcast_doubleRotateWithRight (VCAST_T);
	}
    }
  /* Else X is in the tree already; we'll do nothing */

  VCAST_T->vcast_height = vcast_avl_max (vcast_height (VCAST_T->left), vcast_height (VCAST_T->right)) + 1;
  return VCAST_T;
}
#endif /* #ifdef VCAST_USE_STANDARD_MCDC_INSTRUMENTATION */

#endif /* defined (VCAST_COVERAGE_TYPE_MCDC) || defined(VCAST_COVERAGE_TYPE_STATEMENT_MCDC) */

void VCAST_REGISTER_DUMP_AT_EXIT (void)
{
#ifdef VCAST_DUMP_COVERAGE_AT_EXIT
  if (vcast_has_registered_atexit == 0) {
     vcast_register_atexit();
     vcast_has_registered_atexit = 1;
   }
#endif  /* VCAST_DUMP_COVERAGE_AT_EXIT */
}

#if defined (VCAST_COVERAGE_TYPE_MCDC) || defined (VCAST_COVERAGE_TYPE_STATEMENT_MCDC)

#ifdef VCAST_USE_STANDARD_MCDC_INSTRUMENTATION
void VCAST_DUMP_MCDC_COVERAGE_ID (int unit, int unique_id, AVLTree tree);
void
VCAST_DUMP_MCDC_COVERAGE_ID (int unit, int unique_id, AVLTree tree)
{
  /* Walk the tree, and output the data */
  if (tree)
  {
    VCAST_DUMP_MCDC_COVERAGE_ID (unit, unique_id, tree->left);
    VCAST_WRITE_MCDC_ID (unit, unique_id,
                         tree->element->mcdc_bits,
                         tree->element->mcdc_bits_used);
    VCAST_DUMP_MCDC_COVERAGE_ID (unit, unique_id, tree->right);
  }
}
#endif /* #ifdef VCAST_USE_STANDARD_MCDC_INSTRUMENTATION */

#endif /* defined (VCAST_COVERAGE_TYPE_MCDC) || defined (VCAST_COVERAGE_TYPE_STATEMENT_MCDC) */

#if defined(VCAST_COVERAGE_TYPE_STATEMENT) || defined(VCAST_COVERAGE_TYPE_STATEMENT_BRANCH) || defined(VCAST_COVERAGE_TYPE_STATEMENT_MCDC)
void VCAST_DUMP_STATEMENT_COVERAGE_DATA_ID(int vcast_unit,
                                           char *vcast_statement_array,
                                           int vcast_statement_bytes);
void VCAST_DUMP_STATEMENT_COVERAGE_DATA_ID(int vcast_unit,
                                           char *vcast_statement_array,
                                           int vcast_statement_bytes)
{
  int vcast_cur_byte;
  int vcast_cur_bit;

  /* For each byte */
  for (vcast_cur_byte = 0; vcast_cur_byte < vcast_statement_bytes; ++vcast_cur_byte) {
    int vcast_byte = vcast_statement_array[vcast_cur_byte];
    /* For each bit in the byte */
    for (vcast_cur_bit = 0; vcast_cur_bit < 8; ++vcast_cur_bit) {
      if (vcast_byte & (1 << vcast_cur_bit)) {
        VCAST_WRITE_STATEMENT_ID(vcast_unit, vcast_cur_byte*8 + vcast_cur_bit);
      }
    }
  }
}
#endif

#ifdef VCAST_ENABLE_FUNCTION_CALL_COVERAGE
void VCAST_DUMP_FN_CALL_COVERAGE_DATA_ID(int vcast_unit,
                                         char *vcast_fn_call_array,
                                         int vcast_fn_call_bytes);
void VCAST_DUMP_FN_CALL_COVERAGE_DATA_ID(int vcast_unit,
                                         char *vcast_fn_call_array,
                                         int vcast_fn_call_bytes)
{
  int vcast_cur_byte;
  int vcast_cur_bit;

  /* For each byte */
  for (vcast_cur_byte = 0; vcast_cur_byte < vcast_fn_call_bytes; ++vcast_cur_byte) {
    int vcast_byte = vcast_fn_call_array[vcast_cur_byte];
    /* For each bit in the byte */
    for (vcast_cur_bit = 0; vcast_cur_bit < 8; ++vcast_cur_bit) {
      if (vcast_byte & (1 << vcast_cur_bit)) {
        VCAST_WRITE_FN_CALL_ID(vcast_unit, vcast_cur_byte*8 + vcast_cur_bit);
      }
    }
  }
}
#endif

#if defined(VCAST_COVERAGE_TYPE_BRANCH) || defined(VCAST_COVERAGE_TYPE_STATEMENT_BRANCH)
void VCAST_DUMP_BRANCH_COVERAGE_DATA_ID(int vcast_unit,
                                        char *vcast_branch_array,
                                        int vcast_branch_bytes);

void VCAST_DUMP_BRANCH_COVERAGE_DATA_ID(int vcast_unit,
                                        char *vcast_branch_array,
                                        int vcast_branch_bytes)
{
  int vcast_cur_byte;
  int vcast_cur_bit;

  /* For each byte */
  for (vcast_cur_byte = 0; vcast_cur_byte < vcast_branch_bytes; ++vcast_cur_byte) {
    int vcast_byte = vcast_branch_array[vcast_cur_byte];
    /* For each bit in the byte */
    for (vcast_cur_bit = 0; vcast_cur_bit < 8; ++vcast_cur_bit) {
      if (vcast_byte & (1 << vcast_cur_bit)) {
        VCAST_WRITE_BRANCH_ID(vcast_unit, vcast_cur_byte*4 + (vcast_cur_bit >> 1),
                              ((vcast_cur_bit % 2 == 0) ? "T" : "F"));
      }
    }
  }
}
#endif

#if defined(VCAST_COVERAGE_TYPE_MCDC) || defined(VCAST_COVERAGE_TYPE_STATEMENT_MCDC)

#ifdef VCAST_USE_STANDARD_MCDC_INSTRUMENTATION
void VCAST_DUMP_MCDC_COVERAGE_DATA_ID(int vcast_unit,
                                      AVLTree *vcast_mcdc_array,
                                      int vcast_mcdc_statement_count);
void VCAST_DUMP_MCDC_COVERAGE_DATA_ID(int vcast_unit,
                                      AVLTree *vcast_mcdc_array,
                                      int vcast_mcdc_statement_count)
{
  int unique_id;
  for (unique_id = 0; unique_id < vcast_mcdc_statement_count; ++unique_id)
  {
    if (vcast_mcdc_array[unique_id])
    {
      VCAST_DUMP_MCDC_COVERAGE_ID(vcast_unit, unique_id,
                                  vcast_mcdc_array[unique_id]);
    }
  }
}
#endif /* #ifdef VCAST_USE_STANDARD_MCDC_INSTRUMENTATION */

#ifdef VCAST_USE_OPTIMIZED_MCDC_INSTRUMENTATION
void VCAST_DUMP_OPTIMIZED_MCDC_COVERAGE_DATA_ID(int vcast_unit,
                                                char *vcast_optimized_mcdc_array,
                                                int vcast_optimized_mcdc_bytes,
                                                int num_conditions);
void VCAST_DUMP_OPTIMIZED_MCDC_COVERAGE_DATA_ID(int vcast_unit,
                                                char *vcast_optimized_mcdc_array,
                                                int vcast_optimized_mcdc_bytes,
                                                int num_conditions)
{
  int id;
  int bit_offset = 0;
  int bits_needed = (1 << num_conditions) * (num_conditions + 1);
  if (bits_needed == 1)
    bits_needed = 2;

  for (id = 0; id < vcast_optimized_mcdc_bytes; ++id)
  {
    int cond_result_start = bit_offset + (1 << num_conditions);
    int used_start = bit_offset + (1 << (num_conditions + 1));
    int cond_val;
    int used_val;
    int actual_result;

    for (cond_val = 0; cond_val < (1 << num_conditions); ++cond_val)
    {
      if (vcast_optimized_mcdc_array[(bit_offset + cond_val) >> 3] & (1 << ((bit_offset + cond_val) % 8)))
      {
        int i;
        actual_result = (vcast_optimized_mcdc_array[(cond_result_start + cond_val) >> 3] & (1 << ((cond_result_start + cond_val) % 8))) >> ((cond_result_start + cond_val) % 8);
        used_val = (1 << (num_conditions > 0 ? 1 : 0)) | 1;
        for (i = 0; i < num_conditions - 1; ++i)
          used_val |= ((vcast_optimized_mcdc_array[(used_start + cond_val + i * (1 << num_conditions)) >> 3] & (1 << ((used_start + cond_val + i * (1 << num_conditions)) % 8))) >> (((used_start + cond_val + i * (1 << num_conditions)) % 8))) << (2 + i);

        VCAST_WRITE_OPTIMIZED_MCDC_ID (vcast_unit, id, (char)(num_conditions + 97),
                                       (cond_val << 1) | actual_result,
                                       used_val);
      }
    }

    bit_offset += bits_needed;
  }
}
#endif /* VCAST_USE_OPTIMIZED_MCDC_INSTRUMENTATION */
#endif

void VCAST_DUMP_COVERAGE_DATA_ID(void);

void
VCAST_DUMP_COVERAGE_DATA_ID(void)
{
#if defined(VCAST_COVERAGE_IO_BUFFERED)
  const struct vcast_unit_list *vcast_unit_cur;
  /* For the entire unit */
  for (vcast_unit_cur = vcast_unit_list_values; vcast_unit_cur->vcast_unit; vcast_unit_cur++) {
    int vcast_unit = vcast_unit_cur->vcast_unit;

#if defined(VCAST_COVERAGE_TYPE_STATEMENT) || defined(VCAST_COVERAGE_TYPE_STATEMENT_BRANCH) || defined(VCAST_COVERAGE_TYPE_STATEMENT_MCDC)
    VCAST_DUMP_STATEMENT_COVERAGE_DATA_ID(vcast_unit, vcast_unit_cur->vcast_statement_array,
                                          vcast_unit_cur->vcast_statement_bytes);
#if defined(VCAST_ENABLE_FUNCTION_CALL_COVERAGE)
    VCAST_DUMP_FN_CALL_COVERAGE_DATA_ID(vcast_unit, vcast_unit_cur->vcast_fn_call_array,
                                        vcast_unit_cur->vcast_fn_call_bytes);
#endif
#endif
#if defined(VCAST_COVERAGE_TYPE_BRANCH) || defined(VCAST_COVERAGE_TYPE_STATEMENT_BRANCH)
    VCAST_DUMP_BRANCH_COVERAGE_DATA_ID(vcast_unit, vcast_unit_cur->vcast_branch_array,
                                       vcast_unit_cur->vcast_branch_bytes);
#endif
#if defined(VCAST_COVERAGE_TYPE_MCDC) || defined(VCAST_COVERAGE_TYPE_STATEMENT_MCDC)
#ifdef VCAST_USE_STANDARD_MCDC_INSTRUMENTATION
    VCAST_DUMP_MCDC_COVERAGE_DATA_ID(vcast_unit, vcast_unit_cur->vcast_mcdc_array,
                                     vcast_unit_cur->vcast_mcdc_statement_count);
#endif /* #ifdef VCAST_USE_STANDARD_MCDC_INSTRUMENTATION */

#ifdef VCAST_USE_OPTIMIZED_MCDC_INSTRUMENTATION
#if VCAST_OPTIMIZED_MCDC_STORAGE_THRESHOLD >= 0
    VCAST_DUMP_OPTIMIZED_MCDC_COVERAGE_DATA_ID(vcast_unit, vcast_unit_cur->vcast_optimized_mcdc_array_0,
                                               vcast_unit_cur->vcast_optimized_mcdc_bytes_0, 0);
#endif
#if VCAST_OPTIMIZED_MCDC_STORAGE_THRESHOLD >= 1
    VCAST_DUMP_OPTIMIZED_MCDC_COVERAGE_DATA_ID(vcast_unit, vcast_unit_cur->vcast_optimized_mcdc_array_1,
                                               vcast_unit_cur->vcast_optimized_mcdc_bytes_1, 1);
#endif
#if VCAST_OPTIMIZED_MCDC_STORAGE_THRESHOLD >= 2
    VCAST_DUMP_OPTIMIZED_MCDC_COVERAGE_DATA_ID(vcast_unit, vcast_unit_cur->vcast_optimized_mcdc_array_2,
                                               vcast_unit_cur->vcast_optimized_mcdc_bytes_2, 2);
#endif
#if VCAST_OPTIMIZED_MCDC_STORAGE_THRESHOLD >= 3
    VCAST_DUMP_OPTIMIZED_MCDC_COVERAGE_DATA_ID(vcast_unit, vcast_unit_cur->vcast_optimized_mcdc_array_3,
                                               vcast_unit_cur->vcast_optimized_mcdc_bytes_3, 3);
#endif
#if VCAST_OPTIMIZED_MCDC_STORAGE_THRESHOLD >= 4
    VCAST_DUMP_OPTIMIZED_MCDC_COVERAGE_DATA_ID(vcast_unit, vcast_unit_cur->vcast_optimized_mcdc_array_4,
                                               vcast_unit_cur->vcast_optimized_mcdc_bytes_4, 4);
#endif
#if VCAST_OPTIMIZED_MCDC_STORAGE_THRESHOLD >= 5
    VCAST_DUMP_OPTIMIZED_MCDC_COVERAGE_DATA_ID(vcast_unit, vcast_unit_cur->vcast_optimized_mcdc_array_5,
                                               vcast_unit_cur->vcast_optimized_mcdc_bytes_5, 5);
#endif
#if VCAST_OPTIMIZED_MCDC_STORAGE_THRESHOLD >= 6
    VCAST_DUMP_OPTIMIZED_MCDC_COVERAGE_DATA_ID(vcast_unit, vcast_unit_cur->vcast_optimized_mcdc_array_6,
                                               vcast_unit_cur->vcast_optimized_mcdc_bytes_6, 6);
#endif
#if VCAST_OPTIMIZED_MCDC_STORAGE_THRESHOLD >= 7
    VCAST_DUMP_OPTIMIZED_MCDC_COVERAGE_DATA_ID(vcast_unit, vcast_unit_cur->vcast_optimized_mcdc_array_7,
                                               vcast_unit_cur->vcast_optimized_mcdc_bytes_7, 7);
#endif
#if VCAST_OPTIMIZED_MCDC_STORAGE_THRESHOLD >= 8
    VCAST_DUMP_OPTIMIZED_MCDC_COVERAGE_DATA_ID(vcast_unit, vcast_unit_cur->vcast_optimized_mcdc_array_8,
                                               vcast_unit_cur->vcast_optimized_mcdc_bytes_8, 8);
#endif
#endif
#endif
  }
#endif /* VCAST_COVERAGE_IO_BUFFERED */
}

void 
VCAST_DUMP_COVERAGE_DATA (void)
{
#if defined(VCAST_COVERAGE_IO_BUFFERED)
  VCAST_DUMP_COVERAGE_DATA_ID();
#ifdef VCAST_DUMP_CALLBACK
  VCAST_DUMP_CALLBACK ();
#endif /* VCAST_DUMP_CALLBACK */
#ifndef VCAST_UNIT_TEST_TOOL
#ifndef VCAST_USE_STDOUT
  VCAST_CLOSE_FILE();
#endif
#endif
#endif /* VCAST_COVERAGE_IO_BUFFERED */
}

#if defined (VCAST_ENABLE_DATA_CLEAR_API)
static void VCAST_CLEAR_BUFFER(char* buffer, unsigned int size )
{
  unsigned int i = 0;
    for (; i < size; ++i)
        buffer[i] = 0;
}

#ifdef VCAST_USE_STANDARD_MCDC_INSTRUMENTATION
#ifndef VCAST_USE_STATIC_MEMORY
static void vcast_freeAVLTree( AVLTree root )
{
  if( root )
  {
    vcast_freeAVLTree(root->left);
    vcast_freeAVLTree(root->right);
    VCAST_free(root->element);
    VCAST_free(root);
  }
}
#endif
#endif

void VCAST_CLEAR_COVERAGE_DATA_ID(void);

void
VCAST_CLEAR_COVERAGE_DATA_ID(void)
{
#if defined(VCAST_COVERAGE_IO_BUFFERED)
  const struct vcast_unit_list *vcast_unit_cur;
  /* For the entire unit */
  for (vcast_unit_cur = vcast_unit_list_values; vcast_unit_cur->vcast_unit; vcast_unit_cur++) {
#if defined(VCAST_COVERAGE_TYPE_STATEMENT) || defined(VCAST_COVERAGE_TYPE_STATEMENT_BRANCH) || defined(VCAST_COVERAGE_TYPE_STATEMENT_MCDC)
    VCAST_CLEAR_BUFFER ( vcast_unit_cur->vcast_statement_array,  vcast_unit_cur->vcast_statement_bytes );
#if defined(VCAST_ENABLE_FUNCTION_CALL_COVERAGE)
    VCAST_CLEAR_BUFFER( vcast_unit_cur->vcast_fn_call_array, vcast_unit_cur->vcast_fn_call_bytes);
#endif
#endif
#if defined(VCAST_COVERAGE_TYPE_BRANCH) || defined(VCAST_COVERAGE_TYPE_STATEMENT_BRANCH)
    VCAST_CLEAR_BUFFER ( vcast_unit_cur->vcast_branch_array, vcast_unit_cur->vcast_branch_bytes );
#endif
#if defined (VCAST_COVERAGE_TYPE_MCDC) || defined(VCAST_COVERAGE_TYPE_STATEMENT_MCDC)
#ifdef VCAST_USE_STANDARD_MCDC_INSTRUMENTATION
#ifndef VCAST_USE_STATIC_MEMORY
    {
      int unique_id;
      for (unique_id = 0; unique_id < vcast_unit_cur->vcast_mcdc_statement_count; ++unique_id)
      {
        vcast_freeAVLTree(vcast_unit_cur->vcast_mcdc_array[unique_id]);
      }
    }
#endif
    VCAST_CLEAR_BUFFER ( (char*)vcast_unit_cur->vcast_mcdc_array, vcast_unit_cur->vcast_mcdc_statement_count * sizeof(AVLTree) );
#endif /* #ifdef VCAST_USE_STANDARD_MCDC_INSTRUMENTATION */
#ifdef VCAST_USE_OPTIMIZED_MCDC_INSTRUMENTATION
#if VCAST_OPTIMIZED_MCDC_STORAGE_THRESHOLD >= 0
    VCAST_CLEAR_BUFFER ( vcast_unit_cur->vcast_optimized_mcdc_array_0, VCAST_OPTIMIZED_MCDC_BYTES_0_SIZE(vcast_unit_cur->vcast_optimized_mcdc_bytes_0) );
#endif
#if VCAST_OPTIMIZED_MCDC_STORAGE_THRESHOLD >= 1
    VCAST_CLEAR_BUFFER ( vcast_unit_cur->vcast_optimized_mcdc_array_1, VCAST_OPTIMIZED_MCDC_BYTES_1_SIZE(vcast_unit_cur->vcast_optimized_mcdc_bytes_1) );
#endif
#if VCAST_OPTIMIZED_MCDC_STORAGE_THRESHOLD >= 2
    VCAST_CLEAR_BUFFER ( vcast_unit_cur->vcast_optimized_mcdc_array_2, VCAST_OPTIMIZED_MCDC_BYTES_2_SIZE(vcast_unit_cur->vcast_optimized_mcdc_bytes_2) );
#endif
#if VCAST_OPTIMIZED_MCDC_STORAGE_THRESHOLD >= 3
    VCAST_CLEAR_BUFFER ( vcast_unit_cur->vcast_optimized_mcdc_array_3, VCAST_OPTIMIZED_MCDC_BYTES_3_SIZE(vcast_unit_cur->vcast_optimized_mcdc_bytes_3) );
#endif
#if VCAST_OPTIMIZED_MCDC_STORAGE_THRESHOLD >= 4
    VCAST_CLEAR_BUFFER ( vcast_unit_cur->vcast_optimized_mcdc_array_4, VCAST_OPTIMIZED_MCDC_BYTES_4_SIZE(vcast_unit_cur->vcast_optimized_mcdc_bytes_4) );
#endif
#if VCAST_OPTIMIZED_MCDC_STORAGE_THRESHOLD >= 5
    VCAST_CLEAR_BUFFER ( vcast_unit_cur->vcast_optimized_mcdc_array_5, VCAST_OPTIMIZED_MCDC_BYTES_5_SIZE(vcast_unit_cur->vcast_optimized_mcdc_bytes_5) );
#endif
#if VCAST_OPTIMIZED_MCDC_STORAGE_THRESHOLD >= 6
    VCAST_CLEAR_BUFFER ( vcast_unit_cur->vcast_optimized_mcdc_array_6, VCAST_OPTIMIZED_MCDC_BYTES_6_SIZE(vcast_unit_cur->vcast_optimized_mcdc_bytes_6) );
#endif
#if VCAST_OPTIMIZED_MCDC_STORAGE_THRESHOLD >= 7
    VCAST_CLEAR_BUFFER ( vcast_unit_cur->vcast_optimized_mcdc_array_7, VCAST_OPTIMIZED_MCDC_BYTES_7_SIZE(vcast_unit_cur->vcast_optimized_mcdc_bytes_7) );
#endif
#if VCAST_OPTIMIZED_MCDC_STORAGE_THRESHOLD >= 8
    VCAST_CLEAR_BUFFER ( vcast_unit_cur->vcast_optimized_mcdc_array_8, VCAST_OPTIMIZED_MCDC_BYTES_8_SIZE(vcast_unit_cur->vcast_optimized_mcdc_bytes_8) );
#endif
#endif /* VCAST_USE_OPTIMIZED_MCDC_INSTRUMENTATION */
#endif /* if defined (VCAST_COVERAGE_TYPE_MCDC) || defined(VCAST_COVERAGE_TYPE_STATEMENT_MCDC) */
  }
#endif /* VCAST_COVERAGE_IO_BUFFERED */
}

void 
VCAST_CLEAR_COVERAGE_DATA(void)
{
#if defined(VCAST_COVERAGE_IO_BUFFERED)
  VCAST_CLEAR_COVERAGE_DATA_ID();
#endif /* VCAST_COVERAGE_IO_BUFFERED */

#ifdef VCAST_USE_BUFFERED_ASCII_DATA
  vcast_ascii_coverage_data_pool[0] = 0;
  vcast_ascii_coverage_data_pos = 0;
  vcast_coverage_data_buffer_full = 0;
#endif

#ifndef VCAST_UNIT_TEST_TOOL
#ifndef VCAST_USE_STDOUT
  VCAST_CLOSE_FILE();
#endif
#endif

#if defined (VCAST_COVERAGE_TYPE_MCDC) || defined(VCAST_COVERAGE_TYPE_STATEMENT_MCDC)
#ifdef VCAST_USE_STANDARD_MCDC_INSTRUMENTATION
#ifdef VCAST_USE_STATIC_MEMORY
   vcast_mcdc_statement_pool_ptr = vcast_mcdc_statement_pool;
   vcast_avlnode_pool_ptr = vcast_avlnode_pool;
#endif /* VCAST_USE_STATIC_MEMORY */
   vcast_max_mcdc_statements_exceeded = 0;
#endif /* VCAST_USE_STANDARD_MCDC_INSTRUMENTATION */
#endif
}
#endif /* VCAST_ENABLE_DATA_CLEAR_API */


#ifndef VCAST_COVERAGE_POINTS_AS_MACROS

int VCAST_FN_CALL_INSTRUMENTATION_POINT_REALTIME(char* covdata, int unit, int id)
{
  return ((covdata[id >> 3] & (((unsigned long)1) << id % 8)) == 0) ?
    (covdata[id >> 3] |= (((unsigned long)1) << id % 8), 
     VCAST_WRITE_FN_CALL_ID(unit, id)) : 1;
} 

int VCAST_FN_CALL_INSTRUMENTATION_POINT_BUFFERED(char* covdata, int unit, int id)
{
  return covdata[id >> 3] |= (((unsigned long)1) << (id % 8));
}

int VCAST_FN_CALL_INSTRUMENTATION_POINT_ANIMATION(int unit, int id)
{
  return VCAST_WRITE_FN_CALL_ID(unit, id);
}

/***************************** Functions for Statement Coverage **************************************** */

#if defined(VCAST_COVERAGE_TYPE_STATEMENT) || defined (VCAST_COVERAGE_TYPE_STATEMENT_BRANCH) || defined (VCAST_COVERAGE_TYPE_STATEMENT_MCDC)


#if defined(VCAST_COVERAGE_IO_ANIMATION)
int VCAST_STATEMENT_INSTRUMENTATION_POINT_ANIMATION(int unit, int id)
{
  return VCAST_WRITE_STATEMENT_ID(unit, id);
}

#elif defined (VCAST_COVERAGE_IO_BUFFERED)
int VCAST_STATEMENT_INSTRUMENTATION_POINT_BUFFERED(char* covdata, int unit, int id)
{
  return covdata[id >> 3] |= (((unsigned long)1) << (id % 8));
}

#else
int VCAST_STATEMENT_INSTRUMENTATION_POINT_REALTIME(char* covdata, int unit, int id)
{
  return ((covdata[id >> 3] & (((unsigned long)1) << id % 8)) == 0) ?
    (covdata[id >> 3] |= (((unsigned long)1) << id % 8), 
     VCAST_WRITE_STATEMENT_ID(unit, id)) : 1;
} 

#endif /*type of COVERAGE_IO*/
#endif /*statement instrumentation*/


/***************************** Functions for Branch Coverage **************************************** */
/***************************** Functions for Branch Coverage **************************************** */
#if defined(VCAST_COVERAGE_TYPE_BRANCH) || defined (VCAST_COVERAGE_TYPE_STATEMENT_BRANCH)
#if defined(VCAST_COVERAGE_IO_ANIMATION)
int VCAST_BRANCH_INSTRUMENTATION_POINT_ANIMATION(int unit, int id, VCAST_CONDITION_TYP condition, int onPath)
{
  return condition ? 
    (VCAST_WRITE_BRANCH_ID(unit, id, onPath ? "T" : "TX"), 1) 
    : 
    (VCAST_WRITE_BRANCH_ID(unit, id, onPath ? "F" : "FX"), 0); 
}


#elif defined (VCAST_COVERAGE_IO_BUFFERED)
int VCAST_BRANCH_INSTRUMENTATION_POINT_BUFFERED(char* covdata, int unit, int id, VCAST_CONDITION_TYP condition)
{
  return condition ? 
    (covdata[id >> 2] |= (((unsigned long)1) << (id % 4 << 1)), 1) 
    : 
    (covdata[id >> 2] |= (((unsigned long)1) << ((id % 4 << 1) + 1)), 0); 
}

#else
int VCAST_BRANCH_INSTRUMENTATION_POINT_REALTIME(char* covdata, int unit, int id, VCAST_CONDITION_TYP condition)
{
  return condition ? 
    (((covdata[id >> 2] & (((unsigned long)1) << (id % 4 << 1))) == 0) ? 
     (covdata[id >> 2] |= (((unsigned long)1) << (id % 4 << 1)), 
      VCAST_WRITE_BRANCH_ID(unit, id, "T"), 1) : 1) 
    : 
    (((covdata[id >> 2] & (((unsigned long)1) << ((id % 4 << 1) + 1))) == 0) ? 
     (covdata[id >> 2] |= (((unsigned long)1) << ((id % 4 << 1) + 1)), 
      VCAST_WRITE_BRANCH_ID(unit, id, "F"), 0) : 0); 
}

#endif /*type of COVERAGE_IO*/
#endif /* Branch */
#endif /* VCAST_COVERAGE_POINTS_AS_MACROS */

#ifdef VCAST_PROBE_PRINT_AVAILABLE

/** This function copies string VC_T to string VC_S */
void vectorcast_strcpy ( char *VC_S, const char *VC_T )
{
   int vcast_i = 0;
   while ( (VC_S[vcast_i] = VC_T[vcast_i]) != 0 )
      vcast_i++;
}

VCAST_LONGEST_INT vcast_abs ( VCAST_LONGEST_INT vcNum )
{
   if ( vcNum < 0 )
      return 0 - vcNum;
   else
      return vcNum;
}
#define VCAST_DECIMAL_DIGIT(u) ('0'+u)
void vectorcast_signed_to_string ( char vcDest[],
                                   VCAST_LONGEST_INT vcSrc )
{
   char vcBackwards[32];
   unsigned vcCount = 0;
   unsigned vcFirst;
   unsigned vcI;
   VCAST_LONGEST_INT vcValue = vcSrc;
   VCAST_LONGEST_INT vcRem;

   if ( vcSrc < 0 ) {
      vcDest[0] = '-';
      vcFirst = 1;
   } else {
      vcFirst = 0;
   }

   vcCount = 0;
   while ( vcValue >= 10 || vcValue <= -10 ) {
      /* we use absolute value here because we can't use
         it on the original number if the original number -MaxInt */
      vcRem = vcast_abs ( vcValue % 10 );
      vcBackwards[vcCount++] = VCAST_DECIMAL_DIGIT(vcRem);
      vcValue = vcValue / 10;
   }
   vcValue = vcast_abs ( vcValue );

   vcBackwards[vcCount] = VCAST_DECIMAL_DIGIT(vcValue);
   /* vcI already initialized (based on sign) */
   for ( vcI=0; vcI<=vcCount; vcI++ )
      vcDest[vcFirst+vcI] = vcBackwards[vcCount-vcI];
   vcDest[vcFirst+vcI] = 0;
}

#if defined(VCAST_PROBE_POINTS_AVAILABLE) || defined(VCAST_UNIT_TEST_TOOL)

#if !defined(VCAST_UNIT_TEST_TOOL) || defined(VCAST_FP) || defined(VCAST_NO_SPRINTF)

/* ifndef VCAST_NO_FLOAT */
#ifndef VCAST_NO_FLOAT

#define VCAST_FLOAT_ZERO  0.0
#define VCAST_FLOAT_ONE   1.0
#define VCAST_FLOAT_TWO   2.0
#define VCAST_FLOAT_TEN  10.0

#define vCAST_false 0
#define vCAST_true 1

#define ASCII_CONVERSION 48
#define MAX_DIGITS 32
#define MAX_PRECISION 17
#define DEFAULT_PRECISION 6

int VCAST_special_compare ( char *vcDouble1, char *vcDouble2, int vcLen )
{
   int vcI;
   for (vcI=0; vcI<vcLen; vcI++) {
      if ( vcDouble1[vcI] != vcDouble2[vcI] )
         return vCAST_false;
   }
   return vCAST_true;
}

/* ------------------------------------------------------------------------------- */
void vectorcast_float_to_string( char *mixed_str, vCAST_long_double vcast_f ) {

   char whole_str[MAX_DIGITS]; /* string representation of whole portion */
   char frac_str[MAX_DIGITS];  /* string representation of fractional portion */
   char temp_str[MAX_DIGITS];  /* temp variable for string manipulation */

   vCAST_long_double f_abs;  /* the absolute value of vcast_f */
   VCAST_UNSIGNED_CONVERSION_TYPE whole;        /* int value of whole portion */
   vCAST_long_double frac;                /* double value of fractional portion */
   VCAST_UNSIGNED_CONVERSION_TYPE upper;
   int new_dig,      /* as digits get popped off, they're held here */
       float_precision=-1, /* desired precision of final result */
       sig_digs=0,   /* counter to keep track of how precise the number is */
       sign,         /* the sign of vcast_f */
       exp=0,        /* the exponent of vcast_f */
       i=0,          /* string index counter */
       last,         /* the last digit in the precision */
       last_in_frac, /* flag - does last reside in frac or whole? */
       key,          /* the next digit after last (investigate for rounding) */
       round,        /* flag - round or not? */
       cur_pos;      /* rounding index counter */

   /* handle special-case numbers */
   static int vcDoubleSize = 0;
   static vCAST_long_double vcZERO;
   static vCAST_long_double vcNAN;
   static vCAST_long_double vcNINF;
   static vCAST_long_double vcPINF;
   if ( vcDoubleSize == 0 ) {
      vcDoubleSize = sizeof ( vCAST_long_double );
      vcZERO = VCAST_FLOAT_ZERO;
      vcNAN  = VCAST_FLOAT_ZERO/vcZERO;
      vcNINF = (-VCAST_FLOAT_ONE)/vcZERO;
      vcPINF = VCAST_FLOAT_ONE/vcZERO;
   }

   if ( VCAST_special_compare ( (char *)&vcast_f, (char *)&vcNAN, vcDoubleSize ) ) {
      vectorcast_strcpy ( mixed_str, "NaN" );
      return;
   }

   if ( VCAST_special_compare ( (char *)&vcast_f, (char *)&vcNINF, vcDoubleSize ) ) {
      vectorcast_strcpy ( mixed_str, "-INF" );
      return;
   }

   if ( VCAST_special_compare ( (char *)&vcast_f, (char *)&vcPINF, vcDoubleSize ) ) {
      vectorcast_strcpy ( mixed_str, "+INF" );
      return;
   }

/* --- calculate float precision --- */

#ifdef VCAST_UNIT_TEST_TOOL
   /* assumes VCAST_FLOAT_FORMAT in form "%lg" or "%.xlg" or "%.xxlg" */
   if( VCAST_FLOAT_FORMAT[1] != '.' ) {
      float_precision = DEFAULT_PRECISION;
   } else {
      last = VCAST_FLOAT_FORMAT[2] - ASCII_CONVERSION;
      if( VCAST_FLOAT_FORMAT[3] == 'l' ) {
         float_precision = last;
      } else {
         key = VCAST_FLOAT_FORMAT[3] - ASCII_CONVERSION;
         float_precision = last*10 + key;
      }
   }

   if( float_precision < 0 || float_precision > MAX_PRECISION ) {
      float_precision=DEFAULT_PRECISION;
   } else if( float_precision == 0 ) {
      float_precision=1;
   }
#else
   float_precision = DEFAULT_PRECISION;
#endif

/* --- determine sign of vcast_f --- */

   if( vcast_f == 0.0 ) {
      /* vcast_f is zero */
      vectorcast_strcpy( mixed_str, "0" );
      return;

   } else if( vcast_f > 0.0 ) {
      sign = 1;   /* vcast_f is positive */

   } else {
      sign = -1;  /* vcast_f is negative */
   }

   f_abs = vcast_f*sign;

   if( f_abs < 0 ) { /* out of range - infinity */
      vectorcast_strcpy( mixed_str, "Inf" );
      return;
   }


/* --- determine exponent value --- */

   /* calculate pow(10, float_precision) without including math.h */
   for( i=1, upper=10; i<float_precision; i++ ) {
      upper*=10;
   }
   upper-=1;

   /* to switch to exp notation: 4 leading zeros or f > (10^precision-1) */
   if( f_abs < .00009999999999999 || f_abs > upper ) {
      if( f_abs < 1.0 ) { /* negative exponent */
         while( f_abs < 1.0 ) {
            exp--;
            f_abs*=10.0;      /* introduces loss of precision */
         }

      } else {          /* positive exponent */
         while( f_abs > 10.0 ) {
            exp++;
            f_abs/=10.0;      /* introduces loss of precision */
         }
      }
   } /* else, don't use exponential notation */


/* --- trim digits off while building whole_str, frac_str and mixed_str --- */

   whole = (VCAST_UNSIGNED_CONVERSION_TYPE)f_abs;
   vcast_int_to_string ( whole_str, whole );
   if( whole > 0 ) {
      sig_digs = vcast_strlen(whole_str);
   }

   frac = f_abs - (float)whole;

   /* build frac_str (grab an extra digit for rounding information) */
   i=0;
   while( sig_digs < float_precision+1 ) {
      frac*=10.0;             /* introduces loss of precision */
      new_dig = (int)(frac);
      frac_str[i++] = new_dig+ASCII_CONVERSION;
      frac-=(float)new_dig;

      if( sig_digs > 0 || new_dig > 0 ) {
         sig_digs++;
      }

   }
   frac_str[i] = 0;


/* --- calculate and perform rounding (if necessary) --- */

   /* check for rounding */
   if( i < 2 ) {  /* last dig is in whole_str */
      last_in_frac = 0;
      cur_pos = vcast_strlen(whole_str)-1;
      last = whole_str[cur_pos]-ASCII_CONVERSION;
   } else {       /* last dig is in frac_str */
      last_in_frac = 1;
      cur_pos = i-2;
      last = frac_str[cur_pos]-ASCII_CONVERSION;
   }

   round = 0;
   key = frac_str[i-1]-ASCII_CONVERSION;

   if( key > 5 ) {  /* 1.6 -> round up, 1.4 -> don't round */
      round = 1;
   } else if( key == 5 ) { /* 1.50000 -> don't round, 1.500001 -> round up */
      while( sig_digs < 36 && !round ) {
         frac*=10.0;          /* introduces loss of precision */
         new_dig = (int)(frac);

         if( new_dig>0 ) {
            round=1;
         }
         sig_digs++;

      }
   }

   if( round ) {       /* round up */
      if( last != 9 ) {    /* just add 1 to the last digit */
         if( last_in_frac ) {
            frac_str[cur_pos]++;
         } else {
            whole_str[cur_pos]++;
         }

      } else {             /* domino rounding */
         while( last == 9 ) {
            /* make cur_pos 0 */
            if( last_in_frac ) {
               frac_str[cur_pos] = '0';
            } else {
               whole_str[cur_pos] = '0';
            }

            /* set new last */
            if( --cur_pos >= 0 ) {  /* simply set new last */
               if( last_in_frac ) {
                  last = frac_str[cur_pos]-ASCII_CONVERSION;
               } else {
                  last = whole_str[cur_pos]-ASCII_CONVERSION;
               }
            } else {                /* cross decimal point */
               if( last_in_frac ) {
                  last_in_frac = 0;
                  cur_pos = vcast_strlen(whole_str)-1;
                  last = whole_str[cur_pos]-ASCII_CONVERSION;
               } else { /* need to shift to add extra 1 */
                  last = 0;
               }
            }
         } /* end while */

         /* add 1 to the current digit */
         if( last_in_frac ) {
            frac_str[cur_pos]++;
         } else {
            if( cur_pos >= 0 ) {
               whole_str[cur_pos]++;
            } else {
               /* need to add a 1 to the front of whole_str */
               if( exp==0 ) {
                  vectorcast_strcpy ( temp_str, "1" );
                  vcast_strcat ( temp_str, whole_str );
                  vectorcast_strcpy( whole_str, temp_str );
               } else {
                  vectorcast_strcpy( whole_str, "1" );
                  exp++;
               }
            }
         }

      } /* end domino */
   } /* end rounding */


/* --- clean up and build mixed_str --- */

   /* trim off rounding info */
   frac_str[i-1] = 0;

   /* kill trailing zeros */
   while( vcast_strlen(frac_str) > 0 && frac_str[vcast_strlen(frac_str)-1] == '0' ) {
      frac_str[vcast_strlen(frac_str)-1] = 0;
   }

   /* don't print the exponent if its zero */
   vectorcast_strcpy ( mixed_str, (sign==-1)?"-":"" );
   vcast_strcat ( mixed_str, whole_str );
   if( vcast_strlen(frac_str) > 0 ) {
      vcast_strcat ( mixed_str, "." );
      vcast_strcat ( mixed_str, frac_str );
   }
   if( exp!=0 ) {
      vectorcast_signed_to_string ( whole_str, exp );
      vcast_strcat ( mixed_str, (exp<0)?"e":"e+" );
      vcast_strcat ( mixed_str, whole_str );
   }

   /* done - mixed_str contains final result */
   return;
}
#endif
/* endif VCAST_NO_FLOAT */
#endif /* !VCAST_UNIT_TEST_TOOL || VCAST_FP || VCAST_NO_SPRINTF */
#endif /* VCAST_PROBE_POINTS_AVAILABLE || VCAST_UNIT_TEST_TOOL */

#ifdef VCAST_PROBE_POINTS_AVAILABLE

#ifndef VCAST_UNIT_TEST_TOOL
void vcast_probe_print (const char *S)
{
   VCAST_WRITE_COVERAGE_DATA("VPROBE:");
   VCAST_WRITE_COVERAGE_DATA(S);
   VCAST_WRITE_COVERAGE_DATA(":VPROBE");
}
#endif

void vcast_probe_print_unsigned (VCAST_UNSIGNED_CONVERSION_TYPE i)
{
   char local_string[32];
   vcast_int_to_string(local_string, i);
   vcast_probe_print (local_string);
}
void vcast_probe_print_int (VCAST_SIGNED_CONVERSION_TYPE i)
{
   char local_string[32];
   vectorcast_signed_to_string(local_string, i);
   vcast_probe_print (local_string);
}
#ifndef VCAST_NO_FLOAT
void vcast_probe_print_float (vCAST_long_double vcast_f)
{
   char local_string[32];
#if !defined(VCAST_UNIT_TEST_TOOL) || defined(VCAST_FP) || defined(VCAST_NO_SPRINTF)
   vectorcast_float_to_string(local_string, vcast_f);
#else
   sprintf ( local_string, VCAST_FLOAT_FORMAT, vcast_f );
#endif /* !VCAST_UNIT_TEST_TOOL || VCAST_FP || VCAST_NO_SPRINTF */
   vcast_probe_print (local_string);
}
#endif

#endif /* endif VCAST_PROBE_POINTS_AVAILABLE */

#endif /* VCAST_PROBE_PRINT_AVAILABLE */

#endif /*VCAST_COVER_IO_COVER_CODE*/
