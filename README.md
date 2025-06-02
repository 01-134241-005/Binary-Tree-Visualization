# Binary-Tree-Visualization

# 🌳 Binary Tree Visualization and Quiz Project (C++ with SFML)

This project is a C++ console application with graphical visualization using **SFML (Simple and Fast Multimedia Library)**. It provides the following core features:

- Insert and delete nodes in a **Binary Search Tree (BST)**
- Display **Inorder**, **Preorder**, and **Postorder** traversals
- **Graphically visualize** the structure of the BST
- Take a short **quiz** on binary tree concepts

---

## 🎯 Features

1. **Dynamic BST Creation**:
   - Insert and delete nodes
   - Maintains BST properties

2. **Tree Traversals**:
   - Inorder
   - Preorder
   - Postorder

3. **Graphical Tree Visualization**:
   - Uses **SFML** to draw nodes and links
   - Dynamically updates layout

4. **Quiz Section**:
   - 5 Multiple Choice Questions (MCQs)
   - Immediate scoring and feedback

---

## 🛠️ Requirements

- C++17 or above
- [SFML Library](https://www.sfml-dev.org/download.php) (Graphics module)
- `arial.ttf` font file in the same directory as the executable

---

## 🧱 How to Compile

**Using g++ (Linux / Windows with MinGW):**

```bash
g++ -o BinaryTreeApp main.cpp -lsfml-graphics -lsfml-window -lsfml-system
````

Make sure:

* SFML is installed correctly and linked
* `arial.ttf` is present in the working directory

---

## 🖼️ How to Run


On execution, you'll see a text menu with the following options:

```
===== BINARY TREE MENU =====
1. Insert Node
2. Delete Node
3. Inorder Traversal
4. Preorder Traversal
5. Postorder Traversal
6. Visualize Tree
7. Take Quiz
8. Exit
```

Select the appropriate option by entering the number.

---



## 📁 File Structure


├── main.cpp        # Full source code
├── README.md       # DOCUMENTATION OF CODE

---

## 🧠 Concepts Covered

* Binary Search Tree operations
* Tree Traversals
* Graph-based visualization (SFML)
* User interaction through CLI
* Educational quiz logic

---

## 👤 Author

* **Your Name** AQSA RIAZ ,ALMAS BIBI
* BSCS Semester Project – *Data Structures & Algorithms*
* Bahria University Islamabad

---

## ✅ Future Improvements

* Add more questions to the quiz
* Add support for balancing (e.g., AVL or Red-Black Trees)
* Save/load tree from file
* Use GUI buttons instead of console for interaction

---
