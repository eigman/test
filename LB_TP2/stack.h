struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr){}
    Stack(int value) : top(new Node(value)){}
    Stack(const Stack& other);
    ~Stack();

    void push(int value = 1);
    int pop();
    
    friend bool operator!(const Stack& stack);

    friend void operator++(Stack& stack);   
    friend void operator++(Stack& stack, int); 
    void operator--();
    void operator--(int);


    void display() const; 
};
