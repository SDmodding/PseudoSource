// File Line: 28
// RVA: 0x89A890
void __fastcall Scaleform::GFx::MouseState::MouseState(Scaleform::GFx::MouseState *this)
{
  Scaleform::ArrayLH<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>,2,Scaleform::ArrayDefaultPolicy> *v1; // [rsp+28h] [rbp+10h]

  this->TopmostEntity.pProxy.pObject = 0i64;
  this->PrevTopmostEntity.pProxy.pObject = 0i64;
  this->ActiveEntity.pProxy.pObject = 0i64;
  v1 = &this->MouseButtonDownEntities;
  *(_OWORD *)&v1->Data.Data = 0ui64;
  v1->Data.Policy.Capacity = 0i64;
  this->mPresetCursorType = -1;
  *(_QWORD *)&this->CursorType = 0i64;
  *(_QWORD *)&this->CurButtonsState = 0i64;
  this->LastPosition = 0i64;
  *((_BYTE *)this + 76) &= 0xE0u;
}

// File Line: 107
// RVA: 0x909940
void __fastcall Scaleform::GFx::MouseState::SetMouseButtonDownEntity(Scaleform::GFx::MouseState *this, unsigned int buttonIdx, Scaleform::GFx::InteractiveObject *pch)
{
  __int64 v3; // rsi
  Scaleform::GFx::InteractiveObject *v4; // rdi
  Scaleform::GFx::MouseState *v5; // rbx
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject> *v6; // rbx
  Scaleform::WeakPtrProxy *v7; // rax
  Scaleform::WeakPtrProxy *v8; // rdx
  Scaleform::WeakPtrProxy *v9; // rdi
  bool v10; // zf
  Scaleform::WeakPtrProxy *v11; // rdx

  v3 = buttonIdx;
  v4 = pch;
  v5 = this;
  if ( buttonIdx >= this->MouseButtonDownEntities.Data.Size )
    Scaleform::ArrayData<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &this->MouseButtonDownEntities.Data,
      buttonIdx + 1);
  v6 = &v5->MouseButtonDownEntities.Data.Data[v3];
  if ( v4 )
  {
    v7 = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy((Scaleform::RefCountWeakSupportImpl *)&v4->vfptr);
    v8 = v6->pProxy.pObject;
    v9 = v7;
    if ( v6->pProxy.pObject )
    {
      v10 = v8->RefCount-- == 1;
      if ( v10 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    }
    v6->pProxy.pObject = v9;
  }
  else
  {
    v11 = v6->pProxy.pObject;
    if ( v6->pProxy.pObject )
    {
      v10 = v11->RefCount-- == 1;
      if ( v10 )
        ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
    }
    v6->pProxy.pObject = 0i64;
  }
}

// File Line: 114
// RVA: 0x8DB160
Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *__fastcall Scaleform::GFx::MouseState::GetMouseButtonDownEntity(Scaleform::GFx::MouseState *this, Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *result, unsigned int buttonIdx)
{
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v3; // rbx
  Scaleform::GFx::Sprite *v4; // rax
  Scaleform::Ptr<Scaleform::GFx::Sprite> resulta; // [rsp+40h] [rbp+8h]
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v7; // [rsp+48h] [rbp+10h]

  v7 = result;
  v3 = result;
  if ( buttonIdx < this->MouseButtonDownEntities.Data.Size )
  {
    Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
      (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->MouseButtonDownEntities.Data.Data[buttonIdx],
      &resulta);
    v4 = resulta.pObject;
    if ( resulta.pObject )
    {
      ++resulta.pObject->RefCount;
      v4 = resulta.pObject;
    }
    v3->pObject = (Scaleform::GFx::InteractiveObject *)&v4->vfptr;
    if ( resulta.pObject )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&resulta.pObject->vfptr);
  }
  else
  {
    result->pObject = 0i64;
  }
  return v3;
}

