// File Line: 286
// RVA: 0x8B1A30
void __fastcall Scaleform::GFx::InputEventsQueue::AddKeyDown(
        Scaleform::GFx::InputEventsQueue *this,
        unsigned int code,
        char ascii,
        Scaleform::KeyModifiers specialKeysState,
        char keyboardIndex)
{
  Scaleform::GFx::InputEventsQueue *v7; // rax

  v7 = Scaleform::GFx::InputEventsQueue::AddEmptyQueueEntry(this);
  v7->Queue[0].t = QE_Key;
  v7->Queue[0].u.keyEntry.Code = code;
  v7->Queue[0].u.keyEntry.AsciiCode = ascii;
  v7->Queue[0].u.keyEntry.WcharCode = 0;
  BYTE1(v7->Queue[0].u.statusEntry.Level) = specialKeysState;
  v7->Queue[0].u.mouseEntry.Flags = 1;
  v7->Queue[0].u.mouseEntry.WheelScrollDelta = keyboardIndex;
}

// File Line: 291
// RVA: 0x8B1A80
void __fastcall Scaleform::GFx::InputEventsQueue::AddKeyUp(
        Scaleform::GFx::InputEventsQueue *this,
        unsigned int code,
        char ascii,
        Scaleform::KeyModifiers specialKeysState,
        unsigned __int8 keyboardIndex)
{
  Scaleform::GFx::InputEventsQueue *v7; // rax

  v7 = Scaleform::GFx::InputEventsQueue::AddEmptyQueueEntry(this);
  v7->Queue[0].t = QE_Key;
  v7->Queue[0].u.keyEntry.Code = code;
  v7->Queue[0].u.keyEntry.AsciiCode = ascii;
  v7->Queue[0].u.keyEntry.WcharCode = 0;
  BYTE1(v7->Queue[0].u.statusEntry.Level) = specialKeysState;
  WORD1(v7->Queue[0].u.statusEntry.Level) = keyboardIndex;
}

// File Line: 295
// RVA: 0x8B0480
void __fastcall Scaleform::GFx::InputEventsQueue::AddCharTyped(
        Scaleform::GFx::InputEventsQueue *this,
        unsigned int wcharCode,
        char keyboardIndex)
{
  Scaleform::GFx::InputEventsQueueEntry *v5; // rax

  v5 = Scaleform::GFx::InputEventsQueue::AddEmptyQueueEntry(this);
  v5->t = QE_Key;
  v5->u.keyEntry.WcharCode = wcharCode;
  v5->u.keyEntry.Code = 0;
  v5->u.mouseEntry.ButtonsState = 0x8000;
  v5->u.mouseEntry.WheelScrollDelta = keyboardIndex;
  v5->u.mouseEntry.Flags = 1;
}

// File Line: 410
// RVA: 0x6EE4A0
Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *__fastcall Scaleform::GFx::MouseState::GetActiveEntity(
        Scaleform::GFx::MouseState *this,
        Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *result)
{
  Scaleform::GFx::Sprite *pObject; // rax
  Scaleform::Ptr<Scaleform::GFx::Sprite> resulta; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v6; // [rsp+48h] [rbp+10h]

  v6 = result;
  Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->ActiveEntity,
    &resulta);
  pObject = resulta.pObject;
  if ( resulta.pObject )
  {
    ++resulta.pObject->RefCount;
    pObject = resulta.pObject;
  }
  result->pObject = pObject;
  if ( resulta.pObject )
    Scaleform::RefCountNTSImpl::Release(resulta.pObject);
  return result;
}

// File Line: 414
// RVA: 0x6F7220
Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *__fastcall Scaleform::GFx::MouseState::GetTopmostEntity(
        Scaleform::GFx::MouseState *this,
        Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *result)
{
  Scaleform::GFx::Sprite *pObject; // rax
  Scaleform::Ptr<Scaleform::GFx::Sprite> resulta; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v6; // [rsp+48h] [rbp+10h]

  v6 = result;
  Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)this,
    &resulta);
  pObject = resulta.pObject;
  if ( resulta.pObject )
  {
    ++resulta.pObject->RefCount;
    pObject = resulta.pObject;
  }
  result->pObject = pObject;
  if ( resulta.pObject )
    Scaleform::RefCountNTSImpl::Release(resulta.pObject);
  return result;
}

// File Line: 424
// RVA: 0x90E700
void __fastcall Scaleform::GFx::MouseState::SetTopmostEntity(
        Scaleform::GFx::MouseState *this,
        Scaleform::GFx::InteractiveObject *pch)
{
  Scaleform::WeakPtrProxy *pObject; // rdx
  bool v5; // zf
  Scaleform::WeakPtrProxy *WeakProxy; // rax
  Scaleform::WeakPtrProxy *v7; // rdx
  Scaleform::WeakPtrProxy *v8; // rsi
  Scaleform::WeakPtrProxy *v9; // rdx

  if ( this->TopmostEntity.pProxy.pObject )
    ++this->TopmostEntity.pProxy.pObject->RefCount;
  pObject = this->PrevTopmostEntity.pProxy.pObject;
  if ( pObject )
  {
    v5 = pObject->RefCount-- == 1;
    if ( v5 )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
  this->PrevTopmostEntity.pProxy.pObject = this->TopmostEntity.pProxy.pObject;
  *((_BYTE *)this + 76) ^= (*((_BYTE *)this + 76) ^ (2 * *((_BYTE *)this + 76))) & 2;
  if ( pch )
  {
    WeakProxy = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy(pch);
    v7 = this->TopmostEntity.pProxy.pObject;
    v8 = WeakProxy;
    if ( this->TopmostEntity.pProxy.pObject )
    {
      v5 = v7->RefCount-- == 1;
      if ( v5 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    }
    this->TopmostEntity.pProxy.pObject = v8;
  }
  else
  {
    v9 = this->TopmostEntity.pProxy.pObject;
    if ( this->TopmostEntity.pProxy.pObject )
    {
      v5 = v9->RefCount-- == 1;
      if ( v5 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    }
    this->TopmostEntity.pProxy.pObject = 0i64;
  }
  *((_BYTE *)this + 76) &= ~1u;
  *((_BYTE *)this + 76) |= pch == 0i64;
}

// File Line: 432
// RVA: 0x8E79B0
_BOOL8 __fastcall Scaleform::GFx::MouseState::IsTopmostEntityChanged(Scaleform::GFx::MouseState *this)
{
  Scaleform::GFx::Sprite *pObject; // rbx
  Scaleform::GFx::Sprite *v3; // rdi
  bool v4; // si
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::Sprite *v7; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::Sprite *v8; // [rsp+60h] [rbp+18h]

  Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)this,
    &result);
  pObject = result.pObject;
  if ( result.pObject )
  {
    ++result.pObject->RefCount;
    pObject = result.pObject;
  }
  v7 = pObject;
  if ( result.pObject )
    Scaleform::RefCountNTSImpl::Release(result.pObject);
  Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
    (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->PrevTopmostEntity,
    &result);
  v3 = result.pObject;
  if ( result.pObject )
  {
    ++result.pObject->RefCount;
    v3 = result.pObject;
  }
  v8 = v3;
  if ( result.pObject )
    Scaleform::RefCountNTSImpl::Release(result.pObject);
  v4 = pObject != v3 || !pObject && (*((_BYTE *)this + 76) & 1) == 0 || !v3 && (*((_BYTE *)this + 76) & 2) == 0;
  if ( v3 )
    Scaleform::RefCountNTSImpl::Release(v3);
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  return v4;
}

