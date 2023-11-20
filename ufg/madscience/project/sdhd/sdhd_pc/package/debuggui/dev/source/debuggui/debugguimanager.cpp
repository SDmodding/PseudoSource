// File Line: 43
// RVA: 0xBAB70
void __fastcall UFG::DebugGUIManager::DebugGUIManager(UFG::DebugGUIManager *this)
{
  UFG::DebugGUIManager *v1; // rbx
  UFG::qResourceHandle *v2; // rdi
  unsigned int v3; // esi
  UFG::qResourceInventory *v4; // rax
  UFG::qResourceWarehouse *v5; // rax

  v1 = this;
  this->mGUIObjects.mNode.mPrev = &this->mGUIObjects.mNode;
  this->mGUIObjects.mNode.mNext = &this->mGUIObjects.mNode;
  v2 = (UFG::qResourceHandle *)&this->mMenuFontHandle.mPrev;
  UFG::qResourceHandle::qResourceHandle((UFG::qResourceHandle *)&this->mMenuFontHandle.mPrev);
  v1->mMousePos = 0i64;
  *(_QWORD *)&v1->mMouseButtons = 0i64;
  *(_QWORD *)&v1->mMenuItemCheckWidth = 0i64;
  v3 = UFG::qStringHash32("GUIMenu", 0xFFFFFFFF);
  v4 = `UFG::qGetResourceInventory<Render::Font>::`2::result;
  if ( !`UFG::qGetResourceInventory<Render::Font>::`2::result )
  {
    v5 = UFG::qResourceWarehouse::Instance();
    v4 = UFG::qResourceWarehouse::GetInventory(v5, 0x69FCCB4Cu);
    `UFG::qGetResourceInventory<Render::Font>::`2::result = v4;
  }
  UFG::qResourceHandle::Init(v2, 0x69FCCB4Cu, v3, v4);
}

