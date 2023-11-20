// File Line: 198
// RVA: 0x8184E0
void __fastcall Scaleform::GFx::InteractiveObject::SetBlendMode(Scaleform::GFx::InteractiveObject *this, Scaleform::Render::BlendMode blend)
{
  Scaleform::GFx::InteractiveObject *v2; // rbx

  v2 = this;
  Scaleform::GFx::DisplayObjectBase::SetBlendMode((Scaleform::GFx::DisplayObjectBase *)&this->vfptr, blend);
  _((AMD_HD3D *)v2);
}

// File Line: 259
// RVA: 0x7E97C0
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::InteractiveObject::GetFocusRect(Scaleform::GFx::InteractiveObject *this, Scaleform::Render::Rect<float> *result)
{
  Scaleform::RefCountNTSImplCoreVtbl *v2; // rax
  Scaleform::Render::Rect<float> *v3; // rbx
  __int128 v5; // [rsp+20h] [rbp-28h]
  __m128 v6; // [rsp+30h] [rbp-18h]

  v2 = this->vfptr;
  v3 = result;
  v5 = _xmm;
  v6 = _xmm;
  ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::Render::Rect<float> *, __int128 *))v2[61].__vecDelDtor)(
    this,
    result,
    &v5);
  return v3;
}

// File Line: 270
// RVA: 0x804A90
void __fastcall Scaleform::GFx::InteractiveObject::OnKeyEvent(Scaleform::GFx::InteractiveObject *this, Scaleform::GFx::EventId *id)
{
  this->vfptr[72].__vecDelDtor((Scaleform::RefCountNTSImplCore *)this, (unsigned int)id);
}

// File Line: 295
// RVA: 0x80A650
void __fastcall Scaleform::GFx::InteractiveObject::PropagateKeyEvent(Scaleform::GFx::InteractiveObject *this, Scaleform::GFx::EventId *id, int *pkeyMask)
{
  ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::GFx::EventId *, int *))this->vfptr[96].__vecDelDtor)(
    this,
    id,
    pkeyMask);
}

// File Line: 300
// RVA: 0x818CB0
void __fastcall Scaleform::GFx::InteractiveObject::SetDisplayCallback(Scaleform::GFx::InteractiveObject *this, void (__fastcall *callback)(void *), void *userPtr)
{
  this->pDisplayCallback = callback;
  this->DisplayCallbackUserPtr = userPtr;
}

// File Line: 305
// RVA: 0x7C6650
void __fastcall Scaleform::GFx::InteractiveObject::DoDisplayCallback(Scaleform::GFx::InteractiveObject *this)
{
  void (__fastcall *v1)(void *); // rax

  v1 = this->pDisplayCallback;
  if ( v1 )
    v1(this->DisplayCallbackUserPtr);
}

// File Line: 319
// RVA: 0x703070
void __fastcall Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayList(Scaleform::GFx::InteractiveObject *this, __int64 a2)
{
  Scaleform::GFx::InteractiveObject *v2; // rbx
  unsigned int v3; // ecx
  int v4; // eax

  v2 = this;
  v3 = this->Flags;
  if ( !((v3 >> 21) & 1) || (v3 >> 22) & 1 )
    a2 = 0i64;
  else
    LOBYTE(a2) = 1;
  v4 = (__int64)v2->vfptr[103].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, a2);
  if ( v4 == -1 )
  {
    v2->Flags |= 0x400000u;
  }
  else if ( v4 == 1 )
  {
    Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(v2);
  }
}

// File Line: 332
// RVA: 0x6C1470
void __fastcall Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayListLocal<Scaleform::GFx::TextField>(Scaleform::GFx::InteractiveObject *this)
{
  Scaleform::GFx::TextField *v1; // rbx
  unsigned int v2; // ecx
  bool v3; // dl
  int v4; // eax

  v1 = (Scaleform::GFx::TextField *)this;
  v2 = this->Flags;
  v3 = (v2 >> 21) & 1 && !((v2 >> 22) & 1);
  v4 = Scaleform::GFx::TextField::CheckAdvanceStatus(v1, v3);
  if ( v4 == -1 )
  {
    v1->Flags |= 0x400000u;
  }
  else if ( v4 == 1 )
  {
    Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList((Scaleform::GFx::InteractiveObject *)&v1->vfptr);
  }
}

// File Line: 346
// RVA: 0x80A640
void __fastcall Scaleform::GFx::InteractiveObject::PropagateFocusGroupMask(Scaleform::GFx::InteractiveObject *this, unsigned int mask)
{
  this->FocusGroupMask = mask;
}

// File Line: 395
// RVA: 0x81E7A0
void __fastcall Scaleform::GFx::InteractiveObject::SetStateChangeFlags(Scaleform::GFx::InteractiveObject *this, char flags)
{
  this->Flags &= 0xFFF0FFFF;
  this->Flags |= (flags & 0xF) << 16;
}

// File Line: 398
// RVA: 0x7EFEB0
__int64 __fastcall Scaleform::GFx::InteractiveObject::GetStateChangeFlags(Scaleform::GFx::InteractiveObject *this)
{
  return HIWORD(this->Flags) & 0xF;
}

