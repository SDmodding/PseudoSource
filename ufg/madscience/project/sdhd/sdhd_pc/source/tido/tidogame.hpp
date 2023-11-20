// File Line: 53
// RVA: 0x5936A0
void __fastcall UFG::TidoGame::TidoGame(UFG::TidoGame *this)
{
  UFG::TidoGame *v1; // rbx

  v1 = this;
  UFG::TiDo::TiDo((UFG::TiDo *)&this->vfptr);
  v1->vfptr = (UFG::TiDoVtbl *)&UFG::TidoGame::`vftable;
  v1->m_loadingBankName.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
  v1->m_loadingEventName.mUID = -1;
  _((AMD_HD3D *)0xFFFFFFFFi64);
}