// File Line: 48
// RVA: 0xBAD50
UFG::DebugGUIManager *__fastcall UFG::DebugGUIManager::Instance()
{
  if ( !(_S1_15 & 1) )
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
  bool *v2; // rbp
  UFG::DebugGUIManager *v3; // rbx
  UFG::DebugGUIManager *v4; // rsi
  signed __int64 v5; // rdi
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *v6; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v7; // rax
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **v8; // r8

  this->mIsActive = 0;
  v2 = &this[-1].mIsActive;
  v3 = (UFG::DebugGUIManager *)&this->mGUIObjects.mNode.mNext[-1].mNext;
  v4 = this;
  if ( v3 != (UFG::DebugGUIManager *)&this[-1].mIsActive )
  {
    do
    {
      v5 = (signed __int64)&v3->mMenuFontHandle.mPrev[-1].mNext;
      if ( ((unsigned __int8 (__fastcall *)(UFG::DebugGUIManager *))v3->mGUIObjects.mNode.mPrev[6].mPrev)(v3) )
        ((void (__fastcall *)(UFG::DebugGUIManager *))v3->mGUIObjects.mNode.mPrev->mNext)(v3);
      if ( ((unsigned __int8 (__fastcall *)(UFG::DebugGUIManager *))v3->mGUIObjects.mNode.mPrev[6].mPrev)(v3) )
      {
        v4->mIsActive = 1;
      }
      else if ( ((unsigned __int8 (__fastcall *)(UFG::DebugGUIManager *))v3->mGUIObjects.mNode.mPrev[7].mPrev)(v3) )
      {
        v6 = v3->mGUIObjects.mNode.mNext;
        v7 = v3->mMenuFontHandle.mPrev;
        v8 = &v3->mGUIObjects.mNode.mNext;
        v6->mNext = (UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *)v7;
        v7->mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)v6;
        *v8 = (UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *)v8;
        v8[1] = (UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> *)v8;
        ((void (__fastcall *)(UFG::DebugGUIManager *, signed __int64))v3->mGUIObjects.mNode.mPrev->mPrev)(v3, 1i64);
      }
      v3 = (UFG::DebugGUIManager *)v5;
    }
    while ( (bool *)v5 != v2 );
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
  UFG::DebugGUIManager *v2; // r13
  UFG::Controller *v3; // rdx
  float v4; // xmm7_4
  bool *v5; // rdi
  signed __int64 v6; // rsi
  UFG::InputState *v7; // rdx
  char *v8; // rcx
  signed __int64 v9; // rax
  __int128 v10; // xmm0
  __int128 v11; // xmm1
  __int128 v12; // xmm0
  __int128 v13; // xmm1
  __int128 v14; // xmm0
  __int128 v15; // xmm1
  __int128 v16; // xmm0
  __int128 v17; // xmm1
  __int64 v18; // rax
  UFG::InputMKeys v19; // er14
  UFG::InputMouseButtons v20; // eax
  __int64 v21; // r12
  UFG::InputMouseButtons v22; // er15
  unsigned int v23; // esi
  int v24; // eax
  int v25; // er10
  int v26; // er8
  int v27; // er9
  int v28; // ebp
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **i; // rbx
  __int64 v30; // r9
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **j; // rbx
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **k; // rbx
  bool v33; // bp
  unsigned int v34; // esi
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **l; // rbx
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **m; // rbx
  unsigned int v37; // eax
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **v38; // rbx
  unsigned int n; // esi
  UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **v40; // rbx
  __int128 ii; // xmm6
  __int64 v42; // r8
  __int64 v43; // [rsp+20h] [rbp-188h]
  __int64 v44; // [rsp+28h] [rbp-180h]
  char Dst; // [rsp+30h] [rbp-178h]
  int v46; // [rsp+1C0h] [rbp+18h]
  int v47; // [rsp+1C4h] [rbp+1Ch]
  __int64 v48; // [rsp+1C8h] [rbp+20h]

  v2 = this;
  v3 = UFG::gInputSystem->mControllers[0];
  v4 = fRealTimeDelta;
  if ( v3 )
  {
    v5 = &this[-1].mIsActive;
    if ( (bool *)&this->mGUIObjects.mNode.mNext[-1].mNext != &this[-1].mIsActive && !v3->m_IsKeyboardController )
    {
      v6 = (signed __int64)&v3->mInputMessages;
      v7 = &v3->mPreviousInputState;
      v8 = &Dst;
      v48 = v6;
      if ( ((unsigned __int8)&Dst | (unsigned __int8)v7) & 0xF )
      {
        memmove(&Dst, v7, 0x118ui64);
      }
      else
      {
        v9 = 2i64;
        do
        {
          v10 = *(_OWORD *)&v7->mLastMouseXYTime;
          v11 = *(_OWORD *)&v7->mPrevMouseY;
          v8 += 128;
          v7 = (UFG::InputState *)((char *)v7 + 128);
          *((_OWORD *)v8 - 8) = v10;
          v12 = *(_OWORD *)&v7[-1].mKeyState[164];
          *((_OWORD *)v8 - 7) = v11;
          v13 = *(_OWORD *)&v7[-1].mKeyState[180];
          *((_OWORD *)v8 - 6) = v12;
          v14 = *(_OWORD *)&v7[-1].mKeyState[196];
          *((_OWORD *)v8 - 5) = v13;
          v15 = *(_OWORD *)&v7[-1].mKeyState[212];
          *((_OWORD *)v8 - 4) = v14;
          v16 = *(_OWORD *)&v7[-1].mKeyState[228];
          *((_OWORD *)v8 - 3) = v15;
          v17 = *(_OWORD *)&v7[-1].mKeyState[244];
          *((_OWORD *)v8 - 2) = v16;
          *((_OWORD *)v8 - 1) = v17;
          --v9;
        }
        while ( v9 );
        v18 = *(_QWORD *)&v7->mPrevMouseY;
        *(_OWORD *)v8 = *(_OWORD *)&v7->mLastMouseXYTime;
        *((_QWORD *)v8 + 2) = v18;
      }
      v19 = UFG::InputState::GetModiferKeys((UFG::InputState *)&Dst);
      v20 = UFG::InputState::GetMouseButtons((UFG::InputState *)&Dst);
      v2->mModKeys = v19;
      v2->mMouseButtons = v20;
      v21 = *(_QWORD *)(v6 + 8);
      v22 = v20;
      if ( v21 != v6 )
      {
        do
        {
          v23 = *(unsigned __int8 *)(v21 + 17);
          v24 = UFG::InputState::GetRepeatCount((UFG::InputState *)&Dst, v23);
          v25 = *(char *)(v21 + 16);
          v26 = *(signed __int16 *)(v21 + 18);
          v27 = *(signed __int16 *)(v21 + 20);
          v28 = v24;
          v46 = *(signed __int16 *)(v21 + 18);
          v47 = v27;
          switch ( v25 )
          {
            case 2:
              for ( i = &v2->mGUIObjects.mNode.mNext[-1].mNext;
                    i != (UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **)v5;
                    i = &i[2][-1].mNext )
              {
                if ( ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **))(*i)[5].mNext)(i) )
                {
                  LOBYTE(v30) = v28 > 0;
                  if ( ((unsigned __int64 (__fastcall *)(UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **, _QWORD, _QWORD, __int64))(*i)[1].mNext)(
                         i,
                         v23,
                         (unsigned int)v19,
                         v30) )
                  {
                    break;
                  }
                }
              }
              break;
            case 3:
              for ( j = &v2->mGUIObjects.mNode.mNext[-1].mNext;
                    j != (UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **)v5;
                    j = &j[2][-1].mNext )
              {
                if ( ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **))(*j)[5].mNext)(j)
                  && ((unsigned __int64 (__fastcall *)(UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **, _QWORD, _QWORD))(*j)[2].mPrev)(
                       j,
                       v23,
                       (unsigned int)v19) )
                {
                  break;
                }
              }
              break;
            case 4:
              if ( v2->mMousePos.i_x != v26 || v2->mMousePos.i_y != v27 )
              {
                v2->mMousePos.i_x = v26;
                v2->mMousePos.i_y = v27;
                for ( k = &v2->mGUIObjects.mNode.mNext[-1].mNext;
                      k != (UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **)v5;
                      k = &k[2][-1].mNext )
                {
                  if ( ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **))(*k)[5].mPrev)(k)
                    && ((unsigned __int64 (__fastcall *)(UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **, int *, _QWORD, _QWORD))(*k)[3].mNext)(
                         k,
                         &v46,
                         (unsigned int)v22,
                         (unsigned int)v19) )
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
                for ( l = &v2->mGUIObjects.mNode.mNext[-1].mNext;
                      l != (UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **)v5;
                      l = &l[2][-1].mNext )
                {
                  if ( ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **))(*l)[5].mPrev)(l) )
                    ((void (__fastcall *)(UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **, int *))(*l)[4].mNext)(
                      l,
                      &v46);
                }
              }
              for ( m = &v2->mGUIObjects.mNode.mNext[-1].mNext;
                    m != (UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **)v5;
                    m = &m[2][-1].mNext )
              {
                if ( ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **))(*m)[5].mPrev)(m) )
                {
                  LODWORD(v44) = v19;
                  LODWORD(v43) = v22;
                  if ( ((unsigned __int64 (__fastcall *)(UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **, int *, _QWORD, bool, __int64, __int64))(*m)[2].mNext)(
                         m,
                         &v46,
                         v34,
                         v33,
                         v43,
                         v44) )
                  {
                    break;
                  }
                }
              }
              break;
            case 8:
              v37 = UFG::DebugGUIManager::MapMouseButton(v23);
              v38 = &v2->mGUIObjects.mNode.mNext[-1].mNext;
              for ( n = v37; v38 != (UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **)v5; v38 = &v38[2][-1].mNext )
              {
                if ( ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **))(*v38)[5].mPrev)(v38)
                  && ((unsigned __int64 (__fastcall *)(UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **, int *, _QWORD, _QWORD))(*v38)[3].mPrev)(
                       v38,
                       &v46,
                       n,
                       (unsigned int)v22) )
                {
                  break;
                }
              }
              break;
            case 10:
              v40 = &v2->mGUIObjects.mNode.mNext[-1].mNext;
              for ( ii = COERCE_UNSIGNED_INT((float)*(signed __int16 *)(v21 + 22));
                    v40 != (UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **)v5;
                    v40 = &v40[2][-1].mNext )
              {
                if ( ((unsigned __int8 (__fastcall *)(UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **))(*v40)[5].mPrev)(v40)
                  && ((unsigned __int64 (__fastcall *)(UFG::qNode<UFG::GUIObjectBase,UFG::GUIObjectBase> **, AVec2i *, __int64, _QWORD))(*v40)[4].mPrev)(
                       v40,
                       &v2->mMousePos,
                       v42,
                       (unsigned int)v22) )
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
        while ( v21 != v48 );
      }
    }
  }
  UFG::DebugGUIManager::PostUpdate(v2, v4);
}

