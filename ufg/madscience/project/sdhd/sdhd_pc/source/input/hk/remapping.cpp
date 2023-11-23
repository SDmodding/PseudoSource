// File Line: 22
// RVA: 0x41F3B0
void __fastcall UFG::SaveKeyboardRemap(UFG *this)
{
  __int64 i; // rsi
  UFG::Controller *v2; // rcx
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *mNext; // rbx
  UFG::qList<UFG::ActionRemapInfo,UFG::ActionRemapInfo,1,0> *j; // rbp
  UFG::qSymbol *v5; // rdi
  UFG::GameStatTracker *v6; // rax
  UFG::qWiseSymbol result; // [rsp+30h] [rbp+8h] BYREF

  for ( i = 0i64; i < 5; ++i )
  {
    v2 = UFG::gInputSystem->mControllers[i];
    if ( v2 )
    {
      if ( v2->m_IsKeyboardController )
      {
        mNext = v2->mRemappableActions.mNode.mNext;
        for ( j = &v2->mRemappableActions;
              mNext != (UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *)j;
              mNext = mNext->mNext )
        {
          v5 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, (unsigned int)mNext[2].mNext);
          v6 = UFG::GameStatTracker::Instance();
          UFG::GameStatTracker::SetStat(v6, KeyboardMapping, v5, (int)mNext[3].mPrev);
        }
      }
    }
  }
}

// File Line: 41
// RVA: 0x41F300
void __fastcall UFG::LoadKeyboardRemap(UFG *this)
{
  __int64 i; // r14
  UFG::Controller *v2; // rbp
  UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *j; // rbx
  UFG::qSymbol *v4; // rdi
  UFG::GameStatTracker *v5; // rax
  int Stat; // eax
  UFG::qWiseSymbol result; // [rsp+40h] [rbp+8h] BYREF

  for ( i = 0i64; i < 5; ++i )
  {
    v2 = UFG::gInputSystem->mControllers[i];
    if ( v2 && v2->m_IsKeyboardController )
    {
      for ( j = v2->mRemappableActions.mNode.mNext;
            j != (UFG::qNode<UFG::ActionRemapInfo,UFG::ActionRemapInfo> *)&v2->mRemappableActions;
            j = j->mNext )
      {
        v4 = (UFG::qSymbol *)UFG::qSymbol::qSymbol(&result, (unsigned int)j[2].mNext);
        v5 = UFG::GameStatTracker::Instance();
        Stat = UFG::GameStatTracker::GetStat(v5, KeyboardMapping, v4);
        if ( Stat )
          LODWORD(j[3].mPrev) = Stat;
      }
      UFG::Controller::ApplyRemapList(v2);
    }
  }
}