// File Line: 141
// RVA: 0x8B0CE0
Scaleform::GFx::InputEventsQueueEntry *__fastcall Scaleform::GFx::InputEventsQueue::AddEmptyQueueEntry(Scaleform::GFx::InputEventsQueue *this)
{
  unsigned __int64 v1; // rax
  unsigned __int64 v2; // r8
  unsigned __int64 v3; // rdx

  if ( this->UsedEntries == 100 )
  {
    v1 = ++this->StartPos;
    this->UsedEntries = 99i64;
    if ( v1 == 100 )
      v1 = 0i64;
    this->StartPos = v1;
  }
  v2 = this->UsedEntries;
  v3 = v2 + this->StartPos;
  if ( v3 >= 0x64 )
    v3 -= 100i64;
  this->UsedEntries = v2 + 1;
  return (Scaleform::GFx::InputEventsQueueEntry *)((char *)this + 80 * v3);
}

// File Line: 273
// RVA: 0x8B0390
void __fastcall Scaleform::GFx::InputEventsQueue::AddAccelerometerEvent(Scaleform::GFx::InputEventsQueue *this, int idAcc, long double timestamp, long double accelerationX, long double accelerationY, long double accelerationZ)
{
  int v6; // ebx
  Scaleform::GFx::InputEventsQueueEntry *v7; // rax

  v6 = idAcc;
  v7 = Scaleform::GFx::InputEventsQueue::AddEmptyQueueEntry(this);
  v7->t = 5;
  v7->u.keyEntry.WcharCode = v6;
  v7->u.accelerometerEntry.Timestamp = timestamp;
  v7->u.accelerometerEntry.AccelerationX = accelerationX;
  v7->u.accelerometerEntry.AccelerationY = accelerationY;
  v7->u.accelerometerEntry.AccelerationZ = accelerationZ;
}

// File Line: 285
// RVA: 0x8B1360
void __fastcall Scaleform::GFx::InputEventsQueue::AddGeolocationEvent(Scaleform::GFx::InputEventsQueue *this, int idGeo, long double latitude, long double longitude, long double altitude, long double hAccuracy, long double vAccuracy, long double speed, long double heading, long double timestamp)
{
  int v10; // ebx
  Scaleform::GFx::InputEventsQueueEntry *v11; // rax

  v10 = idGeo;
  v11 = Scaleform::GFx::InputEventsQueue::AddEmptyQueueEntry(this);
  v11->t = 6;
  v11->u.keyEntry.WcharCode = v10;
  v11->u.accelerometerEntry.AccelerationY = altitude;
  v11->u.accelerometerEntry.AccelerationZ = hAccuracy;
  v11->u.geolocationEntry.VAccuracy = vAccuracy;
  v11->u.geolocationEntry.Speed = speed;
  v11->u.accelerometerEntry.Timestamp = latitude;
  v11->u.accelerometerEntry.AccelerationX = longitude;
  v11->u.geolocationEntry.Heading = heading;
  v11->u.geolocationEntry.Timestamp = timestamp;
}

// File Line: 301
// RVA: 0x8B2DE0
void __fastcall Scaleform::GFx::InputEventsQueue::AddStatusEvent(Scaleform::GFx::InputEventsQueue *this, Scaleform::String *code, Scaleform::String *level, Scaleform::String *extensionId, Scaleform::String *contextId)
{
  Scaleform::String *v5; // rsi
  Scaleform::String *v6; // rdi
  Scaleform::String *v7; // rbx
  Scaleform::GFx::InputEventsQueueEntry *v8; // rax

  v5 = extensionId;
  v6 = level;
  v7 = code;
  v8 = Scaleform::GFx::InputEventsQueue::AddEmptyQueueEntry(this);
  v8->t = 7;
  v8->u.statusEntry.Code = v7;
  *(_QWORD *)&v8->u.accelerometerEntry.AccelerationX = v5;
  *(_QWORD *)&v8->u.accelerometerEntry.Timestamp = v6;
  *(_QWORD *)&v8->u.accelerometerEntry.AccelerationY = contextId;
}

