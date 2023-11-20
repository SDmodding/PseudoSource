// File Line: 286
// RVA: 0x8B1A30
void __fastcall Scaleform::GFx::InputEventsQueue::AddKeyDown(Scaleform::GFx::InputEventsQueue *this, unsigned int code, char ascii, Scaleform::KeyModifiers specialKeysState, char keyboardIndex)
{
  char v5; // di
  unsigned int v6; // ebx
  Scaleform::GFx::InputEventsQueueEntry *v7; // rax
  char v8; // [rsp+48h] [rbp+20h]

  v8 = specialKeysState.States;
  v5 = ascii;
  v6 = code;
  v7 = Scaleform::GFx::InputEventsQueue::AddEmptyQueueEntry(this);
  v7->t = 1;
  v7->u.keyEntry.Code = v6;
  v7->u.keyEntry.AsciiCode = v5;
  v7->u.keyEntry.WcharCode = 0;
  v7->u.keyEntry.KeysState = v8;
  v7->u.mouseEntry.Flags = 1;
  v7->u.mouseEntry.WheelScrollDelta = keyboardIndex;
}

// File Line: 291
// RVA: 0x8B1A80
void __fastcall Scaleform::GFx::InputEventsQueue::AddKeyUp(Scaleform::GFx::InputEventsQueue *this, unsigned int code, char ascii, Scaleform::KeyModifiers specialKeysState, char keyboardIndex)
{
  char v5; // di
  unsigned int v6; // ebx
  Scaleform::GFx::InputEventsQueueEntry *v7; // rax
  char v8; // [rsp+48h] [rbp+20h]

  v8 = specialKeysState.States;
  v5 = ascii;
  v6 = code;
  v7 = Scaleform::GFx::InputEventsQueue::AddEmptyQueueEntry(this);
  v7->t = 1;
  v7->u.keyEntry.Code = v6;
  v7->u.keyEntry.AsciiCode = v5;
  v7->u.keyEntry.WcharCode = 0;
  v7->u.keyEntry.KeysState = v8;
  WORD1(v7->u.statusEntry.Level) = (unsigned __int8)keyboardIndex;
}

// File Line: 295
// RVA: 0x8B0480
void __fastcall Scaleform::GFx::InputEventsQueue::AddCharTyped(Scaleform::GFx::InputEventsQueue *this, unsigned int wcharCode, char keyboardIndex)
{
  char v3; // di
  unsigned int v4; // ebx
  Scaleform::GFx::InputEventsQueueEntry *v5; // rax

  v3 = keyboardIndex;
  v4 = wcharCode;
  v5 = Scaleform::GFx::InputEventsQueue::AddEmptyQueueEntry(this);
  v5->t = 1;
  v5->u.keyEntry.WcharCode = v4;
  v5->u.keyEntry.Code = 0;
  v5->u.mouseEntry.ButtonsState = -32768;
  v5->u.mouseEntry.WheelScrollDelta = v3;
  v5->u.mouseEntry.Flags = 1;
}

// File Line: 410
// RVA: 0x6EE4A0
Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *__fastcall Scaleform::GFx::MouseState::GetActiveEntity(Scaleform::GFx::MouseState *this, Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *result)
{
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v2; // rbx
  Scaleform::GFx::Sprite *v3; // rax
  Scaleform::Ptr<Scaleform::GFx::Sprite> resulta; // [rsp+40h] [rbp+8h]
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v6; // [rsp+48h] [rbp+10h]

  v6 = result;
  v2 = result;
  Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->ActiveEntity,
    &resulta);
  v3 = resulta.pObject;
  if ( resulta.pObject )
  {
    ++resulta.pObject->RefCount;
    v3 = resulta.pObject;
  }
  v2->pObject = (Scaleform::GFx::InteractiveObject *)&v3->vfptr;
  if ( resulta.pObject )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&resulta.pObject->vfptr);
  return v2;
}

