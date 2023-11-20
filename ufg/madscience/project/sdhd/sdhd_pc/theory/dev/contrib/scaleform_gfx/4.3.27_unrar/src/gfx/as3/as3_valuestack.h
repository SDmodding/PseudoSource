// File Line: 149
// RVA: 0x807720
void __fastcall Scaleform::GFx::AS3::VSBase::PopBack(Scaleform::GFx::AS3::VSBase *this, unsigned int n)
{
  unsigned int v2; // edi
  Scaleform::GFx::AS3::VSBase *v3; // rsi
  Scaleform::GFx::AS3::Value *v4; // rbx
  Scaleform::GFx::AS3::WeakProxy *v5; // rdx
  bool v6; // zf

  if ( n )
  {
    v2 = n;
    v3 = this;
    do
    {
      v4 = v3->pCurrent;
      --v2;
      if ( (v3->pCurrent->Flags & 0x1F) > 9 )
      {
        if ( (v3->pCurrent->Flags >> 9) & 1 )
        {
          v5 = v4->Bonus.pWeakProxy;
          v6 = v5->RefCount-- == 1;
          if ( v6 )
            ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
          v4->Flags &= 0xFFFFFDE0;
          v4->Bonus.pWeakProxy = 0i64;
          v4->value.VNumber = 0.0;
          v4->value.VS._2.VObj = 0i64;
        }
        else
        {
          Scaleform::GFx::AS3::Value::ReleaseInternal(v3->pCurrent);
        }
      }
      --v3->pCurrent;
    }
    while ( v2 );
  }
}

// File Line: 184
// RVA: 0x825420
void __fastcall Scaleform::GFx::AS3::VSBase::SwapTop(Scaleform::GFx::AS3::VSBase *this)
{
  Scaleform::GFx::AS3::Value::Extra v1; // rax
  long double v2; // r10
  Scaleform::GFx::AS3::Value::V2U v3; // r9
  Scaleform::GFx::AS3::Value *v5; // rdx
  __int64 v6; // [rsp+8h] [rbp-30h]

  LODWORD(v6) = this->pCurrent->Flags;
  v1.pWeakProxy = (Scaleform::GFx::AS3::WeakProxy *)this->pCurrent->Bonus;
  v2 = this->pCurrent->value.VNumber;
  v3.VObj = (Scaleform::GFx::AS3::Object *)this->pCurrent->value.VS._2;
  this->pCurrent->Flags = 0;
  _RDX = this->pCurrent;
  __asm { prefetcht1 byte ptr [rdx-20h]; Prefetch to all cache levels }
  *(_QWORD *)&_RDX->Flags = *(_QWORD *)&this->pCurrent[-1].Flags;
  _RDX->Bonus.pWeakProxy = _RDX[-1].Bonus.pWeakProxy;
  _RDX->value.VNumber = _RDX[-1].value.VNumber;
  _RDX->value.VS._2.VObj = _RDX[-1].value.VS._2.VObj;
  _RDX[-1].Flags = 0;
  v5 = this->pCurrent;
  __asm { prefetcht1 byte ptr [rsp+38h+var_30]; Prefetch to all cache levels }
  *(_QWORD *)&v5[-1].Flags = v6;
  v5[-1].Bonus = v1;
  v5[-1].value.VNumber = v2;
  v5[-1].value.VS._2 = v3;
}

