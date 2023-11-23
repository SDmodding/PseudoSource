// File Line: 69
// RVA: 0x949010
void __fastcall Scaleform::Render::CacheEffectChain::~CacheEffectChain(Scaleform::Render::CacheEffectChain *this)
{
  Scaleform::Render::CacheEffect *pEffect; // rbx
  Scaleform::Render::CacheEffect *v2; // rcx

  pEffect = this->pEffect;
  while ( pEffect )
  {
    v2 = pEffect;
    pEffect = pEffect->pNext;
    v2->vfptr->__vecDelDtor(v2, 1u);
  }
}

// File Line: 81
// RVA: 0x9BE250
char __fastcall Scaleform::Render::CacheEffectChain::UpdateEffects(
        Scaleform::Render::CacheEffectChain *this,
        Scaleform::Render::TreeCacheNode *node,
        unsigned int changeFlags)
{
  Scaleform::Render::TreeNode *pNode; // r9
  char v4; // r13
  unsigned int v5; // ebp
  Scaleform::Render::TreeCacheNode *v6; // r10
  Scaleform::Render::CacheEffectChain *p_pNext; // r12
  Scaleform::Render::CacheEffect *pEffect; // rbx
  unsigned __int64 v10; // rdi
  unsigned __int64 i; // r14
  __int64 Type; // rsi
  Scaleform::Render::StateData::Interface *v13; // r8
  __int64 v14; // r9
  Scaleform::Render::CacheEffect *pNext; // rbp
  unsigned __int64 v16; // rcx
  __int64 v17; // rdx
  unsigned __int64 v18; // rdx
  unsigned __int64 v19; // rcx
  Scaleform::Render::StateData::Interface **v20; // rax
  unsigned __int64 v21; // rcx
  Scaleform::Render::StateData::Interface *v22; // r8
  Scaleform::Render::State *v23; // rdx
  unsigned __int64 v24; // rdx
  unsigned __int64 v25; // rcx
  Scaleform::Render::StateData::Interface **v26; // rax
  Scaleform::Render::CacheEffect *v27; // rax

  pNode = node->pNode;
  v4 = 0;
  v5 = changeFlags;
  v6 = node;
  p_pNext = this;
  if ( !pNode )
    return 0;
  pEffect = this->pEffect;
  v10 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)pNode & 0xFFFFFFFFFFFFF000ui64) + 0x28)
                  + 8i64 * (unsigned int)((int)((_DWORD)pNode - ((unsigned int)pNode & 0xFFFFF000) - 56) / 56)
                  + 40) & 0xFFFFFFFFFFFFFFFEui64;
  if ( !this->pEffect && !*(_QWORD *)(v10 + 64) )
    return 0;
  for ( i = 0i64; i < 6; ++i )
  {
    if ( pEffect )
    {
      Type = Scaleform::Render::ChainOrderSequence[i].Type;
      if ( pEffect->vfptr->GetType(pEffect) == (_DWORD)Type )
      {
        pNext = pEffect->pNext;
        if ( (changeFlags & Scaleform::Render::ChainOrderSequence[i].ChangeFlag) != 0 )
        {
          v16 = *(_QWORD *)(v10 + 64);
          if ( !v16 )
            goto LABEL_18;
          v13 = StateType_Interfaces[Type];
          if ( (v16 & 1) != 0 )
          {
            if ( (Scaleform::Render::StateData::Interface *)(v16 & 0xFFFFFFFFFFFFFFFEui64) != v13 )
              goto LABEL_18;
            v17 = v10 + 64;
          }
          else
          {
            v18 = 0i64;
            v14 = *(_QWORD *)(v10 + 72) + 4i64;
            v19 = v16 >> 1;
            if ( !v19 )
              goto LABEL_18;
            v20 = (Scaleform::Render::StateData::Interface **)(*(_QWORD *)(v10 + 72) + 4i64);
            while ( *v20 != v13 )
            {
              ++v18;
              v20 += 2;
              if ( v18 >= v19 )
                goto LABEL_18;
            }
            v17 = v14 + 16 * v18;
          }
          if ( !v17 )
          {
LABEL_18:
            ((void (__fastcall *)(Scaleform::Render::CacheEffect *, __int64, Scaleform::Render::StateData::Interface *, __int64))pEffect->vfptr->__vecDelDtor)(
              pEffect,
              1i64,
              v13,
              v14);
            p_pNext->pEffect = pNext;
            pEffect = pNext;
            v5 = changeFlags;
            v4 = 1;
            goto LABEL_38;
          }
          v4 |= ((__int64 (__fastcall *)(Scaleform::Render::CacheEffect *))pEffect->vfptr->Update)(pEffect);
        }
        p_pNext = (Scaleform::Render::CacheEffectChain *)&pEffect->pNext;
        pEffect = pNext;
        v5 = changeFlags;
        goto LABEL_38;
      }
      v6 = node;
    }
    if ( (v5 & Scaleform::Render::ChainOrderSequence[i].ChangeFlag) != 0 )
    {
      v21 = *(_QWORD *)(v10 + 64);
      if ( v21 )
      {
        v22 = StateType_Interfaces[Scaleform::Render::ChainOrderSequence[i].Type];
        if ( (v21 & 1) != 0 )
        {
          if ( (Scaleform::Render::StateData::Interface *)(v21 & 0xFFFFFFFFFFFFFFFEui64) != v22 )
            goto LABEL_38;
          v23 = (Scaleform::Render::State *)(v10 + 64);
        }
        else
        {
          v24 = 0i64;
          v25 = v21 >> 1;
          if ( !v25 )
            goto LABEL_38;
          v26 = (Scaleform::Render::StateData::Interface **)(*(_QWORD *)(v10 + 72) + 4i64);
          while ( *v26 != v22 )
          {
            ++v24;
            v26 += 2;
            if ( v24 >= v25 )
              goto LABEL_38;
          }
          v23 = (Scaleform::Render::State *)(*(_QWORD *)(v10 + 72) + 4i64 + 16 * v24);
        }
        if ( v23 )
        {
          v27 = Scaleform::Render::ChainOrderSequence[i].Factory(v6, v23, pEffect);
          if ( v27 )
          {
            p_pNext->pEffect = v27;
            p_pNext = (Scaleform::Render::CacheEffectChain *)&v27->pNext;
          }
        }
      }
    }
LABEL_38:
    v6 = node;
  }
  return v4;
}

// File Line: 153
// RVA: 0x9F8B20
void __fastcall Scaleform::Render::CacheEffectChain::updateBundleChain(
        Scaleform::Render::CacheEffectChain *this,
        Scaleform::Render::CacheEffect *effect,
        Scaleform::Render::BundleEntryRange *chain,
        Scaleform::Render::BundleEntryRange *maskChain)
{
  Scaleform::Render::CacheEffect *pNext; // rdx

  pNext = effect->pNext;
  if ( pNext )
    Scaleform::Render::CacheEffectChain::updateBundleChain(this, pNext, chain, maskChain);
  effect->vfptr->ChainNext(effect, chain, maskChain);
}

