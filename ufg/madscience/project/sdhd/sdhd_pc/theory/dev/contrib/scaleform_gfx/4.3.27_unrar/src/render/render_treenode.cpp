// File Line: 29
// RVA: 0x9A8020
void __fastcall Scaleform::Render::TreeNode::NodeData::ReleaseNodes(Scaleform::Render::TreeNode::NodeData *this)
{
  if ( (this->Flags & 0x10) != 0 )
    Scaleform::Render::TreeNode::removeThisAsMaskOwner(this);
  Scaleform::Render::StateBag::ReleaseNodes(&this->States);
}

// File Line: 62
// RVA: 0x9E2AA0
void __fastcall Scaleform::Render::TreeNode::NodeData::expandByFilterBounds(
        Scaleform::Render::Filter *filter,
        Scaleform::Render::Rect<float> *bounds)
{
  Scaleform::Render::FilterType Type; // eax
  float v3; // xmm3_4
  float vfptr_high; // xmm2_4
  float v5; // xmm6_4
  float v6; // xmm7_4
  float v7; // xmm8_4
  float v8; // xmm7_4
  float v9; // xmm5_4
  float v10; // xmm6_4
  Scaleform::Render::FilterType v11; // eax
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  bool v14; // cc
  __m128 v15; // xmm2
  int v16; // ecx
  __m128 v17; // xmm1
  int v18; // ecx

  if ( filter )
  {
    Type = filter->Type;
    if ( (unsigned int)Type <= Filter_GradientBevel )
    {
      if ( ((Type - 3) & 0xFFFFFFFD) != 0 )
        v3 = *(float *)&FLOAT_1_0;
      else
        v3 = FLOAT_2_0;
      vfptr_high = (float)SHIDWORD(filter[1].vfptr);
      v5 = (float)((float)((float)((float)(*((float *)&filter[1].RefCount + 1) * 0.050000001) + 1.0) * 20.0) * vfptr_high)
         * v3;
      v6 = (float)((float)((float)((float)(*(float *)&filter[1].RefCount * 0.050000001) + 1.0) * 20.0) * vfptr_high)
         * v3;
      v7 = bounds->x1 - v6;
      v8 = v6 + bounds->x2;
      v9 = bounds->y1 - v5;
      v10 = v5 + bounds->y2;
      bounds->x2 = v8;
      bounds->x1 = v7;
      bounds->y2 = v10;
      bounds->y1 = v9;
      v11 = filter->Type;
      if ( v11 == Filter_Shadow || (unsigned int)(v11 - 3) <= 2 )
      {
        v12 = (__m128)(unsigned int)filter[1].Type;
        v13 = (__m128)*(unsigned int *)&filter[1].Frozen;
        v14 = v12.m128_f32[0] <= 0.0;
        v15 = _mm_and_ps(v12, (__m128)(unsigned int)_xmm);
        v15.m128_f32[0] = v15.m128_f32[0] * v3;
        v16 = (int)v15.m128_f32[0];
        if ( v14 )
        {
          if ( v16 != 0x80000000 && (float)v16 != v15.m128_f32[0] )
            v15.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v15, v15)) & 1) + v16);
          bounds->x2 = v8;
          bounds->x1 = v7 - v15.m128_f32[0];
        }
        else
        {
          if ( v16 != 0x80000000 && (float)v16 != v15.m128_f32[0] )
            v15.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v15, v15)) & 1) + v16);
          bounds->x2 = v15.m128_f32[0] + v8;
        }
        v14 = v13.m128_f32[0] <= 0.0;
        v17 = _mm_and_ps(v13, (__m128)(unsigned int)_xmm);
        v17.m128_f32[0] = v17.m128_f32[0] * v3;
        v18 = (int)v17.m128_f32[0];
        if ( v14 )
        {
          if ( v18 != 0x80000000 && (float)v18 != v17.m128_f32[0] )
            v17.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v17, v17)) & 1) + v18);
          bounds->y2 = v10;
          bounds->y1 = v9 - v17.m128_f32[0];
        }
        else
        {
          bounds->y1 = v9;
          if ( v18 != 0x80000000 && (float)v18 != v17.m128_f32[0] )
            v17.m128_f32[0] = (float)(!(_mm_movemask_ps(_mm_unpacklo_ps(v17, v17)) & 1) + v18);
          bounds->y2 = v17.m128_f32[0] + v10;
        }
      }
      Scaleform::Render::SnapRectToPixels(bounds, COERCE_DOUBLE((unsigned __int64)LODWORD(FLOAT_0_5)));
    }
  }
}

// File Line: 105
// RVA: 0x9FA4B0
void __fastcall Scaleform::Render::TreeNode::NodeData::updateOriginalBoundState(
        Scaleform::Render::TreeNode::NodeData *this,
        Scaleform::Render::Rect<float> *bounds)
{
  __int64 v4; // rax
  void (__fastcall ***v5)(_QWORD, _QWORD); // rbx
  int v6; // [rsp+58h] [rbp+10h] BYREF
  __int64 v7; // [rsp+60h] [rbp+18h]
  void (__fastcall ***v8)(_QWORD, _QWORD); // [rsp+68h] [rbp+20h]

  if ( bounds->x1 == this->AproxLocalBounds.x1
    && bounds->x2 == this->AproxLocalBounds.x2
    && bounds->y1 == this->AproxLocalBounds.y1
    && bounds->y2 == this->AproxLocalBounds.y2 )
  {
    if ( Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::OrigNodeBoundsState>(this) )
      Scaleform::Render::StateBag::RemoveState(&this->States, State_OrigNodeBounds);
  }
  else
  {
    v6 = 2;
    v4 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeNode::NodeData *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
           Scaleform::Memory::pGlobalHeap,
           this,
           32i64,
           &v6,
           -2i64);
    v5 = (void (__fastcall ***)(_QWORD, _QWORD))v4;
    v7 = v4;
    if ( v4 )
    {
      *(_QWORD *)(v4 + 16) = 0i64;
      *(_QWORD *)(v4 + 24) = 0i64;
      *(_QWORD *)v4 = &Scaleform::RefCountImplCore::`vftable;
      *(_DWORD *)(v4 + 8) = 1;
      *(_QWORD *)v4 = &Scaleform::RefCountImpl::`vftable;
      *(_QWORD *)v4 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
      *(_QWORD *)v4 = &Scaleform::RefCountBase<Scaleform::Render::Rect<float>,2>::`vftable;
      *(_QWORD *)v4 = &Scaleform::Render::RectRef<float>::`vftable;
    }
    else
    {
      v5 = 0i64;
    }
    v8 = v5;
    *((_DWORD *)v5 + 4) = LODWORD(bounds->x1);
    *((_DWORD *)v5 + 5) = LODWORD(bounds->y1);
    *((_DWORD *)v5 + 6) = LODWORD(bounds->x2);
    *((_DWORD *)v5 + 7) = LODWORD(bounds->y2);
    Scaleform::Render::StateBag::SetStateVoid(&this->States, &Scaleform::Render::OrigNodeBoundsState::InterfaceImpl, v5);
    if ( !_InterlockedDecrement((volatile signed __int32 *)v5 + 2) )
      (**v5)(v5, 1i64);
  }
}

// File Line: 122
// RVA: 0x9649B0
void __fastcall Scaleform::Render::TreeNode::NodeData::CopyGeomData(
        Scaleform::Render::TreeNode::NodeData *this,
        Scaleform::Render::TreeNode *destNode,
        Scaleform::Render::TreeNode *srcNode)
{
  char *v5; // r9
  __int64 v7; // r8
  __int64 v8; // rdx
  __int64 v9; // rdi
  Scaleform::Render::ContextImpl::Entry *pParent; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v12; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *pPrev; // rax
  bool v14; // zf
  Scaleform::Render::State *State; // rax
  Scaleform::Render::BlendMode pData; // edx
  Scaleform::Render::State *v17; // rax
  Scaleform::Render::Rect<float> v18; // [rsp+20h] [rbp-60h]
  Scaleform::Render::Rect<float> rect; // [rsp+30h] [rbp-50h] BYREF
  Scaleform::Render::Matrix4x4<float> Dst; // [rsp+40h] [rbp-40h] BYREF

  if ( destNode != srcNode )
  {
    v5 = (char *)srcNode - ((unsigned __int64)srcNode & 0xFFFFFFFFFFFFF000ui64);
    v7 = *(_QWORD *)(((unsigned __int64)srcNode & 0xFFFFFFFFFFFFF000ui64) + 0x20);
    v8 = (__int64)(v5 - 56) / 56;
    v9 = *(_QWORD *)(v7 + 8i64 * (unsigned int)v8 + 40);
    if ( ((LOBYTE(this->Flags) ^ *(_BYTE *)(v9 + 10)) & 1) != 0 )
    {
      Scaleform::Render::TreeNode::SetVisible(
        destNode,
        *(_BYTE *)(*(_QWORD *)(v7 + 8i64 * (unsigned int)v8 + 40) + 10i64) & 1);
      pParent = destNode->pParent;
      if ( pParent )
      {
        p_PNode = &pParent->PNode;
        if ( !pParent->PNode.pPrev )
        {
          v12 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(((unsigned __int64)pParent & 0xFFFFFFFFFFFFF000ui64)
                                                                         + 0x18);
          pPrev = v12[4].pPrev;
          v12 += 4;
          p_PNode->pPrev = pPrev;
          p_PNode->pNext = v12;
          v12->pPrev->pNext = p_PNode;
          v12->pPrev = p_PNode;
        }
      }
    }
    v14 = (*(_WORD *)(v9 + 10) & 0x200) == 0;
    this->M34.M[0][0] = *(float *)(v9 + 16);
    this->M34.M[0][1] = *(float *)(v9 + 20);
    this->M34.M[0][2] = *(float *)(v9 + 24);
    this->M34.M[0][3] = *(float *)(v9 + 28);
    this->M34.M[1][0] = *(float *)(v9 + 32);
    this->M34.M[1][1] = *(float *)(v9 + 36);
    this->M34.M[1][2] = *(float *)(v9 + 40);
    this->M34.M[1][3] = *(float *)(v9 + 44);
    if ( !v14 )
    {
      this->M34.M[2][0] = *(float *)(v9 + 48);
      this->M34.M[2][1] = *(float *)(v9 + 52);
      this->M34.M[2][2] = *(float *)(v9 + 56);
      this->M34.M[2][3] = *(float *)(v9 + 60);
      this->Flags |= 0x200u;
      memset(&Dst, 0, sizeof(Dst));
      Dst.M[0][0] = 1.0;
      Dst.M[1][1] = 1.0;
      Dst.M[2][2] = 1.0;
      Dst.M[3][3] = 1.0;
      if ( Scaleform::Render::TreeNode::GetProjectionMatrix3D(srcNode, &Dst) )
        Scaleform::Render::TreeNode::SetProjectionMatrix3D(destNode, &Dst);
      memset(&Dst, 0, 0x30ui64);
      Dst.M[0][0] = 1.0;
      Dst.M[1][1] = 1.0;
      Dst.M[2][2] = 1.0;
      if ( Scaleform::Render::TreeNode::GetViewMatrix3D(srcNode, (Scaleform::Render::Matrix3x4<float> *)&Dst) )
        Scaleform::Render::TreeNode::SetViewMatrix3D(destNode, (Scaleform::Render::Matrix3x4<float> *)&Dst);
    }
    *(_OWORD *)&this->Cx.M[0][0] = *(_OWORD *)(v9 + 80);
    *(_OWORD *)&this->Cx.M[1][0] = *(_OWORD *)(v9 + 96);
    State = Scaleform::Render::TreeNode::GetState(srcNode, State_BlendMode);
    if ( State )
      pData = (Scaleform::Render::BlendMode)State->pData;
    else
      pData = Blend_None;
    Scaleform::Render::TreeNode::SetBlendMode(destNode, pData);
    v17 = Scaleform::Render::TreeNode::GetState(srcNode, State_Scale9);
    if ( v17 )
      v18 = *(Scaleform::Render::Rect<float> *)(v17->DataValue + 16);
    else
      v18 = 0i64;
    rect = v18;
    if ( v18.x1 < v18.x2 && v18.y1 < v18.y2 )
      Scaleform::Render::TreeNode::SetScale9Grid(destNode, &rect);
  }
}

