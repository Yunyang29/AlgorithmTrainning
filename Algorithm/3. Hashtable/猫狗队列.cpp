// Date: 25/05/15
//
// 实现一种狗猫队列的结构，要求如下：
// ● 用户可以调用add方法将cat类或dog类的实例放入队列中；
// ● 用户可以调用pollAll方法，将队列中所有的实例按照进队列的先后顺序依次弹出；
// ● 用户可以调用pollDog方法，将队列中dog类的实例按照进队列的先后顺序依次弹出；
// ● 用户可以调用pollCat方法，将队列中cat类的实例按照进队列的先后顺序依次弹出；
// ● 用户可以调用isEmpty方法，检查队列中是否还有dog或cat的实例；
// ● 用户可以调用isDogEmpty方法，检查队列中是否有dog类的实例；
// ● 用户可以调用isCatEmpty方法，检查队列中是否有cat类的实例。

#include <iostream>
#include <queue>
#include "..\Header\Queue&Stack.h" 

using namespace Queue_Stack;

void CatAndDogQueue::add(string type)
{
	Animal* animal = new Animal();
	animal->type = type;
	animal->order = orderCounter++;

	if (type == "dog") {
		dogQueue.push(animal);
	}
	else if (type == "cat") {
		catQueue.push(animal);
	}
	else {
		cout << "Unknown animal type: " << type << endl;
		delete animal; // Clean up if the type is unknown
	}
}

CatAndDogQueue::Animal* CatAndDogQueue::pollAll()
{
	if (dogQueue.empty() && catQueue.empty()) {
		return nullptr;
	}

	if (dogQueue.empty()) {
		return pollCat();
	}
	else if (catQueue.empty()) {
		return pollDog();
	}

	if (dogQueue.front()->order < catQueue.front()->order) {
		return pollDog();
	}
	else {
		return pollCat();
	}
}

CatAndDogQueue::Animal* CatAndDogQueue::pollDog()
{
	if (!dogQueue.empty()) {
		Animal* dog = dogQueue.front();
		dogQueue.pop();
		return dog; // Return the dog
	}
	else {
		cout << "No dogs in the queue." << endl;
		return nullptr; // No dogs to poll
	}
}

CatAndDogQueue::Animal* CatAndDogQueue::pollCat()
{
	if (!catQueue.empty()) {
		Animal* cat = catQueue.front();
		catQueue.pop();
		return cat; // Return the cat
	}
	else {
		cout << "No cats in the queue." << endl;
		return nullptr; // No cats to poll
	}
}

bool  CatAndDogQueue::isEmpty()
{
	return dogQueue.empty() && catQueue.empty();
}

bool  CatAndDogQueue::isDogEmpty()
{
	return dogQueue.empty();
}

bool  CatAndDogQueue::isCatEmpty()
{
	return catQueue.empty();
}