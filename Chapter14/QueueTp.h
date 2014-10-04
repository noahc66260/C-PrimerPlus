// QueueTp.h -- interface and implementation of the QueueTp class
// This is exercise 3 of chapter 14 in C++ Primer Plus 5e by Stephen Prata

#ifndef QUEUETP_H_
#define QUEUETP_H_

template <typename T>
class QueueTp
{
private:
	struct Node {T value; Node * next; Node * prev;};
	typedef Node * link;
	link head;
	link tail;
	void emptyList();
public:
	QueueTp();
	QueueTp(const QueueTp<T> & q);
	~QueueTp();
	bool enqueue(const T & val);
	bool dequeue(T & val);
	bool isEmpty() const;
	QueueTp<T> & operator=(const QueueTp<T> & q);
};

template <typename T>
QueueTp<T>::QueueTp()
{
	head = NULL;
	tail = NULL;
}

template <typename T>
QueueTp<T>::QueueTp(const QueueTp<T> & q)
{
	link t = q.tail;
	while (t != NULL)
	{
		enqueue(t->value);
		t = t->prev;
	}
}

template <typename T>
QueueTp<T>::~QueueTp()
{
	emptyList();
}

template <typename T>
void QueueTp<T>::emptyList()
{
	link t = head;
	while (t!= NULL && t != tail)
	{
		t = t->next;
		delete t->prev;
	}
	delete t;
	head = NULL;
	tail = NULL;
}

template <typename T>
bool QueueTp<T>::enqueue(const T & val)
{
	link l = new (std::nothrow) Node;
	if (NULL == l)				// no memory available
		return false;
	else if (isEmpty()) 		// no elements in queue
	{
		l->value = val;
		l->next = NULL;
		l->prev = NULL;
		head = l;
		tail = l;
	}
	else 							// at least one element in queue
	{
		l->value = val;
		l->next = head;
		l->prev = NULL;
		head->prev = l;
		head = l;
	}
	return true;
}

template <typename T>
bool QueueTp<T>::dequeue(T & val)
{
	if (isEmpty())				// no elements in queue
		return false;
	else if (head == tail) 	// one element in queue
	{
		val = tail->value;
		delete tail;
		head = tail = NULL;
	}
	else 							// more than one element in queue
	{
		val = tail->value;
		tail = tail->prev;
		delete tail->next;
		tail->next = NULL;
	}
	return true;	
}

template <typename T>
bool QueueTp<T>::isEmpty() const
{
	if (NULL == head && NULL == tail)
		return true;
	else
		return false;
}

template <typename T>
QueueTp<T> & QueueTp<T>::operator=(const QueueTp<T> & q)
{
	if (&q == this)
		return *this;
	emptyList();

	link t = q.tail;
	while (t != NULL)
	{
		enqueue(t->value);
		t = t->prev;
	}
}

#endif



