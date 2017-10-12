#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../PriorityQueue.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testCreatePriorityQueue() {
    PriorityQueue* result = createPriorityQueue(sizeof(int));
    if (result != NULL) {
        CU_ASSERT(1);
    }
}

void testEnqueue() {
    PriorityQueue* queue = createPriorityQueue(sizeof(int));
    int item = 5;
    int priority = 10;
    int comparison = 0;
    enqueue(queue, &item, priority, &comparison);
    if (isEmpty(queue)) {
        CU_ASSERT(0);
    }
}

void testDequeue() {
    PriorityQueue* queue = createPriorityQueue(sizeof(int));
    int item = 5;
    int priority = 10;
    int comparison = 0;
    enqueue(queue, &item, priority, &comparison);
    int result = *((int*) dequeue(queue));
    if (result != item) {
        CU_ASSERT(0);
    }
}

void testIsEmpty() {
    PriorityQueue* queue = createPriorityQueue(sizeof(int));
    int result = isEmpty(queue);
    if (!result) {
        CU_ASSERT(1);
    }
}

void testGetSize() {
    PriorityQueue* queue = createPriorityQueue(sizeof(int));
    int result = getSize(queue);
    if (result != 0) {
        CU_ASSERT(0);
    }
}

void testDestroyPriorityQueue() {
    PriorityQueue* queue = createPriorityQueue(sizeof(int));
    destroyPriorityQueue(queue);
    if (queue != NULL) {
        CU_ASSERT(1);
    }
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("newcunittest", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testCreatePriorityQueue", testCreatePriorityQueue)) ||
            (NULL == CU_add_test(pSuite, "testEnqueue", testEnqueue)) ||
            (NULL == CU_add_test(pSuite, "testDequeue", testDequeue)) ||
            (NULL == CU_add_test(pSuite, "testIsEmpty", testIsEmpty)) ||
            (NULL == CU_add_test(pSuite, "testGetSize", testGetSize)) ||
            (NULL == CU_add_test(pSuite, "testDestroyPriorityQueue", testDestroyPriorityQueue))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
