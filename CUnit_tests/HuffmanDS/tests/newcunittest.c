#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>

typedef unsigned char byte;

int init_suite(void) {
    return 0;
}

int clean_suite(void) {
    return 0;
}

typedef struct huffmanTree {
	void* treeByte;
	size_t dataTypeSize;
	int frequency;
	struct huffmanTree* left;
	struct huffmanTree* right;
} HuffmanTree;

typedef struct list {
	HuffmanTree* tree;
	struct list* next;
} List;

typedef struct {
	List* head;
} PriorityQueue;


HuffmanTree* newHuffmanTree(size_t dataTypeSize, void* treeByte, int frequency);

HuffmanTree* newHuffmanHandle(size_t dataTypeSize);

List* newList();

List* newNode(HuffmanTree* tree);

PriorityQueue* newPriorityQueue();

int isEmpty(PriorityQueue* queue);

void enqueue(PriorityQueue* queue, HuffmanTree* tree);

HuffmanTree* dequeue(PriorityQueue* queue);


void testNewHuffmanTree() {
    size_t dataTypeSize = sizeof(byte);
    byte treeByte = '*';
    int frequency = 10;
    HuffmanTree* result = newHuffmanTree(dataTypeSize, &treeByte, frequency);
    if (result != NULL) {
        CU_ASSERT(1);
    }
}

void testNewHuffmanHandle() {
    size_t dataTypeSize = sizeof(byte);
    HuffmanTree* result = newHuffmanHandle(dataTypeSize);
    if (result != NULL) {
        CU_ASSERT(1);
    }
}

void testNewList() {
    List* result = newList();
    if (result == NULL) {
        CU_ASSERT(1);
    }
}

void testNewNode() {
    byte x = '8';
    HuffmanTree* t = newHuffmanTree(sizeof(byte), &x,10);
    List* result = newNode(t);
    if (result != NULL) {
        CU_ASSERT(1);
    }
}

void testNewPriorityQueue() {
    PriorityQueue* result = newPriorityQueue();
    if (result != NULL) {
        CU_ASSERT(1);
    }
}

void testIsEmpty() {
    PriorityQueue* queue = newPriorityQueue();
    int result = isEmpty(queue);
    if (result == 0) {
        CU_ASSERT(1);
    }
}

void enqueue(PriorityQueue* queue, HuffmanTree* tree);

void testEnqueue() {
    byte x = '*';
    PriorityQueue* queue = newPriorityQueue();
    HuffmanTree* tree = newHuffmanTree(sizeof(byte), &x, 505);
    enqueue(queue, tree);
    HuffmanTree* result = dequeue(queue);
    if (result == NULL) {
        CU_ASSERT(0);
    }
}

void testDequeue() {
    PriorityQueue* queue = newPriorityQueue();
    HuffmanTree* result = dequeue(queue);
    if (result == NULL) {
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
    if ((NULL == CU_add_test(pSuite, "testNewHuffmanTree", testNewHuffmanTree)) ||
            (NULL == CU_add_test(pSuite, "testNewHuffmanHandle", testNewHuffmanHandle)) ||
            (NULL == CU_add_test(pSuite, "testNewList", testNewList)) ||
            (NULL == CU_add_test(pSuite, "testNewNode", testNewNode)) ||
            (NULL == CU_add_test(pSuite, "testNewPriorityQueue", testNewPriorityQueue)) ||
            (NULL == CU_add_test(pSuite, "testIsEmpty", testIsEmpty)) ||
            (NULL == CU_add_test(pSuite, "testEnqueue", testEnqueue)) ||
            (NULL == CU_add_test(pSuite, "testDequeue", testDequeue))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Run all tests using the CUnit Basic interface */
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}
