#include "Entity.hpp"

class EnemySpawner : public Entity
{
	private:
	float spawnCooldown = INITIAL_SPAWN_TIME;
	protected:
		bool HasCollisions() override {return false;}

	public:
	explicit EnemySpawner() : Entity({0,0}, NULL) {}
	void Update(GameState& state) override;
};

class ChestSpawner : public Entity
{
	protected:
		bool HasCollisions() override {return false;}

	public:
	explicit ChestSpawner() : Entity({0,0}, NULL) {}
	void Update(GameState& state) override;
};