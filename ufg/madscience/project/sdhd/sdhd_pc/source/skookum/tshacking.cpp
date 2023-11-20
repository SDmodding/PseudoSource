// File Line: 64
// RVA: 0x4E9B80
void __fastcall UFG::TSHacking::MthdC_is_successful(SSInvokedMethod *pScope, SSInstance **ppResult)
{
  if ( ppResult )
    *ppResult = (SSInstance *)SSBoolean::pool_new(UFG::UIHKScreenHackingMinigame::m_bWon);
}

