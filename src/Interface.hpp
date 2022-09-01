#ifndef _INTERFACE_H
#define _INTERFACE_H

template <typename E>
class Interface {
public:
    /**
     * @brief Construct a new Interface object with default capacity of 1000.
     * 
     */
    Interface() {
        _capacity = 1000;
    };

    /**
     * @brief Construct a new Interface object with the specified capacity.
     * 
     * @param capacity the initial capacity of the object.
     */
    Interface(int capacity) {
        _capacity = capacity;
    };

    /**
     * @brief Destroy the Interface object and sets the capacity and size to 0.
     * 
     */
    ~Interface() {
        _capacity = 0;
        _size = 0;
    };

    /**
     * @brief Adds an element to the container.
     * 
     * Adds an element to the container in the order determined by the implementing class.
     * If capacity is full it increases capcity determined by the implmenting class.
     * The size is increases by 1.
     * 
     * @param value the value to add to the container.
     */
    virtual void add(E value) = 0;

    /**
     * @brief Removes and returns an element from the container.
     * 
     * Removes and returns an element from the container.
     * Which element is returned depends on the implementing class.
     * Also decrements the size.
     * 
     * @throws std::out-of-range if the container is empty,
     * this method throws out-of-range exception.
     * 
     * @return E the element that was removed.
     */
    virtual E get() = 0;
    
    /**
     * @brief Checks if the container is empty.
     * 
     * @return true if the container is empty.
     * @return false otherwise.
     */
    bool isEmpty() {
        return _size == 0;
    };

    /**
     * @brief Returns the number of elements stored in the container.
     * 
     * @return int the number of elements stored in the container.
     */
    int size() {
        return _size;
    };

    /**
     * @brief Returns the capacity of the container.
     * 
     * @return int the capacity of the container.
     */
    int capacity() {
        return _capacity;
    }
    
protected:
    int _size = 0;
    int _capacity = 0;
};

#endif