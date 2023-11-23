// File Line: 28
// RVA: 0x5C9D70
void __fastcall UFG::UIHKPopUpNotifier::~UIHKPopUpNotifier(UFG::UIHKPopUpNotifier *this)
{
  UFG::qList<UFG::PopUpMessage,UFG::PopUpMessage,1,0> *p_m_MessageQueue; // rbx
  UFG::qNode<UFG::PopUpMessage,UFG::PopUpMessage> *mPrev; // rcx
  UFG::qNode<UFG::PopUpMessage,UFG::PopUpMessage> *mNext; // rax

  this->vfptr = (UFG::UIHKPopUpNotifierVtbl *)&UFG::UIHKPopUpNotifier::`vftable;
  p_m_MessageQueue = &this->m_MessageQueue;
  UFG::qList<UFG::PopUpMessage,UFG::PopUpMessage,1,0>::DeleteNodes((UFG::qList<UFG::MissionWorkStatus,UFG::MissionWorkStatus,1,0> *)&this->m_MessageQueue);
  mPrev = p_m_MessageQueue->mNode.mPrev;
  mNext = p_m_MessageQueue->mNode.mNext;
  mPrev->mNext = mNext;
  mNext->mPrev = mPrev;
  p_m_MessageQueue->mNode.mPrev = &p_m_MessageQueue->mNode;
  p_m_MessageQueue->mNode.mNext = &p_m_MessageQueue->mNode;
}

// File Line: 42
// RVA: 0x621560
char __fastcall UFG::UIHKPopUpNotifier::handleMessage(
        UFG::UIHKPopUpNotifier *this,
        UFG::UIScreen *screen,
        unsigned int msgId,
        UFG::UIMessage *msg)
{
  UFG::allocator::free_link *v5; // rax
  UFG::allocator::free_link *v6; // rsi
  UFG::qNode<UFG::PopUpMessage,UFG::PopUpMessage> *mPrev; // rax

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
  mPrev = this->m_MessageQueue.mNode.mPrev;
  mPrev->mNext = (UFG::qNode<UFG::PopUpMessage,UFG::PopUpMessage> *)v6;
  v6->mNext = (UFG::allocator::free_link *)mPrev;
  v6[1].mNext = (UFG::allocator::free_link *)&this->m_MessageQueue;
  this->m_MessageQueue.mNode.mPrev = (UFG::qNode<UFG::PopUpMessage,UFG::PopUpMessage> *)v6;
  ++this->m_iNumMessages;
  if ( this->m_eState == STATE_IDLE )
    this->m_eState = STATE_ROOT_MENU;
  return 1;
}

// File Line: 60
// RVA: 0x63BBE0
void __fastcall UFG::UIHKPopUpNotifier::update(UFG::UIHKPopUpNotifier *this, UFG::UIScreen *screen, float elapsed)
{
  __int32 v5; // ecx
  float v6; // xmm2_4
  UFG::qNode<UFG::PopUpMessage,UFG::PopUpMessage> *mNext; // rsi
  UFG::qNode<UFG::PopUpMessage,UFG::PopUpMessage> *mPrev; // rcx
  UFG::qNode<UFG::PopUpMessage,UFG::PopUpMessage> *v9; // rax
  Scaleform::GFx::Value::ValueUnion v10; // r14
  __int64 v11; // r14
  UFG::qNode<UFG::PopUpMessage,UFG::PopUpMessage> *v12; // r10
  UFG::qNode<UFG::PopUpMessage,UFG::PopUpMessage> *v13; // rax
  Scaleform::GFx::Value ptr; // [rsp+40h] [rbp-78h] BYREF
  char v15[16]; // [rsp+70h] [rbp-48h] BYREF
  __int64 v16; // [rsp+80h] [rbp-38h]
  int v17; // [rsp+88h] [rbp-30h]
  __int64 v18; // [rsp+90h] [rbp-28h]

  if ( screen )
  {
    v5 = this->m_eState - 1;
    if ( v5 )
    {
      if ( v5 == 1 )
      {
        v6 = elapsed + this->m_fElapsedTime;
        this->m_fElapsedTime = v6;
        if ( v6 > 10.0 )
        {
          Scaleform::GFx::Movie::Invoke(screen->mRenderable->m_movie.pObject, "PopUpNotifier_Close", 0i64, 0i64, 0);
          this->m_eState = STATE_ROOT_MENU;
        }
      }
    }
    else if ( this->m_iNumMessages )
    {
      mNext = this->m_MessageQueue.mNode.mNext;
      mPrev = mNext->mPrev;
      v9 = mNext->mNext;
      mPrev->mNext = v9;
      v9->mPrev = mPrev;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      `eh vector constructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::Value);
      v10 = (Scaleform::GFx::Value::ValueUnion)mNext[2].mNext;
      if ( (ptr.Type & 0x40) != 0 )
      {
        (*(void (__fastcall **)(Scaleform::GFx::Value::ObjectInterface *, Scaleform::GFx::Value *, Scaleform::GFx::Value::ValueUnion))&ptr.pObjectInterface->vfptr->gap8[8])(
          ptr.pObjectInterface,
          &ptr,
          ptr.mValue);
        ptr.pObjectInterface = 0i64;
      }
      ptr.Type = VT_String;
      ptr.mValue = v10;
      v11 = (__int64)mNext[5].mPrev;
      if ( (v17 & 0x40) != 0 )
      {
        (*(void (__fastcall **)(__int64, char *, __int64))(*(_QWORD *)v16 + 16i64))(v16, v15, v18);
        v16 = 0i64;
      }
      v17 = 6;
      v18 = v11;
      Scaleform::GFx::Movie::Invoke(screen->mRenderable->m_movie.pObject, "PopUpNotifier_Show", 0i64, &ptr, 2u);
      UFG::qString::~qString((UFG::qString *)&mNext[3].mNext);
      UFG::qString::~qString((UFG::qString *)&mNext[1]);
      v12 = mNext->mPrev;
      v13 = mNext->mNext;
      v12->mNext = v13;
      v13->mPrev = v12;
      mNext->mPrev = mNext;
      mNext->mNext = mNext;
      operator delete[](mNext);
      --this->m_iNumMessages;
      this->m_fElapsedTime = 0.0;
      this->m_eState = STATE_PHONE_CONTACTS;
      `eh vector destructor iterator(&ptr, 0x30ui64, 2, (void (__fastcall *)(void *))Scaleform::GFx::Value::~Value);
    }
    else
    {
      this->m_eState = STATE_IDLE;
    }
  }
}