// File Line: 175
// RVA: 0x960FE0
char __fastcall Scaleform::Render::TreeNode::NodeData::CloneInit(
        Scaleform::Render::TreeNode::NodeData *this,
        Scaleform::Render::TreeNode *node,
        Scaleform::Render::ContextImpl::Context *context)
{
  __int64 v6; // r9
  Scaleform::Render::StateBag *WritableData; // r15
  Scaleform::Render::StateBag *p_States; // rbx
  __int64 v9; // rsi
  char v10; // r14
  Scaleform::Render::StateBag *v11; // rdi
  __int64 v12; // rbp
  Scaleform::Render::StateBag *v13; // r8
  unsigned __int64 v14; // rdx
  int v15; // eax
  unsigned __int64 ArraySize; // rdx
  unsigned __int64 v17; // rax
  unsigned __int64 v18; // rdx
  _QWORD *v19; // rcx
  unsigned __int64 v20; // r8
  __int64 v21; // rdi
  __int64 v22; // rax
  Scaleform::Render::TreeNode *v23; // rbx

  WritableData = (Scaleform::Render::StateBag *)Scaleform::Render::ContextImpl::Entry::getWritableData(node, 0xFF0000u);
  p_States = &this->States;
  if ( ((__int64)p_States->pInterface & 1) != 0 )
    v9 = 1i64;
  else
    v9 = p_States->ArraySize >> 1;
  v10 = 0;
  if ( v9 )
  {
    v11 = 0i64;
    v12 = 0i64;
    do
    {
      if ( ((__int64)p_States->pInterface & 1) != 0 )
        v13 = p_States;
      else
        v13 = (Scaleform::Render::StateBag *)(v12 + p_States->DataValue + 4);
      v14 = v13->ArraySize & 0xFFFFFFFFFFFFFFFEui64;
      if ( v14 )
        v15 = *(_DWORD *)(v14 + 8);
      else
        v15 = 0;
      if ( v15 == 4 )
      {
        v10 = 1;
      }
      else if ( v15 != 9 )
      {
        Scaleform::Render::StateBag::SetStateVoid(
          WritableData + 4,
          (Scaleform::Render::StateData::Interface *)v14,
          v13->pData);
      }
      v12 += 16i64;
      --v9;
    }
    while ( v9 );
    if ( v10 )
    {
      ArraySize = p_States->ArraySize;
      if ( p_States->ArraySize )
      {
        if ( (ArraySize & 1) != 0 )
        {
          if ( (ArraySize & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A60 )
            v11 = p_States;
        }
        else
        {
          v6 = p_States->DataValue + 4;
          v17 = 0i64;
          v18 = ArraySize >> 1;
          if ( v18 )
          {
            v19 = (_QWORD *)(p_States->DataValue + 4);
            while ( *v19 != qword_142451A60 )
            {
              ++v17;
              v19 += 2;
              if ( v17 >= v18 )
                goto LABEL_29;
            }
            v11 = (Scaleform::Render::StateBag *)(v6 + 16 * v17);
          }
        }
      }
LABEL_29:
      v20 = v11->DataValue & 0xFFFFFFFFFFFFF000ui64;
      v21 = *(_QWORD *)(*(_QWORD *)(v20 + 0x20) + 8i64 * (unsigned int)((LODWORD(v11->pData) - (int)v20 - 56) / 56) + 40);
      v22 = (*(__int64 (__fastcall **)(__int64, Scaleform::Render::ContextImpl::Context *, unsigned __int64, __int64, __int64))(*(_QWORD *)v21 + 64i64))(
              v21,
              context,
              v20,
              v6,
              -2i64);
      v23 = (Scaleform::Render::TreeNode *)v22;
      if ( v22 )
        (*(void (__fastcall **)(__int64, __int64, Scaleform::Render::ContextImpl::Context *))(*(_QWORD *)v21 + 72i64))(
          v21,
          v22,
          context);
      Scaleform::Render::TreeNode::SetMaskNode(node, v23);
      if ( v23 )
      {
        if ( v23->RefCount-- == 1 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper(v23);
      }
    }
  }
  return 1;
}

// File Line: 214
// RVA: 0x960CD0
Scaleform::Render::TreeNode *__fastcall Scaleform::Render::TreeNode::Clone(
        Scaleform::Render::TreeNode *this,
        Scaleform::Render::ContextImpl::Context *context)
{
  __int64 v3; // rdi
  Scaleform::Render::TreeNode *result; // rax
  Scaleform::Render::TreeNode *v5; // rbx

  v3 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                 + 40);
  result = (Scaleform::Render::TreeNode *)(*(__int64 (__fastcall **)(__int64, Scaleform::Render::ContextImpl::Context *))(*(_QWORD *)v3 + 64i64))(
                                            v3,
                                            context);
  v5 = result;
  if ( result )
  {
    (*(void (__fastcall **)(__int64, Scaleform::Render::TreeNode *, Scaleform::Render::ContextImpl::Context *))(*(_QWORD *)v3 + 72i64))(
      v3,
      result,
      context);
    return v5;
  }
  return result;
}

// File Line: 226
// RVA: 0x95F0A0
void __fastcall Scaleform::Render::TreeNode::Clear3D(Scaleform::Render::TreeNode *this)
{
  unsigned __int64 v2; // rcx
  unsigned int v3; // r8d
  unsigned __int64 v4; // rdx
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax

  v2 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v3 = 1;
  v4 = (__int64)((unsigned __int128)((__int64)((__int64)&this[-1] - v2) * (__int128)0x4924924924924925i64) >> 64) >> 4;
  if ( (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(v2 + 32) + 8 * ((unsigned int)v4 + (v4 >> 63)) + 40) + 10i64) & 0x200) != 0 )
    v3 = 8193;
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, v3);
  WritableData[1] = *(Scaleform::Render::ContextImpl::EntryData *)&Scaleform::Render::Matrix3x4<float>::Identity.M[0][0];
  *(float *)(&WritableData[1].Flags + 1) = Scaleform::Render::Matrix3x4<float>::Identity.M[0][3];
  WritableData[2] = *(Scaleform::Render::ContextImpl::EntryData *)&Scaleform::Render::Matrix3x4<float>::Identity.M[1][0];
  WritableData[3] = *(Scaleform::Render::ContextImpl::EntryData *)&Scaleform::Render::Matrix3x4<float>::Identity.M[2][0];
  WritableData->Flags &= ~0x200u;
}

// File Line: 238
// RVA: 0x9B1BF0
void __fastcall Scaleform::Render::TreeNode::SetMatrix(
        Scaleform::Render::TreeNode *this,
        Scaleform::Render::Matrix2x4<float> *m)
{
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v6; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *pPrev; // rax

  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 1u);
  p_PNode = &this->PNode;
  WritableData[1] = *(Scaleform::Render::ContextImpl::EntryData *)&m->M[0][0];
  *(float *)(&WritableData[1].Flags + 1) = m->M[0][3];
  WritableData[2] = *(Scaleform::Render::ContextImpl::EntryData *)&m->M[1][0];
  if ( !this->PNode.Scaleform::Render::ContextImpl::Entry::pPrev )
  {
    v6 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)
                                                                  + 0x18);
    pPrev = v6[4].pPrev;
    v6 += 4;
    p_PNode->pPrev = pPrev;
    this->PNode.pNext = v6;
    v6->pPrev->pNext = p_PNode;
    v6->pPrev = p_PNode;
  }
}

// File Line: 249
// RVA: 0x9B1990
void __fastcall Scaleform::Render::TreeNode::SetMatrix3D(
        Scaleform::Render::TreeNode *this,
        Scaleform::Render::Matrix3x4<float> *m)
{
  unsigned __int64 v4; // rbp
  unsigned int v5; // edi
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax
  Scaleform::Render::ContextImpl::Entry *pParent; // rbx
  Scaleform::Render::ContextImpl::EntryData *v8; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v10; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *pPrev; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v12; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v13; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v14; // rax

  v4 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v5 = 1;
  if ( (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 10i64) & 0x200) == 0 )
    v5 = 8193;
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, v5);
  WritableData[1] = *(Scaleform::Render::ContextImpl::EntryData *)&m->M[0][0];
  *(float *)(&WritableData[1].Flags + 1) = m->M[0][3];
  WritableData[2] = *(Scaleform::Render::ContextImpl::EntryData *)&m->M[1][0];
  *(float *)(&WritableData[2].Flags + 1) = m->M[1][3];
  WritableData[3] = *(Scaleform::Render::ContextImpl::EntryData *)&m->M[2][0];
  *(float *)(&WritableData[3].Flags + 1) = m->M[2][3];
  WritableData->Flags |= 0x200u;
  if ( (v5 & 0x2000) != 0 )
  {
    pParent = this->pParent;
    if ( pParent )
    {
      do
      {
        v8 = Scaleform::Render::ContextImpl::Entry::getWritableData(pParent, v5);
        p_PNode = &pParent->PNode;
        v8->Flags |= 0x4000u;
        if ( !pParent->PNode.pPrev )
        {
          v10 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(((unsigned __int64)pParent & 0xFFFFFFFFFFFFF000ui64)
                                                                         + 0x18);
          pPrev = v10[4].pPrev;
          v10 += 4;
          p_PNode->pPrev = pPrev;
          pParent->PNode.pNext = v10;
          v10->pPrev->pNext = p_PNode;
          v10->pPrev = p_PNode;
        }
        pParent = pParent->pParent;
      }
      while ( pParent
           && (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)pParent & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                    + 8i64
                                    * (unsigned int)((int)((_DWORD)pParent - ((unsigned int)pParent & 0xFFFFF000) - 56)
                                                   / 56)
                                    + 40)
                        + 10i64) & 0x200) == 0 );
    }
  }
  v12 = &this->PNode;
  if ( !this->PNode.Scaleform::Render::ContextImpl::Entry::pPrev )
  {
    v13 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(v4 + 24);
    v14 = v13[4].pPrev;
    v13 += 4;
    v12->pPrev = v14;
    this->PNode.pNext = v13;
    v13->pPrev->pNext = v12;
    v13->pPrev = v12;
  }
}