// File Line: 172
// RVA: 0x93E580
void __fastcall Scaleform::Render::MaskEffect::MaskEffect(
        Scaleform::Render::MaskEffect *this,
        Scaleform::Render::TreeCacheNode *node,
        Scaleform::Render::MaskEffectState mes,
        Scaleform::Render::MatrixPoolImpl::HMatrix *areaMatrix,
        Scaleform::Render::CacheEffect *next)
{
  Scaleform::Render::SortKeyInterface *v9; // rdi
  struct Scaleform::Render::SKI_MaskEnd *v10; // rdi
  struct Scaleform::Render::SKI_MaskEnd *v11; // rdi
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // rax

  this->vfptr = (Scaleform::Render::CacheEffectVtbl *)&Scaleform::Render::CacheEffect::`vftable;
  this->pNext = next;
  this->Length = 0;
  this->vfptr = (Scaleform::Render::CacheEffectVtbl *)&Scaleform::Render::MaskEffect::`vftable;
  v9 = SortKeyMaskInterfaces[0];
  SortKeyMaskInterfaces[0]->vfptr->AddRef(SortKeyMaskInterfaces[0], 0i64);
  this->StartEntry.pNextPattern = 0i64;
  this->StartEntry.pChain = 0i64;
  *(_DWORD *)&this->StartEntry.ChainHeight = 0;
  this->StartEntry.Key.pImpl = v9;
  this->StartEntry.Key.Data = 0i64;
  v9->vfptr->AddRef(v9, 0i64);
  this->StartEntry.pBundle.pObject = 0i64;
  this->StartEntry.pSourceNode = node;
  this->StartEntry.Removed = 0;
  v9->vfptr->Release(v9, 0i64);
  v10 = off_1420BB4C8[0];
  off_1420BB4C8[0]->vfptr->AddRef(off_1420BB4C8[0], (void *)1);
  this->EndEntry.pNextPattern = 0i64;
  this->EndEntry.pChain = 0i64;
  *(_DWORD *)&this->EndEntry.ChainHeight = 0;
  this->EndEntry.Key.pImpl = v10;
  this->EndEntry.Key.Data = (void *)1;
  v10->vfptr->AddRef(v10, (void *)1);
  this->EndEntry.pBundle.pObject = 0i64;
  this->EndEntry.pSourceNode = node;
  this->EndEntry.Removed = 0;
  v10->vfptr->Release(v10, (void *)1);
  v11 = off_1420BB4D0;
  off_1420BB4D0->vfptr->AddRef(off_1420BB4D0, (void *)2);
  this->PopEntry.pNextPattern = 0i64;
  this->PopEntry.pChain = 0i64;
  *(_DWORD *)&this->PopEntry.ChainHeight = 0;
  this->PopEntry.Key.pImpl = v11;
  this->PopEntry.Key.Data = (void *)2;
  v11->vfptr->AddRef(v11, (void *)2);
  this->PopEntry.pBundle.pObject = 0i64;
  this->PopEntry.pSourceNode = node;
  this->PopEntry.Removed = 0;
  v11->vfptr->Release(v11, (void *)2);
  this->MES = mes;
  pHandle = areaMatrix->pHandle;
  this->BoundsMatrix = (Scaleform::Render::MatrixPoolImpl::HMatrix)areaMatrix->pHandle;
  if ( pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    ++pHandle->pHeader->RefCount;
}

// File Line: 185
// RVA: 0x9BBFE0
char __fastcall Scaleform::Render::MaskEffect::Update(
        Scaleform::Render::MaskEffect *this,
        Scaleform::Render::State *stateArg)
{
  char v3; // si
  Scaleform::Render::TreeCacheNode *pSourceNode; // rbx
  Scaleform::Render::MaskEffectState v6; // ebp
  Scaleform::Render::SortKeyInterface *v7; // rbx
  Scaleform::Render::Rect<float> maskBounds; // [rsp+30h] [rbp-B8h] BYREF
  Scaleform::Render::Matrix2x4<float> boundAreaMatrix; // [rsp+40h] [rbp-A8h] BYREF
  Scaleform::Render::Matrix3x4<float> Dst; // [rsp+60h] [rbp-88h] BYREF
  __int64 v11; // [rsp+90h] [rbp-58h]
  Scaleform::Render::Matrix4x4<float> pviewProj; // [rsp+A0h] [rbp-48h] BYREF

  v11 = -2i64;
  v3 = 0;
  pSourceNode = this->StartEntry.pSourceNode;
  if ( !pSourceNode )
    return 0;
  maskBounds = 0i64;
  *(_OWORD *)&boundAreaMatrix.M[0][0] = _xmm;
  *(__m128 *)&boundAreaMatrix.M[1][0] = _xmm;
  memset(&Dst, 0, sizeof(Dst));
  Dst.M[0][0] = 1.0;
  Dst.M[1][1] = 1.0;
  Dst.M[2][2] = 1.0;
  memset(&pviewProj, 0, sizeof(pviewProj));
  pviewProj.M[0][0] = 1.0;
  pviewProj.M[1][1] = 1.0;
  pviewProj.M[2][2] = 1.0;
  pviewProj.M[3][3] = 1.0;
  Scaleform::Render::TreeCacheNode::CalcViewMatrix(pSourceNode, &Dst, &pviewProj);
  v6 = Scaleform::Render::TreeCacheNode::calcMaskBounds(pSourceNode, &maskBounds, &boundAreaMatrix, &Dst, &pviewProj);
  if ( this->StartEntry.Key.pImpl->Type != SortKey_MaskStart )
  {
    Scaleform::Render::BundleEntry::ClearBundle(&this->StartEntry);
    v7 = SortKeyMaskInterfaces[0];
    *(Scaleform::Render::SortKeyInterface **)&maskBounds.x1 = SortKeyMaskInterfaces[0];
    v3 = 1;
    *(_QWORD *)&maskBounds.x2 = 0i64;
    SortKeyMaskInterfaces[0]->vfptr->AddRef(SortKeyMaskInterfaces[0], 0i64);
    v7->vfptr->AddRef(v7, 0i64);
    this->StartEntry.Key.pImpl->vfptr->Release(this->StartEntry.Key.pImpl, this->StartEntry.Key.Data);
    this->StartEntry.Key.pImpl = v7;
    this->StartEntry.Key.Data = 0i64;
    v7->vfptr->Release(v7, 0i64);
  }
  this->MES = v6;
  Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(&this->BoundsMatrix, &boundAreaMatrix);
  return v3;
}

// File Line: 234
// RVA: 0x95DFC0
void __fastcall Scaleform::Render::MaskEffect::ChainNext(
        Scaleform::Render::MaskEffect *this,
        Scaleform::Render::BundleEntryRange *chain,
        Scaleform::Render::BundleEntryRange *maskChain)
{
  Scaleform::Render::BundleEntry *pFirst; // rax
  Scaleform::Render::BundleEntry *p_StartEntry; // r9
  Scaleform::Render::BundleEntry *p_EndEntry; // rcx
  Scaleform::Render::BundleEntry *v8; // rax
  unsigned int v9; // edx

  if ( this->MES && maskChain && (maskChain->Length & 0x7FFFFFFF) != 0 )
  {
    pFirst = maskChain->pFirst;
    p_StartEntry = &this->StartEntry;
    this->StartEntry.pChain = 0i64;
    this->StartEntry.ChainHeight = 0;
    this->StartEntry.pNextPattern = pFirst;
    p_EndEntry = &this->EndEntry;
    maskChain->pLast->pNextPattern = p_EndEntry;
    v8 = chain->pFirst;
    this->EndEntry.pChain = 0i64;
    this->EndEntry.ChainHeight = 0;
    p_EndEntry->pNextPattern = v8;
    chain->pLast->pNextPattern = &this->PopEntry;
    this->PopEntry.pChain = 0i64;
    this->PopEntry.ChainHeight = 0;
    v9 = (chain->Length & 0x7FFFFFFF) + (maskChain->Length & 0x7FFFFFFF) + 3;
    this->Length = v9;
    chain->pFirst = p_StartEntry;
    chain->pLast = &this->PopEntry;
    chain->Length = v9;
  }
  else
  {
    this->StartEntry.pNextPattern = 0i64;
    this->EndEntry.pNextPattern = chain->pFirst;
    this->PopEntry.pNextPattern = chain->pLast;
    this->Length = chain->Length & 0x7FFFFFFF;
  }
}

// File Line: 267
// RVA: 0x98ADF0
void __fastcall Scaleform::Render::MaskEffect::GetRange(
        Scaleform::Render::MaskEffect *this,
        Scaleform::Render::BundleEntryRange *result)
{
  Scaleform::Render::BundleEntry *p_StartEntry; // rcx
  unsigned int Length; // r8d
  Scaleform::Render::BundleEntry *pNextPattern; // rcx
  unsigned int v7; // edx

  p_StartEntry = &this->StartEntry;
  if ( p_StartEntry->pNextPattern )
  {
    Length = this->Length;
    result->pFirst = p_StartEntry;
    result->Length = Length;
    result->pLast = &this->PopEntry;
  }
  else
  {
    pNextPattern = this->PopEntry.pNextPattern;
    v7 = this->Length;
    result->pFirst = this->EndEntry.pNextPattern;
    result->pLast = pNextPattern;
    result->Length = v7;
  }
}

// File Line: 276
// RVA: 0x928730
Scaleform::Render::CacheEffect *__fastcall Scaleform::Render::MaskEffect::Create(
        Scaleform::Render::TreeCacheNode *node,
        Scaleform::Render::State *__formal,
        Scaleform::Render::CacheEffect *next)
{
  Scaleform::Render::MaskEffectState v5; // esi
  Scaleform::Render::MaskEffect *v6; // rax
  __int64 v7; // rax
  __int64 v8; // rdi
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // rbx
  __int64 DataPageOffset; // rcx
  Scaleform::Render::MatrixPoolImpl::HMatrix result; // [rsp+30h] [rbp-79h] BYREF
  Scaleform::Render::Rect<float> maskBounds; // [rsp+40h] [rbp-69h] BYREF
  Scaleform::Render::Matrix2x4<float> boundAreaMatrix; // [rsp+50h] [rbp-59h] BYREF
  Scaleform::Render::Matrix3x4<float> Dst; // [rsp+70h] [rbp-39h] BYREF
  __int64 v17; // [rsp+A0h] [rbp-9h]
  Scaleform::Render::Matrix4x4<float> pviewProj; // [rsp+B0h] [rbp+7h] BYREF
  int v19; // [rsp+128h] [rbp+7Fh] BYREF

  v17 = -2i64;
  maskBounds = 0i64;
  *(_OWORD *)&boundAreaMatrix.M[0][0] = _xmm;
  *(__m128 *)&boundAreaMatrix.M[1][0] = _xmm;
  memset(&Dst, 0, sizeof(Dst));
  Dst.M[0][0] = 1.0;
  Dst.M[1][1] = 1.0;
  Dst.M[2][2] = 1.0;
  memset(&pviewProj, 0, sizeof(pviewProj));
  pviewProj.M[0][0] = 1.0;
  pviewProj.M[1][1] = 1.0;
  pviewProj.M[2][2] = 1.0;
  pviewProj.M[3][3] = 1.0;
  Scaleform::Render::TreeCacheNode::CalcViewMatrix(node, &Dst, &pviewProj);
  v5 = Scaleform::Render::TreeCacheNode::calcMaskBounds(node, &maskBounds, &boundAreaMatrix, &Dst, &pviewProj);
  Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(&node->pRenderer2D->MPool, &result, &boundAreaMatrix, 0);
  v19 = 71;
  v6 = (Scaleform::Render::MaskEffect *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                          Scaleform::Memory::pGlobalHeap,
                                          node,
                                          232i64,
                                          &v19);
  *(_QWORD *)&maskBounds.x1 = v6;
  if ( v6 )
  {
    Scaleform::Render::MaskEffect::MaskEffect(v6, node, v5, &result, next);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  if ( result.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
  {
    pHeader = result.pHandle->pHeader;
    if ( result.pHandle->pHeader->RefCount-- == 1 )
    {
      DataPageOffset = pHeader->DataPageOffset;
      *(_WORD *)((char *)&pHeader[1].RefCount + DataPageOffset + 2) += 16 * (unsigned __int8)pHeader->UnitSize;
      (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&pHeader[1].pHandle + DataPageOffset))[5].pHeader += (unsigned __int8)pHeader->UnitSize;
      Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(pHeader->pHandle);
      pHeader->pHandle = 0i64;
    }
  }
  return (Scaleform::Render::CacheEffect *)v8;
}

// File Line: 300
// RVA: 0x938F20
void __fastcall Scaleform::Render::BlendModeEffect::BlendModeEffect(
        Scaleform::Render::BlendModeEffect *this,
        Scaleform::Render::TreeCacheNode *node,
        Scaleform::Render::MatrixPoolImpl::HMatrix *m,
        Scaleform::Render::BlendState *state,
        Scaleform::Render::CacheEffect *next)
{
  unsigned int DataValue; // eax
  int v10; // ecx
  void *pData_low; // rsi
  Scaleform::Render::SKI_BlendMode *v12; // rdi
  void *v13; // rdx
  Scaleform::Render::SortKeyInterfaceVtbl *vfptr; // rax
  unsigned int v15; // eax
  int v16; // ecx
  bool v17; // cl
  void *v18; // rdi
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // rax

  this->vfptr = (Scaleform::Render::CacheEffectVtbl *)&Scaleform::Render::CacheEffect::`vftable;
  this->pNext = next;
  this->Length = 0;
  this->vfptr = (Scaleform::Render::CacheEffectVtbl *)&Scaleform::Render::BlendModeEffect::`vftable;
  DataValue = state->DataValue;
  v10 = 24804;
  if ( DataValue <= 0xE && _bittest(&v10, DataValue) )
  {
    pData_low = (void *)SLODWORD(state->pData);
    v12 = &Scaleform::Render::SKI_BlendMode::StartCacheable_Instance;
    v13 = pData_low;
    vfptr = Scaleform::Render::SKI_BlendMode::StartCacheable_Instance.vfptr;
  }
  else
  {
    pData_low = (void *)SLODWORD(state->pData);
    v12 = &Scaleform::Render::SKI_BlendMode::Start_Instance;
    v13 = pData_low;
    vfptr = Scaleform::Render::SKI_BlendMode::Start_Instance.vfptr;
  }
  vfptr->AddRef(v12, v13);
  this->StartEntry.pNextPattern = 0i64;
  this->StartEntry.pChain = 0i64;
  *(_DWORD *)&this->StartEntry.ChainHeight = 0;
  this->StartEntry.Key.pImpl = v12;
  this->StartEntry.Key.Data = pData_low;
  v12->vfptr->AddRef(v12, pData_low);
  this->StartEntry.pBundle.pObject = 0i64;
  this->StartEntry.pSourceNode = node;
  this->StartEntry.Removed = 0;
  v12->vfptr->Release(v12, pData_low);
  v15 = state->DataValue;
  v17 = 0;
  if ( v15 <= 0xE )
  {
    v16 = 24804;
    if ( _bittest(&v16, v15) )
      v17 = 1;
  }
  v18 = (void *)(v17 + 20);
  Scaleform::Render::SKI_BlendMode::End_Instance.vfptr->AddRef(&Scaleform::Render::SKI_BlendMode::End_Instance, v18);
  this->EndEntry.pNextPattern = 0i64;
  this->EndEntry.pChain = 0i64;
  *(_DWORD *)&this->EndEntry.ChainHeight = 0;
  this->EndEntry.Key.pImpl = &Scaleform::Render::SKI_BlendMode::End_Instance;
  this->EndEntry.Key.Data = v18;
  Scaleform::Render::SKI_BlendMode::End_Instance.vfptr->AddRef(&Scaleform::Render::SKI_BlendMode::End_Instance, v18);
  this->EndEntry.pBundle.pObject = 0i64;
  this->EndEntry.pSourceNode = node;
  this->EndEntry.Removed = 0;
  Scaleform::Render::SKI_BlendMode::End_Instance.vfptr->Release(&Scaleform::Render::SKI_BlendMode::End_Instance, v18);
  pHandle = m->pHandle;
  this->BoundsMatrix = (Scaleform::Render::MatrixPoolImpl::HMatrix)m->pHandle;
  if ( pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    ++pHandle->pHeader->RefCount;
}

// File Line: 318
// RVA: 0x9BBD90
char __fastcall Scaleform::Render::BlendModeEffect::Update(
        Scaleform::Render::BlendModeEffect *this,
        Scaleform::Render::State *stateArg)
{
  unsigned int DataValue; // eax
  int v5; // edi
  bool v6; // bp
  void *pData_low; // rax
  void *v8; // rdi
  Scaleform::Render::SKI_BlendMode *v9; // rbx
  void *v10; // rdx
  Scaleform::Render::SortKeyInterfaceVtbl *vfptr; // rax
  void *v12; // rbx

  DataValue = stateArg->DataValue;
  v5 = 24804;
  v6 = DataValue <= 0xE && _bittest(&v5, DataValue);
  Scaleform::Render::BundleEntry::ClearBundle(&this->StartEntry);
  Scaleform::Render::BundleEntry::ClearBundle(&this->EndEntry);
  pData_low = (void *)SLODWORD(stateArg->pData);
  if ( (unsigned int)pData_low <= 0xE && _bittest(&v5, (unsigned int)pData_low) )
  {
    v8 = (void *)SLODWORD(stateArg->pData);
    v9 = &Scaleform::Render::SKI_BlendMode::StartCacheable_Instance;
    v10 = pData_low;
    vfptr = Scaleform::Render::SKI_BlendMode::StartCacheable_Instance.vfptr;
  }
  else
  {
    v8 = (void *)SLODWORD(stateArg->pData);
    v9 = &Scaleform::Render::SKI_BlendMode::Start_Instance;
    v10 = pData_low;
    vfptr = Scaleform::Render::SKI_BlendMode::Start_Instance.vfptr;
  }
  vfptr->AddRef(v9, v10);
  v9->vfptr->AddRef(v9, v8);
  this->StartEntry.Key.pImpl->vfptr->Release(this->StartEntry.Key.pImpl, this->StartEntry.Key.Data);
  this->StartEntry.Key.pImpl = v9;
  this->StartEntry.Key.Data = v8;
  v9->vfptr->Release(v9, v8);
  v12 = (void *)(v6 + 20);
  Scaleform::Render::SKI_BlendMode::End_Instance.vfptr->AddRef(&Scaleform::Render::SKI_BlendMode::End_Instance, v12);
  Scaleform::Render::SKI_BlendMode::End_Instance.vfptr->AddRef(&Scaleform::Render::SKI_BlendMode::End_Instance, v12);
  this->EndEntry.Key.pImpl->vfptr->Release(this->EndEntry.Key.pImpl, this->EndEntry.Key.Data);
  this->EndEntry.Key.pImpl = &Scaleform::Render::SKI_BlendMode::End_Instance;
  this->EndEntry.Key.Data = v12;
  Scaleform::Render::SKI_BlendMode::End_Instance.vfptr->Release(&Scaleform::Render::SKI_BlendMode::End_Instance, v12);
  return 1;
}

// File Line: 337
// RVA: 0x95E090
void __fastcall Scaleform::Render::UserDataEffect::ChainNext(
        Scaleform::Render::ViewMatrix3DEffect *this,
        Scaleform::Render::BundleEntryRange *chain,
        Scaleform::Render::BundleEntryRange *__formal)
{
  unsigned int v3; // eax

  this->StartEntry.pNextPattern = chain->pFirst;
  this->StartEntry.pChain = 0i64;
  this->StartEntry.ChainHeight = 0;
  chain->pLast->pNextPattern = &this->EndEntry;
  this->EndEntry.pChain = 0i64;
  this->EndEntry.ChainHeight = 0;
  v3 = (chain->Length & 0x7FFFFFFF) + 2;
  this->Length = v3;
  chain->pFirst = &this->StartEntry;
  chain->pLast = &this->EndEntry;
  chain->Length = v3;
}

// File Line: 342
// RVA: 0x98AD90
void __fastcall Scaleform::Render::BlendModeEffect::GetRange(
        Scaleform::Render::ViewMatrix3DEffect *this,
        Scaleform::Render::BundleEntryRange *result)
{
  unsigned int Length; // r8d

  Length = this->Length;
  result->pFirst = &this->StartEntry;
  result->Length = Length;
  result->pLast = &this->EndEntry;
}

// File Line: 347
// RVA: 0x9288C0
Scaleform::Render::CacheEffect *__fastcall Scaleform::Render::BlendModeEffect::Create(
        Scaleform::Render::TreeCacheNode *node,
        Scaleform::Render::BlendState *stateArg,
        Scaleform::Render::CacheEffect *next)
{
  Scaleform::Render::BlendModeEffect *v6; // rax
  __int64 v7; // rax
  __int64 v8; // rdi
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // rbx
  __int64 DataPageOffset; // rcx
  Scaleform::Render::MatrixPoolImpl::HMatrix result; // [rsp+30h] [rbp-79h] BYREF
  Scaleform::Render::Rect<float> returnBounds; // [rsp+40h] [rbp-69h] BYREF
  Scaleform::Render::Matrix2x4<float> areaMatrix; // [rsp+50h] [rbp-59h] BYREF
  Scaleform::Render::Matrix3x4<float> Dst; // [rsp+70h] [rbp-39h] BYREF
  __int64 v17; // [rsp+A0h] [rbp-9h]
  Scaleform::Render::Matrix4x4<float> pviewProj; // [rsp+B0h] [rbp+7h] BYREF
  int v19; // [rsp+128h] [rbp+7Fh] BYREF

  v17 = -2i64;
  memset(&Dst, 0, sizeof(Dst));
  Dst.M[0][0] = 1.0;
  Dst.M[1][1] = 1.0;
  Dst.M[2][2] = 1.0;
  memset(&pviewProj, 0, sizeof(pviewProj));
  pviewProj.M[0][0] = 1.0;
  pviewProj.M[1][1] = 1.0;
  pviewProj.M[2][2] = 1.0;
  pviewProj.M[3][3] = 1.0;
  *(_OWORD *)&areaMatrix.M[0][0] = _xmm;
  *(__m128 *)&areaMatrix.M[1][0] = _xmm;
  returnBounds = 0i64;
  Scaleform::Render::TreeCacheNode::CalcViewMatrix(node, &Dst, &pviewProj);
  if ( Scaleform::Render::TreeCacheNode::calcCacheableBounds(node, &returnBounds, &areaMatrix, &Dst, &pviewProj, 0i64) == CacheableBoundResult_CompletelyClipped )
  {
    *(_OWORD *)&areaMatrix.M[0][0] = _xmm;
    *(__m128 *)&areaMatrix.M[1][0] = _xmm;
  }
  Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(&node->pRenderer2D->MPool, &result, &areaMatrix, 0);
  Scaleform::Render::MatrixPoolImpl::HMatrix::SetCxform(
    &result,
    (Scaleform::Render::Cxform *)((*(_QWORD *)(*(_QWORD *)(((unsigned __int64)node->pNode & 0xFFFFFFFFFFFFF000ui64)
                                                         + 0x28)
                                             + 8i64
                                             * (unsigned int)((int)(LODWORD(node->pNode)
                                                                  - ((__int64)node->pNode & 0xFFFFF000)
                                                                  - 56)
                                                            / 56)
                                             + 40) & 0xFFFFFFFFFFFFFFFEui64)
                                + 80));
  v19 = 71;
  v6 = (Scaleform::Render::BlendModeEffect *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                               Scaleform::Memory::pGlobalHeap,
                                               node,
                                               160i64,
                                               &v19);
  *(_QWORD *)&returnBounds.x1 = v6;
  if ( v6 )
  {
    Scaleform::Render::BlendModeEffect::BlendModeEffect(v6, node, &result, stateArg, next);
    v8 = v7;
  }
  else
  {
    v8 = 0i64;
  }
  if ( result.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
  {
    pHeader = result.pHandle->pHeader;
    if ( result.pHandle->pHeader->RefCount-- == 1 )
    {
      DataPageOffset = pHeader->DataPageOffset;
      *(_WORD *)((char *)&pHeader[1].RefCount + DataPageOffset + 2) += 16 * (unsigned __int8)pHeader->UnitSize;
      (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&pHeader[1].pHandle + DataPageOffset))[5].pHeader += (unsigned __int8)pHeader->UnitSize;
      Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(pHeader->pHandle);
      pHeader->pHandle = 0i64;
    }
  }
  return (Scaleform::Render::CacheEffect *)v8;
}

// File Line: 378
// RVA: 0x93BCD0
void __fastcall Scaleform::Render::FilterEffect::FilterEffect(
        Scaleform::Render::FilterEffect *this,
        Scaleform::Render::TreeCacheNode *node,
        Scaleform::Render::MatrixPoolImpl::HMatrix *m,
        Scaleform::Render::FilterState *state,
        Scaleform::Render::CacheEffect *next)
{
  unsigned int v9; // esi
  void *pData; // rdi
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // rax
  _QWORD *v12; // rax
  __int64 v13; // rbx
  int v14; // eax
  Scaleform::Render::Image *GradientImage; // rdi
  __int64 v16; // rcx
  Scaleform::Render::Matrix2x4<float> ma; // [rsp+40h] [rbp-48h] BYREF

  this->vfptr = (Scaleform::Render::CacheEffectVtbl *)&Scaleform::Render::CacheEffect::`vftable;
  this->pNext = next;
  v9 = 0;
  this->Length = 0;
  this->vfptr = (Scaleform::Render::CacheEffectVtbl *)&Scaleform::Render::FilterEffect::`vftable;
  this->Contributing = 1;
  pData = state->pData;
  Scaleform::Render::SKI_Filter::Start_Instance.vfptr->AddRef(&Scaleform::Render::SKI_Filter::Start_Instance, pData);
  this->StartEntry.pNextPattern = 0i64;
  this->StartEntry.pChain = 0i64;
  *(_DWORD *)&this->StartEntry.ChainHeight = 0;
  this->StartEntry.Key.pImpl = &Scaleform::Render::SKI_Filter::Start_Instance;
  this->StartEntry.Key.Data = pData;
  Scaleform::Render::SKI_Filter::Start_Instance.vfptr->AddRef(&Scaleform::Render::SKI_Filter::Start_Instance, pData);
  this->StartEntry.pBundle.pObject = 0i64;
  this->StartEntry.pSourceNode = node;
  this->StartEntry.Removed = 0;
  Scaleform::Render::SKI_Filter::Start_Instance.vfptr->Release(&Scaleform::Render::SKI_Filter::Start_Instance, pData);
  *(_QWORD *)&ma.M[0][0] = &Scaleform::Render::SKI_Filter::End_Instance;
  *(_QWORD *)&ma.M[0][2] = 0i64;
  Scaleform::Render::SKI_Filter::End_Instance.vfptr->AddRef(&Scaleform::Render::SKI_Filter::End_Instance, 0i64);
  this->EndEntry.pNextPattern = 0i64;
  this->EndEntry.pChain = 0i64;
  *(_DWORD *)&this->EndEntry.ChainHeight = 0;
  this->EndEntry.Key.pImpl = &Scaleform::Render::SKI_Filter::End_Instance;
  this->EndEntry.Key.Data = 0i64;
  Scaleform::Render::SKI_Filter::End_Instance.vfptr->AddRef(&Scaleform::Render::SKI_Filter::End_Instance, 0i64);
  this->EndEntry.pBundle.pObject = 0i64;
  this->EndEntry.pSourceNode = node;
  this->EndEntry.Removed = 0;
  Scaleform::Render::SKI_Filter::End_Instance.vfptr->Release(&Scaleform::Render::SKI_Filter::End_Instance, 0i64);
  pHandle = m->pHandle;
  this->BoundsMatrix = (Scaleform::Render::MatrixPoolImpl::HMatrix)m->pHandle;
  if ( pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
    ++pHandle->pHeader->RefCount;
  memset(&ma, 0, sizeof(ma));
  Scaleform::Render::MatrixPoolImpl::HMatrix::SetTextureMatrix(&this->BoundsMatrix, &ma, 1u);
  Scaleform::Render::MatrixPoolImpl::HMatrix::SetUserData(
    &this->BoundsMatrix,
    &m->pHandle->pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[m->pHandle->pHeader->Format & 0xF].Offsets[4]
                       + 1],
    0x20ui64);
  v12 = state->pData;
  if ( *((_DWORD *)v12 + 6) )
  {
    do
    {
      v13 = *(_QWORD *)(v12[2] + 8i64 * v9);
      v14 = *(_DWORD *)(v13 + 16);
      if ( v14 == 5 || v14 == 4 )
      {
        GradientImage = Scaleform::Render::PrimitiveFillManager::createGradientImage(
                          &node->pRenderer2D->FillManager,
                          *(Scaleform::Render::GradientData **)(v13 + 64),
                          0.0);
        v16 = *(_QWORD *)(v13 + 80);
        if ( v16 )
          (*(void (__fastcall **)(__int64))(*(_QWORD *)v16 + 16i64))(v16);
        *(_QWORD *)(v13 + 80) = GradientImage;
      }
      ++v9;
      v12 = state->pData;
    }
    while ( v9 < *((_DWORD *)v12 + 6) );
  }
}

// File Line: 400
// RVA: 0x9BEC00
bool __fastcall Scaleform::Render::FilterEffect::UpdateMatrix(
        Scaleform::Render::FilterEffect *this,
        Scaleform::Render::Matrix2x4<float> *boundsMatrix,
        Scaleform::Render::Matrix2x4<float> *newNodeMatrix,
        bool forceUncache)
{
  Scaleform::Render::MatrixPoolImpl::HMatrix *p_BoundsMatrix; // r12
  char CanCacheAcrossTransform; // r13
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // rax
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // rbx
  char Format; // dl
  Scaleform::Render::Matrix2x4<float> *v11; // rsi
  float v12; // xmm1_4
  float v13; // xmm2_4
  float v14; // xmm2_4
  bool v15; // r13
  float v16; // xmm3_4
  __m128 v17; // xmm4
  float v18; // xmm7_4
  __m128 v19; // xmm1
  __m128 v20; // xmm8
  float v21; // xmm5_4
  __m128 v22; // xmm1
  float v23; // xmm2_4
  __m128 v24; // xmm1
  __m128 v25; // xmm0
  float v26; // xmm5_4
  float v27; // xmm1_4
  bool v28; // si
  float v29; // xmm9_4
  float v30; // xmm0_4
  char v31; // al
  float v32; // xmm1_4
  int v33; // eax
  __int64 v34; // rcx
  float v35; // xmm2_4
  float v36; // xmm2_4
  char v37; // al
  float v38; // xmm7_4
  char v39; // r13
  __m128 v40; // xmm1
  __m128 v41; // xmm8
  float v42; // xmm5_4
  __m128 v43; // xmm1
  float v44; // xmm2_4
  __m128 v45; // xmm1
  __m128 v46; // xmm0
  float v47; // xmm5_4
  float v48; // xmm1_4
  char v49; // al
  char v50; // si
  float v51; // xmm9_4
  float v52; // xmm0_4
  char v53; // al
  Scaleform::Render::MatrixPoolImpl::DataHeader *v54; // rdx
  char v55; // r8
  __int64 v56; // rcx
  unsigned int v57; // xmm1_4
  unsigned int v58; // xmm0_4
  Scaleform::Render::Matrix2x4<float> *v59; // rax
  float v60; // xmm6_4
  float v61; // xmm5_4
  float v62; // xmm4_4
  float v63; // xmm3_4
  float v64; // xmm2_4
  float v65; // xmm1_4
  float v66; // xmm0_4
  Scaleform::Render::Matrix2x4<float> *v67; // rdx
  __m128 si128; // xmm7
  __m128 v69; // xmm8
  __m128 v70; // xmm5
  __m128 v71; // xmm6
  __m128 v72; // xmm0
  __m128 v74; // [rsp+20h] [rbp-79h] BYREF
  __m128 v75; // [rsp+30h] [rbp-69h]
  Scaleform::Render::Matrix2x4<float> v76; // [rsp+40h] [rbp-59h] BYREF
  Scaleform::Render::Matrix2x4<float> Buf2; // [rsp+60h] [rbp-39h] BYREF
  bool v79; // [rsp+118h] [rbp+7Fh]

  p_BoundsMatrix = &this->BoundsMatrix;
  CanCacheAcrossTransform = 0;
  pHandle = this->BoundsMatrix.pHandle;
  pHeader = pHandle->pHeader;
  Format = pHandle->pHeader->Format;
  if ( (Format & 4) != 0 )
    v11 = (Scaleform::Render::Matrix2x4<float> *)&pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[pHeader->Format & 0xF].Offsets[2]
                                                        + 1];
  else
    v11 = &Scaleform::Render::Matrix2x4<float>::Identity;
  memset(&Buf2, 0, sizeof(Buf2));
  if ( forceUncache || (Format & 4) == 0 || !memcmp(v11, &Buf2, 0x20ui64) )
    goto LABEL_43;
  v12 = newNodeMatrix->M[0][3];
  v13 = v11->M[0][3];
  v15 = 1;
  if ( (float)(v12 + 0.000099999997) >= v13 && (float)(v12 - 0.000099999997) <= v13 )
  {
    v14 = v11->M[1][3];
    if ( (float)(newNodeMatrix->M[1][3] + 0.000099999997) >= v14
      && (float)(newNodeMatrix->M[1][3] - 0.000099999997) <= v14 )
    {
      v15 = 0;
    }
  }
  v16 = v11->M[1][0];
  v17 = (__m128)LODWORD(v11->M[0][0]);
  v18 = newNodeMatrix->M[1][0];
  v19 = v17;
  v20 = (__m128)LODWORD(newNodeMatrix->M[0][0]);
  v19.m128_f32[0] = (float)(v17.m128_f32[0] * v17.m128_f32[0]) + (float)(v16 * v16);
  v21 = _mm_sqrt_ps(v19).m128_f32[0];
  v22 = v20;
  v22.m128_f32[0] = (float)(v20.m128_f32[0] * v20.m128_f32[0]) + (float)(v18 * v18);
  v23 = _mm_sqrt_ps(v22).m128_f32[0];
  v28 = 1;
  if ( (float)(v23 + 0.000099999997) >= v21 && (float)(v23 - 0.000099999997) <= v21 )
  {
    v24 = (__m128)LODWORD(v11->M[0][1]);
    v24.m128_f32[0] = (float)(v24.m128_f32[0] * v24.m128_f32[0]) + (float)(v11->M[1][1] * v11->M[1][1]);
    v25 = (__m128)LODWORD(newNodeMatrix->M[0][1]);
    v26 = _mm_sqrt_ps(v24).m128_f32[0];
    v25.m128_f32[0] = (float)(v25.m128_f32[0] * v25.m128_f32[0])
                    + (float)(newNodeMatrix->M[1][1] * newNodeMatrix->M[1][1]);
    v27 = _mm_sqrt_ps(v25).m128_f32[0];
    if ( (float)(v27 + 0.000099999997) >= v26 && (float)(v27 - 0.000099999997) <= v26 )
      v28 = 0;
  }
  v29 = atan2f(v16, v17.m128_f32[0]);
  v30 = atan2f(v18, v20.m128_f32[0]);
  if ( (float)(v30 + 0.000099999997) < v29 || (v31 = 1, (float)(v30 - 0.000099999997) > v29) )
    v31 = 0;
  v32 = boundsMatrix->M[0][3];
  v79 = v31 == 0;
  v33 = (unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[pHeader->Format & 0xF].Offsets[4];
  v34 = v33 * 16;
  v35 = *(float *)&pHeader[v33 + 1].DataPageOffset;
  if ( (float)(v32 + 0.000099999997) < v35
    || (float)(v32 - 0.000099999997) > v35
    || (v36 = *(float *)&pHeader[v33 + 2].DataPageOffset, (float)(boundsMatrix->M[1][3] + 0.000099999997) < v36)
    || (v37 = 0, (float)(boundsMatrix->M[1][3] - 0.000099999997) > v36) )
  {
    v37 = 1;
  }
  v38 = boundsMatrix->M[1][0];
  v39 = v37 | v15;
  v40 = (__m128)*(unsigned int *)((char *)&pHeader[1].pHandle + v34);
  v41 = (__m128)LODWORD(boundsMatrix->M[0][0]);
  v40.m128_f32[0] = (float)(v40.m128_f32[0] * v40.m128_f32[0])
                  + (float)(*(float *)((char *)&pHeader[2].pHandle + v34) * *(float *)((char *)&pHeader[2].pHandle + v34));
  v42 = _mm_sqrt_ps(v40).m128_f32[0];
  v43 = v41;
  v43.m128_f32[0] = (float)(v41.m128_f32[0] * v41.m128_f32[0]) + (float)(v38 * v38);
  v44 = _mm_sqrt_ps(v43).m128_f32[0];
  if ( (float)(v44 + 0.000099999997) < v42
    || (float)(v44 - 0.000099999997) > v42
    || (v45 = (__m128)*(unsigned int *)((char *)&pHeader[1].pHandle + v34 + 4),
        v45.m128_f32[0] = (float)(v45.m128_f32[0] * v45.m128_f32[0])
                        + (float)(*(float *)((char *)&pHeader[2].pHandle + v34 + 4)
                                * *(float *)((char *)&pHeader[2].pHandle + v34 + 4)),
        v46 = (__m128)LODWORD(boundsMatrix->M[0][1]),
        v47 = _mm_sqrt_ps(v45).m128_f32[0],
        v46.m128_f32[0] = (float)(v46.m128_f32[0] * v46.m128_f32[0])
                        + (float)(boundsMatrix->M[1][1] * boundsMatrix->M[1][1]),
        v48 = _mm_sqrt_ps(v46).m128_f32[0],
        (float)(v48 + 0.000099999997) < v47)
    || (v49 = 0, (float)(v48 - 0.000099999997) > v47) )
  {
    v49 = 1;
  }
  v50 = v49 | v28;
  v51 = atan2f(*(float *)((char *)&pHeader[2].pHandle + v34), *(float *)((char *)&pHeader[1].pHandle + v34));
  v52 = atan2f(v38, v41.m128_f32[0]);
  if ( (float)(v52 + 0.000099999997) < v51 || (v53 = 1, (float)(v52 - 0.000099999997) > v51) )
    v53 = 0;
  CanCacheAcrossTransform = Scaleform::Render::FilterSet::CanCacheAcrossTransform(
                              (Scaleform::Render::FilterSet *)this->StartEntry.Key.Data,
                              v39,
                              v79 || v53 == 0,
                              v50);
  if ( !CanCacheAcrossTransform )
  {
LABEL_43:
    Scaleform::Render::MatrixPoolImpl::HMatrix::SetTextureMatrix(p_BoundsMatrix, newNodeMatrix, 1u);
    Scaleform::Render::MatrixPoolImpl::HMatrix::SetUserData(p_BoundsMatrix, boundsMatrix, 0x20ui64);
    v67 = boundsMatrix;
  }
  else
  {
    v54 = p_BoundsMatrix->pHandle->pHeader;
    v55 = v54->Format;
    if ( (v55 & 8) != 0 )
      v56 = (__int64)&v54[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v54->Format & 0xF].Offsets[3]
                        + 1];
    else
      v56 = 0i64;
    v57 = *(_DWORD *)(v56 + 4);
    v74.m128_i32[0] = *(_DWORD *)v56;
    *(unsigned __int64 *)((char *)v74.m128_u64 + 4) = __PAIR64__(*(_DWORD *)(v56 + 8), v57);
    v58 = *(_DWORD *)(v56 + 16);
    v74.m128_i32[3] = *(_DWORD *)(v56 + 12);
    v75.m128_u64[0] = __PAIR64__(*(_DWORD *)(v56 + 20), v58);
    v75.m128_u64[1] = *(_QWORD *)(v56 + 24);
    if ( (v55 & 4) != 0 )
      v59 = (Scaleform::Render::Matrix2x4<float> *)&v54[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[v54->Format & 0xF].Offsets[2]
                                                      + 1];
    else
      v59 = &Scaleform::Render::Matrix2x4<float>::Identity;
    v60 = v59->M[0][1];
    v61 = v59->M[0][2];
    v62 = v59->M[0][3];
    v63 = v59->M[1][0];
    v64 = v59->M[1][1];
    v65 = v59->M[1][2];
    v66 = v59->M[1][3];
    v76.M[0][0] = v59->M[0][0];
    *(_QWORD *)&v76.M[0][1] = __PAIR64__(LODWORD(v61), LODWORD(v60));
    v76.M[0][3] = v62;
    *(_QWORD *)&v76.M[1][0] = __PAIR64__(LODWORD(v64), LODWORD(v63));
    *(_QWORD *)&v76.M[1][2] = __PAIR64__(LODWORD(v66), LODWORD(v65));
    *(_QWORD *)&Buf2.M[0][0] = __PAIR64__(LODWORD(v60), LODWORD(v76.M[0][0]));
    *(_QWORD *)&Buf2.M[0][2] = __PAIR64__(LODWORD(v62), LODWORD(v61));
    *(_QWORD *)&Buf2.M[1][0] = __PAIR64__(LODWORD(v64), LODWORD(v63));
    *(_QWORD *)&Buf2.M[1][2] = __PAIR64__(LODWORD(v66), LODWORD(v65));
    Scaleform::Render::Matrix2x4<float>::SetInverse(&v76, &Buf2);
    v67 = (Scaleform::Render::Matrix2x4<float> *)&v74;
    si128 = (__m128)_mm_load_si128((const __m128i *)&`Scaleform::SIMD::SSE::InstructionSet::Constant<0,0,0,4294967295>::`2::v);
    v69 = (__m128)_mm_load_si128((const __m128i *)&`Scaleform::SIMD::SSE::InstructionSet::Constant<4294967295,4294967295,0,4294967295>::`2::v);
    v70 = _mm_and_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps(*(__m128 *)&newNodeMatrix->M[0][0], *(__m128 *)&newNodeMatrix->M[0][0], 85),
                  *(__m128 *)&v76.M[1][0]),
                _mm_mul_ps(
                  _mm_shuffle_ps(*(__m128 *)&newNodeMatrix->M[0][0], *(__m128 *)&newNodeMatrix->M[0][0], 0),
                  *(__m128 *)&v76.M[0][0])),
              _mm_and_ps(*(__m128 *)&newNodeMatrix->M[0][0], si128)),
            v69);
    v71 = _mm_and_ps(
            _mm_add_ps(
              _mm_add_ps(
                _mm_mul_ps(
                  _mm_shuffle_ps(*(__m128 *)&newNodeMatrix->M[1][0], *(__m128 *)&newNodeMatrix->M[1][0], 85),
                  *(__m128 *)&v76.M[1][0]),
                _mm_mul_ps(
                  _mm_shuffle_ps(*(__m128 *)&newNodeMatrix->M[1][0], *(__m128 *)&newNodeMatrix->M[1][0], 0),
                  *(__m128 *)&v76.M[0][0])),
              _mm_and_ps(*(__m128 *)&newNodeMatrix->M[1][0], si128)),
            v69);
    v72 = _mm_mul_ps(_mm_shuffle_ps(v71, v71, 0), v74);
    v74 = _mm_and_ps(
            _mm_add_ps(
              _mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v70, v70, 85), v75), _mm_mul_ps(_mm_shuffle_ps(v70, v70, 0), v74)),
              _mm_and_ps(v70, si128)),
            v69);
    v75 = _mm_and_ps(
            _mm_add_ps(_mm_add_ps(_mm_mul_ps(_mm_shuffle_ps(v71, v71, 85), v75), v72), _mm_and_ps(v71, si128)),
            v69);
  }
  Scaleform::Render::MatrixPoolImpl::HMatrix::SetMatrix2D(p_BoundsMatrix, v67);
  Scaleform::Render::MatrixPoolImpl::HMatrix::SetTextureMatrix(p_BoundsMatrix, boundsMatrix, 0);
  return CanCacheAcrossTransform == 0;
}

