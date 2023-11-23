// File Line: 28
// RVA: 0x89A890
void __fastcall Scaleform::GFx::MouseState::MouseState(Scaleform::GFx::MouseState *this)
{
  this->TopmostEntity.pProxy.pObject = 0i64;
  this->PrevTopmostEntity.pProxy.pObject = 0i64;
  this->ActiveEntity.pProxy.pObject = 0i64;
  this->MouseButtonDownEntities.Data.Data = 0i64;
  this->MouseButtonDownEntities.Data.Size = 0i64;
  this->MouseButtonDownEntities.Data.Policy.Capacity = 0i64;
  this->mPresetCursorType = -1;
  *(_QWORD *)&this->CursorType = 0i64;
  *(_QWORD *)&this->CurButtonsState = 0i64;
  this->LastPosition = 0i64;
  *((_BYTE *)this + 76) &= 0xE0u;
}

// File Line: 107
// RVA: 0x909940
void __fastcall Scaleform::GFx::MouseState::SetMouseButtonDownEntity(
        Scaleform::GFx::MouseState *this,
        unsigned int buttonIdx,
        Scaleform::GFx::InteractiveObject *pch)
{
  __int64 v3; // rsi
  Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject> *v6; // rbx
  Scaleform::WeakPtrProxy *WeakProxy; // rax
  Scaleform::WeakPtrProxy *pObject; // rdx
  Scaleform::WeakPtrProxy *v9; // rdi
  bool v10; // zf
  Scaleform::WeakPtrProxy *v11; // rdx

  v3 = buttonIdx;
  if ( buttonIdx >= this->MouseButtonDownEntities.Data.Size )
    Scaleform::ArrayData<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>,Scaleform::AllocatorLH<Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>,2>,Scaleform::ArrayDefaultPolicy>::Resize(
      &this->MouseButtonDownEntities.Data,
      buttonIdx + 1);
  v6 = &this->MouseButtonDownEntities.Data.Data[v3];
  if ( pch )
  {
    WeakProxy = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy(pch);
    pObject = v6->pProxy.pObject;
    v9 = WeakProxy;
    if ( v6->pProxy.pObject )
    {
      v10 = pObject->RefCount-- == 1;
      if ( v10 )
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
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
        ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
    }
    v6->pProxy.pObject = 0i64;
  }
}

