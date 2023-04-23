#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE 1024 // page size in bytes
#define PAGE_TABLE_ENTRIES 256 // number of entries in page table
#define MEMORY_SIZE 65536 // total memory size in bytes

typedef struct page_table_entry {
    int valid; // whether the page is in memory or not
    int frame; // frame number where the page is stored
} page_table_entry;

int main() {
    int *memory = (int *) malloc(MEMORY_SIZE); // allocate memory
    page_table_entry page_table[PAGE_TABLE_ENTRIES]; // initialize page table
    int num_pages = MEMORY_SIZE / PAGE_SIZE;
    int num_frames = num_pages / 2;
    int i, j;

    // initialize page table entries
    for (i = 0; i < num_pages; i++) {
        page_table[i].valid = 0;
        page_table[i].frame = -1;
    }

    // initialize memory frames
    for (i = 0; i < num_frames; i++) {
        for (j = 0; j < PAGE_SIZE / sizeof(int); j++) {
            memory[i * PAGE_SIZE / sizeof(int) + j] = i; // fill with frame number
        }
    }

    // simulate program execution
    for (i = 0; i < num_pages; i++) {
        if (!page_table[i].valid) { // page fault, load page into memory
            int frame = i % num_frames; // select frame to load page into
            page_table[i].valid = 1;
            page_table[i].frame = frame;
            printf("Page %d loaded into frame %d\n", i, frame);
        }

        // access memory
        int value = memory[page_table[i].frame * PAGE_SIZE / sizeof(int)];
        printf("Value at address %d is %d\n", i * PAGE_SIZE, value);
    }

    free(memory); // free memory

    return 0;
}

