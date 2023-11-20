// File Line: 28
// RVA: 0x5C9D70
void __fastcall UFG::UIHKPopUpNotifier::~UIHKPopUpNotifier(UFG::UIHKPopUpNotifier *this)
{
  UFG::qList<UFG::PopUpMessage,UFG::PopUpMessage,1,0> *v1; // rbx
  UFG::qNode<UFG::PopUpMessage,UFG::PopUpMessage> *v2; // rcx
  UFG::qNode<UFG::PopUpMessage,UFG::PopUpMessage> *v3; // rax

  this->vfptr = (UFG::UIHKPopUpNotifierVtbl *)&UFG::UIHKPopUpNotifier::`vftable';
  v1 = &this->m_MessageQueue;
  UFG::qList<UFG::PopUpMessage,UFG::PopUpMessage,1,0>::DeleteNodes((UFG::qList<UFG::MissionWorkStatus,UFG::MissionWorkStatus,1,0> *)&this->m_MessageQueue);
  v2 = v1->mNode.mPrev;
  v3 = v1->mNode.mNext;
  v2->mNext = v3;
  v3->mPrev = v2;
  v1->mNode.mPrev = &v1->mNode;
  v1->mNode.mNext = &v1->mNode;
}

// File Line: 42
// RVA: 0x621560
char __fastcall UFG::UIHKPopUpNotifier::handleMessage(UFG::UIHKPopUpNotifier *this, UFG::UIScreen *screen, unsigned int msgId, UFG::UIMessage *msg)
{
  UFG::UIHKPopUpNotifier *v4; // rbp
  UFG::allocator::free_link *v5; // rax
  UFG::allocator::free_link *v6; // rsi
  UFG::qNode<UFG::PopUpMessage,UFG::PopUpMessage> *v7; // rax

  v4 = this;
  if ( msgId != UI_HASH_CHALLENGE_UNLOCKED_20 )
    return 0;
  v5 = UFG::qMalloc(0x60ui64, "UIHKPopUpNotifier", 0i64);
  v6 = v5;
  if ( v5 )
  {
    v5->mNext = v5;
    v5[1].mNext = v5;
    UFG::qString::qString((UFG::qString *)&v5[2]);
    UFG::qString::qString((UFG::qString *)&v6[7]);
    UFG::qString::Set((UFG::qString *)&v6[2], "$CHALLENGE_UNLOCKED");
    UFG::qString::Set((UFG::qString *)&v6[7], "$CHALLENGE_NAME");
  }
  else
  {
    v6 = 0i64;
  }
  v7 = v4->m_MessageQueue.mNode.mPrev;
  v7->mNext = (UFG::qNode<UFG::PopUpMessage,UFG::PopUpMessage> *)v6;
  v6->mNext = (UFG::allocator::free_link *)v7;
  v6[1].mNext = (UFG::allocator::free_link *)&v4->m_MessageQueue;
  v4->m_MessageQueue.mNode.mPrev = (UFG::qNode<UFG::PopUpMessage,UFG::PopUpMessage> *)v6;
  ++v4->m_iNumMessages;
  if ( v4->m_eState == STATE_IDLE )
    v4->m_eState = 1;
  return 1;
}

// File Line: 60
// RVA: 0x63BBE0
void __fastcall UFG::UIHKPopUpNotifier::update(UFG::UIHKPopUpNotifier *this, UFG::UIScreen *screen, float elapsed)
{
  UFG::UIScreen *v3; // rbp
  UFG::UIHKPopUpNotifier *v4; // rbx
  __int32 v5; // ecx
  float v6; // xmm2_4
  UFG::qNode<UFG::PopUpMessage,UFG::PopUpMessage> *v7; // rsi
  UFG::qNode<UFG::PopUpMessage,UFG::PopUpMessage> *v8; // rcx
  UFG::qNode<UFG::PopUpMessage,UFG::PopUpMessage> *v9; // rax
  __int64 v10; // r14
  __int64 v11; // r14
  UFG::qNode<UFG::PopUpMessage,UFG::PopUpMessage> *v12; // r10
  UFG::qNode<UFG::PopUpMessage,UFG::PopUpMessage> *v13; // rax
  char ptr; // [rsp+40h] [rbp-78h]
  __int64 v15; // [rsp+50h] [rbp-68h]
  unsigned int v16; // [rsp+58h] [rbp-60h]
  __int64 v17; // [rsp+60h] [rbp-58h]
  char v18; // [rsp+70h] [rbp-48h]
  __int64 v19; // [rsp+80h] [rbp-38h]
  unsigned int v20; // [rsp+88h] [rbp-30h]
  __int64 v21; // [rsp+90h] [rbp-28h]

  if ( screen )
  {
    v3 = screen;
    v4 = this;
    v5 = this->m_eState - 1;
    if ( v5 )
    {
      if ( v5 == 1 )
      {
        v6 = elapsed + v4->m_fElapsedTime;
        v4->m_fElapsedTime = v6;
        if ( v6 > 10.0 )
        {
          Scaleform::GFx::Movie::Invoke(screen->mRenderable->m_movie.pObject, "PopUpNotifier_Close", 0i64, 0i64, 0);
          v4->m_eState = 1;
        }
      }
    }
    else if ( v4->m_iNumMessages )
    {
      v7 = v4->m_MessageQueue.mNode.mNext;
      v8 = v7->mPrev;
      v9 = v7->mNext;
      v8->mNext = v9;
      v9->mPrev = v8;
      v7->mPrev = v7;
      v7->mNext = v7;
      `eh vector constructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      v10 = (__int64)v7[2].mNext;
      if ( (v16 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v15 + 16i64))(v15, &ptr, v17);
        v15 = 0i64;
      }
      v16 = 6;
      v17 = v10;
      v11 = (__int64)v7[5].mPrev;
      if ( (v20 >> 6) & 1 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v19 + 16i64))(v19, &v18, v21);
        v19 = 0i64;
      }
      v20 = 6;
      v21 = v11;
      Scaleform::GFx::Movie::Invoke(
        v3->mRenderable->m_movie.pObject,
        "PopUpNotifier_Show",
        0i64,
        (Scaleform::GFx::Value *)&ptr,
        2u);
      UFG::qString::~qString((UFG::qString *)&v7[3].mNext);
      UFG::qString::~qString((UFG::qString *)&v7[1]);
      v12 = v7->mPrev;
      v13 = v7->mNext;
      v12->mNext = v13;
      v13->mPrev = v12;
      v7->mPrev = v7;
      v7->mNext = v7;
      operator delete[](v7);
      --v4->m_iNumMessages;
      v4->m_fElapsedTime = 0.0;
      v4->m_eState = 2;
      `eh vector destructor iterator'(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    }
    else
    {
      v4->m_eState = 0;
    }
  }
}

