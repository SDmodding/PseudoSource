// File Line: 62
// RVA: 0x4ED740
void __fastcall UFG::TSLockpicking::MthdC_set_difficulty(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  UFG::UIHKScreenPickLockMinigame::m_iDifficulty = (*pScope->i_data.i_array_p)->i_data_p->i_user_data;
}

// File Line: 77
// RVA: 0x4E9BE0
void __fastcall UFG::TSLockpicking::MthdC_is_successful(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(UFG::UIHKScreenPickLockMinigame::m_bWon);
}

