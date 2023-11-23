// File Line: 198
// RVA: 0x8184E0
void __fastcall Scaleform::GFx::InteractiveObject::SetBlendMode(
        Scaleform::GFx::InteractiveObject *this,
        Scaleform::Render::BlendMode blend)
{
  Scaleform::GFx::DisplayObjectBase::SetBlendMode(this, blend);
  _((AMD_HD3D *)this);
}

// File Line: 259
// RVA: 0x7E97C0
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::InteractiveObject::GetFocusRect(
        Scaleform::GFx::InteractiveObject *this,
        Scaleform::Render::Rect<float> *result)
{
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // rax
  __int128 v5[2]; // [rsp+20h] [rbp-28h] BYREF

  vfptr = this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
  v5[0] = _xmm;
  v5[1] = (__int128)_xmm;
  ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::Render::Rect<float> *, __int128 *))vfptr[61].__vecDelDtor)(
    this,
    result,
    v5);
  return result;
}

// File Line: 270
// RVA: 0x804A90
void __fastcall Scaleform::GFx::InteractiveObject::OnKeyEvent(
        Scaleform::GFx::InteractiveObject *this,
        Scaleform::GFx::EventId *id)
{
  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[72].__vecDelDtor(
    this,
    (unsigned int)id);
}

// File Line: 295
// RVA: 0x80A650
void __fastcall Scaleform::GFx::InteractiveObject::PropagateKeyEvent(
        Scaleform::GFx::InteractiveObject *this,
        Scaleform::GFx::EventId *id,
        int *pkeyMask)
{
  ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::GFx::EventId *, int *))this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[96].__vecDelDtor)(
    this,
    id,
    pkeyMask);
}

// File Line: 300
// RVA: 0x818CB0
void __fastcall Scaleform::GFx::InteractiveObject::SetDisplayCallback(
        Scaleform::GFx::InteractiveObject *this,
        void (__fastcall *callback)(void *),
        void *userPtr)
{
  this->pDisplayCallback = callback;
  this->DisplayCallbackUserPtr = userPtr;
}

// File Line: 305
// RVA: 0x7C6650
void __fastcall Scaleform::GFx::InteractiveObject::DoDisplayCallback(Scaleform::GFx::InteractiveObject *this)
{
  void (__fastcall *pDisplayCallback)(void *); // rax

  pDisplayCallback = this->pDisplayCallback;
  if ( pDisplayCallback )
    pDisplayCallback(this->DisplayCallbackUserPtr);
}

// File Line: 319
// RVA: 0x703070
void __fastcall Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayList(
        Scaleform::GFx::InteractiveObject *this,
        __int64 a2)
{
  unsigned int Flags; // ecx
  int v4; // eax

  Flags = this->Flags;
  if ( (Flags & 0x200000) == 0 || (Flags & 0x400000) != 0 )
    a2 = 0i64;
  else
    LOBYTE(a2) = 1;
  v4 = (int)this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[103].__vecDelDtor(
              this,
              a2);
  if ( v4 == -1 )
  {
    this->Flags |= 0x400000u;
  }
  else if ( v4 == 1 )
  {
    Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(this);
  }
}

// File Line: 332
// RVA: 0x6C1470
void __fastcall Scaleform::GFx::InteractiveObject::ModifyOptimizedPlayListLocal<Scaleform::GFx::TextField>(
        Scaleform::GFx::InteractiveObject *this)
{
  unsigned int Flags; // ecx
  bool v3; // dl
  int v4; // eax

  Flags = this->Flags;
  v3 = (Flags & 0x200000) != 0 && (Flags & 0x400000) == 0;
  v4 = Scaleform::GFx::TextField::CheckAdvanceStatus((Scaleform::GFx::TextField *)this, v3);
  if ( v4 == -1 )
  {
    this->Flags |= 0x400000u;
  }
  else if ( v4 == 1 )
  {
    Scaleform::GFx::InteractiveObject::AddToOptimizedPlayList(this);
  }
}

// File Line: 346
// RVA: 0x80A640
void __fastcall Scaleform::GFx::InteractiveObject::PropagateFocusGroupMask(
        Scaleform::GFx::InteractiveObject *this,
        unsigned __int16 mask)
{
  this->FocusGroupMask = mask;
}

// File Line: 395
// RVA: 0x81E7A0
void __fastcall Scaleform::GFx::InteractiveObject::SetStateChangeFlags(
        Scaleform::GFx::InteractiveObject *this,
        char flags)
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

