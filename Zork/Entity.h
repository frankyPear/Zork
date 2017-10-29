#include <list>
enum typeEnt
{
	ITEMZONE,
	ITEMINVENTORY
};
class Entity
{
public:
	Entity();
	~Entity();

private:

public:
	Entity* ent;
	//<Entity*> Pack;
	typeEnt type;

};

Entity::Entity()
{
}

Entity::~Entity()
{
}