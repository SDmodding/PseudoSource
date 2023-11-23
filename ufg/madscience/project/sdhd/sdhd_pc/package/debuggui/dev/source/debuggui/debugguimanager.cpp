// File Line: 43
// RVA: 0xBAB70
void __fastcall UFG::DebugGUIManager::DebugGUIManager(UFG::DebugGUIManager *this)
{
  Render::FontHandle *p_mMenuFontHandle; // rdi
  unsigned int v3; // esi
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v5; // rax

  this->mGUIObjects.mNode.mPrev = &this->mGUIObjects.mNode;
  this->mGUIObjects.mNode.mNext = &this->mGUIObjects.mNode;
  p_mMenuFontHandle = &this->mMenuFontHandle;
  UFG::qResourceHandle::qResourceHandle(&this->mMenuFontHandle);
  this->mMousePos = 0i64;
  *(_QWORD *)&this->mMouseButtons = 0i64;
  *(_QWORD *)&this->mMenuItemCheckWidth = 0i64;
  v3 = UFG::qStringHash32("GUIMenu", 0xFFFFFFFF);
  Inventory = `UFG::qGetResourceInventory<Render::Font>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::Font>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v5, 0x69FCCB4Cu);
    `UFG::qGetResourceInventory<Render::Font>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Init(p_mMenuFontHandle, 0x69FCCB4Cu, v3, Inventory);
}

// File Line: 48
// RVA: 0xBAD50
UFG::DebugGUIManager *__fastcall UFG::DebugGUIManager::Instance()
{
  if ( (_S1_15 & 1) == 0 )
  {
    _S1_15 |= 1u;
    UFG::DebugGUIManager::DebugGUIManager(&sDebugGUIManager);
    atexit(UFG::DebugGUIManager::Instance_::_2_::_dynamic_atexit_destructor_for__sDebugGUIManager__);
  }
  UFG::DebugGUIManager::mspInstance = &sDebugGUIManager;
  return &sDebugGUIManager;
}

// File Line: 83
// RVA: 0xBADE0
void __fastcall UFG::DebugGUIManager::PostUpdate(UFG::DebugGUIManager *this, float fRealTimeDelta)
{
  bool *p_mIsActive; // rbp
  UFG::DebugGUIManager *p_mNext; // rbx
  __int64 v5; // rdi
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *mNext; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rax

  this->mIsActive = 0;
  p_mIsActive = &this[-1].mIsActive;
  p_mNext = (UFG::DebugGUIManager *)&this->mGUIObjects.mNode.mNext[-1].mNext;
  if ( p_mNext != (UFG::DebugGUIManager *)&this[-1].mIsActive )
  {
    do
    {
      v5 = (__int64)&p_mNext->mMenuFontHandle.mPrev[-1].mNext;
      if ( ((unsigned __int8 (__fastcall *)(UFG::DebugGUIManager *))p_mNext->mGUIObjects.mNode.mPrev[6].mPrev)(p_mNext) )
        ((void (__fastcall *)(UFG::DebugGUIManager *))p_mNext->mGUIObjects.mNode.mPrev->mNext)(p_mNext);
      if ( ((unsigned __int8 (__fastcall *)(UFG::DebugGUIManager *))p_mNext->mGUIObjects.mNode.mPrev[6].mPrev)(p_mNext) )
      {
        this->mIsActive = 1;
      }
      else if ( ((unsigned __int8 (__fastcall *)(UFG::DebugGUIManager *))p_mNext->mGUIObjects.mNode.mPrev[7].mPrev)(p_mNext) )
      {
        mNext = p_mNext->mGUIObjects.mNode.mNext;
        mPrev = p_mNext->mMenuFontHandle.mPrev;
        mNext->mNext = (UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *)mPrev;
        mPrev->mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)mNext;
        p_mNext->mGUIObjects.mNode.mNext = (UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *)&p_mNext->mGUIObjects.mNode.mNext;
        p_mNext->mMenuFontHandle.mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&p_mNext->mGUIObjects.mNode.mNext;
        ((void (__fastcall *)(UFG::DebugGUIManager *, __int64))p_mNext->mGUIObjects.mNode.mPrev->mPrev)(p_mNext, 1i64);
      }
      p_mNext = (UFG::DebugGUIManager *)v5;
    }
    while ( (bool *)v5 != p_mIsActive );
  }
}

// File Line: 118
// RVA: 0xBADA0
signed __int64 __fastcall UFG::DebugGUIManager::MapMouseButton(char vkey)
{
  switch ( vkey )
  {
    case 1:
      return 1i64;
    case 2:
      return 2i64;
    case 4:
      return 4i64;
    case 5:
      return 8i64;
    case 6:
      return 16i64;
  }
  return 0i64;
}

