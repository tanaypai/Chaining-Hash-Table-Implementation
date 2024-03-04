/*
CSE 310 Hash Function DIY Contest
Instructor: Yiran "Lawrence" Luo
Your name(s): Tanay Pai
Your team alias: 
*/

#include <iostream>
#include <string>
#include "hash.h"
using namespace std;

struct Node {
    string key;
    Node* next;
};

int main() {

    int k = 0;
    int n = 0;
    string texts[500];

    // WARNING: Start of the tokenizer that loads the input from std::cin, DO NOT change this part!
    cin >> k;
    string line;
    getline(cin, line);

    while (getline(cin, line)) {
        texts[n] = line;
        n++;
    }
    // WARNING: End of the tokenizer, DO NOT change this part!

    // By this point, k is the # of slots, and n is the # of tokens to fit in
    // texts[] stores the input sequence of tokens/keys to be inserted into your hash table

    // The template is able to be compiled by running 
    //   make
    //   ./encoder < inputs/sample_input.txt
    // which puts out the placeholders only.

    // Your time to shine starts now

    Node* hashTable[k];
    for (int i = 0; i < k; i++) {
        hashTable[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        int index = hash_function(texts[i], k);
        Node* newNode = new Node;
        newNode->key = texts[i];
        newNode->next = NULL;
        if(hashTable[index] == NULL) {
            hashTable[index] = newNode;
        } else {
            Node* temp = hashTable[index];
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        
        }
    }

    cout << "==== Printing the contents of the first 5 slots ====" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Slot" << i << ": ";
        Node* temp = hashTable[i];
        while(temp != NULL) {
            cout << temp->key << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    cout << "==== Printing the slot lengths ====" << endl;
    for (int i = 0; i < k; i++) {
        int count = 0;
        Node* temp = hashTable[i];
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }
        cout << "Slot" << i << ": " << count << endl;
    }
    cout << "==== Printing the standard variance =====" << endl;
    int counts[k];
    for (int i = 0; i < k; i++) {
        int count = 0;
        Node* temp = hashTable[i];
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }
        counts[i] = count;
    }
    double mean = 0;
    for (int i = 0; i < k; i++) {
        mean += counts[i];
    }
    mean = mean / k;
    double std_dev = 0;
    for (int i = 0; i < k; i++) {
        std_dev += (counts[i] - mean) * (counts[i] - mean);
    }
    std_dev = std_dev / k;
    std_dev = sqrt(std_dev);
    cout << std_dev << endl;
    return 0;
}