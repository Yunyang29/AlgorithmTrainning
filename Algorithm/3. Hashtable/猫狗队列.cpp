// Date: 25/05/15
//
// ʵ��һ�ֹ�è���еĽṹ��Ҫ�����£�
// �� �û����Ե���add������cat���dog���ʵ����������У�
// �� �û����Ե���pollAll�����������������е�ʵ�����ս����е��Ⱥ�˳�����ε�����
// �� �û����Ե���pollDog��������������dog���ʵ�����ս����е��Ⱥ�˳�����ε�����
// �� �û����Ե���pollCat��������������cat���ʵ�����ս����е��Ⱥ�˳�����ε�����
// �� �û����Ե���isEmpty���������������Ƿ���dog��cat��ʵ����
// �� �û����Ե���isDogEmpty���������������Ƿ���dog���ʵ����
// �� �û����Ե���isCatEmpty���������������Ƿ���cat���ʵ����

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