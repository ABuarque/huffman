#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../HeapedPriorityQueue.h"

/*
 * CUnit Test Suite
 */

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

void testNewHeapedPriorityQueue() {
    HeapedPriorityQueue* result = newHeapedPriorityQueue(sizeof(int));
    if (result != NULL) {
        CU_ASSERT(1);
    }
}

void testDestroyHeapedPriorityQueue() {
    HeapedPriorityQueue* queue = newHeapedPriorityQueue(sizeof(int));
    destroyHeapedPriorityQueue(queue);
    if (queue == NULL) {
        CU_ASSERT(0);
    }
}

void testEnqueueHPQ() {
    HeapedPriorityQueue* queue = newHeapedPriorityQueue(sizeof(int));
    int a = 10, comparator = 0;
    enqueueHPQ(queue, &a, &comparator);
    int size = getQueueSize(queue);
    if (size == 0) {
        CU_ASSERT(0);
    }
}

void testDequeueHPQ() {
    HeapedPriorityQueue* queue = newHeapedPriorityQueue(sizeof(int));
    int a = 10, comparator = 0;
    enqueueHPQ(queue, &a, &comparator);
    int result = *((int*) dequeueHPQ(queue));
    if (result != a) {
        CU_ASSERT(0);
    }
}

int main() {
    CU_pSuite pSuite = NULL;

    /* Initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* Add a suite to the registry */
    pSuite = CU_add_suite("newcunittest1", init_suite, clean_suite);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Add the tests to the suite */
    if ((NULL == CU_add_test(pSuite, "testNewHeapedPriorityQueue", testNewHeapedPriorityQueue)) ||
            (NULL == CU_add_test(pSuite, "testDestroyHeapedPriorityQueue", testDestroyHeapedPriorityQueue)) ||
            (NULL == CU_add_test(pSuite, "testEnqueueHPQ", testEnqueueHPQ)) ||
            (NULL == CU_add_test(pSuite, "testDequeueHPQ", testDequeueHPQ))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
