

#pragma once
#ifndef BST_H
#define BST_H
#include <iostream>
#include <string>
using namespace std;

class appointment {
public:
    string name;
    int plevel;
    string department;
    appointment(string n, int l, string dept) {
        name = n;
        plevel = l;
        department = dept;
    }
};

class Node {
public:
    appointment data;
    Node* left;
    Node* right;
    Node(appointment a) : data(a) {
        left = right = nullptr;
    }
};
class BST {
    Node* root;
    Node* insert(Node* node, appointment a) {
        if (node == nullptr) {
            return new Node(a);
        }
        if (a.plevel < node->data.plevel) {
            node->left = insert(node->left, a);
        }
        else if (a.plevel > node->data.plevel) {
            node->right = insert(node->right, a);
        }
        else {
            node->left = insert(node->left, a);
        }
        return node;
    }
    void inorder(Node* node, int& Count) {
        if (!node) return;

        inorder(node->left, Count);

        cout <<"[" << node->data.name << ","
            << node->data.plevel << ","
            << node->data.department<<"]\n";
        Count++;

        inorder(node->right, Count);
    }
    void search(Node* node, int p, int&count) {
        if (!node) return;
        search(node->left, p, count);
        if (node->data.plevel == p) {
            cout << "[" << node->data.name << ", "
                << node->data.plevel << ", "
                << node->data.department << "]\n";
            count++;
        }
        search(node->right, p, count);
    }
    Node* findmin(Node* node) {
        while (node->left)
            node = node->left;
        return node;
    }
    Node* deleteAll(Node* node, int p, int& count) {
        if (!node) return nullptr;
        node->left = deleteAll(node->left, p, count);
        node->right = deleteAll(node->right, p, count);
        if (node->data.plevel == p) {
            count++;
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findmin(node->right);
            node->data = temp->data;
            node->right = deleteAll(node->right, temp->data.plevel, count);
        }
        return node;
    }
    void moreUrgent(Node* node, int p, int& count) {
        if (!node) return;

        moreUrgent(node->left, p, count);

        if (node->data.plevel <= p) {
            cout << "[" << node->data.name << ", "
                << node->data.plevel << ", "
                << node->data.department << "]\n";
            count++;
        }

        moreUrgent(node->right, p, count);
    }

    void lessUrgent(Node* node, int p, int& count) {
        if (!node) return;

        lessUrgent(node->left, p, count);

        if (node->data.plevel >= p) {
            cout << "[" << node->data.name << ", "
                << node->data.plevel << ", "
                << node->data.department << "]\n";
            count++;
        }

        lessUrgent(node->right, p, count);
    }
public:
    BST() {
        root = nullptr;
    }
    void schedule(appointment a) {
        root = insert(root, a);
        cout << "Appointment Scheduled\n";
    }
    void DisplayAll() {
        int count = 0;
        inorder(root, count);
        cout << endl;
        cout << count << " Appointments are found \n";
    }
    void cancelPriority(int p) {
        int count = 0;
        root = deleteAll(root, p, count);
        cout << endl;
        cout << count << " Appointments are cancelled\n ";
    }
    void displayMoreUrgent(int p) {
        int count = 0;
        moreUrgent(root, p, count);
        cout << endl;
        cout << count << " Appointments found\n ";
    }
    void displayLessUrgent(int p) {
        int count = 0;
        lessUrgent(root, p, count);
        cout << endl;
        cout << count << " Appointments found\n ";
    }
    void searchPriority(int p) {
        int count = 0;

        search(root, p, count);

        cout << endl;
        cout << count  << "appointments are found";
    }
};
#endif
