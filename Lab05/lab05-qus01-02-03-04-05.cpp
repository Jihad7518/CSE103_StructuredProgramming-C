#include<bits/stdc++.h>
class Node{
public:
    int data;
    Node* left = NULL;
    Node* right = NULL;
    Node(){};
    Node(int data){
    this -> data = data;
    }
};

using namespace std;
class BST {
  public:
    Node* root = NULL;
    Node* newData = new Node();
    Node* insert(Node* root, int data ) {
        Node* temp = root;
        if( temp == NULL ) {
            root = new Node(data);
        } else {
            while( temp != NULL ) {
                if( temp -> data > data ) {
                    if( temp -> left != NULL ) {
                        temp = temp -> left;
                    } else {
                        temp -> left = new Node(data);
                        return root;
                    }
                } else {
                    if( temp -> right != NULL ) {
                        temp = temp -> right;
                    } else {
                        temp -> right = new Node(data);
                        return root;
                    }
                }
            }
        }
        return root;
    }
    Node* search( int data ) {
        Node* temp = root;
        while( temp != NULL ) {
            if( temp -> data == data )break;
            else if(temp -> data > data ) {
                temp = temp -> left;
            } else temp = temp -> right;
        }
        return temp;
    }
    void Preorder( Node* root ) {
        if (root == NULL)return;
        cout << root->data << " ";
        Postorder(root->left);
        Postorder(root->right);

    }
    void Postorder( Node* root ) {
        if (root == NULL)return;
        Postorder(root->left);
        Postorder(root->right);
        cout << root->data << " ";
    }
    void Inorder( Node* root ) {
        if (root == NULL)return;
        Postorder(root->left);
        cout << root->data << " ";
        Postorder(root->right);
    }
    int deleteNode( int value ) {
        if(search(value) != NULL) {
            Node* temp = search(value);
            if( temp -> left != NULL && temp -> right != NULL ){

            }
            else if( temp -> left != NULL || temp -> right != NULL ){
                if( temp -> left != NULL ){
                    Node* temp1 = temp -> left;
                    delete temp;
                    temp = temp1;
                }
                else{
                    Node* temp1 = temp -> right;
                    delete temp;
                    temp = temp1;
                }
            }
            else{
                    delete temp;
            }
            return 1;
        } else {
            return 0;
        }

    }
    int findMax() {
        if( this -> root == NULL ) {
            return 0;
        } else {
            Node* temp = this -> root;
            while( temp -> right != NULL ) {
                temp = temp -> right;
            }
            return temp -> data;
        }
    }
    int findMin() {
        if( this -> root == NULL ) {
            return 0;
        } else {
            Node* temp = this -> root;
            while( temp -> left != NULL ) {
                temp = temp -> left;
            }
            return temp -> data;
        }
    }

};

using namespace std;
int main() {
    BST* tree = new BST();
    int data[] = {128, 32, 512, 16, 64, 256, 1024};
    for(int i = 0 ; i < 7 ; i++ )
        tree -> root = tree -> insert(tree -> root, data[i]);
    while(true) {
        cout <<endl<<"1.Insert data" << endl
             <<"2.Search data" << endl
             <<"3.Traversal data" << endl
             <<"4.Delete data" << endl
             <<"5.Find max and min data"<< endl
             <<"0.Exit"<< endl;
        int option;
        cin >> option;
        if( option == 1 ) {
            cout <<"Enter data to insert in BST :";
            int data;
            cin >> data;
            tree -> root = tree -> insert(tree -> root, data);
        } else if( option == 2) {
            if(tree -> root == NULL ) {
                cout << "BST is still empty" << endl;
            } else {
                cout <<"Enter data to search in BST :";
                int data;
                cin >> data;
                if( tree -> search(data)!= NULL ) {
                    cout << data << " found in BST" << endl;
                } else cout << data << " not found in BST" << endl;
            }
        } else if( option == 3) {
            cout <<"1.Pre order traversal of BST"<<endl
                 <<"2.Post order traversal of BST"<<endl
                 <<"3.In order traversal of BST"<<endl;
                 int option1;
                 cin >> option1;
                 if( option1 == 1 )tree -> Preorder( tree -> root );
                 else if( option1 == 2 )tree -> Postorder( tree -> root );
                 else if( option1 == 3 )tree -> Inorder( tree -> root );
        } else if( option == 4) {

        } else if( option == 5) {
            cout <<"1.Find largest value of BST"<<endl
                 <<"2.Find smallest value of BST"<<endl;
                 int option1;
                 cin >> option1;
                 if( option1 == 1 )cout << tree -> findMax()<< " is the largest value" << endl;
                 else if( option1 == 2 )cout << tree -> findMin()<< " is the smallest value" << endl;
        } else if( option == 0)break;
    }

}
