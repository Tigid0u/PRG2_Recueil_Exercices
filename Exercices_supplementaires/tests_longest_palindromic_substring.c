#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <string.h>
#include "longest_palindromic_substring.h"

/* === 1. Test functions === */

void test_nominal_case(void) {
    const char *str = "asugusisnice";
    // Redirect stdout to a temporary file
    FILE *fp = freopen("output.txt", "w+", stdout);
    if (!fp) {
        CU_FAIL("Failed to redirect stdout");
        return;
    }

    // Call the function (writes to redirected stdout)
    longest_palindrome_in_string(str, strlen(str));

    // Flush stdout and rewind the file
    fflush(stdout);
    fseek(fp, 0, SEEK_SET);

    // Read output back
    char buffer[256];
    fgets(buffer, sizeof(buffer), fp);

    // Restore stdout
    freopen("CON", "w", stdout);  // Windows-specific console
    // On Linux: freopen("/dev/tty", "w", stdout);

    // Assert
    CU_ASSERT_STRING_EQUAL(buffer, "Longest palindromic substring of the said string: sugus");
}

void test_empty_string(void) {
    const char *str = "";
    // Redirect stdout to a temporary file
    FILE *fp = freopen("output.txt", "w+", stdout);
    if (!fp) {
        CU_FAIL("Failed to redirect stdout");
        return;
    }

    // Call the function (writes to redirected stdout)
    longest_palindrome_in_string(str, strlen(str));

    // Flush stdout and rewind the file
    fflush(stdout);
    fseek(fp, 0, SEEK_SET);

    // Read output back
    char buffer[256];
    fgets(buffer, sizeof(buffer), fp);

    // Restore stdout
    freopen("CON", "w", stdout);  // Windows-specific console
    // On Linux: freopen("/dev/tty", "w", stdout);

    // Assert
    CU_ASSERT_STRING_EQUAL(buffer, "Empty string or string is too short to be a palindrome\n");
}

void test_string_too_short(void) {
    const char *str = "ab";
    // Redirect stdout to a temporary file
    FILE *fp = freopen("output.txt", "w+", stdout);
    if (!fp) {
        CU_FAIL("Failed to redirect stdout");
        return;
    }

    // Call the function (writes to redirected stdout)
    longest_palindrome_in_string(str, strlen(str));

    // Flush stdout and rewind the file
    fflush(stdout);
    fseek(fp, 0, SEEK_SET);

    // Read output back
    char buffer[256];
    fgets(buffer, sizeof(buffer), fp);

    // Restore stdout
    freopen("CON", "w", stdout);  // Windows-specific console
    // On Linux: freopen("/dev/tty", "w", stdout);

    // Assert
    CU_ASSERT_STRING_EQUAL(buffer, "Empty string or string is too short to be a palindrome\n");
}

void test_no_palindrome_in_string(void) {
    const char *str = "abcdefg";
    // Redirect stdout to a temporary file
    FILE *fp = freopen("output.txt", "w+", stdout);
    if (!fp) {
        CU_FAIL("Failed to redirect stdout");
        return;
    }

    // Call the function (writes to redirected stdout)
    longest_palindrome_in_string(str, strlen(str));

    // Flush stdout and rewind the file
    fflush(stdout);
    fseek(fp, 0, SEEK_SET);

    // Read output back
    char buffer[256];
    fgets(buffer, sizeof(buffer), fp);

    // Restore stdout
    freopen("CON", "w", stdout);  // Windows-specific console
    // On Linux: freopen("/dev/tty", "w", stdout);

    // Assert
    CU_ASSERT_STRING_EQUAL(buffer, "No palindrome was found in abcdefg !\n");
}

void test_two_equal_length_palindrome_in_string(void) {
    const char *str = "suguswithkayak";
    // Redirect stdout to a temporary file
    FILE *fp = freopen("output.txt", "w+", stdout);
    if (!fp) {
        CU_FAIL("Failed to redirect stdout");
        return;
    }

    // Call the function (writes to redirected stdout)
    longest_palindrome_in_string(str, strlen(str));

    // Flush stdout and rewind the file
    fflush(stdout);
    fseek(fp, 0, SEEK_SET);

    // Read output back
    char buffer[256];
    fgets(buffer, sizeof(buffer), fp);

    // Restore stdout
    freopen("CON", "w", stdout);  // Windows-specific console
    // On Linux: freopen("/dev/tty", "w", stdout);

    // Assert
    CU_ASSERT_STRING_EQUAL(buffer, "Longest palindromic substring of the said string: kayak");
}

/* === 2. Main function with test suite registration === */
int main(void) {
    // Initialize the CUnit test registry
    if (CU_initialize_registry() != CUE_SUCCESS)
        return CU_get_error();

    // Create a test suite
    CU_pSuite suite = CU_add_suite("LongestPalindromeInString tests", NULL, NULL);
    if (!suite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add the tests to the suite
    if (!CU_add_test(suite, "nominal case", test_nominal_case) ||
        !CU_add_test(suite, "empty string", test_empty_string) ||
        !CU_add_test(suite, "string too short", test_string_too_short) ||
        !CU_add_test(suite, "no palindrome in string", test_no_palindrome_in_string) ||
        !CU_add_test(suite, "two equal length palindrome in string", test_two_equal_length_palindrome_in_string)) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run tests using the basic interface
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    remove("output.txt");

    // Clean up registry and return
    CU_cleanup_registry();
    return CU_get_error();
}
