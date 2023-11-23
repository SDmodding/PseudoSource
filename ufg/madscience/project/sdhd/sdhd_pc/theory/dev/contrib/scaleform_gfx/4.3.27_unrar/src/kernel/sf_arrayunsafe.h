// File Line: 96
// RVA: 0x9AB8A0
void __fastcall Scaleform::ArrayUnsafeBase<Scaleform::Render::Texture::UpdateDesc,Scaleform::AllocatorLH_POD<Scaleform::Render::Texture::UpdateDesc,2>>::Reserve(
        Scaleform::ArrayUnsafeBase<Scaleform::Render::Texture::UpdateDesc,Scaleform::AllocatorLH_POD<Scaleform::Render::Texture::UpdateDesc,2> > *this,
        unsigned __int64 cap,
        unsigned __int64 extraTail)
{
  Scaleform::Render::Texture::UpdateDesc *v6; // rax
  int v7; // [rsp+30h] [rbp+8h] BYREF

  if ( cap <= this->Capacity )
  {
    this->Size = 0i64;
  }
  else
  {
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Data);
    this->Capacity = cap + extraTail;
    if ( cap + extraTail )
    {
      v7 = 2;
      v6 = (Scaleform::Render::Texture::UpdateDesc *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                       Scaleform::Memory::pGlobalHeap,
                                                       this,
                                                       56 * (cap + extraTail),
                                                       &v7);
      this->Size = 0i64;
      this->Data = v6;
    }
    else
    {
      this->Data = 0i64;
      this->Size = 0i64;
    }
  }
}

