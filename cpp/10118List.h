typedef int Item;
class List{
private:
	int index;
	int size;
	Item* items;
public:
	List(int size);
	~List();
	void Add(const Item& item);
	bool IsFull() const;
	bool IsEmpty() const;
	void Visit(void (*pf)(Item& item));
	const Item Get(int i) const;
	int Length() const;
};