// File Line: 295
// RVA: 0x9B5E60
void __fastcall Scaleform::Render::TreeNode::SetVisible(Scaleform::Render::TreeNode *this, bool visible)
{
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax
  Scaleform::Render::ContextImpl::Entry *pParent; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v7; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *pPrev; // rax

  if ( (*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 10i64) & 1) != visible )
  {
    WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 4u);
    WritableData->Flags &= ~1u;
    WritableData->Flags |= visible;
    pParent = this->pParent;
    if ( pParent )
    {
      p_PNode = &pParent->PNode;
      if ( !pParent->PNode.pPrev )
      {
        v7 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(((unsigned __int64)pParent & 0xFFFFFFFFFFFFF000ui64)
                                                                      + 0x18);
        pPrev = v7[4].pPrev;
        v7 += 4;
        p_PNode->pPrev = pPrev;
        p_PNode->pNext = v7;
        v7->pPrev->pNext = p_PNode;
        v7->pPrev = p_PNode;
      }
    }
  }
}

// File Line: 310
// RVA: 0x9AF1F0
void __fastcall Scaleform::Render::TreeNode::SetEdgeAAMode(
        Scaleform::Render::TreeNode *this,
        Scaleform::Render::EdgeAAMode edgeAA)
{
  __int16 v2; // bx
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax

  v2 = edgeAA;
  if ( (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 10i64) & 0xC) != edgeAA )
  {
    WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x20u);
    WritableData->Flags &= 0xFFF3u;
    WritableData->Flags |= v2;
  }
}

// File Line: 320
// RVA: 0x98B930
Scaleform::Render::State *__fastcall Scaleform::Render::TreeNode::GetState(
        Scaleform::Render::TreeNode *this,
        Scaleform::Render::StateType state)
{
  __int64 v2; // r9
  __int64 v3; // r8
  __int64 v4; // r10
  unsigned __int64 v5; // rdx
  __int64 v6; // r10
  Scaleform::Render::StateData::Interface *v7; // r9
  __int64 v9; // rax
  __int64 v10; // r10
  unsigned __int64 v11; // rdx
  Scaleform::Render::StateData::Interface **i; // rcx

  v2 = state;
  v3 = 0i64;
  v4 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                 + 40);
  v5 = *(_QWORD *)(v4 + 64);
  v6 = v4 + 64;
  if ( !v5 )
    return (Scaleform::Render::State *)v3;
  v7 = StateType_Interfaces[v2];
  if ( (v5 & 1) != 0 )
  {
    if ( (Scaleform::Render::StateData::Interface *)(v5 & 0xFFFFFFFFFFFFFFFEui64) == v7 )
      return (Scaleform::Render::State *)v6;
    return (Scaleform::Render::State *)v3;
  }
  v9 = 0i64;
  v10 = *(_QWORD *)(v6 + 8) + 4i64;
  v11 = v5 >> 1;
  if ( !v11 )
    return (Scaleform::Render::State *)v3;
  for ( i = (Scaleform::Render::StateData::Interface **)v10; *i != v7; i += 2 )
  {
    if ( ++v9 >= v11 )
      return 0i64;
  }
  return (Scaleform::Render::State *)(v10 + 16 * v9);
}

// File Line: 325
// RVA: 0x9B3700
void __fastcall Scaleform::Render::TreeNode::SetScale9Grid(
        Scaleform::Render::TreeNode *this,
        Scaleform::Render::Rect<float> *rect)
{
  Scaleform::Render::StateBag *WritableData; // rax
  Scaleform::Render::StateBag *v5; // rsi
  volatile signed __int32 *v6; // rbx
  float y2; // xmm2_4
  float x2; // xmm1_4
  float y1; // xmm0_4
  int v10; // [rsp+58h] [rbp+10h] BYREF
  volatile signed __int32 *v11; // [rsp+60h] [rbp+18h]
  volatile signed __int32 *v12; // [rsp+68h] [rbp+20h]

  WritableData = (Scaleform::Render::StateBag *)Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x10000u);
  v5 = WritableData;
  if ( rect->x2 <= rect->x1 || rect->y2 <= rect->y1 )
  {
    Scaleform::Render::StateBag::RemoveState(WritableData + 4, State_Scale9);
  }
  else
  {
    v10 = 71;
    v6 = (volatile signed __int32 *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeNode *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                      Scaleform::Memory::pGlobalHeap,
                                      this,
                                      32i64,
                                      &v10,
                                      -2i64);
    v11 = v6;
    if ( v6 )
    {
      *(_QWORD *)v6 = &Scaleform::RefCountImplCore::`vftable;
      *((_DWORD *)v6 + 2) = 1;
      *(_QWORD *)v6 = &Scaleform::RefCountImpl::`vftable;
      *(_QWORD *)v6 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,71>::`vftable;
      *(_QWORD *)v6 = &Scaleform::RefCountBase<Scaleform::Render::Scale9GridRect,71>::`vftable;
      *(_QWORD *)v6 = &Scaleform::Render::Scale9GridRect::`vftable;
      *((_QWORD *)v6 + 2) = 0i64;
      *((_QWORD *)v6 + 3) = 0i64;
    }
    else
    {
      v6 = 0i64;
    }
    v12 = v6;
    if ( v6 )
    {
      y2 = rect->y2;
      x2 = rect->x2;
      y1 = rect->y1;
      *((_DWORD *)v6 + 4) = LODWORD(rect->x1);
      *((float *)v6 + 5) = y1;
      *((float *)v6 + 6) = x2;
      *((float *)v6 + 7) = y2;
      Scaleform::Render::StateBag::SetStateVoid(v5 + 4, &Scaleform::Render::Scale9State::InterfaceImpl, (void *)v6);
    }
    if ( v6 )
    {
      if ( !_InterlockedDecrement(v6 + 2) )
        (**(void (__fastcall ***)(volatile signed __int32 *, __int64))v6)(v6, 1i64);
    }
  }
}

// File Line: 343
// RVA: 0x9B57E0
void __fastcall Scaleform::Render::TreeNode::SetViewMatrix3D(
        Scaleform::Render::TreeNode *this,
        Scaleform::Render::Matrix3x4<float> *mat3D)
{
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rbp
  __int64 v5; // rax
  volatile signed __int32 *v6; // rdi
  int v7; // [rsp+68h] [rbp+10h] BYREF
  __int64 v8; // [rsp+70h] [rbp+18h]
  volatile signed __int32 *v9; // [rsp+78h] [rbp+20h]

  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x80000u);
  v7 = 2;
  v5 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeNode *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
         Scaleform::Memory::pGlobalHeap,
         this,
         64i64,
         &v7,
         -2i64);
  v6 = (volatile signed __int32 *)v5;
  v8 = v5;
  if ( v5 )
  {
    memset((void *)(v5 + 16), 0, 0x30ui64);
    *((_DWORD *)v6 + 4) = 1065353216;
    *((_DWORD *)v6 + 9) = 1065353216;
    *((_DWORD *)v6 + 14) = 1065353216;
    *(_QWORD *)v6 = &Scaleform::RefCountImplCore::`vftable;
    *((_DWORD *)v6 + 2) = 1;
    *(_QWORD *)v6 = &Scaleform::RefCountImpl::`vftable;
    *(_QWORD *)v6 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
    *(_QWORD *)v6 = &Scaleform::RefCountBase<Scaleform::Render::Matrix3x4<float>,2>::`vftable;
    *(_QWORD *)v6 = &Scaleform::Render::Matrix3x4Ref<float>::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  v9 = v6;
  *((_DWORD *)v6 + 4) = LODWORD(mat3D->M[0][0]);
  *((_DWORD *)v6 + 5) = LODWORD(mat3D->M[0][1]);
  *((_DWORD *)v6 + 6) = LODWORD(mat3D->M[0][2]);
  *((_DWORD *)v6 + 7) = LODWORD(mat3D->M[0][3]);
  *((_DWORD *)v6 + 8) = LODWORD(mat3D->M[1][0]);
  *((_DWORD *)v6 + 9) = LODWORD(mat3D->M[1][1]);
  *((_DWORD *)v6 + 10) = LODWORD(mat3D->M[1][2]);
  *((_DWORD *)v6 + 11) = LODWORD(mat3D->M[1][3]);
  *((_DWORD *)v6 + 12) = LODWORD(mat3D->M[2][0]);
  *((_DWORD *)v6 + 13) = LODWORD(mat3D->M[2][1]);
  *((_DWORD *)v6 + 14) = LODWORD(mat3D->M[2][2]);
  *((_DWORD *)v6 + 15) = LODWORD(mat3D->M[2][3]);
  Scaleform::Render::StateBag::SetStateVoid(
    (Scaleform::Render::StateBag *)&WritableData[4],
    &Scaleform::Render::ViewMatrix3DState::InterfaceImpl,
    (void *)v6);
  WritableData->Flags |= 0x800u;
  if ( !_InterlockedDecrement(v6 + 2) )
    (**(void (__fastcall ***)(volatile signed __int32 *, __int64))v6)(v6, 1i64);
}

// File Line: 353
// RVA: 0x960600
void __fastcall Scaleform::Render::TreeNode::ClearViewMatrix3D(Scaleform::Render::TreeNode *this)
{
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rbx

  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x80000u);
  Scaleform::Render::StateBag::RemoveState((Scaleform::Render::StateBag *)&WritableData[4], State_ViewMatrix3D);
  WritableData->Flags &= ~0x800u;
}

