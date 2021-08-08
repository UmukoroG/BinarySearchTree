#include "BinarySearchTree.h"
#include <iostream> 
#include <iomanip>
#include <ctime>
using namespace std;

int main() { 
    BinarySearchTree b; 
    int ch, tmp, tmp1; 
    int Old;//old data to be updated with a random data
    srand(time(NULL));
    int ran= rand()%51;
    while (1) { 
        cout << endl << endl; 
        cout << " Binary Search Tree Operations " << endl; 
        cout << " ----------------------------- " << endl; 
        cout << " 1. Insertion/Creation " << endl; 
        cout << " 2. In-Order Traversal " << endl; 
        cout << " 3. Pre-Order Traversal " << endl; 
        cout << " 4. Post-Order Traversal " << endl; 
        cout << " 5. Removal " << endl; 
        cout << " 6. Update an old node with a random node"<<endl;
        cout << " 7. Exit " << endl; 
        cout << " Enter your choice : "; 
        cin >> ch;
        switch (ch) { 
            case 1 : cout<<" Enter data to be inserted : ";
                cin>>tmp;
                b.insert(tmp);                  
                b.print_inorder();
                break;
            case 2: 
                cout << endl; 
                cout << " In-Order Traversal " << endl; 
                cout << " -------------------" << endl; 
                b.print_inorder(); 
                break; 
            case 3: 
                cout << endl; 
                cout << " Pre-Order Traversal " << endl; 
                cout << " -------------------" << endl; 
                b.print_preorder(); 
                break; 
            case 4: 
                cout << endl; 
                cout << " Post-Order Traversal " << endl; 
                cout << " --------------------" << endl; 
                b.print_postorder(); 
                break; 
            case 5: 
                cout << " Enter data to be deleted : "; 
                cin>>tmp1;
                b.remove(tmp1);                   
                b.print_inorder();
                break;
            case 6:
                cout<<"Enter data to be updated:";
                cin >> Old; 
                b.update(Old,ran);
                b.print_inorder();
                break;
            case 7: system("pause"); 
                return 0; 
                break; 
        } 
    }
    return 0;
}