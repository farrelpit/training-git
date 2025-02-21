#include <stdio.h>
#include <stdlib.h>

// Struktur Node untuk Doubly Linked List
struct node {
    int value;
    struct node *next;
    struct node *prev;
} *head, *tail;

// Fungsi untuk mencetak DLL dari depan ke belakang
void printForward() {
    struct node *curr = head;
    printf("Forward: ");
    while (curr != NULL) {
        printf("%d -> ", curr->value);
        curr = curr->next;
    }
    printf("NULL\n");
}

// Fungsi untuk mencetak DLL dari belakang ke depan
void printBackward() {
    struct node *curr = tail;
    printf("Backward: ");
    while (curr != NULL) {
        printf("%d -> ", curr->value);
        curr = curr->prev;
    }
    printf("NULL\n");
}

// Fungsi untuk menambahkan elemen secara terurut
void push(int x) {
    struct node *c = (struct node*)malloc(sizeof(struct node));
    c->value = x;
    c->next = NULL;
    c->prev = NULL;

    if (head == NULL) {
        // Jika list kosong, node pertama jadi head dan tail
        head = tail = c;
    }
    
    else if (x <= head->value) {
        // Insert di depan
        c->next = head;
        head->prev = c;
        head = c;
    }
    else if (x >= tail->value) {
        // Insert di belakang
        tail->next = c;
        c->prev = tail;
        tail = c;
    } 
    else {
        // Insert di tengah
        struct node *curr = head;
        while (curr->next != NULL && curr->next->value < x) {
            curr = curr->next;
        }
        c->next = curr->next;
        c->prev = curr;
        if (curr->next != NULL) {
            curr->next->prev = c;
        }
        curr->next = c;
    }
}

// Fungsi untuk menghapus elemen dengan nilai tertentu
void pop(int x) {
    if (head == NULL) return; // List kosong

    struct node *curr = head;

    while (curr != NULL && curr->value != x) {
        curr = curr->next;
    }

    if (curr == NULL) return; // Nilai tidak ditemukan

    if (curr == head) {
        // Hapus head
        head = head->next;
        if (head != NULL) head->prev = NULL;
    } 
    else if (curr == tail) {
        // Hapus tail
        tail = tail->prev;
        if (tail != NULL) tail->next = NULL;
    } 
    else {
        // Hapus di tengah
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }

    free(curr); // Hapus node dari memori
}

// Program utama
int main() {
    head = tail = NULL; // Inisialisasi

    push(20);
    push(10);
    push(30);
    push(25);
    push(15);

    printForward();
    printBackward();

    pop(25);
    printf("\nSetelah pop(25):\n");
    printForward();

    pop(10);
    printf("\nSetelah pop(10):\n");
    printForward();

    return 0;
}

