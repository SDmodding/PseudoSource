// File Line: 31
// RVA: 0x9FB2B0
void __fastcall Scaleform::GFx::FontProviderWin32::FontProviderWin32(
        Scaleform::GFx::FontProviderWin32 *this,
        HDC__ *dc)
{
  Scaleform::Render::FontProviderWinAPI *v4; // rax
  Scaleform::GFx::Resource *v5; // rax
  Scaleform::GFx::Resource *v6; // rbx

  v4 = (Scaleform::Render::FontProviderWinAPI *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  112i64);
  if ( v4 )
  {
    Scaleform::Render::FontProviderWinAPI::FontProviderWinAPI(v4, dc);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  Scaleform::GFx::FontProvider::FontProvider(this, v6);
  if ( v6 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v6);
  this->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontProviderWin32::`vftable;
}

// File Line: 67
// RVA: 0x9FB3B0
void __fastcall ArrayOfTuplesImplementation::clear(ArrayOfTuplesImplementation *this)
{
  ((void (__fastcall *)(hkDataArrayImpl *))this->m_impl->vfptr[2].__vecDelDtor)(this->m_impl);
}

