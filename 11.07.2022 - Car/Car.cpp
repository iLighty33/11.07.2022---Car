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

private:


};

class LightCar : public Car {
public:
	void setWeight(int weight) {
		this->weight_ = weight;
	}

	int getWeight() {
		return this->weight_;
	}

private:
	std::string mark_ = "";
	int weight_ = 0;
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
		for (int i = 0; i < coll1.size(); ++i)
			delete coll1.size();
	}


private:
	std::vector<Car*> coll1;
};

BigCar* createCar() {
	BigCar* myBigCar = new BigCar;

	for (int i = 0; i < 100; ++i)
		myBigCar->addCar(new LightCar);

	return BigCar;
}

int main() {

	using namespace std;

	BigCar* myBigCar = new BigCar;
	for (int i = 0; i < 5; ++i)
		myBigCar->addCar(createCar());

	cout << "My car weigth is "
		<< myBigCar->getWeigth() << endl;

	delete myBigCar;

	return 0;
}