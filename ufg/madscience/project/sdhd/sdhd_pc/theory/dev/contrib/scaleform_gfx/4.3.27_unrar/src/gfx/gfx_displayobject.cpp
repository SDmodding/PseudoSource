// File Line: 41
// RVA: 0x8955D0
void __fastcall Scaleform::GFx::DisplayObjectBase::DisplayObjectBase(Scaleform::GFx::DisplayObjectBase *this, Scaleform::GFx::ASMovieRootBase *pasRoot, Scaleform::GFx::InteractiveObject *parent, __int64 id)
{
  Scaleform::Render::TreeNode *v4; // rcx

  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImplCore::`vftable';
  this->RefCount = 1;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountNTSImpl::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountWeakSupportImpl::`vftable';
  this->pWeakProxy = 0i64;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::`vftable';
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::`vftable';
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::DisplayObjectBase::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::DisplayObjectBase::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
  this->pASRoot = pasRoot;
  this->Id.Id = *(_DWORD *)id;
  this->Depth = -1;
  this->CreateFrame = 0;
  this->pParent = parent;
  this->pRenNode.pObject = 0i64;
  this->pGeomData = 0i64;
  this->pPerspectiveData = 0i64;
  this->pIndXFormData = 0i64;
  *(_DWORD *)&this->ClipDepth = 0x40000000;
  *(_WORD *)&this->BlendMode = 0;
  v4 = this->pRenNode.pObject;
  if ( v4 )
    Scaleform::Render::TreeNode::SetVisible(v4, 1);
}

