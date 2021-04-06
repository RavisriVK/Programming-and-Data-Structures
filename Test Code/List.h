/* Mark Allen Weiss */

#include<iostream>
#include<stdexcept>
using namespace std;

template <typename Object>
class List
{
    private:
        /* struct Node is available to all members of List class*/
        struct Node
        {
            Object data;
            Node *prev;
            Node *next;
            Node(const Object& d=Object(), Node *p=NULL, Node *n=NULL) : data(d), prev(p), next(n)
                {}
        };

    public:
        class const_iterator
        {
            public:
                const_iterator() : current(NULL), theList(NULL)
                    {}

                const Object& operator*() const
                    {return retrieve();}

                const_iterator& operator++()
                {
                    if(theList==NULL || current==NULL)
                        throw "UninitializedIterator";
                    if(current==theList->tail)
                        throw "CannotIncrementEndOfListIterator";
                    current=current->next;
                    return *this;
                }

                const_iterator operator++(int)
                {
                    const_iterator old=*this;
                    ++(*this);
                    return old;
                }

                const_iterator& operator--()
                {
                    assertIsValid();
                    if(current->left==theList->head)
                        throw "CannotDecrementBeginningOfListIterator";
                    current=current->prev;
                    return *this;
                }

                const_iterator operator--(int)
                {
                    const_iterator old=*this;
                    --(*this);
                    return old;
                }

                bool operator== (const const_iterator& rhs) const
                    {return current==rhs.current;}
                bool operator!= (const const_iterator& rhs) const
                    {return !(*this==rhs);}

                protected:
                    Node *current;
                    const List<Object> *theList;

                    Object& retrieve() const
                    {
                        assertIsValid();
                        if(current==theList->tail)
                            throw "IteratorOutOfBoundsException";
                        return current->data;
                    }

                    const_iterator(const List<Object>& lst, Node *p): current(p), theList(&lst)
                        {}

                    void assertIsValid() const
                    {
                        if(theList==NULL || current==NULL || current==theList->head)
                            throw "UninitializedIterator";
                    }

                    friend class List<Object>;
        };

        class iterator : public const_iterator
        {
            public:
                iterator(): const_iterator()
                    {}

                Object& operator*()
                    {return this->retrieve();}
                const Object& operator*() const
                    {return this->const_iterator::operator*();}

                iterator& operator++()
                {
                    if(this->theList==NULL || this->current==NULL)
                        throw "UninitializedIterator";
                    if(this->current==this->theList->tail)
                        throw "CannotIncrementEndOfListIterator";
                    this->current=this->current->next;
                    return *this;
                }

                iterator operator++(int)
                {
                    iterator old=*this;
                    ++(*this);
                    return old;
                }

                iterator& operator--()
                {
                    this->assertIsValid();
                    if(this->current->prev==this->theList->head)
                        throw "CannotDecrementBeginningOfListIterator";
                    this->current=this->current->prev;
                    return *this;
                }

                iterator operator--(int)
                {
                    iterator old=*this;
                    --(*this);
                    return old;
                }

                bool operator== (const iterator& rhs) const
                    {return this->current==rhs.current;}
                bool operator!= (const iterator& rhs) const
                    {return !(*this==rhs);}

            protected:
                iterator(const List<Object>& lst, Node *p): const_iterator(lst, p)
                    {}

                friend class List<Object>;
        };

    public:
        List()
            {init();}
        List(const List& rhs)
        {
            init();
            *this=rhs;
        }
        const List& operator=(const List& rhs)
        {
            if(this!=&rhs)
            {
                clear();
                for(const_iterator itr=rhs.begin(); itr!=rhs.end(); ++itr)
                    push_back(*itr);
            }
            return *this;
        }
        ~List()
        {
            clear();
            delete head;
            delete tail;
        }

        iterator begin()
        {
            iterator itr(*this, head);
            return ++itr;
        }
        const_iterator begin() const
        {
            const_iterator itr(*this, head);
            return ++itr;
        }
        iterator end()
        {
            iterator itr(*this, tail);
            return itr;
        }
        const_iterator end() const
        {
            const_iterator itr(*this, tail);
            return itr;
        }

        int size() const
            {return theSize;}
        bool empty() const
            {return size()==0;}

        void clear()
        {
            while(!empty())
                pop_front();
        }

        Object& front()
            {return *begin();}
        const Object& front() const
            {return *begin();}
        Object& back()
            {return *--end();}
        const Object& back() const
            {return *--end();}
        void push_front(const Object& x)
            {insert(begin(),x);}
        void push_back(const Object& x)
            {insert(end(),x);}
        void pop_front()
            {erase(begin());}
        void pop_back()
            {erase(--end());}

        iterator insert(iterator itr, const Object& x)
        {
            itr.assertIsValid();
            if(itr.theList!=this)
                throw "IteratorMismatchExcpetion";

            Node *p=itr.current;
            theSize++;
            return iterator(*this, p->prev=p->prev->next=new Node(x, p->prev, p));
        }

        iterator erase(iterator itr)
        {
            itr.assertIsValid();
            if(itr.theList!=this)
                throw "IteratorMismatchExcpetion";
            else if(itr.current==this->tail)
                throw "IteratorOutOfBoundsException";

            Node *p=itr.current;
            iterator retVal(*this, p->next);
            p->prev->next=p->next;
            p->next->prev=p->prev;
            delete p;
            theSize--;
            return retVal;
        }

        iterator erase(iterator start, iterator end)
        {
            start.assertIsValid();
            if(start.theList!=this)
                throw "IteratorMismatchExcpetion";
            else if(start.current==this->tail)
                throw "IteratorOutOfBoundsException";

            end.assertIsValid();
            if(end.theList!=this)
                throw "IteratorMismatchExcpetion";
            else if(end.current==this->tail)
                throw "IteratorOutOfBoundsException";

            for(iterator itr=start; itr!=end; itr=erase(itr))
                ;
            return end;
        }

        void print()
        {
            const_iterator end=this->end();
            for(const_iterator i=this->begin(); i!=end; i++)
                std::cout << *i << " ";
            std::cout<<"\n";
        }
    private:
        int theSize;
        Node *head;
        Node *tail;

        void init()
        {
            theSize=0;
            head=new Node;
            tail=new Node;
            head->next=tail; head->prev=NULL; head->data=-1;
            tail->next=NULL; tail->prev=head; tail->data=-2;
        }
};
