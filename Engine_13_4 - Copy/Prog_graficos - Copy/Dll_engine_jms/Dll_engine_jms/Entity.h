#ifndef ENTITY_H
#define ENTITY_H
#include"EngineApi.h"
#include<string>
#include<iostream>

class ENGINE_API Entity
{
public:
	Entity();
//~Entity();
	
	virtual std::string GetName();
	virtual void SetName(std::string _name);

	virtual void Update();
	
	virtual void Draw();


private:
	std::string name;
};


#endif // !ENTITY_H
