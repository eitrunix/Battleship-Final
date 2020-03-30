#pragma once
class PlayerManager
{

private:
	static PlayerManager* sInstance;
	PlayerManager* mPlayerManager;

public:
	PlayerManager();
	~PlayerManager();
	static PlayerManager* Instance();
	static void Release();

};

