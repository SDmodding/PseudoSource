// File Line: 38
// RVA: 0x8F5660
void __fastcall Scaleform::GFx::KeyboardState::KeyQueue::Put(Scaleform::GFx::KeyboardState::KeyQueue *this, __int16 code, char ascii, unsigned int wcharCode, Scaleform::GFx::Event::EventType event, Scaleform::KeyModifiers specialKeysState)
{
  unsigned int v6; // eax

  if ( this->Count < 0x64 )
  {
    this->Buffer[this->PutIdx].code = code;
    this->Buffer[this->PutIdx].ascii = ascii;
    this->Buffer[this->PutIdx].wcharCode = wcharCode;
    this->Buffer[this->PutIdx].event = event;
    this->Buffer[this->PutIdx++].keyMods = specialKeysState;
    v6 = this->PutIdx;
    if ( v6 >= 0x64 )
      v6 = 0;
    ++this->Count;
    this->PutIdx = v6;
  }
}

// File Line: 70
// RVA: 0x898AA0
void __fastcall Scaleform::GFx::KeyboardState::KeyboardState(Scaleform::GFx::KeyboardState *this)
{
  Scaleform::GFx::KeyboardState *v1; // rbx
  Scaleform::GFx::KeyboardState::KeyQueue *v2; // rcx
  signed int v3; // edx
  Scaleform::KeyModifiers *v4; // rax

  v1 = this;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImplCore::`vftable;
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountImpl::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::RefCountBase<Scaleform::GFx::KeyboardState,2>::`vftable;
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::KeyboardState::`vftable;
  v2 = &this->KeyQueue;
  v3 = 99;
  v4 = &v2->Buffer[0].keyMods;
  do
  {
    v4->States = 0;
    v4 += 16;
    --v3;
  }
  while ( v3 >= 0 );
  *(_QWORD *)&v2->PutIdx = 0i64;
  v2->Count = 0;
  memset(v2, 0, 0x640ui64);
  v1->pListener = 0i64;
  v1->KeyboardIndex = 0;
  *(_QWORD *)v1->Keymap = 0i64;
  *(_QWORD *)&v1->Keymap[8] = 0i64;
  *(_QWORD *)&v1->Keymap[16] = 0i64;
  *(_DWORD *)&v1->Keymap[24] = 0;
  v1->Keymap[28] = 0;
  *(_WORD *)v1->Toggled = 0;
  v1->Toggled[2] = 0;
}

// File Line: 85
// RVA: 0x8E7390
bool __fastcall Scaleform::GFx::KeyboardState::IsKeyDown(Scaleform::GFx::KeyboardState *this, int code)
{
  bool result; // al

  if ( code > (unsigned int)ä )
    result = 0;
  else
    result = ((unsigned __int8)(1 << (code - 8 * (code >> 3))) & this->Keymap[code >> 3]) != 0;
  return result;
}

// File Line: 105
// RVA: 0x8E73D0
bool __fastcall Scaleform::GFx::KeyboardState::IsKeyToggled(Scaleform::GFx::KeyboardState *this, int code)
{
  int v2; // edx
  int v3; // edx

  v2 = code - 20;
  if ( !v2 )
    return this->Toggled[1];
  v3 = v2 - 124;
  if ( !v3 )
    return this->Toggled[0];
  if ( v3 == 1 )
    return this->Toggled[2];
  return 0;
}

// File Line: 119
// RVA: 0x8DA970
Scaleform::KeyModifiers *__fastcall Scaleform::GFx::KeyboardState::GetKeyModifiers(Scaleform::GFx::KeyboardState *this, Scaleform::KeyModifiers *result)
{
  char v2; // r8
  Scaleform::KeyModifiers *v3; // rax

  v2 = this->Keymap[2];
  result->States = 0;
  result->States = v2 & 4;
  if ( v2 & 2 )
    result->States |= 2u;
  else
    result->States &= 0xFDu;
  if ( v2 & 1 )
    result->States |= 1u;
  else
    result->States &= 0xFEu;
  if ( this->Toggled[0] )
    result->States |= 0x10u;
  else
    result->States &= 0xEFu;
  if ( this->Toggled[1] )
    result->States |= 8u;
  else
    result->States &= 0xF7u;
  v3 = result;
  if ( this->Toggled[2] )
    result->States |= 0x20u;
  else
    result->States &= 0xDFu;
  return v3;
}

// File Line: 204
// RVA: 0x917490
void __fastcall Scaleform::GFx::KeyboardState::UpdateListeners(Scaleform::GFx::KeyboardState *this, Scaleform::GFx::EventId *evt)
{
  Scaleform::GFx::KeyboardState::IListener *v2; // rcx

  v2 = this->pListener;
  if ( v2 )
    v2->vfptr->Update(v2, evt);
}

