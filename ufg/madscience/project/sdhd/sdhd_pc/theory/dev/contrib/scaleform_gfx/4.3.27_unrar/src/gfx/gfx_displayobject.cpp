// File Line: 41
// RVA: 0x8955D0
void __fastcall Scaleform::GFx::DisplayObjectBase::DisplayObjectBase(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::GFx::ASMovieRootBase *pasRoot,
        Scaleform::GFx::InteractiveObject *parent,
        unsigned int *id)
{
  Scaleform::Render::TreeNode *pObject; // rcx

  this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable;
  this->RefCount = 1;
  this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable;
  this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountWeakSupportImpl::`vftable;
  this->pWeakProxy = 0i64;
  this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::`vftable;
  this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::`vftable;
  this->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::`vftable;
  this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::DisplayObjectBase::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  this->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::DisplayObjectBase::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  this->pASRoot = pasRoot;
  this->Id.Id = *id;
  this->Depth = -1;
  this->CreateFrame = 0;
  this->pParent = parent;
  this->pRenNode.pObject = 0i64;
  this->pGeomData = 0i64;
  this->pPerspectiveData = 0i64;
  this->pIndXFormData = 0i64;
  *(_DWORD *)&this->ClipDepth = 0x40000000;
  *(_WORD *)&this->BlendMode = 0;
  pObject = this->pRenNode.pObject;
  if ( pObject )
    Scaleform::Render::TreeNode::SetVisible(pObject, 1);
}

