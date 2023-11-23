// File Line: 60
// RVA: 0x4E9C40
void __fastcall UFG::TSSafeCracking::MthdC_is_successful(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = SSBoolean::pool_new(UFG::UIHKScreenSafeCrackingMinigame::m_bWon);
}