// File Line: 360
// RVA: 0x9B2CB0
void __fastcall Scaleform::Render::TreeNode::SetProjectionMatrix3D(
        Scaleform::Render::TreeNode *this,
        Scaleform::Render::Matrix4x4<float> *mat3D)
{
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rbp
  __int64 v5; // rax
  volatile signed __int32 *v6; // rdi
  int v7; // [rsp+68h] [rbp+10h] BYREF
  __int64 v8; // [rsp+70h] [rbp+18h]
  volatile signed __int32 *v9; // [rsp+78h] [rbp+20h]

  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x100000u);
  v7 = 2;
  v5 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeNode *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
         Scaleform::Memory::pGlobalHeap,
         this,
         80i64,
         &v7,
         -2i64);
  v6 = (volatile signed __int32 *)v5;
  v8 = v5;
  if ( v5 )
  {
    memset((void *)(v5 + 16), 0, 0x40ui64);
    *((_DWORD *)v6 + 4) = 1065353216;
    *((_DWORD *)v6 + 9) = 1065353216;
    *((_DWORD *)v6 + 14) = 1065353216;
    *((_DWORD *)v6 + 19) = 1065353216;
    *(_QWORD *)v6 = &Scaleform::RefCountImplCore::`vftable;
    *((_DWORD *)v6 + 2) = 1;
    *(_QWORD *)v6 = &Scaleform::RefCountImpl::`vftable;
    *(_QWORD *)v6 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
    *(_QWORD *)v6 = &Scaleform::RefCountBase<Scaleform::Render::Matrix4x4<float>,2>::`vftable;
    *(_QWORD *)v6 = &Scaleform::Render::Matrix4x4Ref<float>::`vftable;
  }
  else
  {
    v6 = 0i64;
  }
  v9 = v6;
  *((_DWORD *)v6 + 4) = LODWORD(mat3D->M[0][0]);
  *((_DWORD *)v6 + 5) = LODWORD(mat3D->M[0][1]);
  *((_DWORD *)v6 + 6) = LODWORD(mat3D->M[0][2]);
  *((_DWORD *)v6 + 7) = LODWORD(mat3D->M[0][3]);
  *((_DWORD *)v6 + 8) = LODWORD(mat3D->M[1][0]);
  *((_DWORD *)v6 + 9) = LODWORD(mat3D->M[1][1]);
  *((_DWORD *)v6 + 10) = LODWORD(mat3D->M[1][2]);
  *((_DWORD *)v6 + 11) = LODWORD(mat3D->M[1][3]);
  *((_DWORD *)v6 + 12) = LODWORD(mat3D->M[2][0]);
  *((_DWORD *)v6 + 13) = LODWORD(mat3D->M[2][1]);
  *((_DWORD *)v6 + 14) = LODWORD(mat3D->M[2][2]);
  *((_DWORD *)v6 + 15) = LODWORD(mat3D->M[2][3]);
  *((_DWORD *)v6 + 16) = LODWORD(mat3D->M[3][0]);
  *((_DWORD *)v6 + 17) = LODWORD(mat3D->M[3][1]);
  *((_DWORD *)v6 + 18) = LODWORD(mat3D->M[3][2]);
  *((_DWORD *)v6 + 19) = LODWORD(mat3D->M[3][3]);
  Scaleform::Render::StateBag::SetStateVoid(
    (Scaleform::Render::StateBag *)&WritableData[4],
    &Scaleform::Render::ProjectionMatrix3DState::InterfaceImpl,
    (void *)v6);
  WritableData->Flags |= 0x1000u;
  if ( !_InterlockedDecrement(v6 + 2) )
    (**(void (__fastcall ***)(volatile signed __int32 *, __int64))v6)(v6, 1i64);
}

// File Line: 370
// RVA: 0x9605D0
void __fastcall Scaleform::Render::TreeNode::ClearProjectionMatrix3D(Scaleform::Render::TreeNode *this)
{
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rbx

  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x100000u);
  Scaleform::Render::StateBag::RemoveState((Scaleform::Render::StateBag *)&WritableData[4], State_ProjectionMatrix3D);
  WritableData->Flags &= ~0x1000u;
}

// File Line: 377
// RVA: 0x9AE3D0
void __fastcall Scaleform::Render::TreeNode::SetBlendMode(Scaleform::Render::TreeNode *this, int mode)
{
  void *v2; // rdi
  Scaleform::Render::StateBag *v4; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v6; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *pPrev; // rax

  v2 = (void *)mode;
  v4 = (Scaleform::Render::StateBag *)&Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x20000u)[4];
  if ( (_DWORD)v2 )
    Scaleform::Render::StateBag::SetStateVoid(v4, &Scaleform::Render::BlendState::InterfaceImpl, v2);
  else
    Scaleform::Render::StateBag::RemoveState(v4, State_BlendMode);
  p_PNode = &this->PNode;
  if ( !this->PNode.Scaleform::Render::ContextImpl::Entry::pPrev )
  {
    v6 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)
                                                                  + 0x18);
    pPrev = v6[4].pPrev;
    v6 += 4;
    p_PNode->pPrev = pPrev;
    this->PNode.pNext = v6;
    v6->pPrev->pNext = p_PNode;
    v6->pPrev = p_PNode;
  }
}

// File Line: 388
// RVA: 0x9B1680
void __fastcall Scaleform::Render::TreeNode::SetMaskNode(
        Scaleform::Render::TreeNode *this,
        Scaleform::Render::TreeNode *node)
{
  Scaleform::Render::TreeNode::NodeData *WritableData; // rax
  Scaleform::Render::TreeNode::NodeData *v5; // rdi
  Scaleform::Render::ContextImpl::EntryData *v6; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v8; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *pPrev; // rax

  WritableData = (Scaleform::Render::TreeNode::NodeData *)Scaleform::Render::ContextImpl::Entry::getWritableData(
                                                            this,
                                                            0x40000u);
  v5 = WritableData;
  if ( node )
  {
    v6 = Scaleform::Render::ContextImpl::Entry::getWritableData(node, 0x80u);
    node->pParent = this;
    v6->Flags |= 0x20u;
    Scaleform::Render::StateBag::SetStateVoid(
      (Scaleform::Render::StateBag *)&v6[4],
      &Scaleform::Render::Internal_MaskOwnerState::InterfaceImpl,
      this);
    v5->Flags |= 0x10u;
    Scaleform::Render::StateBag::SetStateVoid(&v5->States, &Scaleform::Render::MaskNodeState::InterfaceImpl, node);
  }
  else if ( Scaleform::Render::TreeNode::removeThisAsMaskOwner(WritableData) )
  {
    Scaleform::Render::StateBag::RemoveState(&v5->States, State_MaskNode);
    v5->Flags &= ~0x10u;
  }
  p_PNode = &this->PNode;
  if ( !this->PNode.Scaleform::Render::ContextImpl::Entry::pPrev )
  {
    v8 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)
                                                                  + 0x18);
    pPrev = v8[4].pPrev;
    v8 += 4;
    p_PNode->pPrev = pPrev;
    this->PNode.pNext = v8;
    v8->pPrev->pNext = p_PNode;
    v8->pPrev = p_PNode;
  }
}

// File Line: 407
// RVA: 0x9AF300
void __fastcall Scaleform::Render::TreeNode::SetFilters(
        Scaleform::Render::TreeNode *this,
        Scaleform::Render::FilterSet *filters)
{
  Scaleform::Render::FilterSet *v3; // rsi
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rbx
  Scaleform::Render::ContextImpl::EntryData *v5; // rbx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v7; // rcx

  if ( filters && LODWORD(filters->Filters.Data.Size) )
  {
    v3 = Scaleform::Render::FilterSet::Clone(filters, 1, 0i64);
    WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x200002u);
    Scaleform::Render::StateBag::SetStateVoid(
      (Scaleform::Render::StateBag *)&WritableData[4],
      &Scaleform::Render::FilterState::InterfaceImpl,
      v3);
    WritableData->Flags |= 0x400u;
    if ( v3 && !_InterlockedDecrement(&v3->RefCount) )
      v3->vfptr->__vecDelDtor(v3, 1u);
  }
  else
  {
    if ( (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                               + 8i64
                               * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                               + 40)
                   + 10i64) & 0x400) == 0 )
      return;
    v5 = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x200002u);
    Scaleform::Render::StateBag::RemoveState((Scaleform::Render::StateBag *)&v5[4], State_Filter);
    v5->Flags &= ~0x400u;
  }
  p_PNode = &this->PNode;
  if ( !this->PNode.Scaleform::Render::ContextImpl::Entry::pPrev )
  {
    v7 = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)
                                                                            + 0x18)
                                                                + 64i64);
    p_PNode->pPrev = v7->pPrev;
    this->PNode.pNext = v7;
    v7->pPrev->pNext = p_PNode;
    v7->pPrev = p_PNode;
  }
}

// File Line: 433
// RVA: 0x9B24A0
void __fastcall Scaleform::Render::TreeNode::SetOrigScale9Parent(
        Scaleform::Render::TreeNode *this,
        Scaleform::Render::TreeNode *origParent)
{
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rbx
  Scaleform::Render::StateBag *v5; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v7; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *pPrev; // rax

  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x10000u);
  v5 = (Scaleform::Render::StateBag *)&WritableData[4];
  if ( origParent )
  {
    Scaleform::Render::StateBag::SetStateVoid(v5, &Scaleform::Render::OrigScale9ParentState::InterfaceImpl, origParent);
    WritableData->Flags |= 0x2000u;
  }
  else
  {
    Scaleform::Render::StateBag::RemoveState(v5, State_OrigScale9Parent);
    WritableData->Flags &= ~0x2000u;
  }
  p_PNode = &this->PNode;
  if ( !this->PNode.Scaleform::Render::ContextImpl::Entry::pPrev )
  {
    v7 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)
                                                                  + 0x18);
    pPrev = v7[4].pPrev;
    v7 += 4;
    p_PNode->pPrev = pPrev;
    this->PNode.pNext = v7;
    v7->pPrev->pNext = p_PNode;
    v7->pPrev = p_PNode;
  }
}

