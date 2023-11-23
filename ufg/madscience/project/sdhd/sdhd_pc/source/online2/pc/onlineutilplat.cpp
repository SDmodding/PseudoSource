// File Line: 30
// RVA: 0xA40610
char __fastcall UFG::OnlineUtil::ShowGamerCard(UFG::OnlineId *id, __int64 a2)
{
  __int64 v3; // rax
  UFG::Controller *v4; // rcx

  v3 = SteamFriends(id, a2);
  (*(void (__fastcall **)(__int64, const char *, CSteamID::SteamID_t))(*(_QWORD *)v3 + 184i64))(
    v3,
    "stats",
    id->m_SteamId.m_steamid);
  v4 = UFG::gInputSystem->mControllers[0];
  if ( v4 )
    UFG::InputState::Clear(&v4->mInputState);
  return 1;
}

