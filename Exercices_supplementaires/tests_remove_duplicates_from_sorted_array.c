#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "remove_duplicates_from_sorted_array.h"

void display_int_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

void test_nominal_case(void) {
    int arr[] = { 1,1,2,2,2,3,3,4,5 };
    int size = sizeof(arr) / sizeof(int), new_size;
    FILE *fp = freopen("output.txt", "w+", stdout);
    // Redirect stdout to a temporary file
    if (!fp) {
        CU_FAIL("Failed to redirect stdout");
        return;
    }

    new_size = remove_duplicates_from_array(arr, size);

    display_int_array(arr, new_size);

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
    CU_ASSERT_STRING_EQUAL(buffer, "1 2 3 4 5 ");
}

void test_one_element_in_arr(void) {
    int arr[] = { 1 };
    int size = sizeof(arr) / sizeof(int), new_size;
    FILE *fp = freopen("output.txt", "w+", stdout);
    // Redirect stdout to a temporary file
    if (!fp) {
        CU_FAIL("Failed to redirect stdout");
        return;
    }

    new_size = remove_duplicates_from_array(arr, size);

    display_int_array(arr, new_size);

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
    CU_ASSERT_STRING_EQUAL(buffer, "1 ");
}

void test_empty_arr(void) {
    int arr[0];
    int size = sizeof(arr) / sizeof(int), new_size;

    new_size = remove_duplicates_from_array(arr, size);

    // Assert
    CU_ASSERT(new_size == 0);
}

int main() {
    if (CU_initialize_registry() != CUE_SUCCESS) {
        printf("Failed to init tests !\n");
        return CU_get_error();
    }

    CU_TestInfo tests[] = {
        {"nominal case",test_nominal_case},
        {"one element in array", test_one_element_in_arr},
        {"empty array", test_empty_arr},
        CU_TEST_INFO_NULL
    };

    CU_SuiteInfo suites[] = {
        {"remove duplicates from sorted array suite", NULL, NULL, NULL, NULL, tests},
        CU_SUITE_INFO_NULL
    };

    if (CUE_SUCCESS != CU_register_suites(suites)) {
        printf("Failed to init test suite !\n");
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}
