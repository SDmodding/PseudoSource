// File Line: 243
// RVA: 0x8A50A0
void __fastcall Scaleform::GFx::ResourceKey::KeyInterface::~KeyInterface(Scaleform::GFx::ResourceKey::KeyInterface *this)
{
  this->vfptr = (Scaleform::GFx::ResourceKey::KeyInterfaceVtbl *)&Scaleform::GFx::ResourceKey::KeyInterface::`vftable;
}

// File Line: 277
// RVA: 0x6D2550
void __fastcall Scaleform::GFx::ResourceData::~ResourceData(Scaleform::GFx::ResourceKey *this)
{
  Scaleform::GFx::ResourceKey *v1; // rdx
  Scaleform::GFx::ResourceKey::KeyInterface *v2; // rcx

  v1 = this;
  v2 = this->pKeyInterface;
  if ( v2 )
    v2->vfptr->Release(v2, v1->hKeyData);
}

// File Line: 381
// RVA: 0x6D2510
void __fastcall Scaleform::GFx::Resource::~Resource(Scaleform::GFx::Resource *this)
{
  this->vfptr = (Scaleform::GFx::ResourceVtbl *)&Scaleform::GFx::Resource::`vftable;
}

// File Line: 442
// RVA: 0x6EFC60
Scaleform::GFx::ResourceKey *__fastcall Scaleform::GFx::Resource::GetKey(Scaleform::GFx::Resource *this, Scaleform::GFx::ResourceKey *result)
{
  Scaleform::GFx::ResourceKey *v2; // rbx

  v2 = result;
  AK::DSP::MultiChannelBiquadFilter<8>::Memories::Memories((AK::DSP::MultiChannelBiquadFilter<8>::Memories *)result);
  return v2;
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
  Scaleform::GFx::Resource *v1; // rbx
  Scaleform::GFx::ResourceLibBase *v2; // rcx

  if ( this->State == 1 )
  {
    v1 = this->pResource;
    if ( !_InterlockedDecrement(&v1->RefCount.Value) )
    {
      v2 = v1->pLib;
      if ( v2 )
      {
        v2->vfptr[1].__vecDelDtor((Scaleform::RefCountImplCore *)&v2->vfptr, (unsigned int)v1);
        v1->pLib = 0i64;
      }
      v1->vfptr->__vecDelDtor(v1, 1u);
    }
  }
  else if ( this->State >= 2 )
  {
    Scaleform::RefCountImpl::Release((Scaleform::Render::RenderBuffer *)this->pResource);
  }
}

// File Line: 811
// RVA: 0x8A9200
bool __fastcall Scaleform::GFx::ResourceWeakLib::ResourceNode::operator==(Scaleform::GFx::ResourceWeakLib::ResourceNode *this, Scaleform::GFx::ResourceKey *k)
{
  Scaleform::GFx::ResourceKey *v2; // rbx
  _QWORD *v3; // rax
  __int64 v4; // rbx
  bool result; // al
  Scaleform::GFx::ResourceLib::ResourceSlot *v6; // rdx
  Scaleform::GFx::ResourceKey::KeyInterface *v7; // rcx
  __int64 v8; // [rsp+28h] [rbp-20h]
  __int64 v9; // [rsp+30h] [rbp-18h]

  v2 = k;
  if ( this->Type )
  {
    v6 = this->pResolver;
    v7 = v6->Key.pKeyInterface;
    if ( v7 && v2->pKeyInterface )
      result = v7->vfptr->KeyEquals(v7, v6->Key.hKeyData, v2);
    else
      result = 0;
  }
  else
  {
    v3 = (_QWORD *)this->pResolver->vfptr[1].__vecDelDtor(
                     (Scaleform::RefCountImplCore *)this->pResolver,
                     (unsigned int)&v8);
    if ( *v3 && v2->pKeyInterface )
      v4 = (*(unsigned __int8 (__fastcall **)(_QWORD, _QWORD, Scaleform::GFx::ResourceKey *))(*(_QWORD *)*v3 + 40i64))(
             *v3,
             v3[1],
             v2);
    else
      LOBYTE(v4) = 0;
    if ( v8 )
      (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v8 + 16i64))(v8, v9);
    result = v4;
  }
  return result;
}

// File Line: 827
// RVA: 0x8A9BB0
__int64 __fastcall Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp::operator()(Scaleform::GFx::ResourceWeakLib::ResourceNode::HashOp *this, Scaleform::GFx::ResourceWeakLib::ResourceNode *node)
{
  __int64 v2; // rbp
  __int64 *v3; // rsi
  char v4; // bl
  __int64 v5; // r15
  __int64 v6; // r14
  Scaleform::GFx::ResourceLib::ResourceSlot *v7; // rbx
  Scaleform::GFx::ResourceKey::KeyInterface *v8; // rcx
  __int64 v9; // rdi
  __int64 v10; // rsi
  Scaleform::GFx::ResourceKey::KeyInterface *v12; // [rsp+30h] [rbp-48h]
  void *v13; // [rsp+38h] [rbp-40h]
  __int64 v14; // [rsp+40h] [rbp-38h]
  __int64 v15; // [rsp+48h] [rbp-30h]
  __int64 v16; // [rsp+50h] [rbp-28h]
  __int64 v17; // [rsp+58h] [rbp-20h]

  v2 = 0i64;
  if ( node->Type )
  {
    v7 = node->pResolver;
    v8 = v7->Key.pKeyInterface;
    if ( v8 )
      v8->vfptr->AddRef(v8, v7->Key.hKeyData);
    v6 = (__int64)v7->Key.pKeyInterface;
    v12 = v7->Key.pKeyInterface;
    v5 = (__int64)v7->Key.hKeyData;
    v13 = v7->Key.hKeyData;
    v3 = (__int64 *)&v12;
    v4 = 2;
  }
  else
  {
    v3 = (__int64 *)node->pResolver->vfptr[1].__vecDelDtor(
                      (Scaleform::RefCountImplCore *)node->pResolver,
                      (unsigned int)&v14);
    v4 = 1;
    v5 = (__int64)v13;
    v6 = (__int64)v12;
  }
  if ( *v3 )
    (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)*v3 + 8i64))(*v3, v3[1]);
  v9 = *v3;
  v16 = *v3;
  v10 = v3[1];
  v17 = v10;
  if ( v4 & 2 )
  {
    v4 &= 0xFDu;
    if ( v6 )
      (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v6 + 16i64))(v6, v5);
  }
  if ( v4 & 1 && v14 )
    (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v14 + 16i64))(v14, v15);
  if ( v9 )
    v2 = (*(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)v9 + 32i64))(v9, v10);
  if ( v9 )
    (*(void (__fastcall **)(__int64, __int64))(*(_QWORD *)v9 + 16i64))(v9, v10);
  return v2;
}