// File Line: 479
// RVA: 0x9F0470
char __fastcall Scaleform::Render::TreeNode::removeThisAsMaskOwner(Scaleform::Render::TreeNode::NodeData *thisData)
{
  Scaleform::Render::StateData::Interface *pInterface; // rdx
  Scaleform::Render::StateBag *p_States; // rbx
  __int64 v4; // rax
  unsigned __int64 v5; // r9
  unsigned __int64 v6; // rdx
  _QWORD *i; // rcx
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax

  pInterface = thisData->States.pInterface;
  p_States = &thisData->States;
  if ( !pInterface )
    return 0;
  if ( ((unsigned __int8)pInterface & 1) != 0 )
  {
    if ( ((unsigned __int64)pInterface & 0xFFFFFFFFFFFFFFFEui64) != qword_142451A60 )
      return 0;
  }
  else
  {
    v4 = 0i64;
    v5 = thisData->States.DataValue + 4;
    v6 = (unsigned __int64)pInterface >> 1;
    if ( !v6 )
      return 0;
    for ( i = (_QWORD *)(thisData->States.DataValue + 4); *i != qword_142451A60; i += 2 )
    {
      if ( ++v4 >= v6 )
        return 0;
    }
    p_States = (Scaleform::Render::StateBag *)(16 * v4 + v5);
  }
  if ( !p_States )
    return 0;
  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(
                   (Scaleform::Render::ContextImpl::Entry *)p_States->pData,
                   0x80u);
  *(_QWORD *)(p_States->DataValue + 32) = 0i64;
  WritableData->Flags &= ~0x20u;
  Scaleform::Render::StateBag::RemoveState((Scaleform::Render::StateBag *)&WritableData[4], State_Internal_MaskOwner);
  return 1;
}

// File Line: 496
// RVA: 0x964C40
void __fastcall Scaleform::Render::TreeNode::CopyGeomData(
        Scaleform::Render::TreeNode *this,
        Scaleform::Render::TreeNode *src)
{
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax

  WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(this, 3u);
  ((void (__fastcall *)(Scaleform::Render::ContextImpl::EntryData *, Scaleform::Render::TreeNode *, Scaleform::Render::TreeNode *))WritableData->vfptr[1].ConstructCopy)(
    WritableData,
    this,
    src);
}

// File Line: 501
// RVA: 0x9B3530
void __fastcall Scaleform::Render::TreeNode::SetRendererString(Scaleform::Render::TreeNode *this, const char *str)
{
  Scaleform::Render::StateBag *WritableData; // r14
  Scaleform::Render::State *State; // rax
  size_t v6; // rdi
  volatile signed __int32 *pData; // rbx
  int v8; // [rsp+68h] [rbp+10h] BYREF
  volatile signed __int32 *v9; // [rsp+70h] [rbp+18h]
  volatile signed __int32 *v10; // [rsp+78h] [rbp+20h]

  WritableData = (Scaleform::Render::StateBag *)Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400000u);
  State = Scaleform::Render::TreeNode::GetState(this, State_UserData);
  v6 = 0i64;
  v9 = 0i64;
  if ( State )
  {
    pData = (volatile signed __int32 *)State->pData;
    if ( pData )
      _InterlockedExchangeAdd(pData + 2, 1u);
  }
  else
  {
    v8 = 2;
    pData = (volatile signed __int32 *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeNode *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                         Scaleform::Memory::pGlobalHeap,
                                         this,
                                         40i64,
                                         &v8,
                                         -2i64);
    v10 = pData;
    if ( pData )
    {
      *(_QWORD *)pData = &Scaleform::RefCountImplCore::`vftable;
      *((_DWORD *)pData + 2) = 1;
      *(_QWORD *)pData = &Scaleform::RefCountImpl::`vftable;
      *(_QWORD *)pData = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
      *(_QWORD *)pData = &Scaleform::RefCountBase<Scaleform::Render::UserDataState::Data,2>::`vftable;
      *(_QWORD *)pData = &Scaleform::Render::UserDataState::Data::`vftable;
      _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
      *((_QWORD *)pData + 2) = (char *)&Scaleform::String::NullData.Size + 1;
      *((_DWORD *)pData + 6) = 0;
      *((_BYTE *)pData + 28) = 0;
      *((_DWORD *)pData + 8) = 0;
    }
    else
    {
      pData = 0i64;
    }
  }
  v9 = pData;
  if ( str )
  {
    v6 = -1i64;
    do
      ++v6;
    while ( str[v6] );
  }
  Scaleform::String::AssignString((Scaleform::String *)pData + 2, str, v6);
  *((_DWORD *)pData + 8) |= 1u;
  Scaleform::Render::StateBag::SetStateVoid(
    WritableData + 4,
    &Scaleform::Render::UserDataState::InterfaceImpl,
    (void *)pData);
  if ( _InterlockedExchangeAdd(pData + 2, 0xFFFFFFFF) == 1 )
    (**(void (__fastcall ***)(volatile signed __int32 *, __int64))v9)(v9, 1i64);
}

// File Line: 519
// RVA: 0x98B070
Scaleform::Render::State *__fastcall Scaleform::Render::TreeNode::GetRendererString(Scaleform::Render::TreeNode *this)
{
  Scaleform::Render::State *result; // rax

  result = Scaleform::Render::TreeNode::GetState(this, State_UserData);
  if ( result )
    return (Scaleform::Render::State *)((*(_QWORD *)(result->DataValue + 16) & 0xFFFFFFFFFFFFFFFCui64) + 12);
  return result;
}

// File Line: 530
// RVA: 0x9B33E0
void __fastcall Scaleform::Render::TreeNode::SetRendererFloat(Scaleform::Render::TreeNode *this, float f)
{
  Scaleform::Render::StateBag *WritableData; // rdi
  Scaleform::Render::State *State; // rax
  volatile signed __int32 *pData; // rbx
  int v6; // [rsp+68h] [rbp+10h] BYREF
  volatile signed __int32 *v7; // [rsp+70h] [rbp+18h]
  volatile signed __int32 *v8; // [rsp+78h] [rbp+20h]

  WritableData = (Scaleform::Render::StateBag *)Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400000u);
  State = Scaleform::Render::TreeNode::GetState(this, State_UserData);
  v7 = 0i64;
  if ( State )
  {
    pData = (volatile signed __int32 *)State->pData;
    if ( pData )
      _InterlockedExchangeAdd(pData + 2, 1u);
  }
  else
  {
    v6 = 2;
    pData = (volatile signed __int32 *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeNode *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                         Scaleform::Memory::pGlobalHeap,
                                         this,
                                         40i64,
                                         &v6,
                                         -2i64);
    v8 = pData;
    if ( pData )
    {
      *(_QWORD *)pData = &Scaleform::RefCountImplCore::`vftable;
      *((_DWORD *)pData + 2) = 1;
      *(_QWORD *)pData = &Scaleform::RefCountImpl::`vftable;
      *(_QWORD *)pData = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
      *(_QWORD *)pData = &Scaleform::RefCountBase<Scaleform::Render::UserDataState::Data,2>::`vftable;
      *(_QWORD *)pData = &Scaleform::Render::UserDataState::Data::`vftable;
      _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
      *((_QWORD *)pData + 2) = (char *)&Scaleform::String::NullData.Size + 1;
      *((_DWORD *)pData + 6) = 0;
      *((_BYTE *)pData + 28) = 0;
      *((_DWORD *)pData + 8) = 0;
    }
    else
    {
      pData = 0i64;
    }
  }
  v7 = pData;
  *((_DWORD *)pData + 8) |= 2u;
  *((float *)pData + 6) = f;
  Scaleform::Render::StateBag::SetStateVoid(
    WritableData + 4,
    &Scaleform::Render::UserDataState::InterfaceImpl,
    (void *)pData);
  if ( !_InterlockedDecrement(pData + 2) )
    (**(void (__fastcall ***)(volatile signed __int32 *, __int64))v7)(v7, 1i64);
}

// File Line: 548
// RVA: 0x98B040
float __fastcall Scaleform::Render::TreeNode::GetRendererFloat(Scaleform::Render::TreeNode *this)
{
  Scaleform::Render::State *State; // rax

  State = Scaleform::Render::TreeNode::GetState(this, State_UserData);
  if ( State )
    return *(float *)(State->DataValue + 24);
  else
    return 0.0;
}

// File Line: 559
// RVA: 0x96E210
void __fastcall Scaleform::Render::TreeNode::DisableBatching(Scaleform::Render::TreeNode *this, bool b)
{
  Scaleform::Render::StateBag *WritableData; // rsi
  Scaleform::Render::State *State; // rax
  volatile signed __int32 *pData; // rbx
  int v7; // [rsp+58h] [rbp+10h] BYREF
  volatile signed __int32 *v8; // [rsp+60h] [rbp+18h]
  volatile signed __int32 *v9; // [rsp+68h] [rbp+20h]

  WritableData = (Scaleform::Render::StateBag *)Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x400000u);
  State = Scaleform::Render::TreeNode::GetState(this, State_UserData);
  v8 = 0i64;
  if ( State )
  {
    pData = (volatile signed __int32 *)State->pData;
    if ( pData )
      _InterlockedExchangeAdd(pData + 2, 1u);
  }
  else
  {
    v7 = 2;
    pData = (volatile signed __int32 *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeNode *, __int64, int *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                         Scaleform::Memory::pGlobalHeap,
                                         this,
                                         40i64,
                                         &v7,
                                         -2i64);
    v9 = pData;
    if ( pData )
    {
      *(_QWORD *)pData = &Scaleform::RefCountImplCore::`vftable;
      *((_DWORD *)pData + 2) = 1;
      *(_QWORD *)pData = &Scaleform::RefCountImpl::`vftable;
      *(_QWORD *)pData = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
      *(_QWORD *)pData = &Scaleform::RefCountBase<Scaleform::Render::UserDataState::Data,2>::`vftable;
      *(_QWORD *)pData = &Scaleform::Render::UserDataState::Data::`vftable;
      _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
      *((_QWORD *)pData + 2) = (char *)&Scaleform::String::NullData.Size + 1;
      *((_DWORD *)pData + 6) = 0;
      *((_BYTE *)pData + 28) = 0;
      *((_DWORD *)pData + 8) = 0;
    }
    else
    {
      pData = 0i64;
    }
  }
  v8 = pData;
  *((_DWORD *)pData + 8) |= 4u;
  *((_BYTE *)pData + 28) = b;
  Scaleform::Render::StateBag::SetStateVoid(
    WritableData + 4,
    &Scaleform::Render::UserDataState::InterfaceImpl,
    (void *)pData);
  if ( !_InterlockedDecrement(pData + 2) )
    (**(void (__fastcall ***)(volatile signed __int32 *, __int64))v8)(v8, 1i64);
}

// File Line: 577
// RVA: 0x997490
Scaleform::Render::State *__fastcall Scaleform::Render::TreeNode::IsBatchingDisabled(Scaleform::Render::TreeNode *this)
{
  Scaleform::Render::State *result; // rax

  result = Scaleform::Render::TreeNode::GetState(this, State_UserData);
  if ( result )
    return (Scaleform::Render::State *)*(unsigned __int8 *)(result->DataValue + 28);
  return result;
}

