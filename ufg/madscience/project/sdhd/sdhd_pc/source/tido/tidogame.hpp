// File Line: 53
// RVA: 0x5936A0
void __fastcall UFG::TidoGame::TidoGame(UFG::TidoGame *this)
{
  UFG::TiDo::TiDo(this);
  this->vfptr = (UFG::TiDoVtbl *)&UFG::TidoGame::`vftable;
  this->m_loadingBankName.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  this->m_loadingEventName.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
}