// File Line: 471
// RVA: 0x9BBEE0
char __fastcall Scaleform::Render::FilterEffect::Update(
        Scaleform::Render::FilterEffect *this,
        Scaleform::Render::State *stateArg)
{
  void *pData; // [rsp+30h] [rbp-28h]

  Scaleform::Render::BundleEntry::ClearBundle(&this->StartEntry);
  Scaleform::Render::BundleEntry::ClearBundle(&this->EndEntry);
  pData = stateArg->pData;
  Scaleform::Render::SKI_Filter::Start_Instance.vfptr->AddRef(&Scaleform::Render::SKI_Filter::Start_Instance, pData);
  Scaleform::Render::SKI_Filter::Start_Instance.vfptr->AddRef(&Scaleform::Render::SKI_Filter::Start_Instance, pData);
  this->StartEntry.Key.pImpl->vfptr->Release(this->StartEntry.Key.pImpl, this->StartEntry.Key.Data);
  this->StartEntry.Key.pImpl = &Scaleform::Render::SKI_Filter::Start_Instance;
  this->StartEntry.Key.Data = pData;
  Scaleform::Render::SKI_Filter::Start_Instance.vfptr->Release(&Scaleform::Render::SKI_Filter::Start_Instance, pData);
  Scaleform::Render::SKI_Filter::End_Instance.vfptr->AddRef(&Scaleform::Render::SKI_Filter::End_Instance, 0i64);
  Scaleform::Render::SKI_Filter::End_Instance.vfptr->AddRef(&Scaleform::Render::SKI_Filter::End_Instance, 0i64);
  this->EndEntry.Key.pImpl->vfptr->Release(this->EndEntry.Key.pImpl, this->EndEntry.Key.Data);
  this->EndEntry.Key.pImpl = &Scaleform::Render::SKI_Filter::End_Instance;
  this->EndEntry.Key.Data = 0i64;
  Scaleform::Render::SKI_Filter::End_Instance.vfptr->Release(&Scaleform::Render::SKI_Filter::End_Instance, 0i64);
  return 1;
}

