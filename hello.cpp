#include <iostream>
#include <string>
#include <vector>
#include <lib_functions.h>

using namespace std; 

enum class Color {Red, Green, Blue};
enum class Size {Small, Medium, Large};

struct Product{
	string name;
	Color color;
	Size size;
};

typedef vector<Product*> Items;

struct ProductFilter{
	
	static Items by_color(Items items, Color color){
		Items result;
		for (auto& i : items)
			if (i->color == color)
				result.push_back(i);
		return result;
	}

	static Items by_size(Items items, Size size){
		Items result;
		for (auto& i : items)
			if (i->size == size)
				result.push_back(i);
		return result;
	}
};

template <typename T> struct ISpecification{
	virtual bool is_satisfied(T* item) = 0;
};

template <typename T> struct IFilter{
	virtual vector<T*> filter(vector<T*> items, ISpecification<T>& spec) = 0;
};

struct BetterFilter : IFilter<Product>{
	vector<Product*> filter(vector<Product*> items, ISpecification<Product>& spec) override{
		Items result;
		for (auto& p: items)
			if (spec.is_satisfied(p))
				result.push_back(p);
		return result;
	};
};

struct ColorSpecification : ISpecification<Product>{	
	Color color;

	explicit ColorSpecification(const Color color) : color{color}{
	}

	bool is_satisfied(Product* item) override{
		return item->color == color;
	}
};

int main(){
	cout << "Hello World this is a change." << endl;
	cout << "This is a second test" << endl;
	say_hello();

	cout << "--- Open Closed Principle ---" << endl;

	Product p = Product();
	ProductFilter pf = ProductFilter();

	Items items = Items();
	Color color = Color::Red;
	//items.push_back(Product(string("product1"), Color::Green, Size::Small));
	
	auto results = pf.by_color(items, color);

	Product apple{"Apple", Color::Green, Size::Small};
	Product tree{"Tree", Color::Blue, Size::Large};
	Product car{"Car", Color::Red, Size::Small};
	Product leaf{"A Leaf", Color::Green, Size::Small};

	vector<Product*> all{&apple, &tree, &car, &leaf};
	BetterFilter bf;
	ColorSpecification green_spec(Color::Green);
	
	auto green_things = bf.filter(all, green_spec);
	for (auto& thing: green_things)
		cout << thing->name << " is green." << endl;
}