// File Line: 133
// RVA: 0xBAEB0
void __fastcall UFG::DebugGUIManager::Update(UFG::DebugGUIManager *this, float fRealTimeDelta)
{
  UFG::Controller *v3; // rdx
  bool *p_mIsActive; // rdi
  __int64 p_mInputMessages; // rsi
  UFG::InputState *p_mPreviousInputState; // rdx
  UFG::InputState *p_Dst; // rcx
  __int64 v9; // rax
  __int128 v10; // xmm0
  __int128 v11; // xmm1
  __int128 v12; // xmm0
  __int128 v13; // xmm1
  __int128 v14; // xmm0
  __int128 v15; // xmm1
  __int128 v16; // xmm0
  __int128 v17; // xmm1
  __int64 v18; // rax
  UFG::InputMKeys ModiferKeys; // r14d
  unsigned int MouseButtons; // eax
  __int64 v21; // r12
  unsigned int v22; // r15d
  unsigned int v23; // esi
  int RepeatCount; // eax
  int v25; // r10d
  int v26; // r8d
  int v27; // r9d
  int v28; // ebp
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **i; // rbx
  __int64 v30; // r9
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **j; // rbx
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **k; // rbx
  bool v33; // bp
  unsigned int v34; // esi
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **m; // rbx
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **n; // rbx
  unsigned int v37; // eax
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **p_mNext; // rbx
  unsigned int ii; // esi
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **jj; // rbx
  __int64 v41; // r8
  UFG::InputState Dst; // [rsp+30h] [rbp-178h] BYREF
  int v43; // [rsp+1C0h] [rbp+18h] BYREF
  int v44; // [rsp+1C4h] [rbp+1Ch]
  __int64 v45; // [rsp+1C8h] [rbp+20h]

  v3 = UFG::gInputSystem->mControllers[0];
  if ( v3 )
  {
    p_mIsActive = &this[-1].mIsActive;
    if ( (bool *)&this->mGUIObjects.mNode.mNext[-1].mNext != &this[-1].mIsActive && !v3->m_IsKeyboardController )
    {
      p_mInputMessages = (__int64)&v3->mInputMessages;
      p_mPreviousInputState = &v3->mPreviousInputState;
      p_Dst = &Dst;
      v45 = p_mInputMessages;
      if ( (((unsigned __int8)&Dst | (unsigned __int8)p_mPreviousInputState) & 0xF) != 0 )
      {
        memmove(&Dst, p_mPreviousInputState, 0x118ui64);
      }
      else
      {
        v9 = 2i64;
        do
        {
          v10 = *(_OWORD *)&p_mPreviousInputState->mLastMouseXYTime;
          v11 = *(_OWORD *)&p_mPreviousInputState->mPrevMouseY;
          p_Dst = (UFG::InputState *)((char *)p_Dst + 128);
          p_mPreviousInputState = (UFG::InputState *)((char *)p_mPreviousInputState + 128);
          *(_OWORD *)&p_Dst[-1].mKeyState[132] = v10;
          v12 = *(_OWORD *)&p_mPreviousInputState[-1].mKeyState[164];
          *(_OWORD *)&p_Dst[-1].mKeyState[148] = v11;
          v13 = *(_OWORD *)&p_mPreviousInputState[-1].mKeyState[180];
          *(_OWORD *)&p_Dst[-1].mKeyState[164] = v12;
          v14 = *(_OWORD *)&p_mPreviousInputState[-1].mKeyState[196];
          *(_OWORD *)&p_Dst[-1].mKeyState[180] = v13;
          v15 = *(_OWORD *)&p_mPreviousInputState[-1].mKeyState[212];
          *(_OWORD *)&p_Dst[-1].mKeyState[196] = v14;
          v16 = *(_OWORD *)&p_mPreviousInputState[-1].mKeyState[228];
          *(_OWORD *)&p_Dst[-1].mKeyState[212] = v15;
          v17 = *(_OWORD *)&p_mPreviousInputState[-1].mKeyState[244];
          *(_OWORD *)&p_Dst[-1].mKeyState[228] = v16;
          *(_OWORD *)&p_Dst[-1].mKeyState[244] = v17;
          --v9;
        }
        while ( v9 );
        v18 = *(_QWORD *)&p_mPreviousInputState->mPrevMouseY;
        *(_OWORD *)&p_Dst->mLastMouseXYTime = *(_OWORD *)&p_mPreviousInputState->mLastMouseXYTime;
        *(_QWORD *)&p_Dst->mPrevMouseY = v18;
      }
      ModiferKeys = UFG::InputState::GetModiferKeys(&Dst);
      MouseButtons = UFG::InputState::GetMouseButtons(&Dst);
      this->mModKeys = ModiferKeys;
      this->mMouseButtons = MouseButtons;
      v21 = *(_QWORD *)(p_mInputMessages + 8);
      v22 = MouseButtons;
      if ( v21 != p_mInputMessages )
      {
        do
        {
          v23 = *(unsigned __int8 *)(v21 + 17);
          RepeatCount = UFG::InputState::GetRepeatCount(&Dst, v23);
          v25 = *(char *)(v21 + 16);
          v26 = *(__int16 *)(v21 + 18);
          v27 = *(__int16 *)(v21 + 20);
          v28 = RepeatCount;
          v43 = v26;
          v44 = v27;
          switch ( v25 )
          {
            case 2:
              for ( i = &this->mGUIObjects.mNode.mNext[-1].mNext;
                    i != (UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **)p_mIsActive;
                    i = &i[2][-1].mNext )
              {
                if ( ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **))(*i)[5].mNext)(i) )
                {
                  LOBYTE(v30) = v28 > 0;
                  if ( ((unsigned __int64 (__fastcall *)(UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **, _QWORD, _QWORD, __int64))(*i)[1].mNext)(
                         i,
                         v23,
                         (unsigned int)ModiferKeys,
                         v30) )
                  {
                    break;
                  }
                }
              }
              break;
            case 3:
              for ( j = &this->mGUIObjects.mNode.mNext[-1].mNext;
                    j != (UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **)p_mIsActive;
                    j = &j[2][-1].mNext )
              {
                if ( ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **))(*j)[5].mNext)(j)
                  && ((unsigned __int64 (__fastcall *)(UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **, _QWORD, _QWORD))(*j)[2].mPrev)(
                       j,
                       v23,
                       (unsigned int)ModiferKeys) )
                {
                  break;
                }
              }
              break;
            case 4:
              if ( this->mMousePos.i_x != v26 || this->mMousePos.i_y != v27 )
              {
                this->mMousePos.i_x = v26;
                this->mMousePos.i_y = v27;
                for ( k = &this->mGUIObjects.mNode.mNext[-1].mNext;
                      k != (UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **)p_mIsActive;
                      k = &k[2][-1].mNext )
                {
                  if ( ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **))(*k)[5].mPrev)(k)
                    && ((unsigned __int64 (__fastcall *)(UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **, int *, _QWORD, _QWORD))(*k)[3].mNext)(
                         k,
                         &v43,
                         v22,
                         (unsigned int)ModiferKeys) )
                  {
                    break;
                  }
                }
              }
              break;
            case 7:
            case 9:
              v33 = v25 == 9;
              v34 = UFG::DebugGUIManager::MapMouseButton(v23);
              if ( !v33 )
              {
                for ( m = &this->mGUIObjects.mNode.mNext[-1].mNext;
                      m != (UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **)p_mIsActive;
                      m = &m[2][-1].mNext )
                {
                  if ( ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **))(*m)[5].mPrev)(m) )
                    ((void (__fastcall *)(UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **, int *))(*m)[4].mNext)(
                      m,
                      &v43);
                }
              }
              for ( n = &this->mGUIObjects.mNode.mNext[-1].mNext;
                    n != (UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **)p_mIsActive;
                    n = &n[2][-1].mNext )
              {
                if ( ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **))(*n)[5].mPrev)(n)
                  && ((unsigned __int64 (__fastcall *)(UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **, int *, _QWORD, bool, unsigned int, UFG::InputMKeys))(*n)[2].mNext)(
                       n,
                       &v43,
                       v34,
                       v33,
                       v22,
                       ModiferKeys) )
                {
                  break;
                }
              }
              break;
            case 8:
              v37 = UFG::DebugGUIManager::MapMouseButton(v23);
              p_mNext = &this->mGUIObjects.mNode.mNext[-1].mNext;
              for ( ii = v37;
                    p_mNext != (UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **)p_mIsActive;
                    p_mNext = &p_mNext[2][-1].mNext )
              {
                if ( ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **))(*p_mNext)[5].mPrev)(p_mNext)
                  && ((unsigned __int64 (__fastcall *)(UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **, int *, _QWORD, _QWORD, UFG::InputMKeys))(*p_mNext)[3].mPrev)(
                       p_mNext,
                       &v43,
                       ii,
                       v22,
                       ModiferKeys) )
                {
                  break;
                }
              }
              break;
            case 10:
              for ( jj = &this->mGUIObjects.mNode.mNext[-1].mNext;
                    jj != (UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **)p_mIsActive;
                    jj = &jj[2][-1].mNext )
              {
                if ( ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **))(*jj)[5].mPrev)(jj)
                  && ((unsigned __int64 (__fastcall *)(UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **, AVec2i *, __int64, _QWORD, UFG::InputMKeys))(*jj)[4].mPrev)(
                       jj,
                       &this->mMousePos,
                       v41,
                       v22,
                       ModiferKeys) )
                {
                  break;
                }
              }
              break;
            default:
              break;
          }
          v21 = *(_QWORD *)(v21 + 8);
        }
        while ( v21 != v45 );
      }
    }
  }
  UFG::DebugGUIManager::PostUpdate(this, fRealTimeDelta);
}

