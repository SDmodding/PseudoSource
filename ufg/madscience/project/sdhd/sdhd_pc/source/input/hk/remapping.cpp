// File Line: 22
// RVA: 0x41F3B0
void __fastcall UFG::SaveKeyboardRemap(UFG *this)
{
  signed __int64 v1; // rsi
  UFG::Controller *v2; // rcx
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *v3; // rbx
  signed __int64 i; // rbp
  UFG::qSymbol *v5; // rdi
  UFG::GameStatTracker *v6; // rax
  UFG::qWiseSymbol result; // [rsp+30h] [rbp+8h]

  v1 = 0i64;
  do
  {
    v2 = UFG::gInputSystem->mControllers[v1];
    if ( v2 )
    {
      if ( v2->m_IsKeyboardController )
      {
        v3 = v2->mRemappableActions.mNode.mNext;
        for ( i = (signed __int64)&v2->mRemappableActions;
              v3 != (UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *)i;
              v3 = v3->mNext )
        {
          v5 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, (unsigned int)v3[2].mNext);
          v6 = UFG::GameStatTracker::Instance();
          UFG::GameStatTracker::SetStat(v6, KeyboardMapping, v5, (int)v3[3].mPrev);
        }
      }
    }
    ++v1;
  }
  while ( v1 < 5 );
}

// File Line: 41
// RVA: 0x41F300
void __fastcall UFG::LoadKeyboardRemap(UFG *this)
{
  signed __int64 v1; // r14
  UFG::Controller *v2; // rbp
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *i; // rbx
  UFG::qSymbol *v4; // rdi
  UFG::GameStatTracker *v5; // rax
  int v6; // eax
  UFG::qWiseSymbol result; // [rsp+40h] [rbp+8h]

  v1 = 0i64;
  do
  {
    v2 = UFG::gInputSystem->mControllers[v1];
    if ( v2 && v2->m_IsKeyboardController )
    {
      for ( i = v2->mRemappableActions.mNode.mNext;
            i != (UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *)&v2->mRemappableActions;
            i = i->mNext )
      {
        v4 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, (unsigned int)i[2].mNext);
        v5 = UFG::GameStatTracker::Instance();
        v6 = UFG::GameStatTracker::GetStat(v5, KeyboardMapping, v4);
        if ( v6 )
          LODWORD(i[3].mPrev) = v6;
      }
      UFG::Controller::ApplyRemapList(v2);
    }
    ++v1;
  }
  while ( v1 < 5 );
}