// File Line: 114
// RVA: 0x8DB160
Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *__fastcall Scaleform::GFx::MouseState::GetMouseButtonDownEntity(
        Scaleform::GFx::MouseState *this,
        Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *result,
        unsigned int buttonIdx)
{
  Scaleform::GFx::Sprite *pObject; // rax
  Scaleform::Ptr<Scaleform::GFx::Sprite> resulta; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *v7; // [rsp+48h] [rbp+10h]

  v7 = result;
  if ( buttonIdx < this->MouseButtonDownEntities.Data.Size )
  {
    Scaleform::WeakPtr<Scaleform::GFx::DisplayObject>::operator Scaleform::Ptr<Scaleform::GFx::DisplayObject>(
      (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&this->MouseButtonDownEntities.Data.Data[buttonIdx],
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
  }
  else
  {
    result->pObject = 0i64;
  }
  return result;
}

// File Line: 141
// RVA: 0x8B0CE0
Scaleform::GFx::InputEventsQueue *__fastcall Scaleform::GFx::InputEventsQueue::AddEmptyQueueEntry(
        Scaleform::GFx::InputEventsQueue *this)
{
  unsigned __int64 v1; // rax
  unsigned __int64 UsedEntries; // r8
  unsigned __int64 v3; // rdx

  if ( this->UsedEntries == 100 )
  {
    v1 = ++this->StartPos;
    this->UsedEntries = 99i64;
    if ( v1 == 100 )
      v1 = 0i64;
    this->StartPos = v1;
  }
  UsedEntries = this->UsedEntries;
  v3 = UsedEntries + this->StartPos;
  if ( v3 >= 0x64 )
    v3 -= 100i64;
  this->UsedEntries = UsedEntries + 1;
  return (Scaleform::GFx::InputEventsQueue *)((char *)this + 80 * v3);
}

// File Line: 273
// RVA: 0x8B0390
void __fastcall Scaleform::GFx::InputEventsQueue::AddAccelerometerEvent(
        Scaleform::GFx::InputEventsQueue *this,
        unsigned int idAcc,
        long double timestamp,
        long double accelerationX,
        long double accelerationY,
        long double accelerationZ)
{
  Scaleform::GFx::InputEventsQueueEntry *v7; // rax

  v7 = Scaleform::GFx::InputEventsQueue::AddEmptyQueueEntry(this);
  v7->t = QE_Accelerometer;
  v7->u.keyEntry.WcharCode = idAcc;
  v7->u.accelerometerEntry.Timestamp = timestamp;
  v7->u.accelerometerEntry.AccelerationX = accelerationX;
  v7->u.accelerometerEntry.AccelerationY = accelerationY;
  v7->u.accelerometerEntry.AccelerationZ = accelerationZ;
}

// File Line: 285
// RVA: 0x8B1360
void __fastcall Scaleform::GFx::InputEventsQueue::AddGeolocationEvent(
        Scaleform::GFx::InputEventsQueue *this,
        unsigned int idGeo,
        long double latitude,
        long double longitude,
        long double altitude,
        long double hAccuracy,
        long double vAccuracy,
        long double speed,
        long double heading,
        long double timestamp)
{
  Scaleform::GFx::InputEventsQueue *v11; // rax

  v11 = Scaleform::GFx::InputEventsQueue::AddEmptyQueueEntry(this);
  v11->Queue[0].t = QE_Geolocation;
  v11->Queue[0].u.keyEntry.WcharCode = idGeo;
  v11->Queue[0].u.accelerometerEntry.AccelerationY = altitude;
  v11->Queue[0].u.accelerometerEntry.AccelerationZ = hAccuracy;
  v11->Queue[0].u.geolocationEntry.VAccuracy = vAccuracy;
  v11->Queue[0].u.geolocationEntry.Speed = speed;
  v11->Queue[0].u.accelerometerEntry.Timestamp = latitude;
  v11->Queue[0].u.accelerometerEntry.AccelerationX = longitude;
  v11->Queue[0].u.geolocationEntry.Heading = heading;
  v11->Queue[0].u.geolocationEntry.Timestamp = timestamp;
}

// File Line: 301
// RVA: 0x8B2DE0
void __fastcall Scaleform::GFx::InputEventsQueue::AddStatusEvent(
        Scaleform::GFx::InputEventsQueue *this,
        Scaleform::String *code,
        Scaleform::String *level,
        Scaleform::String *extensionId,
        Scaleform::String *contextId)
{
  Scaleform::GFx::InputEventsQueue *v8; // rax

  v8 = Scaleform::GFx::InputEventsQueue::AddEmptyQueueEntry(this);
  v8->Queue[0].t = QE_Status;
  v8->Queue[0].u.statusEntry.Code = code;
  v8->Queue[0].u.statusEntry.ExtensionId = extensionId;
  v8->Queue[0].u.statusEntry.Level = level;
  v8->Queue[0].u.statusEntry.ContextId = contextId;
}

// File Line: 312
// RVA: 0x8D7420
Scaleform::GFx::InputEventsQueueEntry *__fastcall Scaleform::GFx::InputEventsQueue::GetEntry(
        Scaleform::GFx::InputEventsQueue *this)
{
  Scaleform::GFx::InputEventsQueueEntry *result; // rax
  unsigned int v3; // r9d
  int v4; // r10d
  unsigned __int64 v5; // rax
  unsigned __int64 UsedEntries; // rdx
  unsigned __int64 v7; // rcx
  Scaleform::GFx::InputEventsQueueEntry *v8; // rdx
  float y; // eax
  unsigned __int64 StartPos; // rdx
  unsigned __int64 v11; // rcx

  result = (Scaleform::GFx::InputEventsQueueEntry *)this->UsedEntries;
  if ( result )
    goto LABEL_13;
  v3 = 0;
  v4 = 1;
  do
  {
    if ( (v4 & this->LastMousePosMask) != 0 )
    {
      if ( this->UsedEntries == 100 )
      {
        v5 = ++this->StartPos;
        this->UsedEntries = 99i64;
        if ( v5 == 100 )
          v5 = 0i64;
        this->StartPos = v5;
      }
      UsedEntries = this->UsedEntries;
      v7 = UsedEntries + this->StartPos;
      if ( v7 >= 0x64 )
        v7 -= 100i64;
      this->UsedEntries = UsedEntries + 1;
      v8 = &this->Queue[v7];
      v8->t = QE_Mouse;
      v8->u.mouseEntry.MouseIndex = v3;
      v8->u.keyEntry.WcharCode = LODWORD(this->LastMousePos[v3].x);
      y = this->LastMousePos[v3].y;
      v8->u.mouseEntry.ButtonsState = 0;
      v8->u.mouseEntry.PosY = y;
      v8->u.mouseEntry.Flags = 64;
      this->LastMousePosMask &= ~v4;
    }
    ++v3;
    v4 *= 2;
  }
  while ( v3 < 6 );
  result = (Scaleform::GFx::InputEventsQueueEntry *)this->UsedEntries;
  if ( result )
  {
LABEL_13:
    StartPos = this->StartPos;
    this->UsedEntries = (unsigned __int64)&result[-1].u.statusEntry + 71;
    v11 = StartPos + 1;
    if ( StartPos == 99 )
      v11 = 0i64;
    result = &this->Queue[StartPos];
    this->StartPos = v11;
  }
  return result;
}

// File Line: 412
// RVA: 0x8BDDC0
__int64 __fastcall Scaleform::GFx::EventId::ConvertToButtonKeyCode(Scaleform::GFx::EventId *this)
{
  unsigned int v1; // r8d
  __int64 result; // rax
  unsigned __int8 AsciiCode; // al

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
      AsciiCode = this->AsciiCode;
      if ( AsciiCode >= 0x20u )
        v1 = AsciiCode;
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
  unsigned int KeyCode; // ecx
  __int64 v3; // rcx
  __int64 v5; // rcx

  v1 = this->KeysState.States & 1;
  if ( (this->KeysState.States & 8) != 0 )
    v1 = v1 == 0;
  KeyCode = this->KeyCode;
  if ( KeyCode - 32 > 0x50 )
  {
    if ( KeyCode - 186 > 0x50 )
    {
      return 0;
    }
    else
    {
      v5 = KeyCode - 186;
      if ( v1 )
        return asciiShift2[v5];
      else
        return ascii2[v5];
    }
  }
  else
  {
    v3 = KeyCode - 32;
    if ( v1 )
      return asciiShift1[v3];
    else
      return ascii1[v3];
  }
}