// File Line: 486
// RVA: 0x95DF10
void __fastcall Scaleform::Render::FilterEffect::ChainNext(
        Scaleform::Render::FilterEffect *this,
        Scaleform::Render::BundleEntryRange *chain,
        Scaleform::Render::BundleEntryRange *__formal)
{
  Scaleform::Render::FilterSet *Data; // rcx
  bool v6; // zf
  bool v7; // al
  unsigned int v8; // eax

  Data = (Scaleform::Render::FilterSet *)this->StartEntry.Key.Data;
  if ( !Data || (v6 = !Scaleform::Render::FilterSet::IsContributing(Data), v7 = 1, v6) )
    v7 = 0;
  this->Contributing = v7;
  this->StartEntry.pNextPattern = chain->pFirst;
  if ( v7 )
  {
    this->StartEntry.pChain = 0i64;
    this->StartEntry.ChainHeight = 0;
    chain->pLast->pNextPattern = &this->EndEntry;
    this->EndEntry.pChain = 0i64;
    this->EndEntry.ChainHeight = 0;
    v8 = (chain->Length & 0x7FFFFFFF) + 2;
    this->Length = v8;
    chain->pFirst = &this->StartEntry;
    chain->pLast = &this->EndEntry;
    chain->Length = v8;
  }
  else
  {
    this->EndEntry.pNextPattern = chain->pLast;
    this->Length = chain->Length & 0x7FFFFFFF;
  }
}

