// File Line: 243
// RVA: 0x8A50A0
void __fastcall Scaleform::GFx::ResourceKey::KeyInterface::~KeyInterface(
        Scaleform::GFx::ResourceKey::KeyInterface *this)
{
  this->vfptr = (Scaleform::GFx::ResourceKey::KeyInterfaceVtbl *)&Scaleform::GFx::ResourceKey::KeyInterface::`vftable;
}

// File Line: 277
// RVA: 0x6D2550
void __fastcall Scaleform::GFx::ResourceData::~ResourceData(Scaleform::GFx::ResourceKey *this)
{
  Scaleform::GFx::ResourceKey::KeyInterface *pKeyInterface; // rcx

  pKeyInterface = this->pKeyInterface;
  if ( pKeyInterface )
    pKeyInterface->vfptr->Release(pKeyInterface, this->hKeyData);
}

// File Line: 381
// RVA: 0x6D2510
void __fastcall Scaleform::GFx::Resource::~Resource(Scaleform::GFx::Resource *this)
{
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable;
}

// File Line: 442
// RVA: 0x6EFC60
AK::DSP::MultiChannelBiquadFilter<8>::Memories *__fastcall Scaleform::GFx::Resource::GetKey(
        Scaleform::GFx::Resource *this,
        AK::DSP::MultiChannelBiquadFilter<8>::Memories *result)
{
  AK::DSP::MultiChannelBiquadFilter<8>::Memories::Memories(result);
  return result;
}

// File Line: 473
// RVA: 0x8A7400
void __fastcall Scaleform::GFx::ResourceReport::~ResourceReport(Scaleform::GFx::ResourceReport *this)
{
  this->vfptr = (Scaleform::GFx::ResourceReportVtbl *)&Scaleform::GFx::ResourceReport::`vftable;
}

// File Line: 692
// RVA: 0x8A32D0
void __fastcall Scaleform::GFx::ResourceLib::BindHandle::~BindHandle(Scaleform::GFx::ResourceLib::BindHandle *this)
{
  Scaleform::GFx::Resource *pResource; // rbx
  Scaleform::GFx::ResourceLibBase *pLib; // rcx

  if ( this->State == RS_Available )
  {
    pResource = this->pResource;
    if ( !_InterlockedDecrement(&pResource->RefCount.Value) )
    {
      pLib = pResource->pLib;
      if ( pLib )
      {
        pLib->vfptr[1].__vecDelDtor(pLib, (unsigned int)pResource);
        pResource->pLib = 0i64;
      }
      pResource->vfptr->__vecDelDtor(pResource, 1u);
    }
  }
  else if ( this->State >= RS_WaitingResolve )
  {
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)this->pResource);
  }
}

// File Line: 811
// RVA: 0x8A9200
char __fastcall Scaleform::GFx::ResourceWeakLib::ResourceNode::operator==(
        Scaleform::GFx::ResourceWeakLib::ResourceNode *this,
        Scaleform::GFx::ResourceKey *k)
{
  _QWORD *v3; // rax
  char v4; // bl
  Scaleform::GFx::ResourceLib::ResourceSlot *pResolver; // rdx
  Scaleform::GFx::ResourceKey::KeyInterface *pKeyInterface; // rcx
  __int64 v8[4]; // [rsp+28h] [rbp-20h] BYREF

  if ( this->Type )
  {
    pResolver = this->pResolver;
    pKeyInterface = pResolver->Key.pKeyInterface;
    return pKeyInterface
        && k->pKeyInterface
        && pKeyInterface->vfptr->KeyEquals(pKeyInterface, pResolver->Key.hKeyData, k);
  }
  else
  {
    v3 = this->pResolver->vfptr[1].__vecDelDtor(this->pResolver, v8);
    if ( *v3 && k->pKeyInterface )
      v4 = (*(__int64 (__fastcall **)(_QWORD, _QWORD, Scaleform::GFx::ResourceKey *))(*(_QWORD *)*v3 + 40i64))(
             *v3,
             v3[1],
             k);
    else
      v4 = 0;
    if ( v8[0] )
      (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v8[0] + 16i64))(v8[0], v8[1]);
    return v4;
  }
}

// File Line: 827
// RVA: 0x8A9BB0
__int64 __fastcall Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp::operator()(
        Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp *this,
        Scaleform::GFx::ResourceWeakLib::ResourceNode *node)
{
  __int64 v2; // rbp
  __int64 *v3; // rsi
  char v4; // bl
  __int64 hKeyData; // r15
  __int64 v6; // r14
  Scaleform::GFx::ResourceLib::ResourceSlot *pResolver; // rbx
  Scaleform::GFx::ResourceKey::KeyInterface *pKeyInterface; // rcx
  __int64 v9; // rdi
  __int64 v10; // rsi
  __int64 v12; // [rsp+30h] [rbp-48h] BYREF
  __int64 v13; // [rsp+38h] [rbp-40h]
  __int64 v14[4]; // [rsp+40h] [rbp-38h] BYREF

  v2 = 0i64;
  if ( node->Type )
  {
    pResolver = node->pResolver;
    pKeyInterface = pResolver->Key.pKeyInterface;
    if ( pKeyInterface )
      pKeyInterface->vfptr->AddRef(pKeyInterface, pResolver->Key.hKeyData);
    v6 = (__int64)pResolver->Key.pKeyInterface;
    v12 = v6;
    hKeyData = (__int64)pResolver->Key.hKeyData;
    v13 = hKeyData;
    v3 = &v12;
    v4 = 2;
  }
  else
  {
    v3 = (__int64 *)node->pResolver->vfptr[1].__vecDelDtor(node->pResolver, v14);
    v4 = 1;
    hKeyData = v13;
    v6 = v12;
  }
  if ( *v3 )
    (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)*v3 + 8i64))(*v3, v3[1]);
  v9 = *v3;
  v14[2] = *v3;
  v10 = v3[1];
  v14[3] = v10;
  if ( (v4 & 2) != 0 )
  {
    v4 &= ~2u;
    if ( v6 )
      (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v6 + 16i64))(v6, hKeyData);
  }
  if ( (v4 & 1) != 0 && v14[0] )
    (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v14[0] + 16i64))(v14[0], v14[1]);
  if ( v9 )
    v2 = (*(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)v9 + 32i64))(v9, v10);
  if ( v9 )
    (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v9 + 16i64))(v9, v10);
  return v2;
}