// File Line: 49
// RVA: 0x8A3E00
void __fastcall Scaleform::GFx::DisplayObjectBase::~DisplayObjectBase(Scaleform::GFx::DisplayObjectBase *this)
{
  unsigned __int8 AvmObjOffset; // al
  Scaleform::Render::TreeNode *pObject; // rcx

  this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::DisplayObjectBase::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  this->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::DisplayObjectBase::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  if ( this->pGeomData )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( this->pPerspectiveData )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( this->pIndXFormData )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
    (**(void (__fastcall ***)(char *, _QWORD))((char *)&this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                             + 4 * AvmObjOffset))(
      (char *)this + 4 * AvmObjOffset,
      0i64);
  pObject = this->pRenNode.pObject;
  if ( pObject )
  {
    if ( pObject->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(pObject);
  }
  this->Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::`vftable;
  Scaleform::RefCountWeakSupportImpl::~RefCountWeakSupportImpl(this);
}

// File Line: 66
// RVA: 0x8DD6A0
Scaleform::Render::TreeNode *__fastcall Scaleform::GFx::DisplayObjectBase::GetRenderNode(
        Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode **v2; // rdi
  Scaleform::Render::TreeNode *pObject; // rcx
  bool v4; // zf
  Scaleform::Render::ContextImpl::Entry *v5; // rcx
  Scaleform::Render::ContextImpl::Entry *v7; // [rsp+40h] [rbp+8h] BYREF

  if ( this->pRenNode.pObject )
    return this->pRenNode.pObject;
  v2 = (Scaleform::Render::TreeNode **)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::ContextImpl::Entry **, Scaleform::Render::ContextImpl::Context *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[1].__vecDelDtor)(
                                         this,
                                         &v7,
                                         &this->pASRoot->pMovieImpl->RenderContext);
  if ( *v2 )
    ++(*v2)->RefCount;
  pObject = this->pRenNode.pObject;
  if ( pObject )
  {
    v4 = pObject->RefCount-- == 1;
    if ( v4 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(pObject);
  }
  this->pRenNode.pObject = *v2;
  v5 = v7;
  if ( v7 )
  {
    v4 = v7->RefCount-- == 1;
    if ( v4 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v5);
  }
  Scaleform::Render::TreeNode::SetVisible(this->pRenNode.pObject, (this->Flags & 0x4000) != 0);
  return this->pRenNode.pObject;
}

// File Line: 77
// RVA: 0x8BDEF0
Scaleform::Render::TreeContainer *__fastcall Scaleform::GFx::DisplayObjectBase::ConvertToTreeContainer(
        Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeContainer *pParent; // r14
  Scaleform::Render::BlendMode pData; // r12d
  Scaleform::Render::TreeContainer *v4; // rbx
  Scaleform::Render::TreeNode *pObject; // r15
  unsigned __int64 v6; // rsi
  unsigned __int64 Size; // r9
  _QWORD *v8; // rcx
  Scaleform::Render::TreeNode *v9; // rcx
  Scaleform::Render::Matrix3x4<float> *v10; // rax
  Scaleform::Render::Matrix2x4<float> *v11; // rax
  Scaleform::Render::TreeNode *v12; // rcx
  Scaleform::Render::Cxform *v13; // rsi
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax
  Scaleform::Render::ContextImpl::EntryData *v15; // rax
  char v16; // al
  Scaleform::Render::State *State; // rax
  Scaleform::Render::State *v18; // rax
  float *v19; // rax
  float v20; // xmm3_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  Scaleform::Render::TreeNode *v23; // rcx
  bool v24; // zf
  Scaleform::Render::Rect<float> v26; // [rsp+20h] [rbp-79h] BYREF
  Scaleform::Render::Rect<float> rect; // [rsp+30h] [rbp-69h] BYREF
  Scaleform::Render::Matrix3x4<float> mat3D; // [rsp+40h] [rbp-59h] BYREF
  __int64 v29; // [rsp+70h] [rbp-29h]
  Scaleform::Render::Matrix4x4<float> Dst; // [rsp+80h] [rbp-19h] BYREF

  v29 = -2i64;
  if ( !this->pRenNode.pObject )
    Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  pParent = (Scaleform::Render::TreeContainer *)this->pRenNode.pObject->pParent;
  pData = Blend_None;
  v4 = Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeContainer>(&this->pASRoot->pMovieImpl->RenderContext);
  if ( pParent )
  {
    pObject = this->pRenNode.pObject;
    if ( (*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                               + 8i64
                               * (unsigned int)((int)(LODWORD(this->pRenNode.pObject)
                                                    - ((__int64)this->pRenNode.pObject & 0xFFFFF000)
                                                    - 56)
                                              / 56)
                               + 40)
                   + 10i64) & 0x20) != 0 )
    {
      Scaleform::Render::TreeNode::SetMaskNode(pParent, 0i64);
      Scaleform::Render::TreeNode::SetMaskNode(pParent, v4);
    }
    else
    {
      v6 = 0i64;
      Size = Scaleform::Render::TreeContainer::GetSize(pParent);
      if ( Size )
      {
        do
        {
          v8 = (_QWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pParent & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                    + 8i64
                                    * (unsigned int)((__int64)((__int64)&pParent[-1]
                                                             - ((unsigned __int64)pParent & 0xFFFFFFFFFFFFF000ui64))
                                                   / 56)
                                    + 40)
                        + 144i64);
          if ( (*(_BYTE *)v8 & 1) != 0 )
            v8 = (_QWORD *)((*v8 & 0xFFFFFFFFFFFFFFFEui64) + 16);
          if ( (Scaleform::Render::TreeNode *)v8[v6] == pObject )
            break;
          ++v6;
        }
        while ( v6 < Size );
      }
      Scaleform::Render::TreeContainer::Remove(pParent, v6, 1ui64);
      Scaleform::Render::TreeContainer::Insert(pParent, v6, v4);
    }
  }
  v9 = this->pRenNode.pObject;
  if ( v9
    && (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v9 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64 * (unsigned int)((int)((_DWORD)v9 - ((unsigned int)v9 & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 10i64) & 0x200) != 0 )
  {
    v10 = (Scaleform::Render::Matrix3x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[4].__vecDelDtor)(this);
    Scaleform::Render::TreeNode::SetMatrix3D(v4, v10);
    memset(&Dst, 0, sizeof(Dst));
    Dst.M[0][0] = 1.0;
    Dst.M[1][1] = 1.0;
    Dst.M[2][2] = 1.0;
    Dst.M[3][3] = 1.0;
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Matrix4x4<float> *, _QWORD))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[6].__vecDelDtor)(
           this,
           &Dst,
           0i64) )
    {
      Scaleform::Render::TreeNode::SetProjectionMatrix3D(v4, &Dst);
    }
    memset(&mat3D, 0, sizeof(mat3D));
    mat3D.M[0][0] = 1.0;
    mat3D.M[1][1] = 1.0;
    mat3D.M[2][2] = 1.0;
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Matrix3x4<float> *, _QWORD))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[9].__vecDelDtor)(
           this,
           &mat3D,
           0i64) )
    {
      Scaleform::Render::TreeNode::SetViewMatrix3D(v4, &mat3D);
    }
    Scaleform::Render::TreeNode::SetMatrix3D(this->pRenNode.pObject, &Scaleform::Render::Matrix3x4<float>::Identity);
  }
  else
  {
    v11 = (Scaleform::Render::Matrix2x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
    Scaleform::Render::TreeNode::SetMatrix(v4, v11);
    Scaleform::Render::TreeNode::SetMatrix(this->pRenNode.pObject, &Scaleform::Render::Matrix2x4<float>::Identity);
  }
  v12 = this->pRenNode.pObject;
  if ( v12 )
    v13 = (Scaleform::Render::Cxform *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v12 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                                  + 8i64
                                                  * (unsigned int)((int)((_DWORD)v12
                                                                       - ((unsigned int)v12 & 0xFFFFF000)
                                                                       - 56)
                                                                 / 56)
                                                  + 40)
                                      + 80i64);
  else
    v13 = &Scaleform::Render::Cxform::Identity;
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(v4, 2u);
  WritableData[5] = *(Scaleform::Render::ContextImpl::EntryData *)&v13->M[0][0];
  WritableData[6] = *(Scaleform::Render::ContextImpl::EntryData *)&v13->M[1][0];
  v15 = Scaleform::Render::ContextImpl::Entry::getWritableData(this->pRenNode.pObject, 2u);
  v15[5] = *(Scaleform::Render::ContextImpl::EntryData *)&Scaleform::Render::Cxform::Identity.M[0][0];
  v15[6] = *(Scaleform::Render::ContextImpl::EntryData *)&Scaleform::Render::Cxform::Identity.M[1][0];
  v16 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[59].__vecDelDtor)(this);
  Scaleform::Render::TreeNode::SetVisible(v4, v16);
  Scaleform::Render::TreeNode::SetVisible(this->pRenNode.pObject, 1);
  State = Scaleform::Render::TreeNode::GetState(this->pRenNode.pObject, State_BlendMode);
  if ( State )
    pData = (Scaleform::Render::BlendMode)State->pData;
  Scaleform::Render::TreeNode::SetBlendMode(v4, pData);
  Scaleform::Render::TreeNode::SetBlendMode(this->pRenNode.pObject, Blend_None);
  v18 = Scaleform::Render::TreeNode::GetState(this->pRenNode.pObject, State_Scale9);
  if ( v18 )
  {
    v19 = (float *)v18->pData;
    v20 = v19[7];
    v21 = v19[6];
    v22 = v19[5];
    v26.x1 = v19[4];
    v26.y1 = v22;
    v26.x2 = v21;
    v26.y2 = v20;
  }
  else
  {
    v26 = 0i64;
  }
  rect = v26;
  if ( v26.x1 < v26.x2 && v26.y1 < v26.y2 )
  {
    Scaleform::Render::TreeNode::SetScale9Grid(v4, &rect);
    v26 = 0i64;
    Scaleform::Render::TreeNode::SetScale9Grid(this->pRenNode.pObject, &v26);
  }
  Scaleform::Render::TreeContainer::Add(v4, this->pRenNode.pObject);
  if ( v4 )
    ++v4->RefCount;
  v23 = this->pRenNode.pObject;
  if ( v23 )
  {
    v24 = v23->RefCount-- == 1;
    if ( v24 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v23);
  }
  this->pRenNode.pObject = v4;
  if ( v4 )
  {
    v24 = v4->RefCount-- == 1;
    if ( v24 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v4);
  }
  return v4;
}

// File Line: 165
// RVA: 0x8DAEC0
Scaleform::Render::Matrix2x4<float> *__fastcall Scaleform::GFx::DisplayObjectBase::GetMatrix(
        Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::Matrix2x4<float> *result; // rax
  Scaleform::Render::TreeNode *pObject; // rcx

  result = (Scaleform::Render::Matrix2x4<float> *)this->pIndXFormData;
  if ( !result )
  {
    pObject = this->pRenNode.pObject;
    if ( pObject )
      return (Scaleform::Render::Matrix2x4<float> *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64)
                                                                           + 0x20)
                                                               + 8i64
                                                               * (unsigned int)((int)((_DWORD)pObject
                                                                                    - ((unsigned int)pObject & 0xFFFFF000)
                                                                                    - 56)
                                                                              / 56)
                                                               + 40)
                                                   + 16i64);
    else
      return &Scaleform::Render::Matrix2x4<float>::Identity;
  }
  return result;
}

// File Line: 179
// RVA: 0x909500
void __fastcall Scaleform::GFx::DisplayObjectBase::SetMatrix(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Matrix2x4<float> *m)
{
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *pIndXFormData; // rax
  Scaleform::Render::TreeNode *v5; // rax
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm6_4
  float v12; // xmm7_4
  Scaleform::Render::TreeNode *RenderNode; // rax

  pIndXFormData = this->pIndXFormData;
  if ( pIndXFormData )
  {
    v6 = m->M[0][1];
    v7 = m->M[0][2];
    v8 = m->M[0][3];
    v9 = m->M[1][0];
    v10 = m->M[1][1];
    v11 = m->M[1][2];
    v12 = m->M[1][3];
    pIndXFormData->OrigTransformMatrix.M[0][0] = m->M[0][0];
    pIndXFormData->OrigTransformMatrix.M[0][1] = v6;
    pIndXFormData->OrigTransformMatrix.M[0][2] = v7;
    pIndXFormData->OrigTransformMatrix.M[0][3] = v8;
    pIndXFormData->OrigTransformMatrix.M[1][0] = v9;
    pIndXFormData->OrigTransformMatrix.M[1][1] = v10;
    pIndXFormData->OrigTransformMatrix.M[1][2] = v11;
    pIndXFormData->OrigTransformMatrix.M[1][3] = v12;
    LODWORD(pIndXFormData->OrigTransformMatrix.M[2][0]) = _xmm.m128_i32[0];
    LODWORD(pIndXFormData->OrigTransformMatrix.M[2][1]) = _mm_shuffle_ps(_xmm, _xmm, 85).m128_u32[0];
    LODWORD(pIndXFormData->OrigTransformMatrix.M[2][2]) = _mm_shuffle_ps(_xmm, _xmm, 170).m128_u32[0];
    LODWORD(pIndXFormData->OrigTransformMatrix.M[2][3]) = _xmm.m128_i32[3];
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::ContextImpl::Entry::getWritableData(RenderNode, 1u);
  }
  else
  {
    v5 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::TreeNode::SetMatrix(v5, m);
  }
  Scaleform::GFx::DisplayObjectBase::UpdateViewAndPerspective(this);
}

// File Line: 194
// RVA: 0x8DADF0
Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *__fastcall Scaleform::GFx::DisplayObjectBase::GetMatrix3D(
        Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *result; // rax
  Scaleform::Render::TreeNode *pObject; // rcx

  result = this->pIndXFormData;
  if ( !result )
  {
    pObject = this->pRenNode.pObject;
    if ( pObject )
      return (Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                                                                        + 8i64
                                                                                        * (unsigned int)((int)((_DWORD)pObject - ((unsigned int)pObject & 0xFFFFF000) - 56) / 56)
                                                                                        + 40)
                                                                            + 16i64);
    else
      return (Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *)&Scaleform::Render::Matrix3x4<float>::Identity;
  }
  return result;
}

// File Line: 209
// RVA: 0x909220
void __fastcall Scaleform::GFx::DisplayObjectBase::SetMatrix3D(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Matrix3x4<float> *m)
{
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *pIndXFormData; // rcx
  Scaleform::Render::TreeNode *v5; // rax
  Scaleform::Render::TreeNode *RenderNode; // rax

  pIndXFormData = this->pIndXFormData;
  if ( pIndXFormData )
  {
    pIndXFormData->OrigTransformMatrix = *m;
    this->pIndXFormData->IsOrig3D = 1;
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::ContextImpl::Entry::getWritableData(RenderNode, 1u);
  }
  else
  {
    v5 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::TreeNode::SetMatrix3D(v5, m);
  }
  Scaleform::GFx::DisplayObjectBase::UpdateViewAndPerspective(this);
}

// File Line: 225
// RVA: 0x8E1590
char __fastcall Scaleform::GFx::DisplayObjectBase::GetViewMatrix3D(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Matrix3x4<float> *m,
        bool bInherit)
{
  Scaleform::Render::TreeNode *pObject; // rcx
  Scaleform::GFx::InteractiveObject *pParent; // rcx
  Scaleform::GFx::MovieImpl *pMovieImpl; // rcx

  pObject = this->pRenNode.pObject;
  if ( pObject
    && (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64
                             * (unsigned int)((int)((_DWORD)pObject - ((unsigned int)pObject & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 10i64) & 0x800) != 0 )
  {
    *m = this->pPerspectiveData->ViewMatrix3D;
    return 1;
  }
  if ( !bInherit )
    return 0;
  pParent = this->pParent;
  if ( pParent )
    return (char)pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[9].__vecDelDtor(
                   pParent,
                   (unsigned int)m);
  pMovieImpl = this->pASRoot->pMovieImpl;
  if ( !pMovieImpl )
    return 0;
  return Scaleform::Render::TreeNode::GetViewMatrix3D(pMovieImpl->pRenderRoot.pObject, m);
}

// File Line: 257
// RVA: 0x90E990
void __fastcall Scaleform::GFx::DisplayObjectBase::SetViewMatrix3D(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Matrix3x4<float> *m)
{
  Scaleform::Render::TreeNode *pObject; // rcx
  bool v5; // r10
  Scaleform::GFx::InteractiveObject *pParent; // r9
  Scaleform::Render::TreeNode *v7; // rcx
  _QWORD *v8; // rax
  _QWORD *v9; // rdi
  float *pPerspectiveData; // rcx
  Scaleform::GFx::MovieImpl *pMovieImpl; // rbx
  float x1; // xmm6_4
  Scaleform::Render::TreeNode *RenderNode; // rax
  Scaleform::Render::Matrix3x4<float> m1; // [rsp+20h] [rbp-A9h] BYREF
  _QWORD *v15; // [rsp+50h] [rbp-79h]
  __int64 v16; // [rsp+58h] [rbp-71h]
  Scaleform::Render::Matrix3x4<float> Dst; // [rsp+60h] [rbp-69h] BYREF
  Scaleform::Render::Matrix3x4<float> mat3D; // [rsp+90h] [rbp-39h] BYREF
  Scaleform::Render::Matrix3x4<float> m2; // [rsp+C0h] [rbp-9h] BYREF
  int v20; // [rsp+140h] [rbp+77h] BYREF
  __int64 v21; // [rsp+148h] [rbp+7Fh]

  v16 = -2i64;
  pObject = this->pRenNode.pObject;
  v5 = pObject
    && (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64
                             * (unsigned int)((int)((_DWORD)pObject - ((unsigned int)pObject & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 10i64) & 0x800) != 0;
  pParent = this->pParent;
  if ( !pParent
    || (v7 = pParent->pRenNode.pObject) == 0i64
    || (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64 * (unsigned int)((int)((_DWORD)v7 - ((unsigned int)v7 & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 10i64) & 0x200) == 0
    || pParent->pPerspectiveData
    || v5 )
  {
    if ( !this->pPerspectiveData )
    {
      v20 = 322;
      v8 = Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, 80i64, &v20);
      v9 = v8;
      v15 = v8;
      if ( v8 )
      {
        *v8 = 0i64;
        v8[1] = 0i64;
        memset(v8 + 4, 0, 0x30ui64);
        *((_DWORD *)v9 + 8) = 1065353216;
        *((_DWORD *)v9 + 13) = 1065353216;
        *((_DWORD *)v9 + 18) = 1065353216;
        *((float *)v9 + 4) = NAN;
        v21 = *(_QWORD *)GFxNaN_Bytes;
        *((float *)v9 + 5) = NAN;
      }
      else
      {
        v9 = 0i64;
      }
      this->pPerspectiveData = (Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *)v9;
    }
    pPerspectiveData = (float *)this->pPerspectiveData;
    pPerspectiveData[8] = m->M[0][0];
    pPerspectiveData[9] = m->M[0][1];
    pPerspectiveData[10] = m->M[0][2];
    pPerspectiveData[11] = m->M[0][3];
    pPerspectiveData[12] = m->M[1][0];
    pPerspectiveData[13] = m->M[1][1];
    pPerspectiveData[14] = m->M[1][2];
    pPerspectiveData[15] = m->M[1][3];
    pPerspectiveData[16] = m->M[2][0];
    pPerspectiveData[17] = m->M[2][1];
    pPerspectiveData[18] = m->M[2][2];
    pPerspectiveData[19] = m->M[2][3];
    pMovieImpl = this->pASRoot->pMovieImpl;
    memset(&Dst, 0, sizeof(Dst));
    x1 = pMovieImpl->VisibleFrameRect.x1;
    Dst.M[0][0] = 1.0 / (float)((float)pMovieImpl->mViewport.Width / (float)(pMovieImpl->VisibleFrameRect.x2 - x1));
    Dst.M[1][1] = 1.0
                / (float)((float)pMovieImpl->mViewport.Height
                        / (float)(pMovieImpl->VisibleFrameRect.y2 - pMovieImpl->VisibleFrameRect.y1));
    Dst.M[2][2] = 1.0;
    memset(&m1, 0, sizeof(m1));
    m1.M[0][0] = 1.0;
    m1.M[1][1] = 1.0;
    *(_QWORD *)&m1.M[2][2] = 1065353216i64;
    m1.M[0][3] = x1;
    m1.M[1][3] = pMovieImpl->VisibleFrameRect.y1;
    Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&m2, &m1, &Dst);
    Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&mat3D, m, &m2);
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::TreeNode::SetViewMatrix3D(RenderNode, &mat3D);
    if ( pMovieImpl->MovieLevels.Data.Data->pSprite.pObject == this )
    {
      Scaleform::Render::TreeNode::SetViewMatrix3D(pMovieImpl->pRenderRoot.pObject, &mat3D);
      Scaleform::Render::TreeNode::SetViewMatrix3D(pMovieImpl->pTopMostRoot.pObject, &mat3D);
    }
  }
}

// File Line: 289
// RVA: 0x8BCAB0
void __fastcall Scaleform::GFx::DisplayObjectBase::ClearViewMatrix3D(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode *RenderNode; // rax

  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeNode::ClearViewMatrix3D(RenderNode);
}

// File Line: 294
// RVA: 0x8DC460
char __fastcall Scaleform::GFx::DisplayObjectBase::GetProjectionMatrix3D(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Matrix4x4<float> *m,
        bool bInherit)
{
  Scaleform::Render::TreeNode *pObject; // rcx
  Scaleform::GFx::InteractiveObject *pParent; // rcx
  Scaleform::GFx::MovieImpl *pMovieImpl; // rcx

  pObject = this->pRenNode.pObject;
  if ( pObject && Scaleform::Render::TreeNode::GetProjectionMatrix3D(pObject, m) )
    return 1;
  if ( !bInherit )
    return 0;
  pParent = this->pParent;
  if ( pParent )
    return ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::Render::Matrix4x4<float> *, bool))pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[6].__vecDelDtor)(
             pParent,
             m,
             bInherit);
  pMovieImpl = this->pASRoot->pMovieImpl;
  if ( !pMovieImpl )
    return 0;
  return Scaleform::Render::TreeNode::GetProjectionMatrix3D(pMovieImpl->pRenderRoot.pObject, m);
}

// File Line: 315
// RVA: 0x909FE0
void __fastcall Scaleform::GFx::DisplayObjectBase::SetProjectionMatrix3D(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Matrix4x4<float> *m)
{
  Scaleform::Render::TreeNode *pObject; // rcx
  bool v5; // r10
  Scaleform::GFx::InteractiveObject *pParent; // r9
  Scaleform::Render::TreeNode *v7; // rcx
  Scaleform::Render::TreeNode *RenderNode; // rax
  Scaleform::GFx::MovieImpl *pMovieImpl; // rdi

  pObject = this->pRenNode.pObject;
  v5 = pObject
    && (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64
                             * (unsigned int)((int)((_DWORD)pObject - ((unsigned int)pObject & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 10i64) & 0x1000) != 0;
  pParent = this->pParent;
  if ( !pParent
    || (v7 = pParent->pRenNode.pObject) == 0i64
    || (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64 * (unsigned int)((int)((_DWORD)v7 - ((unsigned int)v7 & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 10i64) & 0x200) == 0
    || pParent->pPerspectiveData
    || v5 )
  {
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::TreeNode::SetProjectionMatrix3D(RenderNode, m);
    pMovieImpl = this->pASRoot->pMovieImpl;
    if ( pMovieImpl )
    {
      if ( pMovieImpl->MovieLevels.Data.Data->pSprite.pObject == this )
      {
        Scaleform::Render::TreeNode::SetProjectionMatrix3D(pMovieImpl->pRenderRoot.pObject, m);
        Scaleform::Render::TreeNode::SetProjectionMatrix3D(pMovieImpl->pTopMostRoot.pObject, m);
      }
    }
  }
}

// File Line: 335
// RVA: 0x8BC560
void __fastcall Scaleform::GFx::DisplayObjectBase::ClearProjectionMatrix3D(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode *RenderNode; // rax

  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeNode::ClearProjectionMatrix3D(RenderNode);
}

// File Line: 340
// RVA: 0x9184B0
void __fastcall Scaleform::GFx::DisplayObjectBase::UpdateViewAndPerspective(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // rsi
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *pPerspectiveData; // rdi
  Scaleform::Render::Rect<float> *p_VisibleFrameRect; // rsi
  float x2; // xmm8_4
  float x1; // xmm6_4
  float focalLength; // xmm12_4
  float x; // xmm10_4
  float y; // xmm11_4
  unsigned __int64 RenderNode; // rax
  Scaleform::GFx::InteractiveObject *pParent; // r15
  unsigned __int64 v12; // rdx
  __int64 v13; // rcx
  bool v14; // al
  bool v15; // r14
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v16; // rdi
  float *v17; // rax
  float v18; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm5_4
  float v22; // xmm4_4
  float v23; // xmm6_4
  float v24; // xmm8_4
  float v25; // xmm9_4
  float v26; // xmm5_4
  float v27; // xmm6_4
  float v28; // xmm1_4
  float v29; // xmm0_4
  float *v30; // rax
  float v31; // xmm0_4
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v32; // rax
  float fieldOfView; // xmm1_4
  double v34; // xmm0_8
  Scaleform::Render::Matrix2x4<float> pmat; // [rsp+40h] [rbp-A8h] BYREF
  Scaleform::Render::Matrix3x4<float> Dst[2]; // [rsp+60h] [rbp-88h] BYREF
  Scaleform::Render::Point<float> projCenter; // [rsp+148h] [rbp+60h] BYREF

  pMovieImpl = this->pASRoot->pMovieImpl;
  if ( pMovieImpl )
  {
    pPerspectiveData = this->pPerspectiveData;
    if ( pPerspectiveData )
    {
      if ( pPerspectiveData->FieldOfView != 0.0 || pPerspectiveData->FocalLength != 0.0 )
      {
        p_VisibleFrameRect = &pMovieImpl->VisibleFrameRect;
        x2 = p_VisibleFrameRect->x2;
        x1 = p_VisibleFrameRect->x1;
        if ( x2 != p_VisibleFrameRect->x1 || p_VisibleFrameRect->y1 != p_VisibleFrameRect->y2 )
        {
          memset(Dst, 0, 88);
          Dst[0].M[0][0] = 1.0;
          *(_QWORD *)&Dst[0].M[1][0] = 0x3F8000003F800000i64;
          Dst[0].M[1][2] = 1.0;
          Dst[0].M[2][3] = 1.0;
          Dst[1].M[1][0] = 1.0;
          Dst[1].M[2][1] = 1.0;
          focalLength = 0.0;
          if ( Scaleform::GFx::NumberUtil::IsNaN(pPerspectiveData->ProjectionCenter.x)
            || Scaleform::GFx::NumberUtil::IsNaN(pPerspectiveData->ProjectionCenter.y) )
          {
            v31 = p_VisibleFrameRect->y2 + p_VisibleFrameRect->y1;
            projCenter.x = (float)(x1 + x2) * 0.5;
            projCenter.y = v31 * 0.5;
          }
          else
          {
            x = pPerspectiveData->ProjectionCenter.x;
            y = pPerspectiveData->ProjectionCenter.y;
            projCenter.x = x;
            projCenter.y = y;
            RenderNode = (unsigned __int64)Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
            pParent = this->pParent;
            v12 = (__int64)((unsigned __int128)((__int64)(RenderNode - (RenderNode & 0xFFFFFFFFFFFFF000ui64) - 56)
                                              * (__int128)0x4924924924924925i64) >> 64) >> 4;
            v13 = *(_QWORD *)(*(_QWORD *)((RenderNode & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                            + 8 * ((unsigned int)v12 + (v12 >> 63))
                            + 40);
            v14 = 0;
            v15 = (*(_WORD *)(v13 + 10) & 0x200) != 0;
            if ( pParent )
            {
              v16 = pParent->pPerspectiveData;
              if ( v16 )
                v14 = !Scaleform::GFx::NumberUtil::IsNaN(v16->ProjectionCenter.x)
                   && !Scaleform::GFx::NumberUtil::IsNaN(v16->ProjectionCenter.y);
            }
            if ( this->pGeomData && (!v15 || v14) )
            {
              *(_OWORD *)&pmat.M[0][0] = _xmm;
              *(__m128 *)&pmat.M[1][0] = _xmm;
              if ( pParent )
              {
                Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(pParent, &pmat);
                v17 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
                v18 = pmat.M[0][0];
                v19 = pmat.M[0][1];
                v20 = pmat.M[1][0];
                v21 = pmat.M[0][0];
                v22 = pmat.M[1][1];
                v23 = pmat.M[1][0];
                v24 = (float)(pmat.M[0][0] * *v17) + (float)(pmat.M[0][1] * v17[4]);
                pmat.M[0][0] = v24;
                v25 = (float)(pmat.M[1][0] * *v17) + (float)(pmat.M[1][1] * v17[4]);
                pmat.M[1][0] = v25;
                v26 = (float)(v21 * v17[1]) + (float)(pmat.M[0][1] * v17[5]);
                *(_QWORD *)&pmat.M[0][1] = LODWORD(v26);
                v27 = (float)(v23 * v17[1]) + (float)(pmat.M[1][1] * v17[5]);
                *(_QWORD *)&pmat.M[1][1] = LODWORD(v27);
                v28 = pmat.M[0][3] + (float)((float)(v19 * v17[7]) + (float)(v18 * v17[3]));
                pmat.M[0][3] = v28;
                v29 = pmat.M[1][3] + (float)((float)(v22 * v17[7]) + (float)(v20 * v17[3]));
              }
              else
              {
                v30 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
                v24 = *v30;
                pmat.M[0][0] = *v30;
                v26 = v30[1];
                *(_QWORD *)&pmat.M[0][1] = *(_QWORD *)(v30 + 1);
                v28 = v30[3];
                pmat.M[0][3] = v28;
                v25 = v30[4];
                pmat.M[1][0] = v25;
                v27 = v30[5];
                *(_QWORD *)&pmat.M[1][1] = *(_QWORD *)(v30 + 5);
                v29 = v30[7];
              }
              projCenter.y = (float)((float)(v27 * y) + (float)(v25 * x)) + v29;
              projCenter.x = (float)((float)(v26 * y) + (float)(v24 * x)) + v28;
            }
          }
          v32 = this->pPerspectiveData;
          if ( v32->FieldOfView == 0.0 )
            fieldOfView = FLOAT_55_0;
          else
            fieldOfView = v32->FieldOfView;
          v34 = v32->FocalLength;
          if ( v34 != 0.0 )
            focalLength = v34;
          Scaleform::GFx::MovieImpl::MakeViewAndPersp3D(
            Dst,
            (Scaleform::Render::Matrix4x4<float> *)&Dst[0].M[1][2],
            p_VisibleFrameRect,
            &projCenter,
            fieldOfView,
            focalLength,
            0);
          this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[10].__vecDelDtor(
            this,
            (unsigned int)Dst);
          this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[7].__vecDelDtor(
            this,
            (unsigned int)&Dst[0].M[1][2]);
        }
      }
    }
  }
}

// File Line: 396
// RVA: 0x907060
void __fastcall Scaleform::GFx::DisplayObjectBase::SetFOV(Scaleform::GFx::DisplayObjectBase *this, long double fovdeg)
{
  double v2; // xmm6_8
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v4; // rax
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *pPerspectiveData; // rax
  long double v6; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v7; // [rsp+60h] [rbp+18h]

  v2 = fovdeg;
  v6 = fovdeg;
  if ( (*(_QWORD *)&fovdeg & 0x7FF0000000000000i64) != 0x7FF0000000000000i64
    || (*(_QWORD *)&fovdeg & 0xFFFFFFFFFFFFFi64) == 0 )
  {
    v6 = fovdeg;
    if ( fovdeg == -INFINITY || (v6 = fovdeg, fovdeg == INFINITY) )
      v2 = 0.0;
    if ( !this->pPerspectiveData )
    {
      LODWORD(v6) = 322;
      v4 = (Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::DisplayObjectBase *, __int64, long double *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                                       Scaleform::Memory::pGlobalHeap,
                                                                       this,
                                                                       80i64,
                                                                       &v6,
                                                                       -2i64);
      v7 = v4;
      if ( v4 )
        Scaleform::GFx::DisplayObjectBase::PerspectiveDataType::PerspectiveDataType(v4);
      this->pPerspectiveData = v4;
    }
    pPerspectiveData = this->pPerspectiveData;
    if ( v2 != pPerspectiveData->FieldOfView )
    {
      pPerspectiveData->FieldOfView = v2;
      Scaleform::GFx::DisplayObjectBase::UpdateViewAndPerspective(this);
    }
  }
}

// File Line: 414
// RVA: 0x8D7A40
double __fastcall Scaleform::GFx::DisplayObjectBase::GetFOV(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *pPerspectiveData; // rax

  pPerspectiveData = this->pPerspectiveData;
  if ( pPerspectiveData )
    return pPerspectiveData->FieldOfView;
  else
    return 0.0;
}

// File Line: 420
// RVA: 0x907440
void __fastcall Scaleform::GFx::DisplayObjectBase::SetFocalLength(
        Scaleform::GFx::DisplayObjectBase *this,
        long double focalLength)
{
  double v2; // xmm6_8
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v4; // rax
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *pPerspectiveData; // rax
  long double v6; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v7; // [rsp+60h] [rbp+18h]

  v2 = focalLength;
  v6 = focalLength;
  if ( (*(_QWORD *)&focalLength & 0x7FF0000000000000i64) != 0x7FF0000000000000i64
    || (*(_QWORD *)&focalLength & 0xFFFFFFFFFFFFFi64) == 0 )
  {
    v6 = focalLength;
    if ( focalLength == -INFINITY || (v6 = focalLength, focalLength == INFINITY) )
      v2 = 0.0;
    if ( !this->pPerspectiveData )
    {
      LODWORD(v6) = 322;
      v4 = (Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::DisplayObjectBase *, __int64, long double *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                                       Scaleform::Memory::pGlobalHeap,
                                                                       this,
                                                                       80i64,
                                                                       &v6,
                                                                       -2i64);
      v7 = v4;
      if ( v4 )
        Scaleform::GFx::DisplayObjectBase::PerspectiveDataType::PerspectiveDataType(v4);
      this->pPerspectiveData = v4;
    }
    pPerspectiveData = this->pPerspectiveData;
    if ( v2 != pPerspectiveData->FocalLength )
    {
      pPerspectiveData->FocalLength = v2;
      Scaleform::GFx::DisplayObjectBase::UpdateViewAndPerspective(this);
    }
  }
}

// File Line: 438
// RVA: 0x8D8180
double __fastcall Scaleform::GFx::DisplayObjectBase::GetFocalLength(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *pPerspectiveData; // rax

  pPerspectiveData = this->pPerspectiveData;
  if ( pPerspectiveData )
    return pPerspectiveData->FocalLength;
  else
    return 0.0;
}

// File Line: 444
// RVA: 0x909E40
void __fastcall Scaleform::GFx::DisplayObjectBase::SetProjectionCenter(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Point<float> projCenter)
{
  float v4; // xmm2_4
  float v5; // xmm1_4
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v6; // rdi
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v7; // rax
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v8; // rax
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *pPerspectiveData; // rdx
  double x; // xmm0_8
  double y; // xmm0_8
  float v12; // xmm0_4
  double v13; // [rsp+68h] [rbp+10h] BYREF
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v14; // [rsp+70h] [rbp+18h]

  v4 = **(float **)&projCenter;
  v13 = **(float **)&projCenter;
  if ( (COERCE_UNSIGNED_INT64(v4) & 0x7FF0000000000000i64) != 0x7FF0000000000000i64
    || (COERCE_UNSIGNED_INT64(v4) & 0xFFFFFFFFFFFFFi64) == 0 )
  {
    v5 = *(float *)(*(_QWORD *)&projCenter + 4i64);
    v13 = v5;
    if ( (COERCE_UNSIGNED_INT64(v5) & 0x7FF0000000000000i64) != 0x7FF0000000000000i64
      || (COERCE_UNSIGNED_INT64(v5) & 0xFFFFFFFFFFFFFi64) == 0 )
    {
      v6 = 0i64;
      if ( COERCE__INT64(v4) == 0xFFF0000000000000ui64 || COERCE__INT64(v4) == 0x7FF0000000000000i64 )
        **(_DWORD **)&projCenter = 0;
      v13 = v5;
      if ( COERCE__INT64(v5) == 0xFFF0000000000000ui64 || (v13 = v5, COERCE__INT64(v5) == 0x7FF0000000000000i64) )
        *(_DWORD *)(*(_QWORD *)&projCenter + 4i64) = 0;
      if ( !this->pPerspectiveData )
      {
        LODWORD(v13) = 322;
        v7 = (Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::DisplayObjectBase *, __int64, double *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                                         Scaleform::Memory::pGlobalHeap,
                                                                         this,
                                                                         80i64,
                                                                         &v13,
                                                                         -2i64);
        v14 = v7;
        if ( v7 )
        {
          Scaleform::GFx::DisplayObjectBase::PerspectiveDataType::PerspectiveDataType(v7);
          v6 = v8;
        }
        this->pPerspectiveData = v6;
      }
      pPerspectiveData = this->pPerspectiveData;
      x = pPerspectiveData->ProjectionCenter.x;
      v13 = x;
      if ( (*(_QWORD *)&x & 0x7FF0000000000000i64) == 0x7FF0000000000000i64 && (*(_QWORD *)&x & 0xFFFFFFFFFFFFFi64) != 0
        || (y = pPerspectiveData->ProjectionCenter.y,
            v13 = y,
            (*(_QWORD *)&y & 0x7FF0000000000000i64) == 0x7FF0000000000000i64)
        && (*(_QWORD *)&y & 0xFFFFFFFFFFFFFi64) != 0
        || **(float **)&projCenter != pPerspectiveData->ProjectionCenter.x
        || *(float *)(*(_QWORD *)&projCenter + 4i64) != pPerspectiveData->ProjectionCenter.y )
      {
        v12 = *(float *)(*(_QWORD *)&projCenter + 4i64);
        pPerspectiveData->ProjectionCenter.x = **(float **)&projCenter;
        pPerspectiveData->ProjectionCenter.y = v12;
        Scaleform::GFx::DisplayObjectBase::UpdateViewAndPerspective(this);
      }
    }
  }
}

// File Line: 466
// RVA: 0x8DC410
Scaleform::Render::Point<float> *__fastcall Scaleform::GFx::DisplayObjectBase::GetProjectionCenter(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Point<float> *result)
{
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *pPerspectiveData; // rax
  Scaleform::Render::Point<float> ProjectionCenter; // [rsp+8h] [rbp+8h]

  pPerspectiveData = this->pPerspectiveData;
  if ( pPerspectiveData )
    ProjectionCenter = pPerspectiveData->ProjectionCenter;
  else
    ProjectionCenter = 0i64;
  *result = ProjectionCenter;
  return result;
}

// File Line: 471
// RVA: 0x8D6740
Scaleform::Render::Cxform *__fastcall Scaleform::GFx::DisplayObjectBase::GetCxform(
        Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode *pObject; // rdx
  unsigned __int64 v2; // r8
  unsigned __int64 v3; // rdx

  pObject = this->pRenNode.pObject;
  if ( !pObject )
    return &Scaleform::Render::Cxform::Identity;
  v2 = (unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64;
  v3 = (__int64)((unsigned __int128)((__int64)((__int64)&pObject[-1]
                                             - ((unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64))
                                   * (__int128)0x4924924924924925i64) >> 64) >> 4;
  return (Scaleform::Render::Cxform *)(*(_QWORD *)(*(_QWORD *)(v2 + 32) + 8 * ((unsigned int)v3 + (v3 >> 63)) + 40)
                                     + 80i64);
}

// File Line: 478
// RVA: 0x906C20
void __fastcall Scaleform::GFx::DisplayObjectBase::SetCxform(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Cxform *cx)
{
  Scaleform::Render::TreeNode *RenderNode; // rax
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax

  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(RenderNode, 2u);
  WritableData[5] = *(Scaleform::Render::ContextImpl::EntryData *)&cx->M[0][0];
  WritableData[6] = *(Scaleform::Render::ContextImpl::EntryData *)&cx->M[1][0];
}

// File Line: 506
// RVA: 0x906710
void __fastcall Scaleform::GFx::DisplayObjectBase::SetBlendMode(Scaleform::GFx::DisplayObjectBase *this, __int32 blend)
{
  Scaleform::Render::BlendMode v2; // ebx
  char v3; // si
  Scaleform::Render::TreeNode *RenderNode; // rax

  v2 = blend;
  v3 = blend;
  if ( blend == 1 )
    v2 = Blend_None;
  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeNode::SetBlendMode(RenderNode, v2);
  this->BlendMode = v3;
}

// File Line: 515
// RVA: 0x8D4DD0
Scaleform::Render::State *__fastcall Scaleform::GFx::DisplayObjectBase::GetBlendMode(
        Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode *RenderNode; // rax
  Scaleform::Render::State *result; // rax

  if ( !Scaleform::GFx::DisplayObjectBase::GetRenderNode(this) )
    return (Scaleform::Render::State *)(unsigned __int8)this->BlendMode;
  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  result = Scaleform::Render::TreeNode::GetState(RenderNode, State_BlendMode);
  if ( result )
    return (Scaleform::Render::State *)LODWORD(result->DataValue);
  return result;
}

// File Line: 522
// RVA: 0x8D59C0
bool __fastcall Scaleform::GFx::DisplayObjectBase::GetCacheAsBitmap(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode *RenderNode; // rax
  Expression::IMemberMap *State; // rax
  Scaleform::Render::FilterSet *Log; // rax
  bool result; // al

  result = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this)
        && (RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this),
            (State = (Expression::IMemberMap *)Scaleform::Render::TreeNode::GetState(RenderNode, State_Filter)) != 0i64)
        && (Log = (Scaleform::Render::FilterSet *)Scaleform::GFx::Stream::GetLog(State)) != 0i64
        && Scaleform::Render::FilterSet::GetCacheAsBitmap(Log);
  return result;
}

// File Line: 534
// RVA: 0x906830
void __fastcall Scaleform::GFx::DisplayObjectBase::SetCacheAsBitmap(
        Scaleform::GFx::DisplayObjectBase *this,
        bool enable)
{
  Scaleform::Render::TreeNode *RenderNode; // rax
  Expression::IMemberMap *State; // rax
  Scaleform::Render::FilterSet *Log; // rax
  Scaleform::Render::FilterSet *v7; // rsi
  Scaleform::Render::FilterSet *v8; // rsi
  Scaleform::Render::RenderBuffer *v9; // rcx
  Scaleform::Render::FilterSet *v10; // rax
  Scaleform::Render::FilterSet *v11; // rax
  Scaleform::Render::FilterSet *v12; // rbx

  if ( Scaleform::GFx::DisplayObjectBase::GetRenderNode(this) )
  {
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    State = (Expression::IMemberMap *)Scaleform::Render::TreeNode::GetState(RenderNode, State_Filter);
    if ( State && (Log = (Scaleform::Render::FilterSet *)Scaleform::GFx::Stream::GetLog(State), (v7 = Log) != 0i64) )
    {
      if ( enable != Scaleform::Render::FilterSet::GetCacheAsBitmap(Log) )
      {
        v8 = Scaleform::Render::FilterSet::Clone(v7, 0, 0i64);
        Scaleform::Render::FilterSet::SetCacheAsBitmap(v8, enable);
        this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[56].__vecDelDtor(
          this,
          (unsigned int)v8);
        if ( v8 )
        {
          v9 = (Scaleform::Render::RenderBuffer *)v8;
LABEL_13:
          Scaleform::RefCountImpl::Release(v9);
        }
      }
    }
    else if ( enable )
    {
      v10 = (Scaleform::Render::FilterSet *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
                                              Scaleform::Memory::pGlobalHeap,
                                              56i64);
      if ( v10 )
      {
        Scaleform::Render::FilterSet::FilterSet(v10, 0i64);
        v12 = v11;
      }
      else
      {
        v12 = 0i64;
      }
      Scaleform::Render::FilterSet::SetCacheAsBitmap(v12, 1);
      this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[56].__vecDelDtor(
        this,
        (unsigned int)v12);
      if ( v12 )
      {
        v9 = (Scaleform::Render::RenderBuffer *)v12;
        goto LABEL_13;
      }
    }
  }
}

// File Line: 554
// RVA: 0x907140
void __fastcall Scaleform::GFx::DisplayObjectBase::SetFilters(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::FilterSet *filters)
{
  Scaleform::Render::TreeNode *RenderNode; // rax

  if ( Scaleform::GFx::DisplayObjectBase::GetRenderNode(this) )
  {
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::TreeNode::SetFilters(RenderNode, filters);
  }
}

// File Line: 564
// RVA: 0x8D7D20
Expression::IMemberMap *__fastcall Scaleform::GFx::DisplayObjectBase::GetFilters(
        Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode *RenderNode; // rax
  Expression::IMemberMap *State; // rax

  if ( Scaleform::GFx::DisplayObjectBase::GetRenderNode(this)
    && (RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this),
        (State = (Expression::IMemberMap *)Scaleform::Render::TreeNode::GetState(RenderNode, State_Filter)) != 0i64) )
  {
    return Scaleform::GFx::Stream::GetLog(State);
  }
  else
  {
    return 0i64;
  }
}

// File Line: 573
// RVA: 0x90F260
void __fastcall Scaleform::GFx::DisplayObjectBase::SetVisibleFlag(Scaleform::GFx::DisplayObjectBase *this, bool v)
{
  Scaleform::Render::TreeNode *pObject; // rcx
  Scaleform::Render::TreeNode *RenderNode; // rax

  if ( v )
  {
    this->Flags |= 0x4000u;
    pObject = this->pRenNode.pObject;
    if ( pObject )
      Scaleform::Render::TreeNode::SetVisible(pObject, v);
  }
  else
  {
    this->Flags &= ~0x4000u;
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::TreeNode::SetVisible(RenderNode, 0);
  }
}

// File Line: 588
// RVA: 0x8B70B0
void __fastcall Scaleform::GFx::DisplayObjectBase::BindAvmObj(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::GFx::AvmDisplayObjBase *p)
{
  this->AvmObjOffset = (unsigned __int64)((char *)p - (char *)this + 3) >> 2;
}

// File Line: 599
// RVA: 0x8E1AC0
void __fastcall Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Matrix2x4<float> *pmat)
{
  Scaleform::GFx::InteractiveObject *pParent; // rcx
  Scaleform::Render::Matrix2x4<float> *v5; // rax
  float *v6; // rax

  pParent = this->pParent;
  if ( pParent )
  {
    Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(pParent, pmat);
    v5 = (Scaleform::Render::Matrix2x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
    Scaleform::Render::Matrix2x4<float>::Prepend(pmat, v5);
  }
  else
  {
    v6 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
    pmat->M[0][0] = *v6;
    pmat->M[0][1] = v6[1];
    pmat->M[0][2] = v6[2];
    pmat->M[0][3] = v6[3];
    pmat->M[1][0] = v6[4];
    pmat->M[1][1] = v6[5];
    pmat->M[1][2] = v6[6];
    pmat->M[1][3] = v6[7];
  }
}

// File Line: 612
// RVA: 0x8E1A20
void __fastcall Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Matrix3x4<float> *pmat)
{
  Scaleform::GFx::InteractiveObject *pParent; // rcx
  Scaleform::Render::Matrix3x4<float> *v5; // rax
  float *v6; // rax

  pParent = this->pParent;
  if ( pParent )
  {
    Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D(pParent, pmat);
    v5 = (Scaleform::Render::Matrix3x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[4].__vecDelDtor)(this);
    Scaleform::Render::Matrix3x4<float>::Prepend(pmat, v5);
  }
  else
  {
    v6 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[4].__vecDelDtor)(this);
    pmat->M[0][0] = *v6;
    pmat->M[0][1] = v6[1];
    pmat->M[0][2] = v6[2];
    pmat->M[0][3] = v6[3];
    pmat->M[1][0] = v6[4];
    pmat->M[1][1] = v6[5];
    pmat->M[1][2] = v6[6];
    pmat->M[1][3] = v6[7];
    pmat->M[2][0] = v6[8];
    pmat->M[2][1] = v6[9];
    pmat->M[2][2] = v6[10];
    pmat->M[2][3] = v6[11];
  }
}

// File Line: 625
// RVA: 0x8BB5E0
void __fastcall Scaleform::GFx::DisplayObjectBase::Clear3D(Scaleform::GFx::DisplayObjectBase *this, bool bInherit)
{
  Scaleform::GFx::InteractiveObject *pParent; // rcx
  Scaleform::Render::TreeNode *pObject; // rcx
  Scaleform::GFx::DisplayObjectBase::GeomDataType gd; // [rsp+20h] [rbp-68h] BYREF

  if ( bInherit )
  {
    pParent = this->pParent;
    if ( pParent )
      Scaleform::GFx::DisplayObjectBase::Clear3D(pParent, bInherit);
  }
  *(_QWORD *)&gd.X = 0i64;
  *(_OWORD *)&gd.OrigMatrix.M[0][0] = _xmm;
  *(__m128 *)&gd.OrigMatrix.M[1][0] = _xmm;
  gd.YScale = DOUBLE_100_0;
  gd.XScale = DOUBLE_100_0;
  gd.Rotation = 0.0;
  *(_OWORD *)&gd.XRotation = 0i64;
  *(_OWORD *)&gd.Z = _xmm;
  Scaleform::GFx::DisplayObjectBase::SetGeomData(this, &gd);
  pObject = this->pRenNode.pObject;
  if ( pObject )
    Scaleform::Render::TreeNode::Clear3D(pObject);
  ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[12].__vecDelDtor)(this);
}

// File Line: 641
// RVA: 0x8E6E00
bool __fastcall Scaleform::GFx::DisplayObjectBase::Is3D(Scaleform::GFx::DisplayObjectBase *this, bool bInherit)
{
  Scaleform::Render::TreeNode *pObject; // r9
  bool result; // al

  do
  {
    pObject = this->pRenNode.pObject;
    result = pObject
          && (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                   + 8i64
                                   * (unsigned int)((int)((_DWORD)pObject - ((unsigned int)pObject & 0xFFFFF000) - 56)
                                                  / 56)
                                   + 40)
                       + 10i64) & 0x200) != 0;
    if ( !bInherit )
      break;
    if ( result )
      return 1;
    this = this->pParent;
  }
  while ( this );
  return result;
}

// File Line: 657
// RVA: 0x8DAB70
void __fastcall Scaleform::GFx::DisplayObjectBase::GetLevelMatrix(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Matrix2x4<float> *pmat)
{
  Scaleform::GFx::InteractiveObject *pParent; // rcx
  Scaleform::Render::Matrix2x4<float> *v5; // rax

  pParent = this->pParent;
  if ( pParent )
  {
    Scaleform::GFx::DisplayObjectBase::GetLevelMatrix(pParent, pmat);
    v5 = (Scaleform::Render::Matrix2x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
    Scaleform::Render::Matrix2x4<float>::Prepend(pmat, v5);
  }
  else
  {
    *(_OWORD *)&pmat->M[0][0] = 0x3F800000ui64;
    pmat->M[1][0] = 0.0;
    pmat->M[1][3] = 0.0;
    *(_QWORD *)&pmat->M[1][1] = 1065353216i64;
  }
}

// File Line: 686
// RVA: 0x8E8BF0
Scaleform::Render::Point<float> *__fastcall Scaleform::GFx::DisplayObjectBase::Local3DToGlobal(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Point<float> *result,
        Scaleform::Render::Point3<float> *ptIn)
{
  Scaleform::Render::TreeNode *pObject; // rcx
  Scaleform::GFx::InteractiveObject *v7; // rdi
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // rax
  __int64 v9; // r8
  Scaleform::RefCountNTSImplCoreVtbl *v10; // rax
  __int64 v11; // r8
  Scaleform::GFx::InteractiveObject *pParent; // rcx
  Scaleform::Render::Matrix3x4<float> *v13; // rax
  Scaleform::GFx::ASMovieRootBase *pASRoot; // rax
  float *pMovieImpl; // rdi
  float y; // xmm4_4
  float x; // xmm3_4
  float z; // xmm5_4
  float v19; // xmm0_4
  float v20; // xmm7_4
  float v21; // xmm6_4
  Scaleform::GFx::ASMovieRootBase *v22; // rax
  float v23; // xmm7_4
  float v24; // xmm8_4
  float v25; // xmm9_4
  float v26; // xmm10_4
  float *v27; // rax
  float v28; // xmm1_4
  float v29; // xmm2_4
  float v30; // xmm3_4
  float v31; // xmm5_4
  float v32; // xmm4_4
  float v33; // xmm6_4
  float v34; // xmm7_4
  float v35; // xmm8_4
  float v36; // xmm5_4
  float v37; // xmm6_4
  float v38; // xmm1_4
  float v39; // xmm0_4
  float *v40; // rax
  Scaleform::Render::Matrix3x4<float> pmat; // [rsp+20h] [rbp-D8h] BYREF
  __int64 v43[2]; // [rsp+50h] [rbp-A8h] BYREF
  int v44; // [rsp+60h] [rbp-98h]
  int v45; // [rsp+64h] [rbp-94h]
  __int64 v46; // [rsp+68h] [rbp-90h]
  __int64 v47; // [rsp+70h] [rbp-88h]
  int v48; // [rsp+78h] [rbp-80h]
  int v49; // [rsp+7Ch] [rbp-7Ch]
  Scaleform::Render::Matrix4x4<float> m1; // [rsp+88h] [rbp-70h] BYREF
  Scaleform::Render::Matrix4x4<float> v51; // [rsp+C8h] [rbp-30h] BYREF
  Scaleform::Render::Matrix3x4<float> Dst; // [rsp+108h] [rbp+10h] BYREF
  Scaleform::Render::Matrix4x4<float> v53; // [rsp+138h] [rbp+40h] BYREF

  pObject = this->pRenNode.pObject;
  if ( pObject
    && (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64
                             * (unsigned int)((int)((_DWORD)pObject - ((unsigned int)pObject & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 10i64) & 0x200) != 0
    || (v7 = this->pParent) != 0i64 && Scaleform::GFx::DisplayObjectBase::Is3D(this->pParent, 1) )
  {
    memset(&Dst, 0, sizeof(Dst));
    vfptr = this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
    LOBYTE(v9) = 1;
    Dst.M[0][0] = 1.0;
    Dst.M[1][1] = 1.0;
    Dst.M[2][2] = 1.0;
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Matrix3x4<float> *, __int64))vfptr[9].__vecDelDtor)(
      this,
      &Dst,
      v9);
    memset(&v53, 0, sizeof(v53));
    v10 = this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
    LOBYTE(v11) = 1;
    v53.M[0][0] = 1.0;
    v53.M[1][1] = 1.0;
    v53.M[2][2] = 1.0;
    v53.M[3][3] = 1.0;
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Matrix4x4<float> *, __int64))v10[6].__vecDelDtor)(
      this,
      &v53,
      v11);
    memset(&pmat, 0, sizeof(pmat));
    pParent = this->pParent;
    pmat.M[0][0] = 1.0;
    pmat.M[1][1] = 1.0;
    pmat.M[2][2] = 1.0;
    if ( pParent )
    {
      Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D(pParent, &pmat);
      v13 = (Scaleform::Render::Matrix3x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[4].__vecDelDtor)(this);
      *(_OWORD *)&m1.M[0][0] = *(_OWORD *)&pmat.M[0][0];
      *(_OWORD *)&m1.M[1][0] = *(_OWORD *)&pmat.M[1][0];
      *(_OWORD *)&m1.M[2][0] = *(_OWORD *)&pmat.M[2][0];
      Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&pmat, (Scaleform::Render::Matrix3x4<float> *)&m1, v13);
    }
    else
    {
      pmat = *(Scaleform::Render::Matrix3x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[4].__vecDelDtor)(this);
    }
    Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(&m1, &v53, &Dst);
    Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(&v51, &m1, &pmat);
    pASRoot = this->pASRoot;
    pMovieImpl = 0i64;
    y = ptIn->y;
    x = ptIn->x;
    z = ptIn->z;
    v43[0] = 0i64;
    v43[1] = 0i64;
    v45 = 1;
    v44 = 1;
    v47 = 0i64;
    v46 = 0i64;
    v48 = 1065353216;
    v49 = 1065353216;
    v19 = 1.0
        / (float)((float)((float)((float)(v51.M[3][0] * x) + (float)(v51.M[3][1] * y)) + (float)(v51.M[3][2] * z))
                + v51.M[3][3]);
    v20 = (float)((float)((float)((float)(v51.M[0][0] * x) + (float)(v51.M[0][1] * y)) + (float)(v51.M[0][2] * z))
                + v51.M[0][3])
        * v19;
    v21 = (float)((float)((float)((float)(v51.M[1][0] * x) + (float)(v51.M[1][1] * y)) + (float)(v51.M[1][2] * z))
                + v51.M[1][3])
        * v19;
    pASRoot->pMovieImpl->vfptr[13].__vecDelDtor(pASRoot->pMovieImpl, (unsigned int)v43);
    v22 = this->pASRoot;
    v23 = (float)((float)(v20 + 1.0) * (float)v44) * 0.5;
    v24 = (float)((float)(1.0 - v21) * (float)v45) * 0.5;
    if ( v22 )
      pMovieImpl = (float *)v22->pMovieImpl;
    if ( pMovieImpl )
    {
      v23 = (float)((float)(v23 * pMovieImpl[54]) + pMovieImpl[56]) * 20.0;
      v24 = (float)((float)(v24 * pMovieImpl[55]) + pMovieImpl[57]) * 20.0;
    }
    result->x = v23;
    result->y = v24;
  }
  else
  {
    v25 = ptIn->x;
    *(_OWORD *)&pmat.M[0][0] = _xmm;
    *(__m128 *)&pmat.M[1][0] = _xmm;
    v26 = ptIn->y;
    if ( v7 )
    {
      Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v7, (Scaleform::Render::Matrix2x4<float> *)&pmat);
      v27 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
      v28 = pmat.M[0][0];
      v29 = pmat.M[0][1];
      v30 = pmat.M[1][0];
      v31 = pmat.M[0][0];
      v32 = pmat.M[1][1];
      v33 = pmat.M[1][0];
      v34 = (float)(pmat.M[0][0] * *v27) + (float)(pmat.M[0][1] * v27[4]);
      pmat.M[0][0] = v34;
      v35 = (float)(pmat.M[1][0] * *v27) + (float)(pmat.M[1][1] * v27[4]);
      pmat.M[1][0] = v35;
      v36 = (float)(v31 * v27[1]) + (float)(pmat.M[0][1] * v27[5]);
      *(_QWORD *)&pmat.M[0][1] = LODWORD(v36);
      v37 = (float)(v33 * v27[1]) + (float)(pmat.M[1][1] * v27[5]);
      *(_QWORD *)&pmat.M[1][1] = LODWORD(v37);
      v38 = pmat.M[0][3] + (float)((float)(v29 * v27[7]) + (float)(v28 * v27[3]));
      pmat.M[0][3] = v38;
      v39 = pmat.M[1][3] + (float)((float)(v32 * v27[7]) + (float)(v30 * v27[3]));
    }
    else
    {
      v40 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
      v34 = *v40;
      pmat.M[0][0] = *v40;
      v36 = v40[1];
      *(_QWORD *)&pmat.M[0][1] = *(_QWORD *)(v40 + 1);
      v38 = v40[3];
      pmat.M[0][3] = v38;
      v35 = v40[4];
      pmat.M[1][0] = v35;
      v37 = v40[5];
      *(_QWORD *)&pmat.M[1][1] = *(_QWORD *)(v40 + 5);
      v39 = v40[7];
    }
    result->x = (float)((float)(v36 * v26) + (float)(v34 * v25)) + v38;
    result->y = (float)((float)(v37 * v26) + (float)(v35 * v25)) + v39;
  }
  return result;
}

// File Line: 727
// RVA: 0x8E20C0
Scaleform::Render::Point<float> *__fastcall Scaleform::GFx::DisplayObjectBase::GlobalToLocal(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Point<float> *result,
        Scaleform::Render::Point<float> *ptIn)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // r9
  float ViewOffsetX; // xmm4_4
  float v6; // xmm6_4
  float v7; // xmm0_4

  pMovieImpl = this->pASRoot->pMovieImpl;
  if ( pMovieImpl )
  {
    ViewOffsetX = pMovieImpl->ViewOffsetX;
    v6 = (float)(ptIn->x - ViewOffsetX) / pMovieImpl->ViewScaleX;
    v7 = pMovieImpl->VisibleFrameRect.x2 - pMovieImpl->VisibleFrameRect.x1;
    LODWORD(pMovieImpl->ScreenToWorld.Sy) = COERCE_UNSIGNED_INT(
                                              (float)((float)((float)((float)((float)(ptIn->y - pMovieImpl->ViewOffsetY)
                                                                            / pMovieImpl->ViewScaleY)
                                                                    - (float)(pMovieImpl->ViewOffsetY * 20.0))
                                                            / (float)(pMovieImpl->VisibleFrameRect.y2
                                                                    - pMovieImpl->VisibleFrameRect.y1))
                                                    * 2.0)
                                            - 1.0) ^ _xmm[0];
    pMovieImpl->ScreenToWorld.Sx = (float)((float)((float)(v6 - (float)(ViewOffsetX * 20.0)) / v7) * 2.0) - 1.0;
    Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(this, result, ptIn, 0, 0i64);
  }
  return result;
}

// File Line: 746
// RVA: 0x8E2080
Scaleform::Render::Point3<float> *__fastcall Scaleform::GFx::DisplayObjectBase::GlobalToLocal3D(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Point3<float> *result,
        Scaleform::Render::Point<float> *ptIn)
{
  Scaleform::Render::Point3<float> *v4; // rax
  float y; // xmm1_4
  Scaleform::Render::Point<float> resulta; // [rsp+38h] [rbp+10h] BYREF

  Scaleform::GFx::DisplayObjectBase::GlobalToLocal(this, &resulta, ptIn);
  result->z = 0.0;
  v4 = result;
  y = resulta.y;
  result->x = resulta.x;
  result->y = y;
  return v4;
}

// File Line: 754
// RVA: 0x9134A0
void __fastcall Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Point<float> *p,
        Scaleform::Render::Point<float> *pt,
        bool bPtInParentSpace,
        Scaleform::Render::Matrix2x4<float> *mat)
{
  Scaleform::Render::TreeNode *pObject; // rcx
  Scaleform::Render::Point<float> *v7; // r14
  Scaleform::Render::Matrix2x4<float> *p_pmat; // rcx
  Scaleform::GFx::InteractiveObject *pParent; // rbx
  Scaleform::GFx::InteractiveObject *v11; // rcx
  Scaleform::Render::Matrix3x4<float> *v12; // rax
  __int64 v13; // r8
  Scaleform::Render::ScreenToWorld *p_ScreenToWorld; // rbx
  __int64 v15; // r8
  float *v16; // rax
  float v17; // xmm6_4
  float v18; // xmm3_4
  float v19; // xmm4_4
  float v20; // xmm5_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  _OWORD *v23; // rax
  Scaleform::Render::Matrix3x4<float> pmat; // [rsp+20h] [rbp-91h] BYREF
  int Dst[12]; // [rsp+50h] [rbp-61h] BYREF
  int v26[16]; // [rsp+80h] [rbp-31h] BYREF
  Scaleform::Render::Matrix3x4<float> m1; // [rsp+C0h] [rbp+Fh] BYREF

  pObject = this->pRenNode.pObject;
  v7 = pt;
  if ( bPtInParentSpace )
  {
    if ( !pObject
      || (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                               + 8i64
                               * (unsigned int)((int)((_DWORD)pObject - ((unsigned int)pObject & 0xFFFFF000) - 56) / 56)
                               + 40)
                   + 10i64) & 0x200) == 0 )
    {
      p_pmat = mat;
      if ( mat )
      {
LABEL_23:
        Scaleform::Render::Matrix2x4<float>::TransformByInverse(p_pmat, p, pt);
        return;
      }
      p_pmat = (Scaleform::Render::Matrix2x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
LABEL_22:
      pt = v7;
      goto LABEL_23;
    }
  }
  else if ( !pObject
         || (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                  + 8i64
                                  * (unsigned int)((int)((_DWORD)pObject - ((unsigned int)pObject & 0xFFFFF000) - 56)
                                                 / 56)
                                  + 40)
                      + 10i64) & 0x200) == 0 )
  {
    pParent = this->pParent;
    if ( !pParent || !Scaleform::GFx::DisplayObjectBase::Is3D(this->pParent, 1) )
    {
      *(_OWORD *)&pmat.M[0][0] = _xmm;
      *(__m128 *)&pmat.M[1][0] = _xmm;
      if ( pParent )
      {
        Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(pParent, (Scaleform::Render::Matrix2x4<float> *)&pmat);
        v16 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
        v17 = pmat.M[1][0];
        v18 = pmat.M[0][0];
        v19 = pmat.M[0][1];
        v20 = pmat.M[1][1];
        pmat.M[0][0] = (float)(pmat.M[0][0] * *v16) + (float)(pmat.M[0][1] * v16[4]);
        pmat.M[1][0] = (float)(pmat.M[1][0] * *v16) + (float)(pmat.M[1][1] * v16[4]);
        pmat.M[0][1] = (float)(v18 * v16[1]) + (float)(pmat.M[0][1] * v16[5]);
        v21 = pmat.M[1][1] * v16[5];
        v22 = v17 * v16[1];
        pmat.M[0][2] = 0.0;
        *(_QWORD *)&pmat.M[1][1] = COERCE_UNSIGNED_INT(v22 + v21);
        pmat.M[0][3] = pmat.M[0][3] + (float)((float)(v19 * v16[7]) + (float)(v18 * v16[3]));
        pmat.M[1][3] = pmat.M[1][3] + (float)((float)(v17 * v16[3]) + (float)(v20 * v16[7]));
      }
      else
      {
        v23 = (_OWORD *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
        *(_OWORD *)&pmat.M[0][0] = *v23;
        *(_OWORD *)&pmat.M[1][0] = v23[1];
      }
      p_pmat = (Scaleform::Render::Matrix2x4<float> *)&pmat;
      goto LABEL_22;
    }
  }
  memset(Dst, 0, sizeof(Dst));
  Dst[0] = 1065353216;
  Dst[5] = 1065353216;
  Dst[10] = 1065353216;
  memset(v26, 0, sizeof(v26));
  v26[0] = 1065353216;
  v26[5] = 1065353216;
  v26[10] = 1065353216;
  v26[15] = 1065353216;
  memset(&pmat, 0, sizeof(pmat));
  v11 = this->pParent;
  pmat.M[0][0] = 1.0;
  pmat.M[1][1] = 1.0;
  pmat.M[2][2] = 1.0;
  if ( v11 )
  {
    Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D(v11, &pmat);
    v12 = (Scaleform::Render::Matrix3x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[4].__vecDelDtor)(this);
    m1 = pmat;
    Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&pmat, &m1, v12);
  }
  else
  {
    pmat = *(Scaleform::Render::Matrix3x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[4].__vecDelDtor)(this);
  }
  LOBYTE(v13) = 1;
  p_ScreenToWorld = &this->pASRoot->pMovieImpl->ScreenToWorld;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, int *, __int64))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[6].__vecDelDtor)(
         this,
         v26,
         v13) )
  {
    LODWORD(p_ScreenToWorld->MatProj.M[0][0]) = v26[0];
    LODWORD(p_ScreenToWorld->MatProj.M[0][1]) = v26[1];
    LODWORD(p_ScreenToWorld->MatProj.M[0][2]) = v26[2];
    LODWORD(p_ScreenToWorld->MatProj.M[0][3]) = v26[3];
    LODWORD(p_ScreenToWorld->MatProj.M[1][0]) = v26[4];
    LODWORD(p_ScreenToWorld->MatProj.M[1][1]) = v26[5];
    LODWORD(p_ScreenToWorld->MatProj.M[1][2]) = v26[6];
    LODWORD(p_ScreenToWorld->MatProj.M[1][3]) = v26[7];
    LODWORD(p_ScreenToWorld->MatProj.M[2][0]) = v26[8];
    LODWORD(p_ScreenToWorld->MatProj.M[2][1]) = v26[9];
    LODWORD(p_ScreenToWorld->MatProj.M[2][2]) = v26[10];
    LODWORD(p_ScreenToWorld->MatProj.M[2][3]) = v26[11];
    LODWORD(p_ScreenToWorld->MatProj.M[3][0]) = v26[12];
    LODWORD(p_ScreenToWorld->MatProj.M[3][1]) = v26[13];
    LODWORD(p_ScreenToWorld->MatProj.M[3][2]) = v26[14];
    LODWORD(p_ScreenToWorld->MatProj.M[3][3]) = v26[15];
  }
  LOBYTE(v15) = 1;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, int *, __int64))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[9].__vecDelDtor)(
         this,
         Dst,
         v15) )
  {
    LODWORD(p_ScreenToWorld->MatView.M[0][0]) = Dst[0];
    LODWORD(p_ScreenToWorld->MatView.M[0][1]) = Dst[1];
    LODWORD(p_ScreenToWorld->MatView.M[0][2]) = Dst[2];
    LODWORD(p_ScreenToWorld->MatView.M[0][3]) = Dst[3];
    LODWORD(p_ScreenToWorld->MatView.M[1][0]) = Dst[4];
    LODWORD(p_ScreenToWorld->MatView.M[1][1]) = Dst[5];
    LODWORD(p_ScreenToWorld->MatView.M[1][2]) = Dst[6];
    LODWORD(p_ScreenToWorld->MatView.M[1][3]) = Dst[7];
    LODWORD(p_ScreenToWorld->MatView.M[2][0]) = Dst[8];
    LODWORD(p_ScreenToWorld->MatView.M[2][1]) = Dst[9];
    LODWORD(p_ScreenToWorld->MatView.M[2][2]) = Dst[10];
    LODWORD(p_ScreenToWorld->MatView.M[2][3]) = Dst[11];
  }
  p_ScreenToWorld->MatWorld = pmat;
  Scaleform::Render::ScreenToWorld::GetWorldPoint(p_ScreenToWorld, p);
}

// File Line: 811
// RVA: 0x8E1530
__int64 __fastcall Scaleform::GFx::DisplayObjectBase::GetVersion(Scaleform::GFx::DisplayObjectBase *this)
{
  __int64 v1; // rax

  v1 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[66].__vecDelDtor)(this);
  return (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)v1 + 32i64))(v1);
}

// File Line: 817
// RVA: 0x8DAC50
Scaleform::Log *__fastcall Scaleform::GFx::DisplayObjectBase::GetLog(Scaleform::GFx::DisplayObjectBase *this)
{
  if ( !this )
    return Scaleform::GFx::MovieImpl::GetCachedLog(0i64);
  while ( SLOBYTE(this->Flags) >= 0 )
  {
    this = this->pParent;
    if ( !this )
      return Scaleform::GFx::MovieImpl::GetCachedLog(0i64);
  }
  return Scaleform::GFx::MovieImpl::GetCachedLog(this->pASRoot->pMovieImpl);
}

// File Line: 823
// RVA: 0x8E7D90
__int64 __fastcall Scaleform::GFx::DisplayObjectBase::IsVerboseAction(Scaleform::GFx::DisplayObjectBase *this)
{
  if ( !this )
    return (MEMORY[0x52D0] >> 2) & 1;
  while ( SLOBYTE(this->Flags) >= 0 )
  {
    this = this->pParent;
    if ( !this )
      return (MEMORY[0x52D0] >> 2) & 1;
  }
  return (this->pASRoot->pMovieImpl->Flags >> 2) & 1;
}

// File Line: 828
// RVA: 0x8E7DD0
_BOOL8 __fastcall Scaleform::GFx::DisplayObjectBase::IsVerboseActionErrors(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType **p_pPerspectiveData; // rax

  p_pPerspectiveData = &this[-1].pPerspectiveData;
  if ( this == (Scaleform::GFx::DisplayObjectBase *)24 )
    return (MEMORY[0x52D0] & 0x40) == 0;
  while ( *((char *)p_pPerspectiveData + 106) >= 0 )
  {
    p_pPerspectiveData = (Scaleform::GFx::DisplayObjectBase::PerspectiveDataType **)p_pPerspectiveData[7];
    if ( !p_pPerspectiveData )
      return (MEMORY[0x52D0] & 0x40) == 0;
  }
  return (*(_DWORD *)(*(_QWORD *)&p_pPerspectiveData[4]->ProjectionCenter + 21200i64) & 0x40) == 0;
}

// File Line: 833
// RVA: 0x8EC940
void __fastcall Scaleform::GFx::DisplayObjectBase::OnEventUnload(Scaleform::GFx::DisplayObjectBase *this)
{
  unsigned __int16 v2; // ax
  Scaleform::GFx::DisplayObjectBase *pParent; // rdx
  Scaleform::GFx::MovieImpl *pMovieImpl; // rcx
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // rax
  __int64 v6; // [rsp+20h] [rbp-28h] BYREF
  int v7; // [rsp+28h] [rbp-20h]
  char v8; // [rsp+2Ch] [rbp-1Ch]
  int v9; // [rsp+30h] [rbp-18h]

  v2 = this->Flags | 0x1000;
  this->Flags = v2;
  if ( (v2 & 2) != 0 )
  {
    pParent = this;
    while ( SLOBYTE(pParent->Flags) >= 0 )
    {
      pParent = pParent->pParent;
      if ( !pParent )
      {
        pMovieImpl = 0i64;
        goto LABEL_7;
      }
    }
    pMovieImpl = pParent->pASRoot->pMovieImpl;
LABEL_7:
    Scaleform::GFx::MovieImpl::RemoveTopmostLevelCharacter(pMovieImpl, this);
  }
  if ( (this->Flags & 0x10) == 0 )
  {
    vfptr = this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
    v6 = 4i64;
    v7 = 0;
    v8 = 0;
    v9 = 65280;
    vfptr[72].__vecDelDtor(this, (unsigned int)&v6);
    this->Flags |= 0x10u;
  }
}

// File Line: 868
// RVA: 0x8E6D40
void __fastcall Scaleform::GFx::DisplayObjectBase::InvalidateHitResult(Scaleform::GFx::DisplayObjectBase *this)
{
  this->Flags &= 0xFFF3u;
}

// File Line: 878
// RVA: 0x8D9200
Scaleform::GFx::DisplayObjectBase::GeomDataType *__fastcall Scaleform::GFx::DisplayObjectBase::GetGeomData(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::GFx::DisplayObjectBase::GeomDataType *geomData)
{
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // rdx
  float *v5; // rax
  __m128d v6; // xmm1
  __m128d v7; // xmm2
  float *v8; // rax

  pGeomData = this->pGeomData;
  if ( pGeomData )
  {
    geomData->X = pGeomData->X;
    geomData->Y = pGeomData->Y;
    geomData->XScale = pGeomData->XScale;
    geomData->YScale = pGeomData->YScale;
    geomData->Rotation = pGeomData->Rotation;
    geomData->OrigMatrix.M[0][0] = pGeomData->OrigMatrix.M[0][0];
    geomData->OrigMatrix.M[0][1] = pGeomData->OrigMatrix.M[0][1];
    geomData->OrigMatrix.M[0][2] = pGeomData->OrigMatrix.M[0][2];
    geomData->OrigMatrix.M[0][3] = pGeomData->OrigMatrix.M[0][3];
    geomData->OrigMatrix.M[1][0] = pGeomData->OrigMatrix.M[1][0];
    geomData->OrigMatrix.M[1][1] = pGeomData->OrigMatrix.M[1][1];
    geomData->OrigMatrix.M[1][2] = pGeomData->OrigMatrix.M[1][2];
    geomData->OrigMatrix.M[1][3] = pGeomData->OrigMatrix.M[1][3];
    geomData->Z = pGeomData->Z;
    geomData->ZScale = pGeomData->ZScale;
    geomData->XRotation = pGeomData->XRotation;
    geomData->YRotation = pGeomData->YRotation;
  }
  else
  {
    v5 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
    geomData->X = (int)v5[3];
    geomData->Y = (int)v5[7];
    v6 = _mm_cvtps_pd((__m128)*(unsigned int *)v5);
    v6.m128d_f64[0] = v6.m128d_f64[0] * v6.m128d_f64[0] + v5[4] * v5[4];
    geomData->XScale = _mm_sqrt_pd(v6).m128d_f64[0] * 100.0;
    v7 = _mm_cvtps_pd((__m128)*((unsigned int *)v5 + 1));
    v7.m128d_f64[0] = v7.m128d_f64[0] * v7.m128d_f64[0] + v5[5] * v5[5];
    geomData->YScale = _mm_sqrt_pd(v7).m128d_f64[0] * 100.0;
    geomData->Rotation = atan2(v5[4], *v5) * 180.0 * 0.3183098861837907;
    v8 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
    geomData->OrigMatrix.M[0][0] = *v8;
    geomData->OrigMatrix.M[0][1] = v8[1];
    geomData->OrigMatrix.M[0][2] = v8[2];
    geomData->OrigMatrix.M[0][3] = v8[3];
    geomData->OrigMatrix.M[1][0] = v8[4];
    geomData->OrigMatrix.M[1][1] = v8[5];
    geomData->OrigMatrix.M[1][2] = v8[6];
    geomData->OrigMatrix.M[1][3] = v8[7];
  }
  return geomData;
}

// File Line: 898
// RVA: 0x907650
void __fastcall Scaleform::GFx::DisplayObjectBase::SetGeomData(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::GFx::DisplayObjectBase::GeomDataType *gd)
{
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // rdx
  __int64 v5; // rax
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v6; // rdx
  int v7; // [rsp+50h] [rbp+18h] BYREF
  __int64 v8; // [rsp+58h] [rbp+20h]

  pGeomData = this->pGeomData;
  if ( pGeomData )
  {
    pGeomData->X = gd->X;
    pGeomData->Y = gd->Y;
    pGeomData->XScale = gd->XScale;
    pGeomData->YScale = gd->YScale;
    pGeomData->Rotation = gd->Rotation;
    pGeomData->OrigMatrix.M[0][0] = gd->OrigMatrix.M[0][0];
    pGeomData->OrigMatrix.M[0][1] = gd->OrigMatrix.M[0][1];
    pGeomData->OrigMatrix.M[0][2] = gd->OrigMatrix.M[0][2];
    pGeomData->OrigMatrix.M[0][3] = gd->OrigMatrix.M[0][3];
    pGeomData->OrigMatrix.M[1][0] = gd->OrigMatrix.M[1][0];
    pGeomData->OrigMatrix.M[1][1] = gd->OrigMatrix.M[1][1];
    pGeomData->OrigMatrix.M[1][2] = gd->OrigMatrix.M[1][2];
    pGeomData->OrigMatrix.M[1][3] = gd->OrigMatrix.M[1][3];
    pGeomData->Z = gd->Z;
    pGeomData->ZScale = gd->ZScale;
    pGeomData->XRotation = gd->XRotation;
    pGeomData->YRotation = gd->YRotation;
  }
  else
  {
    v7 = 322;
    v5 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::DisplayObjectBase *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
           Scaleform::Memory::pGlobalHeap,
           this,
           96i64,
           &v7,
           -2i64);
    v6 = (Scaleform::GFx::DisplayObjectBase::GeomDataType *)v5;
    v8 = v5;
    if ( v5 )
    {
      *(_DWORD *)v5 = gd->X;
      *(_DWORD *)(v5 + 4) = gd->Y;
      *(long double *)(v5 + 8) = gd->XScale;
      *(long double *)(v5 + 16) = gd->YScale;
      *(long double *)(v5 + 24) = gd->Rotation;
      *(float *)(v5 + 32) = gd->OrigMatrix.M[0][0];
      *(float *)(v5 + 36) = gd->OrigMatrix.M[0][1];
      *(float *)(v5 + 40) = gd->OrigMatrix.M[0][2];
      *(float *)(v5 + 44) = gd->OrigMatrix.M[0][3];
      *(float *)(v5 + 48) = gd->OrigMatrix.M[1][0];
      *(float *)(v5 + 52) = gd->OrigMatrix.M[1][1];
      *(float *)(v5 + 56) = gd->OrigMatrix.M[1][2];
      *(float *)(v5 + 60) = gd->OrigMatrix.M[1][3];
      *(long double *)(v5 + 64) = gd->Z;
      *(long double *)(v5 + 72) = gd->ZScale;
      *(long double *)(v5 + 80) = gd->XRotation;
      *(long double *)(v5 + 88) = gd->YRotation;
    }
    else
    {
      v6 = 0i64;
    }
    this->pGeomData = v6;
  }
}

// File Line: 906
// RVA: 0x8C88E0
void __fastcall Scaleform::GFx::DisplayObjectBase::EnsureGeomDataCreated(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v2; // rax
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [rsp+20h] [rbp-68h] BYREF

  if ( !this->pGeomData )
  {
    *(_QWORD *)&geomData.X = 0i64;
    *(_OWORD *)&geomData.OrigMatrix.M[0][0] = _xmm;
    *(__m128 *)&geomData.OrigMatrix.M[1][0] = _xmm;
    geomData.YScale = DOUBLE_100_0;
    geomData.XScale = DOUBLE_100_0;
    geomData.Rotation = 0.0;
    *(_OWORD *)&geomData.XRotation = 0i64;
    *(_OWORD *)&geomData.Z = _xmm;
    v2 = Scaleform::GFx::DisplayObjectBase::GetGeomData(this, &geomData);
    Scaleform::GFx::DisplayObjectBase::SetGeomData(this, v2);
  }
}

// File Line: 915
// RVA: 0x8AFF30
void __fastcall Scaleform::GFx::ASCharacter_MatrixScaleAndRotate2x2(
        Scaleform::Render::Matrix2x4<float> *m,
        float sx,
        float sy,
        float radians)
{
  float v7; // xmm9_4
  float v8; // xmm6_4
  float v9; // xmm4_4
  float v10; // xmm0_4
  float v11; // xmm3_4
  float v12; // xmm2_4
  float v13; // xmm1_4

  v7 = cosf(radians);
  v8 = sinf(radians);
  v9 = m->M[0][0] * v8;
  v10 = m->M[1][1];
  v11 = m->M[1][0] * v7;
  v12 = (float)(m->M[0][0] * v7) - (float)(m->M[1][0] * v8);
  v13 = m->M[0][1];
  m->M[1][1] = (float)((float)(v13 * v8) + (float)(v10 * v7)) * sy;
  m->M[0][1] = (float)((float)(v13 * v7) - (float)(v10 * v8)) * sy;
  m->M[0][0] = v12 * sx;
  m->M[1][0] = (float)(v9 + v11) * sx;
}

// File Line: 930
// RVA: 0x90F760
// local variable allocation has failed, the output may be wrong!
void __fastcall Scaleform::GFx::DisplayObjectBase::SetX(Scaleform::GFx::DisplayObjectBase *this, double x)
{
  __m128d v2; // xmm6
  int *v4; // rax
  int v5; // ecx
  float v6; // xmm2_4
  float v7; // [rsp+20h] [rbp-38h] BYREF
  float v8; // [rsp+24h] [rbp-34h]
  float v9; // [rsp+28h] [rbp-30h]
  float v10; // [rsp+2Ch] [rbp-2Ch]
  float v11; // [rsp+30h] [rbp-28h]
  float v12; // [rsp+34h] [rbp-24h]
  float v13; // [rsp+38h] [rbp-20h]
  float v14; // [rsp+3Ch] [rbp-1Ch]

  v2 = *(__m128d *)&x;
  if ( (*(_QWORD *)&x & 0x7FF0000000000000i64) != 0x7FF0000000000000i64 || (*(_QWORD *)&x & 0xFFFFFFFFFFFFFi64) == 0 )
  {
    if ( x == -INFINITY || x == INFINITY )
      v2 = 0i64;
    this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[53].__vecDelDtor(
      this,
      0);
    v4 = (int *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
    v2.m128d_f64[0] = v2.m128d_f64[0] * 20.0;
    v7 = *(float *)v4;
    v5 = (int)v2.m128d_f64[0];
    v8 = *((float *)v4 + 1);
    v9 = *((float *)v4 + 2);
    v10 = *((float *)v4 + 3);
    v11 = *((float *)v4 + 4);
    v12 = *((float *)v4 + 5);
    v13 = *((float *)v4 + 6);
    v14 = *((float *)v4 + 7);
    if ( (double)v5 != v2.m128d_f64[0] )
      v2.m128d_f64[0] = (double)(v5 - (_mm_movemask_pd(_mm_unpacklo_pd(v2, v2)) & 1));
    this->pGeomData->X = (int)v2.m128d_f64[0];
    v6 = (float)this->pGeomData->X;
    v10 = v6;
    if ( v7 >= -3.4028235e38
      && v7 <= 3.4028235e38
      && v8 >= -3.4028235e38
      && v8 <= 3.4028235e38
      && v9 >= -3.4028235e38
      && v9 <= 3.4028235e38
      && v6 >= -3.4028235e38
      && v6 <= 3.4028235e38
      && v11 >= -3.4028235e38
      && v11 <= 3.4028235e38
      && v12 >= -3.4028235e38
      && v12 <= 3.4028235e38
      && v13 >= -3.4028235e38
      && v13 <= 3.4028235e38
      && v14 >= -3.4028235e38
      && v14 <= 3.4028235e38 )
    {
      this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[3].__vecDelDtor(
        this,
        (unsigned int)&v7);
    }
  }
}

// File Line: 947
// RVA: 0x90FF10
// local variable allocation has failed, the output may be wrong!
void __fastcall Scaleform::GFx::DisplayObjectBase::SetY(Scaleform::GFx::DisplayObjectBase *this, double y)
{
  __m128d v2; // xmm6
  int *v4; // rax
  int v5; // ecx
  float v6; // xmm2_4
  float v7; // [rsp+20h] [rbp-38h] BYREF
  float v8; // [rsp+24h] [rbp-34h]
  float v9; // [rsp+28h] [rbp-30h]
  float v10; // [rsp+2Ch] [rbp-2Ch]
  float v11; // [rsp+30h] [rbp-28h]
  float v12; // [rsp+34h] [rbp-24h]
  float v13; // [rsp+38h] [rbp-20h]
  float v14; // [rsp+3Ch] [rbp-1Ch]

  v2 = *(__m128d *)&y;
  if ( (*(_QWORD *)&y & 0x7FF0000000000000i64) != 0x7FF0000000000000i64 || (*(_QWORD *)&y & 0xFFFFFFFFFFFFFi64) == 0 )
  {
    if ( y == -INFINITY || y == INFINITY )
      v2 = 0i64;
    this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[53].__vecDelDtor(
      this,
      0);
    v4 = (int *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
    v2.m128d_f64[0] = v2.m128d_f64[0] * 20.0;
    v7 = *(float *)v4;
    v5 = (int)v2.m128d_f64[0];
    v8 = *((float *)v4 + 1);
    v9 = *((float *)v4 + 2);
    v10 = *((float *)v4 + 3);
    v11 = *((float *)v4 + 4);
    v12 = *((float *)v4 + 5);
    v13 = *((float *)v4 + 6);
    v14 = *((float *)v4 + 7);
    if ( (double)v5 != v2.m128d_f64[0] )
      v2.m128d_f64[0] = (double)(v5 - (_mm_movemask_pd(_mm_unpacklo_pd(v2, v2)) & 1));
    this->pGeomData->Y = (int)v2.m128d_f64[0];
    v6 = (float)this->pGeomData->Y;
    v14 = v6;
    if ( v7 >= -3.4028235e38
      && v7 <= 3.4028235e38
      && v8 >= -3.4028235e38
      && v8 <= 3.4028235e38
      && v9 >= -3.4028235e38
      && v9 <= 3.4028235e38
      && v10 >= -3.4028235e38
      && v10 <= 3.4028235e38
      && v11 >= -3.4028235e38
      && v11 <= 3.4028235e38
      && v12 >= -3.4028235e38
      && v12 <= 3.4028235e38
      && v13 >= -3.4028235e38
      && v13 <= 3.4028235e38
      && v6 >= -3.4028235e38
      && v6 <= 3.4028235e38 )
    {
      this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[3].__vecDelDtor(
        this,
        (unsigned int)&v7);
    }
  }
}

// File Line: 963
// RVA: 0x9106E0
void __fastcall Scaleform::GFx::DisplayObjectBase::SetZ(Scaleform::GFx::DisplayObjectBase *this, long double z)
{
  long double v2; // xmm6_8
  Scaleform::GFx::ASMovieRootBase *pASRoot; // rcx

  v2 = z;
  if ( (*(_QWORD *)&z & 0x7FF0000000000000i64) != 0x7FF0000000000000i64 || (*(_QWORD *)&z & 0xFFFFFFFFFFFFFi64) == 0 )
  {
    if ( z == -INFINITY || z == INFINITY )
      v2 = 0.0;
    pASRoot = this->pASRoot;
    if ( pASRoot
      && ((unsigned __int8 (__fastcall *)(Scaleform::GFx::MovieImpl *))pASRoot->pMovieImpl->vfptr[70].__vecDelDtor)(pASRoot->pMovieImpl) )
    {
      Scaleform::GFx::DisplayObjectBase::EnsureGeomDataCreated(this);
    }
    else
    {
      this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[53].__vecDelDtor(
        this,
        0);
    }
    this->pGeomData->Z = v2;
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[13].__vecDelDtor)(this);
  }
}

// File Line: 981
// RVA: 0x90FC80
void __fastcall Scaleform::GFx::DisplayObjectBase::SetXScale(Scaleform::GFx::DisplayObjectBase *this, double xscale)
{
  double v2; // xmm7_8
  bool v4; // zf
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // rax
  __int64 v6; // rax
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // rdi
  float v8; // xmm10_4
  __m128d v9; // xmm2
  __m128 v10; // xmm9
  double v11; // xmm8_8
  long double v12; // xmm6_8
  long double v13; // xmm0_8
  float v14; // xmm1_4
  Scaleform::Render::Matrix2x4<float> m; // [rsp+20h] [rbp-78h] BYREF

  v2 = xscale;
  if ( ((*(_QWORD *)&xscale & 0x7FF0000000000000i64) != 0x7FF0000000000000i64
     || (*(_QWORD *)&xscale & 0xFFFFFFFFFFFFFi64) == 0)
    && xscale != -INFINITY
    && xscale != INFINITY )
  {
    this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[53].__vecDelDtor(
      this,
      0);
    this->pGeomData->XScale = xscale;
    v4 = !Scaleform::GFx::DisplayObjectBase::Has3D(this);
    vfptr = this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
    if ( v4 )
    {
      v6 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))vfptr[2].__vecDelDtor)(this);
      pGeomData = this->pGeomData;
      m.M[0][0] = pGeomData->OrigMatrix.M[0][0];
      v8 = pGeomData->OrigMatrix.M[0][1];
      v9 = _mm_cvtps_pd((__m128)LODWORD(m.M[0][0]));
      *(_QWORD *)&m.M[0][1] = *(_QWORD *)&pGeomData->OrigMatrix.M[0][1];
      m.M[0][3] = pGeomData->OrigMatrix.M[0][3];
      m.M[1][0] = pGeomData->OrigMatrix.M[1][0];
      v10 = (__m128)LODWORD(pGeomData->OrigMatrix.M[1][1]);
      *(_QWORD *)&m.M[1][1] = *(_QWORD *)&pGeomData->OrigMatrix.M[1][1];
      m.M[1][3] = pGeomData->OrigMatrix.M[1][3];
      m.M[0][3] = *(float *)(v6 + 12);
      v9.m128d_f64[0] = v9.m128d_f64[0] * v9.m128d_f64[0] + m.M[1][0] * m.M[1][0];
      m.M[1][3] = *(float *)(v6 + 28);
      v11 = _mm_sqrt_pd(v9).m128d_f64[0];
      if ( v11 == 0.0 || xscale > 1.0e16 )
      {
        v11 = DOUBLE_1_0;
        v2 = 0.0;
      }
      v12 = pGeomData->Rotation * 3.141592653589793 * 0.005555555555555556;
      v13 = atan2(m.M[1][0], m.M[0][0]);
      v10.m128_f32[0] = (float)(v10.m128_f32[0] * v10.m128_f32[0]) + (float)(v8 * v8);
      v14 = v2 / (v11 * 100.0);
      Scaleform::GFx::ASCharacter_MatrixScaleAndRotate2x2(
        &m,
        v14,
        pGeomData->YScale / (_mm_sqrt_pd(_mm_cvtps_pd(v10)).m128d_f64[0] * 100.0),
        v12 - v13);
      if ( Scaleform::Render::Matrix2x4<float>::IsValid(&m) )
        this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[3].__vecDelDtor(
          this,
          (unsigned int)&m);
    }
    else
    {
      ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))vfptr[13].__vecDelDtor)(this);
    }
  }
}

// File Line: 1019
// RVA: 0x910440
void __fastcall Scaleform::GFx::DisplayObjectBase::SetYScale(Scaleform::GFx::DisplayObjectBase *this, double yscale)
{
  double v2; // xmm7_8
  bool v4; // zf
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // rax
  __int64 v6; // rax
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // rdi
  float v8; // xmm10_4
  __m128 v9; // xmm9
  __m128d v10; // xmm2
  double v11; // xmm8_8
  long double v12; // xmm6_8
  long double v13; // xmm0_8
  float v14; // xmm2_4
  Scaleform::Render::Matrix2x4<float> m; // [rsp+20h] [rbp-78h] BYREF

  v2 = yscale;
  if ( ((*(_QWORD *)&yscale & 0x7FF0000000000000i64) != 0x7FF0000000000000i64
     || (*(_QWORD *)&yscale & 0xFFFFFFFFFFFFFi64) == 0)
    && yscale != -INFINITY
    && yscale != INFINITY )
  {
    this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[53].__vecDelDtor(
      this,
      0);
    this->pGeomData->YScale = yscale;
    v4 = !Scaleform::GFx::DisplayObjectBase::Has3D(this);
    vfptr = this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
    if ( v4 )
    {
      v6 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))vfptr[2].__vecDelDtor)(this);
      pGeomData = this->pGeomData;
      v8 = pGeomData->OrigMatrix.M[0][0];
      *(_OWORD *)&m.M[0][0] = *(_OWORD *)&pGeomData->OrigMatrix.M[0][0];
      v9 = (__m128)LODWORD(pGeomData->OrigMatrix.M[1][0]);
      *(_OWORD *)&m.M[1][0] = *(_OWORD *)&pGeomData->OrigMatrix.M[1][0];
      m.M[0][3] = *(float *)(v6 + 12);
      v10 = _mm_cvtps_pd((__m128)LODWORD(m.M[0][1]));
      m.M[1][3] = *(float *)(v6 + 28);
      v10.m128d_f64[0] = v10.m128d_f64[0] * v10.m128d_f64[0] + m.M[1][1] * m.M[1][1];
      v11 = _mm_sqrt_pd(v10).m128d_f64[0];
      if ( v11 == 0.0 || yscale > 1.0e16 )
      {
        v11 = DOUBLE_1_0;
        v2 = 0.0;
      }
      v12 = pGeomData->Rotation * 3.141592653589793 * 0.005555555555555556;
      v13 = atan2(v9.m128_f32[0], v8);
      v9.m128_f32[0] = (float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(v8 * v8);
      v14 = v2 / (v11 * 100.0);
      Scaleform::GFx::ASCharacter_MatrixScaleAndRotate2x2(
        &m,
        pGeomData->XScale / (_mm_sqrt_pd(_mm_cvtps_pd(v9)).m128d_f64[0] * 100.0),
        v14,
        v12 - v13);
      if ( Scaleform::Render::Matrix2x4<float>::IsValid(&m) )
        this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[3].__vecDelDtor(
          this,
          (unsigned int)&m);
    }
    else
    {
      ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))vfptr[13].__vecDelDtor)(this);
    }
  }
}

// File Line: 1057
// RVA: 0x9107A0
void __fastcall Scaleform::GFx::DisplayObjectBase::SetZScale(
        Scaleform::GFx::DisplayObjectBase *this,
        long double zscale)
{
  Scaleform::GFx::ASMovieRootBase *pASRoot; // rcx

  if ( ((*(_QWORD *)&zscale & 0x7FF0000000000000i64) != 0x7FF0000000000000i64
     || (*(_QWORD *)&zscale & 0xFFFFFFFFFFFFFi64) == 0)
    && zscale != -INFINITY
    && zscale != INFINITY )
  {
    pASRoot = this->pASRoot;
    if ( pASRoot
      && ((unsigned __int8 (__fastcall *)(Scaleform::GFx::MovieImpl *))pASRoot->pMovieImpl->vfptr[70].__vecDelDtor)(pASRoot->pMovieImpl) )
    {
      Scaleform::GFx::DisplayObjectBase::EnsureGeomDataCreated(this);
    }
    else
    {
      this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[53].__vecDelDtor(
        this,
        0);
    }
    this->pGeomData->ZScale = zscale;
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[13].__vecDelDtor)(this);
  }
}

// File Line: 1077
// RVA: 0x90B1A0
void __fastcall Scaleform::GFx::DisplayObjectBase::SetRotation(
        Scaleform::GFx::DisplayObjectBase *this,
        long double rotation)
{
  double v3; // xmm0_8
  double v4; // xmm10_8
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // rax
  Scaleform::Render::TreeNode *pObject; // rcx
  __int64 v7; // rax
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v8; // rbx
  __m128 v9; // xmm8
  __m128 v10; // xmm6
  float v11; // xmm3_4
  float v12; // xmm2_4
  Scaleform::Render::Matrix2x4<float> m; // [rsp+20h] [rbp-78h] BYREF

  if ( (*(_QWORD *)&rotation & 0x7FF0000000000000i64) != 0x7FF0000000000000i64
    || (*(_QWORD *)&rotation & 0xFFFFFFFFFFFFFi64) == 0 )
  {
    this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[53].__vecDelDtor(
      this,
      0);
    v3 = fmod(rotation, 360.0);
    v4 = v3;
    if ( v3 <= 180.0 )
    {
      if ( v3 < -180.0 )
        v4 = v3 + 360.0;
    }
    else
    {
      v4 = v3 + -360.0;
    }
    pGeomData = this->pGeomData;
    if ( this->pASRoot->AVMVersion == 1 )
      pGeomData->Rotation = v4;
    else
      pGeomData->Rotation = rotation;
    pObject = this->pRenNode.pObject;
    if ( pObject
      && (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                               + 8i64
                               * (unsigned int)((int)((_DWORD)pObject - ((unsigned int)pObject & 0xFFFFF000) - 56) / 56)
                               + 40)
                   + 10i64) & 0x200) != 0 )
    {
      ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[13].__vecDelDtor)(this);
    }
    else
    {
      v7 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
      v8 = this->pGeomData;
      m = v8->OrigMatrix;
      v9 = (__m128)LODWORD(m.M[1][0]);
      v10 = (__m128)LODWORD(m.M[1][1]);
      m.M[0][3] = *(float *)(v7 + 12);
      m.M[1][3] = *(float *)(v7 + 28);
      v10.m128_f32[0] = (float)(v10.m128_f32[0] * v10.m128_f32[0]) + (float)(m.M[0][1] * m.M[0][1]);
      v9.m128_f32[0] = (float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(m.M[0][0] * m.M[0][0]);
      v11 = v4 * 3.141592653589793 * 0.005555555555555556 - atan2(m.M[1][0], m.M[0][0]);
      v12 = v8->YScale / (_mm_sqrt_pd(_mm_cvtps_pd(v10)).m128d_f64[0] * 100.0);
      Scaleform::GFx::ASCharacter_MatrixScaleAndRotate2x2(
        &m,
        v8->XScale / (_mm_sqrt_pd(_mm_cvtps_pd(v9)).m128d_f64[0] * 100.0),
        v12,
        v11);
      if ( m.M[0][0] >= -3.4028235e38
        && m.M[0][0] <= 3.4028235e38
        && m.M[0][1] >= -3.4028235e38
        && m.M[0][1] <= 3.4028235e38
        && m.M[0][2] >= -3.4028235e38
        && m.M[0][2] <= 3.4028235e38
        && m.M[0][3] >= -3.4028235e38
        && m.M[0][3] <= 3.4028235e38
        && m.M[1][0] >= -3.4028235e38
        && m.M[1][0] <= 3.4028235e38
        && m.M[1][1] >= -3.4028235e38
        && m.M[1][1] <= 3.4028235e38
        && m.M[1][2] >= -3.4028235e38
        && m.M[1][2] <= 3.4028235e38
        && m.M[1][3] >= -3.4028235e38
        && m.M[1][3] <= 3.4028235e38 )
      {
        this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[3].__vecDelDtor(
          this,
          (unsigned int)&m);
      }
    }
  }
}

// File Line: 1118
// RVA: 0x90FB90
void __fastcall Scaleform::GFx::DisplayObjectBase::SetXRotation(
        Scaleform::GFx::DisplayObjectBase *this,
        long double rotation)
{
  Scaleform::GFx::ASMovieRootBase *pASRoot; // rcx
  double v4; // xmm0_8

  if ( (*(_QWORD *)&rotation & 0x7FF0000000000000i64) != 0x7FF0000000000000i64
    || (*(_QWORD *)&rotation & 0xFFFFFFFFFFFFFi64) == 0 )
  {
    pASRoot = this->pASRoot;
    if ( pASRoot
      && ((unsigned __int8 (__fastcall *)(Scaleform::GFx::MovieImpl *))pASRoot->pMovieImpl->vfptr[70].__vecDelDtor)(pASRoot->pMovieImpl) )
    {
      Scaleform::GFx::DisplayObjectBase::EnsureGeomDataCreated(this);
    }
    else
    {
      this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[53].__vecDelDtor(
        this,
        0);
    }
    if ( this->pASRoot->AVMVersion == 1 )
    {
      v4 = fmod(rotation, 360.0);
      if ( v4 <= 180.0 )
      {
        if ( v4 < -180.0 )
          v4 = v4 + 360.0;
        this->pGeomData->XRotation = v4;
      }
      else
      {
        this->pGeomData->XRotation = v4 + -360.0;
      }
    }
    else
    {
      this->pGeomData->XRotation = rotation;
    }
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[13].__vecDelDtor)(this);
  }
}

// File Line: 1145
// RVA: 0x910350
void __fastcall Scaleform::GFx::DisplayObjectBase::SetYRotation(
        Scaleform::GFx::DisplayObjectBase *this,
        long double rotation)
{
  Scaleform::GFx::ASMovieRootBase *pASRoot; // rcx
  double v4; // xmm0_8

  if ( (*(_QWORD *)&rotation & 0x7FF0000000000000i64) != 0x7FF0000000000000i64
    || (*(_QWORD *)&rotation & 0xFFFFFFFFFFFFFi64) == 0 )
  {
    pASRoot = this->pASRoot;
    if ( pASRoot
      && ((unsigned __int8 (__fastcall *)(Scaleform::GFx::MovieImpl *))pASRoot->pMovieImpl->vfptr[70].__vecDelDtor)(pASRoot->pMovieImpl) )
    {
      Scaleform::GFx::DisplayObjectBase::EnsureGeomDataCreated(this);
    }
    else
    {
      this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[53].__vecDelDtor(
        this,
        0);
    }
    if ( this->pASRoot->AVMVersion == 1 )
    {
      v4 = fmod(rotation, 360.0);
      if ( v4 <= 180.0 )
      {
        if ( v4 < -180.0 )
          v4 = v4 + 360.0;
        this->pGeomData->YRotation = v4;
      }
      else
      {
        this->pGeomData->YRotation = v4 + -360.0;
      }
    }
    else
    {
      this->pGeomData->YRotation = rotation;
    }
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[13].__vecDelDtor)(this);
  }
}

// File Line: 1172
// RVA: 0x90F2B0
void __fastcall Scaleform::GFx::DisplayObjectBase::SetWidth(Scaleform::GFx::DisplayObjectBase *this, double width)
{
  double v2; // xmm8_8
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // rax
  float v5; // xmm1_4
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // rax
  __int64 v7; // rax
  float v8; // xmm4_4
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v9; // rax
  double Rotation; // xmm6_8
  float v11; // xmm0_4
  float v12; // xmm6_4
  float *v13; // rax
  float v14; // xmm1_4
  float v15; // xmm6_4
  __m128d v16; // xmm1
  double v17; // xmm8_8
  double v18; // xmm7_8
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v19; // rbx
  double v20; // xmm6_8
  long double v21; // xmm0_8
  __m128 v22; // xmm1
  Scaleform::Render::Matrix2x4<float> m; // [rsp+20h] [rbp-49h] BYREF
  Scaleform::Render::Matrix2x4<float> v24; // [rsp+40h] [rbp-29h] BYREF
  Scaleform::Render::Matrix2x4<float> v25; // [rsp+60h] [rbp-9h] BYREF

  v2 = width;
  if ( ((*(_QWORD *)&width & 0x7FF0000000000000i64) != 0x7FF0000000000000i64
     || (*(_QWORD *)&width & 0xFFFFFFFFFFFFFi64) == 0)
    && width != -INFINITY )
  {
    if ( width == INFINITY )
      v2 = 0.0;
    this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[53].__vecDelDtor(
      this,
      0);
    pGeomData = this->pGeomData;
    *(_OWORD *)&v24.M[0][0] = *(_OWORD *)&pGeomData->OrigMatrix.M[0][0];
    *(_QWORD *)&v24.M[1][0] = *(_QWORD *)&pGeomData->OrigMatrix.M[1][0];
    v24.M[1][2] = pGeomData->OrigMatrix.M[1][2];
    v5 = pGeomData->OrigMatrix.M[1][3];
    vfptr = this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
    v24.M[1][3] = v5;
    v7 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))vfptr[2].__vecDelDtor)(this);
    v24.M[0][3] = *(float *)(v7 + 12);
    v8 = *(float *)(v7 + 28);
    v9 = this->pGeomData;
    *(_QWORD *)&v25.M[1][2] = __PAIR64__(LODWORD(v8), LODWORD(v24.M[1][2]));
    v24.M[1][3] = v8;
    *(_OWORD *)&v25.M[0][0] = *(_OWORD *)&v24.M[0][0];
    *(_QWORD *)&v25.M[1][0] = *(_QWORD *)&v24.M[1][0];
    Rotation = v9->Rotation;
    *(float *)&Rotation = Rotation * 3.141592653589793 * 0.005555555555555556 - atan2(v24.M[1][0], v24.M[0][0]);
    cosf(*(float *)&Rotation);
    v11 = sinf(*(float *)&Rotation);
    m.M[0][0] = *(float *)&Rotation;
    m.M[1][1] = *(float *)&Rotation;
    v12 = 0.0;
    m.M[1][0] = v11;
    m.M[0][3] = 0.0;
    *(_QWORD *)&m.M[1][2] = 0i64;
    *(_QWORD *)&m.M[0][1] = (unsigned int)(LODWORD(v11) ^ _xmm[0]);
    Scaleform::Render::Matrix2x4<float>::Append(&v25, &m);
    v13 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Matrix2x4<float> *, Scaleform::Render::Matrix2x4<float> *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[61].__vecDelDtor)(
                     this,
                     &m,
                     &v25);
    v14 = v13[2] - *v13;
    if ( COERCE_FLOAT(LODWORD(v14) & _xmm) > 0.000001 )
    {
      v15 = v2 * 20.0;
      v12 = v15 / v14;
    }
    v16 = _mm_cvtps_pd((__m128)LODWORD(v24.M[0][0]));
    v16.m128d_f64[0] = v16.m128d_f64[0] * v16.m128d_f64[0] + v24.M[1][0] * v24.M[1][0];
    v17 = _mm_sqrt_pd(v16).m128d_f64[0];
    v18 = v12 * v17 * 100.0;
    this->pGeomData->XScale = v18;
    if ( v17 == 0.0 )
    {
      v17 = DOUBLE_1_0;
      v18 = 0.0;
    }
    v19 = this->pGeomData;
    v20 = v19->Rotation;
    v21 = atan2(v24.M[1][0], v24.M[0][0]);
    v22 = (__m128)LODWORD(v24.M[1][1]);
    v22.m128_f32[0] = (float)(v22.m128_f32[0] * v22.m128_f32[0]) + (float)(v24.M[0][1] * v24.M[0][1]);
    Scaleform::GFx::ASCharacter_MatrixScaleAndRotate2x2(
      &v24,
      COERCE_DOUBLE(COERCE_UNSIGNED_INT64(v18 / (v17 * 100.0)) & _xmm),
      COERCE_DOUBLE(COERCE_UNSIGNED_INT64(v19->YScale / (_mm_sqrt_pd(_mm_cvtps_pd(v22)).m128d_f64[0] * 100.0)) & _xmm),
      v20 * 3.141592653589793 * 0.005555555555555556 - v21);
    *(_QWORD *)&v19->XScale &= _xmm;
    *(_QWORD *)&this->pGeomData->YScale &= _xmm;
    if ( v24.M[0][0] >= -3.4028235e38
      && v24.M[0][0] <= 3.4028235e38
      && v24.M[0][1] >= -3.4028235e38
      && v24.M[0][1] <= 3.4028235e38
      && v24.M[0][2] >= -3.4028235e38
      && v24.M[0][2] <= 3.4028235e38
      && v24.M[0][3] >= -3.4028235e38
      && v24.M[0][3] <= 3.4028235e38
      && v24.M[1][0] >= -3.4028235e38
      && v24.M[1][0] <= 3.4028235e38
      && v24.M[1][1] >= -3.4028235e38
      && v24.M[1][1] <= 3.4028235e38
      && v24.M[1][2] >= -3.4028235e38
      && v24.M[1][2] <= 3.4028235e38
      && v24.M[1][3] >= -3.4028235e38
      && v24.M[1][3] <= 3.4028235e38 )
    {
      this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[3].__vecDelDtor(
        this,
        (unsigned int)&v24);
    }
  }
}

// File Line: 1223
// RVA: 0x9077B0
void __fastcall Scaleform::GFx::DisplayObjectBase::SetHeight(Scaleform::GFx::DisplayObjectBase *this, double height)
{
  double v2; // xmm8_8
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // rax
  float v5; // xmm1_4
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // rax
  __int64 v7; // rax
  float v8; // xmm4_4
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v9; // rax
  double Rotation; // xmm6_8
  float v11; // xmm0_4
  float v12; // xmm6_4
  __int64 v13; // rax
  float v14; // xmm1_4
  float v15; // xmm6_4
  __m128d v16; // xmm1
  double v17; // xmm10_8
  double v18; // xmm9_8
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v19; // rbx
  __m128 v20; // xmm8
  float v21; // xmm7_4
  double v22; // xmm6_8
  long double v23; // xmm6_8
  Scaleform::Render::Matrix2x4<float> m; // [rsp+20h] [rbp-69h] BYREF
  Scaleform::Render::Matrix2x4<float> v25; // [rsp+40h] [rbp-49h] BYREF
  Scaleform::Render::Matrix2x4<float> v26; // [rsp+60h] [rbp-29h] BYREF

  v2 = height;
  if ( ((*(_QWORD *)&height & 0x7FF0000000000000i64) != 0x7FF0000000000000i64
     || (*(_QWORD *)&height & 0xFFFFFFFFFFFFFi64) == 0)
    && height != -INFINITY )
  {
    if ( height == INFINITY )
      v2 = 0.0;
    this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[53].__vecDelDtor(
      this,
      0);
    pGeomData = this->pGeomData;
    *(_OWORD *)&v25.M[0][0] = *(_OWORD *)&pGeomData->OrigMatrix.M[0][0];
    *(_QWORD *)&v25.M[1][0] = *(_QWORD *)&pGeomData->OrigMatrix.M[1][0];
    v25.M[1][2] = pGeomData->OrigMatrix.M[1][2];
    v5 = pGeomData->OrigMatrix.M[1][3];
    vfptr = this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
    v25.M[1][3] = v5;
    v7 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))vfptr[2].__vecDelDtor)(this);
    v25.M[0][3] = *(float *)(v7 + 12);
    v8 = *(float *)(v7 + 28);
    v9 = this->pGeomData;
    *(_QWORD *)&v26.M[1][2] = __PAIR64__(LODWORD(v8), LODWORD(v25.M[1][2]));
    v25.M[1][3] = v8;
    *(_OWORD *)&v26.M[0][0] = *(_OWORD *)&v25.M[0][0];
    *(_QWORD *)&v26.M[1][0] = *(_QWORD *)&v25.M[1][0];
    Rotation = v9->Rotation;
    *(float *)&Rotation = Rotation * 3.141592653589793 * 0.005555555555555556 - atan2(v25.M[1][0], v25.M[0][0]);
    cosf(*(float *)&Rotation);
    v11 = sinf(*(float *)&Rotation);
    m.M[0][0] = *(float *)&Rotation;
    m.M[1][1] = *(float *)&Rotation;
    v12 = 0.0;
    m.M[1][0] = v11;
    m.M[0][3] = 0.0;
    *(_QWORD *)&m.M[1][2] = 0i64;
    *(_QWORD *)&m.M[0][1] = (unsigned int)(LODWORD(v11) ^ _xmm[0]);
    Scaleform::Render::Matrix2x4<float>::Append(&v26, &m);
    v13 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Matrix2x4<float> *, Scaleform::Render::Matrix2x4<float> *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[61].__vecDelDtor)(
            this,
            &m,
            &v26);
    v14 = *(float *)(v13 + 12) - *(float *)(v13 + 4);
    if ( COERCE_FLOAT(LODWORD(v14) & _xmm) > 0.000001 )
    {
      v15 = v2 * 20.0;
      v12 = v15 / v14;
    }
    v16 = _mm_cvtps_pd((__m128)LODWORD(v25.M[0][1]));
    v16.m128d_f64[0] = v16.m128d_f64[0] * v16.m128d_f64[0] + v25.M[1][1] * v25.M[1][1];
    v17 = _mm_sqrt_pd(v16).m128d_f64[0];
    v18 = v12 * v17 * 100.0;
    this->pGeomData->YScale = v18;
    if ( v17 == 0.0 )
    {
      v17 = DOUBLE_1_0;
      v18 = 0.0;
    }
    v19 = this->pGeomData;
    v20 = (__m128)LODWORD(v25.M[1][0]);
    v21 = v25.M[0][0];
    v22 = v19->Rotation;
    v23 = v22 * 3.141592653589793 * 0.005555555555555556 - atan2(v25.M[1][0], v25.M[0][0]);
    v20.m128_f32[0] = (float)(v20.m128_f32[0] * v20.m128_f32[0]) + (float)(v21 * v21);
    Scaleform::GFx::ASCharacter_MatrixScaleAndRotate2x2(
      &v25,
      COERCE_DOUBLE(COERCE_UNSIGNED_INT64(v19->XScale / (_mm_sqrt_pd(_mm_cvtps_pd(v20)).m128d_f64[0] * 100.0)) & _xmm),
      COERCE_DOUBLE(COERCE_UNSIGNED_INT64(v18 / (v17 * 100.0)) & _xmm),
      v23);
    *(_QWORD *)&v19->XScale &= _xmm;
    *(_QWORD *)&this->pGeomData->YScale &= _xmm;
    if ( v25.M[0][0] >= -3.4028235e38
      && v25.M[0][0] <= 3.4028235e38
      && v25.M[0][1] >= -3.4028235e38
      && v25.M[0][1] <= 3.4028235e38
      && v25.M[0][2] >= -3.4028235e38
      && v25.M[0][2] <= 3.4028235e38
      && v25.M[0][3] >= -3.4028235e38
      && v25.M[0][3] <= 3.4028235e38
      && v25.M[1][0] >= -3.4028235e38
      && v25.M[1][0] <= 3.4028235e38
      && v25.M[1][1] >= -3.4028235e38
      && v25.M[1][1] <= 3.4028235e38
      && v25.M[1][2] >= -3.4028235e38
      && v25.M[1][2] <= 3.4028235e38
      && v25.M[1][3] >= -3.4028235e38
      && v25.M[1][3] <= 3.4028235e38 )
    {
      this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[3].__vecDelDtor(
        this,
        (unsigned int)&v25);
    }
  }
}

// File Line: 1275
// RVA: 0x9061C0
void __fastcall Scaleform::GFx::DisplayObjectBase::SetAlpha(Scaleform::GFx::DisplayObjectBase *this, long double alpha)
{
  Scaleform::Render::TreeNode *pObject; // rcx
  Scaleform::Render::Cxform *v4; // rdx
  Scaleform::Render::ContextImpl::EntryData v5; // xmm6
  float v6; // xmm0_4
  Scaleform::Render::TreeNode *RenderNode; // rax
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax
  Scaleform::Render::ContextImpl::EntryData v9; // [rsp+20h] [rbp-38h]

  if ( (*(_QWORD *)&alpha & 0x7FF0000000000000i64) != 0x7FF0000000000000i64
    || (*(_QWORD *)&alpha & 0xFFFFFFFFFFFFFi64) == 0 )
  {
    pObject = this->pRenNode.pObject;
    if ( pObject )
      v4 = (Scaleform::Render::Cxform *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64)
                                                               + 0x20)
                                                   + 8i64
                                                   * (unsigned int)((int)((_DWORD)pObject
                                                                        - ((unsigned int)pObject & 0xFFFFF000)
                                                                        - 56)
                                                                  / 56)
                                                   + 40)
                                       + 80i64);
    else
      v4 = &Scaleform::Render::Cxform::Identity;
    v5 = *(Scaleform::Render::ContextImpl::EntryData *)&v4->M[1][0];
    v9 = *(Scaleform::Render::ContextImpl::EntryData *)&v4->M[0][0];
    v6 = alpha * 0.01;
    *(float *)(&v9.Flags + 1) = v6;
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(RenderNode, 2u);
    WritableData[5] = v9;
    WritableData[6] = v5;
    this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[53].__vecDelDtor(
      this,
      0);
  }
}

// File Line: 1288
// RVA: 0x8E1B40
double __fastcall Scaleform::GFx::DisplayObjectBase::GetX(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [rsp+20h] [rbp-68h] BYREF

  *(_QWORD *)&geomData.X = 0i64;
  *(_OWORD *)&geomData.OrigMatrix.M[0][0] = _xmm;
  *(__m128 *)&geomData.OrigMatrix.M[1][0] = _xmm;
  geomData.YScale = DOUBLE_100_0;
  geomData.XScale = DOUBLE_100_0;
  geomData.Rotation = 0.0;
  *(_OWORD *)&geomData.XRotation = 0i64;
  *(_OWORD *)&geomData.Z = _xmm;
  return (double)Scaleform::GFx::DisplayObjectBase::GetGeomData(this, &geomData)->X * 0.05;
}

// File Line: 1294
// RVA: 0x8E1D50
double __fastcall Scaleform::GFx::DisplayObjectBase::GetY(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [rsp+20h] [rbp-68h] BYREF

  *(_QWORD *)&geomData.X = 0i64;
  *(_OWORD *)&geomData.OrigMatrix.M[0][0] = _xmm;
  *(__m128 *)&geomData.OrigMatrix.M[1][0] = _xmm;
  geomData.YScale = DOUBLE_100_0;
  geomData.XScale = DOUBLE_100_0;
  geomData.Rotation = 0.0;
  *(_OWORD *)&geomData.XRotation = 0i64;
  *(_OWORD *)&geomData.Z = _xmm;
  return (double)Scaleform::GFx::DisplayObjectBase::GetGeomData(this, &geomData)->Y * 0.05;
}

// File Line: 1300
// RVA: 0x8E1F60
long double __fastcall Scaleform::GFx::DisplayObjectBase::GetZ(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [rsp+20h] [rbp-68h] BYREF

  *(_QWORD *)&geomData.X = 0i64;
  *(_OWORD *)&geomData.OrigMatrix.M[0][0] = _xmm;
  *(__m128 *)&geomData.OrigMatrix.M[1][0] = _xmm;
  geomData.YScale = DOUBLE_100_0;
  geomData.XScale = DOUBLE_100_0;
  geomData.Rotation = 0.0;
  *(_OWORD *)&geomData.XRotation = 0i64;
  *(_OWORD *)&geomData.Z = _xmm;
  return Scaleform::GFx::DisplayObjectBase::GetGeomData(this, &geomData)->Z;
}

// File Line: 1306
// RVA: 0x8E1CE0
long double __fastcall Scaleform::GFx::DisplayObjectBase::GetXScale(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [rsp+20h] [rbp-68h] BYREF

  *(_QWORD *)&geomData.X = 0i64;
  *(_OWORD *)&geomData.OrigMatrix.M[0][0] = _xmm;
  *(__m128 *)&geomData.OrigMatrix.M[1][0] = _xmm;
  geomData.YScale = DOUBLE_100_0;
  geomData.XScale = DOUBLE_100_0;
  geomData.Rotation = 0.0;
  *(_OWORD *)&geomData.XRotation = 0i64;
  *(_OWORD *)&geomData.Z = _xmm;
  return Scaleform::GFx::DisplayObjectBase::GetGeomData(this, &geomData)->XScale;
}

// File Line: 1312
// RVA: 0x8E1EF0
long double __fastcall Scaleform::GFx::DisplayObjectBase::GetYScale(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [rsp+20h] [rbp-68h] BYREF

  *(_QWORD *)&geomData.X = 0i64;
  *(_OWORD *)&geomData.OrigMatrix.M[0][0] = _xmm;
  *(__m128 *)&geomData.OrigMatrix.M[1][0] = _xmm;
  geomData.YScale = DOUBLE_100_0;
  geomData.XScale = DOUBLE_100_0;
  geomData.Rotation = 0.0;
  *(_OWORD *)&geomData.XRotation = 0i64;
  *(_OWORD *)&geomData.Z = _xmm;
  return Scaleform::GFx::DisplayObjectBase::GetGeomData(this, &geomData)->YScale;
}

// File Line: 1318
// RVA: 0x8E1FD0
long double __fastcall Scaleform::GFx::DisplayObjectBase::GetZScale(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [rsp+20h] [rbp-68h] BYREF

  *(_QWORD *)&geomData.X = 0i64;
  *(_OWORD *)&geomData.OrigMatrix.M[0][0] = _xmm;
  *(__m128 *)&geomData.OrigMatrix.M[1][0] = _xmm;
  geomData.YScale = DOUBLE_100_0;
  geomData.XScale = DOUBLE_100_0;
  geomData.Rotation = 0.0;
  *(_OWORD *)&geomData.XRotation = 0i64;
  *(_OWORD *)&geomData.Z = _xmm;
  return Scaleform::GFx::DisplayObjectBase::GetGeomData(this, &geomData)->ZScale;
}

// File Line: 1324
// RVA: 0x8DDDC0
long double __fastcall Scaleform::GFx::DisplayObjectBase::GetRotation(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [rsp+20h] [rbp-68h] BYREF

  *(_QWORD *)&geomData.X = 0i64;
  *(_OWORD *)&geomData.OrigMatrix.M[0][0] = _xmm;
  *(__m128 *)&geomData.OrigMatrix.M[1][0] = _xmm;
  geomData.YScale = DOUBLE_100_0;
  geomData.XScale = DOUBLE_100_0;
  geomData.Rotation = 0.0;
  *(_OWORD *)&geomData.XRotation = 0i64;
  *(_OWORD *)&geomData.Z = _xmm;
  return Scaleform::GFx::DisplayObjectBase::GetGeomData(this, &geomData)->Rotation;
}

// File Line: 1330
// RVA: 0x8E1C40
long double __fastcall Scaleform::GFx::DisplayObjectBase::GetXRotation(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [rsp+20h] [rbp-68h] BYREF

  *(_QWORD *)&geomData.X = 0i64;
  *(_OWORD *)&geomData.OrigMatrix.M[0][0] = _xmm;
  *(__m128 *)&geomData.OrigMatrix.M[1][0] = _xmm;
  geomData.YScale = DOUBLE_100_0;
  geomData.XScale = DOUBLE_100_0;
  geomData.Rotation = 0.0;
  *(_OWORD *)&geomData.XRotation = 0i64;
  *(_OWORD *)&geomData.Z = _xmm;
  return Scaleform::GFx::DisplayObjectBase::GetGeomData(this, &geomData)->XRotation;
}

// File Line: 1336
// RVA: 0x8E1E50
long double __fastcall Scaleform::GFx::DisplayObjectBase::GetYRotation(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [rsp+20h] [rbp-68h] BYREF

  *(_QWORD *)&geomData.X = 0i64;
  *(_OWORD *)&geomData.OrigMatrix.M[0][0] = _xmm;
  *(__m128 *)&geomData.OrigMatrix.M[1][0] = _xmm;
  geomData.YScale = DOUBLE_100_0;
  geomData.XScale = DOUBLE_100_0;
  geomData.Rotation = 0.0;
  *(_OWORD *)&geomData.XRotation = 0i64;
  *(_OWORD *)&geomData.Z = _xmm;
  return Scaleform::GFx::DisplayObjectBase::GetGeomData(this, &geomData)->YRotation;
}

// File Line: 1342
// RVA: 0x8E18D0
double __fastcall Scaleform::GFx::DisplayObjectBase::GetWidth(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode *pObject; // rcx
  Scaleform::Render::Rect<float> *BoundsIn3D; // rax
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // rbx
  __int64 v5; // rax
  __m128 x2_low; // xmm0
  __m128d v7; // xmm0
  int v8; // ecx
  Scaleform::Render::Rect<float> result; // [rsp+20h] [rbp-18h] BYREF

  pObject = this->pRenNode.pObject;
  if ( pObject
    && (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64
                             * (unsigned int)((int)((_DWORD)pObject - ((unsigned int)pObject & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 10i64) & 0x200) != 0 )
  {
    BoundsIn3D = Scaleform::GFx::DisplayObjectBase::GetBoundsIn3D(this, &result);
  }
  else
  {
    vfptr = this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
    v5 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
    BoundsIn3D = (Scaleform::Render::Rect<float> *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Rect<float> *, __int64))vfptr[61].__vecDelDtor)(
                                                     this,
                                                     &result,
                                                     v5);
  }
  x2_low = (__m128)LODWORD(BoundsIn3D->x2);
  x2_low.m128_f32[0] = x2_low.m128_f32[0] - BoundsIn3D->x1;
  v7 = _mm_cvtps_pd(x2_low);
  v7.m128d_f64[0] = v7.m128d_f64[0] + 0.5;
  v8 = (int)v7.m128d_f64[0];
  if ( (double)v8 != v7.m128d_f64[0] )
    v7.m128d_f64[0] = (double)(v8 - (_mm_movemask_pd(_mm_unpacklo_pd(v7, v7)) & 1));
  return v7.m128d_f64[0] * 0.05;
}

// File Line: 1353
// RVA: 0x8D9990
double __fastcall Scaleform::GFx::DisplayObjectBase::GetHeight(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode *pObject; // rcx
  Scaleform::Render::Rect<float> *BoundsIn3D; // rax
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // rbx
  __int64 v5; // rax
  __m128 y2_low; // xmm0
  __m128d v7; // xmm0
  int v8; // ecx
  Scaleform::Render::Rect<float> result; // [rsp+20h] [rbp-18h] BYREF

  pObject = this->pRenNode.pObject;
  if ( pObject
    && (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64
                             * (unsigned int)((int)((_DWORD)pObject - ((unsigned int)pObject & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 10i64) & 0x200) != 0 )
  {
    BoundsIn3D = Scaleform::GFx::DisplayObjectBase::GetBoundsIn3D(this, &result);
  }
  else
  {
    vfptr = this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
    v5 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
    BoundsIn3D = (Scaleform::Render::Rect<float> *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Rect<float> *, __int64))vfptr[61].__vecDelDtor)(
                                                     this,
                                                     &result,
                                                     v5);
  }
  y2_low = (__m128)LODWORD(BoundsIn3D->y2);
  y2_low.m128_f32[0] = y2_low.m128_f32[0] - BoundsIn3D->y1;
  v7 = _mm_cvtps_pd(y2_low);
  v7.m128d_f64[0] = v7.m128d_f64[0] + 0.5;
  v8 = (int)v7.m128d_f64[0];
  if ( (double)v8 != v7.m128d_f64[0] )
    v7.m128d_f64[0] = (double)(v8 - (_mm_movemask_pd(_mm_unpacklo_pd(v7, v7)) & 1));
  return v7.m128d_f64[0] * 0.05;
}

// File Line: 1364
// RVA: 0x8D5440
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::DisplayObjectBase::GetBoundsIn3D(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Rect<float> *result)
{
  Scaleform::GFx::InteractiveObject *pParent; // rcx
  Scaleform::Render::Point<float> *v5; // rax
  float x; // xmm6_4
  float y; // xmm7_4
  Scaleform::Render::Point<float> *v8; // rax
  float v9; // xmm0_4
  float v10; // xmm1_4
  Scaleform::Render::Rect<float> *v11; // rax
  Scaleform::Render::Point3<float> ptIn; // [rsp+20h] [rbp-48h] BYREF
  int v13[4]; // [rsp+30h] [rbp-38h] BYREF
  Scaleform::Render::Point<float> resulta; // [rsp+70h] [rbp+8h] BYREF
  Scaleform::Render::Point<float> v15; // [rsp+78h] [rbp+10h] BYREF
  Scaleform::Render::Point<float> v16; // [rsp+80h] [rbp+18h] BYREF

  ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, int *, Scaleform::Render::Matrix2x4<float> *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[61].__vecDelDtor)(
    this,
    v13,
    &Scaleform::Render::Matrix2x4<float>::Identity);
  LODWORD(ptIn.x) = v13[0];
  LODWORD(ptIn.y) = v13[1];
  ptIn.z = 0.0;
  Scaleform::GFx::DisplayObjectBase::Local3DToGlobal(this, &resulta, &ptIn);
  LODWORD(ptIn.x) = v13[2];
  LODWORD(ptIn.y) = v13[3];
  ptIn.z = 0.0;
  Scaleform::GFx::DisplayObjectBase::Local3DToGlobal(this, &v15, &ptIn);
  pParent = this->pParent;
  if ( pParent )
  {
    v5 = Scaleform::GFx::DisplayObjectBase::GlobalToLocal(pParent, &v16, &resulta);
    x = v5->x;
    y = v5->y;
    v8 = Scaleform::GFx::DisplayObjectBase::GlobalToLocal(this->pParent, &resulta, &v15);
    v9 = v8->x;
    v10 = v8->y;
  }
  else
  {
    y = resulta.y;
    x = resulta.x;
    v10 = v15.y;
    v9 = v15.x;
  }
  result->x1 = x;
  v11 = result;
  result->y1 = y;
  result->x2 = (float)(v9 - x) + x;
  result->y2 = (float)(v10 - y) + y;
  return v11;
}

// File Line: 1387
// RVA: 0x8D4CD0
long double __fastcall Scaleform::GFx::DisplayObjectBase::GetAlpha(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode *pObject; // rdx
  __int64 v2; // rax
  unsigned __int64 v3; // rdx
  float v4; // xmm0_4

  pObject = this->pRenNode.pObject;
  if ( pObject )
  {
    v2 = *(_QWORD *)(((unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20);
    v3 = (__int64)((unsigned __int128)((__int64)((__int64)&pObject[-1]
                                               - ((unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64))
                                     * (__int128)0x4924924924924925i64) >> 64) >> 4;
    v4 = *(float *)(*(_QWORD *)(v2 + 8 * ((unsigned int)v3 + (v3 >> 63)) + 40) + 92i64);
  }
  else
  {
    v4 = Scaleform::Render::Cxform::Identity.M[0][3];
  }
  return (float)(v4 * 100.0);
}

// File Line: 1392
// RVA: 0x8CC420
Scaleform::GFx::MovieImpl *__fastcall Scaleform::GFx::DisplayObjectBase::FindMovieImpl(
        Scaleform::GFx::DisplayObjectBase *this)
{
  if ( !this )
    return 0i64;
  while ( SLOBYTE(this->Flags) >= 0 )
  {
    this = this->pParent;
    if ( !this )
      return 0i64;
  }
  return this->pASRoot->pMovieImpl;
}

// File Line: 1405
// RVA: 0x8E0FC0
Scaleform::GFx::InteractiveObject *__fastcall Scaleform::GFx::DisplayObjectBase::GetTopMostMouseEntityDef(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::GFx::CharacterDef *pdef,
        Scaleform::Render::Point<float> *pt,
        bool testAll,
        Scaleform::GFx::InteractiveObject *ignoreMC)
{
  __int64 v9; // r8
  Scaleform::GFx::InteractiveObject *pParent; // rbx
  Scaleform::GFx::InteractiveObject *v11; // rdi
  unsigned __int8 AvmObjOffset; // al
  __int64 v13; // rax
  __int64 v14; // rax
  unsigned __int8 v15; // cl
  __int64 v16; // rax
  Scaleform::Render::Point<float> p; // [rsp+40h] [rbp+8h] BYREF

  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[59].__vecDelDtor)(this) )
  {
    Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(this, &p, pt, 1, 0i64);
    if ( !this->ClipDepth )
    {
      LOBYTE(v9) = 1;
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::CharacterDef *, Scaleform::Render::Point<float> *, __int64, Scaleform::GFx::DisplayObjectBase *))pdef->vfptr[1].GetResourceTypeCode)(
             pdef,
             &p,
             v9,
             this) )
      {
        pParent = this->pParent;
        if ( pParent )
        {
          v11 = ignoreMC;
          while ( (pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x400) != 0 )
          {
            if ( testAll
              || (AvmObjOffset = pParent->AvmObjOffset) != 0
              && (v13 = ((__int64 (__fastcall *)(__int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                                                  + 4 * AvmObjOffset))[1].__vecDelDtor)((__int64)pParent + 4 * AvmObjOffset),
                  (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v13 + 96i64))(v13))
              || ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[121].__vecDelDtor)(pParent)
              && (v14 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[121].__vecDelDtor)(pParent),
                  (v15 = *(_BYTE *)(v14 + 109)) != 0)
              && (v16 = (*(__int64 (__fastcall **)(__int64))(*(_QWORD *)(v14 + 4i64 * v15) + 8i64))(v14 + 4i64 * v15),
                  (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v16 + 96i64))(v16)) )
            {
              if ( !v11 || v11 != pParent )
                return pParent;
            }
            pParent = pParent->pParent;
            if ( !pParent )
              return 0i64;
          }
        }
      }
    }
  }
  return 0i64;
}

// File Line: 1434
// RVA: 0x8E6E80
char __fastcall Scaleform::GFx::DisplayObjectBase::IsAncestor(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::GFx::DisplayObjectBase *ch)
{
  Scaleform::GFx::InteractiveObject *pParent; // rax

  pParent = ch->pParent;
  if ( !pParent )
    return 0;
  while ( pParent != this )
  {
    pParent = pParent->pParent;
    if ( !pParent )
      return 0;
  }
  return 1;
}

// File Line: 1455
// RVA: 0x917730
void __fastcall Scaleform::GFx::DisplayObjectBase::UpdateTransform3D(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase::GeomDataType *pGeomData; // rbx
  __m128i v2; // xmm2
  __m128i v3; // xmm3
  double Z; // xmm4_8
  float v5; // edi
  float v6; // esi
  float XScale; // xmm1_4
  double XRotation; // xmm1_8
  float v9; // ebx
  float v10; // r14d
  float v11; // r15d
  float v12; // r12d
  float v13; // r13d
  float v14; // xmm6_4
  float v15; // xmm0_4
  float v16; // edx
  float v17; // r8d
  float v18; // r9d
  float v19; // r10d
  float v20; // r11d
  Scaleform::Render::Matrix3x4<float> *p_Dst; // rcx
  double YRotation; // xmm0_8
  float v23; // xmm6_4
  float v24; // xmm0_4
  Scaleform::Render::Matrix3x4<float> *v25; // rcx
  double Rotation; // xmm0_8
  float v27; // xmm6_4
  float v28; // xmm0_4
  Scaleform::Render::Matrix3x4<float> v29; // [rsp+20h] [rbp-D8h] BYREF
  Scaleform::Render::Matrix3x4<float> Dst; // [rsp+50h] [rbp-A8h] BYREF
  float v31; // [rsp+80h] [rbp-78h]
  unsigned int v32; // [rsp+84h] [rbp-74h]
  float v33; // [rsp+88h] [rbp-70h]
  int v34; // [rsp+8Ch] [rbp-6Ch]
  float v35; // [rsp+90h] [rbp-68h]
  unsigned int v36; // [rsp+94h] [rbp-64h]
  __int64 v37; // [rsp+98h] [rbp-60h]
  int v38; // [rsp+A0h] [rbp-58h]
  int v39; // [rsp+A4h] [rbp-54h]
  Scaleform::Render::Matrix3x4<float> m1; // [rsp+A8h] [rbp-50h] BYREF
  Scaleform::Render::Matrix3x4<float> m2; // [rsp+D8h] [rbp-20h] BYREF
  Scaleform::Render::Matrix3x4<float> v42; // [rsp+108h] [rbp+10h] BYREF
  Scaleform::Render::Matrix3x4<float> v43; // [rsp+138h] [rbp+40h] BYREF
  Scaleform::Render::Matrix3x4<float> v44; // [rsp+168h] [rbp+70h] BYREF
  Scaleform::Render::Matrix3x4<float> v45; // [rsp+198h] [rbp+A0h] BYREF
  void *retaddr; // [rsp+238h] [rbp+140h]
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v47; // [rsp+240h] [rbp+148h]

  pGeomData = this->pGeomData;
  memset(&Dst, 0, sizeof(Dst));
  v2 = _mm_cvtsi32_si128(pGeomData->X);
  v3 = _mm_cvtsi32_si128(pGeomData->Y);
  Z = pGeomData->Z;
  v47 = pGeomData;
  v31 = Dst.M[0][2];
  *(float *)&Z = Z;
  v33 = Dst.M[1][0];
  v35 = Dst.M[1][2];
  v37 = *(_QWORD *)&Dst.M[2][0];
  v32 = _mm_cvtepi32_ps(v2).m128_u32[0];
  v34 = (int)FLOAT_1_0;
  v36 = _mm_cvtepi32_ps(v3).m128_u32[0];
  v38 = (int)FLOAT_1_0;
  v39 = LODWORD(Z);
  memset(&Dst, 0, sizeof(Dst));
  v2.m128i_i64[0] = *(_QWORD *)&pGeomData->YScale;
  v5 = Scaleform::Render::Matrix3x4<float>::Identity.M[2][2];
  v6 = Scaleform::Render::Matrix3x4<float>::Identity.M[2][1];
  v3.m128i_i64[0] = *(_QWORD *)&pGeomData->ZScale;
  XScale = pGeomData->XScale;
  m2.M[0][0] = XScale * 0.0099999998;
  m2.M[1][0] = Dst.M[1][0];
  *(_QWORD *)&m2.M[0][1] = *(_QWORD *)&Dst.M[0][1];
  m2.M[0][3] = Dst.M[0][3];
  *(_QWORD *)&m2.M[1][2] = *(_QWORD *)&Dst.M[1][2];
  *(_QWORD *)&m2.M[2][0] = *(_QWORD *)&Dst.M[2][0];
  m2.M[1][1] = (float)*(double *)v2.m128i_i64 * 0.0099999998;
  m2.M[2][3] = Dst.M[2][3];
  m2.M[2][2] = (float)*(double *)v3.m128i_i64 * 0.0099999998;
  XRotation = pGeomData->XRotation;
  v9 = Scaleform::Render::Matrix3x4<float>::Identity.M[2][3];
  v10 = Scaleform::Render::Matrix3x4<float>::Identity.M[2][0];
  v11 = Scaleform::Render::Matrix3x4<float>::Identity.M[1][3];
  v12 = Scaleform::Render::Matrix3x4<float>::Identity.M[1][2];
  v13 = Scaleform::Render::Matrix3x4<float>::Identity.M[1][1];
  if ( XRotation == 0.0 )
  {
    v20 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][0];
    v19 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][1];
    v18 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][2];
    v17 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][3];
    v16 = Scaleform::Render::Matrix3x4<float>::Identity.M[1][0];
    v29 = Scaleform::Render::Matrix3x4<float>::Identity;
    p_Dst = &v29;
  }
  else
  {
    v14 = XRotation * 3.141592653589793 * 0.005555555555555556;
    memset(&Dst, 0, sizeof(Dst));
    cosf(v14);
    v15 = sinf(v14);
    v16 = Scaleform::Render::Matrix3x4<float>::Identity.M[1][0];
    v17 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][3];
    Dst.M[1][1] = v14;
    *(_QWORD *)&Dst.M[2][1] = __PAIR64__(LODWORD(v14), LODWORD(v15));
    v18 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][2];
    v19 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][1];
    v20 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][0];
    LODWORD(Dst.M[1][2]) = LODWORD(v14) ^ _xmm[0];
    *(_QWORD *)&Dst.M[0][0] = 1065353216i64;
    Dst.M[1][0] = 0.0;
    Dst.M[2][0] = 0.0;
    Dst.M[0][2] = 0.0;
    p_Dst = &Dst;
  }
  m1 = *p_Dst;
  YRotation = v47->YRotation;
  if ( YRotation == 0.0 )
  {
    *(_QWORD *)&v29.M[0][0] = __PAIR64__(LODWORD(v19), LODWORD(v20));
    *(_QWORD *)&v29.M[0][2] = __PAIR64__(LODWORD(v17), LODWORD(v18));
    *(_QWORD *)&v29.M[1][0] = __PAIR64__(LODWORD(v13), LODWORD(v16));
    *(_QWORD *)&v29.M[1][2] = __PAIR64__(LODWORD(v11), LODWORD(v12));
    *(_QWORD *)&v29.M[2][0] = __PAIR64__(LODWORD(v6), LODWORD(v10));
    *(_QWORD *)&v29.M[2][2] = __PAIR64__(LODWORD(v9), LODWORD(v5));
    v25 = &v29;
  }
  else
  {
    v23 = YRotation * 3.141592653589793 * 0.005555555555555556;
    memset(&Dst, 0, sizeof(Dst));
    cosf(v23);
    v24 = sinf(v23);
    v16 = Scaleform::Render::Matrix3x4<float>::Identity.M[1][0];
    v17 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][3];
    *(_QWORD *)&Dst.M[0][0] = LODWORD(v23);
    Dst.M[2][2] = v23;
    Dst.M[0][2] = v24;
    v18 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][2];
    v19 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][1];
    v20 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][0];
    *(_QWORD *)&Dst.M[2][0] = (unsigned int)(LODWORD(v23) ^ _xmm[0]);
    Dst.M[1][0] = 0.0;
    *(_QWORD *)&Dst.M[1][1] = 1065353216i64;
    v25 = &Dst;
  }
  v42 = *v25;
  Rotation = v47->Rotation;
  if ( Rotation == 0.0 )
  {
    *(_QWORD *)&v29.M[0][0] = __PAIR64__(LODWORD(v19), LODWORD(v20));
    *(_QWORD *)&v29.M[0][2] = __PAIR64__(LODWORD(v17), LODWORD(v18));
    *(_QWORD *)&v29.M[1][0] = __PAIR64__(LODWORD(v13), LODWORD(v16));
    *(_QWORD *)&v29.M[1][2] = __PAIR64__(LODWORD(v11), LODWORD(v12));
    *(_QWORD *)&v29.M[2][0] = __PAIR64__(LODWORD(v6), LODWORD(v10));
    *(_QWORD *)&v29.M[2][2] = __PAIR64__(LODWORD(v9), LODWORD(v5));
  }
  else
  {
    v27 = Rotation * 3.141592653589793 * 0.005555555555555556;
    memset(&v29, 0, sizeof(v29));
    cosf(v27);
    v28 = sinf(v27);
    v29.M[0][0] = v27;
    *(_QWORD *)&v29.M[1][1] = LODWORD(v27);
    *(_QWORD *)&v29.M[2][0] = 0i64;
    v29.M[1][0] = v28;
    v29.M[2][2] = 1.0;
    *(_QWORD *)&v29.M[0][1] = (unsigned int)(LODWORD(v27) ^ _xmm[0]);
  }
  Dst = v29;
  Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&v43, &m1, &m2);
  Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&v44, &Dst, &v42);
  Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&v45, &v44, &v43);
  Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&v29, (Scaleform::Render::Matrix3x4<float> *)&Dst.M[2][2], &v45);
  if ( Scaleform::Render::Matrix3x4<float>::IsValid(&v29) )
    (*(void (__fastcall **)(void *, Scaleform::Render::Matrix3x4<float> *))(*(_QWORD *)retaddr + 40i64))(retaddr, &v29);
}

// File Line: 1483
// RVA: 0x908060
Scaleform::Ptr<Scaleform::Render::TreeNode> *__fastcall Scaleform::GFx::DisplayObjectBase::SetIndirectTransform(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Ptr<Scaleform::Render::TreeNode> *result,
        Scaleform::Render::TreeNode *newParent)
{
  Scaleform::Render::TreeNode *RenderNode; // rax
  Scaleform::Render::TreeNode *v7; // rdi
  Scaleform::Render::TreeNode *pParent; // rbp
  Scaleform::GFx::DisplayObjContainer *v9; // rbx
  Scaleform::GFx::InteractiveObject *v10; // rcx
  unsigned __int64 v11; // r8
  unsigned __int64 Size; // rcx
  Scaleform::GFx::DisplayObjectBase **p_pCharacter; // rax
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *v14; // rax
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *v15; // rbx
  _DWORD *v16; // r8
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *pIndXFormData; // rcx
  int v20; // [rsp+80h] [rbp+18h] BYREF
  Scaleform::Render::TreeNode *v21; // [rsp+88h] [rbp+20h]

  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  v7 = RenderNode;
  if ( RenderNode )
    ++RenderNode->RefCount;
  v21 = RenderNode;
  pParent = (Scaleform::Render::TreeNode *)RenderNode->pParent;
  Scaleform::Render::TreeNode::SetOrigScale9Parent(RenderNode, pParent);
  if ( newParent )
  {
    while ( newParent != v7 )
    {
      newParent = (Scaleform::Render::TreeNode *)newParent->pParent;
      if ( !newParent )
        goto LABEL_8;
    }
    result->pObject = 0i64;
  }
  else
  {
LABEL_8:
    v9 = 0i64;
    v10 = this->pParent;
    if ( v10 )
    {
      if ( (v10->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x200) != 0 )
        v9 = (Scaleform::GFx::DisplayObjContainer *)this->pParent;
      if ( v9 )
      {
        v11 = 0i64;
        Size = v9->mDisplayList.DisplayObjectArray.Data.Size;
        if ( Size )
        {
          p_pCharacter = &v9->mDisplayList.DisplayObjectArray.Data.Data->pCharacter;
          while ( *p_pCharacter != this )
          {
            ++v11;
            p_pCharacter += 2;
            if ( v11 >= Size )
              goto LABEL_16;
          }
        }
        else
        {
LABEL_16:
          v11 = -1i64;
        }
        Scaleform::GFx::DisplayList::RemoveFromRenderTree(&v9->mDisplayList, v9, v11);
      }
    }
    Scaleform::GFx::MovieImpl::AddIndirectTransformPair(this->pASRoot->pMovieImpl, v9, pParent, this);
    if ( !this->pIndXFormData )
    {
      v20 = 322;
      v14 = (Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::DisplayObjectBase *, __int64, int *, _DWORD, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                                              Scaleform::Memory::pGlobalHeap,
                                                                              this,
                                                                              64i64,
                                                                              &v20,
                                                                              0,
                                                                              -2i64);
      v15 = v14;
      if ( v14 )
      {
        memset(v14, 0, 0x30ui64);
        v15->OrigTransformMatrix.M[0][0] = 1.0;
        v15->OrigTransformMatrix.M[1][1] = 1.0;
        v15->OrigTransformMatrix.M[2][2] = 1.0;
      }
      else
      {
        v15 = 0i64;
      }
      this->pIndXFormData = v15;
    }
    v16 = *(_DWORD **)(*(_QWORD *)(((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                     + 8i64 * (unsigned int)((int)((_DWORD)v7 - ((unsigned int)v7 & 0xFFFFF000) - 56) / 56)
                     + 40);
    pIndXFormData = this->pIndXFormData;
    pIndXFormData->OrigTransformMatrix.M[0][0] = (float)v16[4];
    pIndXFormData->OrigTransformMatrix.M[0][1] = (float)v16[5];
    pIndXFormData->OrigTransformMatrix.M[0][2] = (float)v16[6];
    pIndXFormData->OrigTransformMatrix.M[0][3] = (float)v16[7];
    pIndXFormData->OrigTransformMatrix.M[1][0] = (float)v16[8];
    pIndXFormData->OrigTransformMatrix.M[1][1] = (float)v16[9];
    pIndXFormData->OrigTransformMatrix.M[1][2] = (float)v16[10];
    pIndXFormData->OrigTransformMatrix.M[1][3] = (float)v16[11];
    pIndXFormData->OrigTransformMatrix.M[2][0] = (float)v16[12];
    pIndXFormData->OrigTransformMatrix.M[2][1] = (float)v16[13];
    pIndXFormData->OrigTransformMatrix.M[2][2] = (float)v16[14];
    pIndXFormData->OrigTransformMatrix.M[2][3] = (float)v16[15];
    this->pIndXFormData->IsOrig3D = (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64)
                                                                      + 0x20)
                                                          + 8i64
                                                          * (unsigned int)((int)((_DWORD)v7
                                                                               - ((unsigned int)v7 & 0xFFFFF000)
                                                                               - 56)
                                                                         / 56)
                                                          + 40)
                                              + 10i64) & 0x200) != 0;
    this->Flags |= 0x8000u;
    ++v7->RefCount;
    result->pObject = v7;
  }
  if ( v7->RefCount-- == 1 )
    Scaleform::Render::ContextImpl::Entry::destroyHelper(v7);
  return result;
}

// File Line: 1523
// RVA: 0x8FF8A0
void __fastcall Scaleform::GFx::DisplayObjectBase::RemoveIndirectTransform(
        Scaleform::GFx::DisplayObjectBase *this,
        bool readdToDisplayList)
{
  Scaleform::Render::TreeNode *RenderNode; // rax
  Scaleform::Render::TreeNode *v5; // rdi
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *pIndXFormData; // rdx
  unsigned __int64 v7; // rbx
  unsigned __int64 Size; // rcx
  Scaleform::GFx::DisplayList::DisplayEntry *Data; // rax
  Scaleform::Render::TreeNode *pObject; // rcx
  bool v11; // zf
  Scaleform::GFx::MovieImpl::IndirectTransPair result; // [rsp+28h] [rbp-30h] BYREF

  if ( (this->Flags & 0x8000u) != 0 )
  {
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    v5 = RenderNode;
    if ( RenderNode )
      ++RenderNode->RefCount;
    pIndXFormData = this->pIndXFormData;
    if ( pIndXFormData->IsOrig3D )
    {
      Scaleform::Render::TreeNode::SetMatrix3D(RenderNode, &pIndXFormData->OrigTransformMatrix);
    }
    else
    {
      Scaleform::Render::TreeNode::Clear3D(RenderNode);
      Scaleform::Render::TreeNode::SetMatrix(v5, (Scaleform::Render::Matrix2x4<float> *)this->pIndXFormData);
    }
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->pIndXFormData);
    v7 = 0i64;
    this->pIndXFormData = 0i64;
    this->Flags &= ~0x8000u;
    Scaleform::GFx::MovieImpl::RemoveIndirectTransformPair(this->pASRoot->pMovieImpl, &result, this);
    if ( readdToDisplayList )
    {
      if ( result.OriginalParent.pObject )
      {
        Size = result.OriginalParent.pObject->mDisplayList.DisplayObjectArray.Data.Size;
        if ( Size )
        {
          Data = result.OriginalParent.pObject->mDisplayList.DisplayObjectArray.Data.Data;
          while ( Data->pCharacter != this )
          {
            ++v7;
            ++Data;
            if ( v7 >= Size )
              goto LABEL_16;
          }
          if ( v7 != -1i64 )
            Scaleform::GFx::DisplayList::InsertIntoRenderTree(
              &result.OriginalParent.pObject->mDisplayList,
              result.OriginalParent.pObject,
              v7);
        }
      }
    }
LABEL_16:
    Scaleform::Render::TreeNode::SetOrigScale9Parent(v5, 0i64);
    if ( result.OriginalParent.pObject )
      Scaleform::RefCountNTSImpl::Release(result.OriginalParent.pObject);
    if ( result.Obj.pObject )
      Scaleform::RefCountNTSImpl::Release(result.Obj.pObject);
    pObject = result.TransformParent.pObject;
    if ( result.TransformParent.pObject )
    {
      v11 = result.TransformParent.pObject->RefCount-- == 1;
      if ( v11 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(pObject);
    }
    if ( v5 )
    {
      v11 = v5->RefCount-- == 1;
      if ( v11 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v5);
    }
  }
}

// File Line: 1559
// RVA: 0x90B6D0
void __fastcall Scaleform::GFx::DisplayObjectBase::SetScale9Grid(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Rect<float> *gr)
{
  Scaleform::Render::TreeNode *RenderNode; // rax

  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeNode::SetScale9Grid(RenderNode, gr);
}

// File Line: 1565
// RVA: 0x8DDEA0
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::DisplayObjectBase::GetScale9Grid(
        Scaleform::GFx::DisplayObjectBase *this,
        Scaleform::Render::Rect<float> *result)
{
  Scaleform::Render::TreeNode *RenderNode; // rax

  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeNode::GetScale9Grid(RenderNode, result);
  return result;
}

// File Line: 1570
// RVA: 0x8C36C0
void __fastcall Scaleform::GFx::DisplayObjectBase::CreateScale9Grid(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::InteractiveObject *pParent; // rbx
  Scaleform::Render::TreeNode *RenderNode; // rax
  Scaleform::Render::State *State; // rax
  float *pData; // rax
  float v6; // xmm3_4
  unsigned int v7; // xmm2_4
  unsigned int v8; // xmm1_4
  Scaleform::Render::Rect<float> *p_s9Rect; // rax
  Scaleform::Render::Matrix2x4<float> *v10; // rax
  Scaleform::Render::Scale9GridInfo *v11; // rdi
  Scaleform::Render::TreeNode *v12; // rax
  Scaleform::Render::State *v13; // rax
  float *v14; // rax
  float v15; // xmm3_4
  unsigned int v16; // xmm2_4
  unsigned int v17; // xmm1_4
  Scaleform::Render::Matrix2x4<float> *v18; // rax
  Scaleform::Render::Rect<float> v19; // [rsp+40h] [rbp-19h] BYREF
  Scaleform::Render::Rect<float> s9Rect; // [rsp+50h] [rbp-9h] BYREF
  __m128 v21; // [rsp+60h] [rbp+7h]
  Scaleform::Render::Rect<float> bounds; // [rsp+70h] [rbp+17h] BYREF
  Scaleform::Render::Matrix2x4<float> shapeMtx; // [rsp+80h] [rbp+27h] BYREF
  int v24; // [rsp+C8h] [rbp+6Fh] BYREF
  Scaleform::Render::Scale9GridInfo *v25; // [rsp+D0h] [rbp+77h]

  pParent = this->pParent;
  shapeMtx = *(Scaleform::Render::Matrix2x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))this->Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(this);
  while ( pParent )
  {
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(pParent);
    State = Scaleform::Render::TreeNode::GetState(RenderNode, State_Scale9);
    if ( State )
    {
      pData = (float *)State->pData;
      v6 = pData[7];
      v7 = *((_DWORD *)pData + 6);
      v8 = *((_DWORD *)pData + 5);
      v19.x1 = pData[4];
      *(_QWORD *)&v19.y1 = __PAIR64__(v7, v8);
      v19.y2 = v6;
      p_s9Rect = &v19;
    }
    else
    {
      s9Rect = 0i64;
      p_s9Rect = &s9Rect;
    }
    if ( p_s9Rect->x1 < p_s9Rect->x2 && p_s9Rect->y1 < p_s9Rect->y2 )
    {
      s9Rect = (Scaleform::Render::Rect<float>)_xmm;
      v21 = _xmm;
      ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::Render::Rect<float> *, Scaleform::Render::Rect<float> *))pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[62].__vecDelDtor)(
        pParent,
        &bounds,
        &s9Rect);
      v24 = 71;
      v11 = (Scaleform::Render::Scale9GridInfo *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   this,
                                                   448i64,
                                                   &v24);
      v25 = v11;
      if ( v11 )
      {
        v12 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(pParent);
        v13 = Scaleform::Render::TreeNode::GetState(v12, State_Scale9);
        if ( v13 )
        {
          v14 = (float *)v13->pData;
          v15 = v14[7];
          v16 = *((_DWORD *)v14 + 6);
          v17 = *((_DWORD *)v14 + 5);
          v19.x1 = v14[4];
          *(_QWORD *)&v19.y1 = __PAIR64__(v16, v17);
          v19.y2 = v15;
        }
        else
        {
          v19 = 0i64;
        }
        s9Rect = v19;
        v18 = (Scaleform::Render::Matrix2x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(pParent);
        Scaleform::Render::Scale9GridInfo::Scale9GridInfo(v11, &s9Rect, v18, &shapeMtx, &bounds);
      }
      return;
    }
    v10 = (Scaleform::Render::Matrix2x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[2].__vecDelDtor)(pParent);
    Scaleform::Render::Matrix2x4<float>::Append(&shapeMtx, v10);
    pParent = pParent->pParent;
  }
}

// File Line: 1589
// RVA: 0x90AE50
void __fastcall Scaleform::GFx::DisplayObjectBase::SetRendererString(
        Scaleform::GFx::DisplayObjectBase *this,
        const char *str)
{
  Scaleform::Render::TreeNode *RenderNode; // rax
  Scaleform::Render::ContextImpl::Entry *v4; // rbx

  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  v4 = RenderNode;
  if ( RenderNode )
    ++RenderNode->RefCount;
  Scaleform::Render::TreeNode::SetRendererString(RenderNode, str);
  if ( v4 )
  {
    if ( v4->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v4);
  }
}

// File Line: 1595
// RVA: 0x90ADF0
void __fastcall Scaleform::GFx::DisplayObjectBase::SetRendererFloat(Scaleform::GFx::DisplayObjectBase *this, float fl)
{
  Scaleform::Render::TreeNode *RenderNode; // rax
  Scaleform::Render::ContextImpl::Entry *v3; // rbx

  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  v3 = RenderNode;
  if ( RenderNode )
    ++RenderNode->RefCount;
  Scaleform::Render::TreeNode::SetRendererFloat(RenderNode, fl);
  if ( v3 )
  {
    if ( v3->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v3);
  }
}

// File Line: 1601
// RVA: 0x8DD7A0
const char *__fastcall Scaleform::GFx::DisplayObjectBase::GetRendererString(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode *RenderNode; // rax
  Scaleform::Render::ContextImpl::Entry *v2; // rbx
  const char *result; // rax
  const char *v4; // rdi

  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  v2 = RenderNode;
  if ( RenderNode )
    ++RenderNode->RefCount;
  result = Scaleform::Render::TreeNode::GetRendererString(RenderNode);
  v4 = result;
  if ( v2 )
  {
    if ( v2->RefCount-- == 1 )
    {
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v2);
      return v4;
    }
  }
  return result;
}

// File Line: 1607
// RVA: 0x8DD740
float __fastcall Scaleform::GFx::DisplayObjectBase::GetRendererFloat(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode *RenderNode; // rax
  Scaleform::Render::ContextImpl::Entry *v2; // rbx
  float result; // xmm0_4

  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  v2 = RenderNode;
  if ( RenderNode )
    ++RenderNode->RefCount;
  result = Scaleform::Render::TreeNode::GetRendererFloat(RenderNode);
  if ( v2 )
  {
    if ( v2->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v2);
  }
  return result;
}

// File Line: 1613
// RVA: 0x8C7510
void __fastcall Scaleform::GFx::DisplayObjectBase::DisableBatching(Scaleform::GFx::DisplayObjectBase *this, bool b)
{
  Scaleform::Render::TreeNode *RenderNode; // rax
  Scaleform::Render::ContextImpl::Entry *v4; // rbx

  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  v4 = RenderNode;
  if ( RenderNode )
    ++RenderNode->RefCount;
  Scaleform::Render::TreeNode::DisableBatching(RenderNode, b);
  if ( v4 )
  {
    if ( v4->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v4);
  }
}

// File Line: 1619
// RVA: 0x8E6EB0
_BOOL8 __fastcall Scaleform::GFx::DisplayObjectBase::IsBatchingDisabled(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode *RenderNode; // rax
  Scaleform::Render::ContextImpl::Entry *v2; // rbx
  bool IsBatchingDisabled; // di

  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  v2 = RenderNode;
  if ( RenderNode )
    ++RenderNode->RefCount;
  IsBatchingDisabled = Scaleform::Render::TreeNode::IsBatchingDisabled(RenderNode);
  if ( v2 )
  {
    if ( v2->RefCount-- == 1 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v2);
  }
  return IsBatchingDisabled;
}

// File Line: 1631
// RVA: 0x895560
void __fastcall Scaleform::GFx::DisplayObject::DisplayObject(
        Scaleform::GFx::DisplayObject *this,
        Scaleform::GFx::ASMovieRootBase *pasRoot,
        Scaleform::GFx::InteractiveObject *pparent,
        unsigned int *id)
{
  Scaleform::GFx::ResourceId ida; // [rsp+58h] [rbp+20h] BYREF

  ida.Id = *id;
  Scaleform::GFx::DisplayObjectBase::DisplayObjectBase(this, pasRoot, pparent, (Scaleform::GFx::ResourceId)&ida);
  this->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::DisplayObject::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  this->Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::DisplayObject::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  this->pNameHandle.pObject = 0i64;
  this->pScrollRect = 0i64;
  this->pMaskCharacter = 0i64;
  this->Scaleform::GFx::DisplayObjectBase::Flags |= 0x100u;
  this->Flags = 10;
}

// File Line: 1640
// RVA: 0x8A3CD0
void __fastcall Scaleform::GFx::DisplayObject::~DisplayObject(Scaleform::GFx::DisplayObject *this)
{
  Scaleform::GFx::DisplayObject::ScrollRectInfo *pScrollRect; // rdi
  Scaleform::RefCountNTSImpl *pObject; // rcx
  Scaleform::GFx::DisplayObject *pMaskCharacter; // rcx
  Scaleform::GFx::CharacterHandle *v5; // rax
  Scaleform::GFx::CharacterHandle *v6; // rdi
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v8; // zf
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::GFx::ASStringNode *v10; // rcx

  this->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::DisplayObject::`vftable{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>};
  this->Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::DisplayObject::`vftable{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>};
  pScrollRect = this->pScrollRect;
  if ( pScrollRect )
  {
    pObject = pScrollRect->Mask.pObject;
    if ( pObject )
      Scaleform::RefCountNTSImpl::Release(pObject);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pScrollRect);
  }
  if ( this->pMaskCharacter )
  {
    if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *))this->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[78].__vecDelDtor)(this) )
    {
      if ( !this->pMaskCharacter )
        goto LABEL_13;
      Scaleform::GFx::DisplayObject::SetMask(this, 0i64, this->ClipDepth != 0);
    }
    if ( this->pMaskCharacter )
    {
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *))this->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[78].__vecDelDtor)(this) )
      {
        pMaskCharacter = this->pMaskCharacter;
        if ( pMaskCharacter )
          Scaleform::GFx::DisplayObject::SetMask(pMaskCharacter, 0i64, 1);
      }
    }
  }
LABEL_13:
  v5 = this->pNameHandle.pObject;
  if ( v5 )
    v5->pCharacter = 0i64;
  v6 = this->pNameHandle.pObject;
  if ( v6 )
  {
    if ( --v6->RefCount <= 0 )
    {
      pNode = v6->OriginalName.pNode;
      v8 = pNode->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
      v9 = v6->NamePath.pNode;
      v8 = v9->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v9);
      v10 = v6->Name.pNode;
      v8 = v10->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v10);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v6);
    }
  }
  Scaleform::GFx::DisplayObjectBase::~DisplayObjectBase(this);
}

// File Line: 1657
// RVA: 0x8EC730
void __fastcall Scaleform::GFx::InteractiveObject::OnEventLoad(Scaleform::GFx::InteractiveObject *this)
{
  unsigned __int8 AvmObjOffset; // al

  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags |= 0x2000u;
  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
    ((void (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                          + 4 * AvmObjOffset))[9].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
}

// File Line: 1664
// RVA: 0x8EC8F0
void __fastcall Scaleform::GFx::DisplayObject::OnEventUnload(Scaleform::GFx::DisplayObject *this)
{
  Scaleform::GFx::CharacterHandle *pObject; // rax
  unsigned __int8 AvmObjOffset; // al

  Scaleform::GFx::DisplayObjectBase::OnEventUnload(this);
  pObject = this->pNameHandle.pObject;
  if ( pObject )
    pObject->pCharacter = 0i64;
  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
    ((void (__fastcall *)(char *))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                                          + 4 * AvmObjOffset))[10].__vecDelDtor)((char *)this + 4 * AvmObjOffset);
}

// File Line: 1674
// RVA: 0x8C26F0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::DisplayObject::CreateNewInstanceName(
        Scaleform::GFx::DisplayObject *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v3; // rax
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASStringNode *v5; // rcx
  Scaleform::GFx::ASString resulta; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::GFx::ASString *v9; // [rsp+48h] [rbp+10h]

  v9 = result;
  v3 = Scaleform::GFx::MovieImpl::CreateNewInstanceName(this->pASRoot->pMovieImpl, &resulta);
  pNode = v3->pNode;
  result->pNode = v3->pNode;
  ++pNode->RefCount;
  v5 = resulta.pNode;
  if ( resulta.pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  return result;
}

// File Line: 1680
// RVA: 0x8BE8C0
Scaleform::GFx::CharacterHandle *__fastcall Scaleform::GFx::DisplayObject::CreateCharacterHandle(
        Scaleform::GFx::DisplayObject *this)
{
  Scaleform::GFx::CharacterHandle *v2; // rbp
  char v3; // si
  Scaleform::GFx::MovieImpl *pMovieImpl; // rbx
  Scaleform::GFx::CharacterHandle *v5; // r14
  Scaleform::GFx::ASStringManager *v6; // rax
  Scaleform::GFx::ASString *v7; // rbx
  Scaleform::GFx::ASStringNode *v8; // rcx
  Scaleform::GFx::ASStringNode *v9; // rax
  Scaleform::GFx::CharacterHandle *v10; // rbx
  Scaleform::GFx::ASStringNode *v11; // rcx
  bool v12; // zf
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASStringNode *v15; // rcx
  __int64 v16; // rcx
  Scaleform::GFx::CharacterHandle *v17; // rax
  Scaleform::GFx::CharacterHandle *v18; // rax
  Scaleform::GFx::CharacterHandle *pObject; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::ASString name; // [rsp+60h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+68h] [rbp+10h] BYREF
  void *pHeap; // [rsp+70h] [rbp+18h]
  Scaleform::GFx::CharacterHandle *v27; // [rsp+78h] [rbp+20h]

  v2 = 0i64;
  v3 = 0;
  if ( this->pNameHandle.pObject )
    return this->pNameHandle.pObject;
  pMovieImpl = this->pASRoot->pMovieImpl;
  if ( (this->Scaleform::GFx::DisplayObjectBase::Flags & 0x10) == 0 )
  {
    this->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[82].__vecDelDtor(
      this,
      (unsigned int)&name);
    result.pNode = (Scaleform::GFx::ASStringNode *)pMovieImpl->pHeap;
    v17 = (Scaleform::GFx::CharacterHandle *)(*((__int64 (__fastcall **)(__int64, __int64))result.pNode->pData + 10))(
                                               v16,
                                               40i64);
    pHeap = v17;
    if ( v17 )
    {
      Scaleform::GFx::CharacterHandle::CharacterHandle(v17, &name, this->pParent, this);
      v2 = v18;
    }
    pObject = this->pNameHandle.pObject;
    if ( pObject )
    {
      if ( --pObject->RefCount <= 0 )
      {
        result.pNode = (Scaleform::GFx::ASStringNode *)pObject;
        pNode = pObject->OriginalName.pNode;
        v12 = pNode->RefCount-- == 1;
        if ( v12 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        v21 = pObject->NamePath.pNode;
        v12 = v21->RefCount-- == 1;
        if ( v12 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v21);
        v22 = pObject->Name.pNode;
        v12 = v22->RefCount-- == 1;
        if ( v12 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v22);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, pObject);
      }
    }
    this->pNameHandle.pObject = v2;
    v15 = name.pNode;
    goto LABEL_29;
  }
  pHeap = pMovieImpl->pHeap;
  v5 = (Scaleform::GFx::CharacterHandle *)(*(__int64 (__fastcall **)(Scaleform::GFx::DisplayObject *, __int64, _QWORD))(*(_QWORD *)pHeap + 80i64))(
                                            this,
                                            40i64,
                                            0i64);
  v27 = v5;
  if ( v5 )
  {
    v6 = (Scaleform::GFx::ASStringManager *)((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))pMovieImpl->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[59].__vecDelDtor)(pMovieImpl->pASMovieRoot.pObject);
    v7 = Scaleform::GFx::ASStringManager::CreateEmptyString(v6, &result);
    v3 = 1;
    v8 = v7->pNode;
    v5->Name = (Scaleform::GFx::ASString)v7->pNode;
    ++v8->RefCount;
    Scaleform::GFx::ASStringManager::CreateEmptyString(v7->pNode->pManager, &v5->NamePath);
    v9 = v7->pNode;
    v5->OriginalName = (Scaleform::GFx::ASString)v7->pNode;
    ++v9->RefCount;
    v5->RefCount = 1;
    v5->pCharacter = 0i64;
  }
  else
  {
    v5 = 0i64;
  }
  v10 = this->pNameHandle.pObject;
  if ( v10 )
  {
    if ( --v10->RefCount <= 0 )
    {
      pHeap = v10;
      v11 = v10->OriginalName.pNode;
      v12 = v11->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v11);
      v13 = v10->NamePath.pNode;
      v12 = v13->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v13);
      v14 = v10->Name.pNode;
      v12 = v14->RefCount-- == 1;
      if ( v12 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v10);
    }
  }
  this->pNameHandle.pObject = v5;
  if ( (v3 & 1) != 0 )
  {
    v15 = result.pNode;
LABEL_29:
    v12 = v15->RefCount-- == 1;
    if ( v12 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v15);
  }
  return this->pNameHandle.pObject;
}

// File Line: 1707
// RVA: 0x8DB270
double __fastcall Scaleform::GFx::DisplayObject::GetMouseX(Scaleform::GFx::DisplayObject *this)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // rdx
  float x; // xmm4_4
  float v3; // xmm0_4
  float x2; // xmm1_4
  float v5; // xmm5_4
  float y2; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm5_4
  float v9; // xmm0_4
  __m128d v10; // xmm0
  int v11; // ecx
  Scaleform::Render::Point<float> pt; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::Render::Point<float> p; // [rsp+48h] [rbp+10h] BYREF

  pMovieImpl = this->pASRoot->pMovieImpl;
  x = pMovieImpl->mMouseState[0].LastPosition.x;
  v3 = pMovieImpl->ViewOffsetY * 20.0;
  x2 = pMovieImpl->VisibleFrameRect.x2;
  pt.y = pMovieImpl->mMouseState[0].LastPosition.y;
  v5 = pt.y - v3;
  y2 = pMovieImpl->VisibleFrameRect.y2;
  v7 = x2 - pMovieImpl->VisibleFrameRect.x1;
  pt.x = x;
  v8 = v5 / (float)(y2 - pMovieImpl->VisibleFrameRect.y1);
  v9 = pMovieImpl->ViewOffsetX * 20.0;
  LODWORD(pMovieImpl->ScreenToWorld.Sy) = COERCE_UNSIGNED_INT((float)(v8 * 2.0) - 1.0) ^ _xmm[0];
  pMovieImpl->ScreenToWorld.Sx = (float)((float)((float)(x - v9) / v7) * 2.0) - 1.0;
  Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(this, &p, &pt, 0, 0i64);
  v10 = _mm_cvtps_pd((__m128)LODWORD(p.x));
  v10.m128d_f64[0] = v10.m128d_f64[0] + 0.5;
  v11 = (int)v10.m128d_f64[0];
  if ( (double)v11 != v10.m128d_f64[0] )
    v10.m128d_f64[0] = (double)(v11 - (_mm_movemask_pd(_mm_unpacklo_pd(v10, v10)) & 1));
  return v10.m128d_f64[0] * 0.05;
}

// File Line: 1716
// RVA: 0x8DB3A0
double __fastcall Scaleform::GFx::DisplayObject::GetMouseY(Scaleform::GFx::DisplayObject *this)
{
  Scaleform::GFx::MovieImpl *pMovieImpl; // rdx
  float x; // xmm4_4
  float v3; // xmm0_4
  float x2; // xmm1_4
  float v5; // xmm5_4
  float y2; // xmm0_4
  float v7; // xmm1_4
  float v8; // xmm5_4
  float v9; // xmm0_4
  __m128d v10; // xmm0
  int v11; // ecx
  Scaleform::Render::Point<float> pt; // [rsp+40h] [rbp+8h] BYREF
  Scaleform::Render::Point<float> p; // [rsp+48h] [rbp+10h] BYREF

  pMovieImpl = this->pASRoot->pMovieImpl;
  x = pMovieImpl->mMouseState[0].LastPosition.x;
  v3 = pMovieImpl->ViewOffsetY * 20.0;
  x2 = pMovieImpl->VisibleFrameRect.x2;
  pt.y = pMovieImpl->mMouseState[0].LastPosition.y;
  v5 = pt.y - v3;
  y2 = pMovieImpl->VisibleFrameRect.y2;
  v7 = x2 - pMovieImpl->VisibleFrameRect.x1;
  pt.x = x;
  v8 = v5 / (float)(y2 - pMovieImpl->VisibleFrameRect.y1);
  v9 = pMovieImpl->ViewOffsetX * 20.0;
  LODWORD(pMovieImpl->ScreenToWorld.Sy) = COERCE_UNSIGNED_INT((float)(v8 * 2.0) - 1.0) ^ _xmm[0];
  pMovieImpl->ScreenToWorld.Sx = (float)((float)((float)(x - v9) / v7) * 2.0) - 1.0;
  Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(this, &p, &pt, 0, 0i64);
  v10 = _mm_cvtps_pd((__m128)LODWORD(p.y));
  v10.m128d_f64[0] = v10.m128d_f64[0] + 0.5;
  v11 = (int)v10.m128d_f64[0];
  if ( (double)v11 != v10.m128d_f64[0] )
    v10.m128d_f64[0] = (double)(v11 - (_mm_movemask_pd(_mm_unpacklo_pd(v10, v10)) & 1));
  return v10.m128d_f64[0] * 0.05;
}

// File Line: 1725
// RVA: 0x909A10
void __fastcall Scaleform::GFx::DisplayObject::SetName(
        Scaleform::GFx::DisplayObject *this,
        Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::CharacterHandle *pObject; // rcx
  Scaleform::GFx::CharacterHandle *v5; // rax
  Scaleform::GFx::CharacterHandle *v6; // rax
  Scaleform::GFx::CharacterHandle *v7; // rsi
  Scaleform::GFx::CharacterHandle *v8; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v10; // zf
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::ASStringNode *v12; // rcx
  int v13; // [rsp+58h] [rbp+10h] BYREF
  Scaleform::GFx::CharacterHandle *v14; // [rsp+60h] [rbp+18h]

  if ( name->pNode->Size )
    this->Flags &= ~2u;
  pObject = this->pNameHandle.pObject;
  if ( pObject )
  {
    Scaleform::GFx::CharacterHandle::ChangeName(pObject, name, this->pParent);
  }
  else
  {
    v13 = 322;
    v5 = (Scaleform::GFx::CharacterHandle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::DisplayObject *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                              Scaleform::Memory::pGlobalHeap,
                                              this,
                                              40i64,
                                              &v13,
                                              -2i64);
    v14 = v5;
    if ( v5 )
    {
      Scaleform::GFx::CharacterHandle::CharacterHandle(v5, name, this->pParent, this);
      v7 = v6;
    }
    else
    {
      v7 = 0i64;
    }
    v8 = this->pNameHandle.pObject;
    if ( v8 )
    {
      if ( --v8->RefCount <= 0 )
      {
        pNode = v8->OriginalName.pNode;
        v10 = pNode->RefCount-- == 1;
        if ( v10 )
          Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
        v11 = v8->NamePath.pNode;
        v10 = v11->RefCount-- == 1;
        if ( v10 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v11);
        v12 = v8->Name.pNode;
        v10 = v12->RefCount-- == 1;
        if ( v10 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v12);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v8);
      }
    }
    this->pNameHandle.pObject = v7;
  }
}

// File Line: 1742
// RVA: 0x909B50
void __fastcall Scaleform::GFx::DisplayObject::SetOriginalName(
        Scaleform::GFx::DisplayObject *this,
        Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::CharacterHandle *pObject; // rbx
  Scaleform::GFx::ASStringNode *pNode; // rdi
  Scaleform::GFx::ASStringNode *v6; // rcx

  Scaleform::GFx::DisplayObject::SetName(this, name);
  pObject = this->pNameHandle.pObject;
  if ( pObject || (pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(this)) != 0i64 )
  {
    pNode = name->pNode;
    ++name->pNode->RefCount;
    v6 = pObject->OriginalName.pNode;
    if ( v6->RefCount-- == 1 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
    pObject->OriginalName.pNode = pNode;
  }
}

// File Line: 1750
// RVA: 0x8DC030
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::DisplayObject::GetOriginalName(
        Scaleform::GFx::DisplayObject *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::CharacterHandle *pObject; // rax
  Scaleform::GFx::ASStringNode *pNode; // rax

  pObject = this->pNameHandle.pObject;
  if ( pObject || (pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(this)) != 0i64 )
  {
    pNode = pObject->OriginalName.pNode;
    result->pNode = pNode;
    ++pNode->RefCount;
  }
  else
  {
    Scaleform::GFx::DisplayObject::GetName(this, result);
  }
  return result;
}

// File Line: 1758
// RVA: 0x8DB590
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::DisplayObject::GetName(
        Scaleform::GFx::DisplayObject *this,
        Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::CharacterHandle *pObject; // rax
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASMovieRootBase *v6; // rcx
  Scaleform::GFx::ASStringManager *v7; // rax

  pObject = this->pNameHandle.pObject;
  if ( pObject || (pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(this)) != 0i64 )
  {
    pNode = pObject->Name.pNode;
    result->pNode = pNode;
    ++pNode->RefCount;
  }
  else
  {
    v6 = this->pASRoot->pMovieImpl->pASMovieRoot.pObject;
    v7 = (Scaleform::GFx::ASStringManager *)((__int64 (__fastcall *)(Scaleform::GFx::ASMovieRootBase *))v6->vfptr[59].__vecDelDtor)(v6);
    Scaleform::GFx::ASStringManager::CreateEmptyString(v7, result);
  }
  return result;
}

// File Line: 1767
// RVA: 0x8D4BF0
char *__fastcall Scaleform::GFx::DisplayObject::GetAbsolutePath(
        Scaleform::GFx::DisplayObject *this,
        Scaleform::String *ppath)
{
  unsigned __int8 AvmObjOffset; // al

  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
    return (char *)(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                           + 4 * AvmObjOffset))[6].__vecDelDtor(
                     (char *)this + 4 * AvmObjOffset,
                     ppath);
  else
    return &customCaption;
}

// File Line: 1774
// RVA: 0x906080
void __fastcall Scaleform::GFx::DisplayObject::SetAcceptAnimMoves(Scaleform::GFx::DisplayObject *this, bool accept)
{
  Scaleform::GFx::DisplayObjectBase::GeomDataType *GeomData; // rax
  Scaleform::GFx::ASMovieRootBase *pASRoot; // rdx
  Scaleform::GFx::DisplayObjectBase::GeomDataType v6; // [rsp+20h] [rbp-68h] BYREF

  if ( !this->pGeomData )
  {
    *(_QWORD *)&v6.X = 0i64;
    *(_OWORD *)&v6.OrigMatrix.M[0][0] = _xmm;
    *(__m128 *)&v6.OrigMatrix.M[1][0] = _xmm;
    v6.YScale = DOUBLE_100_0;
    v6.XScale = DOUBLE_100_0;
    v6.Rotation = 0.0;
    *(_OWORD *)&v6.XRotation = 0i64;
    *(_OWORD *)&v6.Z = _xmm;
    GeomData = Scaleform::GFx::DisplayObjectBase::GetGeomData(this, &v6);
    Scaleform::GFx::DisplayObjectBase::SetGeomData(this, GeomData);
  }
  if ( accept )
    this->Flags |= 8u;
  else
    this->Flags &= ~8u;
  pASRoot = this->pASRoot;
  if ( (pASRoot->pMovieImpl->Flags & 0x2000) != 0 )
    this->Flags |= 0x10u;
  else
    this->Flags &= ~0x10u;
  if ( (pASRoot->pMovieImpl->Flags & 0x2000) != 0 && accept )
  {
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, this->pGeomData);
    this->pGeomData = 0i64;
  }
}

// File Line: 1800
// RVA: 0x901240
void __fastcall Scaleform::GFx::DisplayObject::ResetClipDepth(Scaleform::GFx::DisplayObject *this)
{
  Scaleform::GFx::InteractiveObject *pParent; // rcx
  Scaleform::GFx::InteractiveObject *v3; // rsi
  unsigned __int64 v4; // rcx
  unsigned __int64 v5; // rbx
  Scaleform::GFx::DisplayObject **vfptr; // rax

  if ( this->ClipDepth )
  {
    pParent = this->pParent;
    if ( !pParent )
      goto LABEL_12;
    v3 = 0i64;
    if ( (pParent->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags & 0x200) != 0 )
      v3 = pParent;
    if ( v3 )
    {
      v4 = *(_QWORD *)&v3[1].RefCount;
      v5 = 0i64;
      if ( v4 )
      {
        vfptr = (Scaleform::GFx::DisplayObject **)v3[1].Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
        while ( *vfptr != this )
        {
          ++v5;
          vfptr += 2;
          if ( v5 >= v4 )
            goto LABEL_10;
        }
      }
      else
      {
LABEL_10:
        v5 = -1i64;
      }
      Scaleform::GFx::DisplayList::RemoveFromRenderTree((Scaleform::GFx::DisplayList *)&v3[1], v3, v5);
      this->ClipDepth = 0;
      Scaleform::GFx::DisplayList::InsertIntoRenderTree((Scaleform::GFx::DisplayList *)&v3[1], v3, v5);
    }
    else
    {
LABEL_12:
      this->ClipDepth = 0;
    }
  }
}

// File Line: 1823
// RVA: 0x908C00
void __fastcall Scaleform::GFx::DisplayObject::SetMask(
        Scaleform::GFx::DisplayObject *this,
        Scaleform::GFx::DisplayObject *pmaskSprite,
        bool readdMaskToDisplayList)
{
  Scaleform::Render::TreeNode *RenderNode; // rax
  Scaleform::Render::TreeNode *v6; // rbp
  Scaleform::GFx::DisplayObject *pMaskCharacter; // rbx
  Scaleform::GFx::DisplayObject *v8; // rcx
  Scaleform::GFx::DisplayObject *v9; // rcx
  Scaleform::Render::TreeNode *pObject; // rbx
  Scaleform::Ptr<Scaleform::Render::TreeNode> *v11; // rax
  Scaleform::Render::TreeNode *v12; // rcx
  bool v13; // zf
  Scaleform::Ptr<Scaleform::Render::TreeNode> result; // [rsp+68h] [rbp+10h] BYREF
  bool v15; // [rsp+70h] [rbp+18h]
  Scaleform::Render::TreeNode *v16; // [rsp+78h] [rbp+20h]

  v15 = readdMaskToDisplayList;
  RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  v6 = RenderNode;
  if ( RenderNode )
    ++RenderNode->RefCount;
  v16 = RenderNode;
  Scaleform::GFx::DisplayObject::ResetClipDepth(this);
  if ( pmaskSprite )
  {
    if ( this->pScrollRect )
      Scaleform::GFx::DisplayObject::SetScrollRect(this, 0i64);
    Scaleform::GFx::DisplayObject::ResetClipDepth(pmaskSprite);
  }
  if ( this->pMaskCharacter )
  {
    if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *))this->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[78].__vecDelDtor)(this) )
    {
      pMaskCharacter = this->pMaskCharacter;
      if ( pMaskCharacter )
      {
        if ( pMaskCharacter->pMaskCharacter
          && !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *))pMaskCharacter->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[78].__vecDelDtor)(this->pMaskCharacter)
          && pMaskCharacter->pMaskCharacter )
        {
          Scaleform::GFx::DisplayObject::SetMask(pMaskCharacter, 0i64, 1);
        }
        pMaskCharacter->Flags &= ~4u;
        pMaskCharacter->pMaskCharacter = 0i64;
        Scaleform::Render::TreeNode::SetMaskNode(v6, 0i64);
        Scaleform::GFx::DisplayObjectBase::RemoveIndirectTransform(pMaskCharacter, v15);
      }
    }
    if ( this->pMaskCharacter )
    {
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *))this->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[78].__vecDelDtor)(this) )
      {
        v8 = this->pMaskCharacter;
        if ( v8 )
          Scaleform::GFx::DisplayObject::SetMask(v8, 0i64, 1);
      }
    }
  }
  if ( pmaskSprite
    && pmaskSprite->pMaskCharacter
    && ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *))pmaskSprite->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[78].__vecDelDtor)(pmaskSprite)
    && pmaskSprite->pMaskCharacter )
  {
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *))pmaskSprite->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[78].__vecDelDtor)(pmaskSprite) )
      v9 = pmaskSprite->pMaskCharacter;
    else
      v9 = 0i64;
    Scaleform::GFx::DisplayObject::SetMask(v9, 0i64, 1);
  }
  if ( this->pMaskCharacter
    && !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *))this->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[78].__vecDelDtor)(this) )
  {
    Scaleform::RefCountNTSImpl::Release(this->pMaskCharacter);
  }
  pObject = 0i64;
  if ( pmaskSprite )
  {
    v11 = Scaleform::GFx::DisplayObjectBase::SetIndirectTransform(pmaskSprite, &result, v6);
    if ( v11->pObject )
      ++v11->pObject->RefCount;
    pObject = v11->pObject;
    v12 = result.pObject;
    if ( result.pObject )
    {
      v13 = result.pObject->RefCount-- == 1;
      if ( v13 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v12);
    }
  }
  Scaleform::Render::TreeNode::SetMaskNode(v6, pObject);
  this->Flags &= ~4u;
  if ( pObject )
  {
    this->pMaskCharacter = pmaskSprite;
    if ( pmaskSprite )
    {
      ++pmaskSprite->RefCount;
      Scaleform::GFx::DisplayObject::SetMaskOwner(pmaskSprite, this);
    }
  }
  else
  {
    this->pMaskCharacter = 0i64;
  }
  if ( pObject )
  {
    v13 = pObject->RefCount-- == 1;
    if ( v13 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(pObject);
  }
  if ( v6 )
  {
    v13 = v6->RefCount-- == 1;
    if ( v13 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v6);
  }
}

// File Line: 1886
// RVA: 0x8DAD50
Scaleform::GFx::DisplayObject *__fastcall Scaleform::GFx::DisplayObject::GetMask(Scaleform::GFx::DisplayObject *this)
{
  if ( !this->pMaskCharacter
    || ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *))this->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[78].__vecDelDtor)(this) )
  {
    return 0i64;
  }
  else
  {
    return this->pMaskCharacter;
  }
}

// File Line: 1896
// RVA: 0x908E20
void __fastcall Scaleform::GFx::DisplayObject::SetMaskOwner(
        Scaleform::GFx::DisplayObject *this,
        Scaleform::GFx::DisplayObject *pmaskOwner)
{
  if ( this->pMaskCharacter
    && !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *))this->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[78].__vecDelDtor)(this)
    && this->pMaskCharacter )
  {
    Scaleform::GFx::DisplayObject::SetMask(this, 0i64, 1);
  }
  this->pMaskCharacter = pmaskOwner;
  if ( pmaskOwner )
    this->Flags |= 4u;
  else
    this->Flags &= ~4u;
}

// File Line: 1915
// RVA: 0x8DAE50
Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *__fastcall Scaleform::GFx::DisplayObject::GetMatrix(
        Scaleform::GFx::DisplayObject *this)
{
  Scaleform::GFx::DisplayObject::ScrollRectInfo *pScrollRect; // rax
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *result; // rax
  Scaleform::Render::TreeNode *pObject; // rdx
  unsigned __int64 v4; // r8
  unsigned __int64 v5; // rdx

  pScrollRect = this->pScrollRect;
  if ( pScrollRect )
    return (Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *)&pScrollRect->OrigTransformMatrix;
  result = this->pIndXFormData;
  if ( !result )
  {
    pObject = this->pRenNode.pObject;
    if ( pObject )
    {
      v4 = (unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64;
      v5 = (__int64)((unsigned __int128)((__int64)((__int64)&pObject[-1]
                                                 - ((unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64))
                                       * (__int128)0x4924924924924925i64) >> 64) >> 4;
      return (Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *)(*(_QWORD *)(*(_QWORD *)(v4 + 32)
                                                                                        + 8
                                                                                        * ((unsigned int)v5 + (v5 >> 63))
                                                                                        + 40)
                                                                            + 16i64);
    }
    else
    {
      return (Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *)&Scaleform::Render::Matrix2x4<float>::Identity;
    }
  }
  return result;
}

// File Line: 1925
// RVA: 0x9092E0
void __fastcall Scaleform::GFx::DisplayObject::SetMatrix(
        Scaleform::GFx::DisplayObject *this,
        Scaleform::Render::Matrix2x4<float> *mt)
{
  Scaleform::GFx::DisplayObject::ScrollRectInfo *pScrollRect; // rax
  float v4; // xmm1_4
  float v5; // xmm2_4
  float v6; // xmm3_4
  float v7; // xmm4_4
  float v8; // xmm5_4
  float v9; // xmm6_4
  float v10; // xmm7_4
  Scaleform::GFx::DisplayObject::ScrollRectInfo *v11; // rax
  float v12; // xmm3_4
  float v13; // xmm2_4
  Scaleform::Render::TreeNode *RenderNode; // rax
  Scaleform::GFx::DisplayObject::ScrollRectInfo *v15; // rcx
  float y1; // xmm2_4
  float x1; // xmm3_4
  Scaleform::Render::Matrix2x4<float> m; // [rsp+20h] [rbp-88h] BYREF
  Scaleform::Render::Matrix2x4<float> v19; // [rsp+40h] [rbp-68h] BYREF

  pScrollRect = this->pScrollRect;
  if ( pScrollRect )
  {
    v4 = mt->M[0][1];
    v5 = mt->M[0][2];
    v6 = mt->M[0][3];
    v7 = mt->M[1][0];
    v8 = mt->M[1][1];
    v9 = mt->M[1][2];
    v10 = mt->M[1][3];
    pScrollRect->OrigTransformMatrix.M[0][0] = mt->M[0][0];
    pScrollRect->OrigTransformMatrix.M[0][1] = v4;
    pScrollRect->OrigTransformMatrix.M[0][2] = v5;
    pScrollRect->OrigTransformMatrix.M[0][3] = v6;
    pScrollRect->OrigTransformMatrix.M[1][0] = v7;
    pScrollRect->OrigTransformMatrix.M[1][1] = v8;
    pScrollRect->OrigTransformMatrix.M[1][2] = v9;
    pScrollRect->OrigTransformMatrix.M[1][3] = v10;
    LODWORD(pScrollRect->OrigTransformMatrix.M[2][0]) = _xmm.m128_i32[0];
    LODWORD(pScrollRect->OrigTransformMatrix.M[2][1]) = _mm_shuffle_ps(_xmm, _xmm, 85).m128_u32[0];
    LODWORD(pScrollRect->OrigTransformMatrix.M[2][2]) = _mm_shuffle_ps(_xmm, _xmm, 170).m128_u32[0];
    LODWORD(pScrollRect->OrigTransformMatrix.M[2][3]) = _xmm.m128_i32[3];
    v11 = this->pScrollRect;
    *(_OWORD *)&m.M[0][0] = *(_OWORD *)&v11->OrigTransformMatrix.M[0][0];
    *(_OWORD *)&m.M[1][0] = *(_OWORD *)&v11->OrigTransformMatrix.M[1][0];
    v12 = COERCE_DOUBLE(*(_QWORD *)&v11->Rectangle.y1 ^ _xmm[0]);
    v13 = -v11->Rectangle.x1;
    m.M[0][3] = m.M[0][3] + (float)((float)(m.M[0][1] * v12) + (float)(m.M[0][0] * v13));
    m.M[1][3] = m.M[1][3] + (float)((float)(m.M[1][1] * v12) + (float)(m.M[1][0] * v13));
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::TreeNode::SetMatrix(RenderNode, &m);
    v15 = this->pScrollRect;
    *(_OWORD *)&v19.M[0][0] = _xmm;
    *(__m128 *)&v19.M[1][0] = _xmm;
    y1 = v15->Rectangle.y1;
    x1 = v15->Rectangle.x1;
    v19.M[0][3] = (float)(y1 * 0.0) + x1;
    v19.M[1][3] = (float)(x1 * 0.0) + y1;
    Scaleform::Render::TreeNode::SetMatrix(v15->Mask.pObject->pTreeContainer.pObject, &v19);
  }
  else
  {
    Scaleform::GFx::DisplayObjectBase::SetMatrix(this, mt);
  }
}

// File Line: 1942
// RVA: 0x8DAD80
Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *__fastcall Scaleform::GFx::DisplayObject::GetMatrix3D(
        Scaleform::GFx::DisplayObject *this)
{
  Scaleform::GFx::DisplayObject::ScrollRectInfo *pScrollRect; // rax
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *result; // rax
  Scaleform::Render::TreeNode *pObject; // rdx
  unsigned __int64 v4; // r8
  unsigned __int64 v5; // rdx

  pScrollRect = this->pScrollRect;
  if ( pScrollRect )
    return (Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *)&pScrollRect->OrigTransformMatrix;
  result = this->pIndXFormData;
  if ( !result )
  {
    pObject = this->pRenNode.pObject;
    if ( pObject )
    {
      v4 = (unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64;
      v5 = (__int64)((unsigned __int128)((__int64)((__int64)&pObject[-1]
                                                 - ((unsigned __int64)pObject & 0xFFFFFFFFFFFFF000ui64))
                                       * (__int128)0x4924924924924925i64) >> 64) >> 4;
      return (Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *)(*(_QWORD *)(*(_QWORD *)(v4 + 32)
                                                                                        + 8
                                                                                        * ((unsigned int)v5 + (v5 >> 63))
                                                                                        + 40)
                                                                            + 16i64);
    }
    else
    {
      return (Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *)&Scaleform::Render::Matrix3x4<float>::Identity;
    }
  }
  return result;
}

// File Line: 1952
// RVA: 0x908E90
void __fastcall Scaleform::GFx::DisplayObject::SetMatrix3D(
        Scaleform::GFx::DisplayObject *this,
        Scaleform::Render::Matrix3x4<float> *mt)
{
  Scaleform::GFx::DisplayObject::ScrollRectInfo *pScrollRect; // r8
  Scaleform::GFx::DisplayObject::ScrollRectInfo *v3; // rax
  float v4; // r13d
  float v5; // xmm7_4
  long double v6; // xmm0_8
  Scaleform::Render::TreeNode *RenderNode; // rax
  Scaleform::GFx::DisplayObject::ScrollRectInfo *v8; // rax
  float y1; // xmm7_4
  float x1; // xmm6_4
  Scaleform::Render::Matrix3x4<float> m1; // [rsp+20h] [rbp-E0h] BYREF
  float v12; // [rsp+50h] [rbp-B0h]
  float v13; // [rsp+60h] [rbp-A0h]
  float v14; // [rsp+70h] [rbp-90h]
  Scaleform::Render::Matrix3x4<float> v15; // [rsp+80h] [rbp-80h] BYREF
  Scaleform::Render::Matrix3x4<float> m; // [rsp+B0h] [rbp-50h] BYREF
  Scaleform::Render::Matrix3x4<float> Dst; // [rsp+E0h] [rbp-20h] BYREF
  Scaleform::Render::Matrix3x4<float> m2; // [rsp+110h] [rbp+10h] BYREF

  pScrollRect = this->pScrollRect;
  if ( pScrollRect )
  {
    pScrollRect->OrigTransformMatrix = *mt;
    this->pScrollRect->IsOrig3D = 1;
    v3 = this->pScrollRect;
    *(_QWORD *)&m.M[0][0] = *(_QWORD *)&v3->OrigTransformMatrix.M[0][0];
    m.M[0][2] = v3->OrigTransformMatrix.M[0][2];
    v14 = m.M[0][2];
    m.M[0][3] = v3->OrigTransformMatrix.M[0][3];
    v12 = m.M[0][3];
    m.M[1][0] = v3->OrigTransformMatrix.M[1][0];
    v4 = v3->OrigTransformMatrix.M[1][1];
    v13 = m.M[1][0];
    m.M[1][1] = v4;
    *(_QWORD *)&m.M[1][2] = *(_QWORD *)&v3->OrigTransformMatrix.M[1][2];
    *(_OWORD *)&m.M[2][0] = *(_OWORD *)&v3->OrigTransformMatrix.M[2][0];
    v5 = COERCE_DOUBLE(*(_QWORD *)&v3->Rectangle.y1 ^ _xmm[0]);
    v6 = -v3->Rectangle.x1;
    memset(&Dst, 0, sizeof(Dst));
    Dst.M[0][0] = 1.0;
    Dst.M[1][1] = 1.0;
    Dst.M[0][3] = v6;
    Dst.M[1][3] = v5;
    *(_OWORD *)&m1.M[0][0] = *(_OWORD *)&m.M[0][0];
    *(_QWORD *)&Dst.M[2][2] = 1065353216i64;
    *(_QWORD *)&m1.M[1][1] = __PAIR64__(LODWORD(m.M[1][2]), LODWORD(v4));
    m1.M[1][3] = m.M[1][3];
    *(_OWORD *)&m1.M[2][0] = *(_OWORD *)&m.M[2][0];
    m1.M[1][0] = m.M[1][0];
    Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&m, &m1, &Dst);
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::TreeNode::SetMatrix3D(RenderNode, &m);
    memset(&v15, 0, sizeof(v15));
    v8 = this->pScrollRect;
    LODWORD(v15.M[0][0]) = (_DWORD)FLOAT_1_0;
    LODWORD(v15.M[1][1]) = (_DWORD)FLOAT_1_0;
    LODWORD(v15.M[2][2]) = (_DWORD)FLOAT_1_0;
    y1 = v8->Rectangle.y1;
    x1 = v8->Rectangle.x1;
    memset(&m2, 0, sizeof(m2));
    m2.M[0][0] = 1.0;
    m2.M[1][1] = 1.0;
    *(_QWORD *)&m2.M[2][2] = 1065353216i64;
    m2.M[0][3] = x1;
    *(_QWORD *)&m1.M[0][1] = *(_QWORD *)&v15.M[0][1];
    m1.M[0][3] = v15.M[0][3];
    *(_QWORD *)&m1.M[1][2] = *(_QWORD *)&v15.M[1][2];
    *(_QWORD *)&m1.M[1][0] = __PAIR64__((unsigned int)FLOAT_1_0, LODWORD(v15.M[1][0]));
    *(_QWORD *)&m1.M[2][0] = *(_QWORD *)&v15.M[2][0];
    m2.M[1][3] = y1;
    LODWORD(m1.M[0][0]) = (_DWORD)FLOAT_1_0;
    *(_QWORD *)&m1.M[2][2] = __PAIR64__(LODWORD(v15.M[2][3]), (unsigned int)FLOAT_1_0);
    Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&v15, &m1, &m2);
    Scaleform::Render::TreeNode::SetMatrix3D(this->pScrollRect->Mask.pObject->pTreeContainer.pObject, &v15);
  }
  else
  {
    Scaleform::GFx::DisplayObjectBase::SetMatrix3D(this, mt);
  }
}

// File Line: 1975
// RVA: 0x90B790
void __fastcall Scaleform::GFx::DisplayObject::SetScrollRect(
        Scaleform::GFx::DisplayObject *this,
        Scaleform::Render::Rect<double> *r)
{
  Scaleform::Render::TreeNode *RenderNode; // rax
  Scaleform::Render::TreeNode *v5; // rbp
  Scaleform::GFx::DisplayObject::ScrollRectInfo *pScrollRect; // rdx
  Scaleform::GFx::DisplayObject::ScrollRectInfo *v7; // rbx
  Scaleform::RefCountNTSImpl *v8; // rcx
  __int64 v9; // r14
  __int64 v10; // rsi
  Scaleform::GFx::DisplayObject::ScrollRectInfo *v11; // rcx
  long double y2; // xmm2_8
  long double x2; // xmm1_8
  long double y1; // xmm0_8
  _DWORD *v15; // rdx
  Scaleform::GFx::DisplayObject::ScrollRectInfo *v16; // rcx
  Scaleform::GFx::DrawingContext *DrawingContext; // rsi
  Scaleform::GFx::DisplayObject::ScrollRectInfo *v18; // rbx
  Scaleform::RefCountNTSImpl *pObject; // rcx
  float v20; // xmm6_4
  float v21; // xmm7_4
  Scaleform::RefCountNTSImplCoreVtbl *vfptr; // r8
  __int64 v23; // rdx
  Scaleform::Render::Matrix2x4<float> m; // [rsp+30h] [rbp-78h] BYREF
  int v25; // [rsp+C0h] [rbp+18h] BYREF
  __int64 v26; // [rsp+C8h] [rbp+20h]

  if ( this->pMaskCharacter
    && !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *))this->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr[78].__vecDelDtor)(this)
    && this->pMaskCharacter )
  {
    Scaleform::GFx::DisplayObject::SetMask(this, 0i64, 1);
  }
  if ( (this->Scaleform::GFx::DisplayObjectBase::Flags & 0x8000u) == 0 )
  {
    RenderNode = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    v5 = RenderNode;
    if ( this->pScrollRect )
    {
      Scaleform::Render::TreeNode::SetMaskNode(RenderNode, 0i64);
      pScrollRect = this->pScrollRect;
      if ( pScrollRect->IsOrig3D )
      {
        Scaleform::Render::TreeNode::SetMatrix3D(v5, &pScrollRect->OrigTransformMatrix);
      }
      else
      {
        m = *(Scaleform::Render::Matrix2x4<float> *)&pScrollRect->OrigTransformMatrix.M[0][0];
        Scaleform::Render::TreeNode::SetMatrix(v5, &m);
      }
    }
    if ( r )
    {
      v9 = (__int64)((__int64)&v5[-1] - ((unsigned __int64)v5 & 0xFFFFFFFFFFFFF000ui64)) / 56;
      if ( (*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v5 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                 + 8i64 * (unsigned int)v9
                                 + 40)
                     + 10i64) & 0x10) != 0 )
        Scaleform::Render::TreeNode::SetMaskNode(v5, 0i64);
      if ( !this->pScrollRect )
      {
        v25 = 322;
        v10 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::DisplayObject *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                Scaleform::Memory::pGlobalHeap,
                this,
                112i64,
                &v25,
                -2i64);
        v26 = v10;
        if ( v10 )
        {
          *(_QWORD *)v10 = 0i64;
          *(_QWORD *)(v10 + 8) = 0i64;
          *(_QWORD *)(v10 + 16) = 0i64;
          *(_QWORD *)(v10 + 24) = 0i64;
          *(_QWORD *)(v10 + 32) = 0i64;
          memset((void *)(v10 + 48), 0, 0x30ui64);
          *(_DWORD *)(v10 + 48) = 1065353216;
          *(_DWORD *)(v10 + 68) = 1065353216;
          *(_DWORD *)(v10 + 88) = 1065353216;
        }
        else
        {
          v10 = 0i64;
        }
        this->pScrollRect = (Scaleform::GFx::DisplayObject::ScrollRectInfo *)v10;
      }
      v11 = this->pScrollRect;
      y2 = r->y2;
      x2 = r->x2;
      y1 = r->y1;
      v11->Rectangle.x1 = r->x1;
      v11->Rectangle.y1 = y1;
      v11->Rectangle.x2 = x2;
      v11->Rectangle.y2 = y2;
      v15 = *(_DWORD **)(*(_QWORD *)(((unsigned __int64)v5 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                       + 8i64 * (unsigned int)v9
                       + 40);
      v16 = this->pScrollRect;
      v16->OrigTransformMatrix.M[0][0] = (float)v15[4];
      v16->OrigTransformMatrix.M[0][1] = (float)v15[5];
      v16->OrigTransformMatrix.M[0][2] = (float)v15[6];
      v16->OrigTransformMatrix.M[0][3] = (float)v15[7];
      v16->OrigTransformMatrix.M[1][0] = (float)v15[8];
      v16->OrigTransformMatrix.M[1][1] = (float)v15[9];
      v16->OrigTransformMatrix.M[1][2] = (float)v15[10];
      v16->OrigTransformMatrix.M[1][3] = (float)v15[11];
      v16->OrigTransformMatrix.M[2][0] = (float)v15[12];
      v16->OrigTransformMatrix.M[2][1] = (float)v15[13];
      v16->OrigTransformMatrix.M[2][2] = (float)v15[14];
      v16->OrigTransformMatrix.M[2][3] = (float)v15[15];
      this->pScrollRect->IsOrig3D = (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v5 & 0xFFFFFFFFFFFFF000ui64)
                                                                      + 0x20)
                                                          + 8i64 * (unsigned int)v9
                                                          + 40)
                                              + 10i64) & 0x200) != 0;
      DrawingContext = Scaleform::GFx::MovieImpl::CreateDrawingContext(this->pASRoot->pMovieImpl);
      v18 = this->pScrollRect;
      pObject = v18->Mask.pObject;
      if ( pObject )
        Scaleform::RefCountNTSImpl::Release(pObject);
      v18->Mask.pObject = DrawingContext;
      Scaleform::GFx::DrawingContext::BeginSolidFill(this->pScrollRect->Mask.pObject, 0xFFFFFFFF);
      v20 = r->x2 - r->x1;
      v21 = r->y2 - r->y1;
      Scaleform::GFx::DrawingContext::MoveTo(this->pScrollRect->Mask.pObject, 0.0, 0.0);
      Scaleform::GFx::DrawingContext::LineTo(this->pScrollRect->Mask.pObject, v20, 0.0);
      Scaleform::GFx::DrawingContext::LineTo(this->pScrollRect->Mask.pObject, v20, v21);
      Scaleform::GFx::DrawingContext::LineTo(this->pScrollRect->Mask.pObject, 0.0, v21);
      Scaleform::GFx::DrawingContext::EndFill(this->pScrollRect->Mask.pObject);
      Scaleform::GFx::DrawingContext::UpdateRenderNode(this->pScrollRect->Mask.pObject);
      vfptr = this->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr;
      v23 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)v5 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                      + 8i64 * (unsigned int)v9
                      + 40);
      if ( this->pScrollRect->IsOrig3D )
        vfptr[5].__vecDelDtor(this, v23 + 16);
      else
        vfptr[3].__vecDelDtor(this, v23 + 16);
      Scaleform::Render::TreeNode::SetMaskNode(v5, this->pScrollRect->Mask.pObject->pTreeContainer.pObject);
    }
    else
    {
      v7 = this->pScrollRect;
      if ( v7 )
      {
        v8 = v7->Mask.pObject;
        if ( v8 )
          Scaleform::RefCountNTSImpl::Release(v8);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v7);
      }
      this->pScrollRect = 0i64;
    }
  }
}

// File Line: 2041
// RVA: 0x8E2E10
bool __fastcall Scaleform::GFx::DisplayObject::HasEventHandler(
        Scaleform::GFx::DisplayObject *this,
        Scaleform::GFx::EventId *id)
{
  unsigned __int8 AvmObjOffset; // al

  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
    return (bool)(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                         + 4 * AvmObjOffset))[7].__vecDelDtor(
                   (char *)this + 4 * AvmObjOffset,
                   id);
  else
    return 0;
}

// File Line: 2048
// RVA: 0x8EC670
bool __fastcall Scaleform::GFx::DisplayObject::OnEvent(
        Scaleform::GFx::DisplayObject *this,
        Scaleform::GFx::EventId *id)
{
  unsigned __int8 AvmObjOffset; // al

  AvmObjOffset = this->AvmObjOffset;
  if ( AvmObjOffset )
    return (bool)(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                         + 4 * AvmObjOffset))[8].__vecDelDtor(
                   (char *)this + 4 * AvmObjOffset,
                   id);
  else
    return 0;
}

// File Line: 2056
// RVA: 0x913A90
char __fastcall Scaleform::GFx::DisplayObject::TransformPointToLocalAndCheckBounds(
        Scaleform::GFx::DisplayObject *this,
        Scaleform::Render::Point<float> *p,
        Scaleform::Render::Point<float> *pt,
        bool bPtInParentSpace,
        Scaleform::Render::Matrix2x4<float> *mat)
{
  float x; // xmm3_4
  float y; // xmm2_4
  Scaleform::GFx::DisplayObject::ScrollRectInfo *pScrollRect; // rax
  float x1; // xmm0_4
  float v11; // xmm1_4
  Scaleform::GFx::DisplayObject::ScrollRectInfo *v12; // rax
  Scaleform::Render::Point<float> pa; // [rsp+40h] [rbp+8h] BYREF

  if ( this->pScrollRect )
  {
    Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(this, &pa, pt, bPtInParentSpace, mat);
    x = pa.x;
    y = pa.y;
    p->x = pa.x;
    p->y = y;
    pScrollRect = this->pScrollRect;
    x1 = pScrollRect->Rectangle.x1;
    v11 = (float)pScrollRect->Rectangle.y1 + y;
    p->x = x1 + x;
    p->y = v11;
    if ( x < 0.0 )
      return 0;
    if ( y < 0.0 )
      return 0;
    v12 = this->pScrollRect;
    if ( x > v12->Rectangle.x2 - v12->Rectangle.x1 || y > v12->Rectangle.y2 - v12->Rectangle.y1 )
      return 0;
  }
  else
  {
    Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(this, p, pt, bPtInParentSpace, mat);
  }
  return 1;
}

// File Line: 2079
// RVA: 0x894FF0
void __fastcall Scaleform::GFx::CharacterHandle::CharacterHandle(
        Scaleform::GFx::CharacterHandle *this,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::DisplayObject *pparent,
        Scaleform::GFx::DisplayObject *pcharacter)
{
  Scaleform::GFx::ASStringNode *pNode; // rax
  Scaleform::GFx::ASStringNode *v9; // rax
  unsigned __int8 AvmObjOffset; // al
  Scaleform::GFx::ASString *v11; // rax
  Scaleform::GFx::ASStringNode *v12; // rsi
  Scaleform::GFx::ASStringNode *v13; // rcx
  bool v14; // zf
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::String str; // [rsp+68h] [rbp+10h] BYREF
  Scaleform::GFx::ASString result; // [rsp+78h] [rbp+20h] BYREF

  pNode = name->pNode;
  this->Name = (Scaleform::GFx::ASString)name->pNode;
  ++pNode->RefCount;
  Scaleform::GFx::ASStringManager::CreateEmptyString(name->pNode->pManager, &this->NamePath);
  v9 = name->pNode;
  this->OriginalName = (Scaleform::GFx::ASString)name->pNode;
  ++v9->RefCount;
  this->RefCount = 1;
  this->pCharacter = pcharacter;
  if ( pcharacter && pcharacter->pASRoot->AVMVersion == 1 )
  {
    Scaleform::String::String(&str);
    if ( pparent )
    {
      AvmObjOffset = pparent->AvmObjOffset;
      if ( AvmObjOffset )
        (*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&pparent->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                                + 4 * AvmObjOffset))[6].__vecDelDtor(
          (Scaleform::GFx::DisplayObject *)((char *)pparent + 4 * AvmObjOffset),
          (unsigned int)&str);
      Scaleform::String::AppendString(&str, ".", -1i64);
    }
    Scaleform::String::AppendString(&str, this->Name.pNode->pData, -1i64);
    v11 = Scaleform::GFx::ASStringManager::CreateString(name->pNode->pManager, &result, &str);
    v12 = v11->pNode;
    ++v11->pNode->RefCount;
    v13 = this->NamePath.pNode;
    v14 = v13->RefCount-- == 1;
    if ( v14 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    this->NamePath.pNode = v12;
    v15 = result.pNode;
    v14 = result.pNode->RefCount-- == 1;
    if ( v14 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v15);
    if ( _InterlockedExchangeAdd(
           (volatile signed __int32 *)((str.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
           0xFFFFFFFF) == 1 )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
}

// File Line: 2098
// RVA: 0x8A3780
void __fastcall Scaleform::GFx::CharacterHandle::~CharacterHandle(Scaleform::GFx::CharacterHandle *this)
{
  Scaleform::GFx::ASStringNode *pNode; // rcx
  bool v3; // zf
  Scaleform::GFx::ASStringNode *v4; // rcx
  Scaleform::GFx::ASStringNode *v5; // rcx

  pNode = this->OriginalName.pNode;
  v3 = pNode->RefCount-- == 1;
  if ( v3 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v4 = this->NamePath.pNode;
  v3 = v4->RefCount-- == 1;
  if ( v3 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  v5 = this->Name.pNode;
  v3 = v5->RefCount-- == 1;
  if ( v3 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
}

// File Line: 2110
// RVA: 0x8BA400
void __fastcall Scaleform::GFx::CharacterHandle::ChangeName(
        Scaleform::GFx::CharacterHandle *this,
        Scaleform::GFx::ASString *name,
        Scaleform::GFx::DisplayObject *pparent)
{
  Scaleform::GFx::ASStringNode *pNode; // rsi
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  unsigned __int8 AvmObjOffset; // al
  Scaleform::GFx::ASString *v10; // rax
  Scaleform::GFx::ASStringNode *v11; // rsi
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::GFx::ASStringNode *v13; // rcx
  Scaleform::String str; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+10h] BYREF

  pNode = name->pNode;
  ++name->pNode->RefCount;
  v7 = this->Name.pNode;
  v8 = v7->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  this->Name.pNode = pNode;
  if ( pparent && pparent->pASRoot->AVMVersion == 1 )
  {
    Scaleform::String::String(&str);
    AvmObjOffset = pparent->AvmObjOffset;
    if ( AvmObjOffset )
      (*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&pparent->Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::vfptr
                                              + 4 * AvmObjOffset))[6].__vecDelDtor(
        (Scaleform::GFx::DisplayObject *)((char *)pparent + 4 * AvmObjOffset),
        (unsigned int)&str);
    Scaleform::String::AppendString(&str, ".", -1i64);
    Scaleform::String::AppendString(&str, this->Name.pNode->pData, -1i64);
    v10 = Scaleform::GFx::ASStringManager::CreateString(name->pNode->pManager, &result, &str);
    v11 = v10->pNode;
    ++v10->pNode->RefCount;
    v12 = this->NamePath.pNode;
    v8 = v12->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    this->NamePath.pNode = v11;
    v13 = result.pNode;
    v8 = result.pNode->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
    if ( _InterlockedExchangeAdd(
           (volatile signed __int32 *)((str.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
           0xFFFFFFFF) == 1 )
      ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
}

// File Line: 2130
// RVA: 0x9039F0
Scaleform::GFx::DisplayObject *__fastcall Scaleform::GFx::CharacterHandle::ResolveCharacter(
        Scaleform::GFx::CharacterHandle *this,
        Scaleform::GFx::MovieImpl *proot)
{
  Scaleform::GFx::DisplayObject *result; // rax

  result = this->pCharacter;
  if ( !result )
    return (Scaleform::GFx::DisplayObject *)proot->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[8].__vecDelDtor(
                                              proot->pASMovieRoot.pObject,
                                              &this->NamePath);
  return result;
}

// File Line: 2138
// RVA: 0x8CE400
Scaleform::GFx::DisplayObject *__fastcall Scaleform::GFx::CharacterHandle::ForceResolveCharacter(
        Scaleform::GFx::CharacterHandle *this,
        Scaleform::GFx::MovieImpl *proot)
{
  return (Scaleform::GFx::DisplayObject *)proot->pASMovieRoot.pObject->Scaleform::GFx::Movie::vfptr[8].__vecDelDtor(
                                            proot->pASMovieRoot.pObject,
                                            &this->NamePath);
}