// File Line: 506
// RVA: 0x98ADB0
void __fastcall Scaleform::Render::FilterEffect::GetRange(
        Scaleform::Render::FilterEffect *this,
        Scaleform::Render::BundleEntryRange *result)
{
  unsigned int Length; // r8d
  Scaleform::Render::BundleEntry *pNextPattern; // rcx
  unsigned int v6; // edx

  if ( this->Contributing )
  {
    Length = this->Length;
    result->pFirst = &this->StartEntry;
    result->Length = Length;
    result->pLast = &this->EndEntry;
  }
  else
  {
    pNextPattern = this->EndEntry.pNextPattern;
    v6 = this->Length;
    result->pFirst = this->StartEntry.pNextPattern;
    result->pLast = pNextPattern;
    result->Length = v6;
  }
}

// File Line: 514
// RVA: 0x928AC0
Scaleform::Render::CacheEffect *__fastcall Scaleform::Render::FilterEffect::Create(
        Scaleform::Render::TreeCacheNode *node,
        Scaleform::Render::FilterState *stateArg,
        Scaleform::Render::CacheEffect *next)
{
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // rax
  unsigned __int8 Format; // dl
  Scaleform::Render::FilterEffect *v8; // rax
  __int64 v9; // rax
  __int64 v10; // rdi
  Scaleform::Render::MatrixPoolImpl::DataHeader *pHeader; // rbx
  __int64 DataPageOffset; // rcx
  Scaleform::Render::MatrixPoolImpl::HMatrix result; // [rsp+30h] [rbp-D0h] BYREF
  Scaleform::Render::Cxform dest; // [rsp+40h] [rbp-C0h] BYREF
  Scaleform::Render::Matrix2x4<float> areaMatrix; // [rsp+60h] [rbp-A0h] BYREF
  Scaleform::Render::Rect<float> returnBounds; // [rsp+80h] [rbp-80h] BYREF
  Scaleform::Render::Matrix3x4<float> Dst; // [rsp+90h] [rbp-70h] BYREF
  __int64 v20; // [rsp+C0h] [rbp-40h]
  Scaleform::Render::Matrix4x4<float> pviewProj; // [rsp+D0h] [rbp-30h] BYREF
  int v22; // [rsp+148h] [rbp+48h] BYREF

  v20 = -2i64;
  returnBounds = 0i64;
  *(_OWORD *)&areaMatrix.M[0][0] = _xmm;
  *(__m128 *)&areaMatrix.M[1][0] = _xmm;
  *(_OWORD *)&dest.M[0][0] = *(_OWORD *)_xmm;
  *(_OWORD *)&dest.M[1][0] = 0i64;
  memset(&Dst, 0, sizeof(Dst));
  Dst.M[0][0] = 1.0;
  Dst.M[1][1] = 1.0;
  Dst.M[2][2] = 1.0;
  memset(&pviewProj, 0, sizeof(pviewProj));
  pviewProj.M[0][0] = 1.0;
  pviewProj.M[1][1] = 1.0;
  pviewProj.M[2][2] = 1.0;
  pviewProj.M[3][3] = 1.0;
  Scaleform::Render::TreeCacheNode::CalcViewMatrix(node, &Dst, &pviewProj);
  Scaleform::Render::TreeCacheNode::CalcCxform(node, &dest);
  if ( Scaleform::Render::TreeCacheNode::calcCacheableBounds(node, &returnBounds, &areaMatrix, &Dst, &pviewProj, 0i64) == CacheableBoundResult_CompletelyClipped )
  {
    *(_OWORD *)&areaMatrix.M[0][0] = _xmm;
    *(__m128 *)&areaMatrix.M[1][0] = _xmm;
  }
  Scaleform::Render::MatrixPoolImpl::MatrixPool::CreateMatrix(&node->pRenderer2D->MPool, &result, &areaMatrix, 0);
  pHandle = result.pHandle;
  Format = result.pHandle->pHeader->Format;
  if ( (Format & 1) == 0 )
  {
    if ( dest.M[0][0] == Scaleform::Render::Cxform::Identity.M[0][0]
      && dest.M[0][1] == Scaleform::Render::Cxform::Identity.M[0][1]
      && dest.M[0][2] == Scaleform::Render::Cxform::Identity.M[0][2]
      && dest.M[0][3] == Scaleform::Render::Cxform::Identity.M[0][3]
      && dest.M[1][0] == Scaleform::Render::Cxform::Identity.M[1][0]
      && dest.M[1][1] == Scaleform::Render::Cxform::Identity.M[1][1]
      && dest.M[1][2] == Scaleform::Render::Cxform::Identity.M[1][2]
      && dest.M[1][3] == Scaleform::Render::Cxform::Identity.M[1][3] )
    {
      goto LABEL_14;
    }
    Scaleform::Render::MatrixPoolImpl::MatrixPool::reallocMatrixData(
      *(Scaleform::Render::MatrixPoolImpl::MatrixPool **)(*(_QWORD *)(((unsigned __int64)result.pHandle & 0xFFFFFFFFFFFFF800ui64)
                                                                    + 0x20)
                                                        + 8i64),
      result.pHandle,
      Format | 1);
    pHandle = result.pHandle;
  }
  *(Scaleform::Render::Cxform *)&pHandle->pHeader[(unsigned __int8)Scaleform::Render::MatrixPoolImpl::HMatrixConstants::MatrixElementSizeTable[pHandle->pHeader->Format & 0xF].Offsets[0]
                                                + 1].pHandle = dest;
LABEL_14:
  v22 = 71;
  v8 = (Scaleform::Render::FilterEffect *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                            Scaleform::Memory::pGlobalHeap,
                                            node,
                                            168i64,
                                            &v22);
  *(_QWORD *)&returnBounds.x1 = v8;
  if ( v8 )
  {
    Scaleform::Render::FilterEffect::FilterEffect(v8, node, &result, stateArg, next);
    v10 = v9;
  }
  else
  {
    v10 = 0i64;
  }
  if ( result.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
  {
    pHeader = result.pHandle->pHeader;
    if ( result.pHandle->pHeader->RefCount-- == 1 )
    {
      DataPageOffset = pHeader->DataPageOffset;
      *(_WORD *)((char *)&pHeader[1].RefCount + DataPageOffset + 2) += 16 * (unsigned __int8)pHeader->UnitSize;
      (*(Scaleform::Render::MatrixPoolImpl::EntryHandle **)((char *)&pHeader[1].pHandle + DataPageOffset))[5].pHeader += (unsigned __int8)pHeader->UnitSize;
      Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(pHeader->pHandle);
      pHeader->pHandle = 0i64;
    }
  }
  return (Scaleform::Render::CacheEffect *)v10;
}

// File Line: 543
// RVA: 0x946FB0
void __fastcall Scaleform::Render::ViewMatrix3DEffect::ViewMatrix3DEffect(
        Scaleform::Render::ViewMatrix3DEffect *this,
        Scaleform::Render::TreeCacheNode *node,
        Scaleform::Render::ViewMatrix3DState *state,
        Scaleform::Render::CacheEffect *next)
{
  void *pData; // rdi

  this->vfptr = (Scaleform::Render::CacheEffectVtbl *)&Scaleform::Render::CacheEffect::`vftable;
  this->pNext = next;
  this->Length = 0;
  this->vfptr = (Scaleform::Render::CacheEffectVtbl *)&Scaleform::Render::ViewMatrix3DEffect::`vftable;
  pData = state->pData;
  Scaleform::Render::SKI_ViewMatrix3D::Start_Instance.vfptr->AddRef(
    &Scaleform::Render::SKI_ViewMatrix3D::Start_Instance,
    pData);
  this->StartEntry.pNextPattern = 0i64;
  this->StartEntry.pChain = 0i64;
  *(_DWORD *)&this->StartEntry.ChainHeight = 0;
  this->StartEntry.Key.pImpl = &Scaleform::Render::SKI_ViewMatrix3D::Start_Instance;
  this->StartEntry.Key.Data = pData;
  Scaleform::Render::SKI_ViewMatrix3D::Start_Instance.vfptr->AddRef(
    &Scaleform::Render::SKI_ViewMatrix3D::Start_Instance,
    pData);
  this->StartEntry.pBundle.pObject = 0i64;
  this->StartEntry.pSourceNode = node;
  this->StartEntry.Removed = 0;
  Scaleform::Render::SKI_ViewMatrix3D::Start_Instance.vfptr->Release(
    &Scaleform::Render::SKI_ViewMatrix3D::Start_Instance,
    pData);
  Scaleform::Render::SKI_ViewMatrix3D::End_Instance.vfptr->AddRef(
    &Scaleform::Render::SKI_ViewMatrix3D::End_Instance,
    0i64);
  this->EndEntry.pNextPattern = 0i64;
  this->EndEntry.pChain = 0i64;
  *(_DWORD *)&this->EndEntry.ChainHeight = 0;
  this->EndEntry.Key.pImpl = &Scaleform::Render::SKI_ViewMatrix3D::End_Instance;
  this->EndEntry.Key.Data = 0i64;
  Scaleform::Render::SKI_ViewMatrix3D::End_Instance.vfptr->AddRef(
    &Scaleform::Render::SKI_ViewMatrix3D::End_Instance,
    0i64);
  this->EndEntry.pBundle.pObject = 0i64;
  this->EndEntry.pSourceNode = node;
  this->EndEntry.Removed = 0;
  Scaleform::Render::SKI_ViewMatrix3D::End_Instance.vfptr->Release(
    &Scaleform::Render::SKI_ViewMatrix3D::End_Instance,
    0i64);
}

// File Line: 547
// RVA: 0x9BCCB0
char __fastcall Scaleform::Render::ViewMatrix3DEffect::Update(
        Scaleform::Render::ViewMatrix3DEffect *this,
        Scaleform::Render::State *stateArg)
{
  void *pData; // [rsp+30h] [rbp-18h]

  Scaleform::Render::BundleEntry::ClearBundle(&this->StartEntry);
  pData = stateArg->pData;
  Scaleform::Render::SKI_ViewMatrix3D::Start_Instance.vfptr->AddRef(
    &Scaleform::Render::SKI_ViewMatrix3D::Start_Instance,
    pData);
  Scaleform::Render::SKI_ViewMatrix3D::Start_Instance.vfptr->AddRef(
    &Scaleform::Render::SKI_ViewMatrix3D::Start_Instance,
    pData);
  this->StartEntry.Key.pImpl->vfptr->Release(this->StartEntry.Key.pImpl, this->StartEntry.Key.Data);
  this->StartEntry.Key.pImpl = &Scaleform::Render::SKI_ViewMatrix3D::Start_Instance;
  this->StartEntry.Key.Data = pData;
  Scaleform::Render::SKI_ViewMatrix3D::Start_Instance.vfptr->Release(
    &Scaleform::Render::SKI_ViewMatrix3D::Start_Instance,
    pData);
  return 1;
}

// File Line: 568
// RVA: 0x928D80
void __fastcall Scaleform::Render::ViewMatrix3DEffect::Create(
        Scaleform::Render::TreeCacheNode *node,
        Scaleform::Render::ViewMatrix3DState *stateArg,
        Scaleform::Render::CacheEffect *next)
{
  Scaleform::Render::ViewMatrix3DEffect *v6; // rax
  int v7; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::Render::ViewMatrix3DEffect *v8; // [rsp+68h] [rbp+20h]

  v7 = 71;
  v6 = (Scaleform::Render::ViewMatrix3DEffect *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeCacheNode *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  node,
                                                  152i64,
                                                  &v7,
                                                  -2i64);
  v8 = v6;
  if ( v6 )
    Scaleform::Render::ViewMatrix3DEffect::ViewMatrix3DEffect(v6, node, stateArg, next);
}

// File Line: 581
// RVA: 0x940C70
void __fastcall Scaleform::Render::ProjectionMatrix3DEffect::ProjectionMatrix3DEffect(
        Scaleform::Render::ProjectionMatrix3DEffect *this,
        Scaleform::Render::TreeCacheNode *node,
        Scaleform::Render::ProjectionMatrix3DState *state,
        Scaleform::Render::CacheEffect *next)
{
  void *pData; // rdi

  this->vfptr = (Scaleform::Render::CacheEffectVtbl *)&Scaleform::Render::CacheEffect::`vftable;
  this->pNext = next;
  this->Length = 0;
  this->vfptr = (Scaleform::Render::CacheEffectVtbl *)&Scaleform::Render::ProjectionMatrix3DEffect::`vftable;
  pData = state->pData;
  Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance.vfptr->AddRef(
    &Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance,
    pData);
  this->StartEntry.pNextPattern = 0i64;
  this->StartEntry.pChain = 0i64;
  *(_DWORD *)&this->StartEntry.ChainHeight = 0;
  this->StartEntry.Key.pImpl = &Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance;
  this->StartEntry.Key.Data = pData;
  Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance.vfptr->AddRef(
    &Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance,
    pData);
  this->StartEntry.pBundle.pObject = 0i64;
  this->StartEntry.pSourceNode = node;
  this->StartEntry.Removed = 0;
  Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance.vfptr->Release(
    &Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance,
    pData);
  Scaleform::Render::SKI_ProjectionMatrix3D::End_Instance.vfptr->AddRef(
    &Scaleform::Render::SKI_ProjectionMatrix3D::End_Instance,
    0i64);
  this->EndEntry.pNextPattern = 0i64;
  this->EndEntry.pChain = 0i64;
  *(_DWORD *)&this->EndEntry.ChainHeight = 0;
  this->EndEntry.Key.pImpl = &Scaleform::Render::SKI_ProjectionMatrix3D::End_Instance;
  this->EndEntry.Key.Data = 0i64;
  Scaleform::Render::SKI_ProjectionMatrix3D::End_Instance.vfptr->AddRef(
    &Scaleform::Render::SKI_ProjectionMatrix3D::End_Instance,
    0i64);
  this->EndEntry.pBundle.pObject = 0i64;
  this->EndEntry.pSourceNode = node;
  this->EndEntry.Removed = 0;
  Scaleform::Render::SKI_ProjectionMatrix3D::End_Instance.vfptr->Release(
    &Scaleform::Render::SKI_ProjectionMatrix3D::End_Instance,
    0i64);
}

// File Line: 586
// RVA: 0x9BC170
char __fastcall Scaleform::Render::ProjectionMatrix3DEffect::Update(
        Scaleform::Render::ProjectionMatrix3DEffect *this,
        Scaleform::Render::State *stateArg)
{
  void *pData; // [rsp+30h] [rbp-18h]

  Scaleform::Render::BundleEntry::ClearBundle(&this->StartEntry);
  pData = stateArg->pData;
  Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance.vfptr->AddRef(
    &Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance,
    pData);
  Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance.vfptr->AddRef(
    &Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance,
    pData);
  this->StartEntry.Key.pImpl->vfptr->Release(this->StartEntry.Key.pImpl, this->StartEntry.Key.Data);
  this->StartEntry.Key.pImpl = &Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance;
  this->StartEntry.Key.Data = pData;
  Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance.vfptr->Release(
    &Scaleform::Render::SKI_ProjectionMatrix3D::Start_Instance,
    pData);
  return 1;
}

// File Line: 607
// RVA: 0x928DF0
void __fastcall Scaleform::Render::ProjectionMatrix3DEffect::Create(
        Scaleform::Render::TreeCacheNode *node,
        Scaleform::Render::ProjectionMatrix3DState *stateArg,
        Scaleform::Render::CacheEffect *next)
{
  Scaleform::Render::ProjectionMatrix3DEffect *v6; // rax
  int v7; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::Render::ProjectionMatrix3DEffect *v8; // [rsp+68h] [rbp+20h]

  v7 = 71;
  v6 = (Scaleform::Render::ProjectionMatrix3DEffect *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeCacheNode *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                        Scaleform::Memory::pGlobalHeap,
                                                        node,
                                                        152i64,
                                                        &v7,
                                                        -2i64);
  v8 = v6;
  if ( v6 )
    Scaleform::Render::ProjectionMatrix3DEffect::ProjectionMatrix3DEffect(v6, node, stateArg, next);
}

// File Line: 620
// RVA: 0x946BD0
void __fastcall Scaleform::Render::UserDataEffect::UserDataEffect(
        Scaleform::Render::UserDataEffect *this,
        Scaleform::Render::TreeCacheNode *node,
        Scaleform::Render::UserDataState *state,
        Scaleform::Render::CacheEffect *next)
{
  this->vfptr = (Scaleform::Render::CacheEffectVtbl *)&Scaleform::Render::CacheEffect::`vftable;
  this->pNext = next;
  this->Length = 0;
  this->vfptr = (Scaleform::Render::CacheEffectVtbl *)&Scaleform::Render::UserDataEffect::`vftable;
  Scaleform::Render::SKI_UserData::Start_Instance.vfptr->AddRef(&Scaleform::Render::SKI_UserData::Start_Instance, 0i64);
  this->StartEntry.pNextPattern = 0i64;
  this->StartEntry.pChain = 0i64;
  *(_DWORD *)&this->StartEntry.ChainHeight = 0;
  this->StartEntry.Key.pImpl = &Scaleform::Render::SKI_UserData::Start_Instance;
  this->StartEntry.Key.Data = 0i64;
  Scaleform::Render::SKI_UserData::Start_Instance.vfptr->AddRef(&Scaleform::Render::SKI_UserData::Start_Instance, 0i64);
  this->StartEntry.pBundle.pObject = 0i64;
  this->StartEntry.pSourceNode = node;
  this->StartEntry.Removed = 0;
  Scaleform::Render::SKI_UserData::Start_Instance.vfptr->Release(&Scaleform::Render::SKI_UserData::Start_Instance, 0i64);
  Scaleform::Render::SKI_UserData::End_Instance.vfptr->AddRef(&Scaleform::Render::SKI_UserData::End_Instance, 0i64);
  this->EndEntry.pNextPattern = 0i64;
  this->EndEntry.pChain = 0i64;
  *(_DWORD *)&this->EndEntry.ChainHeight = 0;
  this->EndEntry.Key.pImpl = &Scaleform::Render::SKI_UserData::End_Instance;
  this->EndEntry.Key.Data = 0i64;
  Scaleform::Render::SKI_UserData::End_Instance.vfptr->AddRef(&Scaleform::Render::SKI_UserData::End_Instance, 0i64);
  this->EndEntry.pBundle.pObject = 0i64;
  this->EndEntry.pSourceNode = node;
  this->EndEntry.Removed = 0;
  Scaleform::Render::SKI_UserData::End_Instance.vfptr->Release(&Scaleform::Render::SKI_UserData::End_Instance, 0i64);
  Scaleform::Render::UserDataEffect::rebuildBundles(this, state);
}

// File Line: 625
// RVA: 0x9BCC70
char __fastcall Scaleform::Render::UserDataEffect::Update(
        Scaleform::Render::UserDataEffect *this,
        Scaleform::Render::UserDataState *stateArg)
{
  Scaleform::Render::BundleEntry::ClearBundle(&this->StartEntry);
  Scaleform::Render::UserDataEffect::rebuildBundles(this, stateArg);
  return 1;
}

// File Line: 646
// RVA: 0x928E60
void __fastcall Scaleform::Render::UserDataEffect::Create(
        Scaleform::Render::TreeCacheNode *node,
        Scaleform::Render::UserDataState *stateArg,
        Scaleform::Render::CacheEffect *next)
{
  Scaleform::Render::UserDataEffect *v6; // rax
  int v7; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::Render::UserDataEffect *v8; // [rsp+68h] [rbp+20h]

  v7 = 71;
  v6 = (Scaleform::Render::UserDataEffect *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeCacheNode *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                              Scaleform::Memory::pGlobalHeap,
                                              node,
                                              152i64,
                                              &v7,
                                              -2i64);
  v8 = v6;
  if ( v6 )
    Scaleform::Render::UserDataEffect::UserDataEffect(v6, node, stateArg, next);
}

// File Line: 653
// RVA: 0x9EF350
void __fastcall Scaleform::Render::UserDataEffect::rebuildBundles(
        Scaleform::Render::UserDataEffect *this,
        Scaleform::Render::UserDataState *state)
{
  void *pData; // rdi

  pData = state->pData;
  Scaleform::Render::SKI_UserData::Start_Instance.vfptr->AddRef(&Scaleform::Render::SKI_UserData::Start_Instance, pData);
  Scaleform::Render::SKI_UserData::Start_Instance.vfptr->AddRef(&Scaleform::Render::SKI_UserData::Start_Instance, pData);
  this->StartEntry.Key.pImpl->vfptr->Release(this->StartEntry.Key.pImpl, this->StartEntry.Key.Data);
  this->StartEntry.Key.pImpl = &Scaleform::Render::SKI_UserData::Start_Instance;
  this->StartEntry.Key.Data = pData;
  Scaleform::Render::SKI_UserData::Start_Instance.vfptr->Release(
    &Scaleform::Render::SKI_UserData::Start_Instance,
    pData);
}

