Name: Cole DiStasio

How it was implemented:
    I chose to use a deque of sf::int16 to make my ring buffer instead of a circular array or vector because it is easier to access both ends of the data structure than using one of the other methods I mentioned. My functions mainly use deque.front(), deque.push_back(), deque.isEmpty() and others included in the class.

What works:
     Everything is working.

Testing:
These are the test cases I wanted to test:
 	  generate std::invalid_argument exception on bad constructor;
 	  don't generate exception on good constructor;
 	  enqueue, dequeue, and peek work;
 	  generate std::runtime_error when calling enqueue on full buffer;
 	  generate std::runtime_error when calling dequeue or peek on empty buffer.
And these are the exceptions I used to test them:
	  std::invalid_argument("RB constructor: capacity must be > 0.");
	  If the constructor is called with a capacity of less than 1.

	  std::runtime_error("enqueue: can't enqueue to a full ring.");
	  When enqueue() is called but the ring buffer has met its capacity already.

	  std::runtime_error("dequeue: can't dequeue from an empty ring.");
	  When dequeue() is called but the ring buffer is empty.

	  std::runtime_error("peek: can't peek at an empty ring.");
	  When peek() is called but the ring buffer is empty.
