#include <utility>

#include "Schedule.h"

using namespace std::rel_ops;

Schedule::Node::Node(Course c)
{
    this->data = c;
    this->next = nullptr;
}

//------------------------------------------------------------------------------
Schedule::Schedule()
{
    head = nullptr;
    tail = nullptr;
    totalCredits = 0;
}

/**
 * @todo implement this function (it is simliar to Review 01)
 */
Schedule::Schedule(const Schedule& src)
{
    // Copy the src Linked List **data**
    this->head = nullptr;
    this->tail = nullptr; 
    this->totalCredits = 0;

    Node* srcIt = src.head;

    while (srcIt != nullptr) 
    {
        this->appendNoCheck(srcIt->data);

        srcIt = srcIt->next;
    }
}

/**
 * @todo implement this function (it is similar to Review 01)
 */
Schedule::~Schedule()
{
    Node *temp;                 //pointer to deallocate memory

    while (head != nullptr)     //while loop that makes sure the list is not empty before traversing through the list
    {
        temp = head;            //sets the temp pointer to the head (first) node
        head = head ->next;     //advances the head (first) node to the next node in the list
        delete temp;            //deallocates the memory occupied by temp

        std::cout << "Deletion of Node is processing!" << "\n";
    }

    std::cout << "List was deleted!" << "\n";

    tail = nullptr;             //initilaizes the tail (last) node to nullptr;

    totalCredits = 0;           //sets the node back to zero
}

/**
 * @todo implement this function (it is similar to Review 01)
 */
void Schedule::appendNoCheck(Course course)
{
    Node *newNode;                      //pointer to create a new node
    newNode = new Node(course);                 //creates the new node
    newNode->data = course;             //stores the new info in the newly created node
    newNode->next = nullptr;            //sets the next node of the newNode to nullptr

    if (this->head == nullptr)          //if list is empty, the newly created node will be the head (first) node
    {
        this->head = newNode;           //assign the new node pointer to head (first)
        this->tail = newNode;           //assign the new node pointer to tail (last)
    } 
    else 
    {
        (this->tail)->next = newNode;  //insert newNode after last
        this->tail = newNode;          //make last point to actual last node in the list
    }
    this->totalCredits++;             //increments totalCredits node

    newNode = nullptr;               //makes sure the list cannot be seen esxcept through the linked list
}

/**
 * @todo implement this function
 */
bool Schedule::wouldViolateCreditLimit(Course course) const
{
    // The following line is a placeholder (i.e., enough for the code to
    // compile). Remove it when you start implementing this function.
    return true;
}

/**
 * @todo implement this function
 */
bool Schedule::alreadyInSchedule(Course course) const
{
    // Check if the student is registered
    // for a different section of the same course

    // The following line is a placeholder (i.e., enough for the code to
    // compile). Remove it when you start implementing this function.
    return true;
}

//------------------------------------------------------------------------------
void Schedule::display(std::ostream& outs) const
{
    Node* it = head;

    outs << "  (" << totalCredits << " Total Credits)" << "\n";

    while (it != nullptr) {
        outs << "  - " << (it->data) << "\n";

        it = it->next;
    }
}

//------------------------------------------------------------------------------
Schedule& Schedule::operator=(Schedule rhs)
{
    swap(*this, rhs);

    return *this;
}