// File Line: 593
// RVA: 0x9CB770
Scaleform::Render::TreeNodeArray::ArrayData *__fastcall Scaleform::Render::TreeNodeArray::allocByCapacity(
        Scaleform::Render::TreeNodeArray *this,
        unsigned __int64 capacity,
        unsigned __int64 size)
{
  Scaleform::Render::TreeNodeArray::ArrayData *result; // rax

  result = (Scaleform::Render::TreeNodeArray::ArrayData *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                            Scaleform::Memory::pGlobalHeap,
                                                            this,
                                                            8 * capacity + 16,
                                                            0i64);
  if ( result )
  {
    result->RefCount = 1;
    result->Size = size;
  }
  return result;
}

// File Line: 605
// RVA: 0x946BA0
void __fastcall Scaleform::Render::TreeNodeArray::TreeNodeArray(
        Scaleform::Render::TreeNodeArray *this,
        Scaleform::Render::TreeNodeArray *src)
{
  *this = *src;
  if ( ((__int64)src->pNodes[0] & 1) != 0 )
  {
    _InterlockedExchangeAdd((volatile signed __int32 *)(src->pData[0] & 0xFFFFFFFFFFFFFFFEui64), 1u);
    this->pData[1] = 0i64;
  }
}

// File Line: 618
// RVA: 0x94E6F0
void __fastcall Scaleform::Render::TreeNodeArray::operator=(
        Scaleform::Render::TreeNodeArray *this,
        Scaleform::Render::TreeNodeArray *src)
{
  unsigned __int64 v3; // rdx
  Scaleform::Render::TreeNode *v5; // rsi
  unsigned __int64 v6; // rax

  v3 = this->pData[0];
  v5 = src->pNodes[1];
  if ( ((__int64)src->pNodes[0] & 1) != 0 )
  {
    _InterlockedExchangeAdd((volatile signed __int32 *)(src->pData[0] & 0xFFFFFFFFFFFFFFFEui64), 1u);
    v5 = 0i64;
  }
  if ( (v3 & 1) != 0 && !_InterlockedDecrement((volatile signed __int32 *)(v3 & 0xFFFFFFFFFFFFFFFEui64)) )
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  v6 = src->pData[0];
  this->pData[1] = (unsigned __int64)v5;
  this->pData[0] = v6;
}

// File Line: 664
// RVA: 0x9948A0
bool __fastcall Scaleform::Render::TreeNodeArray::Insert(
        Scaleform::Render::TreeNodeArray *this,
        unsigned __int64 index,
        Scaleform::Render::TreeNode *node)
{
  unsigned __int64 v3; // rdi
  _QWORD *v7; // rax
  unsigned __int64 v8; // rcx
  _QWORD *v9; // rdi
  unsigned __int64 v10; // rdx
  unsigned __int64 v11; // r15
  __int64 v12; // r8
  __int64 v13; // rdx
  __int64 v14; // rax
  unsigned __int64 v15; // r12
  unsigned __int64 v16; // r14
  unsigned __int64 v17; // r8

  v3 = this->pData[0];
  if ( !this->pData[0] )
  {
    this->pData[0] = (unsigned __int64)node;
    LOBYTE(v7) = 1;
    return (char)v7;
  }
  if ( ((__int64)this->pNodes[0] & 1) == 0 )
  {
    if ( !this->pData[1] )
    {
      if ( !index )
        this->pData[1] = v3;
      this->pData[index] = (unsigned __int64)node;
      LOBYTE(v7) = 1;
      return (char)v7;
    }
    v7 = (_QWORD *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeNodeArray *, __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                     Scaleform::Memory::pGlobalHeap,
                     this,
                     64i64);
    v8 = (unsigned __int64)v7;
    if ( !v7 )
      return (char)v7;
    *(_DWORD *)v7 = 1;
    v7[1] = 3i64;
    if ( index )
    {
      if ( index != 1 )
      {
        if ( index == 2 )
        {
          v7[2] = this->pData[0];
          v7[3] = this->pNodes[1];
        }
        goto LABEL_16;
      }
      v7[2] = this->pData[0];
    }
    else
    {
      v7[3] = this->pData[0];
    }
    v7[4] = this->pNodes[1];
LABEL_16:
    v7[index + 2] = node;
    LOBYTE(v7) = 1;
    this->pData[0] = v8 | 1;
    this->pData[1] = 6i64;
    return (char)v7;
  }
  v9 = (_QWORD *)(v3 & 0xFFFFFFFFFFFFFFFEui64);
  v10 = v9[1];
  v11 = v10 + 1;
  if ( v10 + 1 > this->pData[1] )
  {
    v15 = (((v10 >> 1) + v10 + 1) & 0xFFFFFFFFFFFFFFFCui64) + 2;
    v7 = Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, this, 8 * v15 + 16, 0i64);
    v16 = (unsigned __int64)v7;
    if ( v7 )
    {
      *(_DWORD *)v7 = 1;
      v7[1] = v11;
      if ( index )
        memmove(v7 + 2, v9 + 2, 8 * index);
      *(_QWORD *)(v16 + 8 * index + 16) = node;
      v17 = v9[1];
      if ( index < v17 )
        memmove((void *)(v16 + 8 * (index + 3)), &v9[index + 2], 8 * (v17 - index));
      if ( !_InterlockedDecrement((volatile signed __int32 *)v9) )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v9);
      this->pData[1] = v15;
      LOBYTE(v7) = 1;
      this->pData[0] = v16 | 1;
    }
  }
  else
  {
    if ( v10 > index )
    {
      v12 = (__int64)&v9[v10 + 2];
      v13 = v10 - index;
      do
      {
        v14 = *(_QWORD *)(v12 - 8);
        v12 -= 8i64;
        *(_QWORD *)(v12 + 8) = v14;
        --v13;
      }
      while ( v13 );
    }
    v9[index + 2] = node;
    ++v9[1];
    LOBYTE(v7) = 1;
  }
  return (char)v7;
}

// File Line: 754
// RVA: 0x9A9240
bool __fastcall Scaleform::Render::TreeNodeArray::Remove(
        Scaleform::Render::TreeNodeArray *this,
        unsigned __int64 index,
        unsigned __int64 count)
{
  Scaleform::Render::TreeNode *v6; // rax
  Scaleform::Render::TreeNodeArray::ArrayData *v7; // rax
  _QWORD *v8; // rdi
  __int64 v9; // rdx
  unsigned __int64 v10; // rdx
  bool v11; // cf
  unsigned __int64 v12; // rax
  unsigned __int64 v13; // rcx
  unsigned __int64 v14; // rsi
  Scaleform::Render::TreeNodeArray::ArrayData *v15; // r15
  unsigned __int64 v16; // r8
  unsigned __int64 v17; // rbp
  _QWORD *v18; // rcx
  __int64 v19; // r8
  __int64 v20; // rax

  if ( !count )
    goto LABEL_10;
  if ( ((__int64)this->pNodes[0] & 1) == 0 )
  {
    v6 = this->pNodes[1];
    if ( !v6 )
    {
      LOBYTE(v7) = 1;
      this->pData[0] = 0i64;
      return (char)v7;
    }
    if ( count == 2 )
    {
      LOBYTE(v7) = 1;
      *this = 0ui64;
      return (char)v7;
    }
    if ( !index )
      this->pData[0] = (unsigned __int64)v6;
    this->pData[1] = 0i64;
LABEL_10:
    LOBYTE(v7) = 1;
    return (char)v7;
  }
  v8 = (_QWORD *)(this->pData[0] & 0xFFFFFFFFFFFFFFFEui64);
  v9 = v8[1];
  v11 = v9 == count;
  v10 = v9 - count;
  if ( !v11 && v10 != 1 )
  {
    v13 = this->pData[1];
    if ( v13 && (v13 >> 1 < v10 || v13 <= 0xA) )
      v14 = v13;
    else
      v14 = ((v10 + 1) & 0xFFFFFFFFFFFFFFFCui64) + 2;
    if ( v14 == v13 )
    {
      if ( index < v10 )
      {
        v17 = count;
        v18 = &v8[index + 2];
        v19 = v10 - index;
        do
        {
          v20 = v18[v17];
          *v18++ = v20;
          --v19;
        }
        while ( v19 );
      }
      v8[1] = v10;
    }
    else
    {
      v7 = Scaleform::Render::TreeNodeArray::allocByCapacity(this, v14, v10);
      v15 = v7;
      if ( !v7 )
        return (char)v7;
      if ( index )
        memmove(v7->pNodes, v8 + 2, 8 * index);
      v16 = v8[1];
      if ( index + count < v16 )
        memmove(&v15->pNodes[index], &v8[index + 2 + count], 8 * (v16 - index - count));
      if ( !_InterlockedDecrement((volatile signed __int32 *)v8) )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v8);
      this->pData[0] = (unsigned __int64)v15 | 1;
    }
    this->pData[1] = v14;
    LOBYTE(v7) = 1;
    return (char)v7;
  }
  if ( v10 == 1 )
  {
    if ( index )
      v12 = v8[2];
    else
      v12 = v8[count + 2];
    this->pData[0] = v12;
  }
  else
  {
    this->pData[0] = 0i64;
  }
  this->pData[1] = 0i64;
  if ( !_InterlockedDecrement((volatile signed __int32 *)v8) )
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v8);
  LOBYTE(v7) = 1;
  return (char)v7;
}

// File Line: 872
// RVA: 0x994810
_BOOL8 __fastcall Scaleform::Render::TreeContainer::Insert(
        Scaleform::Render::TreeContainer *this,
        unsigned __int64 index,
        Scaleform::Render::TreeNode *pnode)
{
  Scaleform::Render::TreeNodeArray *WritableData; // rax
  bool v7; // r9
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v9; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *pPrev; // rax

  WritableData = (Scaleform::Render::TreeNodeArray *)Scaleform::Render::ContextImpl::Entry::getWritableData(
                                                       this,
                                                       0x100u);
  v7 = Scaleform::Render::TreeNodeArray::Insert(WritableData + 9, index, pnode);
  if ( v7 )
  {
    ++pnode->RefCount;
    p_PNode = &this->PNode;
    pnode->pParent = this;
    if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
    {
      v9 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)
                                                                    + 0x18);
      pPrev = v9[4].pPrev;
      v9 += 4;
      p_PNode->pPrev = pPrev;
      this->PNode.pNext = v9;
      v9->pPrev->pNext = p_PNode;
      v9->pPrev = p_PNode;
    }
  }
  return v7;
}

