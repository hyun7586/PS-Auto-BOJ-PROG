#include <algorithm>
#include <iostream>

using namespace std;

struct Node {
  char val;
  Node* left;
  Node* right;

  Node(char input_val) {
    val = input_val;
    left = NULL;
    right = NULL;
  }
};

int N;
Node *ptr, *head;
string initial_str;

void Input() {
  char command, temp;

  cin >> command;

  switch (command) {
    case 'L': {
      if (ptr->left != NULL) ptr = ptr->left;

      break;
    }
    case 'D': {
      if (ptr->right != NULL) ptr = ptr->right;

      break;
    }
    case 'B': {
      if (ptr->left == NULL) break;

      // left - left에 문자가 있는 경우
      if (ptr->left->left != NULL) {
        ptr->left = (ptr->left)->left;
        (ptr->left)->right = ptr;
      } else {
        // left가 첫번째 문자였던 경우
        ptr->left = NULL;
        head = ptr;
      }

      break;
    }
    case 'P': {
      cin >> temp;

      // 현재 ptr이 마지막 문자인 경우
      if (ptr->val == '0') {
        Node* tempNode = new Node(temp);

        ptr->left->right = tempNode;

        tempNode->left = ptr->left;
        tempNode->right = ptr;

        ptr->left = tempNode;

      } else {
        Node* tempNode = new Node(temp);
        // 첫번째 위치에 넣는 경우
        if (ptr->left == NULL) {
          tempNode->right = ptr;
          ptr->left = tempNode;
          head = tempNode;

          break;
        }

        // 중간에 삽입

        ptr->left->right = tempNode;

        tempNode->left = ptr->left;
        tempNode->right = ptr;

        ptr->left = tempNode;
      }

      break;
    }
  }
}

void initialize() {
  // initialize
  cin >> initial_str;
  for (int i = 0; i < initial_str.size(); i++) {
    if (i == 0) {
      ptr = new Node(initial_str[i]);
      head = ptr;
      continue;
    }

    ptr->right = new Node(initial_str[i]);
    (ptr->right)->left = ptr;
    ptr = ptr->right;
  }

  // last cursor position
  ptr->right = new Node('0');
  (ptr->right)->left = ptr;
  ptr = ptr->right;
}

void Solve() {
  initialize();

  cin >> N;
  for (int i = 0; i < N; i++) Input();

  for (head; head->val != '0'; head = head->right) {
    cout << head->val;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}