#include "sample.h"

#include <base/color.h>

#include <engine/shared/config.h>

#include <generated/protocol.h>

#include <game/mapitems.h>
#include <game/server/entities/character.h>
#include <game/server/entities/ddnet_pvp/vanilla_pickup.h>
#include <game/server/gamemodes/base_pvp/base_pvp.h>

void CExtGameControllerSample::OnCreditsChatCmd(IConsole::IResult *pResult, void *pUserData)
{
	static constexpr const char *CREDITS[] = {
		"My custom sample mode!",
		"For more information see /credits_insta",
	};
	for(const char *pLine : CREDITS)
		GameServer()->Console()->Print(IConsole::OUTPUT_LEVEL_STANDARD, "chatresp", pLine);
}

CExtGameControllerSample::CExtGameControllerSample(CGameContext *pGameServer) :
	CGameControllerVanilla(pGameServer)
{
	m_pGameType = "sample";
	m_GameFlags = 0;
	m_DefaultWeapon = WEAPON_GUN;
	m_pStatsTable = "sample";
	m_pExtraColumns = nullptr;
	m_pSqlStats->SetExtraColumns(m_pExtraColumns);
	m_pSqlStats->CreateTable(m_pStatsTable);
}

CExtGameControllerSample::~CExtGameControllerSample() = default;

void CExtGameControllerSample::OnCharacterSpawn(class CCharacter *pChr)
{
	CGameControllerPvp::OnCharacterSpawn(pChr);

	// give default weapons
	pChr->GiveWeapon(WEAPON_GUN, false, 10);
	pChr->GiveWeapon(WEAPON_HAMMER, false, -1);

	// crazy sample mode has infinite grenade watafak
	pChr->GiveWeapon(WEAPON_GRENADE, false, -1);
}

REGISTER_GAMEMODE(sample, CExtGameControllerSample(pGameServer));