// File Line: 312
// RVA: 0x8D7420
Scaleform::GFx::InputEventsQueueEntry *__fastcall Scaleform::GFx::InputEventsQueue::GetEntry(Scaleform::GFx::InputEventsQueue *this)
{
  Scaleform::GFx::InputEventsQueueEntry *result; // rax
  Scaleform::GFx::InputEventsQueue *v2; // r8
  unsigned int v3; // er9
  signed int v4; // er10
  unsigned __int64 v5; // rax
  unsigned __int64 v6; // rdx
  unsigned __int64 v7; // rcx
  signed __int64 v8; // rdx
  float v9; // eax
  unsigned __int64 v10; // rdx
  signed __int64 v11; // rcx

  result = (Scaleform::GFx::InputEventsQueueEntry *)this->UsedEntries;
  v2 = this;
  if ( result )
    goto LABEL_18;
  v3 = 0;
  v4 = 1;
  do
  {
    if ( v4 & v2->LastMousePosMask )
    {
      if ( v2->UsedEntries == 100 )
      {
        v5 = ++v2->StartPos;
        v2->UsedEntries = 99i64;
        if ( v5 == 100 )
          v5 = 0i64;
        v2->StartPos = v5;
      }
      v6 = v2->UsedEntries;
      v7 = v6 + v2->StartPos;
      if ( v7 >= 0x64 )
        v7 -= 100i64;
      v2->UsedEntries = v6 + 1;
      v8 = (signed __int64)&v2->Queue[v7];
      *(_DWORD *)v8 = 0;
      *(_BYTE *)(v8 + 20) = v3;
      *(float *)(v8 + 8) = v2->LastMousePos[v3].x;
      v9 = v2->LastMousePos[v3].y;
      *(_WORD *)(v8 + 16) = 0;
      *(float *)(v8 + 12) = v9;
      *(_BYTE *)(v8 + 19) = 64;
      v2->LastMousePosMask &= ~v4;
    }
    ++v3;
    v4 *= 2;
  }
  while ( v3 < 6 );
  result = (Scaleform::GFx::InputEventsQueueEntry *)v2->UsedEntries;
  if ( result )
  {
LABEL_18:
    v10 = v2->StartPos;
    v2->UsedEntries = (unsigned __int64)&result[-1].u.statusEntry + 71;
    v11 = v10 + 1;
    if ( v10 == 99 )
      v11 = 0i64;
    result = &v2->Queue[v10];
    v2->StartPos = v11;
  }
  return result;
}

// File Line: 412
// RVA: 0x8BDDC0
signed __int64 __fastcall Scaleform::GFx::EventId::ConvertToButtonKeyCode(Scaleform::GFx::EventId *this)
{
  unsigned int v1; // er8
  signed __int64 result; // rax
  unsigned __int8 v3; // al

  v1 = 0;
  switch ( this->KeyCode )
  {
    case 8u:
      result = 8i64;
      break;
    case 9u:
      result = 18i64;
      break;
    case 0xDu:
      result = 13i64;
      break;
    case 0x1Bu:
      result = 19i64;
      break;
    case 0x21u:
      result = 16i64;
      break;
    case 0x22u:
      result = 17i64;
      break;
    case 0x23u:
      result = 4i64;
      break;
    case 0x24u:
      result = 3i64;
      break;
    case 0x25u:
      result = 1i64;
      break;
    case 0x26u:
      result = 14i64;
      break;
    case 0x27u:
      result = 2i64;
      break;
    case 0x28u:
      result = 15i64;
      break;
    case 0x2Du:
      result = 5i64;
      break;
    case 0x2Eu:
      result = 6i64;
      break;
    default:
      v3 = this->AsciiCode;
      if ( v3 >= 0x20u )
        v1 = v3;
      result = v1;
      break;
  }
  return result;
}

// File Line: 440
// RVA: 0x8BDCE0
char __fastcall Scaleform::GFx::EventId::ConvertKeyCodeToAscii(Scaleform::GFx::EventId *this)
{
  char v1; // dl
  unsigned int v2; // ecx
  __int64 v3; // rcx
  char result; // al
  __int64 v5; // rcx

  v1 = this->KeysState.States & 1;
  if ( this->KeysState.States & 8 )
    v1 = v1 == 0;
  v2 = this->KeyCode;
  if ( v2 - 32 > 0x50 )
  {
    if ( v2 - 186 > 0x50 )
    {
      result = 0;
    }
    else
    {
      v5 = v2 - 186;
      if ( v1 )
        result = *(_BYTE *)(v5 + 5394558744i64);
      else
        result = *(_BYTE *)(v5 + 5394558704i64);
    }
  }
  else
  {
    v3 = v2 - 32;
    if ( v1 )
      result = *(_BYTE *)(v3 + 5394558624i64);
    else
      result = *(_BYTE *)(v3 + 5394558544i64);
  }
  return result;
}

