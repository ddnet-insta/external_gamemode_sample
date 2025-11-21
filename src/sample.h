#pragma once

#include <game/server/gamemodes/vanilla/base_vanilla.h>

class CGameContext;
class CCharacter;

class CExtGameControllerSample : public CGameControllerVanilla
{
public:
	CExtGameControllerSample(CGameContext *pGameServer);
	~CExtGameControllerSample() override;

	void OnCreditsChatCmd(IConsole::IResult *pResult, void *pUserData) override;
	void OnCharacterSpawn(CCharacter *pChr) override;
};
