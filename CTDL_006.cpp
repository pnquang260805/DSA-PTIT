// LỌC DỮ LIỆU TRÙNG TRONG DSLK ĐƠN

#include <iostream>
#include <unordered_set>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int val = 0) : val(val), next(nullptr) {}
};

class List {
public:
    ListNode* head;

    List() : head(nullptr) {}

    void append(int new_val) {
        ListNode* new_node = new ListNode(new_val);
        if (!head) {
            head = new_node;
            return;
        }
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        tail->next = new_node;
    }

    void show() {
        ListNode* tail = head;
        while (tail) {
            cout << tail->val << " ";
            tail = tail->next;
        }
        cout << "\n";
    }

    void filtering() {
        if (!head) return;
        unordered_set<int> mark;
        mark.insert(head->val);
        ListNode* curr = head->next;
        ListNode* prev = head;
        while (curr) {
            if (mark.find(curr->val) == mark.end()) {
                mark.insert(curr->val);
                prev->next = curr;
                prev = curr;
            }
            curr = curr->next;
        }
        prev->next = nullptr;
    }
};

int main() {
    int n;
    cin >> n;
    List lst;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        lst.append(num);
    }
    lst.filtering();
    lst.show();
    return 0;
}
