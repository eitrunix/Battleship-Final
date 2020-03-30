#pragma once
class HealthManager
{

private:
	static HealthManager* sInstance;
	HealthManager* mHealthManager;

public:
	HealthManager();
	~HealthManager();
	static HealthManager* Instance();
	static void Release();

};

