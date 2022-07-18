#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

class Car {
public:
	virtual void func() = 0;
	virtual void addCar(Car* p) {
		assert(false);
	}
	virtual ~Car() {}

	void setWeight(int weight) {
		this->weight_ = weight;
	}

	int getWeight() {
		return this->weight_;
	}

private:
	int weight_ = 0;

};

// Создаём класс коллекции машин.
class CarCollection {
public:
	//virtual ~CarCollection() = default;
	virtual ~CarCollection() {
		for (auto&& car : data_) {
			delete car;
		}
	}

	// Для управления коллекцией. Временем жизни машин. Во всех остальных случаях деструктор не пишем.
	void* insert(Car * car) {
		data_.push_back(car);
	}

	// Создаём ссылку на указатель (чтобы занимало меньше памяти)
	(Car*&) operator[] (int i) {
		return data_[i];
	}

private:
	std::vector<Car*> data_;
};

class LightCar : public Car {
public:


private:
	std::string mark_ = "";

};

class BigCar : public Car {
public:
	int getWeigth() {
		int total = 0;
		for (int i = 0; i < coll1.size(); ++i)
			total += coll1[i]->getWeight();
		return total;
	}

	void addCar(Car* p) {
		coll1.push_back(p);
	}
	~BigCar() {
		for (int i = 0; i < coll1.size(); ++i) {
			delete& coll1;
		}
	}


private:
	// Вектор указателей на абстрактный класс Car
	std::vector<Car*> coll1;
};



int main() {

	using namespace std;

	vector<CarCollection> coll1;

	//BigCar* myBigCar = new BigCar;
	//for (int i = 0; i < 5; ++i)
	//	myBigCar->addCar(createCar());

	//cout << "My car weigth is "
	//	<< myBigCar->getWeigth() << endl;

	//delete myBigCar;

	return 0;
}