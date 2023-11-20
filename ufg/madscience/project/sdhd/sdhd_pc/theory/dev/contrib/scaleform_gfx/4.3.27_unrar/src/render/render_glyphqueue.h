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
  Scaleform::Render::GlyphSlot *v2; // rbx
  Scaleform::Render::Fence *v4; // rax
  Scaleform::Render::FenceImpl *v5; // r8
  Scaleform::Render::Fence *v6; // rax
  Scaleform::Render::FenceImpl *v7; // r8
  Scaleform::Render::Fence *v8; // rcx

  v2 = slot;
  if ( slot->PinCount )
    return 1;
  if ( waitOn && (v4 = slot->SlotFence.pObject) != 0i64 )
  {
    if ( v4->HasData )
    {
      v5 = v4->Data;
      if ( v4->Data )
      {
        if ( v5->Parent )
          ((void (__fastcall *)(Scaleform::Render::RenderSync *, signed __int64, unsigned __int64))v5->RSContext->vfptr[5].__vecDelDtor)(
            v5->RSContext,
            1i64,
            v5->APIHandle);
      }
    }
  }
  else
  {
    v6 = slot->SlotFence.pObject;
    if ( v6 )
    {
      if ( v6->HasData )
      {
        v7 = v6->Data;
        if ( v6->Data )
        {
          if ( v7->Parent
            && ((unsigned __int8 (__fastcall *)(Scaleform::Render::RenderSync *, signed __int64, unsigned __int64))v7->RSContext->vfptr[4].__vecDelDtor)(
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
  v8 = v2->SlotFence.pObject;
  if ( v8 )
    Scaleform::Render::Fence::Release(v8);
  v2->SlotFence.pObject = 0i64;
  return 0;
}

