/*
 * Library distributed_link_tracker_properties type test program
 *
 * Copyright (C) 2009-2017, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <file_stream.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "lnk_test_libcerror.h"
#include "lnk_test_liblnk.h"
#include "lnk_test_macros.h"
#include "lnk_test_memory.h"
#include "lnk_test_unused.h"

#include "../liblnk/liblnk_distributed_link_tracker_properties.h"

#if defined( __GNUC__ )

/* Tests the liblnk_distributed_link_tracker_properties_initialize function
 * Returns 1 if successful or 0 if not
 */
int lnk_test_distributed_link_tracker_properties_initialize(
     void )
{
	libcerror_error_t *error                                                          = NULL;
	liblnk_distributed_link_tracker_properties_t *distributed_link_tracker_properties = NULL;
	int result                                                                        = 0;

#if defined( HAVE_LNK_TEST_MEMORY )
	int number_of_malloc_fail_tests                                                   = 1;
	int number_of_memset_fail_tests                                                   = 1;
	int test_number                                                                   = 0;
#endif

	/* Test regular cases
	 */
	result = liblnk_distributed_link_tracker_properties_initialize(
	          &distributed_link_tracker_properties,
	          &error );

	LNK_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        LNK_TEST_ASSERT_IS_NOT_NULL(
         "distributed_link_tracker_properties",
         distributed_link_tracker_properties );

        LNK_TEST_ASSERT_IS_NULL(
         "error",
         error );

	result = liblnk_distributed_link_tracker_properties_free(
	          &distributed_link_tracker_properties,
	          &error );

	LNK_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

        LNK_TEST_ASSERT_IS_NULL(
         "distributed_link_tracker_properties",
         distributed_link_tracker_properties );

        LNK_TEST_ASSERT_IS_NULL(
         "error",
         error );

	/* Test error cases
	 */
	result = liblnk_distributed_link_tracker_properties_initialize(
	          NULL,
	          &error );

	LNK_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        LNK_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	distributed_link_tracker_properties = (liblnk_distributed_link_tracker_properties_t *) 0x12345678UL;

	result = liblnk_distributed_link_tracker_properties_initialize(
	          &distributed_link_tracker_properties,
	          &error );

	LNK_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        LNK_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	distributed_link_tracker_properties = NULL;

#if defined( HAVE_LNK_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test liblnk_distributed_link_tracker_properties_initialize with malloc failing
		 */
		lnk_test_malloc_attempts_before_fail = test_number;

		result = liblnk_distributed_link_tracker_properties_initialize(
		          &distributed_link_tracker_properties,
		          &error );

		if( lnk_test_malloc_attempts_before_fail != -1 )
		{
			lnk_test_malloc_attempts_before_fail = -1;

			if( distributed_link_tracker_properties != NULL )
			{
				liblnk_distributed_link_tracker_properties_free(
				 &distributed_link_tracker_properties,
				 NULL );
			}
		}
		else
		{
			LNK_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			LNK_TEST_ASSERT_IS_NULL(
			 "distributed_link_tracker_properties",
			 distributed_link_tracker_properties );

			LNK_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
	for( test_number = 0;
	     test_number < number_of_memset_fail_tests;
	     test_number++ )
	{
		/* Test liblnk_distributed_link_tracker_properties_initialize with memset failing
		 */
		lnk_test_memset_attempts_before_fail = test_number;

		result = liblnk_distributed_link_tracker_properties_initialize(
		          &distributed_link_tracker_properties,
		          &error );

		if( lnk_test_memset_attempts_before_fail != -1 )
		{
			lnk_test_memset_attempts_before_fail = -1;

			if( distributed_link_tracker_properties != NULL )
			{
				liblnk_distributed_link_tracker_properties_free(
				 &distributed_link_tracker_properties,
				 NULL );
			}
		}
		else
		{
			LNK_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			LNK_TEST_ASSERT_IS_NULL(
			 "distributed_link_tracker_properties",
			 distributed_link_tracker_properties );

			LNK_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
#endif /* defined( HAVE_LNK_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( distributed_link_tracker_properties != NULL )
	{
		liblnk_distributed_link_tracker_properties_free(
		 &distributed_link_tracker_properties,
		 NULL );
	}
	return( 0 );
}

/* Tests the liblnk_distributed_link_tracker_properties_free function
 * Returns 1 if successful or 0 if not
 */
int lnk_test_distributed_link_tracker_properties_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = liblnk_distributed_link_tracker_properties_free(
	          NULL,
	          &error );

	LNK_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

        LNK_TEST_ASSERT_IS_NOT_NULL(
         "error",
         error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

#endif /* defined( __GNUC__ ) */

/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc LNK_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] LNK_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc LNK_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] LNK_TEST_ATTRIBUTE_UNUSED )
#endif
{
	LNK_TEST_UNREFERENCED_PARAMETER( argc )
	LNK_TEST_UNREFERENCED_PARAMETER( argv )

#if defined( __GNUC__ )

	LNK_TEST_RUN(
	 "liblnk_distributed_link_tracker_properties_initialize",
	 lnk_test_distributed_link_tracker_properties_initialize );

	LNK_TEST_RUN(
	 "liblnk_distributed_link_tracker_properties_free",
	 lnk_test_distributed_link_tracker_properties_free );

	/* TODO: add tests for liblnk_distributed_link_tracker_properties_read */

#endif /* defined( __GNUC__ ) */

	return( EXIT_SUCCESS );

on_error:
	return( EXIT_FAILURE );
}

