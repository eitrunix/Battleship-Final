#pragma once
struct stPiece
{
	int	PatrolBoatHealth = 2;
	int	SubmarineHealth = 3;
	int	CruiserHealth = 3;
	int AircraftCarrierHealth = 4;
	int BattleshipHealth = 5;

	bool PatrolBoatHit = false;
	bool SubmarineHit = false;
	bool CruiserHit = false;
	bool AircraftCarrierHit = false;
	bool BattleshipHit = false;
}PlayerPiece, AiPiece;


