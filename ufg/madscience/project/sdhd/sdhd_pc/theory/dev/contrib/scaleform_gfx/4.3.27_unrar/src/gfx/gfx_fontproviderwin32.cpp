// File Line: 31
// RVA: 0x9FB2B0
void __fastcall Scaleform::GFx::FontProviderWin32::FontProviderWin32(Scaleform::GFx::FontProviderWin32 *this, HDC__ *dc)
{
  HDC__ *v2; // rbx
  Scaleform::GFx::FontProviderWin32 *v3; // rdi
  Scaleform::Render::FontProviderWinAPI *v4; // rax
  Scaleform::Render::FontProvider *v5; // rax
  Scaleform::Render::FontProvider *v6; // rbx

  v2 = dc;
  v3 = this;
  v4 = (Scaleform::Render::FontProviderWinAPI *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  112i64);
  if ( v4 )
  {
    Scaleform::Render::FontProviderWinAPI::FontProviderWinAPI(v4, v2);
    v6 = v5;
  }
  else
  {
    v6 = 0i64;
  }
  Scaleform::GFx::FontProvider::FontProvider((Scaleform::GFx::FontProvider *)&v3->vfptr, v6);
  if ( v6 )
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)v6);
  v3->vfptr = (Scaleform::RefCountImplCoreVtbl *)&Scaleform::GFx::FontProviderWin32::`vftable';
}

// File Line: 67
// RVA: 0x9FB3B0
void __fastcall ArrayOfTuplesImplementation::clear(ArrayOfTuplesImplementation *this)
{
  ((void (*)(void))this->m_impl->vfptr[2].__vecDelDtor)();
}

