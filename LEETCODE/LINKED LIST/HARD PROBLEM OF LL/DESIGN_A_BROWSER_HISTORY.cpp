/*
browser(homepage) => creates New LL with homepage as head
visit(url) => creates a newNode attached next to currentPage
back(steps) => goes back "steps" Nodes from currentNode
forward(steps) => goes ahead "steps" Nodes from currentNode

We need to use DLL here as we need back and forward functionalities
*/

class Node{
  public:
    Node* prev;
    Node* next;
    string url;
    Node(string page){
        url = page;
        prev = nullptr;
        next = nullptr;
    }
    Node(string page, Node* prevNode, Node* nextNode){
        url = page;
        prev = prevNode;
        next = nextNode;
    }
}
class Browser{
    Node* currentPage;
  public:
    
    Browser(string& homePage){
        currentPage = new Node(homePage);
    }

    void visit(string& page){
        Node* newNode = new Node(page, currentPage, nullptr);
        currentPage = newNode;
    }

    string back(int steps){
        while(steps>0 && currentPage->prev){
            currentPage = currentPage->prev;
            steps--;
        }
        return currentPage->url;
    }

    string forward(int steps){
        while(steps>0 && currentPage->next){
            currentPage = currentPage->next;
            steps--;
        }
        return currentPage->url;
    }

}