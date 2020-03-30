#include "HealthManager.h"

HealthManager::HealthManager()
{
}

HealthManager::~HealthManager()
{
}
HealthManager* HealthManager::sInstance = nullptr;

HealthManager* HealthManager::Instance()
{
	if (sInstance == nullptr)
	{
		sInstance = new HealthManager();
	}
	return sInstance;

}

void HealthManager::Release()
{
	delete sInstance;
	sInstance = nullptr;

}
