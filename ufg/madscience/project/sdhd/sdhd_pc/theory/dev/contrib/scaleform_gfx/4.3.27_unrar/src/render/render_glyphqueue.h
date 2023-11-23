// File Line: 56
// RVA: 0x94A930
void __fastcall Scaleform::Render::GlyphEvictNotifier::~GlyphEvictNotifier(Scaleform::Render::GlyphEvictNotifier *this)
{
  this->vfptr = (Scaleform::Render::GlyphEvictNotifierVtbl *)&Scaleform::Render::GlyphEvictNotifier::`vftable;
}

// File Line: 216
// RVA: 0x997C60
char __fastcall Scaleform::Render::GlyphQueue::IsPinned(Scaleform::Render::GlyphSlot *slot, bool waitOn)
{
  Scaleform::Render::Fence *v4; // rax
  Scaleform::Render::FenceImpl *Data; // r8
  Scaleform::Render::Fence *pObject; // rax
  Scaleform::Render::FenceImpl *v7; // r8
  Scaleform::Render::Fence *v8; // rcx

  if ( slot->PinCount )
    return 1;
  if ( waitOn && (v4 = slot->SlotFence.pObject) != 0i64 )
  {
    if ( v4->HasData )
    {
      Data = v4->Data;
      if ( v4->Data )
      {
        if ( Data->Parent )
          ((void (__fastcall *)(Scaleform::Render::RenderSync *, __int64, unsigned __int64))Data->RSContext->vfptr[5].__vecDelDtor)(
            Data->RSContext,
            1i64,
            Data->APIHandle);
      }
    }
  }
  else
  {
    pObject = slot->SlotFence.pObject;
    if ( pObject )
    {
      if ( pObject->HasData )
      {
        v7 = pObject->Data;
        if ( pObject->Data )
        {
          if ( v7->Parent
            && ((unsigned __int8 (__fastcall *)(Scaleform::Render::RenderSync *, __int64, unsigned __int64))v7->RSContext->vfptr[4].__vecDelDtor)(
                 v7->RSContext,
                 1i64,
                 v7->APIHandle) )
          {
            return 1;
          }
        }
      }
    }
  }
  v8 = slot->SlotFence.pObject;
  if ( v8 )
    Scaleform::Render::Fence::Release(v8);
  slot->SlotFence.pObject = 0i64;
  return 0;
}

