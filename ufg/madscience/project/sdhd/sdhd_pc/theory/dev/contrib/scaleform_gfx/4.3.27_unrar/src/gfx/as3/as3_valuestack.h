// File Line: 149
// RVA: 0x807720
void __fastcall Scaleform::GFx::AS3::VSBase::PopBack(Scaleform::GFx::AS3::VSBase *this, unsigned int n)
{
  unsigned int v2; // edi
  Scaleform::GFx::AS3::Value *pCurrent; // rbx
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // rdx

  if ( n )
  {
    v2 = n;
    do
    {
      pCurrent = this->pCurrent;
      --v2;
      if ( (this->pCurrent->Flags & 0x1F) > 9 )
      {
        if ( (this->pCurrent->Flags & 0x200) != 0 )
        {
          pWeakProxy = pCurrent->Bonus.pWeakProxy;
          if ( pWeakProxy->RefCount-- == 1 )
            ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
          pCurrent->Flags &= 0xFFFFFDE0;
          pCurrent->Bonus.pWeakProxy = 0i64;
          pCurrent->value.VS._1.VStr = 0i64;
          pCurrent->value.VS._2.VObj = 0i64;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(this->pCurrent);
        }
      }
      --this->pCurrent;
    }
    while ( v2 );
  }
}

// File Line: 184
// RVA: 0x825420
void __fastcall Scaleform::GFx::AS3::VSBase::SwapTop(Scaleform::GFx::AS3::VSBase *this)
{
  Scaleform::GFx::AS3::Value *pCurrent; // rdx
  __int64 pWeakProxy; // rax
  __int64 VStr; // r10
  __int64 VObj; // r9
  Scaleform::GFx::AS3::Value *v5; // rdx
  Scaleform::GFx::AS3::Value *v6; // rdx
  __int64 v7[6]; // [rsp+8h] [rbp-30h] BYREF

  pCurrent = this->pCurrent;
  LODWORD(v7[0]) = this->pCurrent->Flags;
  pWeakProxy = (__int64)pCurrent->Bonus.pWeakProxy;
  v7[1] = pWeakProxy;
  VStr = (__int64)pCurrent->value.VS._1.VStr;
  v7[2] = VStr;
  VObj = (__int64)pCurrent->value.VS._2.VObj;
  v7[3] = VObj;
  pCurrent->Flags = 0;
  v5 = this->pCurrent;
  _mm_prefetch((const char *)&this->pCurrent[-1], 2);
  *v5 = v5[-1];
  v5[-1].Flags = 0;
  v6 = this->pCurrent;
  _mm_prefetch((const char *)v7, 2);
  *(_QWORD *)&v6[-1].Flags = v7[0];
  v6[-1].Bonus.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)pWeakProxy;
  v6[-1].value.VS._1.VStr = (Scaleform::GFx::ASStringNode *)VStr;
  v6[-1].value.VS._2.VObj = (Scaleform::GFx::AS3::Object *)VObj;
}

