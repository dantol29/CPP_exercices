template <class T>
class MutantStack{
	public:
		MutantStack();
		MutantStack(const MutantStack& obj);
		MutantStack& operator=(const MutantStack& obj);
		~MutantStack();
		unsigned int size() const;
		bool empty() const;
		T& top() const;
		void pop();
		void push(const T& element);
		void emplace(const T& element); // constructs an object before placing
		void swap(T& obj); // swap stacks
	private:
		unsigned int _size;
};
