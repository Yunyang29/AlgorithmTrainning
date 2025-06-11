// ✔️题目
// 猫狗队列，要求实现一个​​混合队列​​（可以同时存放 Dog 和 Cat 两种类型的对象）
// ✔️思路
// 设计一个新的类PetQueue，包含一个 Pet 对象和一个计数器
// 确保再弹出时通过比较count，按照加入的顺序弹出
// ✔️leetcode

#include <string>
#include <queue> // 添加此头文件以解决错误
#include <iostream>

class _004 {
private:
	class Pet {
	private:
		std::string type;

	public:
		Pet(const std::string& type) : type(type) {}

		std::string getPetType() const {
			return this->type;
		}
	};

	class Dog : public Pet {
	public:
		Dog() : Pet("dog") {}
	};

	class Cat : public Pet {
	public:
		Cat() : Pet("cat") {}
	};

	class PetQueue {
	public:
		Pet* pet;
		int count;
		PetQueue(Pet* pet, int count) : pet(pet), count(count) {}
	};

	std::queue<PetQueue> catQ; // 使用 std::queue
	std::queue<PetQueue> dogQ; // 使用 std::queue
	int count = 0;
public:
	_004() {
		catQ = std::queue<PetQueue>();
		dogQ = std::queue<PetQueue>();
	}

	void add(const Pet& pet) {
		if (pet.getPetType() == "dog") {
			dogQ.push(PetQueue(new Dog(), count));
		}
		else if (pet.getPetType() == "cat") {
			catQ.push(PetQueue(new Cat(), count));
		}
		else {
			std::cout << "error" << std::endl;
		}
		count++;
	}

	void pollAll() {
		if (catQ.empty() && dogQ.empty()) {
			std::cout << "empty" << std::endl;
			return;
		}

		if (catQ.empty()) {
			std::cout << dogQ.front().pet->getPetType() << " ";
			dogQ.pop();
			return;
		}
		
		if (dogQ.empty()) {
			std::cout << catQ.front().pet->getPetType() << " ";
			catQ.pop();
			return;
		}
		
		if (catQ.front().count < dogQ.front().count) {
			std::cout << catQ.front().pet->getPetType() << " ";
			catQ.pop();
		}
		else {
			std::cout << dogQ.front().pet->getPetType() << " ";
			dogQ.pop();
		}

	}

	void pollDog()
	{
		if (!dogQ.empty())
		{
			std::cout << dogQ.front().pet->getPetType() << " ";
			dogQ.pop();
		}
		else
		{
			std::cout << "empty" << std::endl;
		}
	}

	void pollCat()
	{
		if (!catQ.empty())
		{
			std::cout << catQ.front().pet->getPetType() << " ";
			catQ.pop();
		}
		else
		{
			std::cout << "empty" << std::endl;
		}
	}

	void isEmpty()
	{
		if (catQ.empty() && dogQ.empty())
		{
			std::cout << "empty" << std::endl;
		}
		else
		{
			std::cout << "not empty" << std::endl;
		}
	}

	void isDogEmpty()
	{
		if (dogQ.empty())
		{
			std::cout << "dog empty" << std::endl;
		}
		else
		{
			std::cout << "dog not empty" << std::endl;
		}
	}

	void iscatEmpty()
	{
		if (catQ.empty())
		{
			std::cout << "cat empty" << std::endl;
		}
		else
		{
			std::cout << "cat not empty" << std::endl;
		}
	}

	void test() {
		Pet dog1("dog");
		Pet dog2("dog");
		Pet cat1("cat");
		Pet cat2("cat");
		add(dog1);
		add(cat1);
		add(dog2);
		add(cat2);
		std::cout << "All pets: ";
		pollAll();
		std::cout << std::endl;
		std::cout << "Poll dog: ";
		pollDog();
		std::cout << std::endl;
		std::cout << "Poll cat: ";
		pollCat();
		std::cout << std::endl;
		isEmpty();
	}
};