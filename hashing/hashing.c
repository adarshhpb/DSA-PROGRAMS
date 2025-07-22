#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10

int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert key with linear probing, prevent infinite loop if table is full
void insert(int hashTable[], int key) {
    int index = hashFunction(key);
    int start = index;
    while (hashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
        if (index == start) {
            printf("Hash table is full. Cannot insert %d.\n", key);
            return;
        }
    }
    hashTable[index] = key;
}

void displayHashTable(int hashTable[]) {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != -1)
            printf("%d: %d\n", i, hashTable[i]);
        else
            printf("%d: [empty]\n", i);
    }
}

int main(void) {
    int hashTable[TABLE_SIZE];
    int numKeys;
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }
    printf("Hash table size is fixed at %d.\n", TABLE_SIZE);
    printf("Enter the number of keys (max %d): ", TABLE_SIZE);
    scanf("%d", &numKeys);
    if (numKeys > TABLE_SIZE) {
        printf("Number of keys exceeds table size. Only first %d will be inserted.\n", TABLE_SIZE);
        numKeys = TABLE_SIZE;
    }
    printf("Enter the keys:\n");
    for (int i = 0; i < numKeys; i++) {
        int key;
        scanf("%d", &key);
        insert(hashTable, key);
    }
    displayHashTable(hashTable);
    return 0;
}