// File Line: 414
// RVA: 0x6F7220
Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *__fastcall Scaleform::GFx::MouseState::GetTopmostEntity(Scaleform::GFx::MouseState *this, Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *result)
{
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v2; // rbx
  Scaleform::GFx::Sprite *v3; // rax
  Scaleform::Ptr<Scaleform::GFx::Sprite> resulta; // [rsp+40h] [rbp+8h]
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v6; // [rsp+48h] [rbp+10h]

  v6 = result;
  v2 = result;
  Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)this,
    &resulta);
  v3 = resulta.pObject;
  if ( resulta.pObject )
  {
    ++resulta.pObject->RefCount;
    v3 = resulta.pObject;
  }
  v2->pObject = (Scaleform::GFx::InteractiveObject *)&v3->vfptr;
  if ( resulta.pObject )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&resulta.pObject->vfptr);
  return v2;
}

// File Line: 424
// RVA: 0x90E700
void __fastcall Scaleform::GFx::MouseState::SetTopmostEntity(Scaleform::GFx::MouseState *this, Scaleform::GFx::InteractiveObject *pch)
{
  Scaleform::GFx::InteractiveObject *v2; // rdi
  Scaleform::GFx::MouseState *v3; // rbx
  Scaleform::WeakPtrProxy *v4; // rdx
  bool v5; // zf
  Scaleform::WeakPtrProxy *v6; // rax
  Scaleform::WeakPtrProxy *v7; // rdx
  Scaleform::WeakPtrProxy *v8; // rsi
  Scaleform::WeakPtrProxy *v9; // rdx

  v2 = pch;
  v3 = this;
  if ( this->TopmostEntity.pProxy.pObject )
    ++this->TopmostEntity.pProxy.pObject->RefCount;
  v4 = this->PrevTopmostEntity.pProxy.pObject;
  if ( v4 )
  {
    v5 = v4->RefCount-- == 1;
    if ( v5 )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  }
  v3->PrevTopmostEntity.pProxy.pObject = v3->TopmostEntity.pProxy.pObject;
  *((_BYTE *)v3 + 76) ^= (*((_BYTE *)v3 + 76) ^ 2 * *((_BYTE *)v3 + 76)) & 2;
  if ( v2 )
  {
    v6 = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy((Scaleform::RefCountWeakSupportImpl *)&v2->vfptr);
    v7 = v3->TopmostEntity.pProxy.pObject;
    v8 = v6;
    if ( v3->TopmostEntity.pProxy.pObject )
    {
      v5 = v7->RefCount-- == 1;
      if ( v5 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    }
    v3->TopmostEntity.pProxy.pObject = v8;
  }
  else
  {
    v9 = v3->TopmostEntity.pProxy.pObject;
    if ( v3->TopmostEntity.pProxy.pObject )
    {
      v5 = v9->RefCount-- == 1;
      if ( v5 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    }
    v3->TopmostEntity.pProxy.pObject = 0i64;
  }
  *((_BYTE *)v3 + 76) &= 0xFEu;
  *((_BYTE *)v3 + 76) |= v2 == 0i64;
}

// File Line: 432
// RVA: 0x8E79B0
_BOOL8 __fastcall Scaleform::GFx::MouseState::IsTopmostEntityChanged(Scaleform::GFx::MouseState *this)
{
  Scaleform::GFx::MouseState *v1; // rsi
  Scaleform::GFx::Sprite *v2; // rbx
  Scaleform::GFx::Sprite *v3; // rdi
  bool v4; // si
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::Sprite *v7; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::Sprite *v8; // [rsp+60h] [rbp+18h]

  v1 = this;
  Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)this,
    &result);
  v2 = result.pObject;
  if ( result.pObject )
  {
    ++result.pObject->RefCount;
    v2 = result.pObject;
  }
  v7 = v2;
  if ( result.pObject )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&result.pObject->vfptr);
  Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&v1->PrevTopmostEntity,
    &result);
  v3 = result.pObject;
  if ( result.pObject )
  {
    ++result.pObject->RefCount;
    v3 = result.pObject;
  }
  v8 = v3;
  if ( result.pObject )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&result.pObject->vfptr);
  v4 = v2 != v3 || !v2 && !(*((_BYTE *)v1 + 76) & 1) || !v3 && !(*((_BYTE *)v1 + 76) & 2);
  if ( v3 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v3->vfptr);
  if ( v2 )
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v2->vfptr);
  return v4;
}