// File Line: 890
// RVA: 0x9A9150
void __fastcall Scaleform::Render::TreeContainer::Remove(
        Scaleform::Render::TreeContainer *this,
        unsigned __int64 index,
        unsigned __int64 count)
{
  Scaleform::Render::TreeNodeArray *v6; // r14
  unsigned __int64 v7; // rax
  Scaleform::Render::ContextImpl::Entry **v8; // rbx
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // rdi
  Scaleform::Render::ContextImpl::Entry *v11; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *p_PNode; // r8
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v14; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *pPrev; // rax

  if ( count )
  {
    v6 = (Scaleform::Render::TreeNodeArray *)&Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x200u)[9];
    v7 = v6->pData[0];
    if ( v6->pData[0] || index )
    {
      if ( (v7 & 1) != 0 )
        v9 = (v7 & 0xFFFFFFFFFFFFFFFEui64) + 16;
      else
        v9 = (unsigned __int64)v6;
      v8 = (Scaleform::Render::ContextImpl::Entry **)(v9 + 8 * index);
    }
    else
    {
      v8 = 0i64;
    }
    v10 = count;
    do
    {
      --v10;
      (*v8)->pParent = 0i64;
      v11 = *v8;
      if ( (*v8)->RefCount-- == 1 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v11);
      ++v8;
    }
    while ( v10 );
    p_PNode = &this->PNode;
    if ( !this->PNode.Scaleform::Render::TreeNode::Scaleform::Render::ContextImpl::Entry::pPrev )
    {
      v14 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64)
                                                                     + 0x18);
      pPrev = v14[4].pPrev;
      v14 += 4;
      p_PNode->pPrev = pPrev;
      this->PNode.pNext = v14;
      v14->pPrev->pNext = p_PNode;
      v14->pPrev = p_PNode;
    }
    Scaleform::Render::TreeNodeArray::Remove(v6, index, count);
  }
}

