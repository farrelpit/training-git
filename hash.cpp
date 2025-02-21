#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Struktur Node untuk Linked List (Chaining)
typedef struct Node {
    int key;
    struct Node *next;
} Node;

// Hash Table dengan Chaining
Node* hashTable[TABLE_SIZE];

// Fungsi Hash
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Fungsi untuk Menambahkan Data ke Hash Table
void insert(int key) {
    int index = hashFunction(key);
    
    // Buat Node baru
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    
    // Jika tidak ada collision, langsung simpan
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        // Collision, tambahkan di linked list (chaining)
        Node *temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Fungsi untuk Mencari Data di Hash Table
int search(int key) {
    int index = hashFunction(key);
    Node *temp = hashTable[index];
    
    while (temp != NULL) {
        if (temp->key == key) {
            return 1; // Ditemukan
        }
        temp = temp->next;
    }
    return 0; // Tidak ditemukan
}

// Fungsi untuk Menampilkan Hash Table
void display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d]: ", i);
        Node *temp = hashTable[i];
        while (temp != NULL) {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Fungsi untuk Menghapus Elemen dari Hash Table
void deletes(int key) {
    int index = hashFunction(key);
    Node *temp = hashTable[index];
    Node *prev = NULL;

    while (temp != NULL && temp->key != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return; // Tidak ditemukan

    if (prev == NULL) {
        hashTable[index] = temp->next; // Hapus head list
    } else {
        prev->next = temp->next; // Hapus di tengah
    }

    free(temp);
}

// Program Utama
int main() {
    // Inisialisasi hash table
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(15); // Collision dengan 10
    insert(25); // Collision dengan 20

    display();

    printf("\nCari 25: %s\n", search(25) ? "Ditemukan" : "Tidak ditemukan");

    deletes(25);
    printf("\nSetelah hapus 25:\n");
    display();

    return 0;
}