// File Line: 49
// RVA: 0x8A3E00
void __fastcall Scaleform::GFx::DisplayObjectBase::~DisplayObjectBase(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase *v1; // rbx
  unsigned __int8 v2; // al
  Scaleform::Render::ContextImpl::Entry *v3; // rcx
  bool v4; // zf

  v1 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::DisplayObjectBase::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::DisplayObjectBase::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
  if ( this->pGeomData )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( v1->pPerspectiveData )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  if ( v1->pIndXFormData )
    ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v2 = v1->AvmObjOffset;
  if ( v2 )
    (**(void (__fastcall ***)(signed __int64, _QWORD))((char *)&v1->vfptr + 4 * v2))((signed __int64)v1 + 4 * v2, 0i64);
  v3 = (Scaleform::Render::ContextImpl::Entry *)&v1->pRenNode.pObject->0;
  if ( v3 )
  {
    v4 = v3->RefCount-- == 1;
    if ( v4 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v3);
  }
  v1->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::`vftable';
  Scaleform::RefCountWeakSupportImpl::~RefCountWeakSupportImpl((Scaleform::RefCountWeakSupportImpl *)&v1->vfptr);
}

// File Line: 66
// RVA: 0x8DD6A0
Scaleform::Render::TreeNode *__fastcall Scaleform::GFx::DisplayObjectBase::GetRenderNode(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase *v1; // rbx
  __int64 v2; // rdi
  Scaleform::Render::ContextImpl::Entry *v3; // rcx
  bool v4; // zf
  Scaleform::Render::ContextImpl::Entry *v5; // rcx
  Scaleform::Render::ContextImpl::Entry *v7; // [rsp+40h] [rbp+8h]

  v1 = this;
  if ( this->pRenNode.pObject )
    return this->pRenNode.pObject;
  v2 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::ContextImpl::Entry **, Scaleform::Render::ContextImpl::Context *))this->vfptr[1].__vecDelDtor)(
         this,
         &v7,
         &this->pASRoot->pMovieImpl->RenderContext);
  if ( *(_QWORD *)v2 )
    ++*(_QWORD *)(*(_QWORD *)v2 + 8i64);
  v3 = (Scaleform::Render::ContextImpl::Entry *)&v1->pRenNode.pObject->0;
  if ( v3 )
  {
    v4 = v3->RefCount-- == 1;
    if ( v4 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v3);
  }
  v1->pRenNode.pObject = *(Scaleform::Render::TreeNode **)v2;
  v5 = v7;
  if ( v7 )
  {
    v4 = v7->RefCount-- == 1;
    if ( v4 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v5);
  }
  Scaleform::Render::TreeNode::SetVisible(v1->pRenNode.pObject, (v1->Flags >> 14) & 1);
  return v1->pRenNode.pObject;
}

// File Line: 77
// RVA: 0x8BDEF0
Scaleform::Render::TreeContainer *__fastcall Scaleform::GFx::DisplayObjectBase::ConvertToTreeContainer(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase *v1; // rdi
  Scaleform::Render::TreeContainer *v2; // r14
  Scaleform::Render::BlendMode v3; // er12
  Scaleform::Render::TreeContainer *v4; // rbx
  Scaleform::Render::TreeNode *v5; // r15
  unsigned __int64 v6; // rsi
  unsigned __int64 v7; // r9
  _QWORD *v8; // rcx
  Scaleform::Render::TreeNode *v9; // rcx
  Scaleform::Render::Matrix3x4<float> *v10; // rax
  Scaleform::Render::Matrix2x4<float> *v11; // rax
  Scaleform::Render::TreeNode *v12; // rcx
  Scaleform::Render::Cxform *v13; // rsi
  Scaleform::Render::ContextImpl::EntryData *v14; // rax
  Scaleform::Render::ContextImpl::EntryData *v15; // rax
  char v16; // al
  Scaleform::Render::State *v17; // rax
  Scaleform::Render::State *v18; // rax
  float *v19; // rax
  float v20; // xmm3_4
  float v21; // xmm2_4
  float v22; // xmm1_4
  Scaleform::Render::ContextImpl::Entry *v23; // rcx
  bool v24; // zf
  Scaleform::Render::Rect<float> v26; // [rsp+20h] [rbp-79h]
  Scaleform::Render::Rect<float> rect; // [rsp+30h] [rbp-69h]
  Scaleform::Render::Matrix3x4<float> mat3D; // [rsp+40h] [rbp-59h]
  __int64 v29; // [rsp+70h] [rbp-29h]
  int Dst; // [rsp+80h] [rbp-19h]
  int v31; // [rsp+94h] [rbp-5h]
  int v32; // [rsp+A8h] [rbp+Fh]
  int v33; // [rsp+BCh] [rbp+23h]

  v29 = -2i64;
  v1 = this;
  if ( !this->pRenNode.pObject )
    Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  v2 = (Scaleform::Render::TreeContainer *)v1->pRenNode.pObject->pParent;
  v3 = 0;
  v4 = (Scaleform::Render::TreeContainer *)Scaleform::Render::ContextImpl::Context::CreateEntry<Scaleform::Render::TreeContainer>(&v1->pASRoot->pMovieImpl->RenderContext);
  if ( v2 )
  {
    v5 = v1->pRenNode.pObject;
    if ( (*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(((_QWORD)v1->pRenNode.pObject & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                               + 8
                               * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v1->pRenNode.pObject[-1] - ((_QWORD)v1->pRenNode.pObject & 0xFFFFFFFFFFFFF000ui64))
                                                                                    * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v1->pRenNode.pObject[-1]
                                                                                         - ((_QWORD)v1->pRenNode.pObject & 0xFFFFFFFFFFFFF000ui64))
                                                                        * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                               + 40)
                   + 10i64) >> 5) & 1 )
    {
      Scaleform::Render::TreeNode::SetMaskNode((Scaleform::Render::TreeNode *)&v2->0, 0i64);
      Scaleform::Render::TreeNode::SetMaskNode(
        (Scaleform::Render::TreeNode *)&v2->0,
        (Scaleform::Render::TreeNode *)&v4->0);
    }
    else
    {
      v6 = 0i64;
      v7 = Scaleform::Render::TreeContainer::GetSize(v2);
      if ( v7 )
      {
        do
        {
          v8 = (_QWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                    + 8
                                    * (((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v2[-1]
                                                                                              - ((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64))
                                                                             * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                                     + (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v2[-1] - ((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64))
                                                                                         * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                                    + 40)
                        + 144i64);
          if ( *(_BYTE *)v8 & 1 )
            v8 = (_QWORD *)((*v8 & 0xFFFFFFFFFFFFFFFEui64) + 16);
          if ( (Scaleform::Render::TreeNode *)v8[v6] == v5 )
            break;
          ++v6;
        }
        while ( v6 < v7 );
      }
      Scaleform::Render::TreeContainer::Remove(v2, v6, 1ui64);
      Scaleform::Render::TreeContainer::Insert(v2, v6, (Scaleform::Render::TreeNode *)&v4->0);
    }
  }
  v9 = v1->pRenNode.pObject;
  if ( v9
    && (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v9 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8
                             * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v9[-1] - ((unsigned __int64)v9 & 0xFFFFFFFFFFFFF000ui64))
                                                                                  * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                              + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v9[-1]
                                                                                       - ((unsigned __int64)v9 & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                             + 40)
                 + 10i64) >> 9) & 1 )
  {
    v10 = (Scaleform::Render::Matrix3x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v1->vfptr[4].__vecDelDtor)(v1);
    Scaleform::Render::TreeNode::SetMatrix3D((Scaleform::Render::TreeNode *)&v4->0, v10);
    memset(&Dst, 0, 0x40ui64);
    Dst = 1065353216;
    v31 = 1065353216;
    v32 = 1065353216;
    v33 = 1065353216;
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, int *, _QWORD))v1->vfptr[6].__vecDelDtor)(
           v1,
           &Dst,
           0i64) )
    {
      Scaleform::Render::TreeNode::SetProjectionMatrix3D(
        (Scaleform::Render::TreeNode *)&v4->0,
        (Scaleform::Render::Matrix4x4<float> *)&Dst);
    }
    memset(&mat3D, 0, 0x30ui64);
    mat3D.M[0][0] = 1.0;
    mat3D.M[1][1] = 1.0;
    mat3D.M[2][2] = 1.0;
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Matrix3x4<float> *, _QWORD))v1->vfptr[9].__vecDelDtor)(
           v1,
           &mat3D,
           0i64) )
    {
      Scaleform::Render::TreeNode::SetViewMatrix3D((Scaleform::Render::TreeNode *)&v4->0, &mat3D);
    }
    Scaleform::Render::TreeNode::SetMatrix3D(v1->pRenNode.pObject, &Scaleform::Render::Matrix3x4<float>::Identity);
  }
  else
  {
    v11 = (Scaleform::Render::Matrix2x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v1->vfptr[2].__vecDelDtor)(v1);
    Scaleform::Render::TreeNode::SetMatrix((Scaleform::Render::TreeNode *)&v4->0, v11);
    Scaleform::Render::TreeNode::SetMatrix(v1->pRenNode.pObject, &Scaleform::Render::Matrix2x4<float>::Identity);
  }
  v12 = v1->pRenNode.pObject;
  if ( v12 )
    v13 = (Scaleform::Render::Cxform *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v12 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                                  + 8
                                                  * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v12[-1] - ((unsigned __int64)v12 & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                                   + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v12[-1] - ((unsigned __int64)v12 & 0xFFFFFFFFFFFFF000ui64))
                                                                                           * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                                  + 40)
                                      + 80i64);
  else
    v13 = &Scaleform::Render::Cxform::Identity;
  v14 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&v4->0, 2u);
  v14[5] = *(Scaleform::Render::ContextImpl::EntryData *)&v13->M[0][0];
  v14[6] = *(Scaleform::Render::ContextImpl::EntryData *)&v13->M[1][0];
  v15 = Scaleform::Render::ContextImpl::Entry::getWritableData(
          (Scaleform::Render::ContextImpl::Entry *)&v1->pRenNode.pObject->0,
          2u);
  v15[5] = *(Scaleform::Render::ContextImpl::EntryData *)&Scaleform::Render::Cxform::Identity.M[0][0];
  v15[6] = *(Scaleform::Render::ContextImpl::EntryData *)&Scaleform::Render::Cxform::Identity.M[1][0];
  v16 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v1->vfptr[59].__vecDelDtor)(v1);
  Scaleform::Render::TreeNode::SetVisible((Scaleform::Render::TreeNode *)&v4->0, v16);
  Scaleform::Render::TreeNode::SetVisible(v1->pRenNode.pObject, 1);
  v17 = Scaleform::Render::TreeNode::GetState(v1->pRenNode.pObject, State_BlendMode);
  if ( v17 )
    v3 = (Scaleform::Render::BlendMode)v17->pData;
  Scaleform::Render::TreeNode::SetBlendMode((Scaleform::Render::TreeNode *)&v4->0, v3);
  Scaleform::Render::TreeNode::SetBlendMode(v1->pRenNode.pObject, 0);
  v18 = Scaleform::Render::TreeNode::GetState(v1->pRenNode.pObject, State_Scale9);
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
    Scaleform::Render::TreeNode::SetScale9Grid((Scaleform::Render::TreeNode *)&v4->0, &rect);
    v26 = 0i64;
    Scaleform::Render::TreeNode::SetScale9Grid(v1->pRenNode.pObject, &v26);
  }
  Scaleform::Render::TreeContainer::Add(v4, v1->pRenNode.pObject);
  if ( v4 )
    ++v4->RefCount;
  v23 = (Scaleform::Render::ContextImpl::Entry *)&v1->pRenNode.pObject->0;
  if ( v23 )
  {
    v24 = v23->RefCount-- == 1;
    if ( v24 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v23);
  }
  v1->pRenNode.pObject = (Scaleform::Render::TreeNode *)&v4->0;
  if ( v4 )
  {
    v24 = v4->RefCount-- == 1;
    if ( v24 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)&v4->0);
  }
  return v4;
}

// File Line: 165
// RVA: 0x8DAEC0
Scaleform::Render::Matrix2x4<float> *__fastcall Scaleform::GFx::DisplayObjectBase::GetMatrix(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::Matrix2x4<float> *result; // rax
  Scaleform::Render::TreeNode *v2; // rcx

  result = (Scaleform::Render::Matrix2x4<float> *)this->pIndXFormData;
  if ( !result )
  {
    v2 = this->pRenNode.pObject;
    if ( v2 )
      result = (Scaleform::Render::Matrix2x4<float> *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64)
                                                                             + 0x20)
                                                                 + 8
                                                                 * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v2[-1] - ((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                                                  + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v2[-1] - ((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                                                 + 40)
                                                     + 16i64);
    else
      result = &Scaleform::Render::Matrix2x4<float>::Identity;
  }
  return result;
}

// File Line: 179
// RVA: 0x909500
void __fastcall Scaleform::GFx::DisplayObjectBase::SetMatrix(Scaleform::GFx::DisplayObjectBase *this, Scaleform::Render::Matrix2x4<float> *m)
{
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *v2; // rax
  Scaleform::Render::Matrix2x4<float> *v3; // rdi
  Scaleform::GFx::DisplayObjectBase *v4; // rbx
  Scaleform::Render::TreeNode *v5; // rax
  float v6; // xmm1_4
  float v7; // xmm2_4
  float v8; // xmm3_4
  float v9; // xmm4_4
  float v10; // xmm5_4
  float v11; // xmm6_4
  float v12; // xmm7_4
  Scaleform::Render::TreeNode *v13; // rax

  v2 = this->pIndXFormData;
  v3 = m;
  v4 = this;
  if ( v2 )
  {
    v6 = m->M[0][1];
    v7 = m->M[0][2];
    v8 = m->M[0][3];
    v9 = m->M[1][0];
    v10 = m->M[1][1];
    v11 = m->M[1][2];
    v12 = m->M[1][3];
    v2->OrigTransformMatrix.M[0][0] = m->M[0][0];
    v2->OrigTransformMatrix.M[0][1] = v6;
    v2->OrigTransformMatrix.M[0][2] = v7;
    v2->OrigTransformMatrix.M[0][3] = v8;
    v2->OrigTransformMatrix.M[1][0] = v9;
    v2->OrigTransformMatrix.M[1][1] = v10;
    v2->OrigTransformMatrix.M[1][2] = v11;
    v2->OrigTransformMatrix.M[1][3] = v12;
    LODWORD(v2->OrigTransformMatrix.M[2][0]) = _xmm.m128_i32[0];
    LODWORD(v2->OrigTransformMatrix.M[2][1]) = (unsigned __int128)_mm_shuffle_ps(_xmm, _xmm, 85);
    LODWORD(v2->OrigTransformMatrix.M[2][2]) = (unsigned __int128)_mm_shuffle_ps(_xmm, _xmm, 170);
    v2->OrigTransformMatrix.M[2][3] = _xmm.m128_f32[3];
    v13 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&v13->0, 1u);
  }
  else
  {
    v5 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::TreeNode::SetMatrix(v5, v3);
  }
  Scaleform::GFx::DisplayObjectBase::UpdateViewAndPerspective(v4);
}

// File Line: 194
// RVA: 0x8DADF0
Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *__fastcall Scaleform::GFx::DisplayObjectBase::GetMatrix3D(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *result; // rax
  Scaleform::Render::TreeNode *v2; // rcx

  result = this->pIndXFormData;
  if ( !result )
  {
    v2 = this->pRenNode.pObject;
    if ( v2 )
      result = (Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                                                                          + 8
                                                                                          * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v2[-1] - ((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                                                                           + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v2[-1] - ((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                                                                          + 40)
                                                                              + 16i64);
    else
      result = (Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *)&Scaleform::Render::Matrix3x4<float>::Identity;
  }
  return result;
}

// File Line: 209
// RVA: 0x909220
void __fastcall Scaleform::GFx::DisplayObjectBase::SetMatrix3D(Scaleform::GFx::DisplayObjectBase *this, Scaleform::Render::Matrix3x4<float> *m)
{
  Scaleform::GFx::DisplayObjectBase *v2; // rbx
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *v3; // rcx
  Scaleform::Render::Matrix3x4<float> *v4; // rdi
  Scaleform::Render::TreeNode *v5; // rax
  Scaleform::Render::TreeNode *v6; // rax

  v2 = this;
  v3 = this->pIndXFormData;
  v4 = m;
  if ( v3 )
  {
    v3->OrigTransformMatrix = *m;
    v2->pIndXFormData->IsOrig3D = 1;
    v6 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v2);
    Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&v6->0, 1u);
  }
  else
  {
    v5 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v2);
    Scaleform::Render::TreeNode::SetMatrix3D(v5, v4);
  }
  Scaleform::GFx::DisplayObjectBase::UpdateViewAndPerspective(v2);
}

// File Line: 225
// RVA: 0x8E1590
char __fastcall Scaleform::GFx::DisplayObjectBase::GetViewMatrix3D(Scaleform::GFx::DisplayObjectBase *this, Scaleform::Render::Matrix3x4<float> *m, bool bInherit)
{
  Scaleform::GFx::DisplayObjectBase *v3; // r11
  Scaleform::Render::TreeNode *v4; // rcx
  _OWORD *v5; // rcx
  Scaleform::GFx::InteractiveObject *v7; // rcx
  Scaleform::GFx::MovieImpl *v8; // rcx

  v3 = this;
  v4 = this->pRenNode.pObject;
  if ( v4
    && (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v4 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8
                             * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v4[-1] - ((unsigned __int64)v4 & 0xFFFFFFFFFFFFF000ui64))
                                                                                  * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                              + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v4[-1]
                                                                                       - ((unsigned __int64)v4 & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                             + 40)
                 + 10i64) >> 11) & 1 )
  {
    v5 = (_OWORD *)&v3->pPerspectiveData->FieldOfView;
    *(_OWORD *)&m->M[0][0] = v5[2];
    *(_OWORD *)&m->M[1][0] = v5[3];
    *(_OWORD *)&m->M[2][0] = v5[4];
    return 1;
  }
  if ( !bInherit )
    return 0;
  v7 = v3->pParent;
  if ( v7 )
    return v7->vfptr[9].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v7->vfptr, (unsigned int)m);
  v8 = v3->pASRoot->pMovieImpl;
  if ( !v8 )
    return 0;
  return Scaleform::Render::TreeNode::GetViewMatrix3D((Scaleform::Render::TreeNode *)&v8->pRenderRoot.pObject->0, m);
}

// File Line: 257
// RVA: 0x90E990
void __fastcall Scaleform::GFx::DisplayObjectBase::SetViewMatrix3D(Scaleform::GFx::DisplayObjectBase *this, Scaleform::Render::Matrix3x4<float> *m)
{
  Scaleform::Render::Matrix3x4<float> *v2; // r14
  Scaleform::GFx::DisplayObjectBase *v3; // rsi
  Scaleform::Render::TreeNode *v4; // rcx
  bool v5; // r10
  Scaleform::GFx::InteractiveObject *v6; // r9
  Scaleform::Render::TreeNode *v7; // rcx
  _QWORD *v8; // rax
  _QWORD *v9; // rdi
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v10; // rcx
  Scaleform::GFx::MovieImpl *v11; // rbx
  float v12; // xmm6_4
  Scaleform::Render::TreeNode *v13; // rax
  Scaleform::Render::Matrix3x4<float> m1; // [rsp+20h] [rbp-A9h]
  _QWORD *v15; // [rsp+50h] [rbp-79h]
  __int64 v16; // [rsp+58h] [rbp-71h]
  float Dst; // [rsp+60h] [rbp-69h]
  float v18; // [rsp+74h] [rbp-55h]
  int v19; // [rsp+88h] [rbp-41h]
  Scaleform::Render::Matrix3x4<float> mat3D; // [rsp+90h] [rbp-39h]
  Scaleform::Render::Matrix3x4<float> m2; // [rsp+C0h] [rbp-9h]
  int v22; // [rsp+140h] [rbp+77h]
  __int64 v23; // [rsp+148h] [rbp+7Fh]

  v16 = -2i64;
  v2 = m;
  v3 = this;
  v4 = this->pRenNode.pObject;
  v5 = v4
    && (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v4 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8
                             * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v4[-1] - ((unsigned __int64)v4 & 0xFFFFFFFFFFFFF000ui64))
                                                                                  * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                              + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v4[-1]
                                                                                       - ((unsigned __int64)v4 & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                             + 40)
                 + 10i64) >> 11) & 1;
  v6 = v3->pParent;
  if ( !v6
    || (v7 = v6->pRenNode.pObject) == 0i64
    || !((*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                               + 8
                               * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v7[-1] - ((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64))
                                                                                    * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v7[-1]
                                                                                         - ((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64))
                                                                        * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                               + 40)
                   + 10i64) >> 9) & 1)
    || v6->pPerspectiveData
    || v5 )
  {
    if ( !v3->pPerspectiveData )
    {
      v22 = 322;
      v8 = (_QWORD *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                       Scaleform::Memory::pGlobalHeap,
                       v3,
                       80ui64,
                       (Scaleform::AllocInfo *)&v22);
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
        *((float *)v9 + 4) = -2.696539702293474e308/*NaN*/;
        v23 = *(_QWORD *)GFxNaN_Bytes;
        *((float *)v9 + 5) = -2.696539702293474e308/*NaN*/;
      }
      else
      {
        v9 = 0i64;
      }
      v3->pPerspectiveData = (Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *)v9;
    }
    v10 = v3->pPerspectiveData;
    v10->ViewMatrix3D.M[0][0] = v2->M[0][0];
    v10->ViewMatrix3D.M[0][1] = v2->M[0][1];
    v10->ViewMatrix3D.M[0][2] = v2->M[0][2];
    v10->ViewMatrix3D.M[0][3] = v2->M[0][3];
    v10->ViewMatrix3D.M[1][0] = v2->M[1][0];
    v10->ViewMatrix3D.M[1][1] = v2->M[1][1];
    v10->ViewMatrix3D.M[1][2] = v2->M[1][2];
    v10->ViewMatrix3D.M[1][3] = v2->M[1][3];
    v10->ViewMatrix3D.M[2][0] = v2->M[2][0];
    v10->ViewMatrix3D.M[2][1] = v2->M[2][1];
    v10->ViewMatrix3D.M[2][2] = v2->M[2][2];
    v10->ViewMatrix3D.M[2][3] = v2->M[2][3];
    v11 = v3->pASRoot->pMovieImpl;
    memset(&Dst, 0, 0x30ui64);
    v12 = v11->VisibleFrameRect.x1;
    Dst = 1.0 / (float)((float)v11->mViewport.Width / (float)(v11->VisibleFrameRect.x2 - v12));
    v18 = 1.0 / (float)((float)v11->mViewport.Height / (float)(v11->VisibleFrameRect.y2 - v11->VisibleFrameRect.y1));
    v19 = 1065353216;
    memset(&m1, 0, 0x30ui64);
    m1.M[0][0] = 1.0;
    m1.M[1][1] = 1.0;
    *(_QWORD *)&m1.M[2][2] = 1065353216i64;
    m1.M[0][3] = v12;
    m1.M[1][3] = v11->VisibleFrameRect.y1;
    Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&m2, &m1, (Scaleform::Render::Matrix3x4<float> *)&Dst);
    Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&mat3D, v2, &m2);
    v13 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v3);
    Scaleform::Render::TreeNode::SetViewMatrix3D(v13, &mat3D);
    if ( (Scaleform::GFx::DisplayObjectBase *)v11->MovieLevels.Data.Data->pSprite.pObject == v3 )
    {
      Scaleform::Render::TreeNode::SetViewMatrix3D((Scaleform::Render::TreeNode *)&v11->pRenderRoot.pObject->0, &mat3D);
      Scaleform::Render::TreeNode::SetViewMatrix3D((Scaleform::Render::TreeNode *)&v11->pTopMostRoot.pObject->0, &mat3D);
    }
  }
}

// File Line: 289
// RVA: 0x8BCAB0
void __fastcall Scaleform::GFx::DisplayObjectBase::ClearViewMatrix3D(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode *v1; // rax

  v1 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeNode::ClearViewMatrix3D(v1);
}

// File Line: 294
// RVA: 0x8DC460
char __fastcall Scaleform::GFx::DisplayObjectBase::GetProjectionMatrix3D(Scaleform::GFx::DisplayObjectBase *this, Scaleform::Render::Matrix4x4<float> *m, bool bInherit)
{
  Scaleform::GFx::DisplayObjectBase *v3; // rbx
  Scaleform::Render::TreeNode *v4; // rcx
  bool v5; // si
  Scaleform::Render::Matrix4x4<float> *v6; // rdi
  Scaleform::GFx::InteractiveObject *v8; // rcx
  Scaleform::GFx::MovieImpl *v9; // rcx

  v3 = this;
  v4 = this->pRenNode.pObject;
  v5 = bInherit;
  v6 = m;
  if ( v4 && Scaleform::Render::TreeNode::GetProjectionMatrix3D(v4, m) )
    return 1;
  if ( !v5 )
    return 0;
  v8 = v3->pParent;
  if ( v8 )
    return ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::Render::Matrix4x4<float> *, bool))v8->vfptr[6].__vecDelDtor)(
             v8,
             v6,
             v5);
  v9 = v3->pASRoot->pMovieImpl;
  if ( !v9 )
    return 0;
  return Scaleform::Render::TreeNode::GetProjectionMatrix3D(
           (Scaleform::Render::TreeNode *)&v9->pRenderRoot.pObject->0,
           v6);
}

// File Line: 315
// RVA: 0x909FE0
void __fastcall Scaleform::GFx::DisplayObjectBase::SetProjectionMatrix3D(Scaleform::GFx::DisplayObjectBase *this, Scaleform::Render::Matrix4x4<float> *m)
{
  Scaleform::GFx::DisplayObjectBase *v2; // rbx
  Scaleform::Render::TreeNode *v3; // rcx
  Scaleform::Render::Matrix4x4<float> *v4; // rsi
  bool v5; // r10
  Scaleform::GFx::InteractiveObject *v6; // r9
  Scaleform::Render::TreeNode *v7; // rcx
  Scaleform::Render::TreeNode *v8; // rax
  Scaleform::GFx::MovieImpl *v9; // rdi

  v2 = this;
  v3 = this->pRenNode.pObject;
  v4 = m;
  v5 = v3
    && (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v3 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8
                             * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v3[-1] - ((unsigned __int64)v3 & 0xFFFFFFFFFFFFF000ui64))
                                                                                  * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                              + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v3[-1]
                                                                                       - ((unsigned __int64)v3 & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                             + 40)
                 + 10i64) >> 12) & 1;
  v6 = v2->pParent;
  if ( !v6
    || (v7 = v6->pRenNode.pObject) == 0i64
    || !((*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                               + 8
                               * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v7[-1] - ((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64))
                                                                                    * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v7[-1]
                                                                                         - ((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64))
                                                                        * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                               + 40)
                   + 10i64) >> 9) & 1)
    || v6->pPerspectiveData
    || v5 )
  {
    v8 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v2);
    Scaleform::Render::TreeNode::SetProjectionMatrix3D(v8, v4);
    v9 = v2->pASRoot->pMovieImpl;
    if ( v9 )
    {
      if ( (Scaleform::GFx::DisplayObjectBase *)v9->MovieLevels.Data.Data->pSprite.pObject == v2 )
      {
        Scaleform::Render::TreeNode::SetProjectionMatrix3D(
          (Scaleform::Render::TreeNode *)&v9->pRenderRoot.pObject->0,
          v4);
        Scaleform::Render::TreeNode::SetProjectionMatrix3D(
          (Scaleform::Render::TreeNode *)&v9->pTopMostRoot.pObject->0,
          v4);
      }
    }
  }
}

// File Line: 335
// RVA: 0x8BC560
void __fastcall Scaleform::GFx::DisplayObjectBase::ClearProjectionMatrix3D(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode *v1; // rax

  v1 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeNode::ClearProjectionMatrix3D(v1);
}

// File Line: 340
// RVA: 0x9184B0
void __fastcall Scaleform::GFx::DisplayObjectBase::UpdateViewAndPerspective(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase *v1; // rbx
  Scaleform::GFx::MovieImpl *v2; // rsi
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v3; // rdi
  Scaleform::Render::Rect<float> *v4; // rsi
  float v5; // xmm8_4
  float v6; // xmm6_4
  float focalLength; // xmm12_4
  float v8; // xmm10_4
  float v9; // xmm11_4
  unsigned __int64 v10; // rax
  Scaleform::GFx::DisplayObjectBase *v11; // r15
  unsigned __int64 v12; // rdx
  __int64 v13; // rcx
  bool v14; // al
  char v15; // r14
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
  float v28; // xmm2_4
  float v29; // xmm1_4
  float v30; // xmm0_4
  float *v31; // rax
  float v32; // xmm0_4
  double *v33; // rax
  float fieldOfView; // xmm1_4
  double v35; // xmm0_8
  Scaleform::Render::Matrix2x4<float> pmat; // [rsp+40h] [rbp-A8h]
  int Dst; // [rsp+60h] [rbp-88h]
  int v38; // [rsp+70h] [rbp-78h]
  int v39; // [rsp+74h] [rbp-74h]
  Scaleform::Render::Matrix4x4<float> matPersp; // [rsp+78h] [rbp-70h]
  Scaleform::Render::Point<float> projCenter; // [rsp+148h] [rbp+60h]

  v1 = this;
  v2 = this->pASRoot->pMovieImpl;
  if ( v2 )
  {
    v3 = this->pPerspectiveData;
    if ( v3 )
    {
      if ( v3->FieldOfView != 0.0 || 0.0 != v3->FocalLength )
      {
        v4 = &v2->VisibleFrameRect;
        v5 = v4->x2;
        v6 = v4->x1;
        if ( v5 != v4->x1 || v4->y1 != v4->y2 )
        {
          memset(&Dst, 0, 0x30ui64);
          Dst = 1065353216;
          v39 = 1065353216;
          v38 = 1065353216;
          memset(&matPersp, 0, 0x40ui64);
          matPersp.M[0][0] = 1.0;
          matPersp.M[1][1] = 1.0;
          matPersp.M[2][2] = 1.0;
          matPersp.M[3][3] = 1.0;
          focalLength = 0.0;
          if ( Scaleform::GFx::NumberUtil::IsNaN(v3->ProjectionCenter.x)
            || Scaleform::GFx::NumberUtil::IsNaN(v3->ProjectionCenter.y) )
          {
            v32 = v4->y2 + v4->y1;
            projCenter.x = (float)(v6 + v5) * 0.5;
            projCenter.y = v32 * 0.5;
          }
          else
          {
            v8 = v3->ProjectionCenter.x;
            v9 = v3->ProjectionCenter.y;
            projCenter.x = v3->ProjectionCenter.x;
            projCenter.y = v9;
            v10 = (unsigned __int64)Scaleform::GFx::DisplayObjectBase::GetRenderNode(v1);
            v11 = v1->pParentChar;
            v12 = (signed __int64)((unsigned __int128)((signed __int64)(v10 - (v10 & 0xFFFFFFFFFFFFF000ui64) - 56)
                                                     * (signed __int128)5270498306774157605i64) >> 64) >> 4;
            v13 = *(_QWORD *)(*(_QWORD *)((v10 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                            + 8 * ((unsigned int)v12 + (v12 >> 63))
                            + 40);
            v14 = 0;
            v15 = (*(_WORD *)(v13 + 10) >> 9) & 1;
            if ( v11 )
            {
              v16 = v11->pPerspectiveData;
              if ( v16 )
                v14 = !Scaleform::GFx::NumberUtil::IsNaN(v16->ProjectionCenter.x)
                   && !Scaleform::GFx::NumberUtil::IsNaN(v16->ProjectionCenter.y);
            }
            if ( v1->pGeomData && (!v15 || v14) )
            {
              *(_OWORD *)&pmat.M[0][0] = _xmm;
              *(__m128 *)&pmat.M[1][0] = _xmm;
              if ( v11 )
              {
                Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v11, &pmat);
                v17 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v1->vfptr[2].__vecDelDtor)(v1);
                v19 = pmat.M[0][1];
                v18 = pmat.M[0][0];
                v20 = pmat.M[1][0];
                v21 = pmat.M[0][0];
                v22 = pmat.M[1][1];
                v23 = pmat.M[1][0];
                v24 = (float)(pmat.M[0][0] * *v17) + (float)(pmat.M[0][1] * v17[4]);
                pmat.M[0][0] = (float)(pmat.M[0][0] * *v17) + (float)(pmat.M[0][1] * v17[4]);
                v25 = (float)(pmat.M[1][0] * *v17) + (float)(pmat.M[1][1] * v17[4]);
                pmat.M[1][0] = (float)(pmat.M[1][0] * *v17) + (float)(pmat.M[1][1] * v17[4]);
                v26 = (float)(v21 * v17[1]) + (float)(pmat.M[0][1] * v17[5]);
                *(_QWORD *)&pmat.M[0][1] = LODWORD(v26);
                v27 = (float)(v23 * v17[1]) + (float)(pmat.M[1][1] * v17[5]);
                *(_QWORD *)&pmat.M[1][1] = LODWORD(v27);
                v28 = (float)(v19 * v17[7]) + (float)(v18 * v17[3]);
                v29 = pmat.M[0][3] + v28;
                pmat.M[0][3] = pmat.M[0][3] + v28;
                v30 = pmat.M[1][3] + (float)((float)(v22 * v17[7]) + (float)(v20 * v17[3]));
              }
              else
              {
                v31 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v1->vfptr[2].__vecDelDtor)(v1);
                v24 = *v31;
                pmat.M[0][0] = *v31;
                v26 = v31[1];
                *(_QWORD *)&pmat.M[0][1] = *(_QWORD *)(v31 + 1);
                v29 = v31[3];
                pmat.M[0][3] = v31[3];
                v25 = v31[4];
                pmat.M[1][0] = v31[4];
                v27 = v31[5];
                *(_QWORD *)&pmat.M[1][1] = *(_QWORD *)(v31 + 5);
                v30 = v31[7];
              }
              projCenter.y = (float)((float)(v27 * v9) + (float)(v25 * v8)) + v30;
              projCenter.x = (float)((float)(v26 * v9) + (float)(v24 * v8)) + v29;
            }
          }
          v33 = &v1->pPerspectiveData->FieldOfView;
          if ( *v33 == 0.0 )
            fieldOfView = FLOAT_55_0;
          else
            fieldOfView = *v33;
          v35 = v33[1];
          if ( v35 != 0.0 )
            focalLength = v35;
          Scaleform::GFx::MovieImpl::MakeViewAndPersp3D(
            (Scaleform::Render::Matrix3x4<float> *)&Dst,
            &matPersp,
            v4,
            &projCenter,
            fieldOfView,
            focalLength,
            0);
          v1->vfptr[10].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v1->vfptr, (unsigned int)&Dst);
          v1->vfptr[7].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v1->vfptr, (unsigned int)&matPersp);
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
  Scaleform::GFx::DisplayObjectBase *v3; // rbx
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v4; // rax
  double *v5; // rax
  long double v6; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v7; // [rsp+60h] [rbp+18h]

  v2 = fovdeg;
  v3 = this;
  v6 = fovdeg;
  if ( (*(_QWORD *)&fovdeg & 0x7FF0000000000000i64) != 9218868437227405312i64
    || !(*(_QWORD *)&fovdeg & 0xFFFFFFFFFFFFFi64) )
  {
    v6 = fovdeg;
    if ( fovdeg == -1.797693134862316e308/*-Inf*/ || (v6 = fovdeg, fovdeg == 1.797693134862316e308/*+Inf*/) )
      v2 = 0.0;
    if ( !this->pPerspectiveData )
    {
      LODWORD(v6) = 322;
      v4 = (Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::DisplayObjectBase *, signed __int64, long double *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                                       Scaleform::Memory::pGlobalHeap,
                                                                       this,
                                                                       80i64,
                                                                       &v6,
                                                                       -2i64);
      v7 = v4;
      if ( v4 )
        Scaleform::GFx::DisplayObjectBase::PerspectiveDataType::PerspectiveDataType(v4);
      v3->pPerspectiveData = v4;
    }
    v5 = &v3->pPerspectiveData->FieldOfView;
    if ( v2 != *v5 )
    {
      *v5 = v2;
      Scaleform::GFx::DisplayObjectBase::UpdateViewAndPerspective(v3);
    }
  }
}

// File Line: 414
// RVA: 0x8D7A40
double __fastcall Scaleform::GFx::DisplayObjectBase::GetFOV(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v1; // rax
  double result; // xmm0_8

  v1 = this->pPerspectiveData;
  if ( v1 )
    result = v1->FieldOfView;
  else
    result = 0.0;
  return result;
}

// File Line: 420
// RVA: 0x907440
void __fastcall Scaleform::GFx::DisplayObjectBase::SetFocalLength(Scaleform::GFx::DisplayObjectBase *this, long double focalLength)
{
  double v2; // xmm6_8
  Scaleform::GFx::DisplayObjectBase *v3; // rbx
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v4; // rax
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v5; // rax
  long double v6; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v7; // [rsp+60h] [rbp+18h]

  v2 = focalLength;
  v3 = this;
  v6 = focalLength;
  if ( (*(_QWORD *)&focalLength & 0x7FF0000000000000i64) != 9218868437227405312i64
    || !(*(_QWORD *)&focalLength & 0xFFFFFFFFFFFFFi64) )
  {
    v6 = focalLength;
    if ( focalLength == -1.797693134862316e308/*-Inf*/
      || (v6 = focalLength, focalLength == 1.797693134862316e308/*+Inf*/) )
    {
      v2 = 0.0;
    }
    if ( !this->pPerspectiveData )
    {
      LODWORD(v6) = 322;
      v4 = (Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::DisplayObjectBase *, signed __int64, long double *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                                       Scaleform::Memory::pGlobalHeap,
                                                                       this,
                                                                       80i64,
                                                                       &v6,
                                                                       -2i64);
      v7 = v4;
      if ( v4 )
        Scaleform::GFx::DisplayObjectBase::PerspectiveDataType::PerspectiveDataType(v4);
      v3->pPerspectiveData = v4;
    }
    v5 = v3->pPerspectiveData;
    if ( v2 != v5->FocalLength )
    {
      v5->FocalLength = v2;
      Scaleform::GFx::DisplayObjectBase::UpdateViewAndPerspective(v3);
    }
  }
}

// File Line: 438
// RVA: 0x8D8180
double __fastcall Scaleform::GFx::DisplayObjectBase::GetFocalLength(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v1; // rax
  double result; // xmm0_8

  v1 = this->pPerspectiveData;
  if ( v1 )
    result = v1->FocalLength;
  else
    result = 0.0;
  return result;
}

// File Line: 444
// RVA: 0x909E40
void __fastcall Scaleform::GFx::DisplayObjectBase::SetProjectionCenter(Scaleform::GFx::DisplayObjectBase *this, Scaleform::Render::Point<float> projCenter)
{
  float *v2; // rbx
  Scaleform::GFx::DisplayObjectBase *v3; // rsi
  float v4; // xmm2_4
  double v5; // xmm0_8
  float v6; // xmm1_4
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v7; // rdi
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v8; // rax
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v9; // rax
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v10; // rdx
  double v11; // xmm0_8
  double v12; // xmm0_8
  float v13; // xmm0_4
  double v14; // [rsp+68h] [rbp+10h]
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v15; // [rsp+70h] [rbp+18h]

  v2 = (float *)projCenter;
  v3 = this;
  v4 = **(float **)&projCenter;
  v5 = **(float **)&projCenter;
  v14 = v4;
  if ( (*(unsigned __int64 *)&v4 & 0x7FF0000000000000i64) != 9218868437227405312i64
    || !(*(_QWORD *)&v5 & 0xFFFFFFFFFFFFFi64) )
  {
    v6 = *(float *)(*(_QWORD *)&projCenter + 4i64);
    v14 = v6;
    if ( (*(unsigned __int64 *)&v6 & 0x7FF0000000000000i64) != 9218868437227405312i64
      || !(*(unsigned __int64 *)&v6 & 0xFFFFFFFFFFFFFi64) )
    {
      v7 = 0i64;
      if ( *(signed __int64 *)&v4 == -4503599627370496i64 || *(signed __int64 *)&v4 == 9218868437227405312i64 )
        **(_DWORD **)&projCenter = 0;
      v14 = v6;
      if ( *(signed __int64 *)&v6 == -4503599627370496i64
        || (v14 = v6, *(signed __int64 *)&v6 == 9218868437227405312i64) )
      {
        *(_DWORD *)(*(_QWORD *)&projCenter + 4i64) = 0;
      }
      if ( !this->pPerspectiveData )
      {
        LODWORD(v14) = 322;
        v8 = (Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::DisplayObjectBase *, signed __int64, double *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                                         Scaleform::Memory::pGlobalHeap,
                                                                         this,
                                                                         80i64,
                                                                         &v14,
                                                                         -2i64);
        v15 = v8;
        if ( v8 )
        {
          Scaleform::GFx::DisplayObjectBase::PerspectiveDataType::PerspectiveDataType(v8);
          v7 = v9;
        }
        v3->pPerspectiveData = v7;
      }
      v10 = v3->pPerspectiveData;
      v11 = v10->ProjectionCenter.x;
      v14 = v11;
      if ( (*(_QWORD *)&v11 & 0x7FF0000000000000i64) == 9218868437227405312i64 && *(_QWORD *)&v11 & 0xFFFFFFFFFFFFFi64
        || (v12 = v10->ProjectionCenter.y, v14 = v12,
                                           (*(_QWORD *)&v12 & 0x7FF0000000000000i64) == 9218868437227405312i64)
        && *(_QWORD *)&v12 & 0xFFFFFFFFFFFFFi64
        || *v2 != v10->ProjectionCenter.x
        || v2[1] != v10->ProjectionCenter.y )
      {
        v13 = v2[1];
        v10->ProjectionCenter.x = *v2;
        v10->ProjectionCenter.y = v13;
        Scaleform::GFx::DisplayObjectBase::UpdateViewAndPerspective(v3);
      }
    }
  }
}

// File Line: 466
// RVA: 0x8DC410
Scaleform::Render::Point<float> *__fastcall Scaleform::GFx::DisplayObjectBase::GetProjectionCenter(Scaleform::GFx::DisplayObjectBase *this, Scaleform::Render::Point<float> *result)
{
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType *v2; // rax
  Scaleform::Render::Point<float> v4; // [rsp+8h] [rbp+8h]

  v2 = this->pPerspectiveData;
  if ( v2 )
    v4 = v2->ProjectionCenter;
  else
    v4 = 0i64;
  *result = v4;
  return result;
}

// File Line: 471
// RVA: 0x8D6740
Scaleform::Render::Cxform *__fastcall Scaleform::GFx::DisplayObjectBase::GetCxform(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode *v1; // rdx
  unsigned __int64 v2; // r8
  unsigned __int64 v3; // rdx

  v1 = this->pRenNode.pObject;
  if ( !v1 )
    return &Scaleform::Render::Cxform::Identity;
  v2 = (unsigned __int64)v1 & 0xFFFFFFFFFFFFF000ui64;
  v3 = (signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v1[-1]
                                                           - ((unsigned __int64)v1 & 0xFFFFFFFFFFFFF000ui64))
                                          * (signed __int128)5270498306774157605i64) >> 64) >> 4;
  return (Scaleform::Render::Cxform *)(*(_QWORD *)(*(_QWORD *)(v2 + 32) + 8 * ((unsigned int)v3 + (v3 >> 63)) + 40)
                                     + 80i64);
}

// File Line: 478
// RVA: 0x906C20
void __fastcall Scaleform::GFx::DisplayObjectBase::SetCxform(Scaleform::GFx::DisplayObjectBase *this, Scaleform::Render::Cxform *cx)
{
  Scaleform::Render::Cxform *v2; // rbx
  Scaleform::Render::TreeNode *v3; // rax
  Scaleform::Render::ContextImpl::EntryData *v4; // rax

  v2 = cx;
  v3 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  v4 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&v3->0, 2u);
  v4[5] = *(Scaleform::Render::ContextImpl::EntryData *)&v2->M[0][0];
  v4[6] = *(Scaleform::Render::ContextImpl::EntryData *)&v2->M[1][0];
}

// File Line: 506
// RVA: 0x906710
void __fastcall Scaleform::GFx::DisplayObjectBase::SetBlendMode(Scaleform::GFx::DisplayObjectBase *this, Scaleform::Render::BlendMode blend)
{
  Scaleform::Render::BlendMode v2; // ebx
  char v3; // si
  Scaleform::GFx::DisplayObjectBase *v4; // rdi
  Scaleform::Render::TreeNode *v5; // rax

  v2 = blend;
  v3 = blend;
  v4 = this;
  if ( blend == 1 )
    v2 = 0;
  v5 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeNode::SetBlendMode(v5, v2);
  v4->BlendMode = v3;
}

// File Line: 515
// RVA: 0x8D4DD0
Scaleform::Render::State *__fastcall Scaleform::GFx::DisplayObjectBase::GetBlendMode(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase *v1; // rbx
  Scaleform::Render::TreeNode *v2; // rax
  Scaleform::Render::State *result; // rax

  v1 = this;
  if ( !Scaleform::GFx::DisplayObjectBase::GetRenderNode(this) )
    return (Scaleform::Render::State *)(unsigned __int8)v1->BlendMode;
  v2 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v1);
  result = Scaleform::Render::TreeNode::GetState(v2, State_BlendMode);
  if ( result )
    result = (Scaleform::Render::State *)LODWORD(result->DataValue);
  return result;
}

// File Line: 522
// RVA: 0x8D59C0
bool __fastcall Scaleform::GFx::DisplayObjectBase::GetCacheAsBitmap(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase *v1; // rbx
  Scaleform::Render::TreeNode *v2; // rax
  Expression::IMemberMap *v3; // rax
  Scaleform::Render::FilterSet *v4; // rax
  bool result; // al

  v1 = this;
  if ( Scaleform::GFx::DisplayObjectBase::GetRenderNode(this)
    && (v2 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v1),
        (v3 = (Expression::IMemberMap *)Scaleform::Render::TreeNode::GetState(v2, State_Filter)) != 0i64)
    && (v4 = (Scaleform::Render::FilterSet *)Scaleform::GFx::Stream::GetLog(v3)) != 0i64 )
  {
    result = Scaleform::Render::FilterSet::GetCacheAsBitmap(v4);
  }
  else
  {
    result = 0;
  }
  return result;
}

// File Line: 534
// RVA: 0x906830
void __fastcall Scaleform::GFx::DisplayObjectBase::SetCacheAsBitmap(Scaleform::GFx::DisplayObjectBase *this, bool enable)
{
  bool v2; // bl
  Scaleform::GFx::DisplayObjectBase *v3; // rdi
  Scaleform::Render::TreeNode *v4; // rax
  Expression::IMemberMap *v5; // rax
  Scaleform::Render::FilterSet *v6; // rax
  Scaleform::Render::FilterSet *v7; // rsi
  Scaleform::Render::FilterSet *v8; // rsi
  Scaleform::Render::RenderBuffer *v9; // rcx
  Scaleform::Render::FilterSet *v10; // rax
  Scaleform::Render::FilterSet *v11; // rax
  Scaleform::Render::FilterSet *v12; // rbx

  v2 = enable;
  v3 = this;
  if ( Scaleform::GFx::DisplayObjectBase::GetRenderNode(this) )
  {
    v4 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v3);
    v5 = (Expression::IMemberMap *)Scaleform::Render::TreeNode::GetState(v4, State_Filter);
    if ( v5 && (v6 = (Scaleform::Render::FilterSet *)Scaleform::GFx::Stream::GetLog(v5), (v7 = v6) != 0i64) )
    {
      if ( v2 != Scaleform::Render::FilterSet::GetCacheAsBitmap(v6) )
      {
        v8 = Scaleform::Render::FilterSet::Clone(v7, 0, 0i64);
        Scaleform::Render::FilterSet::SetCacheAsBitmap(v8, v2);
        v3->vfptr[56].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v3->vfptr, (unsigned int)v8);
        if ( v8 )
        {
          v9 = (Scaleform::Render::RenderBuffer *)v8;
LABEL_13:
          Scaleform::RefCountImpl::Release(v9);
          return;
        }
      }
    }
    else if ( v2 )
    {
      v10 = (Scaleform::Render::FilterSet *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->Alloc)(
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
      v3->vfptr[56].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v3->vfptr, (unsigned int)v12);
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
void __fastcall Scaleform::GFx::DisplayObjectBase::SetFilters(Scaleform::GFx::DisplayObjectBase *this, Scaleform::Render::FilterSet *filters)
{
  Scaleform::Render::FilterSet *v2; // rdi
  Scaleform::GFx::DisplayObjectBase *v3; // rbx
  Scaleform::Render::TreeNode *v4; // rax

  v2 = filters;
  v3 = this;
  if ( Scaleform::GFx::DisplayObjectBase::GetRenderNode(this) )
  {
    v4 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v3);
    Scaleform::Render::TreeNode::SetFilters(v4, v2);
  }
}

// File Line: 564
// RVA: 0x8D7D20
Expression::IMemberMap *__fastcall Scaleform::GFx::DisplayObjectBase::GetFilters(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase *v1; // rbx
  Scaleform::Render::TreeNode *v2; // rax
  Expression::IMemberMap *v3; // rax
  Expression::IMemberMap *result; // rax

  v1 = this;
  if ( Scaleform::GFx::DisplayObjectBase::GetRenderNode(this)
    && (v2 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v1),
        (v3 = (Expression::IMemberMap *)Scaleform::Render::TreeNode::GetState(v2, State_Filter)) != 0i64) )
  {
    result = Scaleform::GFx::Stream::GetLog(v3);
  }
  else
  {
    result = 0i64;
  }
  return result;
}

// File Line: 573
// RVA: 0x90F260
void __fastcall Scaleform::GFx::DisplayObjectBase::SetVisibleFlag(Scaleform::GFx::DisplayObjectBase *this, bool v)
{
  Scaleform::Render::TreeNode *v2; // rcx
  Scaleform::Render::TreeNode *v3; // rax

  if ( v )
  {
    this->Flags |= 0x4000u;
    v2 = this->pRenNode.pObject;
    if ( v2 )
      Scaleform::Render::TreeNode::SetVisible(v2, v);
  }
  else
  {
    this->Flags &= 0xBFFFu;
    v3 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    Scaleform::Render::TreeNode::SetVisible(v3, 0);
  }
}

// File Line: 588
// RVA: 0x8B70B0
void __fastcall Scaleform::GFx::DisplayObjectBase::BindAvmObj(Scaleform::GFx::DisplayObjectBase *this, Scaleform::GFx::AvmDisplayObjBase *p)
{
  this->AvmObjOffset = (unsigned __int64)((char *)p - (char *)this + 3) >> 2;
}

// File Line: 599
// RVA: 0x8E1AC0
void __fastcall Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(Scaleform::GFx::DisplayObjectBase *this, Scaleform::Render::Matrix2x4<float> *pmat)
{
  Scaleform::GFx::DisplayObjectBase *v2; // rdi
  Scaleform::GFx::InteractiveObject *v3; // rcx
  Scaleform::Render::Matrix2x4<float> *v4; // rbx
  Scaleform::Render::Matrix2x4<float> *v5; // rax
  float *v6; // rax

  v2 = this;
  v3 = this->pParent;
  v4 = pmat;
  if ( v3 )
  {
    Scaleform::GFx::DisplayObjectBase::GetWorldMatrix((Scaleform::GFx::DisplayObjectBase *)&v3->vfptr, pmat);
    v5 = (Scaleform::Render::Matrix2x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v2->vfptr[2].__vecDelDtor)(v2);
    Scaleform::Render::Matrix2x4<float>::Prepend(v4, v5);
  }
  else
  {
    v6 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v2->vfptr[2].__vecDelDtor)(v2);
    v4->M[0][0] = *v6;
    v4->M[0][1] = v6[1];
    v4->M[0][2] = v6[2];
    v4->M[0][3] = v6[3];
    v4->M[1][0] = v6[4];
    v4->M[1][1] = v6[5];
    v4->M[1][2] = v6[6];
    v4->M[1][3] = v6[7];
  }
}

// File Line: 612
// RVA: 0x8E1A20
void __fastcall Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D(Scaleform::GFx::DisplayObjectBase *this, Scaleform::Render::Matrix3x4<float> *pmat)
{
  Scaleform::GFx::DisplayObjectBase *v2; // rdi
  Scaleform::GFx::InteractiveObject *v3; // rcx
  Scaleform::Render::Matrix3x4<float> *v4; // rbx
  Scaleform::Render::Matrix3x4<float> *v5; // rax
  float *v6; // rax

  v2 = this;
  v3 = this->pParent;
  v4 = pmat;
  if ( v3 )
  {
    Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D((Scaleform::GFx::DisplayObjectBase *)&v3->vfptr, pmat);
    v5 = (Scaleform::Render::Matrix3x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v2->vfptr[4].__vecDelDtor)(v2);
    Scaleform::Render::Matrix3x4<float>::Prepend(v4, v5);
  }
  else
  {
    v6 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v2->vfptr[4].__vecDelDtor)(v2);
    v4->M[0][0] = *v6;
    v4->M[0][1] = v6[1];
    v4->M[0][2] = v6[2];
    v4->M[0][3] = v6[3];
    v4->M[1][0] = v6[4];
    v4->M[1][1] = v6[5];
    v4->M[1][2] = v6[6];
    v4->M[1][3] = v6[7];
    v4->M[2][0] = v6[8];
    v4->M[2][1] = v6[9];
    v4->M[2][2] = v6[10];
    v4->M[2][3] = v6[11];
  }
}

// File Line: 625
// RVA: 0x8BB5E0
void __fastcall Scaleform::GFx::DisplayObjectBase::Clear3D(Scaleform::GFx::DisplayObjectBase *this, bool bInherit)
{
  Scaleform::GFx::DisplayObjectBase *v2; // rbx
  Scaleform::GFx::InteractiveObject *v3; // rcx
  Scaleform::Render::TreeNode *v4; // rcx
  Scaleform::GFx::DisplayObjectBase::GeomDataType gd; // [rsp+20h] [rbp-68h]

  v2 = this;
  if ( bInherit )
  {
    v3 = this->pParent;
    if ( v3 )
      Scaleform::GFx::DisplayObjectBase::Clear3D((Scaleform::GFx::DisplayObjectBase *)&v3->vfptr, bInherit);
  }
  *(_QWORD *)&gd.X = 0i64;
  *(_OWORD *)&gd.OrigMatrix.M[0][0] = _xmm;
  *(__m128 *)&gd.OrigMatrix.M[1][0] = _xmm;
  gd.YScale = DOUBLE_100_0;
  gd.XScale = DOUBLE_100_0;
  gd.Rotation = 0.0;
  *(_OWORD *)&gd.XRotation = 0i64;
  *(_OWORD *)&gd.Z = _xmm;
  Scaleform::GFx::DisplayObjectBase::SetGeomData(v2, &gd);
  v4 = v2->pRenNode.pObject;
  if ( v4 )
    Scaleform::Render::TreeNode::Clear3D(v4);
  ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v2->vfptr[12].__vecDelDtor)(v2);
}

// File Line: 641
// RVA: 0x8E6E00
bool __fastcall Scaleform::GFx::DisplayObjectBase::Is3D(Scaleform::GFx::DisplayObjectBase *this, bool bInherit)
{
  Scaleform::Render::TreeNode *v2; // r9
  bool result; // al

  do
  {
    v2 = this->pRenNode.pObject;
    result = v2
          && (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                   + 8
                                   * (((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v2[-1]
                                                                                             - ((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64))
                                                                            * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                                    + (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v2[-1] - ((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64))
                                                                                        * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                                   + 40)
                       + 10i64) >> 9) & 1;
    if ( !bInherit )
      break;
    if ( result )
      return 1;
    this = this->pParentChar;
  }
  while ( this );
  return result;
}

// File Line: 657
// RVA: 0x8DAB70
void __fastcall Scaleform::GFx::DisplayObjectBase::GetLevelMatrix(Scaleform::GFx::DisplayObjectBase *this, Scaleform::Render::Matrix2x4<float> *pmat)
{
  Scaleform::GFx::DisplayObjectBase *v2; // rdi
  Scaleform::GFx::InteractiveObject *v3; // rcx
  Scaleform::Render::Matrix2x4<float> *v4; // rbx
  Scaleform::Render::Matrix2x4<float> *v5; // rax

  v2 = this;
  v3 = this->pParent;
  v4 = pmat;
  if ( v3 )
  {
    Scaleform::GFx::DisplayObjectBase::GetLevelMatrix((Scaleform::GFx::DisplayObjectBase *)&v3->vfptr, pmat);
    v5 = (Scaleform::Render::Matrix2x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v2->vfptr[2].__vecDelDtor)(v2);
    Scaleform::Render::Matrix2x4<float>::Prepend(v4, v5);
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
Scaleform::Render::Point<float> *__fastcall Scaleform::GFx::DisplayObjectBase::Local3DToGlobal(Scaleform::GFx::DisplayObjectBase *this, Scaleform::Render::Point<float> *result, Scaleform::Render::Point3<float> *ptIn)
{
  Scaleform::GFx::DisplayObjectBase *v3; // rbx
  Scaleform::Render::TreeNode *v4; // rcx
  Scaleform::Render::Point3<float> *v5; // r14
  Scaleform::Render::Point<float> *v6; // rsi
  Scaleform::GFx::DisplayObjectBase *v7; // rdi
  Scaleform::RefCountNTSImplCoreVtbl *v8; // rax
  __int64 v9; // r8
  Scaleform::RefCountNTSImplCoreVtbl *v10; // rax
  __int64 v11; // r8
  Scaleform::GFx::DisplayObjectBase *v12; // rcx
  Scaleform::Render::Matrix3x4<float> *v13; // rax
  _OWORD *v14; // rax
  Scaleform::GFx::ASMovieRootBase *v15; // rax
  float *v16; // rdi
  float v17; // xmm4_4
  float v18; // xmm3_4
  float v19; // xmm5_4
  float v20; // xmm0_4
  float v21; // xmm7_4
  float v22; // xmm6_4
  Scaleform::GFx::ASMovieRootBase *v23; // rax
  float v24; // xmm7_4
  float v25; // xmm8_4
  float v26; // xmm9_4
  float v27; // xmm10_4
  float *v28; // rax
  float v29; // xmm1_4
  float v30; // xmm2_4
  float v31; // xmm3_4
  float v32; // xmm5_4
  float v33; // xmm4_4
  float v34; // xmm6_4
  float v35; // xmm7_4
  float v36; // xmm8_4
  float v37; // xmm5_4
  float v38; // xmm6_4
  float v39; // xmm2_4
  float v40; // xmm1_4
  float v41; // xmm0_4
  float *v42; // rax
  Scaleform::Render::Matrix3x4<float> pmat; // [rsp+20h] [rbp-D8h]
  __int64 v45; // [rsp+50h] [rbp-A8h]
  __int64 v46; // [rsp+58h] [rbp-A0h]
  int v47; // [rsp+60h] [rbp-98h]
  int v48; // [rsp+64h] [rbp-94h]
  __int64 v49; // [rsp+68h] [rbp-90h]
  __int64 v50; // [rsp+70h] [rbp-88h]
  int v51; // [rsp+78h] [rbp-80h]
  int v52; // [rsp+7Ch] [rbp-7Ch]
  Scaleform::Render::Matrix3x4<float> m1; // [rsp+88h] [rbp-70h]
  Scaleform::Render::Matrix4x4<float> v54; // [rsp+C8h] [rbp-30h]
  int Dst; // [rsp+108h] [rbp+10h]
  int v56; // [rsp+11Ch] [rbp+24h]
  int v57; // [rsp+130h] [rbp+38h]
  Scaleform::Render::Matrix4x4<float> v58; // [rsp+138h] [rbp+40h]

  v3 = this;
  v4 = this->pRenNode.pObject;
  v5 = ptIn;
  v6 = result;
  if ( v4
    && (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v4 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8
                             * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v4[-1] - ((unsigned __int64)v4 & 0xFFFFFFFFFFFFF000ui64))
                                                                                  * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                              + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v4[-1]
                                                                                       - ((unsigned __int64)v4 & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                             + 40)
                 + 10i64) >> 9) & 1
    || (v7 = v3->pParentChar) != 0i64 && Scaleform::GFx::DisplayObjectBase::Is3D(v3->pParentChar, 1) )
  {
    memset(&Dst, 0, 0x30ui64);
    v8 = v3->vfptr;
    LOBYTE(v9) = 1;
    Dst = 1065353216;
    v56 = 1065353216;
    v57 = 1065353216;
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, int *, __int64))v8[9].__vecDelDtor)(v3, &Dst, v9);
    memset(&v58, 0, 0x40ui64);
    v10 = v3->vfptr;
    LOBYTE(v11) = 1;
    v58.M[0][0] = 1.0;
    v58.M[1][1] = 1.0;
    v58.M[2][2] = 1.0;
    v58.M[3][3] = 1.0;
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Matrix4x4<float> *, __int64))v10[6].__vecDelDtor)(
      v3,
      &v58,
      v11);
    memset(&pmat, 0, 0x30ui64);
    v12 = v3->pParentChar;
    pmat.M[0][0] = 1.0;
    pmat.M[1][1] = 1.0;
    pmat.M[2][2] = 1.0;
    if ( v12 )
    {
      Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D(v12, &pmat);
      v13 = (Scaleform::Render::Matrix3x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v3->vfptr[4].__vecDelDtor)(v3);
      m1 = pmat;
      Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&pmat, &m1, v13);
    }
    else
    {
      v14 = (_OWORD *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v3->vfptr[4].__vecDelDtor)(v3);
      *(_OWORD *)&pmat.M[0][0] = *v14;
      *(_OWORD *)&pmat.M[1][0] = v14[1];
      *(_OWORD *)&pmat.M[2][0] = v14[2];
    }
    Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(
      (Scaleform::Render::Matrix4x4<float> *)&m1,
      &v58,
      (Scaleform::Render::Matrix3x4<float> *)&Dst);
    Scaleform::Render::Matrix4x4<float>::MultiplyMatrix(&v54, (Scaleform::Render::Matrix4x4<float> *)&m1, &pmat);
    v15 = v3->pASRoot;
    v16 = 0i64;
    v17 = v5->y;
    v18 = v5->x;
    v19 = v5->z;
    v45 = 0i64;
    v46 = 0i64;
    v48 = 1;
    v47 = 1;
    v50 = 0i64;
    v49 = 0i64;
    v51 = 1065353216;
    v52 = 1065353216;
    v20 = 1.0
        / (float)((float)((float)((float)(v54.M[3][0] * v18) + (float)(v54.M[3][1] * v17)) + (float)(v54.M[3][2] * v19))
                + v54.M[3][3]);
    v21 = (float)((float)((float)((float)(v54.M[0][0] * v18) + (float)(v54.M[0][1] * v17)) + (float)(v54.M[0][2] * v19))
                + v54.M[0][3])
        * v20;
    v22 = (float)((float)((float)((float)(v54.M[1][0] * v18) + (float)(v54.M[1][1] * v17)) + (float)(v54.M[1][2] * v19))
                + v54.M[1][3])
        * v20;
    v15->pMovieImpl->vfptr[13].__vecDelDtor((Scaleform::RefCountImplCore *)&v15->pMovieImpl->vfptr, (unsigned int)&v45);
    v23 = v3->pASRoot;
    v24 = (float)((float)(v21 + 1.0) * (float)v47) * 0.5;
    v25 = (float)((float)(1.0 - v22) * (float)v48) * 0.5;
    if ( v23 )
      v16 = (float *)v23->pMovieImpl;
    if ( v16 )
    {
      v24 = (float)((float)(v24 * v16[54]) + v16[56]) * 20.0;
      v25 = (float)((float)(v25 * v16[55]) + v16[57]) * 20.0;
    }
    v6->x = v24;
    v6->y = v25;
  }
  else
  {
    v26 = v5->x;
    *(_OWORD *)&pmat.M[0][0] = _xmm;
    *(__m128 *)&pmat.M[1][0] = _xmm;
    v27 = v5->y;
    if ( v7 )
    {
      Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v7, (Scaleform::Render::Matrix2x4<float> *)&pmat);
      v28 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v3->vfptr[2].__vecDelDtor)(v3);
      v30 = pmat.M[0][1];
      v29 = pmat.M[0][0];
      v31 = pmat.M[1][0];
      v32 = pmat.M[0][0];
      v33 = pmat.M[1][1];
      v34 = pmat.M[1][0];
      v35 = (float)(pmat.M[0][0] * *v28) + (float)(pmat.M[0][1] * v28[4]);
      pmat.M[0][0] = (float)(pmat.M[0][0] * *v28) + (float)(pmat.M[0][1] * v28[4]);
      v36 = (float)(pmat.M[1][0] * *v28) + (float)(pmat.M[1][1] * v28[4]);
      pmat.M[1][0] = (float)(pmat.M[1][0] * *v28) + (float)(pmat.M[1][1] * v28[4]);
      v37 = (float)(v32 * v28[1]) + (float)(pmat.M[0][1] * v28[5]);
      *(_QWORD *)&pmat.M[0][1] = LODWORD(v37);
      v38 = (float)(v34 * v28[1]) + (float)(pmat.M[1][1] * v28[5]);
      *(_QWORD *)&pmat.M[1][1] = LODWORD(v38);
      v39 = (float)(v30 * v28[7]) + (float)(v29 * v28[3]);
      v40 = pmat.M[0][3] + v39;
      pmat.M[0][3] = pmat.M[0][3] + v39;
      v41 = pmat.M[1][3] + (float)((float)(v33 * v28[7]) + (float)(v31 * v28[3]));
    }
    else
    {
      v42 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v3->vfptr[2].__vecDelDtor)(v3);
      v35 = *v42;
      pmat.M[0][0] = *v42;
      v37 = v42[1];
      *(_QWORD *)&pmat.M[0][1] = *(_QWORD *)(v42 + 1);
      v40 = v42[3];
      pmat.M[0][3] = v42[3];
      v36 = v42[4];
      pmat.M[1][0] = v42[4];
      v38 = v42[5];
      *(_QWORD *)&pmat.M[1][1] = *(_QWORD *)(v42 + 5);
      v41 = v42[7];
    }
    v6->x = (float)((float)(v37 * v27) + (float)(v35 * v26)) + v40;
    v6->y = (float)((float)(v38 * v27) + (float)(v36 * v26)) + v41;
  }
  return v6;
}

// File Line: 727
// RVA: 0x8E20C0
Scaleform::Render::Point<float> *__fastcall Scaleform::GFx::DisplayObjectBase::GlobalToLocal(Scaleform::GFx::DisplayObjectBase *this, Scaleform::Render::Point<float> *result, Scaleform::Render::Point<float> *ptIn)
{
  Scaleform::Render::Point<float> *v3; // rbx
  Scaleform::GFx::MovieImpl *v4; // r9
  float v5; // xmm4_4
  float v6; // xmm6_4
  float v7; // xmm0_4

  v3 = result;
  v4 = this->pASRoot->pMovieImpl;
  if ( v4 )
  {
    v5 = v4->ViewOffsetX;
    v6 = (float)(ptIn->x - v5) / v4->ViewScaleX;
    v7 = v4->VisibleFrameRect.x2 - v4->VisibleFrameRect.x1;
    LODWORD(v4->ScreenToWorld.Sy) = COERCE_UNSIGNED_INT(
                                      (float)((float)((float)((float)((float)(ptIn->y - v4->ViewOffsetY) / v4->ViewScaleY)
                                                            - (float)(v4->ViewOffsetY * 20.0))
                                                    / (float)(v4->VisibleFrameRect.y2 - v4->VisibleFrameRect.y1))
                                            * 2.0)
                                    - 1.0) ^ _xmm[0];
    v4->ScreenToWorld.Sx = (float)((float)((float)(v6 - (float)(v5 * 20.0)) / v7) * 2.0) - 1.0;
    Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(this, result, ptIn, 0, 0i64);
  }
  return v3;
}

// File Line: 746
// RVA: 0x8E2080
Scaleform::Render::Point3<float> *__fastcall Scaleform::GFx::DisplayObjectBase::GlobalToLocal3D(Scaleform::GFx::DisplayObjectBase *this, Scaleform::Render::Point3<float> *result, Scaleform::Render::Point<float> *ptIn)
{
  Scaleform::Render::Point3<float> *v3; // rbx
  Scaleform::Render::Point3<float> *v4; // rax
  float v5; // xmm1_4
  Scaleform::Render::Point<float> resulta; // [rsp+38h] [rbp+10h]

  v3 = result;
  Scaleform::GFx::DisplayObjectBase::GlobalToLocal(this, &resulta, ptIn);
  v3->z = 0.0;
  v4 = v3;
  v5 = resulta.y;
  v3->x = resulta.x;
  v3->y = v5;
  return v4;
}

// File Line: 754
// RVA: 0x9134A0
void __fastcall Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(Scaleform::GFx::DisplayObjectBase *this, Scaleform::Render::Point<float> *p, Scaleform::Render::Point<float> *pt, bool bPtInParentSpace, Scaleform::Render::Matrix2x4<float> *mat)
{
  Scaleform::GFx::DisplayObjectBase *v5; // rdi
  Scaleform::Render::TreeNode *v6; // rcx
  Scaleform::Render::Point<float> *v7; // r14
  Scaleform::Render::Point<float> *v8; // rsi
  Scaleform::Render::Matrix2x4<float> *v9; // rcx
  Scaleform::GFx::DisplayObjectBase *v10; // rbx
  Scaleform::GFx::DisplayObjectBase *v11; // rcx
  Scaleform::Render::Matrix3x4<float> *v12; // rax
  __int64 v13; // r8
  _OWORD *v14; // rax
  signed __int64 v15; // rbx
  __int64 v16; // r8
  float *v17; // rax
  float v18; // xmm6_4
  __int64 v19; // kr00_8
  float v20; // xmm5_4
  float v21; // xmm0_4
  float v22; // xmm2_4
  _OWORD *v23; // rax
  Scaleform::Render::Matrix3x4<float> pmat; // [rsp+20h] [rbp-91h]
  int Dst; // [rsp+50h] [rbp-61h]
  int v26; // [rsp+54h] [rbp-5Dh]
  int v27; // [rsp+58h] [rbp-59h]
  int v28; // [rsp+5Ch] [rbp-55h]
  int v29; // [rsp+60h] [rbp-51h]
  int v30; // [rsp+64h] [rbp-4Dh]
  int v31; // [rsp+68h] [rbp-49h]
  int v32; // [rsp+6Ch] [rbp-45h]
  int v33; // [rsp+70h] [rbp-41h]
  int v34; // [rsp+74h] [rbp-3Dh]
  int v35; // [rsp+78h] [rbp-39h]
  int v36; // [rsp+7Ch] [rbp-35h]
  int v37; // [rsp+80h] [rbp-31h]
  int v38; // [rsp+84h] [rbp-2Dh]
  int v39; // [rsp+88h] [rbp-29h]
  int v40; // [rsp+8Ch] [rbp-25h]
  int v41; // [rsp+90h] [rbp-21h]
  int v42; // [rsp+94h] [rbp-1Dh]
  int v43; // [rsp+98h] [rbp-19h]
  int v44; // [rsp+9Ch] [rbp-15h]
  int v45; // [rsp+A0h] [rbp-11h]
  int v46; // [rsp+A4h] [rbp-Dh]
  int v47; // [rsp+A8h] [rbp-9h]
  int v48; // [rsp+ACh] [rbp-5h]
  int v49; // [rsp+B0h] [rbp-1h]
  int v50; // [rsp+B4h] [rbp+3h]
  int v51; // [rsp+B8h] [rbp+7h]
  int v52; // [rsp+BCh] [rbp+Bh]
  Scaleform::Render::Matrix3x4<float> m1; // [rsp+C0h] [rbp+Fh]

  v5 = this;
  v6 = this->pRenNode.pObject;
  v7 = pt;
  v8 = p;
  if ( bPtInParentSpace )
  {
    if ( !v6
      || !((*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v6 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                 + 8
                                 * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v6[-1] - ((unsigned __int64)v6 & 0xFFFFFFFFFFFFF000ui64))
                                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                  + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v6[-1]
                                                                                           - ((unsigned __int64)v6 & 0xFFFFFFFFFFFFF000ui64))
                                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                 + 40)
                     + 10i64) >> 9) & 1) )
    {
      v9 = mat;
      if ( mat )
      {
LABEL_23:
        Scaleform::Render::Matrix2x4<float>::TransformByInverse(v9, v8, pt);
        return;
      }
      v9 = (Scaleform::Render::Matrix2x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v5->vfptr[2].__vecDelDtor)(v5);
LABEL_22:
      pt = v7;
      goto LABEL_23;
    }
  }
  else if ( !v6
         || !((*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v6 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                    + 8
                                    * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v6[-1] - ((unsigned __int64)v6 & 0xFFFFFFFFFFFFF000ui64))
                                                                                         * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                     + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v6[-1]
                                                                                              - ((unsigned __int64)v6 & 0xFFFFFFFFFFFFF000ui64))
                                                                             * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                    + 40)
                        + 10i64) >> 9) & 1) )
  {
    v10 = v5->pParentChar;
    if ( !v10 || !Scaleform::GFx::DisplayObjectBase::Is3D(v5->pParentChar, 1) )
    {
      *(_OWORD *)&pmat.M[0][0] = _xmm;
      *(__m128 *)&pmat.M[1][0] = _xmm;
      if ( v10 )
      {
        Scaleform::GFx::DisplayObjectBase::GetWorldMatrix(v10, (Scaleform::Render::Matrix2x4<float> *)&pmat);
        v17 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v5->vfptr[2].__vecDelDtor)(v5);
        v18 = pmat.M[1][0];
        v19 = *(_QWORD *)&pmat.M[0][0];
        v20 = pmat.M[1][1];
        pmat.M[0][0] = (float)(pmat.M[0][0] * *v17) + (float)(pmat.M[0][1] * v17[4]);
        pmat.M[1][0] = (float)(pmat.M[1][0] * *v17) + (float)(pmat.M[1][1] * v17[4]);
        pmat.M[0][1] = (float)(*(float *)&v19 * v17[1]) + (float)(pmat.M[0][1] * v17[5]);
        v21 = pmat.M[1][1] * v17[5];
        v22 = v18 * v17[1];
        pmat.M[0][2] = 0.0;
        *(_QWORD *)&pmat.M[1][1] = COERCE_UNSIGNED_INT(v22 + v21);
        pmat.M[0][3] = pmat.M[0][3] + (float)((float)(*((float *)&v19 + 1) * v17[7]) + (float)(*(float *)&v19 * v17[3]));
        pmat.M[1][3] = pmat.M[1][3] + (float)((float)(v18 * v17[3]) + (float)(v20 * v17[7]));
      }
      else
      {
        v23 = (_OWORD *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v5->vfptr[2].__vecDelDtor)(v5);
        *(_OWORD *)&pmat.M[0][0] = *v23;
        *(_OWORD *)&pmat.M[1][0] = v23[1];
      }
      v9 = (Scaleform::Render::Matrix2x4<float> *)&pmat;
      goto LABEL_22;
    }
  }
  memset(&Dst, 0, 0x30ui64);
  Dst = 1065353216;
  v30 = 1065353216;
  v35 = 1065353216;
  memset(&v37, 0, 0x40ui64);
  v37 = 1065353216;
  v42 = 1065353216;
  v47 = 1065353216;
  v52 = 1065353216;
  memset(&pmat, 0, 0x30ui64);
  v11 = v5->pParentChar;
  pmat.M[0][0] = 1.0;
  pmat.M[1][1] = 1.0;
  pmat.M[2][2] = 1.0;
  if ( v11 )
  {
    Scaleform::GFx::DisplayObjectBase::GetWorldMatrix3D(v11, &pmat);
    v12 = (Scaleform::Render::Matrix3x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v5->vfptr[4].__vecDelDtor)(v5);
    m1 = pmat;
    Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&pmat, &m1, v12);
  }
  else
  {
    v14 = (_OWORD *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v5->vfptr[4].__vecDelDtor)(v5);
    *(_OWORD *)&pmat.M[0][0] = *v14;
    *(_OWORD *)&pmat.M[1][0] = v14[1];
    *(_OWORD *)&pmat.M[2][0] = v14[2];
  }
  LOBYTE(v13) = 1;
  v15 = (signed __int64)&v5->pASRoot->pMovieImpl->ScreenToWorld;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, int *, __int64))v5->vfptr[6].__vecDelDtor)(
         v5,
         &v37,
         v13) )
  {
    *(_DWORD *)(v15 + 16) = v37;
    *(_DWORD *)(v15 + 20) = v38;
    *(_DWORD *)(v15 + 24) = v39;
    *(_DWORD *)(v15 + 28) = v40;
    *(_DWORD *)(v15 + 32) = v41;
    *(_DWORD *)(v15 + 36) = v42;
    *(_DWORD *)(v15 + 40) = v43;
    *(_DWORD *)(v15 + 44) = v44;
    *(_DWORD *)(v15 + 48) = v45;
    *(_DWORD *)(v15 + 52) = v46;
    *(_DWORD *)(v15 + 56) = v47;
    *(_DWORD *)(v15 + 60) = v48;
    *(_DWORD *)(v15 + 64) = v49;
    *(_DWORD *)(v15 + 68) = v50;
    *(_DWORD *)(v15 + 72) = v51;
    *(_DWORD *)(v15 + 76) = v52;
  }
  LOBYTE(v16) = 1;
  if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, int *, __int64))v5->vfptr[9].__vecDelDtor)(
         v5,
         &Dst,
         v16) )
  {
    *(_DWORD *)(v15 + 80) = Dst;
    *(_DWORD *)(v15 + 84) = v26;
    *(_DWORD *)(v15 + 88) = v27;
    *(_DWORD *)(v15 + 92) = v28;
    *(_DWORD *)(v15 + 96) = v29;
    *(_DWORD *)(v15 + 100) = v30;
    *(_DWORD *)(v15 + 104) = v31;
    *(_DWORD *)(v15 + 108) = v32;
    *(_DWORD *)(v15 + 112) = v33;
    *(_DWORD *)(v15 + 116) = v34;
    *(_DWORD *)(v15 + 120) = v35;
    *(_DWORD *)(v15 + 124) = v36;
  }
  *(_OWORD *)(v15 + 128) = *(_OWORD *)&pmat.M[0][0];
  *(_OWORD *)(v15 + 144) = *(_OWORD *)&pmat.M[1][0];
  *(_OWORD *)(v15 + 160) = *(_OWORD *)&pmat.M[2][0];
  Scaleform::Render::ScreenToWorld::GetWorldPoint((Scaleform::Render::ScreenToWorld *)v15, v8);
}

// File Line: 811
// RVA: 0x8E1530
__int64 __fastcall Scaleform::GFx::DisplayObjectBase::GetVersion(Scaleform::GFx::DisplayObjectBase *this)
{
  __int64 v1; // rax

  v1 = ((__int64 (*)(void))this->vfptr[66].__vecDelDtor)();
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
    this = this->pParentChar;
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
    this = this->pParentChar;
    if ( !this )
      return (MEMORY[0x52D0] >> 2) & 1;
  }
  return (this->pASRoot->pMovieImpl->Flags >> 2) & 1;
}

// File Line: 828
// RVA: 0x8E7DD0
__int64 __fastcall Scaleform::GFx::DisplayObjectBase::IsVerboseActionErrors(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase::PerspectiveDataType **v1; // rax

  v1 = &this[-1].pPerspectiveData;
  if ( this == (Scaleform::GFx::DisplayObjectBase *)24 )
    return ~(unsigned __int8)(MEMORY[0x52D0] >> 6) & 1;
  while ( *((_BYTE *)v1 + 106) >= 0 )
  {
    v1 = (Scaleform::GFx::DisplayObjectBase::PerspectiveDataType **)v1[7];
    if ( !v1 )
      return ~(unsigned __int8)(MEMORY[0x52D0] >> 6) & 1;
  }
  return ~(unsigned __int8)(*(_DWORD *)(*(_QWORD *)&v1[4]->ProjectionCenter + 21200i64) >> 6) & 1;
}

// File Line: 833
// RVA: 0x8EC940
void __fastcall Scaleform::GFx::DisplayObjectBase::OnEventUnload(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase *v1; // rbx
  unsigned __int16 v2; // ax
  Scaleform::GFx::DisplayObjectBase *v3; // rdx
  Scaleform::GFx::MovieImpl *v4; // rcx
  Scaleform::RefCountNTSImplCoreVtbl *v5; // rax
  __int64 v6; // [rsp+20h] [rbp-28h]
  int v7; // [rsp+28h] [rbp-20h]
  char v8; // [rsp+2Ch] [rbp-1Ch]
  int v9; // [rsp+30h] [rbp-18h]

  v1 = this;
  v2 = this->Flags | 0x1000;
  this->Flags = v2;
  if ( ((unsigned __int8)v2 >> 1) & 1 )
  {
    v3 = this;
    while ( SLOBYTE(v3->Flags) >= 0 )
    {
      v3 = v3->pParentChar;
      if ( !v3 )
      {
        v4 = 0i64;
        goto LABEL_7;
      }
    }
    v4 = v3->pASRoot->pMovieImpl;
LABEL_7:
    Scaleform::GFx::MovieImpl::RemoveTopmostLevelCharacter(v4, v1);
  }
  if ( !((LOBYTE(v1->Flags) >> 4) & 1) )
  {
    v5 = v1->vfptr;
    v6 = 4i64;
    v7 = 0;
    v8 = 0;
    v9 = 65280;
    v5[72].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v1->vfptr, (unsigned int)&v6);
    v1->Flags |= 0x10u;
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
Scaleform::GFx::DisplayObjectBase::GeomDataType *__fastcall Scaleform::GFx::DisplayObjectBase::GetGeomData(Scaleform::GFx::DisplayObjectBase *this, Scaleform::GFx::DisplayObjectBase::GeomDataType *geomData)
{
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v2; // rbx
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v3; // rdx
  Scaleform::GFx::DisplayObjectBase *v4; // rdi
  float *v5; // rax
  __m128d v6; // xmm1
  __m128d v7; // xmm2
  float *v8; // rax

  v2 = geomData;
  v3 = this->pGeomData;
  v4 = this;
  if ( v3 )
  {
    v2->X = v3->X;
    v2->Y = v3->Y;
    v2->XScale = v3->XScale;
    v2->YScale = v3->YScale;
    v2->Rotation = v3->Rotation;
    v2->OrigMatrix.M[0][0] = v3->OrigMatrix.M[0][0];
    v2->OrigMatrix.M[0][1] = v3->OrigMatrix.M[0][1];
    v2->OrigMatrix.M[0][2] = v3->OrigMatrix.M[0][2];
    v2->OrigMatrix.M[0][3] = v3->OrigMatrix.M[0][3];
    v2->OrigMatrix.M[1][0] = v3->OrigMatrix.M[1][0];
    v2->OrigMatrix.M[1][1] = v3->OrigMatrix.M[1][1];
    v2->OrigMatrix.M[1][2] = v3->OrigMatrix.M[1][2];
    v2->OrigMatrix.M[1][3] = v3->OrigMatrix.M[1][3];
    v2->Z = v3->Z;
    v2->ZScale = v3->ZScale;
    v2->XRotation = v3->XRotation;
    v2->YRotation = v3->YRotation;
  }
  else
  {
    v5 = (float *)((__int64 (*)(void))this->vfptr[2].__vecDelDtor)();
    v2->X = (signed int)v5[3];
    v2->Y = (signed int)v5[7];
    v6 = _mm_cvtps_pd((__m128)*(unsigned int *)v5);
    v6.m128d_f64[0] = v6.m128d_f64[0] * v6.m128d_f64[0] + v5[4] * v5[4];
    v2->XScale = COERCE_DOUBLE(_mm_sqrt_pd(v6)) * 100.0;
    v7 = _mm_cvtps_pd((__m128)*((unsigned int *)v5 + 1));
    v7.m128d_f64[0] = v7.m128d_f64[0] * v7.m128d_f64[0] + v5[5] * v5[5];
    v2->YScale = COERCE_DOUBLE(_mm_sqrt_pd(v7)) * 100.0;
    v2->Rotation = atan2(v5[4], *v5) * 180.0 * 0.3183098861837907;
    v8 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v4->vfptr[2].__vecDelDtor)(v4);
    v2->OrigMatrix.M[0][0] = *v8;
    v2->OrigMatrix.M[0][1] = v8[1];
    v2->OrigMatrix.M[0][2] = v8[2];
    v2->OrigMatrix.M[0][3] = v8[3];
    v2->OrigMatrix.M[1][0] = v8[4];
    v2->OrigMatrix.M[1][1] = v8[5];
    v2->OrigMatrix.M[1][2] = v8[6];
    v2->OrigMatrix.M[1][3] = v8[7];
  }
  return v2;
}

// File Line: 898
// RVA: 0x907650
void __fastcall Scaleform::GFx::DisplayObjectBase::SetGeomData(Scaleform::GFx::DisplayObjectBase *this, Scaleform::GFx::DisplayObjectBase::GeomDataType *gd)
{
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v2; // rbx
  Scaleform::GFx::DisplayObjectBase *v3; // rdi
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v4; // rdx
  __int64 v5; // rax
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v6; // rdx
  int v7; // [rsp+50h] [rbp+18h]
  __int64 v8; // [rsp+58h] [rbp+20h]

  v2 = gd;
  v3 = this;
  v4 = this->pGeomData;
  if ( v4 )
  {
    v4->X = v2->X;
    v4->Y = v2->Y;
    v4->XScale = v2->XScale;
    v4->YScale = v2->YScale;
    v4->Rotation = v2->Rotation;
    v4->OrigMatrix.M[0][0] = v2->OrigMatrix.M[0][0];
    v4->OrigMatrix.M[0][1] = v2->OrigMatrix.M[0][1];
    v4->OrigMatrix.M[0][2] = v2->OrigMatrix.M[0][2];
    v4->OrigMatrix.M[0][3] = v2->OrigMatrix.M[0][3];
    v4->OrigMatrix.M[1][0] = v2->OrigMatrix.M[1][0];
    v4->OrigMatrix.M[1][1] = v2->OrigMatrix.M[1][1];
    v4->OrigMatrix.M[1][2] = v2->OrigMatrix.M[1][2];
    v4->OrigMatrix.M[1][3] = v2->OrigMatrix.M[1][3];
    v4->Z = v2->Z;
    v4->ZScale = v2->ZScale;
    v4->XRotation = v2->XRotation;
    v4->YRotation = v2->YRotation;
  }
  else
  {
    v7 = 322;
    v5 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::DisplayObjectBase *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
           Scaleform::Memory::pGlobalHeap,
           this,
           96i64,
           &v7,
           -2i64);
    v6 = (Scaleform::GFx::DisplayObjectBase::GeomDataType *)v5;
    v8 = v5;
    if ( v5 )
    {
      *(_DWORD *)v5 = v2->X;
      *(_DWORD *)(v5 + 4) = v2->Y;
      *(long double *)(v5 + 8) = v2->XScale;
      *(long double *)(v5 + 16) = v2->YScale;
      *(long double *)(v5 + 24) = v2->Rotation;
      *(float *)(v5 + 32) = v2->OrigMatrix.M[0][0];
      *(float *)(v5 + 36) = v2->OrigMatrix.M[0][1];
      *(float *)(v5 + 40) = v2->OrigMatrix.M[0][2];
      *(float *)(v5 + 44) = v2->OrigMatrix.M[0][3];
      *(float *)(v5 + 48) = v2->OrigMatrix.M[1][0];
      *(float *)(v5 + 52) = v2->OrigMatrix.M[1][1];
      *(float *)(v5 + 56) = v2->OrigMatrix.M[1][2];
      *(float *)(v5 + 60) = v2->OrigMatrix.M[1][3];
      *(long double *)(v5 + 64) = v2->Z;
      *(long double *)(v5 + 72) = v2->ZScale;
      *(long double *)(v5 + 80) = v2->XRotation;
      *(long double *)(v5 + 88) = v2->YRotation;
    }
    else
    {
      v6 = 0i64;
    }
    v3->pGeomData = v6;
  }
}

// File Line: 906
// RVA: 0x8C88E0
void __fastcall Scaleform::GFx::DisplayObjectBase::EnsureGeomDataCreated(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase *v1; // rbx
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v2; // rax
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [rsp+20h] [rbp-68h]

  v1 = this;
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
    Scaleform::GFx::DisplayObjectBase::SetGeomData(v1, v2);
  }
}

// File Line: 915
// RVA: 0x8AFF30
void __fastcall Scaleform::GFx::ASCharacter_MatrixScaleAndRotate2x2(Scaleform::Render::Matrix2x4<float> *m, float sx, float sy, float radians)
{
  float *v4; // rbx
  float v5; // xmm10_4
  float v6; // xmm9_4
  float v7; // xmm0_4
  float v8; // xmm7_4
  float v9; // xmm5_4
  float v10; // xmm4_4
  float v11; // xmm3_4
  float v12; // xmm2_4

  v4 = (float *)m;
  v5 = sy;
  v6 = cosf(radians);
  v7 = sinf(radians);
  v8 = v4[1];
  v9 = v4[5];
  v10 = *v4 * v7;
  v11 = v4[4] * v6;
  v12 = (float)(*v4 * v6) - (float)(v4[4] * v7);
  v4[5] = (float)((float)(v8 * v7) + (float)(v9 * v6)) * v5;
  v4[1] = (float)((float)(v8 * v6) - (float)(v9 * v7)) * v5;
  *v4 = v12 * sx;
  v4[4] = (float)(v10 + v11) * sx;
}

// File Line: 930
// RVA: 0x90F760
int Scaleform::GFx::DisplayObjectBase::SetX(...)
{
  __m128d v2; // xmm6
  Scaleform::GFx::DisplayObjectBase *v3; // rbx
  int *v4; // rax
  __int64 v5; // rcx
  float v6; // xmm2_4
  float v7; // [rsp+20h] [rbp-38h]
  float v8; // [rsp+24h] [rbp-34h]
  float v9; // [rsp+28h] [rbp-30h]
  float v10; // [rsp+2Ch] [rbp-2Ch]
  float v11; // [rsp+30h] [rbp-28h]
  float v12; // [rsp+34h] [rbp-24h]
  float v13; // [rsp+38h] [rbp-20h]
  float v14; // [rsp+3Ch] [rbp-1Ch]

  v2 = (__m128d)x;
  v3 = this;
  if ( (x & 0x7FF0000000000000i64) != 9218868437227405312i64 || !(x & 0xFFFFFFFFFFFFFi64) )
  {
    if ( (_QWORD)x == -4503599627370496i64 || (_QWORD)x == 9218868437227405312i64 )
      v2 = 0i64;
    this->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)this, 0);
    v4 = (int *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v3->vfptr[2].__vecDelDtor)(v3);
    v2.m128d_f64[0] = v2.m128d_f64[0] * 20.0;
    v7 = *(float *)v4;
    v5 = (unsigned int)(signed int)v2.m128d_f64[0];
    v8 = *((float *)v4 + 1);
    v9 = *((float *)v4 + 2);
    v10 = *((float *)v4 + 3);
    v11 = *((float *)v4 + 4);
    v12 = *((float *)v4 + 5);
    v13 = *((float *)v4 + 6);
    v14 = *((float *)v4 + 7);
    if ( v5 != 0x8000000000000000i64 && (double)(signed int)v5 != v2.m128d_f64[0] )
      v2.m128d_f64[0] = (double)(signed int)(v5 - (_mm_movemask_pd(_mm_unpckl_pd(v2, v2)) & 1));
    v3->pGeomData->X = (signed int)v2.m128d_f64[0];
    v6 = (float)v3->pGeomData->X;
    v10 = (float)v3->pGeomData->X;
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
      v3->vfptr[3].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v3->vfptr, (unsigned int)&v7);
    }
  }
}

// File Line: 947
// RVA: 0x90FF10
int Scaleform::GFx::DisplayObjectBase::SetY(...)
{
  __m128d v2; // xmm6
  Scaleform::GFx::DisplayObjectBase *v3; // rbx
  int *v4; // rax
  __int64 v5; // rcx
  float v6; // xmm2_4
  float v7; // [rsp+20h] [rbp-38h]
  float v8; // [rsp+24h] [rbp-34h]
  float v9; // [rsp+28h] [rbp-30h]
  float v10; // [rsp+2Ch] [rbp-2Ch]
  float v11; // [rsp+30h] [rbp-28h]
  float v12; // [rsp+34h] [rbp-24h]
  float v13; // [rsp+38h] [rbp-20h]
  float v14; // [rsp+3Ch] [rbp-1Ch]

  v2 = (__m128d)y;
  v3 = this;
  if ( (y & 0x7FF0000000000000i64) != 9218868437227405312i64 || !(y & 0xFFFFFFFFFFFFFi64) )
  {
    if ( (_QWORD)y == -4503599627370496i64 || (_QWORD)y == 9218868437227405312i64 )
      v2 = 0i64;
    this->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)this, 0);
    v4 = (int *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v3->vfptr[2].__vecDelDtor)(v3);
    v2.m128d_f64[0] = v2.m128d_f64[0] * 20.0;
    v7 = *(float *)v4;
    v5 = (unsigned int)(signed int)v2.m128d_f64[0];
    v8 = *((float *)v4 + 1);
    v9 = *((float *)v4 + 2);
    v10 = *((float *)v4 + 3);
    v11 = *((float *)v4 + 4);
    v12 = *((float *)v4 + 5);
    v13 = *((float *)v4 + 6);
    v14 = *((float *)v4 + 7);
    if ( v5 != 0x8000000000000000i64 && (double)(signed int)v5 != v2.m128d_f64[0] )
      v2.m128d_f64[0] = (double)(signed int)(v5 - (_mm_movemask_pd(_mm_unpckl_pd(v2, v2)) & 1));
    v3->pGeomData->Y = (signed int)v2.m128d_f64[0];
    v6 = (float)v3->pGeomData->Y;
    v14 = (float)v3->pGeomData->Y;
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
      v3->vfptr[3].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v3->vfptr, (unsigned int)&v7);
    }
  }
}

// File Line: 963
// RVA: 0x9106E0
void __fastcall Scaleform::GFx::DisplayObjectBase::SetZ(Scaleform::GFx::DisplayObjectBase *this, long double z)
{
  long double v2; // xmm6_8
  Scaleform::GFx::DisplayObjectBase *v3; // rbx
  Scaleform::GFx::ASMovieRootBase *v4; // rcx

  v2 = z;
  v3 = this;
  if ( (*(_QWORD *)&z & 0x7FF0000000000000i64) != 9218868437227405312i64 || !(*(_QWORD *)&z & 0xFFFFFFFFFFFFFi64) )
  {
    if ( z == -1.797693134862316e308/*-Inf*/ || z == 1.797693134862316e308/*+Inf*/ )
      v2 = 0.0;
    v4 = this->pASRoot;
    if ( v4 && ((unsigned __int8 (*)(void))v4->pMovieImpl->vfptr[70].__vecDelDtor)() )
      Scaleform::GFx::DisplayObjectBase::EnsureGeomDataCreated(v3);
    else
      v3->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v3->vfptr, 0);
    v3->pGeomData->Z = v2;
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v3->vfptr[13].__vecDelDtor)(v3);
  }
}

// File Line: 981
// RVA: 0x90FC80
void __fastcall Scaleform::GFx::DisplayObjectBase::SetXScale(Scaleform::GFx::DisplayObjectBase *this, long double xscale)
{
  double v2; // xmm7_8
  Scaleform::GFx::DisplayObjectBase *v3; // rbx
  bool v4; // zf
  Scaleform::RefCountNTSImplCoreVtbl *v5; // rax
  __int64 v6; // rax
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v7; // rdi
  float v8; // xmm10_4
  __m128d v9; // xmm2
  __m128 v10; // xmm9
  double v11; // xmm8_8
  long double v12; // xmm6_8
  long double v13; // xmm0_8
  float v14; // xmm1_4
  Scaleform::Render::Matrix2x4<float> m; // [rsp+20h] [rbp-78h]

  v2 = xscale;
  v3 = this;
  if ( ((*(_QWORD *)&xscale & 0x7FF0000000000000i64) != 9218868437227405312i64
     || !(*(_QWORD *)&xscale & 0xFFFFFFFFFFFFFi64))
    && xscale != -1.797693134862316e308/*-Inf*/
    && xscale != 1.797693134862316e308/*+Inf*/ )
  {
    this->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)this, 0);
    v3->pGeomData->XScale = xscale;
    v4 = Scaleform::GFx::DisplayObjectBase::Has3D(v3) == 0;
    v5 = v3->vfptr;
    if ( v4 )
    {
      v6 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v5[2].__vecDelDtor)(v3);
      v7 = v3->pGeomData;
      m.M[0][0] = v7->OrigMatrix.M[0][0];
      v8 = v7->OrigMatrix.M[0][1];
      v9 = _mm_cvtps_pd((__m128)LODWORD(m.M[0][0]));
      *(_QWORD *)&m.M[0][1] = *(_QWORD *)&v7->OrigMatrix.M[0][1];
      m.M[0][3] = v7->OrigMatrix.M[0][3];
      m.M[1][0] = v7->OrigMatrix.M[1][0];
      v10 = (__m128)LODWORD(v7->OrigMatrix.M[1][1]);
      *(_QWORD *)&m.M[1][1] = *(_QWORD *)&v7->OrigMatrix.M[1][1];
      m.M[1][3] = v7->OrigMatrix.M[1][3];
      m.M[0][3] = *(float *)(v6 + 12);
      v9.m128d_f64[0] = v9.m128d_f64[0] * v9.m128d_f64[0] + m.M[1][0] * m.M[1][0];
      m.M[1][3] = *(float *)(v6 + 28);
      *(_QWORD *)&v11 = (unsigned __int128)_mm_sqrt_pd(v9);
      if ( v11 == 0.0 || xscale > 1.0e16 )
      {
        v11 = DOUBLE_1_0;
        v2 = 0.0;
      }
      v12 = v7->Rotation * 3.141592653589793 * 0.005555555555555556;
      v13 = atan2(m.M[1][0], m.M[0][0]);
      v10.m128_f32[0] = (float)(v10.m128_f32[0] * v10.m128_f32[0]) + (float)(v8 * v8);
      v14 = v2 / (v11 * 100.0);
      Scaleform::GFx::ASCharacter_MatrixScaleAndRotate2x2(
        &m,
        v14,
        v7->YScale / (COERCE_DOUBLE(_mm_sqrt_pd(_mm_cvtps_pd(v10))) * 100.0),
        v12 - v13);
      if ( Scaleform::Render::Matrix2x4<float>::IsValid(&m) )
        v3->vfptr[3].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v3->vfptr, (unsigned int)&m);
    }
    else
    {
      ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v5[13].__vecDelDtor)(v3);
    }
  }
}

// File Line: 1019
// RVA: 0x910440
void __fastcall Scaleform::GFx::DisplayObjectBase::SetYScale(Scaleform::GFx::DisplayObjectBase *this, long double yscale)
{
  double v2; // xmm7_8
  Scaleform::GFx::DisplayObjectBase *v3; // rbx
  bool v4; // zf
  Scaleform::RefCountNTSImplCoreVtbl *v5; // rax
  __int64 v6; // rax
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v7; // rdi
  float v8; // xmm10_4
  __m128 v9; // xmm9
  __m128d v10; // xmm2
  double v11; // xmm8_8
  long double v12; // xmm6_8
  long double v13; // xmm0_8
  float v14; // xmm2_4
  Scaleform::Render::Matrix2x4<float> m; // [rsp+20h] [rbp-78h]

  v2 = yscale;
  v3 = this;
  if ( ((*(_QWORD *)&yscale & 0x7FF0000000000000i64) != 9218868437227405312i64
     || !(*(_QWORD *)&yscale & 0xFFFFFFFFFFFFFi64))
    && yscale != -1.797693134862316e308/*-Inf*/
    && yscale != 1.797693134862316e308/*+Inf*/ )
  {
    this->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)this, 0);
    v3->pGeomData->YScale = yscale;
    v4 = Scaleform::GFx::DisplayObjectBase::Has3D(v3) == 0;
    v5 = v3->vfptr;
    if ( v4 )
    {
      v6 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v5[2].__vecDelDtor)(v3);
      v7 = v3->pGeomData;
      v8 = v7->OrigMatrix.M[0][0];
      *(_OWORD *)&m.M[0][0] = *(_OWORD *)&v7->OrigMatrix.M[0][0];
      v9 = (__m128)LODWORD(v7->OrigMatrix.M[1][0]);
      *(_OWORD *)&m.M[1][0] = *(_OWORD *)&v7->OrigMatrix.M[1][0];
      m.M[0][3] = *(float *)(v6 + 12);
      v10 = _mm_cvtps_pd((__m128)LODWORD(m.M[0][1]));
      m.M[1][3] = *(float *)(v6 + 28);
      v10.m128d_f64[0] = v10.m128d_f64[0] * v10.m128d_f64[0] + m.M[1][1] * m.M[1][1];
      *(_QWORD *)&v11 = (unsigned __int128)_mm_sqrt_pd(v10);
      if ( v11 == 0.0 || yscale > 1.0e16 )
      {
        v11 = DOUBLE_1_0;
        v2 = 0.0;
      }
      v12 = v7->Rotation * 3.141592653589793 * 0.005555555555555556;
      v13 = atan2(v9.m128_f32[0], v8);
      v9.m128_f32[0] = (float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(v8 * v8);
      v14 = v2 / (v11 * 100.0);
      Scaleform::GFx::ASCharacter_MatrixScaleAndRotate2x2(
        &m,
        v7->XScale / (COERCE_DOUBLE(_mm_sqrt_pd(_mm_cvtps_pd(v9))) * 100.0),
        v14,
        v12 - v13);
      if ( Scaleform::Render::Matrix2x4<float>::IsValid(&m) )
        v3->vfptr[3].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v3->vfptr, (unsigned int)&m);
    }
    else
    {
      ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v5[13].__vecDelDtor)(v3);
    }
  }
}

// File Line: 1057
// RVA: 0x9107A0
void __fastcall Scaleform::GFx::DisplayObjectBase::SetZScale(Scaleform::GFx::DisplayObjectBase *this, long double zscale)
{
  Scaleform::GFx::DisplayObjectBase *v2; // rbx
  Scaleform::GFx::ASMovieRootBase *v3; // rcx

  v2 = this;
  if ( ((*(_QWORD *)&zscale & 0x7FF0000000000000i64) != 9218868437227405312i64
     || !(*(_QWORD *)&zscale & 0xFFFFFFFFFFFFFi64))
    && zscale != -1.797693134862316e308/*-Inf*/
    && zscale != 1.797693134862316e308/*+Inf*/ )
  {
    v3 = this->pASRoot;
    if ( v3 && ((unsigned __int8 (*)(void))v3->pMovieImpl->vfptr[70].__vecDelDtor)() )
      Scaleform::GFx::DisplayObjectBase::EnsureGeomDataCreated(v2);
    else
      v2->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, 0);
    v2->pGeomData->ZScale = zscale;
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v2->vfptr[13].__vecDelDtor)(v2);
  }
}

// File Line: 1077
// RVA: 0x90B1A0
void __fastcall Scaleform::GFx::DisplayObjectBase::SetRotation(Scaleform::GFx::DisplayObjectBase *this, long double rotation)
{
  Scaleform::GFx::DisplayObjectBase *v2; // rdi
  double v3; // xmm0_8
  double v4; // xmm10_8
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v5; // rax
  Scaleform::Render::TreeNode *v6; // rcx
  __int64 v7; // rax
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v8; // rbx
  __m128 v9; // xmm8
  __m128 v10; // xmm6
  float v11; // xmm3_4
  float v12; // xmm2_4
  Scaleform::Render::Matrix2x4<float> m; // [rsp+20h] [rbp-78h]

  v2 = this;
  if ( (*(_QWORD *)&rotation & 0x7FF0000000000000i64) != 9218868437227405312i64
    || !(*(_QWORD *)&rotation & 0xFFFFFFFFFFFFFi64) )
  {
    this->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)this, 0);
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
    v5 = v2->pGeomData;
    if ( v2->pASRoot->AVMVersion == 1 )
      v5->Rotation = v4;
    else
      v5->Rotation = rotation;
    v6 = v2->pRenNode.pObject;
    if ( v6
      && (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v6 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                               + 8
                               * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v6[-1] - ((unsigned __int64)v6 & 0xFFFFFFFFFFFFF000ui64))
                                                                                    * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v6[-1]
                                                                                         - ((unsigned __int64)v6 & 0xFFFFFFFFFFFFF000ui64))
                                                                        * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                               + 40)
                   + 10i64) >> 9) & 1 )
    {
      ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v2->vfptr[13].__vecDelDtor)(v2);
    }
    else
    {
      v7 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v2->vfptr[2].__vecDelDtor)(v2);
      v8 = v2->pGeomData;
      m.M[0][0] = v8->OrigMatrix.M[0][0];
      *(_QWORD *)&m.M[0][1] = *(_QWORD *)&v8->OrigMatrix.M[0][1];
      m.M[0][3] = v8->OrigMatrix.M[0][3];
      m.M[1][0] = v8->OrigMatrix.M[1][0];
      v9 = (__m128)LODWORD(m.M[1][0]);
      *(_QWORD *)&m.M[1][1] = *(_QWORD *)&v8->OrigMatrix.M[1][1];
      v10 = (__m128)LODWORD(m.M[1][1]);
      m.M[1][3] = v8->OrigMatrix.M[1][3];
      m.M[0][3] = *(float *)(v7 + 12);
      m.M[1][3] = *(float *)(v7 + 28);
      v10.m128_f32[0] = (float)(v10.m128_f32[0] * v10.m128_f32[0]) + (float)(m.M[0][1] * m.M[0][1]);
      v9.m128_f32[0] = (float)(v9.m128_f32[0] * v9.m128_f32[0]) + (float)(m.M[0][0] * m.M[0][0]);
      v11 = v4 * 3.141592653589793 * 0.005555555555555556 - atan2(m.M[1][0], m.M[0][0]);
      v12 = v8->YScale / (COERCE_DOUBLE(_mm_sqrt_pd(_mm_cvtps_pd(v10))) * 100.0);
      Scaleform::GFx::ASCharacter_MatrixScaleAndRotate2x2(
        &m,
        v8->XScale / (COERCE_DOUBLE(_mm_sqrt_pd(_mm_cvtps_pd(v9))) * 100.0),
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
        v2->vfptr[3].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, (unsigned int)&m);
      }
    }
  }
}lDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, (un

// File Line: 1118
// RVA: 0x90FB90
void __fastcall Scaleform::GFx::DisplayObjectBase::SetXRotation(Scaleform::GFx::DisplayObjectBase *this, long double rotation)
{
  Scaleform::GFx::DisplayObjectBase *v2; // rbx
  Scaleform::GFx::ASMovieRootBase *v3; // rcx
  double v4; // xmm0_8

  v2 = this;
  if ( (*(_QWORD *)&rotation & 0x7FF0000000000000i64) != 9218868437227405312i64
    || !(*(_QWORD *)&rotation & 0xFFFFFFFFFFFFFi64) )
  {
    v3 = this->pASRoot;
    if ( v3 && ((unsigned __int8 (*)(void))v3->pMovieImpl->vfptr[70].__vecDelDtor)() )
      Scaleform::GFx::DisplayObjectBase::EnsureGeomDataCreated(v2);
    else
      v2->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, 0);
    if ( v2->pASRoot->AVMVersion == 1 )
    {
      v4 = fmod(rotation, 360.0);
      if ( v4 <= 180.0 )
      {
        if ( v4 < -180.0 )
          v4 = v4 + 360.0;
        v2->pGeomData->XRotation = v4;
      }
      else
      {
        v2->pGeomData->XRotation = v4 + -360.0;
      }
    }
    else
    {
      v2->pGeomData->XRotation = rotation;
    }
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v2->vfptr[13].__vecDelDtor)(v2);
  }
}

// File Line: 1145
// RVA: 0x910350
void __fastcall Scaleform::GFx::DisplayObjectBase::SetYRotation(Scaleform::GFx::DisplayObjectBase *this, long double rotation)
{
  Scaleform::GFx::DisplayObjectBase *v2; // rbx
  Scaleform::GFx::ASMovieRootBase *v3; // rcx
  double v4; // xmm0_8

  v2 = this;
  if ( (*(_QWORD *)&rotation & 0x7FF0000000000000i64) != 9218868437227405312i64
    || !(*(_QWORD *)&rotation & 0xFFFFFFFFFFFFFi64) )
  {
    v3 = this->pASRoot;
    if ( v3 && ((unsigned __int8 (*)(void))v3->pMovieImpl->vfptr[70].__vecDelDtor)() )
      Scaleform::GFx::DisplayObjectBase::EnsureGeomDataCreated(v2);
    else
      v2->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, 0);
    if ( v2->pASRoot->AVMVersion == 1 )
    {
      v4 = fmod(rotation, 360.0);
      if ( v4 <= 180.0 )
      {
        if ( v4 < -180.0 )
          v4 = v4 + 360.0;
        v2->pGeomData->YRotation = v4;
      }
      else
      {
        v2->pGeomData->YRotation = v4 + -360.0;
      }
    }
    else
    {
      v2->pGeomData->YRotation = rotation;
    }
    ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v2->vfptr[13].__vecDelDtor)(v2);
  }
}

// File Line: 1172
// RVA: 0x90F2B0
void __fastcall Scaleform::GFx::DisplayObjectBase::SetWidth(Scaleform::GFx::DisplayObjectBase *this, long double width)
{
  double v2; // xmm8_8
  Scaleform::GFx::DisplayObjectBase *v3; // rdi
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v4; // rax
  float v5; // xmm1_4
  Scaleform::RefCountNTSImplCoreVtbl *v6; // rax
  __int64 v7; // rax
  float v8; // xmm4_4
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v9; // rax
  double v10; // xmm6_8
  float v11; // xmm7_4
  float v12; // xmm0_4
  float v13; // xmm6_4
  float *v14; // rax
  float v15; // xmm1_4
  float v16; // xmm6_4
  __m128d v17; // xmm1
  double v18; // xmm8_8
  double v19; // xmm7_8
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v20; // rbx
  double v21; // xmm6_8
  long double v22; // xmm0_8
  __m128 v23; // xmm1
  float v24; // xmm3_4
  Scaleform::Render::Matrix2x4<float> m; // [rsp+20h] [rbp-49h]
  Scaleform::Render::Matrix2x4<float> v26; // [rsp+40h] [rbp-29h]
  Scaleform::Render::Matrix2x4<float> v27; // [rsp+60h] [rbp-9h]

  v2 = width;
  v3 = this;
  if ( ((*(_QWORD *)&width & 0x7FF0000000000000i64) != 9218868437227405312i64
     || !(*(_QWORD *)&width & 0xFFFFFFFFFFFFFi64))
    && width != -1.797693134862316e308/*-Inf*/ )
  {
    if ( width == 1.797693134862316e308/*+Inf*/ )
      v2 = 0.0;
    this->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)this, 0);
    v4 = v3->pGeomData;
    *(_OWORD *)&v26.M[0][0] = *(_OWORD *)&v4->OrigMatrix.M[0][0];
    *(_QWORD *)&v26.M[1][0] = *(_QWORD *)&v4->OrigMatrix.M[1][0];
    v26.M[1][2] = v4->OrigMatrix.M[1][2];
    v5 = v4->OrigMatrix.M[1][3];
    v6 = v3->vfptr;
    v26.M[1][3] = v5;
    v7 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v6[2].__vecDelDtor)(v3);
    v26.M[0][3] = *(float *)(v7 + 12);
    v8 = *(float *)(v7 + 28);
    v9 = v3->pGeomData;
    *(_QWORD *)&v27.M[1][2] = __PAIR__(LODWORD(v8), LODWORD(v26.M[1][2]));
    v26.M[1][3] = v8;
    *(_OWORD *)&v27.M[0][0] = *(_OWORD *)&v26.M[0][0];
    *(_QWORD *)&v27.M[1][0] = *(_QWORD *)&v26.M[1][0];
    v10 = v9->Rotation;
    *(float *)&v10 = v10 * 3.141592653589793 * 0.005555555555555556 - atan2(v26.M[1][0], v26.M[0][0]);
    v11 = cosf(*(float *)&v10);
    v12 = sinf(*(float *)&v10);
    m.M[0][0] = v11;
    v13 = 0.0;
    *(_OWORD *)&m.M[1][0] = __PAIR__(LODWORD(v11), LODWORD(v12));
    *(_QWORD *)&m.M[0][2] = 0i64;
    *(_QWORD *)&m.M[0][1] = (unsigned int)(LODWORD(v12) ^ _xmm[0]);
    Scaleform::Render::Matrix2x4<float>::Append(&v27, &m);
    v14 = (float *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Matrix2x4<float> *, Scaleform::Render::Matrix2x4<float> *))v3->vfptr[61].__vecDelDtor)(
                     v3,
                     &m,
                     &v27);
    v15 = v14[2] - *v14;
    if ( COERCE_FLOAT(LODWORD(v15) & _xmm) > 0.000001 )
    {
      v16 = v2 * 20.0;
      v13 = v16 / v15;
    }
    v17 = _mm_cvtps_pd((__m128)LODWORD(v26.M[0][0]));
    v17.m128d_f64[0] = v17.m128d_f64[0] * v17.m128d_f64[0] + v26.M[1][0] * v26.M[1][0];
    *(_QWORD *)&v18 = (unsigned __int128)_mm_sqrt_pd(v17);
    v19 = v13 * v18 * 100.0;
    v3->pGeomData->XScale = v19;
    if ( v18 == 0.0 )
    {
      v18 = DOUBLE_1_0;
      v19 = 0.0;
    }
    v20 = v3->pGeomData;
    v21 = v20->Rotation;
    v22 = atan2(v26.M[1][0], v26.M[0][0]);
    v23 = (__m128)LODWORD(v26.M[1][1]);
    v24 = v21 * 3.141592653589793 * 0.005555555555555556 - v22;
    v23.m128_f32[0] = (float)(v23.m128_f32[0] * v23.m128_f32[0]) + (float)(v26.M[0][1] * v26.M[0][1]);
    Scaleform::GFx::ASCharacter_MatrixScaleAndRotate2x2(
      &v26,
      COERCE_DOUBLE(COERCE_UNSIGNED_INT64(v19 / (v18 * 100.0)) & _xmm),
      COERCE_DOUBLE(COERCE_UNSIGNED_INT64(v20->YScale / (COERCE_DOUBLE(_mm_sqrt_pd(_mm_cvtps_pd(v23))) * 100.0)) & _xmm),
      v24);
    *(_QWORD *)&v20->XScale &= _xmm;
    *(_QWORD *)&v3->pGeomData->YScale &= _xmm;
    if ( v26.M[0][0] >= -3.4028235e38
      && v26.M[0][0] <= 3.4028235e38
      && v26.M[0][1] >= -3.4028235e38
      && v26.M[0][1] <= 3.4028235e38
      && v26.M[0][2] >= -3.4028235e38
      && v26.M[0][2] <= 3.4028235e38
      && v26.M[0][3] >= -3.4028235e38
      && v26.M[0][3] <= 3.4028235e38
      && v26.M[1][0] >= -3.4028235e38
      && v26.M[1][0] <= 3.4028235e38
      && v26.M[1][1] >= -3.4028235e38
      && v26.M[1][1] <= 3.4028235e38
      && v26.M[1][2] >= -3.4028235e38
      && v26.M[1][2] <= 3.4028235e38
      && v26.M[1][3] >= -3.4028235e38
      && v26.M[1][3] <= 3.4028235e38 )
    {
      v3->vfptr[3].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v3->vfptr, (unsigned int)&v26);
    }
  }
}

// File Line: 1223
// RVA: 0x9077B0
void __fastcall Scaleform::GFx::DisplayObjectBase::SetHeight(Scaleform::GFx::DisplayObjectBase *this, long double height)
{
  double v2; // xmm8_8
  Scaleform::GFx::DisplayObjectBase *v3; // rdi
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v4; // rax
  float v5; // xmm1_4
  Scaleform::RefCountNTSImplCoreVtbl *v6; // rax
  __int64 v7; // rax
  float v8; // xmm4_4
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v9; // rax
  double v10; // xmm6_8
  float v11; // xmm7_4
  float v12; // xmm0_4
  float v13; // xmm6_4
  __int64 v14; // rax
  float v15; // xmm1_4
  float v16; // xmm6_4
  __m128d v17; // xmm1
  double v18; // xmm10_8
  double v19; // xmm9_8
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v20; // rbx
  __m128 v21; // xmm8
  float v22; // xmm7_4
  double v23; // xmm6_8
  float v24; // xmm3_4
  Scaleform::Render::Matrix2x4<float> m; // [rsp+20h] [rbp-69h]
  Scaleform::Render::Matrix2x4<float> v26; // [rsp+40h] [rbp-49h]
  Scaleform::Render::Matrix2x4<float> v27; // [rsp+60h] [rbp-29h]

  v2 = height;
  v3 = this;
  if ( ((*(_QWORD *)&height & 0x7FF0000000000000i64) != 9218868437227405312i64
     || !(*(_QWORD *)&height & 0xFFFFFFFFFFFFFi64))
    && height != -1.797693134862316e308/*-Inf*/ )
  {
    if ( height == 1.797693134862316e308/*+Inf*/ )
      v2 = 0.0;
    this->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)this, 0);
    v4 = v3->pGeomData;
    *(_OWORD *)&v26.M[0][0] = *(_OWORD *)&v4->OrigMatrix.M[0][0];
    *(_QWORD *)&v26.M[1][0] = *(_QWORD *)&v4->OrigMatrix.M[1][0];
    v26.M[1][2] = v4->OrigMatrix.M[1][2];
    v5 = v4->OrigMatrix.M[1][3];
    v6 = v3->vfptr;
    v26.M[1][3] = v5;
    v7 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v6[2].__vecDelDtor)(v3);
    v26.M[0][3] = *(float *)(v7 + 12);
    v8 = *(float *)(v7 + 28);
    v9 = v3->pGeomData;
    *(_QWORD *)&v27.M[1][2] = __PAIR__(LODWORD(v8), LODWORD(v26.M[1][2]));
    v26.M[1][3] = v8;
    *(_OWORD *)&v27.M[0][0] = *(_OWORD *)&v26.M[0][0];
    *(_QWORD *)&v27.M[1][0] = *(_QWORD *)&v26.M[1][0];
    v10 = v9->Rotation;
    *(float *)&v10 = v10 * 3.141592653589793 * 0.005555555555555556 - atan2(v26.M[1][0], v26.M[0][0]);
    v11 = cosf(*(float *)&v10);
    v12 = sinf(*(float *)&v10);
    m.M[0][0] = v11;
    v13 = 0.0;
    *(_OWORD *)&m.M[1][0] = __PAIR__(LODWORD(v11), LODWORD(v12));
    *(_QWORD *)&m.M[0][2] = 0i64;
    *(_QWORD *)&m.M[0][1] = (unsigned int)(LODWORD(v12) ^ _xmm[0]);
    Scaleform::Render::Matrix2x4<float>::Append(&v27, &m);
    v14 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Matrix2x4<float> *, Scaleform::Render::Matrix2x4<float> *))v3->vfptr[61].__vecDelDtor)(
            v3,
            &m,
            &v27);
    v15 = *(float *)(v14 + 12) - *(float *)(v14 + 4);
    if ( COERCE_FLOAT(LODWORD(v15) & _xmm) > 0.000001 )
    {
      v16 = v2 * 20.0;
      v13 = v16 / v15;
    }
    v17 = _mm_cvtps_pd((__m128)LODWORD(v26.M[0][1]));
    v17.m128d_f64[0] = v17.m128d_f64[0] * v17.m128d_f64[0] + v26.M[1][1] * v26.M[1][1];
    *(_QWORD *)&v18 = (unsigned __int128)_mm_sqrt_pd(v17);
    v19 = v13 * v18 * 100.0;
    v3->pGeomData->YScale = v19;
    if ( v18 == 0.0 )
    {
      v18 = DOUBLE_1_0;
      v19 = 0.0;
    }
    v20 = v3->pGeomData;
    v21 = (__m128)LODWORD(v26.M[1][0]);
    v22 = v26.M[0][0];
    v23 = v20->Rotation;
    v24 = v23 * 3.141592653589793 * 0.005555555555555556 - atan2(v26.M[1][0], v26.M[0][0]);
    v21.m128_f32[0] = (float)(v21.m128_f32[0] * v21.m128_f32[0]) + (float)(v22 * v22);
    Scaleform::GFx::ASCharacter_MatrixScaleAndRotate2x2(
      &v26,
      COERCE_DOUBLE(COERCE_UNSIGNED_INT64(v20->XScale / (COERCE_DOUBLE(_mm_sqrt_pd(_mm_cvtps_pd(v21))) * 100.0)) & _xmm),
      COERCE_DOUBLE(COERCE_UNSIGNED_INT64(v19 / (v18 * 100.0)) & _xmm),
      v24);
    *(_QWORD *)&v20->XScale &= _xmm;
    *(_QWORD *)&v3->pGeomData->YScale &= _xmm;
    if ( v26.M[0][0] >= -3.4028235e38
      && v26.M[0][0] <= 3.4028235e38
      && v26.M[0][1] >= -3.4028235e38
      && v26.M[0][1] <= 3.4028235e38
      && v26.M[0][2] >= -3.4028235e38
      && v26.M[0][2] <= 3.4028235e38
      && v26.M[0][3] >= -3.4028235e38
      && v26.M[0][3] <= 3.4028235e38
      && v26.M[1][0] >= -3.4028235e38
      && v26.M[1][0] <= 3.4028235e38
      && v26.M[1][1] >= -3.4028235e38
      && v26.M[1][1] <= 3.4028235e38
      && v26.M[1][2] >= -3.4028235e38
      && v26.M[1][2] <= 3.4028235e38
      && v26.M[1][3] >= -3.4028235e38
      && v26.M[1][3] <= 3.4028235e38 )
    {
      v3->vfptr[3].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v3->vfptr, (unsigned int)&v26);
    }
  }
}

// File Line: 1275
// RVA: 0x9061C0
void __fastcall Scaleform::GFx::DisplayObjectBase::SetAlpha(Scaleform::GFx::DisplayObjectBase *this, long double alpha)
{
  Scaleform::GFx::DisplayObjectBase *v2; // rbx
  Scaleform::Render::TreeNode *v3; // rcx
  Scaleform::Render::Cxform *v4; // rdx
  Scaleform::Render::ContextImpl::EntryData v5; // xmm6
  Scaleform::Render::ContextImpl::EntryData v6; // ST20_16
  float v7; // xmm0_4
  Scaleform::Render::TreeNode *v8; // rax
  Scaleform::Render::ContextImpl::EntryData *v9; // rax

  v2 = this;
  if ( (*(_QWORD *)&alpha & 0x7FF0000000000000i64) != 9218868437227405312i64
    || !(*(_QWORD *)&alpha & 0xFFFFFFFFFFFFFi64) )
  {
    v3 = this->pRenNode.pObject;
    if ( v3 )
      v4 = (Scaleform::Render::Cxform *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v3 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                                   + 8
                                                   * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v3[-1] - ((unsigned __int64)v3 & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                                    + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v3[-1] - ((unsigned __int64)v3 & 0xFFFFFFFFFFFFF000ui64))
                                                                                            * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                                   + 40)
                                       + 80i64);
    else
      v4 = &Scaleform::Render::Cxform::Identity;
    v5 = *(Scaleform::Render::ContextImpl::EntryData *)&v4->M[1][0];
    v6 = *(Scaleform::Render::ContextImpl::EntryData *)&v4->M[0][0];
    v7 = alpha * 0.01;
    *(float *)(&v6.Flags + 1) = v7;
    v8 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(v2);
    v9 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&v8->0, 2u);
    v9[5] = v6;
    v9[6] = v5;
    v2->vfptr[53].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v2->vfptr, 0);
  }
}

// File Line: 1288
// RVA: 0x8E1B40
double __fastcall Scaleform::GFx::DisplayObjectBase::GetX(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [rsp+20h] [rbp-68h]

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
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [rsp+20h] [rbp-68h]

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
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [rsp+20h] [rbp-68h]

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
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [rsp+20h] [rbp-68h]

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
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [rsp+20h] [rbp-68h]

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
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [rsp+20h] [rbp-68h]

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
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [rsp+20h] [rbp-68h]

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
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [rsp+20h] [rbp-68h]

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
  Scaleform::GFx::DisplayObjectBase::GeomDataType geomData; // [rsp+20h] [rbp-68h]

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
  Scaleform::GFx::DisplayObjectBase *v1; // rdi
  Scaleform::Render::TreeNode *v2; // rcx
  Scaleform::Render::Rect<float> *v3; // rax
  Scaleform::RefCountNTSImplCoreVtbl *v4; // rbx
  __int64 v5; // rax
  __m128 v6; // xmm0
  __m128d v7; // xmm0
  __int64 v8; // rcx
  Scaleform::Render::Rect<float> result; // [rsp+20h] [rbp-18h]

  v1 = this;
  v2 = this->pRenNode.pObject;
  if ( v2
    && (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8
                             * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v2[-1] - ((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64))
                                                                                  * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                              + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v2[-1]
                                                                                       - ((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                             + 40)
                 + 10i64) >> 9) & 1 )
  {
    v3 = Scaleform::GFx::DisplayObjectBase::GetBoundsIn3D(v1, &result);
  }
  else
  {
    v4 = v1->vfptr;
    v5 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v1->vfptr[2].__vecDelDtor)(v1);
    v3 = (Scaleform::Render::Rect<float> *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Rect<float> *, __int64))v4[61].__vecDelDtor)(
                                             v1,
                                             &result,
                                             v5);
  }
  v6 = (__m128)LODWORD(v3->x2);
  v6.m128_f32[0] = v6.m128_f32[0] - v3->x1;
  v7 = _mm_cvtps_pd(v6);
  v7.m128d_f64[0] = v7.m128d_f64[0] + 0.5;
  v8 = (unsigned int)(signed int)v7.m128d_f64[0];
  if ( v8 != 0x8000000000000000i64 && (double)(signed int)v8 != v7.m128d_f64[0] )
    v7.m128d_f64[0] = (double)(signed int)(v8 - (_mm_movemask_pd(_mm_unpckl_pd(v7, v7)) & 1));
  return v7.m128d_f64[0] * 0.05;
}

// File Line: 1353
// RVA: 0x8D9990
double __fastcall Scaleform::GFx::DisplayObjectBase::GetHeight(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase *v1; // rdi
  Scaleform::Render::TreeNode *v2; // rcx
  Scaleform::Render::Rect<float> *v3; // rax
  Scaleform::RefCountNTSImplCoreVtbl *v4; // rbx
  __int64 v5; // rax
  __m128 v6; // xmm0
  __m128d v7; // xmm0
  __int64 v8; // rcx
  Scaleform::Render::Rect<float> result; // [rsp+20h] [rbp-18h]

  v1 = this;
  v2 = this->pRenNode.pObject;
  if ( v2
    && (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8
                             * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v2[-1] - ((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64))
                                                                                  * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                              + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v2[-1]
                                                                                       - ((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                             + 40)
                 + 10i64) >> 9) & 1 )
  {
    v3 = Scaleform::GFx::DisplayObjectBase::GetBoundsIn3D(v1, &result);
  }
  else
  {
    v4 = v1->vfptr;
    v5 = ((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *))v1->vfptr[2].__vecDelDtor)(v1);
    v3 = (Scaleform::Render::Rect<float> *)((__int64 (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, Scaleform::Render::Rect<float> *, __int64))v4[61].__vecDelDtor)(
                                             v1,
                                             &result,
                                             v5);
  }
  v6 = (__m128)LODWORD(v3->y2);
  v6.m128_f32[0] = v6.m128_f32[0] - v3->y1;
  v7 = _mm_cvtps_pd(v6);
  v7.m128d_f64[0] = v7.m128d_f64[0] + 0.5;
  v8 = (unsigned int)(signed int)v7.m128d_f64[0];
  if ( v8 != 0x8000000000000000i64 && (double)(signed int)v8 != v7.m128d_f64[0] )
    v7.m128d_f64[0] = (double)(signed int)(v8 - (_mm_movemask_pd(_mm_unpckl_pd(v7, v7)) & 1));
  return v7.m128d_f64[0] * 0.05;
}

// File Line: 1364
// RVA: 0x8D5440
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::DisplayObjectBase::GetBoundsIn3D(Scaleform::GFx::DisplayObjectBase *this, Scaleform::Render::Rect<float> *result)
{
  Scaleform::Render::Rect<float> *v2; // rbx
  Scaleform::GFx::DisplayObjectBase *v3; // rdi
  Scaleform::GFx::DisplayObjectBase *v4; // rcx
  Scaleform::Render::Point<float> *v5; // rax
  float v6; // xmm6_4
  float v7; // xmm7_4
  Scaleform::Render::Point<float> *v8; // rax
  float v9; // xmm0_4
  float v10; // xmm1_4
  Scaleform::Render::Rect<float> *v11; // rax
  Scaleform::Render::Point3<float> ptIn; // [rsp+20h] [rbp-48h]
  float v13; // [rsp+30h] [rbp-38h]
  float v14; // [rsp+34h] [rbp-34h]
  float v15; // [rsp+38h] [rbp-30h]
  float v16; // [rsp+3Ch] [rbp-2Ch]
  Scaleform::Render::Point<float> resulta; // [rsp+70h] [rbp+8h]
  Scaleform::Render::Point<float> v18; // [rsp+78h] [rbp+10h]
  Scaleform::Render::Point<float> v19; // [rsp+80h] [rbp+18h]

  v2 = result;
  v3 = this;
  ((void (__fastcall *)(Scaleform::GFx::DisplayObjectBase *, float *, Scaleform::Render::Matrix2x4<float> *))this->vfptr[61].__vecDelDtor)(
    this,
    &v13,
    &Scaleform::Render::Matrix2x4<float>::Identity);
  ptIn.x = v13;
  ptIn.y = v14;
  ptIn.z = 0.0;
  Scaleform::GFx::DisplayObjectBase::Local3DToGlobal(v3, &resulta, &ptIn);
  ptIn.x = v15;
  ptIn.y = v16;
  ptIn.z = 0.0;
  Scaleform::GFx::DisplayObjectBase::Local3DToGlobal(v3, &v18, &ptIn);
  v4 = v3->pParentChar;
  if ( v4 )
  {
    v5 = Scaleform::GFx::DisplayObjectBase::GlobalToLocal(v4, &v19, &resulta);
    v6 = v5->x;
    v7 = v5->y;
    v8 = Scaleform::GFx::DisplayObjectBase::GlobalToLocal(v3->pParentChar, &resulta, &v18);
    v9 = v8->x;
    v10 = v8->y;
  }
  else
  {
    v7 = resulta.y;
    v6 = resulta.x;
    v10 = v18.y;
    v9 = v18.x;
  }
  v2->x1 = v6;
  v11 = v2;
  v2->y1 = v7;
  v2->x2 = (float)(v9 - v6) + v6;
  v2->y2 = (float)(v10 - v7) + v7;
  return v11;
}

// File Line: 1387
// RVA: 0x8D4CD0
long double __fastcall Scaleform::GFx::DisplayObjectBase::GetAlpha(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode *v1; // rdx
  __int64 v2; // rax
  unsigned __int64 v3; // rdx
  float v4; // xmm0_4

  v1 = this->pRenNode.pObject;
  if ( v1 )
  {
    v2 = *(_QWORD *)(((unsigned __int64)v1 & 0xFFFFFFFFFFFFF000ui64) + 0x20);
    v3 = (signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v1[-1]
                                                             - ((unsigned __int64)v1 & 0xFFFFFFFFFFFFF000ui64))
                                            * (signed __int128)5270498306774157605i64) >> 64) >> 4;
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
Scaleform::GFx::MovieImpl *__fastcall Scaleform::GFx::DisplayObjectBase::FindMovieImpl(Scaleform::GFx::DisplayObjectBase *this)
{
  if ( !this )
    return 0i64;
  while ( SLOBYTE(this->Flags) >= 0 )
  {
    this = this->pParentChar;
    if ( !this )
      return 0i64;
  }
  return this->pASRoot->pMovieImpl;
}

// File Line: 1405
// RVA: 0x8E0FC0
Scaleform::GFx::InteractiveObject *__fastcall Scaleform::GFx::DisplayObjectBase::GetTopMostMouseEntityDef(Scaleform::GFx::DisplayObjectBase *this, Scaleform::GFx::CharacterDef *pdef, Scaleform::Render::Point<float> *pt, bool testAll, Scaleform::GFx::InteractiveObject *ignoreMC)
{
  bool v5; // si
  Scaleform::Render::Point<float> *v6; // rbp
  Scaleform::GFx::CharacterDef *v7; // rdi
  Scaleform::GFx::DisplayObjectBase *v8; // rbx
  __int64 v9; // r8
  Scaleform::GFx::InteractiveObject *v10; // rbx
  Scaleform::GFx::InteractiveObject *v11; // rdi
  unsigned __int8 v12; // al
  __int64 v13; // rax
  __int64 v14; // rax
  unsigned __int8 v15; // cl
  __int64 v16; // rax
  Scaleform::Render::Point<float> p; // [rsp+40h] [rbp+8h]

  v5 = testAll;
  v6 = pt;
  v7 = pdef;
  v8 = this;
  if ( ((unsigned __int8 (*)(void))this->vfptr[59].__vecDelDtor)() )
  {
    Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(v8, &p, v6, 1, 0i64);
    if ( !v8->ClipDepth )
    {
      LOBYTE(v9) = 1;
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::CharacterDef *, Scaleform::Render::Point<float> *, __int64, Scaleform::GFx::DisplayObjectBase *))v7->vfptr[1].GetResourceTypeCode)(
             v7,
             &p,
             v9,
             v8) )
      {
        v10 = v8->pParent;
        if ( v10 )
        {
          v11 = ignoreMC;
          while ( (v10->Flags >> 10) & 1 )
          {
            if ( v5
              || (v12 = v10->AvmObjOffset) != 0
              && (v13 = ((__int64 (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v10->vfptr + 4 * v12))[1].__vecDelDtor)((signed __int64)v10 + 4 * v12),
                  (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v13 + 96i64))(v13))
              || ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v10->vfptr[121].__vecDelDtor)(v10)
              && (v14 = ((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v10->vfptr[121].__vecDelDtor)(v10),
                  (v15 = *(_BYTE *)(v14 + 109)) != 0)
              && (v16 = (*(__int64 (**)(void))(*(_QWORD *)(v14 + 4i64 * v15) + 8i64))(),
                  (*(unsigned __int8 (__fastcall **)(__int64))(*(_QWORD *)v16 + 96i64))(v16)) )
            {
              if ( !v11 || v11 != v10 )
                return v10;
            }
            v10 = v10->pParent;
            if ( !v10 )
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
char __fastcall Scaleform::GFx::DisplayObjectBase::IsAncestor(Scaleform::GFx::DisplayObjectBase *this, Scaleform::GFx::DisplayObjectBase *ch)
{
  Scaleform::GFx::InteractiveObject *v2; // rax

  v2 = ch->pParent;
  if ( !v2 )
    return 0;
  while ( v2 != (Scaleform::GFx::InteractiveObject *)this )
  {
    v2 = v2->pParent;
    if ( !v2 )
      return 0;
  }
  return 1;
}

// File Line: 1455
// RVA: 0x917730
void __fastcall Scaleform::GFx::DisplayObjectBase::UpdateTransform3D(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v1; // rbx
  __m128i v2; // xmm2
  __m128i v3; // xmm3
  double v4; // xmm4_8
  float v5; // edi
  float v6; // esi
  float v7; // xmm1_4
  double v8; // xmm1_8
  float v9; // ebx
  float v10; // er14
  float v11; // er15
  float v12; // er12
  float v13; // er13
  float v14; // xmm6_4
  float v15; // xmm7_4
  float v16; // xmm0_4
  float v17; // edx
  float v18; // er8
  float v19; // er9
  float v20; // er10
  float v21; // er11
  Scaleform::Render::Matrix3x4<float> *v22; // rcx
  double v23; // xmm0_8
  float v24; // xmm6_4
  float v25; // xmm7_4
  float v26; // xmm0_4
  Scaleform::Render::Matrix3x4<float> *v27; // rcx
  double v28; // xmm0_8
  float v29; // xmm6_4
  float v30; // xmm7_4
  float v31; // xmm0_4
  Scaleform::Render::Matrix3x4<float> v32; // [rsp+20h] [rbp-D8h]
  __int128 Dst; // [rsp+50h] [rbp-A8h]
  __int128 v34; // [rsp+60h] [rbp-98h]
  char v35[20]; // [rsp+70h] [rbp-88h]
  int v36; // [rsp+84h] [rbp-74h]
  int v37; // [rsp+88h] [rbp-70h]
  int v38; // [rsp+8Ch] [rbp-6Ch]
  int v39; // [rsp+90h] [rbp-68h]
  int v40; // [rsp+94h] [rbp-64h]
  __int64 v41; // [rsp+98h] [rbp-60h]
  int v42; // [rsp+A0h] [rbp-58h]
  int v43; // [rsp+A4h] [rbp-54h]
  Scaleform::Render::Matrix3x4<float> m1; // [rsp+A8h] [rbp-50h]
  Scaleform::Render::Matrix3x4<float> m2; // [rsp+D8h] [rbp-20h]
  Scaleform::Render::Matrix3x4<float> v46; // [rsp+108h] [rbp+10h]
  Scaleform::Render::Matrix3x4<float> v47; // [rsp+138h] [rbp+40h]
  Scaleform::Render::Matrix3x4<float> v48; // [rsp+168h] [rbp+70h]
  Scaleform::Render::Matrix3x4<float> v49; // [rsp+198h] [rbp+A0h]
  void *retaddr; // [rsp+238h] [rbp+140h]
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v51; // [rsp+240h] [rbp+148h]

  v1 = this->pGeomData;
  memset(&Dst, 0, 0x30ui64);
  v2 = _mm_cvtsi32_si128(v1->X);
  v3 = _mm_cvtsi32_si128(v1->Y);
  v4 = v1->Z;
  v51 = v1;
  *(_QWORD *)&v35[12] = *(_QWORD *)((char *)&Dst + 4);
  *(float *)&v4 = v4;
  v37 = v34;
  v39 = DWORD2(v34);
  v41 = *(_QWORD *)v35;
  v36 = (unsigned __int128)_mm_cvtepi32_ps(v2);
  v38 = (signed int)FLOAT_1_0;
  v40 = (unsigned __int128)_mm_cvtepi32_ps(v3);
  v42 = (signed int)FLOAT_1_0;
  v43 = LODWORD(v4);
  memset(&Dst, 0, 0x30ui64);
  v2.m128i_i64[0] = *(_QWORD *)&v1->YScale;
  v5 = Scaleform::Render::Matrix3x4<float>::Identity.M[2][2];
  v6 = Scaleform::Render::Matrix3x4<float>::Identity.M[2][1];
  v3.m128i_i64[0] = *(_QWORD *)&v1->ZScale;
  v7 = v1->XScale;
  m2.M[0][0] = v7 * 0.0099999998;
  LODWORD(m2.M[1][0]) = v34;
  *(_QWORD *)&m2.M[0][1] = *(_QWORD *)((char *)&Dst + 4);
  m2.M[0][3] = *((float *)&Dst + 3);
  *(_QWORD *)&m2.M[1][2] = *((_QWORD *)&v34 + 1);
  *(_QWORD *)&m2.M[2][0] = *(_QWORD *)v35;
  m2.M[1][1] = (float)*(double *)v2.m128i_i64 * 0.0099999998;
  m2.M[2][3] = *(float *)&v35[12];
  m2.M[2][2] = (float)*(double *)v3.m128i_i64 * 0.0099999998;
  v8 = v1->XRotation;
  v9 = Scaleform::Render::Matrix3x4<float>::Identity.M[2][3];
  v10 = Scaleform::Render::Matrix3x4<float>::Identity.M[2][0];
  v11 = Scaleform::Render::Matrix3x4<float>::Identity.M[1][3];
  v12 = Scaleform::Render::Matrix3x4<float>::Identity.M[1][2];
  v13 = Scaleform::Render::Matrix3x4<float>::Identity.M[1][1];
  if ( v8 == 0.0 )
  {
    v20 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][1];
    v21 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][0];
    v18 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][3];
    v19 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][2];
    v17 = Scaleform::Render::Matrix3x4<float>::Identity.M[1][0];
    v32 = Scaleform::Render::Matrix3x4<float>::Identity;
    v22 = &v32;
  }
  else
  {
    v14 = v8 * 3.141592653589793 * 0.005555555555555556;
    memset(&Dst, 0, 0x30ui64);
    v15 = cosf(v14);
    v16 = sinf(v14);
    v17 = Scaleform::Render::Matrix3x4<float>::Identity.M[1][0];
    v18 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][3];
    *((float *)&v34 + 1) = v15;
    *(float *)&v35[8] = v15;
    *(float *)&v35[4] = v16;
    v19 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][2];
    v20 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][1];
    v21 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][0];
    DWORD2(v34) = LODWORD(v16) ^ _xmm[0];
    *(_QWORD *)&Dst = 1065353216i64;
    LODWORD(v34) = 0;
    *(_DWORD *)v35 = 0;
    DWORD2(Dst) = 0;
    v22 = (Scaleform::Render::Matrix3x4<float> *)&Dst;
  }
  *(_OWORD *)&m1.M[0][0] = *(_OWORD *)&v22->M[0][0];
  *(_OWORD *)&m1.M[1][0] = *(_OWORD *)&v22->M[1][0];
  *(_OWORD *)&m1.M[2][0] = *(_OWORD *)&v22->M[2][0];
  v23 = v51->YRotation;
  if ( v23 == 0.0 )
  {
    *(_QWORD *)&v32.M[0][0] = __PAIR__(LODWORD(v20), LODWORD(v21));
    *(_QWORD *)&v32.M[0][2] = __PAIR__(LODWORD(v18), LODWORD(v19));
    *(_QWORD *)&v32.M[1][0] = __PAIR__(LODWORD(v13), LODWORD(v17));
    *(_QWORD *)&v32.M[1][2] = __PAIR__(LODWORD(v11), LODWORD(v12));
    *(_QWORD *)&v32.M[2][0] = __PAIR__(LODWORD(v6), LODWORD(v10));
    *(_QWORD *)&v32.M[2][2] = __PAIR__(LODWORD(v9), LODWORD(v5));
    v27 = &v32;
  }
  else
  {
    v24 = v23 * 3.141592653589793 * 0.005555555555555556;
    memset(&Dst, 0, 0x30ui64);
    v25 = cosf(v24);
    v26 = sinf(v24);
    v17 = Scaleform::Render::Matrix3x4<float>::Identity.M[1][0];
    v18 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][3];
    *(_QWORD *)&Dst = LODWORD(v25);
    *(float *)&v35[8] = v25;
    *((float *)&Dst + 2) = v26;
    v19 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][2];
    v20 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][1];
    v21 = Scaleform::Render::Matrix3x4<float>::Identity.M[0][0];
    *(_QWORD *)v35 = (unsigned int)(LODWORD(v26) ^ _xmm[0]);
    LODWORD(v34) = 0;
    *(_QWORD *)((char *)&v34 + 4) = 1065353216i64;
    v27 = (Scaleform::Render::Matrix3x4<float> *)&Dst;
  }
  *(_OWORD *)&v46.M[0][0] = *(_OWORD *)&v27->M[0][0];
  *(_OWORD *)&v46.M[1][0] = *(_OWORD *)&v27->M[1][0];
  *(_OWORD *)&v46.M[2][0] = *(_OWORD *)&v27->M[2][0];
  v28 = v51->Rotation;
  if ( v28 == 0.0 )
  {
    *(_QWORD *)&v32.M[0][0] = __PAIR__(LODWORD(v20), LODWORD(v21));
    *(_QWORD *)&v32.M[0][2] = __PAIR__(LODWORD(v18), LODWORD(v19));
    *(_QWORD *)&v32.M[1][0] = __PAIR__(LODWORD(v13), LODWORD(v17));
    *(_QWORD *)&v32.M[1][2] = __PAIR__(LODWORD(v11), LODWORD(v12));
    *(_QWORD *)&v32.M[2][0] = __PAIR__(LODWORD(v6), LODWORD(v10));
    *(_QWORD *)&v32.M[2][2] = __PAIR__(LODWORD(v9), LODWORD(v5));
  }
  else
  {
    v29 = v28 * 3.141592653589793 * 0.005555555555555556;
    memset(&v32, 0, 0x30ui64);
    v30 = cosf(v29);
    v31 = sinf(v29);
    v32.M[0][0] = v30;
    *(_QWORD *)&v32.M[1][1] = LODWORD(v30);
    *(_QWORD *)&v32.M[2][0] = 0i64;
    v32.M[1][0] = v31;
    v32.M[2][2] = 1.0;
    *(_QWORD *)&v32.M[0][1] = (unsigned int)(LODWORD(v31) ^ _xmm[0]);
  }
  Dst = *(_OWORD *)&v32.M[0][0];
  v34 = *(_OWORD *)&v32.M[1][0];
  *(_OWORD *)v35 = *(_OWORD *)&v32.M[2][0];
  Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&v47, &m1, &m2);
  Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&v48, (Scaleform::Render::Matrix3x4<float> *)&Dst, &v46);
  Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&v49, &v48, &v47);
  Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&v32, (Scaleform::Render::Matrix3x4<float> *)&v35[8], &v49);
  if ( Scaleform::Render::Matrix3x4<float>::IsValid(&v32) )
    (*(void (__fastcall **)(void *, Scaleform::Render::Matrix3x4<float> *))(*(_QWORD *)retaddr + 40i64))(retaddr, &v32);
}

// File Line: 1483
// RVA: 0x908060
Scaleform::Ptr<Scaleform::Render::TreeNode> *__fastcall Scaleform::GFx::DisplayObjectBase::SetIndirectTransform(Scaleform::GFx::DisplayObjectBase *this, Scaleform::Ptr<Scaleform::Render::TreeNode> *result, Scaleform::Render::TreeNode *newParent)
{
  Scaleform::Render::TreeNode *v3; // rbx
  Scaleform::Ptr<Scaleform::Render::TreeNode> *v4; // r14
  Scaleform::GFx::DisplayObjectBase *v5; // rsi
  Scaleform::Render::TreeNode *v6; // rax
  Scaleform::Render::TreeNode *v7; // rdi
  Scaleform::Render::TreeNode *v8; // rbp
  Scaleform::GFx::DisplayObjContainer *v9; // rbx
  Scaleform::GFx::InteractiveObject *v10; // rcx
  unsigned __int64 v11; // r8
  unsigned __int64 v12; // rcx
  Scaleform::GFx::DisplayList::DisplayEntry *v13; // rax
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *v14; // rax
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *v15; // rbx
  _DWORD *v16; // r8
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *v17; // rcx
  bool v18; // zf
  int v20; // [rsp+80h] [rbp+18h]
  Scaleform::Render::TreeNode *v21; // [rsp+88h] [rbp+20h]

  v3 = newParent;
  v4 = result;
  v5 = this;
  v6 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  v7 = v6;
  if ( v6 )
    ++v6->RefCount;
  v21 = v6;
  v8 = (Scaleform::Render::TreeNode *)v6->pParent;
  Scaleform::Render::TreeNode::SetOrigScale9Parent(v6, (Scaleform::Render::TreeNode *)v6->pParent);
  if ( v3 )
  {
    while ( v3 != v7 )
    {
      v3 = (Scaleform::Render::TreeNode *)v3->pParent;
      if ( !v3 )
        goto LABEL_8;
    }
    v4->pObject = 0i64;
  }
  else
  {
LABEL_8:
    v9 = 0i64;
    v10 = v5->pParent;
    if ( v10 )
    {
      if ( (v10->Flags >> 9) & 1 )
        v9 = (Scaleform::GFx::DisplayObjContainer *)v5->pParent;
      if ( v9 )
      {
        v11 = 0i64;
        v12 = v9->mDisplayList.DisplayObjectArray.Data.Size;
        if ( v12 )
        {
          v13 = v9->mDisplayList.DisplayObjectArray.Data.Data;
          while ( v13->pCharacter != v5 )
          {
            ++v11;
            ++v13;
            if ( v11 >= v12 )
              goto LABEL_16;
          }
        }
        else
        {
LABEL_16:
          v11 = -1i64;
        }
        Scaleform::GFx::DisplayList::RemoveFromRenderTree(
          &v9->mDisplayList,
          (Scaleform::GFx::DisplayObjectBase *)&v9->vfptr,
          v11);
      }
    }
    Scaleform::GFx::MovieImpl::AddIndirectTransformPair(v5->pASRoot->pMovieImpl, v9, v8, v5);
    if ( !v5->pIndXFormData )
    {
      v20 = 322;
      v14 = (Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::DisplayObjectBase *, signed __int64, int *, _DWORD, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                                                              Scaleform::Memory::pGlobalHeap,
                                                                              v5,
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
      v5->pIndXFormData = v15;
    }
    v16 = *(_DWORD **)(*(_QWORD *)(((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                     + 8
                     * (((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v7[-1]
                                                                               - ((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64))
                                                              * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                      + (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v7[-1]
                                                                                           - ((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64))
                                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                     + 40);
    v17 = v5->pIndXFormData;
    v17->OrigTransformMatrix.M[0][0] = (float)v16[4];
    v17->OrigTransformMatrix.M[0][1] = (float)v16[5];
    v17->OrigTransformMatrix.M[0][2] = (float)v16[6];
    v17->OrigTransformMatrix.M[0][3] = (float)v16[7];
    v17->OrigTransformMatrix.M[1][0] = (float)v16[8];
    v17->OrigTransformMatrix.M[1][1] = (float)v16[9];
    v17->OrigTransformMatrix.M[1][2] = (float)v16[10];
    v17->OrigTransformMatrix.M[1][3] = (float)v16[11];
    v17->OrigTransformMatrix.M[2][0] = (float)v16[12];
    v17->OrigTransformMatrix.M[2][1] = (float)v16[13];
    v17->OrigTransformMatrix.M[2][2] = (float)v16[14];
    v17->OrigTransformMatrix.M[2][3] = (float)v16[15];
    v5->pIndXFormData->IsOrig3D = (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64)
                                                                    + 0x20)
                                                        + 8
                                                        * (((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v7[-1] - ((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64))
                                                                                                 * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                                                         + (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v7[-1] - ((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64)) * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                                                        + 40)
                                            + 10i64) >> 9) & 1;
    v5->Flags |= 0x8000u;
    ++v7->RefCount;
    v4->pObject = v7;
  }
  v18 = v7->RefCount-- == 1;
  if ( v18 )
    Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)&v7->0);
  return v4;
}

// File Line: 1523
// RVA: 0x8FF8A0
void __fastcall Scaleform::GFx::DisplayObjectBase::RemoveIndirectTransform(Scaleform::GFx::DisplayObjectBase *this, bool readdToDisplayList)
{
  bool v2; // bp
  Scaleform::GFx::DisplayObjectBase *v3; // rsi
  Scaleform::Render::TreeNode *v4; // rax
  Scaleform::Render::TreeNode *v5; // rdi
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *v6; // rdx
  unsigned __int64 v7; // rbx
  unsigned __int64 v8; // rcx
  Scaleform::GFx::DisplayList::DisplayEntry *v9; // rax
  Scaleform::Render::TreeNode *v10; // rcx
  bool v11; // zf
  Scaleform::GFx::MovieImpl::IndirectTransPair result; // [rsp+28h] [rbp-30h]

  v2 = readdToDisplayList;
  v3 = this;
  if ( (this->Flags & 0x8000u) != 0 )
  {
    v4 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
    v5 = v4;
    if ( v4 )
      ++v4->RefCount;
    v6 = v3->pIndXFormData;
    if ( v6->IsOrig3D )
    {
      Scaleform::Render::TreeNode::SetMatrix3D(v4, &v6->OrigTransformMatrix);
    }
    else
    {
      Scaleform::Render::TreeNode::Clear3D(v4);
      Scaleform::Render::TreeNode::SetMatrix(v5, (Scaleform::Render::Matrix2x4<float> *)v3->pIndXFormData);
    }
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3->pIndXFormData);
    v7 = 0i64;
    v3->pIndXFormData = 0i64;
    v3->Flags &= 0x7FFFu;
    Scaleform::GFx::MovieImpl::RemoveIndirectTransformPair(v3->pASRoot->pMovieImpl, &result, v3);
    if ( v2 )
    {
      if ( result.OriginalParent.pObject )
      {
        v8 = result.OriginalParent.pObject->mDisplayList.DisplayObjectArray.Data.Size;
        if ( v8 )
        {
          v9 = result.OriginalParent.pObject->mDisplayList.DisplayObjectArray.Data.Data;
          while ( v9->pCharacter != v3 )
          {
            ++v7;
            ++v9;
            if ( v7 >= v8 )
              goto LABEL_16;
          }
          if ( v7 != -1i64 )
            Scaleform::GFx::DisplayList::InsertIntoRenderTree(
              &result.OriginalParent.pObject->mDisplayList,
              (Scaleform::GFx::DisplayObjectBase *)&result.OriginalParent.pObject->vfptr,
              v7);
        }
      }
    }
LABEL_16:
    Scaleform::Render::TreeNode::SetOrigScale9Parent(v5, 0i64);
    if ( result.OriginalParent.pObject )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&result.OriginalParent.pObject->vfptr);
    if ( result.Obj.pObject )
      Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&result.Obj.pObject->vfptr);
    v10 = result.TransformParent.pObject;
    if ( result.TransformParent.pObject )
    {
      v11 = result.TransformParent.pObject->RefCount-- == 1;
      if ( v11 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)&v10->0);
    }
    if ( v5 )
    {
      v11 = v5->RefCount-- == 1;
      if ( v11 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)&v5->0);
    }
  }
}

// File Line: 1559
// RVA: 0x90B6D0
void __fastcall Scaleform::GFx::DisplayObjectBase::SetScale9Grid(Scaleform::GFx::DisplayObjectBase *this, Scaleform::Render::Rect<float> *gr)
{
  Scaleform::Render::Rect<float> *v2; // rbx
  Scaleform::Render::TreeNode *v3; // rax

  v2 = gr;
  v3 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeNode::SetScale9Grid(v3, v2);
}

// File Line: 1565
// RVA: 0x8DDEA0
Scaleform::Render::Rect<float> *__fastcall Scaleform::GFx::DisplayObjectBase::GetScale9Grid(Scaleform::GFx::DisplayObjectBase *this, Scaleform::Render::Rect<float> *result)
{
  Scaleform::Render::Rect<float> *v2; // rbx
  Scaleform::Render::TreeNode *v3; // rax

  v2 = result;
  v3 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  Scaleform::Render::TreeNode::GetScale9Grid(v3, v2);
  return v2;
}

// File Line: 1570
// RVA: 0x8C36C0
void __fastcall Scaleform::GFx::DisplayObjectBase::CreateScale9Grid(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::GFx::DisplayObjectBase *v1; // rdi
  Scaleform::GFx::InteractiveObject *v2; // rbx
  _OWORD *v3; // rax
  Scaleform::Render::TreeNode *v4; // rax
  Scaleform::Render::State *v5; // rax
  float *v6; // rax
  float v7; // xmm3_4
  unsigned int v8; // xmm2_4
  unsigned int v9; // xmm1_4
  Scaleform::Render::Rect<float> *v10; // rax
  Scaleform::Render::Matrix2x4<float> *v11; // rax
  Scaleform::Render::Scale9GridInfo *v12; // rdi
  Scaleform::Render::TreeNode *v13; // rax
  Scaleform::Render::State *v14; // rax
  float *v15; // rax
  float v16; // xmm3_4
  unsigned int v17; // xmm2_4
  unsigned int v18; // xmm1_4
  Scaleform::Render::Matrix2x4<float> *v19; // rax
  Scaleform::Render::Rect<float> v20; // [rsp+40h] [rbp-19h]
  Scaleform::Render::Rect<float> s9Rect; // [rsp+50h] [rbp-9h]
  __m128 v22; // [rsp+60h] [rbp+7h]
  Scaleform::Render::Rect<float> bounds; // [rsp+70h] [rbp+17h]
  Scaleform::Render::Matrix2x4<float> shapeMtx; // [rsp+80h] [rbp+27h]
  int v25; // [rsp+C8h] [rbp+6Fh]
  Scaleform::Render::Scale9GridInfo *v26; // [rsp+D0h] [rbp+77h]

  v1 = this;
  v2 = this->pParent;
  v3 = (_OWORD *)((__int64 (*)(void))this->vfptr[2].__vecDelDtor)();
  *(_OWORD *)&shapeMtx.M[0][0] = *v3;
  *(_OWORD *)&shapeMtx.M[1][0] = v3[1];
  while ( v2 )
  {
    v4 = Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v2->vfptr);
    v5 = Scaleform::Render::TreeNode::GetState(v4, State_Scale9);
    if ( v5 )
    {
      v6 = (float *)v5->pData;
      v7 = v6[7];
      v8 = *((_DWORD *)v6 + 6);
      v9 = *((_DWORD *)v6 + 5);
      v20.x1 = v6[4];
      *(_QWORD *)&v20.y1 = __PAIR__(v8, v9);
      v20.y2 = v7;
      v10 = &v20;
    }
    else
    {
      s9Rect = 0i64;
      v10 = &s9Rect;
    }
    if ( v10->x1 < v10->x2 && v10->y1 < v10->y2 )
    {
      s9Rect = (Scaleform::Render::Rect<float>)_xmm;
      v22 = _xmm;
      ((void (__fastcall *)(Scaleform::GFx::InteractiveObject *, Scaleform::Render::Rect<float> *, Scaleform::Render::Rect<float> *))v2->vfptr[62].__vecDelDtor)(
        v2,
        &bounds,
        &s9Rect);
      v25 = 71;
      v12 = (Scaleform::Render::Scale9GridInfo *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   v1,
                                                   448ui64,
                                                   (Scaleform::AllocInfo *)&v25);
      v26 = v12;
      if ( v12 )
      {
        v13 = Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v2->vfptr);
        v14 = Scaleform::Render::TreeNode::GetState(v13, State_Scale9);
        if ( v14 )
        {
          v15 = (float *)v14->pData;
          v16 = v15[7];
          v17 = *((_DWORD *)v15 + 6);
          v18 = *((_DWORD *)v15 + 5);
          v20.x1 = v15[4];
          *(_QWORD *)&v20.y1 = __PAIR__(v17, v18);
          v20.y2 = v16;
        }
        else
        {
          v20 = 0i64;
        }
        s9Rect = v20;
        v19 = (Scaleform::Render::Matrix2x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v2->vfptr[2].__vecDelDtor)(v2);
        Scaleform::Render::Scale9GridInfo::Scale9GridInfo(v12, &s9Rect, v19, &shapeMtx, &bounds);
      }
      return;
    }
    v11 = (Scaleform::Render::Matrix2x4<float> *)((__int64 (__fastcall *)(Scaleform::GFx::InteractiveObject *))v2->vfptr[2].__vecDelDtor)(v2);
    Scaleform::Render::Matrix2x4<float>::Append(&shapeMtx, v11);
    v2 = v2->pParent;
  }
}

// File Line: 1589
// RVA: 0x90AE50
void __fastcall Scaleform::GFx::DisplayObjectBase::SetRendererString(Scaleform::GFx::DisplayObjectBase *this, const char *str)
{
  const char *v2; // rdi
  Scaleform::Render::TreeNode *v3; // rax
  Scaleform::Render::ContextImpl::Entry *v4; // rbx
  bool v5; // zf

  v2 = str;
  v3 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  v4 = (Scaleform::Render::ContextImpl::Entry *)&v3->0;
  if ( v3 )
    ++v3->RefCount;
  Scaleform::Render::TreeNode::SetRendererString(v3, v2);
  if ( v4 )
  {
    v5 = v4->RefCount-- == 1;
    if ( v5 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v4);
  }
}

// File Line: 1595
// RVA: 0x90ADF0
void __fastcall Scaleform::GFx::DisplayObjectBase::SetRendererFloat(Scaleform::GFx::DisplayObjectBase *this, float fl)
{
  Scaleform::Render::TreeNode *v2; // rax
  Scaleform::Render::ContextImpl::Entry *v3; // rbx
  bool v4; // zf

  v2 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  v3 = (Scaleform::Render::ContextImpl::Entry *)&v2->0;
  if ( v2 )
    ++v2->RefCount;
  Scaleform::Render::TreeNode::SetRendererFloat(v2, fl);
  if ( v3 )
  {
    v4 = v3->RefCount-- == 1;
    if ( v4 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v3);
  }
}

// File Line: 1601
// RVA: 0x8DD7A0
const char *__fastcall Scaleform::GFx::DisplayObjectBase::GetRendererString(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode *v1; // rax
  Scaleform::Render::ContextImpl::Entry *v2; // rbx
  const char *result; // rax
  const char *v4; // rdi
  bool v5; // zf

  v1 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  v2 = (Scaleform::Render::ContextImpl::Entry *)&v1->0;
  if ( v1 )
    ++v1->RefCount;
  result = Scaleform::Render::TreeNode::GetRendererString(v1);
  v4 = result;
  if ( v2 )
  {
    v5 = v2->RefCount-- == 1;
    if ( v5 )
    {
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v2);
      result = v4;
    }
  }
  return result;
}

// File Line: 1607
// RVA: 0x8DD740
float __fastcall Scaleform::GFx::DisplayObjectBase::GetRendererFloat(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode *v1; // rax
  Scaleform::Render::ContextImpl::Entry *v2; // rbx
  float result; // xmm0_4
  bool v4; // zf

  v1 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  v2 = (Scaleform::Render::ContextImpl::Entry *)&v1->0;
  if ( v1 )
    ++v1->RefCount;
  result = Scaleform::Render::TreeNode::GetRendererFloat(v1);
  if ( v2 )
  {
    v4 = v2->RefCount-- == 1;
    if ( v4 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v2);
  }
  return result;
}

// File Line: 1613
// RVA: 0x8C7510
void __fastcall Scaleform::GFx::DisplayObjectBase::DisableBatching(Scaleform::GFx::DisplayObjectBase *this, bool b)
{
  bool v2; // di
  Scaleform::Render::TreeNode *v3; // rax
  Scaleform::Render::ContextImpl::Entry *v4; // rbx
  bool v5; // zf

  v2 = b;
  v3 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  v4 = (Scaleform::Render::ContextImpl::Entry *)&v3->0;
  if ( v3 )
    ++v3->RefCount;
  Scaleform::Render::TreeNode::DisableBatching(v3, v2);
  if ( v4 )
  {
    v5 = v4->RefCount-- == 1;
    if ( v5 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v4);
  }
}

// File Line: 1619
// RVA: 0x8E6EB0
_BOOL8 __fastcall Scaleform::GFx::DisplayObjectBase::IsBatchingDisabled(Scaleform::GFx::DisplayObjectBase *this)
{
  Scaleform::Render::TreeNode *v1; // rax
  Scaleform::Render::ContextImpl::Entry *v2; // rbx
  bool v3; // di
  bool v4; // zf

  v1 = Scaleform::GFx::DisplayObjectBase::GetRenderNode(this);
  v2 = (Scaleform::Render::ContextImpl::Entry *)&v1->0;
  if ( v1 )
    ++v1->RefCount;
  v3 = Scaleform::Render::TreeNode::IsBatchingDisabled(v1);
  if ( v2 )
  {
    v4 = v2->RefCount-- == 1;
    if ( v4 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper(v2);
  }
  return v3;
}

// File Line: 1631
// RVA: 0x895560
void __fastcall Scaleform::GFx::DisplayObject::DisplayObject(Scaleform::GFx::DisplayObject *this, Scaleform::GFx::ASMovieRootBase *pasRoot, Scaleform::GFx::InteractiveObject *pparent, __int64 id)
{
  Scaleform::GFx::DisplayObject *v4; // rbx
  Scaleform::GFx::ResourceId ida; // [rsp+58h] [rbp+20h]

  v4 = this;
  ida.Id = *(_DWORD *)id;
  Scaleform::GFx::DisplayObjectBase::DisplayObjectBase(
    (Scaleform::GFx::DisplayObjectBase *)&this->vfptr,
    pasRoot,
    pparent,
    (Scaleform::GFx::ResourceId)&ida);
  v4->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::DisplayObject::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
  v4->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::DisplayObject::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
  v4->pNameHandle.pObject = 0i64;
  v4->pScrollRect = 0i64;
  v4->pMaskCharacter = 0i64;
  v4->Flags |= 0x100u;
  v4->Flags = 10;
}

// File Line: 1640
// RVA: 0x8A3CD0
void __fastcall Scaleform::GFx::DisplayObject::~DisplayObject(Scaleform::GFx::DisplayObject *this)
{
  Scaleform::GFx::DisplayObject *v1; // rbx
  Scaleform::GFx::DisplayObject::ScrollRectInfo *v2; // rdi
  Scaleform::RefCountNTSImpl *v3; // rcx
  Scaleform::GFx::DisplayObject *v4; // rcx
  Scaleform::GFx::CharacterHandle *v5; // rax
  Scaleform::GFx::CharacterHandle *v6; // rdi
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::GFx::ASStringNode *v10; // rcx

  v1 = this;
  this->vfptr = (Scaleform::RefCountNTSImplCoreVtbl *)&Scaleform::GFx::DisplayObject::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
  this->vfptr = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>Vtbl *)&Scaleform::GFx::DisplayObject::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
  v2 = this->pScrollRect;
  if ( v2 )
  {
    v3 = (Scaleform::RefCountNTSImpl *)&v2->Mask.pObject->vfptr;
    if ( v3 )
      Scaleform::RefCountNTSImpl::Release(v3);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v2);
  }
  if ( v1->pMaskCharacter )
  {
    if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *))v1->vfptr[78].__vecDelDtor)(v1) )
    {
      if ( !v1->pMaskCharacter )
        goto LABEL_13;
      Scaleform::GFx::DisplayObject::SetMask(v1, 0i64, v1->ClipDepth != 0);
    }
    if ( v1->pMaskCharacter )
    {
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *))v1->vfptr[78].__vecDelDtor)(v1) )
      {
        v4 = v1->pMaskCharacter;
        if ( v4 )
          Scaleform::GFx::DisplayObject::SetMask(v4, 0i64, 1);
      }
    }
  }
LABEL_13:
  v5 = v1->pNameHandle.pObject;
  if ( v5 )
    v5->pCharacter = 0i64;
  v6 = v1->pNameHandle.pObject;
  if ( v6 )
  {
    if ( --v6->RefCount <= 0 )
    {
      v7 = v6->OriginalName.pNode;
      v8 = v7->RefCount-- == 1;
      if ( v8 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v7);
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
  Scaleform::GFx::DisplayObjectBase::~DisplayObjectBase((Scaleform::GFx::DisplayObjectBase *)&v1->vfptr);
}

// File Line: 1657
// RVA: 0x8EC730
void __fastcall Scaleform::GFx::InteractiveObject::OnEventLoad(Scaleform::GFx::InteractiveObject *this)
{
  unsigned __int8 v1; // al

  this->Flags |= 0x2000u;
  v1 = this->AvmObjOffset;
  if ( v1 )
    ((void (*)(void))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->vfptr + 4 * v1))[9].__vecDelDtor)();
}

// File Line: 1664
// RVA: 0x8EC8F0
void __fastcall Scaleform::GFx::DisplayObject::OnEventUnload(Scaleform::GFx::DisplayObject *this)
{
  Scaleform::GFx::DisplayObject *v1; // rbx
  Scaleform::GFx::CharacterHandle *v2; // rax
  unsigned __int8 v3; // al

  v1 = this;
  Scaleform::GFx::DisplayObjectBase::OnEventUnload((Scaleform::GFx::DisplayObjectBase *)&this->vfptr);
  v2 = v1->pNameHandle.pObject;
  if ( v2 )
    v2->pCharacter = 0i64;
  v3 = v1->AvmObjOffset;
  if ( v3 )
    ((void (__fastcall *)(signed __int64))(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v1->vfptr + 4 * v3))[10].__vecDelDtor)((signed __int64)v1 + 4 * v3);
}

// File Line: 1674
// RVA: 0x8C26F0
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::DisplayObject::CreateNewInstanceName(Scaleform::GFx::DisplayObject *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rbx
  Scaleform::GFx::ASString *v3; // rax
  Scaleform::GFx::ASStringNode *v4; // rcx
  Scaleform::GFx::ASStringNode *v5; // rcx
  bool v6; // zf
  Scaleform::GFx::ASString resulta; // [rsp+40h] [rbp+8h]
  Scaleform::GFx::ASString *v9; // [rsp+48h] [rbp+10h]

  v9 = result;
  v2 = result;
  v3 = Scaleform::GFx::MovieImpl::CreateNewInstanceName(this->pASRoot->pMovieImpl, &resulta);
  v4 = v3->pNode;
  v2->pNode = v3->pNode;
  ++v4->RefCount;
  v5 = resulta.pNode;
  v6 = resulta.pNode->RefCount == 1;
  --v5->RefCount;
  if ( v6 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
  return v2;
}

// File Line: 1680
// RVA: 0x8BE8C0
Scaleform::GFx::CharacterHandle *__fastcall Scaleform::GFx::DisplayObject::CreateCharacterHandle(Scaleform::GFx::DisplayObject *this)
{
  Scaleform::GFx::DisplayObject *v1; // rdi
  Scaleform::GFx::CharacterHandle *v2; // rbp
  char v3; // si
  Scaleform::GFx::MovieImpl *v4; // rbx
  __int64 v5; // rdx
  __int64 v6; // r14
  Scaleform::GFx::ASStringManager *v7; // rax
  Scaleform::GFx::ASString *v8; // rbx
  Scaleform::GFx::ASStringNode *v9; // rcx
  Scaleform::GFx::ASStringNode *v10; // rax
  Scaleform::GFx::CharacterHandle *v11; // rbx
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::GFx::ASStringNode *v15; // rcx
  Scaleform::GFx::ASStringNode *v16; // rcx
  __int64 v17; // rcx
  Scaleform::GFx::CharacterHandle *v18; // rax
  Scaleform::GFx::CharacterHandle *v19; // rax
  Scaleform::GFx::CharacterHandle *v20; // rbx
  Scaleform::GFx::ASStringNode *v21; // rcx
  Scaleform::GFx::ASStringNode *v22; // rcx
  Scaleform::GFx::ASStringNode *v23; // rcx
  Scaleform::GFx::ASString name; // [rsp+60h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+68h] [rbp+10h]
  Scaleform::GFx::CharacterHandle *v27; // [rsp+70h] [rbp+18h]
  __int64 v28; // [rsp+78h] [rbp+20h]

  v1 = this;
  v2 = 0i64;
  v3 = 0;
  if ( this->pNameHandle.pObject )
    return v1->pNameHandle.pObject;
  v4 = this->pASRoot->pMovieImpl;
  if ( !((LOBYTE(this->Flags) >> 4) & 1) )
  {
    this->vfptr[82].__vecDelDtor((Scaleform::RefCountNTSImplCore *)this, (unsigned int)&name);
    result.pNode = (Scaleform::GFx::ASStringNode *)v4->pHeap;
    v18 = (Scaleform::GFx::CharacterHandle *)(*((__int64 (__fastcall **)(__int64, signed __int64))result.pNode->pData
                                              + 10))(
                                               v17,
                                               40i64);
    v27 = v18;
    if ( v18 )
    {
      Scaleform::GFx::CharacterHandle::CharacterHandle(
        v18,
        &name,
        (Scaleform::GFx::DisplayObject *)&v1->pParent->vfptr,
        v1);
      v2 = v19;
    }
    v20 = v1->pNameHandle.pObject;
    if ( v20 )
    {
      if ( --v20->RefCount <= 0 )
      {
        result.pNode = (Scaleform::GFx::ASStringNode *)v20;
        v21 = v20->OriginalName.pNode;
        v13 = v21->RefCount-- == 1;
        if ( v13 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v21);
        v22 = v20->NamePath.pNode;
        v13 = v22->RefCount-- == 1;
        if ( v13 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v22);
        v23 = v20->Name.pNode;
        v13 = v23->RefCount-- == 1;
        if ( v13 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v23);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v20);
      }
    }
    v1->pNameHandle.pObject = v2;
    v16 = name.pNode;
    goto LABEL_29;
  }
  v27 = (Scaleform::GFx::CharacterHandle *)v4->pHeap;
  v6 = (*(__int64 (__fastcall **)(Scaleform::GFx::DisplayObject *, signed __int64, _QWORD))(*(_QWORD *)&v27->RefCount
                                                                                          + 80i64))(
         this,
         40i64,
         0i64);
  v28 = v6;
  if ( v6 )
  {
    v7 = (Scaleform::GFx::ASStringManager *)((__int64 (__cdecl *)(Scaleform::GFx::ASMovieRootBase *, __int64))v4->pASMovieRoot.pObject->vfptr[59].__vecDelDtor)(
                                              v4->pASMovieRoot.pObject,
                                              v5);
    v8 = Scaleform::GFx::ASStringManager::CreateEmptyString(v7, &result);
    v3 = 1;
    v9 = v8->pNode;
    *(Scaleform::GFx::ASString *)(v6 + 16) = (Scaleform::GFx::ASString)v8->pNode;
    ++v9->RefCount;
    Scaleform::GFx::ASStringManager::CreateEmptyString(v8->pNode->pManager, (Scaleform::GFx::ASString *)(v6 + 24));
    v10 = v8->pNode;
    *(Scaleform::GFx::ASString *)(v6 + 32) = (Scaleform::GFx::ASString)v8->pNode;
    ++v10->RefCount;
    *(_DWORD *)v6 = 1;
    *(_QWORD *)(v6 + 8) = 0i64;
  }
  else
  {
    v6 = 0i64;
  }
  v11 = v1->pNameHandle.pObject;
  if ( v11 )
  {
    if ( --v11->RefCount <= 0 )
    {
      v27 = v11;
      v12 = v11->OriginalName.pNode;
      v13 = v12->RefCount-- == 1;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v12);
      v14 = v11->NamePath.pNode;
      v13 = v14->RefCount-- == 1;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v14);
      v15 = v11->Name.pNode;
      v13 = v15->RefCount-- == 1;
      if ( v13 )
        Scaleform::GFx::ASStringNode::ReleaseNode(v15);
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v11);
    }
  }
  v1->pNameHandle.pObject = (Scaleform::GFx::CharacterHandle *)v6;
  if ( v3 & 1 )
  {
    v16 = result.pNode;
LABEL_29:
    v13 = v16->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v16);
  }
  return v1->pNameHandle.pObject;
}

// File Line: 1707
// RVA: 0x8DB270
double __fastcall Scaleform::GFx::DisplayObject::GetMouseX(Scaleform::GFx::DisplayObject *this)
{
  Scaleform::GFx::MovieImpl *v1; // rdx
  float v2; // xmm5_4
  float v3; // xmm4_4
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm5_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm5_4
  float v10; // xmm0_4
  __m128d v11; // xmm0
  __int64 v12; // rcx
  Scaleform::Render::Point<float> pt; // [rsp+40h] [rbp+8h]
  Scaleform::Render::Point<float> p; // [rsp+48h] [rbp+10h]

  v1 = this->pASRoot->pMovieImpl;
  v2 = v1->mMouseState[0].LastPosition.y;
  v3 = v1->mMouseState[0].LastPosition.x;
  v4 = v1->ViewOffsetY * 20.0;
  v5 = v1->VisibleFrameRect.x2;
  pt.y = v2;
  v6 = v2 - v4;
  v7 = v1->VisibleFrameRect.y2;
  v8 = v5 - v1->VisibleFrameRect.x1;
  pt.x = v3;
  v9 = v6 / (float)(v7 - v1->VisibleFrameRect.y1);
  v10 = v1->ViewOffsetX * 20.0;
  LODWORD(v1->ScreenToWorld.Sy) = COERCE_UNSIGNED_INT((float)(v9 * 2.0) - 1.0) ^ _xmm[0];
  v1->ScreenToWorld.Sx = (float)((float)((float)(v3 - v10) / v8) * 2.0) - 1.0;
  Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(
    (Scaleform::GFx::DisplayObjectBase *)&this->vfptr,
    &p,
    &pt,
    0,
    0i64);
  v11 = _mm_cvtps_pd((__m128)LODWORD(p.x));
  v11.m128d_f64[0] = v11.m128d_f64[0] + 0.5;
  v12 = (unsigned int)(signed int)v11.m128d_f64[0];
  if ( v12 != 0x8000000000000000i64 && (double)(signed int)v12 != v11.m128d_f64[0] )
    v11.m128d_f64[0] = (double)(signed int)(v12 - (_mm_movemask_pd(_mm_unpckl_pd(v11, v11)) & 1));
  return v11.m128d_f64[0] * 0.05;
}

// File Line: 1716
// RVA: 0x8DB3A0
double __fastcall Scaleform::GFx::DisplayObject::GetMouseY(Scaleform::GFx::DisplayObject *this)
{
  Scaleform::GFx::MovieImpl *v1; // rdx
  float v2; // xmm5_4
  float v3; // xmm4_4
  float v4; // xmm0_4
  float v5; // xmm1_4
  float v6; // xmm5_4
  float v7; // xmm0_4
  float v8; // xmm1_4
  float v9; // xmm5_4
  float v10; // xmm0_4
  __m128d v11; // xmm0
  __int64 v12; // rcx
  Scaleform::Render::Point<float> pt; // [rsp+40h] [rbp+8h]
  Scaleform::Render::Point<float> p; // [rsp+48h] [rbp+10h]

  v1 = this->pASRoot->pMovieImpl;
  v2 = v1->mMouseState[0].LastPosition.y;
  v3 = v1->mMouseState[0].LastPosition.x;
  v4 = v1->ViewOffsetY * 20.0;
  v5 = v1->VisibleFrameRect.x2;
  pt.y = v2;
  v6 = v2 - v4;
  v7 = v1->VisibleFrameRect.y2;
  v8 = v5 - v1->VisibleFrameRect.x1;
  pt.x = v3;
  v9 = v6 / (float)(v7 - v1->VisibleFrameRect.y1);
  v10 = v1->ViewOffsetX * 20.0;
  LODWORD(v1->ScreenToWorld.Sy) = COERCE_UNSIGNED_INT((float)(v9 * 2.0) - 1.0) ^ _xmm[0];
  v1->ScreenToWorld.Sx = (float)((float)((float)(v3 - v10) / v8) * 2.0) - 1.0;
  Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(
    (Scaleform::GFx::DisplayObjectBase *)&this->vfptr,
    &p,
    &pt,
    0,
    0i64);
  v11 = _mm_cvtps_pd((__m128)LODWORD(p.y));
  v11.m128d_f64[0] = v11.m128d_f64[0] + 0.5;
  v12 = (unsigned int)(signed int)v11.m128d_f64[0];
  if ( v12 != 0x8000000000000000i64 && (double)(signed int)v12 != v11.m128d_f64[0] )
    v11.m128d_f64[0] = (double)(signed int)(v12 - (_mm_movemask_pd(_mm_unpckl_pd(v11, v11)) & 1));
  return v11.m128d_f64[0] * 0.05;
}

// File Line: 1725
// RVA: 0x909A10
void __fastcall Scaleform::GFx::DisplayObject::SetName(Scaleform::GFx::DisplayObject *this, Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::ASString *v2; // rbx
  Scaleform::GFx::DisplayObject *v3; // rdi
  Scaleform::GFx::CharacterHandle *v4; // rcx
  Scaleform::GFx::CharacterHandle *v5; // rax
  Scaleform::GFx::CharacterHandle *v6; // rax
  Scaleform::GFx::CharacterHandle *v7; // rsi
  Scaleform::GFx::CharacterHandle *v8; // rbx
  Scaleform::GFx::ASStringNode *v9; // rcx
  bool v10; // zf
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::ASStringNode *v12; // rcx
  int v13; // [rsp+58h] [rbp+10h]
  Scaleform::GFx::CharacterHandle *v14; // [rsp+60h] [rbp+18h]

  v2 = name;
  v3 = this;
  if ( name->pNode->Size )
    this->Flags &= 0xFFFDu;
  v4 = this->pNameHandle.pObject;
  if ( v4 )
  {
    Scaleform::GFx::CharacterHandle::ChangeName(v4, name, (Scaleform::GFx::DisplayObject *)&v3->pParent->vfptr);
  }
  else
  {
    v13 = 322;
    v5 = (Scaleform::GFx::CharacterHandle *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::DisplayObject *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                              Scaleform::Memory::pGlobalHeap,
                                              v3,
                                              40i64,
                                              &v13,
                                              -2i64);
    v14 = v5;
    if ( v5 )
    {
      Scaleform::GFx::CharacterHandle::CharacterHandle(v5, v2, (Scaleform::GFx::DisplayObject *)&v3->pParent->vfptr, v3);
      v7 = v6;
    }
    else
    {
      v7 = 0i64;
    }
    v8 = v3->pNameHandle.pObject;
    if ( v8 )
    {
      if ( --v8->RefCount <= 0 )
      {
        v9 = v8->OriginalName.pNode;
        v10 = v9->RefCount-- == 1;
        if ( v10 )
          Scaleform::GFx::ASStringNode::ReleaseNode(v9);
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
    v3->pNameHandle.pObject = v7;
  }
}

// File Line: 1742
// RVA: 0x909B50
void __fastcall Scaleform::GFx::DisplayObject::SetOriginalName(Scaleform::GFx::DisplayObject *this, Scaleform::GFx::ASString *name)
{
  Scaleform::GFx::ASString *v2; // rsi
  Scaleform::GFx::DisplayObject *v3; // rdi
  Scaleform::GFx::CharacterHandle *v4; // rbx
  Scaleform::GFx::ASStringNode *v5; // rdi
  Scaleform::GFx::ASStringNode *v6; // rcx
  bool v7; // zf

  v2 = name;
  v3 = this;
  Scaleform::GFx::DisplayObject::SetName(this, name);
  v4 = v3->pNameHandle.pObject;
  if ( v4 || (v4 = Scaleform::GFx::DisplayObject::CreateCharacterHandle(v3)) != 0i64 )
  {
    v5 = v2->pNode;
    ++v5->RefCount;
    v6 = v4->OriginalName.pNode;
    v7 = v6->RefCount-- == 1;
    if ( v7 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v6);
    v4->OriginalName.pNode = v5;
  }
}

// File Line: 1750
// RVA: 0x8DC030
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::DisplayObject::GetOriginalName(Scaleform::GFx::DisplayObject *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rbx
  Scaleform::GFx::DisplayObject *v3; // rdi
  Scaleform::GFx::CharacterHandle *v4; // rax
  Scaleform::GFx::ASStringNode *v5; // rax

  v2 = result;
  v3 = this;
  v4 = this->pNameHandle.pObject;
  if ( v4 || (v4 = Scaleform::GFx::DisplayObject::CreateCharacterHandle(this)) != 0i64 )
  {
    v5 = v4->OriginalName.pNode;
    v2->pNode = v5;
    ++v5->RefCount;
  }
  else
  {
    Scaleform::GFx::DisplayObject::GetName(v3, v2);
  }
  return v2;
}

// File Line: 1758
// RVA: 0x8DB590
Scaleform::GFx::ASString *__fastcall Scaleform::GFx::DisplayObject::GetName(Scaleform::GFx::DisplayObject *this, Scaleform::GFx::ASString *result)
{
  Scaleform::GFx::ASString *v2; // rbx
  Scaleform::GFx::DisplayObject *v3; // rdi
  Scaleform::GFx::CharacterHandle *v4; // rax
  __int64 v5; // rdx
  Scaleform::GFx::ASStringNode *v6; // rax
  Scaleform::GFx::ASMovieRootBase *v7; // rcx
  Scaleform::GFx::ASStringManager *v8; // rax

  v2 = result;
  v3 = this;
  v4 = this->pNameHandle.pObject;
  if ( v4 || (v4 = Scaleform::GFx::DisplayObject::CreateCharacterHandle(this)) != 0i64 )
  {
    v6 = v4->Name.pNode;
    v2->pNode = v6;
    ++v6->RefCount;
  }
  else
  {
    v7 = v3->pASRoot->pMovieImpl->pASMovieRoot.pObject;
    v8 = (Scaleform::GFx::ASStringManager *)((__int64 (__cdecl *)(Scaleform::GFx::ASMovieRootBase *, __int64))v7->vfptr[59].__vecDelDtor)(
                                              v7,
                                              v5);
    Scaleform::GFx::ASStringManager::CreateEmptyString(v8, v2);
  }
  return v2;
}

// File Line: 1767
// RVA: 0x8D4BF0
char *__fastcall Scaleform::GFx::DisplayObject::GetAbsolutePath(Scaleform::GFx::DisplayObject *this, Scaleform::String *ppath)
{
  unsigned __int8 v2; // al
  char *result; // rax

  v2 = this->AvmObjOffset;
  if ( v2 )
    result = (char *)(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->vfptr + 4 * v2))[6].__vecDelDtor(
                       (Scaleform::RefCountNTSImplCore *)((char *)this + 4 * v2),
                       (unsigned int)ppath);
  else
    result = &customWorldMapCaption;
  return result;
}

// File Line: 1774
// RVA: 0x906080
void __fastcall Scaleform::GFx::DisplayObject::SetAcceptAnimMoves(Scaleform::GFx::DisplayObject *this, bool accept)
{
  bool v2; // di
  Scaleform::GFx::DisplayObject *v3; // rbx
  Scaleform::GFx::DisplayObjectBase::GeomDataType *v4; // rax
  Scaleform::GFx::ASMovieRootBase *v5; // rdx
  __int64 v6; // [rsp+20h] [rbp-68h]
  long double v7; // [rsp+28h] [rbp-60h]
  long double v8; // [rsp+30h] [rbp-58h]
  __int64 v9; // [rsp+38h] [rbp-50h]
  __int128 v10; // [rsp+40h] [rbp-48h]
  __m128 v11; // [rsp+50h] [rbp-38h]
  __int128 v12; // [rsp+60h] [rbp-28h]
  __int128 v13; // [rsp+70h] [rbp-18h]

  v2 = accept;
  v3 = this;
  if ( !this->pGeomData )
  {
    v6 = 0i64;
    v10 = _xmm;
    v11 = _xmm;
    v8 = DOUBLE_100_0;
    v7 = DOUBLE_100_0;
    v9 = 0i64;
    v13 = 0i64;
    v12 = _xmm;
    v4 = Scaleform::GFx::DisplayObjectBase::GetGeomData(
           (Scaleform::GFx::DisplayObjectBase *)&this->vfptr,
           (Scaleform::GFx::DisplayObjectBase::GeomDataType *)&v6);
    Scaleform::GFx::DisplayObjectBase::SetGeomData((Scaleform::GFx::DisplayObjectBase *)&v3->vfptr, v4);
  }
  if ( v2 )
    v3->Flags |= 8u;
  else
    v3->Flags &= 0xFFF7u;
  v5 = v3->pASRoot;
  if ( (v5->pMovieImpl->Flags >> 13) & 1 )
    v3->Flags |= 0x10u;
  else
    v3->Flags &= 0xFFEFu;
  if ( (v5->pMovieImpl->Flags >> 13) & 1 )
  {
    if ( v2 )
    {
      Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v3->pGeomData);
      v3->pGeomData = 0i64;
    }
  }
}

// File Line: 1800
// RVA: 0x901240
void __fastcall Scaleform::GFx::DisplayObject::ResetClipDepth(Scaleform::GFx::DisplayObject *this)
{
  Scaleform::GFx::DisplayObject *v1; // rdi
  Scaleform::GFx::InteractiveObject *v2; // rcx
  Scaleform::GFx::InteractiveObject *v3; // rsi
  unsigned __int64 v4; // rcx
  unsigned __int64 v5; // rbx
  Scaleform::GFx::DisplayObject **v6; // rax

  v1 = this;
  if ( this->ClipDepth )
  {
    v2 = this->pParent;
    if ( !v2 )
      goto LABEL_15;
    v3 = 0i64;
    if ( (v2->Flags >> 9) & 1 )
      v3 = v2;
    if ( v3 )
    {
      v4 = *(_QWORD *)&v3[1].RefCount;
      v5 = 0i64;
      if ( v4 )
      {
        v6 = (Scaleform::GFx::DisplayObject **)v3[1].vfptr;
        while ( *v6 != v1 )
        {
          ++v5;
          v6 += 2;
          if ( v5 >= v4 )
            goto LABEL_10;
        }
      }
      else
      {
LABEL_10:
        v5 = -1i64;
      }
      Scaleform::GFx::DisplayList::RemoveFromRenderTree(
        (Scaleform::GFx::DisplayList *)&v3[1],
        (Scaleform::GFx::DisplayObjectBase *)&v3->vfptr,
        v5);
      v1->ClipDepth = 0;
      Scaleform::GFx::DisplayList::InsertIntoRenderTree(
        (Scaleform::GFx::DisplayList *)&v3[1],
        (Scaleform::GFx::DisplayObjectBase *)&v3->vfptr,
        v5);
    }
    else
    {
LABEL_15:
      v1->ClipDepth = 0;
    }
  }
}

// File Line: 1823
// RVA: 0x908C00
void __fastcall Scaleform::GFx::DisplayObject::SetMask(Scaleform::GFx::DisplayObject *this, Scaleform::GFx::DisplayObject *pmaskSprite, bool readdMaskToDisplayList)
{
  Scaleform::GFx::DisplayObject *v3; // rsi
  Scaleform::GFx::DisplayObject *v4; // rdi
  Scaleform::Render::TreeNode *v5; // rax
  Scaleform::Render::TreeNode *v6; // rbp
  Scaleform::GFx::DisplayObject *v7; // rbx
  Scaleform::GFx::DisplayObject *v8; // rcx
  Scaleform::GFx::DisplayObject *v9; // rcx
  Scaleform::Render::TreeNode *v10; // rbx
  Scaleform::Ptr<Scaleform::Render::TreeNode> *v11; // rax
  Scaleform::Render::TreeNode *v12; // rcx
  bool v13; // zf
  Scaleform::Ptr<Scaleform::Render::TreeNode> result; // [rsp+68h] [rbp+10h]
  bool v15; // [rsp+70h] [rbp+18h]
  Scaleform::Render::TreeNode *v16; // [rsp+78h] [rbp+20h]

  v15 = readdMaskToDisplayList;
  v3 = pmaskSprite;
  v4 = this;
  v5 = Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&this->vfptr);
  v6 = v5;
  if ( v5 )
    ++v5->RefCount;
  v16 = v5;
  Scaleform::GFx::DisplayObject::ResetClipDepth(v4);
  if ( v3 )
  {
    if ( v4->pScrollRect )
      Scaleform::GFx::DisplayObject::SetScrollRect(v4, 0i64);
    Scaleform::GFx::DisplayObject::ResetClipDepth(v3);
  }
  if ( v4->pMaskCharacter )
  {
    if ( !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *))v4->vfptr[78].__vecDelDtor)(v4) )
    {
      v7 = v4->pMaskCharacter;
      if ( v7 )
      {
        if ( v7->pMaskCharacter
          && !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *))v7->vfptr[78].__vecDelDtor)(v4->pMaskCharacter)
          && v7->pMaskCharacter )
        {
          Scaleform::GFx::DisplayObject::SetMask(v7, 0i64, 1);
        }
        v7->Flags &= 0xFFFBu;
        v7->pMaskCharacter = 0i64;
        Scaleform::Render::TreeNode::SetMaskNode(v6, 0i64);
        Scaleform::GFx::DisplayObjectBase::RemoveIndirectTransform((Scaleform::GFx::DisplayObjectBase *)&v7->vfptr, v15);
      }
    }
    if ( v4->pMaskCharacter )
    {
      if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *))v4->vfptr[78].__vecDelDtor)(v4) )
      {
        v8 = v4->pMaskCharacter;
        if ( v8 )
          Scaleform::GFx::DisplayObject::SetMask(v8, 0i64, 1);
      }
    }
  }
  if ( v3
    && v3->pMaskCharacter
    && ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *))v3->vfptr[78].__vecDelDtor)(v3)
    && v3->pMaskCharacter )
  {
    if ( ((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *))v3->vfptr[78].__vecDelDtor)(v3) )
      v9 = v3->pMaskCharacter;
    else
      v9 = 0i64;
    Scaleform::GFx::DisplayObject::SetMask(v9, 0i64, 1);
  }
  if ( v4->pMaskCharacter
    && !((unsigned __int8 (__fastcall *)(Scaleform::GFx::DisplayObject *))v4->vfptr[78].__vecDelDtor)(v4) )
  {
    Scaleform::RefCountNTSImpl::Release((Scaleform::RefCountNTSImpl *)&v4->pMaskCharacter->vfptr);
  }
  v10 = 0i64;
  if ( v3 )
  {
    v11 = Scaleform::GFx::DisplayObjectBase::SetIndirectTransform(
            (Scaleform::GFx::DisplayObjectBase *)&v3->vfptr,
            &result,
            v6);
    if ( v11->pObject )
      ++v11->pObject->RefCount;
    v10 = v11->pObject;
    v12 = result.pObject;
    if ( result.pObject )
    {
      v13 = result.pObject->RefCount-- == 1;
      if ( v13 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)&v12->0);
    }
  }
  Scaleform::Render::TreeNode::SetMaskNode(v6, v10);
  v4->Flags &= 0xFFFBu;
  if ( v10 )
  {
    v4->pMaskCharacter = v3;
    if ( v3 )
    {
      ++v3->RefCount;
      Scaleform::GFx::DisplayObject::SetMaskOwner(v3, v4);
    }
  }
  else
  {
    v4->pMaskCharacter = 0i64;
  }
  if ( v10 )
  {
    v13 = v10->RefCount-- == 1;
    if ( v13 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)&v10->0);
  }
  if ( v6 )
  {
    v13 = v6->RefCount-- == 1;
    if ( v13 )
      Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)&v6->0);
  }
}13 )
      Scaleform::R

// File Line: 1886
// RVA: 0x8DAD50
Scaleform::GFx::DisplayObject *__fastcall Scaleform::GFx::DisplayObject::GetMask(Scaleform::GFx::DisplayObject *this)
{
  Scaleform::GFx::DisplayObject *v1; // rbx
  Scaleform::GFx::DisplayObject *result; // rax

  v1 = this;
  if ( !this->pMaskCharacter || ((unsigned __int8 (*)(void))this->vfptr[78].__vecDelDtor)() )
    result = 0i64;
  else
    result = v1->pMaskCharacter;
  return result;
}

// File Line: 1896
// RVA: 0x908E20
void __fastcall Scaleform::GFx::DisplayObject::SetMaskOwner(Scaleform::GFx::DisplayObject *this, Scaleform::GFx::DisplayObject *pmaskOwner)
{
  Scaleform::GFx::DisplayObject *v2; // rdi
  Scaleform::GFx::DisplayObject *v3; // rbx

  v2 = pmaskOwner;
  v3 = this;
  if ( this->pMaskCharacter && !((unsigned __int8 (*)(void))this->vfptr[78].__vecDelDtor)() && v3->pMaskCharacter )
    Scaleform::GFx::DisplayObject::SetMask(v3, 0i64, 1);
  v3->pMaskCharacter = v2;
  if ( v2 )
    v3->Flags |= 4u;
  else
    v3->Flags &= 0xFFFBu;
}

// File Line: 1915
// RVA: 0x8DAE50
Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *__fastcall Scaleform::GFx::DisplayObject::GetMatrix(Scaleform::GFx::DisplayObject *this)
{
  Scaleform::GFx::DisplayObject::ScrollRectInfo *v1; // rax
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *result; // rax
  Scaleform::Render::TreeNode *v3; // rdx
  unsigned __int64 v4; // r8
  unsigned __int64 v5; // rdx

  v1 = this->pScrollRect;
  if ( v1 )
    return (Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *)&v1->OrigTransformMatrix;
  result = this->pIndXFormData;
  if ( !result )
  {
    v3 = this->pRenNode.pObject;
    if ( v3 )
    {
      v4 = (unsigned __int64)v3 & 0xFFFFFFFFFFFFF000ui64;
      v5 = (signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v3[-1]
                                                               - ((unsigned __int64)v3 & 0xFFFFFFFFFFFFF000ui64))
                                              * (signed __int128)5270498306774157605i64) >> 64) >> 4;
      result = (Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *)(*(_QWORD *)(*(_QWORD *)(v4 + 32)
                                                                                          + 8
                                                                                          * ((unsigned int)v5
                                                                                           + (v5 >> 63))
                                                                                          + 40)
                                                                              + 16i64);
    }
    else
    {
      result = (Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *)&Scaleform::Render::Matrix2x4<float>::Identity;
    }
  }
  return result;
}

// File Line: 1925
// RVA: 0x9092E0
void __fastcall Scaleform::GFx::DisplayObject::SetMatrix(Scaleform::GFx::DisplayObject *this, Scaleform::Render::Matrix2x4<float> *mt)
{
  Scaleform::GFx::DisplayObject::ScrollRectInfo *v2; // rax
  Scaleform::GFx::DisplayObject *v3; // rbx
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
  Scaleform::Render::TreeNode *v14; // rax
  Scaleform::GFx::DisplayObject::ScrollRectInfo *v15; // rcx
  float v16; // xmm2_4
  float v17; // xmm3_4
  Scaleform::Render::Matrix2x4<float> m; // [rsp+20h] [rbp-88h]
  Scaleform::Render::Matrix2x4<float> v19; // [rsp+40h] [rbp-68h]

  v2 = this->pScrollRect;
  v3 = this;
  if ( v2 )
  {
    v4 = mt->M[0][1];
    v5 = mt->M[0][2];
    v6 = mt->M[0][3];
    v7 = mt->M[1][0];
    v8 = mt->M[1][1];
    v9 = mt->M[1][2];
    v10 = mt->M[1][3];
    v2->OrigTransformMatrix.M[0][0] = mt->M[0][0];
    v2->OrigTransformMatrix.M[0][1] = v4;
    v2->OrigTransformMatrix.M[0][2] = v5;
    v2->OrigTransformMatrix.M[0][3] = v6;
    v2->OrigTransformMatrix.M[1][0] = v7;
    v2->OrigTransformMatrix.M[1][1] = v8;
    v2->OrigTransformMatrix.M[1][2] = v9;
    v2->OrigTransformMatrix.M[1][3] = v10;
    LODWORD(v2->OrigTransformMatrix.M[2][0]) = _xmm.m128_i32[0];
    LODWORD(v2->OrigTransformMatrix.M[2][1]) = (unsigned __int128)_mm_shuffle_ps(_xmm, _xmm, 85);
    LODWORD(v2->OrigTransformMatrix.M[2][2]) = (unsigned __int128)_mm_shuffle_ps(_xmm, _xmm, 170);
    v2->OrigTransformMatrix.M[2][3] = _xmm.m128_f32[3];
    v11 = this->pScrollRect;
    *(_OWORD *)&m.M[0][0] = *(_OWORD *)&v11->OrigTransformMatrix.M[0][0];
    *(_OWORD *)&m.M[1][0] = *(_OWORD *)&v11->OrigTransformMatrix.M[1][0];
    v12 = COERCE_DOUBLE(*(_QWORD *)&v11->Rectangle.y1 ^ _xmm[0]);
    v13 = -v11->Rectangle.x1;
    m.M[0][3] = m.M[0][3] + (float)((float)(m.M[0][1] * v12) + (float)(m.M[0][0] * v13));
    m.M[1][3] = m.M[1][3] + (float)((float)(m.M[1][1] * v12) + (float)(m.M[1][0] * v13));
    v14 = Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&this->vfptr);
    Scaleform::Render::TreeNode::SetMatrix(v14, &m);
    v15 = v3->pScrollRect;
    *(_OWORD *)&v19.M[0][0] = _xmm;
    *(__m128 *)&v19.M[1][0] = _xmm;
    v16 = v15->Rectangle.y1;
    v17 = v15->Rectangle.x1;
    v19.M[0][3] = (float)(v16 * 0.0) + v17;
    v19.M[1][3] = (float)(v17 * 0.0) + v16;
    Scaleform::Render::TreeNode::SetMatrix(
      (Scaleform::Render::TreeNode *)&v15->Mask.pObject->pTreeContainer.pObject->0,
      &v19);
  }
  else
  {
    Scaleform::GFx::DisplayObjectBase::SetMatrix((Scaleform::GFx::DisplayObjectBase *)&this->vfptr, mt);
  }
}

// File Line: 1942
// RVA: 0x8DAD80
Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *__fastcall Scaleform::GFx::DisplayObject::GetMatrix3D(Scaleform::GFx::DisplayObject *this)
{
  Scaleform::GFx::DisplayObject::ScrollRectInfo *v1; // rax
  Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *result; // rax
  Scaleform::Render::TreeNode *v3; // rdx
  unsigned __int64 v4; // r8
  unsigned __int64 v5; // rdx

  v1 = this->pScrollRect;
  if ( v1 )
    return (Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *)&v1->OrigTransformMatrix;
  result = this->pIndXFormData;
  if ( !result )
  {
    v3 = this->pRenNode.pObject;
    if ( v3 )
    {
      v4 = (unsigned __int64)v3 & 0xFFFFFFFFFFFFF000ui64;
      v5 = (signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v3[-1]
                                                               - ((unsigned __int64)v3 & 0xFFFFFFFFFFFFF000ui64))
                                              * (signed __int128)5270498306774157605i64) >> 64) >> 4;
      result = (Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *)(*(_QWORD *)(*(_QWORD *)(v4 + 32)
                                                                                          + 8
                                                                                          * ((unsigned int)v5
                                                                                           + (v5 >> 63))
                                                                                          + 40)
                                                                              + 16i64);
    }
    else
    {
      result = (Scaleform::GFx::DisplayObjectBase::IndirectTransformDataType *)&Scaleform::Render::Matrix3x4<float>::Identity;
    }
  }
  return result;
}

// File Line: 1952
// RVA: 0x908E90
void __fastcall Scaleform::GFx::DisplayObject::SetMatrix3D(Scaleform::GFx::DisplayObject *this, Scaleform::Render::Matrix3x4<float> *mt)
{
  Scaleform::GFx::DisplayObject::ScrollRectInfo *v2; // r8
  Scaleform::GFx::DisplayObject::ScrollRectInfo *v3; // rax
  float v4; // er13
  float v5; // xmm7_4
  float v6; // xmm6_4
  Scaleform::Render::TreeNode *v7; // rax
  double *v8; // rax
  float v9; // xmm7_4
  float v10; // xmm6_4
  Scaleform::Render::Matrix3x4<float> m1; // [rsp+20h] [rbp-E0h]
  float v12; // [rsp+50h] [rbp-B0h]
  float v13; // [rsp+60h] [rbp-A0h]
  float v14; // [rsp+70h] [rbp-90h]
  Scaleform::Render::Matrix3x4<float> v15; // [rsp+80h] [rbp-80h]
  Scaleform::Render::Matrix3x4<float> m; // [rsp+B0h] [rbp-50h]
  int Dst; // [rsp+E0h] [rbp-20h]
  float v18; // [rsp+ECh] [rbp-14h]
  int v19; // [rsp+F4h] [rbp-Ch]
  float v20; // [rsp+FCh] [rbp-4h]
  __int64 v21; // [rsp+108h] [rbp+8h]
  Scaleform::Render::Matrix3x4<float> m2; // [rsp+110h] [rbp+10h]
  Scaleform::GFx::DisplayObject *v23; // [rsp+1B0h] [rbp+B0h]

  v23 = this;
  v2 = this->pScrollRect;
  if ( v2 )
  {
    v2->OrigTransformMatrix = *mt;
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
    memset(&Dst, 0, 0x30ui64);
    Dst = 1065353216;
    v19 = 1065353216;
    v18 = v6;
    v20 = v5;
    *(_OWORD *)&m1.M[0][0] = *(_OWORD *)&m.M[0][0];
    v21 = 1065353216i64;
    *(_QWORD *)&m1.M[1][1] = __PAIR__(LODWORD(m.M[1][2]), LODWORD(v4));
    m1.M[1][3] = m.M[1][3];
    *(_OWORD *)&m1.M[2][0] = *(_OWORD *)&m.M[2][0];
    m1.M[1][0] = m.M[1][0];
    Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&m, &m1, (Scaleform::Render::Matrix3x4<float> *)&Dst);
    v7 = Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v23->vfptr);
    Scaleform::Render::TreeNode::SetMatrix3D(v7, &m);
    memset(&v15, 0, 0x30ui64);
    v8 = &v23->pScrollRect->Rectangle.x1;
    LODWORD(v15.M[0][0]) = (_DWORD)FLOAT_1_0;
    LODWORD(v15.M[1][1]) = (_DWORD)FLOAT_1_0;
    LODWORD(v15.M[2][2]) = (_DWORD)FLOAT_1_0;
    v9 = v8[1];
    v10 = *v8;
    memset(&m2, 0, 0x30ui64);
    m2.M[0][0] = 1.0;
    m2.M[1][1] = 1.0;
    *(_QWORD *)&m2.M[2][2] = 1065353216i64;
    m2.M[0][3] = v10;
    *(_QWORD *)&m1.M[0][1] = *(_QWORD *)&v15.M[0][1];
    m1.M[0][3] = v15.M[0][3];
    *(_QWORD *)&m1.M[1][2] = *(_QWORD *)&v15.M[1][2];
    *(_QWORD *)&m1.M[1][0] = __PAIR__((unsigned int)FLOAT_1_0, LODWORD(v15.M[1][0]));
    *(_QWORD *)&m1.M[2][0] = *(_QWORD *)&v15.M[2][0];
    m2.M[1][3] = v9;
    LODWORD(m1.M[0][0]) = (_DWORD)FLOAT_1_0;
    *(_QWORD *)&m1.M[2][2] = __PAIR__(LODWORD(v15.M[2][3]), (unsigned int)FLOAT_1_0);
    Scaleform::Render::Matrix3x4<float>::MultiplyMatrix(&v15, &m1, &m2);
    Scaleform::Render::TreeNode::SetMatrix3D(
      (Scaleform::Render::TreeNode *)&v23->pScrollRect->Mask.pObject->pTreeContainer.pObject->0,
      &v15);
  }
  else
  {
    Scaleform::GFx::DisplayObjectBase::SetMatrix3D((Scaleform::GFx::DisplayObjectBase *)&this->vfptr, mt);
  }
}

// File Line: 1975
// RVA: 0x90B790
void __fastcall Scaleform::GFx::DisplayObject::SetScrollRect(Scaleform::GFx::DisplayObject *this, Scaleform::Render::Rect<double> *r)
{
  Scaleform::Render::Rect<double> *v2; // r12
  Scaleform::GFx::DisplayObject *v3; // rdi
  Scaleform::Render::TreeNode *v4; // rax
  Scaleform::Render::TreeNode *v5; // rbp
  Scaleform::GFx::DisplayObject::ScrollRectInfo *v6; // rdx
  _QWORD *v7; // rbx
  Scaleform::RefCountNTSImpl *v8; // rcx
  unsigned __int64 v9; // r14
  __int64 v10; // rsi
  long double *v11; // rcx
  long double v12; // xmm2_8
  long double v13; // xmm1_8
  long double v14; // xmm0_8
  _DWORD *v15; // rdx
  Scaleform::GFx::DisplayObject::ScrollRectInfo *v16; // rcx
  Scaleform::GFx::DrawingContext *v17; // rsi
  Scaleform::GFx::DisplayObject::ScrollRectInfo *v18; // rbx
  Scaleform::RefCountNTSImpl *v19; // rcx
  float v20; // xmm6_4
  float v21; // xmm7_4
  Scaleform::RefCountNTSImplCoreVtbl *v22; // r8
  __int64 v23; // rdx
  Scaleform::Render::Matrix2x4<float> m; // [rsp+30h] [rbp-78h]
  int v25; // [rsp+C0h] [rbp+18h]
  __int64 v26; // [rsp+C8h] [rbp+20h]

  v2 = r;
  v3 = this;
  if ( this->pMaskCharacter
    && !((unsigned __int8 (__cdecl *)(Scaleform::GFx::DisplayObject *))this->vfptr[78].__vecDelDtor)(this)
    && v3->pMaskCharacter )
  {
    Scaleform::GFx::DisplayObject::SetMask(v3, 0i64, 1);
  }
  if ( (v3->Flags & 0x8000u) == 0 )
  {
    v4 = Scaleform::GFx::DisplayObjectBase::GetRenderNode((Scaleform::GFx::DisplayObjectBase *)&v3->vfptr);
    v5 = v4;
    if ( v3->pScrollRect )
    {
      Scaleform::Render::TreeNode::SetMaskNode(v4, 0i64);
      v6 = v3->pScrollRect;
      if ( v6->IsOrig3D )
      {
        Scaleform::Render::TreeNode::SetMatrix3D(v5, &v6->OrigTransformMatrix);
      }
      else
      {
        *(_OWORD *)&m.M[0][0] = *(_OWORD *)&v6->OrigTransformMatrix.M[0][0];
        *(_OWORD *)&m.M[1][0] = *(_OWORD *)&v6->OrigTransformMatrix.M[1][0];
        Scaleform::Render::TreeNode::SetMatrix(v5, &m);
      }
    }
    if ( v2 )
    {
      v9 = ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v5[-1]
                                                                  - ((unsigned __int64)v5 & 0xFFFFFFFFFFFFF000ui64))
                                                 * (signed __int128)5270498306774157605i64) >> 64) >> 63)
         + ((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v5[-1]
                                                                - ((unsigned __int64)v5 & 0xFFFFFFFFFFFFF000ui64))
                                               * (signed __int128)5270498306774157605i64) >> 64) >> 4);
      if ( (*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v5 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                 + 8
                                 * (((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v5[-1]
                                                                                           - ((unsigned __int64)v5 & 0xFFFFFFFFFFFFF000ui64))
                                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                                  + (unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v5[-1] - ((unsigned __int64)v5 & 0xFFFFFFFFFFFFF000ui64))
                                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                                 + 40)
                     + 10i64) >> 4) & 1 )
        Scaleform::Render::TreeNode::SetMaskNode(v5, 0i64);
      if ( !v3->pScrollRect )
      {
        v25 = 322;
        v10 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::GFx::DisplayObject *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                Scaleform::Memory::pGlobalHeap,
                v3,
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
        v3->pScrollRect = (Scaleform::GFx::DisplayObject::ScrollRectInfo *)v10;
      }
      v11 = &v3->pScrollRect->Rectangle.x1;
      v12 = v2->y2;
      v13 = v2->x2;
      v14 = v2->y1;
      *v11 = v2->x1;
      v11[1] = v14;
      v11[2] = v13;
      v11[3] = v12;
      v15 = *(_DWORD **)(*(_QWORD *)(((unsigned __int64)v5 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                       + 8i64 * (unsigned int)v9
                       + 40);
      v16 = v3->pScrollRect;
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
      v3->pScrollRect->IsOrig3D = (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v5 & 0xFFFFFFFFFFFFF000ui64)
                                                                    + 0x20)
                                                        + 8i64 * (unsigned int)v9
                                                        + 40)
                                            + 10i64) >> 9) & 1;
      v17 = Scaleform::GFx::MovieImpl::CreateDrawingContext(v3->pASRoot->pMovieImpl);
      v18 = v3->pScrollRect;
      v19 = (Scaleform::RefCountNTSImpl *)&v18->Mask.pObject->vfptr;
      if ( v19 )
        Scaleform::RefCountNTSImpl::Release(v19);
      v18->Mask.pObject = v17;
      Scaleform::GFx::DrawingContext::BeginSolidFill(v3->pScrollRect->Mask.pObject, 0xFFFFFFFF);
      v20 = v2->x2 - v2->x1;
      v21 = v2->y2 - v2->y1;
      Scaleform::GFx::DrawingContext::MoveTo(v3->pScrollRect->Mask.pObject, 0.0, 0.0);
      Scaleform::GFx::DrawingContext::LineTo(v3->pScrollRect->Mask.pObject, v20, 0.0);
      Scaleform::GFx::DrawingContext::LineTo(v3->pScrollRect->Mask.pObject, v20, v21);
      Scaleform::GFx::DrawingContext::LineTo(v3->pScrollRect->Mask.pObject, 0.0, v21);
      Scaleform::GFx::DrawingContext::EndFill(v3->pScrollRect->Mask.pObject);
      Scaleform::GFx::DrawingContext::UpdateRenderNode(v3->pScrollRect->Mask.pObject);
      v22 = v3->vfptr;
      v23 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)v5 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                      + 8i64 * (unsigned int)v9
                      + 40);
      if ( v3->pScrollRect->IsOrig3D )
        v22[5].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v3->vfptr, v23 + 16);
      else
        v22[3].__vecDelDtor((Scaleform::RefCountNTSImplCore *)&v3->vfptr, v23 + 16);
      Scaleform::Render::TreeNode::SetMaskNode(
        v5,
        (Scaleform::Render::TreeNode *)&v3->pScrollRect->Mask.pObject->pTreeContainer.pObject->0);
    }
    else
    {
      v7 = (_QWORD *)&v3->pScrollRect->Rectangle.x1;
      if ( v7 )
      {
        v8 = (Scaleform::RefCountNTSImpl *)v7[4];
        if ( v8 )
          Scaleform::RefCountNTSImpl::Release(v8);
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v7);
      }
      v3->pScrollRect = 0i64;
    }
  }
}

// File Line: 2041
// RVA: 0x8E2E10
bool __fastcall Scaleform::GFx::DisplayObject::HasEventHandler(Scaleform::GFx::DisplayObject *this, Scaleform::GFx::EventId *id)
{
  unsigned __int8 v2; // al
  bool result; // al

  v2 = this->AvmObjOffset;
  if ( v2 )
    result = (__int64)(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->vfptr + 4 * v2))[7].__vecDelDtor(
                        (Scaleform::RefCountNTSImplCore *)((char *)this + 4 * v2),
                        (unsigned int)id);
  else
    result = 0;
  return result;
}

// File Line: 2048
// RVA: 0x8EC670
bool __fastcall Scaleform::GFx::DisplayObject::OnEvent(Scaleform::GFx::DisplayObject *this, Scaleform::GFx::EventId *id)
{
  unsigned __int8 v2; // al
  bool result; // al

  v2 = this->AvmObjOffset;
  if ( v2 )
    result = (__int64)(*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&this->vfptr + 4 * v2))[8].__vecDelDtor(
                        (Scaleform::RefCountNTSImplCore *)((char *)this + 4 * v2),
                        (unsigned int)id);
  else
    result = 0;
  return result;
}

// File Line: 2056
// RVA: 0x913A90
char __fastcall Scaleform::GFx::DisplayObject::TransformPointToLocalAndCheckBounds(Scaleform::GFx::DisplayObject *this, Scaleform::Render::Point<float> *p, Scaleform::Render::Point<float> *pt, bool bPtInParentSpace, Scaleform::Render::Matrix2x4<float> *mat)
{
  Scaleform::Render::Point<float> *v5; // rdi
  Scaleform::GFx::DisplayObject *v6; // rbx
  float v7; // xmm3_4
  float v8; // xmm2_4
  double *v9; // rax
  float v10; // xmm0_4
  float v11; // xmm1_4
  double *v12; // rax
  Scaleform::Render::Point<float> pa; // [rsp+40h] [rbp+8h]

  v5 = p;
  v6 = this;
  if ( this->pScrollRect )
  {
    Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(
      (Scaleform::GFx::DisplayObjectBase *)&this->vfptr,
      &pa,
      pt,
      bPtInParentSpace,
      mat);
    v7 = pa.x;
    v8 = pa.y;
    v5->x = pa.x;
    v5->y = v8;
    v9 = &v6->pScrollRect->Rectangle.x1;
    v10 = *v9;
    v11 = (float)v9[1] + v8;
    v5->x = v10 + v7;
    v5->y = v11;
    if ( v7 < 0.0 )
      return 0;
    if ( v8 < 0.0 )
      return 0;
    v12 = &v6->pScrollRect->Rectangle.x1;
    if ( v7 > v12[2] - *v12 || v8 > v12[3] - v12[1] )
      return 0;
  }
  else
  {
    Scaleform::GFx::DisplayObjectBase::TransformPointToLocal(
      (Scaleform::GFx::DisplayObjectBase *)&this->vfptr,
      p,
      pt,
      bPtInParentSpace,
      mat);
  }
  return 1;
}

// File Line: 2079
// RVA: 0x894FF0
void __fastcall Scaleform::GFx::CharacterHandle::CharacterHandle(Scaleform::GFx::CharacterHandle *this, Scaleform::GFx::ASString *name, Scaleform::GFx::DisplayObject *pparent, Scaleform::GFx::DisplayObject *pcharacter)
{
  Scaleform::GFx::DisplayObject *v4; // rdi
  Scaleform::GFx::DisplayObject *v5; // rsi
  Scaleform::GFx::ASString *v6; // r15
  Scaleform::GFx::CharacterHandle *v7; // rbx
  Scaleform::GFx::ASStringNode *v8; // rax
  Scaleform::GFx::ASStringNode *v9; // rax
  unsigned __int8 v10; // al
  Scaleform::GFx::ASStringNode *v11; // rsi
  Scaleform::GFx::ASStringNode *v12; // rcx
  bool v13; // zf
  Scaleform::GFx::ASStringNode *v14; // rcx
  Scaleform::String str; // [rsp+68h] [rbp+10h]
  Scaleform::GFx::ASString result; // [rsp+78h] [rbp+20h]

  v4 = pcharacter;
  v5 = pparent;
  v6 = name;
  v7 = this;
  v8 = name->pNode;
  this->Name = (Scaleform::GFx::ASString)name->pNode;
  ++v8->RefCount;
  Scaleform::GFx::ASStringManager::CreateEmptyString(name->pNode->pManager, &this->NamePath);
  v9 = v6->pNode;
  v7->OriginalName = (Scaleform::GFx::ASString)v6->pNode;
  ++v9->RefCount;
  v7->RefCount = 1;
  v7->pCharacter = v4;
  if ( v4 && v4->pASRoot->AVMVersion == 1 )
  {
    Scaleform::String::String(&str);
    if ( v5 )
    {
      v10 = v5->AvmObjOffset;
      if ( v10 )
        (*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v5->vfptr + 4 * v10))[6].__vecDelDtor(
          (Scaleform::RefCountNTSImplCore *)((char *)&v5->vfptr + 4 * v10),
          (unsigned int)&str);
      Scaleform::String::AppendString(&str, ".", -1i64);
    }
    Scaleform::String::AppendString(&str, v7->Name.pNode->pData, -1i64);
    v11 = Scaleform::GFx::ASStringManager::CreateString(v6->pNode->pManager, &result, &str)->pNode;
    ++v11->RefCount;
    v12 = v7->NamePath.pNode;
    v13 = v12->RefCount-- == 1;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    v7->NamePath.pNode = v11;
    v14 = result.pNode;
    v13 = result.pNode->RefCount == 1;
    --v14->RefCount;
    if ( v13 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v14);
    if ( _InterlockedExchangeAdd(
           (volatile signed __int32 *)((str.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
           0xFFFFFFFF) == 1 )
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
}

// File Line: 2098
// RVA: 0x8A3780
void __fastcall Scaleform::GFx::CharacterHandle::~CharacterHandle(Scaleform::GFx::CharacterHandle *this)
{
  Scaleform::GFx::CharacterHandle *v1; // rbx
  Scaleform::GFx::ASStringNode *v2; // rcx
  bool v3; // zf
  Scaleform::GFx::ASStringNode *v4; // rcx
  Scaleform::GFx::ASStringNode *v5; // rcx

  v1 = this;
  v2 = this->OriginalName.pNode;
  v3 = v2->RefCount-- == 1;
  if ( v3 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v2);
  v4 = v1->NamePath.pNode;
  v3 = v4->RefCount-- == 1;
  if ( v3 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v4);
  v5 = v1->Name.pNode;
  v3 = v5->RefCount-- == 1;
  if ( v3 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v5);
}

// File Line: 2110
// RVA: 0x8BA400
void __fastcall Scaleform::GFx::CharacterHandle::ChangeName(Scaleform::GFx::CharacterHandle *this, Scaleform::GFx::ASString *name, Scaleform::GFx::DisplayObject *pparent)
{
  Scaleform::GFx::DisplayObject *v3; // rbx
  Scaleform::GFx::ASString *v4; // r14
  Scaleform::GFx::CharacterHandle *v5; // rdi
  Scaleform::GFx::ASStringNode *v6; // rsi
  Scaleform::GFx::ASStringNode *v7; // rcx
  bool v8; // zf
  unsigned __int8 v9; // al
  Scaleform::GFx::ASStringNode *v10; // rsi
  Scaleform::GFx::ASStringNode *v11; // rcx
  Scaleform::GFx::ASStringNode *v12; // rcx
  Scaleform::String str; // [rsp+50h] [rbp+8h]
  Scaleform::GFx::ASString result; // [rsp+58h] [rbp+10h]

  v3 = pparent;
  v4 = name;
  v5 = this;
  v6 = name->pNode;
  ++v6->RefCount;
  v7 = this->Name.pNode;
  v8 = v7->RefCount-- == 1;
  if ( v8 )
    Scaleform::GFx::ASStringNode::ReleaseNode(v7);
  v5->Name.pNode = v6;
  if ( v3 && v3->pASRoot->AVMVersion == 1 )
  {
    Scaleform::String::String(&str);
    v9 = v3->AvmObjOffset;
    if ( v9 )
      (*(Scaleform::RefCountNTSImplCoreVtbl **)((char *)&v3->vfptr + 4 * v9))[6].__vecDelDtor(
        (Scaleform::RefCountNTSImplCore *)((char *)&v3->vfptr + 4 * v9),
        (unsigned int)&str);
    Scaleform::String::AppendString(&str, ".", -1i64);
    Scaleform::String::AppendString(&str, v5->Name.pNode->pData, -1i64);
    v10 = Scaleform::GFx::ASStringManager::CreateString(v4->pNode->pManager, &result, &str)->pNode;
    ++v10->RefCount;
    v11 = v5->NamePath.pNode;
    v8 = v11->RefCount-- == 1;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v11);
    v5->NamePath.pNode = v10;
    v12 = result.pNode;
    v8 = result.pNode->RefCount == 1;
    --v12->RefCount;
    if ( v8 )
      Scaleform::GFx::ASStringNode::ReleaseNode(v12);
    if ( _InterlockedExchangeAdd(
           (volatile signed __int32 *)((str.HeapTypeBits & 0xFFFFFFFFFFFFFFFCui64) + 8),
           0xFFFFFFFF) == 1 )
      ((void (__cdecl *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
}

// File Line: 2130
// RVA: 0x9039F0
Scaleform::GFx::DisplayObject *__fastcall Scaleform::GFx::CharacterHandle::ResolveCharacter(Scaleform::GFx::CharacterHandle *this, Scaleform::GFx::MovieImpl *proot)
{
  Scaleform::GFx::DisplayObject *result; // rax

  result = this->pCharacter;
  if ( !result )
    result = (Scaleform::GFx::DisplayObject *)proot->pASMovieRoot.pObject->vfptr[8].__vecDelDtor(
                                                (Scaleform::RefCountImplCore *)proot->pASMovieRoot.pObject,
                                                (unsigned int)&this->NamePath);
  return result;
}

// File Line: 2138
// RVA: 0x8CE400
Scaleform::GFx::DisplayObject *__fastcall Scaleform::GFx::CharacterHandle::ForceResolveCharacter(Scaleform::GFx::CharacterHandle *this, Scaleform::GFx::MovieImpl *proot)
{
  return (Scaleform::GFx::DisplayObject *)proot->pASMovieRoot.pObject->vfptr[8].__vecDelDtor(
                                            (Scaleform::RefCountImplCore *)proot->pASMovieRoot.pObject,
                                            (unsigned int)&this->NamePath);
}

