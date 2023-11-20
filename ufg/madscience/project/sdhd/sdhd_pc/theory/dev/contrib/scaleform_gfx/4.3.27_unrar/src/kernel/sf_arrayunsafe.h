// File Line: 96
// RVA: 0x9AB8A0
void __fastcall Scaleform::ArrayUnsafeBase<Scaleform::Render::Texture::UpdateDesc,Scaleform::AllocatorLH_POD<Scaleform::Render::Texture::UpdateDesc,2>>::Reserve(Scaleform::ArrayUnsafeBase<Scaleform::Render::Texture::UpdateDesc,Scaleform::AllocatorLH_POD<Scaleform::Render::Texture::UpdateDesc,2> > *this, unsigned __int64 cap, unsigned __int64 extraTail)
{
  unsigned __int64 v3; // rsi
  unsigned __int64 v4; // rdi
  Scaleform::ArrayUnsafeBase<Scaleform::Render::Texture::UpdateDesc,Scaleform::AllocatorLH_POD<Scaleform::Render::Texture::UpdateDesc,2> > *v5; // rbx
  Scaleform::Render::Texture::UpdateDesc *v6; // rax
  int v7; // [rsp+30h] [rbp+8h]

  v3 = extraTail;
  v4 = cap;
  v5 = this;
  if ( cap <= this->Capacity )
  {
    this->Size = 0i64;
  }
  else
  {
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->Data);
    v5->Capacity = v4 + v3;
    if ( v4 + v3 )
    {
      v7 = 2;
      v6 = (Scaleform::Render::Texture::UpdateDesc *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                       Scaleform::Memory::pGlobalHeap,
                                                       v5,
                                                       56 * (v4 + v3),
                                                       (Scaleform::AllocInfo *)&v7);
      v5->Size = 0i64;
      v5->Data = v6;
    }
    else
    {
      v5->Data = 0i64;
      v5->Size = 0i64;
    }
  }
}

