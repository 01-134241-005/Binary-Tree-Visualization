#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    int x, y; // For drawing positions
};

// Create a new node
Node* newNode(int data) {
    Node* temp = new Node();
    temp->data = data;
    temp->left = temp->right = nullptr;
    temp->x = temp->y = 0;
    return temp;
}

// BST insert
Node* insert(Node* root, int data) {
    if (!root) return newNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}

// Minimum node (used for delete)
Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

// Delete node
Node* deleteNode(Node* root, int key) {
    if (!root) return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Traversals
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

// Set node positions for visualization (recursive)
void setNodePositions(Node* root, int x, int y, int dx) {
    if (!root) return;
    root->x = x;
    root->y = y;
    setNodePositions(root->left, x - dx, y + 70, dx / 2);
    setNodePositions(root->right, x + dx, y + 70, dx / 2);
}

// Draw the tree with lines and nodes
void drawTree(sf::RenderWindow& window, Node* root, sf::Font& font) {
    if (!root) return;

    // Draw lines to children first
    if (root->left) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(root->x, root->y), sf::Color::Black),
            sf::Vertex(sf::Vector2f(root->left->x, root->left->y), sf::Color::Black)
        };
        window.draw(line, 2, sf::Lines);
        drawTree(window, root->left, font);
    }
    if (root->right) {
        sf::Vertex line[] = {
            sf::Vertex(sf::Vector2f(root->x, root->y), sf::Color::Black),
            sf::Vertex(sf::Vector2f(root->right->x, root->right->y), sf::Color::Black)
        };
        window.draw(line, 2, sf::Lines);
        drawTree(window, root->right, font);
    }

    // Draw node circle
    sf::CircleShape circle(20);
    circle.setFillColor(sf::Color::Cyan);
    circle.setPosition(root->x - 20, root->y - 20);
    window.draw(circle);

    // Draw node data text
    sf::Text text;
    text.setFont(font);
    text.setString(to_string(root->data));
    text.setCharacterSize(15);
    text.setFillColor(sf::Color::Black);
    text.setPosition(root->x - 10, root->y - 15);
    window.draw(text);
}

// Visualization function
void visualizeTree(Node* root) {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Binary Tree Visualization");
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        cout << "Failed to load font\n";
        return;
    }

    // Calculate positions every time before drawing
    setNodePositions(root, 400, 50, 150);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        drawTree(window, root, font);
        window.display();
    }
}
void takeQuiz() {
    int score = 0;
    int answer;

    cout << "\n=== Binary Tree Quiz ===\n";

    cout << "Q1. What is the maximum number of children a binary tree node can have?\n";
    cout << "1) One\n2) Two\n3) Three\n4) Four\nYour answer: ";
    cin >> answer;
    if (answer == 2) score++;

    cout << "Q2. Which traversal method visits the root node last?\n";
    cout << "1) Inorder\n2) Preorder\n3) Postorder\n4) Level order\nYour answer: ";
    cin >> answer;
    if (answer == 3) score++;

    cout << "Q3. What does a leaf node in a binary tree mean?\n";
    cout << "1) Node with two children\n2) Node with no children\n3) Root node\n4) Node with one child\nYour answer: ";
    cin >> answer;
    if (answer == 2) score++;

    cout << "Q4. What is the inorder traversal of the tree with nodes 10, 5, 15?\n";
    cout << "1) 5 10 15\n2) 10 5 15\n3) 15 10 5\n4) 10 15 5\nYour answer: ";
    cin >> answer;
    if (answer == 1) score++;

    cout << "Q5. In a binary search tree (BST), where are smaller values placed?\n";
    cout << "1) Left subtree\n2) Right subtree\n3) Root\n4) None\nYour answer: ";
    cin >> answer;
    if (answer == 1) score++;

    cout << "\nYour score: " << score << "/5\n";

    if (score == 5) cout << "Excellent! You know your binary trees well.\n";
    else if (score >= 3) cout << "Good job! Keep practicing.\n";
    else cout << "You need more practice on binary trees.\n";
}


// Main menu with original code
int main() {
    Node* root = nullptr;
    int choice, value;

    do {
        cout << "\n===== BINARY TREE MENU =====\n";
        cout << "1. Insert Node\n2. Delete Node\n3. Inorder Traversal\n4. Preorder Traversal\n";
        cout << "5. Postorder Traversal\n6. Visualize Tree\n7. Take Quiz\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            root = deleteNode(root, value);
            break;
        case 3:
            cout << "Inorder: ";
            inorder(root);
            cout << "\n";
            break;
        case 4:
            cout << "Preorder: ";
            preorder(root);
            cout << "\n";
            break;
        case 5:
            cout << "Postorder: ";
            postorder(root);
            cout << "\n";
            break;
        case 6:
            visualizeTree(root);
            break;
        case 7:

            takeQuiz();
            break;
        case 8:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid option.\n";
        }
    } while (choice != 8);

    return 0;
}