// File Line: 916
// RVA: 0x9A7F50
void __fastcall Scaleform::Render::TreeContainer::NodeData::ReleaseNodes(
        Scaleform::Render::TreeContainer::NodeData *this)
{
  unsigned __int64 v1; // rbx
  __int64 v3; // rdi
  Scaleform::Render::TreeNodeArray *p_Children; // rbx
  Scaleform::Render::ContextImpl::Entry *v5; // rcx

  v1 = this->Children.pData[0];
  if ( v1 )
  {
    v3 = (v1 & 1) != 0 ? *(_QWORD *)((v1 & 0xFFFFFFFFFFFFFFFEui64) + 8) : (this->Children.pData[1] != 0) + 1i64;
    if ( v3 )
    {
      if ( (v1 & 1) != 0 )
        p_Children = (Scaleform::Render::TreeNodeArray *)((v1 & 0xFFFFFFFFFFFFFFFEui64) + 16);
      else
        p_Children = &this->Children;
      do
      {
        --v3;
        *(_QWORD *)(p_Children->pData[0] + 32) = 0i64;
        v5 = (Scaleform::Render::ContextImpl::Entry *)p_Children->pData[0];
        if ( (*(_QWORD *)(p_Children->pData[0] + 8))-- == 1i64 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper(v5);
        p_Children = (Scaleform::Render::TreeNodeArray *)((char *)p_Children + 8);
      }
      while ( v3 );
    }
  }
  if ( (this->Flags & 0x10) != 0 )
    Scaleform::Render::TreeNode::removeThisAsMaskOwner(this);
  Scaleform::Render::StateBag::ReleaseNodes(&this->States);
}

// File Line: 933
// RVA: 0x9A0950
bool __fastcall Scaleform::Render::TreeContainer::NodeData::PropagateUp(
        Scaleform::Render::TreeContainer::NodeData *this,
        Scaleform::Render::ContextImpl::Entry *entry)
{
  Scaleform::Render::TreeNodeArray *p_Children; // r10
  unsigned __int64 v5; // r11
  unsigned __int64 v6; // r9
  char v7; // bl
  float v8; // xmm6_4
  float v9; // xmm8_4
  float v10; // xmm7_4
  float x1; // xmm9_4
  __int64 v12; // rdx
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  Scaleform::Render::StateData::Interface *pInterface; // rdx
  Scaleform::Render::StateBag *p_States; // rsi
  unsigned __int64 v19; // rax
  unsigned __int64 v20; // r9
  unsigned __int64 v21; // rdx
  _QWORD *v22; // rcx
  _QWORD *pData; // rsi
  __int64 v24; // rbx
  __m128 v25; // xmm4
  __m128 v26; // xmm1
  __m128 v27; // xmm4
  __m128 v28; // xmm3
  __m128 v29; // xmm2
  __m128 v30; // xmm0
  __m128 v31; // xmm2
  __m128 v32; // xmm3
  __m128 v33; // xmm0
  __m128 v34; // xmm10
  __m128 v35; // xmm3
  __m128 v36; // xmm10
  float y1; // xmm11_4
  float x2; // xmm12_4
  float y2; // xmm13_4
  Scaleform::Render::ContextImpl::EntryData *WritableData; // rax
  __int16 v41; // ax
  Scaleform::Render::ContextImpl::EntryData *v42; // rbx
  Scaleform::Render::Rect<float> bounds; // [rsp+18h] [rbp-59h] BYREF
  Scaleform::Render::Rect<float> pr; // [rsp+28h] [rbp-49h] BYREF
  Scaleform::Render::Rect<float> v46; // [rsp+38h] [rbp-39h] BYREF

  p_Children = (Scaleform::Render::TreeNodeArray *)this->Children.pNodes[0];
  if ( p_Children )
  {
    if ( ((__int64)this->Children.pNodes[0] & 1) != 0 )
      v5 = *(_QWORD *)(((unsigned __int64)p_Children & 0xFFFFFFFFFFFFFFFEui64) + 8);
    else
      v5 = (this->Children.pData[1] != 0) + 1i64;
  }
  else
  {
    v5 = 0i64;
  }
  if ( p_Children )
  {
    if ( ((__int64)this->Children.pNodes[0] & 1) != 0 )
      p_Children = (Scaleform::Render::TreeNodeArray *)(((unsigned __int64)p_Children & 0xFFFFFFFFFFFFFFFEui64) + 16);
    else
      p_Children = &this->Children;
  }
  v6 = 0i64;
  v7 = 1;
  bounds = 0i64;
  v8 = 0.0;
  v9 = 0.0;
  v10 = 0.0;
  x1 = 0.0;
  v46 = 0i64;
  pr = 0i64;
  if ( !v5 )
    goto LABEL_44;
  do
  {
    v12 = *(_QWORD *)(*(_QWORD *)((p_Children->pData[v6] & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                    + 8i64
                    * (unsigned int)((int)(LODWORD(p_Children->pNodes[v6])
                                         - ((__int64)p_Children->pNodes[v6] & 0xFFFFF000)
                                         - 56)
                                   / 56)
                    + 40);
    if ( (*(_BYTE *)(v12 + 10) & 1) != 0 )
    {
      v13 = *(float *)(v12 + 128);
      v14 = *(float *)(v12 + 136);
      if ( v13 < v14 )
      {
        v15 = *(float *)(v12 + 132);
        v16 = *(float *)(v12 + 140);
        if ( v15 < v16 )
        {
          if ( v7 )
          {
            x1 = *(float *)(v12 + 128);
            v10 = *(float *)(v12 + 132);
            v9 = *(float *)(v12 + 136);
            v7 = 0;
            bounds.x1 = x1;
            bounds.y1 = v15;
            bounds.x2 = v14;
LABEL_23:
            v8 = v16;
            bounds.y2 = v16;
            goto LABEL_24;
          }
          if ( x1 > v13 )
          {
            x1 = *(float *)(v12 + 128);
            bounds.x1 = x1;
          }
          if ( v9 <= v14 )
          {
            v9 = v14;
            bounds.x2 = v14;
          }
          if ( v10 > v15 )
          {
            v10 = v15;
            bounds.y1 = v15;
          }
          if ( v8 <= v16 )
            goto LABEL_23;
        }
      }
    }
LABEL_24:
    ++v6;
  }
  while ( v6 < v5 );
  if ( v7 )
  {
LABEL_44:
    y2 = pr.y2;
    x2 = pr.x2;
    y1 = pr.y1;
    v36.m128_i32[0] = LODWORD(pr.x1);
    goto LABEL_45;
  }
  pInterface = this->States.pInterface;
  p_States = &this->States;
  v46.x1 = x1;
  v46.y1 = v10;
  v46.x2 = v9;
  v46.y2 = v8;
  if ( pInterface )
  {
    if ( ((unsigned __int8)pInterface & 1) != 0 )
    {
      if ( ((unsigned __int64)pInterface & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A58 )
        goto LABEL_36;
    }
    else
    {
      v19 = 0i64;
      v20 = this->States.DataValue + 4;
      v21 = (unsigned __int64)pInterface >> 1;
      if ( v21 )
      {
        v22 = (_QWORD *)(this->States.DataValue + 4);
        while ( *v22 != qword_142451A58 )
        {
          ++v19;
          v22 += 2;
          if ( v19 >= v21 )
            goto LABEL_41;
        }
        p_States = (Scaleform::Render::StateBag *)(16 * v19 + v20);
LABEL_36:
        if ( p_States )
        {
          pData = p_States->pData;
          if ( pData )
          {
            v24 = 0i64;
            if ( *((_DWORD *)pData + 6) )
            {
              do
              {
                Scaleform::Render::TreeNode::NodeData::expandByFilterBounds(
                  *(Scaleform::Render::Filter **)(pData[2] + 8 * v24),
                  &bounds);
                v24 = (unsigned int)(v24 + 1);
              }
              while ( (unsigned int)v24 < *((_DWORD *)pData + 6) );
              v8 = bounds.y2;
              v9 = bounds.x2;
              v10 = bounds.y1;
              x1 = bounds.x1;
            }
          }
        }
      }
    }
  }
LABEL_41:
  if ( (this->Flags & 0x200) != 0 )
  {
    Scaleform::Render::Matrix3x4<float>::EncloseTransform(&this->M34, &pr, &bounds);
    goto LABEL_44;
  }
  v25 = *(__m128 *)&this->M34.M[0][0];
  v26 = _mm_unpacklo_ps(v25, *(__m128 *)&this->M34.M[1][0]);
  v27 = _mm_shuffle_ps(v25, *(__m128 *)&this->M34.M[1][0], 255);
  v28 = _mm_mul_ps(_mm_unpackhi_ps((__m128)bounds, (__m128)bounds), v26);
  v29 = _mm_mul_ps(_mm_unpacklo_ps((__m128)bounds, (__m128)bounds), v26);
  v30 = _mm_unpacklo_ps(v29, v28);
  v31 = _mm_unpackhi_ps(v29, v28);
  v32 = _mm_add_ps(v31, v30);
  v33 = _mm_add_ps(_mm_shuffle_ps(v30, v30, 177), v31);
  v34 = _mm_min_ps(v32, v33);
  v35 = _mm_max_ps(v32, v33);
  v36 = _mm_add_ps(
          _mm_shuffle_ps(
            _mm_min_ps(v34, _mm_shuffle_ps(v34, v34, 177)),
            _mm_max_ps(v35, _mm_shuffle_ps(v35, v35, 177)),
            136),
          _mm_shuffle_ps(v27, v27, 136));
  LODWORD(y1) = _mm_shuffle_ps(v36, v36, 85).m128_u32[0];
  LODWORD(x2) = _mm_shuffle_ps(v36, v36, 170).m128_u32[0];
  LODWORD(y2) = _mm_shuffle_ps(v36, v36, 255).m128_u32[0];
LABEL_45:
  if ( x1 == this->AproxLocalBounds.x1
    && v9 == this->AproxLocalBounds.x2
    && v10 == this->AproxLocalBounds.y1
    && v8 == this->AproxLocalBounds.y2
    && v36.m128_f32[0] == this->AproxParentBounds.x1
    && x2 == this->AproxParentBounds.x2
    && y1 == this->AproxParentBounds.y1
    && y2 == this->AproxParentBounds.y2 )
  {
    if ( entry->pPrev )
    {
      WritableData = Scaleform::Render::ContextImpl::Entry::getWritableData(entry, 0);
      if ( ((__int64)WritableData[9].vfptr & 1) != 0 )
        *(_QWORD *)&WritableData[9].Type = 0i64;
    }
    LOBYTE(v41) = 0;
  }
  else
  {
    v42 = Scaleform::Render::ContextImpl::Entry::getWritableData(entry, 9u);
    *(float *)&v42[7].vfptr = x1;
    *((float *)&v42[7].vfptr + 1) = v10;
    *(float *)&v42[7].Type = v9;
    *(float *)(&v42[7].Flags + 1) = v8;
    LODWORD(v42[8].vfptr) = v36.m128_i32[0];
    *((float *)&v42[8].vfptr + 1) = y1;
    *(float *)&v42[8].Type = x2;
    *(float *)(&v42[8].Flags + 1) = y2;
    Scaleform::Render::TreeNode::NodeData::updateOriginalBoundState((Scaleform::Render::TreeNode::NodeData *)v42, &v46);
    if ( entry->pPrev && ((__int64)v42[9].vfptr & 1) != 0 )
      *(_QWORD *)&v42[9].Type = 0i64;
    return this->Flags & 1;
  }
  return v41;
}

// File Line: 1061
// RVA: 0x9F8CA0
Scaleform::Render::TreeCacheNode *__fastcall Scaleform::Render::TreeContainer::NodeData::updateCache(
        Scaleform::Render::TreeContainer::NodeData *this,
        Scaleform::Render::TreeCacheNode *pparent,
        Scaleform::Render::TreeCacheNode *pinsert,
        Scaleform::Render::TreeNode *pnode,
        unsigned __int16 depth)
{
  Scaleform::Render::TreeCacheNode *pRenderer; // rbx
  int v10; // eax
  int v11; // ecx
  unsigned __int16 Flags; // dx
  unsigned __int16 v13; // bx
  Scaleform::Render::TreeCacheContainer *v14; // rax
  Scaleform::Render::TreeCacheNode *v15; // rax
  int v17; // [rsp+78h] [rbp+20h] BYREF

  pRenderer = pnode->pRenderer;
  if ( pRenderer )
    goto LABEL_17;
  if ( pparent )
  {
    v10 = pparent->Flags & 0xC;
    if ( v10 == 12 )
    {
      LOWORD(v11) = 12;
      goto LABEL_8;
    }
  }
  else
  {
    LOWORD(v10) = 4;
  }
  v11 = this->Flags & 0xC;
  if ( !v11 )
    LOWORD(v11) = v10;
LABEL_8:
  Flags = this->Flags;
  v13 = v11 | Flags & 1;
  if ( (Flags & 0x20) != 0 )
    v13 |= 0x60u;
  if ( (Flags & 0x200) != 0 )
    v13 |= 0x200u;
  v17 = 71;
  v14 = (Scaleform::Render::TreeCacheContainer *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   pparent,
                                                   160i64,
                                                   &v17);
  if ( v14 )
  {
    Scaleform::Render::TreeCacheContainer::TreeCacheContainer(v14, pnode, pparent->pRenderer2D, v13);
    pRenderer = v15;
  }
  else
  {
    pRenderer = 0i64;
  }
  pnode->pRenderer = pRenderer;
  if ( !pRenderer )
    return 0i64;
LABEL_17:
  Scaleform::Render::TreeCacheNode::UpdateInsertIntoParent(pRenderer, pparent, pinsert, this, depth);
  return pRenderer;
}

// File Line: 1090
// RVA: 0x960D50
Scaleform::Render::TreeNode *__fastcall Scaleform::Render::TreeContainer::NodeData::CloneCreate(
        Scaleform::Render::TreeContainer::NodeData *this,
        Scaleform::Render::ContextImpl::Context *context)
{
  Scaleform::Render::TreeNode::NodeData *v4; // rax
  Scaleform::Render::TreeNode::NodeData *v5; // rbx
  Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeNode::NodeData> src; // [rsp+50h] [rbp+8h] BYREF
  Scaleform::Render::TreeNode::NodeData *v8; // [rsp+58h] [rbp+10h]
  Scaleform::Render::TreeNode::NodeData *v9; // [rsp+60h] [rbp+18h]

  v4 = (Scaleform::Render::TreeNode::NodeData *)context->pHeap->vfptr->Alloc(context->pHeap, 160i64, 0i64);
  v5 = v4;
  v8 = v4;
  v9 = v4;
  if ( v4 )
  {
    src.pC = this;
    Scaleform::Render::TreeNode::NodeData::NodeData(
      v4,
      (Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeNode::NodeData>)&src);
    v5->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeContainer::NodeData,Scaleform::Render::TreeNode::NodeData>::`vftable;
    v5->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::TreeContainer::NodeData::`vftable;
    *(_QWORD *)&v5[1].Type = 0i64;
    v5[1].vfptr = 0i64;
  }
  return (Scaleform::Render::TreeNode *)Scaleform::Render::ContextImpl::Context::createEntryHelper(context, v5);
}

// File Line: 1095
// RVA: 0x960EA0
bool __fastcall Scaleform::Render::TreeContainer::NodeData::CloneInit(
        Scaleform::Render::TreeContainer::NodeData *this,
        Scaleform::Render::TreeContainer *node,
        Scaleform::Render::ContextImpl::Context *context)
{
  bool result; // al
  Scaleform::Render::TreeNodeArray *p_Children; // rsi
  unsigned __int64 v8; // rdi
  unsigned __int64 v9; // rbp
  unsigned __int64 v10; // rcx
  __int64 v11; // r14
  Scaleform::Render::TreeNode *v12; // rbx

  result = Scaleform::Render::TreeNode::NodeData::CloneInit(this, node, context);
  if ( result )
  {
    p_Children = &this->Children;
    v8 = 0i64;
    if ( p_Children->pData[0] )
    {
      if ( ((__int64)p_Children->pNodes[0] & 1) != 0 )
        v9 = *(_QWORD *)((p_Children->pData[0] & 0xFFFFFFFFFFFFFFFEui64) + 8);
      else
        v9 = (p_Children->pData[1] != 0) + 1i64;
    }
    else
    {
      v9 = 0i64;
    }
    if ( v9 )
    {
      do
      {
        if ( ((__int64)p_Children->pNodes[0] & 1) != 0 )
          v10 = (p_Children->pData[0] & 0xFFFFFFFFFFFFFFFEui64) + 16;
        else
          v10 = (unsigned __int64)p_Children;
        v11 = *(_QWORD *)(*(_QWORD *)((*(_QWORD *)(v10 + 8 * v8) & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                        + 8i64
                        * (unsigned int)((int)(*(_QWORD *)(v10 + 8 * v8) - (*(_QWORD *)(v10 + 8 * v8) & 0xFFFFF000) - 56)
                                       / 56)
                        + 40);
        v12 = (Scaleform::Render::TreeNode *)(*(__int64 (__fastcall **)(__int64, Scaleform::Render::ContextImpl::Context *))(*(_QWORD *)v11 + 64i64))(
                                               v11,
                                               context);
        if ( v12 )
          (*(void (__fastcall **)(__int64, Scaleform::Render::TreeNode *, Scaleform::Render::ContextImpl::Context *))(*(_QWORD *)v11 + 72i64))(
            v11,
            v12,
            context);
        Scaleform::Render::TreeContainer::Add(node, v12);
        if ( v12 )
        {
          if ( v12->RefCount-- == 1 )
            Scaleform::Render::ContextImpl::Entry::destroyHelper(v12);
        }
        ++v8;
      }
      while ( v8 < v9 );
    }
    return 1;
  }
  return result;
}

// File Line: 1117
// RVA: 0x9B5C80
void __fastcall Scaleform::Render::TreeRoot::SetViewport(
        Scaleform::Render::TreeRoot *this,
        Scaleform::Render::Viewport *vp)
{
  Scaleform::Render::Viewport *WritableData; // rax

  if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 160i64) != vp->BufferWidth
    || *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 164i64) != vp->BufferHeight
    || *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 168i64) != vp->Left
    || *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 172i64) != vp->Top
    || *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 176i64) != vp->Width
    || *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 180i64) != vp->Height
    || *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 184i64) != vp->ScissorLeft
    || *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 188i64) != vp->ScissorTop
    || *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 192i64) != vp->ScissorWidth
    || *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 196i64) != vp->ScissorHeight
    || *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 200i64) != vp->Flags )
  {
    WritableData = (Scaleform::Render::Viewport *)Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x1000u);
    WritableData[3].ScissorTop = vp->BufferWidth;
    WritableData[3].ScissorWidth = vp->BufferHeight;
    WritableData[3].ScissorHeight = vp->Left;
    WritableData[3].Flags = vp->Top;
    WritableData[4].BufferWidth = vp->Width;
    WritableData[4].BufferHeight = vp->Height;
    WritableData[4].Left = vp->ScissorLeft;
    WritableData[4].Top = vp->ScissorTop;
    WritableData[4].Width = vp->ScissorWidth;
    WritableData[4].Height = vp->ScissorHeight;
    WritableData[4].ScissorLeft = vp->Flags;
  }
}

