// File Line: 29
// RVA: 0x9A8020
void __fastcall Scaleform::Render::TreeNode::NodeData::ReleaseNodes(Scaleform::Render::TreeNode::NodeData *this)
{
  Scaleform::Render::TreeNode::NodeData *v1; // rbx

  v1 = this;
  if ( (LOBYTE(this->Flags) >> 4) & 1 )
    Scaleform::Render::TreeNode::removeThisAsMaskOwner(this);
  Scaleform::Render::StateBag::ReleaseNodes(&v1->States);
}

// File Line: 62
// RVA: 0x9E2AA0
void __fastcall Scaleform::Render::TreeNode::NodeData::expandByFilterBounds(Scaleform::Render::Filter *filter, Scaleform::Render::Rect<float> *bounds)
{
  Scaleform::Render::FilterType v2; // eax
  float v3; // xmm3_4
  float v4; // xmm2_4
  float v5; // xmm6_4
  float v6; // xmm7_4
  float v7; // xmm8_4
  float v8; // xmm7_4
  float v9; // xmm5_4
  float v10; // xmm6_4
  Scaleform::Render::FilterType v11; // eax
  __m128 v12; // xmm2
  __m128 v13; // xmm1
  bool v14; // cf
  bool v15; // zf
  __m128 v16; // xmm2
  signed int v17; // ecx
  __m128 v18; // xmm1
  signed int v19; // ecx

  if ( filter )
  {
    v2 = filter->Type;
    if ( (unsigned int)v2 <= 5 )
    {
      if ( (v2 - 3) & 0xFFFFFFFD )
        v3 = *(float *)&FLOAT_1_0;
      else
        v3 = FLOAT_2_0;
      v4 = (float)SHIDWORD(filter[1].vfptr);
      v5 = (float)((float)((float)((float)(*((float *)&filter[1].RefCount + 1) * 0.050000001) + 1.0) * 20.0) * v4) * v3;
      v6 = (float)((float)((float)((float)(*(float *)&filter[1].RefCount * 0.050000001) + 1.0) * 20.0) * v4) * v3;
      v7 = bounds->x1 - v6;
      v8 = v6 + bounds->x2;
      v9 = bounds->y1 - v5;
      v10 = v5 + bounds->y2;
      bounds->x2 = v8;
      bounds->x1 = v7;
      bounds->y2 = v10;
      bounds->y1 = v9;
      v11 = filter->Type;
      if ( v11 == 1 || (unsigned int)(v11 - 3) <= 2 )
      {
        v12 = (__m128)(unsigned int)filter[1].Type;
        v13 = (__m128)*(unsigned int *)&filter[1].Frozen;
        v14 = v12.m128_f32[0] < 0.0;
        v15 = v12.m128_f32[0] == 0.0;
        v16 = _mm_and_ps(v12, (__m128)(unsigned int)_xmm);
        v16.m128_f32[0] = v16.m128_f32[0] * v3;
        v17 = (signed int)v16.m128_f32[0];
        if ( v14 || v15 )
        {
          if ( v17 != 0x80000000 && (float)v17 != v16.m128_f32[0] )
            v16.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v16, v16)) & 1 ^ 1) + v17);
          bounds->x2 = v8;
          bounds->x1 = v7 - v16.m128_f32[0];
        }
        else
        {
          if ( v17 != 0x80000000 && (float)v17 != v16.m128_f32[0] )
            v16.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v16, v16)) & 1 ^ 1) + v17);
          bounds->x2 = v16.m128_f32[0] + v8;
        }
        v14 = v13.m128_f32[0] < 0.0;
        v15 = v13.m128_f32[0] == 0.0;
        v18 = _mm_and_ps(v13, (__m128)(unsigned int)_xmm);
        v18.m128_f32[0] = v18.m128_f32[0] * v3;
        v19 = (signed int)v18.m128_f32[0];
        if ( v14 || v15 )
        {
          if ( v19 != 0x80000000 && (float)v19 != v18.m128_f32[0] )
            v18.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v18, v18)) & 1 ^ 1) + v19);
          bounds->y2 = v10;
          bounds->y1 = v9 - v18.m128_f32[0];
        }
        else
        {
          bounds->y1 = v9;
          if ( v19 != 0x80000000 && (float)v19 != v18.m128_f32[0] )
            v18.m128_f32[0] = (float)((_mm_movemask_ps(_mm_unpacklo_ps(v18, v18)) & 1 ^ 1) + v19);
          bounds->y2 = v18.m128_f32[0] + v10;
        }
      }
      Scaleform::Render::SnapRectToPixels(bounds, 0.5);
    }
  }
}

// File Line: 105
// RVA: 0x9FA4B0
void __fastcall Scaleform::Render::TreeNode::NodeData::updateOriginalBoundState(Scaleform::Render::TreeNode::NodeData *this, Scaleform::Render::Rect<float> *bounds)
{
  Scaleform::Render::Rect<float> *v2; // rsi
  Scaleform::Render::TreeNode::NodeData *v3; // rdi
  __int64 v4; // rax
  void (__fastcall ***v5)(_QWORD, _QWORD); // rbx
  int v6; // [rsp+58h] [rbp+10h]
  __int64 v7; // [rsp+60h] [rbp+18h]
  void (__fastcall ***v8)(_QWORD, _QWORD); // [rsp+68h] [rbp+20h]

  v2 = bounds;
  v3 = this;
  if ( bounds->x1 != this->AproxLocalBounds.x1
    || bounds->x2 != this->AproxLocalBounds.x2
    || bounds->y1 != this->AproxLocalBounds.y1
    || bounds->y2 != this->AproxLocalBounds.y2 )
  {
    v6 = 2;
    v4 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeNode::NodeData *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
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
    *((_DWORD *)v5 + 4) = LODWORD(v2->x1);
    *((_DWORD *)v5 + 5) = LODWORD(v2->y1);
    *((_DWORD *)v5 + 6) = LODWORD(v2->x2);
    *((_DWORD *)v5 + 7) = LODWORD(v2->y2);
    Scaleform::Render::StateBag::SetStateVoid(
      &v3->States,
      (Scaleform::Render::StateData::Interface *)&Scaleform::Render::OrigNodeBoundsState::InterfaceImpl.vfptr,
      v5);
    if ( !_InterlockedDecrement((volatile signed __int32 *)v5 + 2) )
      (**v5)(v5, 1i64);
  }
  else if ( Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::OrigNodeBoundsState>(this) )
  {
    Scaleform::Render::StateBag::RemoveState(&v3->States, State_OrigNodeBounds);
  }
}

// File Line: 122
// RVA: 0x9649B0
void __fastcall Scaleform::Render::TreeNode::NodeData::CopyGeomData(Scaleform::Render::TreeNode::NodeData *this, Scaleform::Render::TreeNode *destNode, Scaleform::Render::TreeNode *srcNode)
{
  Scaleform::Render::TreeNode *v3; // rsi
  Scaleform::Render::TreeNode::NodeData *v4; // rbx
  signed __int64 v5; // r9
  Scaleform::Render::TreeNode *v6; // r14
  __int64 v7; // r8
  unsigned __int64 v8; // rdx
  __int64 v9; // rdi
  Scaleform::Render::ContextImpl::Entry *v10; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v11; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v12; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v13; // rax
  __int16 v14; // ax
  Scaleform::Render::State *v15; // rax
  Scaleform::Render::BlendMode v16; // edx
  Scaleform::Render::State *v17; // rax
  _DWORD *v18; // rax
  unsigned int v19; // xmm1_4
  Scaleform::Render::Rect<float> v20; // [rsp+20h] [rbp-60h]
  Scaleform::Render::Rect<float> rect; // [rsp+30h] [rbp-50h]
  int Dst; // [rsp+40h] [rbp-40h]
  int v23; // [rsp+54h] [rbp-2Ch]
  int v24; // [rsp+68h] [rbp-18h]
  int v25; // [rsp+7Ch] [rbp-4h]

  if ( destNode != srcNode )
  {
    v3 = destNode;
    v4 = this;
    v5 = (signed __int64)srcNode - ((unsigned __int64)srcNode & 0xFFFFFFFFFFFFF000ui64);
    v6 = srcNode;
    v7 = *(_QWORD *)(((unsigned __int64)srcNode & 0xFFFFFFFFFFFFF000ui64) + 0x20);
    v5 -= 56i64;
    v8 = ((unsigned __int64)((unsigned __int128)(v5 * (signed __int128)5270498306774157605i64) >> 64) >> 63)
       + ((signed __int64)((unsigned __int128)(v5 * (signed __int128)5270498306774157605i64) >> 64) >> 4);
    v9 = *(_QWORD *)(v7 + 8i64 * (unsigned int)v8 + 40);
    if ( (LOBYTE(this->Flags) ^ *(_BYTE *)(*(_QWORD *)(v7
                                                     + 8
                                                     * (((unsigned __int64)((unsigned __int128)(v5
                                                                                              * (signed __int128)5270498306774157605i64) >> 64) >> 63)
                                                      + (unsigned int)((signed __int64)((unsigned __int128)(v5 * (signed __int128)5270498306774157605i64) >> 64) >> 4))
                                                     + 40)
                                         + 10i64)) & 1 )
    {
      Scaleform::Render::TreeNode::SetVisible(
        v3,
        *(_BYTE *)(*(_QWORD *)(v7 + 8i64 * (unsigned int)v8 + 40) + 10i64) & 1);
      v10 = v3->pParent;
      if ( v10 )
      {
        v11 = &v10->PNode;
        if ( !v10->PNode.pPrev )
        {
          v12 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(((unsigned __int64)v10 & 0xFFFFFFFFFFFFF000ui64)
                                                                         + 0x18);
          v13 = v12[4].pPrev;
          v12 += 4;
          v11->pPrev = v13;
          v11->pNext = v12;
          v12->pPrev->pNext = v11;
          v12->pPrev = v11;
        }
      }
    }
    v14 = *(_WORD *)(v9 + 10) >> 9;
    v4->M34.M[0][0] = *(float *)(v9 + 16);
    v4->M34.M[0][1] = *(float *)(v9 + 20);
    v4->M34.M[0][2] = *(float *)(v9 + 24);
    v4->M34.M[0][3] = *(float *)(v9 + 28);
    v4->M34.M[1][0] = *(float *)(v9 + 32);
    v4->M34.M[1][1] = *(float *)(v9 + 36);
    v4->M34.M[1][2] = *(float *)(v9 + 40);
    v4->M34.M[1][3] = *(float *)(v9 + 44);
    if ( v14 & 1 )
    {
      v4->M34.M[2][0] = *(float *)(v9 + 48);
      v4->M34.M[2][1] = *(float *)(v9 + 52);
      v4->M34.M[2][2] = *(float *)(v9 + 56);
      v4->M34.M[2][3] = *(float *)(v9 + 60);
      v4->Flags |= 0x200u;
      memset(&Dst, 0, 0x40ui64);
      Dst = 1065353216;
      v23 = 1065353216;
      v24 = 1065353216;
      v25 = 1065353216;
      if ( Scaleform::Render::TreeNode::GetProjectionMatrix3D(v6, (Scaleform::Render::Matrix4x4<float> *)&Dst) )
        Scaleform::Render::TreeNode::SetProjectionMatrix3D(v3, (Scaleform::Render::Matrix4x4<float> *)&Dst);
      memset(&Dst, 0, 0x30ui64);
      Dst = 1065353216;
      v23 = 1065353216;
      v24 = 1065353216;
      if ( Scaleform::Render::TreeNode::GetViewMatrix3D(v6, (Scaleform::Render::Matrix3x4<float> *)&Dst) )
        Scaleform::Render::TreeNode::SetViewMatrix3D(v3, (Scaleform::Render::Matrix3x4<float> *)&Dst);
    }
    *(_OWORD *)&v4->Cx.M[0][0] = *(_OWORD *)(v9 + 80);
    *(_OWORD *)&v4->Cx.M[1][0] = *(_OWORD *)(v9 + 96);
    v15 = Scaleform::Render::TreeNode::GetState(v6, State_BlendMode);
    if ( v15 )
      v16 = (Scaleform::Render::BlendMode)v15->pData;
    else
      v16 = 0;
    Scaleform::Render::TreeNode::SetBlendMode(v3, v16);
    v17 = Scaleform::Render::TreeNode::GetState(v6, State_Scale9);
    if ( v17 )
    {
      v18 = v17->pData;
      v19 = v18[5];
      v20.x1 = (float)v18[4];
      *(_QWORD *)&v20.y1 = __PAIR__(v18[6], v19);
      v20.y2 = (float)v18[7];
    }
    else
    {
      v20 = 0i64;
    }
    rect = v20;
    if ( v20.x1 < v20.x2 && v20.y1 < v20.y2 )
      Scaleform::Render::TreeNode::SetScale9Grid(v3, &rect);
  }
}

// File Line: 175
// RVA: 0x960FE0
char __fastcall Scaleform::Render::TreeNode::NodeData::CloneInit(Scaleform::Render::TreeNode::NodeData *this, Scaleform::Render::TreeNode *node, Scaleform::Render::ContextImpl::Context *context)
{
  Scaleform::Render::ContextImpl::Context *v3; // r13
  Scaleform::Render::TreeNode *v4; // r12
  Scaleform::Render::TreeNode::NodeData *v5; // rbx
  signed __int64 v6; // r9
  Scaleform::Render::StateBag *v7; // r15
  unsigned __int64 *v8; // rbx
  signed __int64 v9; // rsi
  char v10; // r14
  signed __int64 v11; // rdi
  __int64 v12; // rbp
  signed __int64 v13; // r8
  unsigned __int64 v14; // rdx
  int v15; // eax
  unsigned __int64 v16; // rdx
  unsigned __int64 v17; // rax
  unsigned __int64 v18; // rdx
  _QWORD *v19; // rcx
  unsigned __int64 v20; // r8
  __int64 v21; // rdi
  __int64 v22; // rax
  Scaleform::Render::TreeNode *v23; // rbx
  bool v24; // zf

  v3 = context;
  v4 = node;
  v5 = this;
  v7 = (Scaleform::Render::StateBag *)Scaleform::Render::ContextImpl::Entry::getWritableData(
                                        (Scaleform::Render::ContextImpl::Entry *)&node->0,
                                        0xFF0000u);
  v8 = (unsigned __int64 *)&v5->States;
  if ( *(_BYTE *)v8 & 1 )
    v9 = 1i64;
  else
    v9 = *v8 >> 1;
  v10 = 0;
  if ( v9 )
  {
    v11 = 0i64;
    v12 = 0i64;
    do
    {
      if ( *(_BYTE *)v8 & 1 )
        v13 = (signed __int64)v8;
      else
        v13 = v12 + v8[1] + 4;
      v14 = *(_QWORD *)v13 & 0xFFFFFFFFFFFFFFFEui64;
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
          v7 + 4,
          (Scaleform::Render::StateData::Interface *)v14,
          *(void **)(v13 + 8));
      }
      v12 += 16i64;
      --v9;
    }
    while ( v9 );
    if ( v10 )
    {
      v16 = *v8;
      if ( *v8 )
      {
        if ( v16 & 1 )
        {
          if ( (v16 & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A60 )
            v11 = (signed __int64)v8;
        }
        else
        {
          v6 = v8[1] + 4;
          v17 = 0i64;
          v18 = v16 >> 1;
          if ( v18 )
          {
            v19 = (_QWORD *)(v8[1] + 4);
            while ( *v19 != qword_142451A60 )
            {
              ++v17;
              v19 += 2;
              if ( v17 >= v18 )
                goto LABEL_29;
            }
            v11 = v6 + 16 * v17;
          }
        }
      }
LABEL_29:
      v20 = *(_QWORD *)(v11 + 8) & 0xFFFFFFFFFFFFF000ui64;
      v21 = *(_QWORD *)(*(_QWORD *)(v20 + 0x20)
                      + 8
                      * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)(*(_QWORD *)(v11 + 8)
                                                                                            - v20
                                                                                            - 56)
                                                                           * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                       + ((unsigned __int64)((unsigned __int128)((signed __int64)(*(_QWORD *)(v11 + 8) - v20 - 56)
                                                               * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                      + 40);
      v22 = (*(__int64 (__fastcall **)(__int64, Scaleform::Render::ContextImpl::Context *, unsigned __int64, signed __int64, signed __int64))(*(_QWORD *)v21 + 64i64))(
              v21,
              v3,
              v20,
              v6,
              -2i64);
      v23 = (Scaleform::Render::TreeNode *)v22;
      if ( v22 )
        (*(void (__fastcall **)(__int64, __int64, Scaleform::Render::ContextImpl::Context *))(*(_QWORD *)v21 + 72i64))(
          v21,
          v22,
          v3);
      Scaleform::Render::TreeNode::SetMaskNode(v4, v23);
      if ( v23 )
      {
        v24 = v23->RefCount-- == 1;
        if ( v24 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)&v23->0);
      }
    }
  }
  return 1;
}

// File Line: 214
// RVA: 0x960CD0
Scaleform::Render::TreeNode *__fastcall Scaleform::Render::TreeNode::Clone(Scaleform::Render::TreeNode *this, Scaleform::Render::ContextImpl::Context *context)
{
  Scaleform::Render::ContextImpl::Context *v2; // rsi
  __int64 v3; // rdi
  Scaleform::Render::TreeNode *result; // rax
  Scaleform::Render::TreeNode *v5; // rbx

  v2 = context;
  v3 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8
                 * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                       - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                  + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                           - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 63))
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
      v2);
    result = v5;
  }
  return result;
}

// File Line: 226
// RVA: 0x95F0A0
void __fastcall Scaleform::Render::TreeNode::Clear3D(Scaleform::Render::TreeNode *this)
{
  Scaleform::Render::TreeNode *v1; // r9
  unsigned __int64 v2; // rcx
  unsigned int v3; // er8
  unsigned __int64 v4; // rdx
  Scaleform::Render::ContextImpl::EntryData *v5; // rax

  v1 = this;
  v2 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v3 = 1;
  v4 = (signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v1[-1] - v2)
                                          * (signed __int128)5270498306774157605i64) >> 64) >> 4;
  if ( (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(v2 + 32) + 8 * ((unsigned int)v4 + (v4 >> 63)) + 40) + 10i64) >> 9) & 1 )
    v3 = 8193;
  v5 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&v1->0, v3);
  *(float *)&v5[1].vfptr = Scaleform::Render::Matrix3x4<float>::Identity.M[0][0];
  *(Scaleform::Render::ContextImpl::EntryDataVtbl **)((char *)&v5[1].vfptr + 4) = *(Scaleform::Render::ContextImpl::EntryDataVtbl **)&Scaleform::Render::Matrix3x4<float>::Identity.M[0][1];
  *(float *)(&v5[1].Flags + 1) = Scaleform::Render::Matrix3x4<float>::Identity.M[0][3];
  v5[2] = *(Scaleform::Render::ContextImpl::EntryData *)&Scaleform::Render::Matrix3x4<float>::Identity.M[1][0];
  v5[3] = *(Scaleform::Render::ContextImpl::EntryData *)&Scaleform::Render::Matrix3x4<float>::Identity.M[2][0];
  v5->Flags &= 0xFDFFu;
}

// File Line: 238
// RVA: 0x9B1BF0
void __fastcall Scaleform::Render::TreeNode::SetMatrix(Scaleform::Render::TreeNode *this, Scaleform::Render::Matrix2x4<float> *m)
{
  Scaleform::Render::Matrix2x4<float> *v2; // rbx
  Scaleform::Render::TreeNode *v3; // rdi
  Scaleform::Render::ContextImpl::EntryData *v4; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v5; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v6; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v7; // rax

  v2 = m;
  v3 = this;
  v4 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&this->0, 1u);
  v5 = &v3->PNode;
  *(float *)&v4[1].vfptr = v2->M[0][0];
  HIDWORD(v4[1].vfptr) = LODWORD(v2->M[0][1]);
  *(float *)&v4[1].Type = v2->M[0][2];
  *(float *)(&v4[1].Flags + 1) = v2->M[0][3];
  *(float *)&v4[2].vfptr = v2->M[1][0];
  HIDWORD(v4[2].vfptr) = LODWORD(v2->M[1][1]);
  *(float *)&v4[2].Type = v2->M[1][2];
  *(float *)(&v4[2].Flags + 1) = v2->M[1][3];
  if ( !v3->PNode.pPrev )
  {
    v6 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(((unsigned __int64)v3 & 0xFFFFFFFFFFFFF000ui64)
                                                                  + 0x18);
    v7 = v6[4].pPrev;
    v6 += 4;
    v5->pPrev = v7;
    v3->PNode.pNext = v6;
    v6->pPrev->pNext = v5;
    v6->pPrev = v5;
  }
}

// File Line: 249
// RVA: 0x9B1990
void __fastcall Scaleform::Render::TreeNode::SetMatrix3D(Scaleform::Render::TreeNode *this, Scaleform::Render::Matrix3x4<float> *m)
{
  Scaleform::Render::Matrix3x4<float> *v2; // rbx
  Scaleform::Render::TreeNode *v3; // rsi
  unsigned __int64 v4; // rbp
  unsigned int v5; // edi
  Scaleform::Render::ContextImpl::EntryData *v6; // rax
  Scaleform::Render::ContextImpl::Entry *v7; // rbx
  Scaleform::Render::ContextImpl::EntryData *v8; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v9; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v10; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v11; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v12; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v13; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v14; // rax

  v2 = m;
  v3 = this;
  v4 = (unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64;
  v5 = 1;
  if ( !((*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                               + 8
                               * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                                    * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                         - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                        * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                               + 40)
                   + 10i64) >> 9) & 1) )
    v5 = 8193;
  v6 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&this->0, v5);
  *(float *)&v6[1].vfptr = v2->M[0][0];
  HIDWORD(v6[1].vfptr) = LODWORD(v2->M[0][1]);
  *(float *)&v6[1].Type = v2->M[0][2];
  *(float *)(&v6[1].Flags + 1) = v2->M[0][3];
  *(float *)&v6[2].vfptr = v2->M[1][0];
  HIDWORD(v6[2].vfptr) = LODWORD(v2->M[1][1]);
  *(float *)&v6[2].Type = v2->M[1][2];
  *(float *)(&v6[2].Flags + 1) = v2->M[1][3];
  *(float *)&v6[3].vfptr = v2->M[2][0];
  HIDWORD(v6[3].vfptr) = LODWORD(v2->M[2][1]);
  *(float *)&v6[3].Type = v2->M[2][2];
  *(float *)(&v6[3].Flags + 1) = v2->M[2][3];
  v6->Flags |= 0x200u;
  if ( _bittest((const signed int *)&v5, 0xDu) )
  {
    v7 = v3->pParent;
    if ( v7 )
    {
      do
      {
        v8 = Scaleform::Render::ContextImpl::Entry::getWritableData(v7, v5);
        v9 = &v7->PNode;
        v8->Flags |= 0x4000u;
        if ( !v7->PNode.pPrev )
        {
          v10 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64)
                                                                         + 0x18);
          v11 = v10[4].pPrev;
          v10 += 4;
          v9->pPrev = v11;
          v7->PNode.pNext = v10;
          v10->pPrev->pNext = v9;
          v10->pPrev = v9;
        }
        v7 = v7->pParent;
      }
      while ( v7
           && !((*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                      + 8
                                      * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&v7[-1] - ((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64))
                                                                                           * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                       + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&v7[-1]
                                                                                                - ((unsigned __int64)v7 & 0xFFFFFFFFFFFFF000ui64))
                                                                               * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                      + 40)
                          + 10i64) >> 9) & 1) );
    }
  }
  v12 = &v3->PNode;
  if ( !v3->PNode.pPrev )
  {
    v13 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(v4 + 24);
    v14 = v13[4].pPrev;
    v13 += 4;
    v12->pPrev = v14;
    v3->PNode.pNext = v13;
    v13->pPrev->pNext = v12;
    v13->pPrev = v12;
  }
}

// File Line: 295
// RVA: 0x9B5E60
void __fastcall Scaleform::Render::TreeNode::SetVisible(Scaleform::Render::TreeNode *this, bool visible)
{
  Scaleform::Render::TreeNode *v2; // rbx
  bool v3; // di
  Scaleform::Render::ContextImpl::EntryData *v4; // rax
  Scaleform::Render::ContextImpl::Entry *v5; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v6; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v7; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v8; // rax

  v2 = this;
  v3 = visible;
  if ( (*(_BYTE *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8
                             * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                                  * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                              + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                       - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                             + 40)
                 + 10i64) & 1) != visible )
  {
    v4 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&this->0, 4u);
    v4->Flags &= 0xFFFEu;
    v4->Flags |= v3 != 0;
    v5 = v2->pParent;
    if ( v5 )
    {
      v6 = &v5->PNode;
      if ( !v5->PNode.pPrev )
      {
        v7 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(((unsigned __int64)v5 & 0xFFFFFFFFFFFFF000ui64)
                                                                      + 0x18);
        v8 = v7[4].pPrev;
        v7 += 4;
        v6->pPrev = v8;
        v6->pNext = v7;
        v7->pPrev->pNext = v6;
        v7->pPrev = v6;
      }
    }
  }
}

// File Line: 310
// RVA: 0x9AF1F0
void __fastcall Scaleform::Render::TreeNode::SetEdgeAAMode(Scaleform::Render::TreeNode *this, Scaleform::Render::EdgeAAMode edgeAA)
{
  __int16 v2; // bx
  Scaleform::Render::ContextImpl::EntryData *v3; // rax

  v2 = edgeAA;
  if ( (*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8
                             * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                                  * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                              + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                       - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                             + 40)
                 + 10i64) & 0xC) != edgeAA )
  {
    v3 = Scaleform::Render::ContextImpl::Entry::getWritableData(
           (Scaleform::Render::ContextImpl::Entry *)&this->0,
           0x20u);
    v3->Flags &= 0xFFF3u;
    v3->Flags |= v2;
  }
}

// File Line: 320
// RVA: 0x98B930
Scaleform::Render::State *__fastcall Scaleform::Render::TreeNode::GetState(Scaleform::Render::TreeNode *this, Scaleform::Render::StateType state)
{
  __int64 v2; // r9
  signed __int64 v3; // r8
  __int64 v4; // r10
  unsigned __int64 v5; // rdx
  signed __int64 v6; // r10
  Scaleform::Render::StateData::Interface *v7; // r9
  unsigned __int64 v9; // rax
  signed __int64 v10; // r10
  unsigned __int64 v11; // rdx
  Scaleform::Render::StateData::Interface **v12; // rcx

  v2 = state;
  v3 = 0i64;
  v4 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8
                 * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                       - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                  + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                           - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                 + 40);
  v5 = *(_QWORD *)(v4 + 64);
  v6 = v4 + 64;
  if ( !v5 )
    return (Scaleform::Render::State *)v3;
  v7 = StateType_Interfaces[v2];
  if ( v5 & 1 )
  {
    if ( (Scaleform::Render::StateData::Interface *)(v5 & 0xFFFFFFFFFFFFFFFEui64) == v7 )
      v3 = v6;
    return (Scaleform::Render::State *)v3;
  }
  v9 = 0i64;
  v10 = *(_QWORD *)(v6 + 8) + 4i64;
  v11 = v5 >> 1;
  if ( !v11 )
    return (Scaleform::Render::State *)v3;
  v12 = (Scaleform::Render::StateData::Interface **)v10;
  while ( *v12 != v7 )
  {
    ++v9;
    v12 += 2;
    if ( v9 >= v11 )
      return 0i64;
  }
  return (Scaleform::Render::State *)(v10 + 16 * v9);
}

// File Line: 325
// RVA: 0x9B3700
void __fastcall Scaleform::Render::TreeNode::SetScale9Grid(Scaleform::Render::TreeNode *this, Scaleform::Render::Rect<float> *rect)
{
  Scaleform::Render::Rect<float> *v2; // rdi
  Scaleform::Render::TreeNode *v3; // rbx
  Scaleform::Render::StateBag *v4; // rax
  Scaleform::Render::StateBag *v5; // rsi
  volatile signed __int32 *v6; // rbx
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  int v10; // [rsp+58h] [rbp+10h]
  volatile signed __int32 *v11; // [rsp+60h] [rbp+18h]
  volatile signed __int32 *v12; // [rsp+68h] [rbp+20h]

  v2 = rect;
  v3 = this;
  v4 = (Scaleform::Render::StateBag *)Scaleform::Render::ContextImpl::Entry::getWritableData(
                                        (Scaleform::Render::ContextImpl::Entry *)&this->0,
                                        0x10000u);
  v5 = v4;
  if ( v2->x2 <= v2->x1 || v2->y2 <= v2->y1 )
  {
    Scaleform::Render::StateBag::RemoveState(v4 + 4, State_Scale9);
  }
  else
  {
    v10 = 71;
    v6 = (volatile signed __int32 *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeNode *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                      Scaleform::Memory::pGlobalHeap,
                                      v3,
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
      v7 = v2->y2;
      v8 = v2->x2;
      v9 = v2->y1;
      *((_DWORD *)v6 + 4) = LODWORD(v2->x1);
      *((float *)v6 + 5) = v9;
      *((float *)v6 + 6) = v8;
      *((float *)v6 + 7) = v7;
      Scaleform::Render::StateBag::SetStateVoid(
        v5 + 4,
        (Scaleform::Render::StateData::Interface *)&Scaleform::Render::Scale9State::InterfaceImpl.vfptr,
        (void *)v6);
    }
    if ( v6 )
    {
      if ( !_InterlockedDecrement(v6 + 2) )
        (**(void (__fastcall ***)(volatile signed __int32 *, signed __int64))v6)(v6, 1i64);
    }
  }
}

// File Line: 343
// RVA: 0x9B57E0
void __fastcall Scaleform::Render::TreeNode::SetViewMatrix3D(Scaleform::Render::TreeNode *this, Scaleform::Render::Matrix3x4<float> *mat3D)
{
  Scaleform::Render::Matrix3x4<float> *v2; // rsi
  Scaleform::Render::TreeNode *v3; // rbx
  Scaleform::Render::ContextImpl::EntryData *v4; // rbp
  __int64 v5; // rax
  volatile signed __int32 *v6; // rdi
  int v7; // [rsp+68h] [rbp+10h]
  __int64 v8; // [rsp+70h] [rbp+18h]
  volatile signed __int32 *v9; // [rsp+78h] [rbp+20h]

  v2 = mat3D;
  v3 = this;
  v4 = Scaleform::Render::ContextImpl::Entry::getWritableData(
         (Scaleform::Render::ContextImpl::Entry *)&this->0,
         0x80000u);
  v7 = 2;
  v5 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeNode *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
         Scaleform::Memory::pGlobalHeap,
         v3,
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
  *((_DWORD *)v6 + 4) = LODWORD(v2->M[0][0]);
  *((_DWORD *)v6 + 5) = LODWORD(v2->M[0][1]);
  *((_DWORD *)v6 + 6) = LODWORD(v2->M[0][2]);
  *((_DWORD *)v6 + 7) = LODWORD(v2->M[0][3]);
  *((_DWORD *)v6 + 8) = LODWORD(v2->M[1][0]);
  *((_DWORD *)v6 + 9) = LODWORD(v2->M[1][1]);
  *((_DWORD *)v6 + 10) = LODWORD(v2->M[1][2]);
  *((_DWORD *)v6 + 11) = LODWORD(v2->M[1][3]);
  *((_DWORD *)v6 + 12) = LODWORD(v2->M[2][0]);
  *((_DWORD *)v6 + 13) = LODWORD(v2->M[2][1]);
  *((_DWORD *)v6 + 14) = LODWORD(v2->M[2][2]);
  *((_DWORD *)v6 + 15) = LODWORD(v2->M[2][3]);
  Scaleform::Render::StateBag::SetStateVoid(
    (Scaleform::Render::StateBag *)&v4[4],
    (Scaleform::Render::StateData::Interface *)&Scaleform::Render::ViewMatrix3DState::InterfaceImpl.vfptr,
    (void *)v6);
  v4->Flags |= 0x800u;
  if ( !_InterlockedDecrement(v6 + 2) )
    (**(void (__fastcall ***)(volatile signed __int32 *, signed __int64))v6)(v6, 1i64);
}

// File Line: 353
// RVA: 0x960600
void __fastcall Scaleform::Render::TreeNode::ClearViewMatrix3D(Scaleform::Render::TreeNode *this)
{
  Scaleform::Render::ContextImpl::EntryData *v1; // rbx

  v1 = Scaleform::Render::ContextImpl::Entry::getWritableData(
         (Scaleform::Render::ContextImpl::Entry *)&this->0,
         0x80000u);
  Scaleform::Render::StateBag::RemoveState((Scaleform::Render::StateBag *)&v1[4], State_ViewMatrix3D);
  v1->Flags &= 0xF7FFu;
}

// File Line: 360
// RVA: 0x9B2CB0
void __fastcall Scaleform::Render::TreeNode::SetProjectionMatrix3D(Scaleform::Render::TreeNode *this, Scaleform::Render::Matrix4x4<float> *mat3D)
{
  Scaleform::Render::Matrix4x4<float> *v2; // rsi
  Scaleform::Render::TreeNode *v3; // rbx
  Scaleform::Render::ContextImpl::EntryData *v4; // rbp
  __int64 v5; // rax
  volatile signed __int32 *v6; // rdi
  int v7; // [rsp+68h] [rbp+10h]
  __int64 v8; // [rsp+70h] [rbp+18h]
  volatile signed __int32 *v9; // [rsp+78h] [rbp+20h]

  v2 = mat3D;
  v3 = this;
  v4 = Scaleform::Render::ContextImpl::Entry::getWritableData(
         (Scaleform::Render::ContextImpl::Entry *)&this->0,
         0x100000u);
  v7 = 2;
  v5 = ((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeNode *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
         Scaleform::Memory::pGlobalHeap,
         v3,
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
  *((_DWORD *)v6 + 4) = LODWORD(v2->M[0][0]);
  *((_DWORD *)v6 + 5) = LODWORD(v2->M[0][1]);
  *((_DWORD *)v6 + 6) = LODWORD(v2->M[0][2]);
  *((_DWORD *)v6 + 7) = LODWORD(v2->M[0][3]);
  *((_DWORD *)v6 + 8) = LODWORD(v2->M[1][0]);
  *((_DWORD *)v6 + 9) = LODWORD(v2->M[1][1]);
  *((_DWORD *)v6 + 10) = LODWORD(v2->M[1][2]);
  *((_DWORD *)v6 + 11) = LODWORD(v2->M[1][3]);
  *((_DWORD *)v6 + 12) = LODWORD(v2->M[2][0]);
  *((_DWORD *)v6 + 13) = LODWORD(v2->M[2][1]);
  *((_DWORD *)v6 + 14) = LODWORD(v2->M[2][2]);
  *((_DWORD *)v6 + 15) = LODWORD(v2->M[2][3]);
  *((_DWORD *)v6 + 16) = LODWORD(v2->M[3][0]);
  *((_DWORD *)v6 + 17) = LODWORD(v2->M[3][1]);
  *((_DWORD *)v6 + 18) = LODWORD(v2->M[3][2]);
  *((_DWORD *)v6 + 19) = LODWORD(v2->M[3][3]);
  Scaleform::Render::StateBag::SetStateVoid(
    (Scaleform::Render::StateBag *)&v4[4],
    (Scaleform::Render::StateData::Interface *)&Scaleform::Render::ProjectionMatrix3DState::InterfaceImpl.vfptr,
    (void *)v6);
  v4->Flags |= 0x1000u;
  if ( !_InterlockedDecrement(v6 + 2) )
    (**(void (__fastcall ***)(volatile signed __int32 *, signed __int64))v6)(v6, 1i64);
}

// File Line: 370
// RVA: 0x9605D0
void __fastcall Scaleform::Render::TreeNode::ClearProjectionMatrix3D(Scaleform::Render::TreeNode *this)
{
  Scaleform::Render::ContextImpl::EntryData *v1; // rbx

  v1 = Scaleform::Render::ContextImpl::Entry::getWritableData(
         (Scaleform::Render::ContextImpl::Entry *)&this->0,
         0x100000u);
  Scaleform::Render::StateBag::RemoveState((Scaleform::Render::StateBag *)&v1[4], State_ProjectionMatrix3D);
  v1->Flags &= 0xEFFFu;
}

// File Line: 377
// RVA: 0x9AE3D0
void __fastcall Scaleform::Render::TreeNode::SetBlendMode(Scaleform::Render::TreeNode *this, Scaleform::Render::BlendMode mode)
{
  void *v2; // rdi
  Scaleform::Render::TreeNode *v3; // rbx
  Scaleform::Render::StateBag *v4; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v5; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v6; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v7; // rax

  v2 = (void *)(signed int)mode;
  v3 = this;
  v4 = (Scaleform::Render::StateBag *)&Scaleform::Render::ContextImpl::Entry::getWritableData(
                                         (Scaleform::Render::ContextImpl::Entry *)&this->0,
                                         0x20000u)[4];
  if ( (_DWORD)v2 )
    Scaleform::Render::StateBag::SetStateVoid(
      v4,
      (Scaleform::Render::StateData::Interface *)&Scaleform::Render::BlendState::InterfaceImpl.vfptr,
      v2);
  else
    Scaleform::Render::StateBag::RemoveState(v4, State_BlendMode);
  v5 = &v3->PNode;
  if ( !v3->PNode.pPrev )
  {
    v6 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(((unsigned __int64)v3 & 0xFFFFFFFFFFFFF000ui64)
                                                                  + 0x18);
    v7 = v6[4].pPrev;
    v6 += 4;
    v5->pPrev = v7;
    v3->PNode.pNext = v6;
    v6->pPrev->pNext = v5;
    v6->pPrev = v5;
  }
}

// File Line: 388
// RVA: 0x9B1680
void __fastcall Scaleform::Render::TreeNode::SetMaskNode(Scaleform::Render::TreeNode *this, Scaleform::Render::TreeNode *node)
{
  Scaleform::Render::TreeNode *v2; // rsi
  Scaleform::Render::TreeNode *v3; // rbx
  Scaleform::Render::TreeNode::NodeData *v4; // rax
  Scaleform::Render::TreeNode::NodeData *v5; // rdi
  Scaleform::Render::ContextImpl::EntryData *v6; // rax
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v7; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v8; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v9; // rax

  v2 = node;
  v3 = this;
  v4 = (Scaleform::Render::TreeNode::NodeData *)Scaleform::Render::ContextImpl::Entry::getWritableData(
                                                  (Scaleform::Render::ContextImpl::Entry *)&this->0,
                                                  0x40000u);
  v5 = v4;
  if ( v2 )
  {
    v6 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&v2->0, 0x80u);
    v2->pParent = (Scaleform::Render::ContextImpl::Entry *)&v3->0;
    v6->Flags |= 0x20u;
    Scaleform::Render::StateBag::SetStateVoid(
      (Scaleform::Render::StateBag *)&v6[4],
      (Scaleform::Render::StateData::Interface *)&Scaleform::Render::Internal_MaskOwnerState::InterfaceImpl.vfptr,
      v3);
    v5->Flags |= 0x10u;
    Scaleform::Render::StateBag::SetStateVoid(
      &v5->States,
      (Scaleform::Render::StateData::Interface *)&Scaleform::Render::MaskNodeState::InterfaceImpl.vfptr,
      v2);
  }
  else if ( Scaleform::Render::TreeNode::removeThisAsMaskOwner(v4) )
  {
    Scaleform::Render::StateBag::RemoveState(&v5->States, State_MaskNode);
    v5->Flags &= 0xFFEFu;
  }
  v7 = &v3->PNode;
  if ( !v3->PNode.pPrev )
  {
    v8 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(((unsigned __int64)v3 & 0xFFFFFFFFFFFFF000ui64)
                                                                  + 0x18);
    v9 = v8[4].pPrev;
    v8 += 4;
    v7->pPrev = v9;
    v3->PNode.pNext = v8;
    v8->pPrev->pNext = v7;
    v8->pPrev = v7;
  }
}

// File Line: 407
// RVA: 0x9AF300
void __fastcall Scaleform::Render::TreeNode::SetFilters(Scaleform::Render::TreeNode *this, Scaleform::Render::FilterSet *filters)
{
  Scaleform::Render::TreeNode *v2; // rdi
  Scaleform::Render::FilterSet *v3; // rsi
  Scaleform::Render::ContextImpl::EntryData *v4; // rbx
  Scaleform::Render::ContextImpl::EntryData *v5; // rbx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v6; // rdx
  signed __int64 v7; // rcx

  v2 = this;
  if ( filters && LODWORD(filters->Filters.Data.Size) )
  {
    v3 = Scaleform::Render::FilterSet::Clone(filters, 1, 0i64);
    v4 = Scaleform::Render::ContextImpl::Entry::getWritableData(
           (Scaleform::Render::ContextImpl::Entry *)&v2->0,
           0x200002u);
    Scaleform::Render::StateBag::SetStateVoid(
      (Scaleform::Render::StateBag *)&v4[4],
      (Scaleform::Render::StateData::Interface *)&Scaleform::Render::FilterState::InterfaceImpl.vfptr,
      v3);
    v4->Flags |= 0x400u;
    if ( v3 && !_InterlockedDecrement(&v3->RefCount) )
      v3->vfptr->__vecDelDtor((Scaleform::RefCountImplCore *)&v3->vfptr, 1u);
  }
  else
  {
    if ( !((*(_WORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                                 + 8
                                 * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                                  + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                           - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                                 + 40)
                     + 10i64) >> 10) & 1) )
      return;
    v5 = Scaleform::Render::ContextImpl::Entry::getWritableData(
           (Scaleform::Render::ContextImpl::Entry *)&this->0,
           0x200002u);
    Scaleform::Render::StateBag::RemoveState((Scaleform::Render::StateBag *)&v5[4], State_Filter);
    v5->Flags &= 0xFBFFu;
  }
  v6 = &v2->PNode;
  if ( !v2->PNode.pPrev )
  {
    v7 = *(_QWORD *)(((unsigned __int64)v2 & 0xFFFFFFFFFFFFF000ui64) + 0x18) + 64i64;
    v6->pPrev = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)v7;
    v2->PNode.pNext = (Scaleform::Render::ContextImpl::Entry::PropagateNode *)v7;
    *(_QWORD *)(*(_QWORD *)v7 + 8i64) = v6;
    *(_QWORD *)v7 = v6;
  }
}

// File Line: 433
// RVA: 0x9B24A0
void __fastcall Scaleform::Render::TreeNode::SetOrigScale9Parent(Scaleform::Render::TreeNode *this, Scaleform::Render::TreeNode *origParent)
{
  Scaleform::Render::TreeNode *v2; // rsi
  Scaleform::Render::TreeNode *v3; // rdi
  Scaleform::Render::ContextImpl::EntryData *v4; // rbx
  Scaleform::Render::StateBag *v5; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v6; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v7; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v8; // rax

  v2 = origParent;
  v3 = this;
  v4 = Scaleform::Render::ContextImpl::Entry::getWritableData(
         (Scaleform::Render::ContextImpl::Entry *)&this->0,
         0x10000u);
  v5 = (Scaleform::Render::StateBag *)&v4[4];
  if ( v2 )
  {
    Scaleform::Render::StateBag::SetStateVoid(
      v5,
      (Scaleform::Render::StateData::Interface *)&Scaleform::Render::OrigScale9ParentState::InterfaceImpl.vfptr,
      v2);
    v4->Flags |= 0x2000u;
  }
  else
  {
    Scaleform::Render::StateBag::RemoveState(v5, State_OrigScale9Parent);
    v4->Flags &= 0xDFFFu;
  }
  v6 = &v3->PNode;
  if ( !v3->PNode.pPrev )
  {
    v7 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(((unsigned __int64)v3 & 0xFFFFFFFFFFFFF000ui64)
                                                                  + 0x18);
    v8 = v7[4].pPrev;
    v7 += 4;
    v6->pPrev = v8;
    v3->PNode.pNext = v7;
    v7->pPrev->pNext = v6;
    v7->pPrev = v6;
  }
}

// File Line: 479
// RVA: 0x9F0470
char __fastcall Scaleform::Render::TreeNode::removeThisAsMaskOwner(Scaleform::Render::TreeNode::NodeData *thisData)
{
  Scaleform::Render::StateData::Interface *v1; // rdx
  Scaleform::Render::ContextImpl::Entry **v2; // rbx
  unsigned __int64 v4; // rax
  unsigned __int64 v5; // r9
  unsigned __int64 v6; // rdx
  _QWORD *v7; // rcx
  Scaleform::Render::ContextImpl::EntryData *v8; // rax

  v1 = thisData->States.pInterface;
  v2 = (Scaleform::Render::ContextImpl::Entry **)&thisData->States;
  if ( !v1 )
    return 0;
  if ( (unsigned __int8)v1 & 1 )
  {
    if ( ((unsigned __int64)v1 & 0xFFFFFFFFFFFFFFFEui64) != qword_142451A60 )
      return 0;
  }
  else
  {
    v4 = 0i64;
    v5 = thisData->States.DataValue + 4;
    v6 = (unsigned __int64)v1 >> 1;
    if ( !v6 )
      return 0;
    v7 = (_QWORD *)(thisData->States.DataValue + 4);
    while ( *v7 != qword_142451A60 )
    {
      ++v4;
      v7 += 2;
      if ( v4 >= v6 )
        return 0;
    }
    v2 = (Scaleform::Render::ContextImpl::Entry **)(16 * v4 + v5);
  }
  if ( !v2 )
    return 0;
  v8 = Scaleform::Render::ContextImpl::Entry::getWritableData(v2[1], 0x80u);
  v2[1]->pParent = 0i64;
  v8->Flags &= 0xFFDFu;
  Scaleform::Render::StateBag::RemoveState((Scaleform::Render::StateBag *)&v8[4], State_Internal_MaskOwner);
  return 1;
}

// File Line: 496
// RVA: 0x964C40
void __fastcall Scaleform::Render::TreeNode::CopyGeomData(Scaleform::Render::TreeNode *this, Scaleform::Render::TreeNode *src)
{
  Scaleform::Render::TreeNode *v2; // rbx
  Scaleform::Render::TreeNode *v3; // rdi
  Scaleform::Render::ContextImpl::EntryData *v4; // rax

  v2 = src;
  v3 = this;
  v4 = Scaleform::Render::ContextImpl::Entry::getWritableData((Scaleform::Render::ContextImpl::Entry *)&this->0, 3u);
  ((void (__fastcall *)(Scaleform::Render::ContextImpl::EntryData *, Scaleform::Render::TreeNode *, Scaleform::Render::TreeNode *))v4->vfptr[1].ConstructCopy)(
    v4,
    v3,
    v2);
}

// File Line: 501
// RVA: 0x9B3530
void __fastcall Scaleform::Render::TreeNode::SetRendererString(Scaleform::Render::TreeNode *this, const char *str)
{
  const char *v2; // rsi
  Scaleform::Render::TreeNode *v3; // rbx
  Scaleform::Render::StateBag *v4; // r14
  Scaleform::Render::State *v5; // rax
  unsigned __int64 v6; // rdi
  volatile signed __int32 *v7; // rbx
  int v8; // [rsp+68h] [rbp+10h]
  volatile signed __int32 *v9; // [rsp+70h] [rbp+18h]
  volatile signed __int32 *v10; // [rsp+78h] [rbp+20h]

  v2 = str;
  v3 = this;
  v4 = (Scaleform::Render::StateBag *)Scaleform::Render::ContextImpl::Entry::getWritableData(
                                        (Scaleform::Render::ContextImpl::Entry *)&this->0,
                                        0x400000u);
  v5 = Scaleform::Render::TreeNode::GetState(v3, State_UserData);
  v6 = 0i64;
  v9 = 0i64;
  if ( v5 )
  {
    v7 = (volatile signed __int32 *)v5->pData;
    if ( v7 )
      _InterlockedExchangeAdd(v7 + 2, 1u);
  }
  else
  {
    v8 = 2;
    v7 = (volatile signed __int32 *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeNode *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                      Scaleform::Memory::pGlobalHeap,
                                      v3,
                                      40i64,
                                      &v8,
                                      -2i64);
    v10 = v7;
    if ( v7 )
    {
      *(_QWORD *)v7 = &Scaleform::RefCountImplCore::`vftable;
      *((_DWORD *)v7 + 2) = 1;
      *(_QWORD *)v7 = &Scaleform::RefCountImpl::`vftable;
      *(_QWORD *)v7 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
      *(_QWORD *)v7 = &Scaleform::RefCountBase<Scaleform::Render::UserDataState::Data,2>::`vftable;
      *(_QWORD *)v7 = &Scaleform::Render::UserDataState::Data::`vftable;
      _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
      *((_QWORD *)v7 + 2) = (unsigned __int64)&Scaleform::String::NullData | 1;
      *((_DWORD *)v7 + 6) = 0;
      *((_BYTE *)v7 + 28) = 0;
      *((_DWORD *)v7 + 8) = 0;
    }
    else
    {
      v7 = 0i64;
    }
  }
  v9 = v7;
  if ( v2 )
  {
    v6 = -1i64;
    do
      ++v6;
    while ( v2[v6] );
  }
  Scaleform::String::AssignString((Scaleform::String *)v7 + 2, v2, v6);
  *((_DWORD *)v7 + 8) |= 1u;
  Scaleform::Render::StateBag::SetStateVoid(
    v4 + 4,
    (Scaleform::Render::StateData::Interface *)&Scaleform::Render::UserDataState::InterfaceImpl.vfptr,
    (void *)v7);
  if ( _InterlockedExchangeAdd(v7 + 2, 0xFFFFFFFF) == 1 )
    (**(void (__fastcall ***)(volatile signed __int32 *, signed __int64))v9)(v9, 1i64);
}

// File Line: 519
// RVA: 0x98B070
Scaleform::Render::State *__fastcall Scaleform::Render::TreeNode::GetRendererString(Scaleform::Render::TreeNode *this)
{
  Scaleform::Render::State *result; // rax

  result = Scaleform::Render::TreeNode::GetState(this, State_UserData);
  if ( result )
    result = (Scaleform::Render::State *)((*(_QWORD *)(result->DataValue + 16) & 0xFFFFFFFFFFFFFFFCui64) + 12);
  return result;
}

// File Line: 530
// RVA: 0x9B33E0
void __fastcall Scaleform::Render::TreeNode::SetRendererFloat(Scaleform::Render::TreeNode *this, float f)
{
  Scaleform::Render::TreeNode *v2; // rbx
  Scaleform::Render::StateBag *v3; // rdi
  Scaleform::Render::State *v4; // rax
  volatile signed __int32 *v5; // rbx
  int v6; // [rsp+68h] [rbp+10h]
  volatile signed __int32 *v7; // [rsp+70h] [rbp+18h]
  volatile signed __int32 *v8; // [rsp+78h] [rbp+20h]

  v2 = this;
  v3 = (Scaleform::Render::StateBag *)Scaleform::Render::ContextImpl::Entry::getWritableData(
                                        (Scaleform::Render::ContextImpl::Entry *)&this->0,
                                        0x400000u);
  v4 = Scaleform::Render::TreeNode::GetState(v2, State_UserData);
  v7 = 0i64;
  if ( v4 )
  {
    v5 = (volatile signed __int32 *)v4->pData;
    if ( v5 )
      _InterlockedExchangeAdd(v5 + 2, 1u);
  }
  else
  {
    v6 = 2;
    v5 = (volatile signed __int32 *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeNode *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                      Scaleform::Memory::pGlobalHeap,
                                      v2,
                                      40i64,
                                      &v6,
                                      -2i64);
    v8 = v5;
    if ( v5 )
    {
      *(_QWORD *)v5 = &Scaleform::RefCountImplCore::`vftable;
      *((_DWORD *)v5 + 2) = 1;
      *(_QWORD *)v5 = &Scaleform::RefCountImpl::`vftable;
      *(_QWORD *)v5 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
      *(_QWORD *)v5 = &Scaleform::RefCountBase<Scaleform::Render::UserDataState::Data,2>::`vftable;
      *(_QWORD *)v5 = &Scaleform::Render::UserDataState::Data::`vftable;
      _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
      *((_QWORD *)v5 + 2) = (unsigned __int64)&Scaleform::String::NullData | 1;
      *((_DWORD *)v5 + 6) = 0;
      *((_BYTE *)v5 + 28) = 0;
      *((_DWORD *)v5 + 8) = 0;
    }
    else
    {
      v5 = 0i64;
    }
  }
  v7 = v5;
  *((_DWORD *)v5 + 8) |= 2u;
  *((float *)v5 + 6) = f;
  Scaleform::Render::StateBag::SetStateVoid(
    v3 + 4,
    (Scaleform::Render::StateData::Interface *)&Scaleform::Render::UserDataState::InterfaceImpl.vfptr,
    (void *)v5);
  if ( !_InterlockedDecrement(v5 + 2) )
    (**(void (__fastcall ***)(volatile signed __int32 *, signed __int64))v7)(v7, 1i64);
}

// File Line: 548
// RVA: 0x98B040
float __fastcall Scaleform::Render::TreeNode::GetRendererFloat(Scaleform::Render::TreeNode *this)
{
  Scaleform::Render::State *v1; // rax
  float result; // xmm0_4

  v1 = Scaleform::Render::TreeNode::GetState(this, State_UserData);
  if ( v1 )
    result = *(float *)(v1->DataValue + 24);
  else
    result = 0.0;
  return result;
}

// File Line: 559
// RVA: 0x96E210
void __fastcall Scaleform::Render::TreeNode::DisableBatching(Scaleform::Render::TreeNode *this, bool b)
{
  bool v2; // di
  Scaleform::Render::TreeNode *v3; // rbx
  Scaleform::Render::StateBag *v4; // rsi
  Scaleform::Render::State *v5; // rax
  volatile signed __int32 *v6; // rbx
  int v7; // [rsp+58h] [rbp+10h]
  volatile signed __int32 *v8; // [rsp+60h] [rbp+18h]
  volatile signed __int32 *v9; // [rsp+68h] [rbp+20h]

  v2 = b;
  v3 = this;
  v4 = (Scaleform::Render::StateBag *)Scaleform::Render::ContextImpl::Entry::getWritableData(
                                        (Scaleform::Render::ContextImpl::Entry *)&this->0,
                                        0x400000u);
  v5 = Scaleform::Render::TreeNode::GetState(v3, State_UserData);
  v8 = 0i64;
  if ( v5 )
  {
    v6 = (volatile signed __int32 *)v5->pData;
    if ( v6 )
      _InterlockedExchangeAdd(v6 + 2, 1u);
  }
  else
  {
    v7 = 2;
    v6 = (volatile signed __int32 *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeNode *, signed __int64, int *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                                      Scaleform::Memory::pGlobalHeap,
                                      v3,
                                      40i64,
                                      &v7,
                                      -2i64);
    v9 = v6;
    if ( v6 )
    {
      *(_QWORD *)v6 = &Scaleform::RefCountImplCore::`vftable;
      *((_DWORD *)v6 + 2) = 1;
      *(_QWORD *)v6 = &Scaleform::RefCountImpl::`vftable;
      *(_QWORD *)v6 = &Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,2>::`vftable;
      *(_QWORD *)v6 = &Scaleform::RefCountBase<Scaleform::Render::UserDataState::Data,2>::`vftable;
      *(_QWORD *)v6 = &Scaleform::Render::UserDataState::Data::`vftable;
      _InterlockedExchangeAdd(&Scaleform::String::NullData.RefCount, 1u);
      *((_QWORD *)v6 + 2) = (unsigned __int64)&Scaleform::String::NullData | 1;
      *((_DWORD *)v6 + 6) = 0;
      *((_BYTE *)v6 + 28) = 0;
      *((_DWORD *)v6 + 8) = 0;
    }
    else
    {
      v6 = 0i64;
    }
  }
  v8 = v6;
  *((_DWORD *)v6 + 8) |= 4u;
  *((_BYTE *)v6 + 28) = v2;
  Scaleform::Render::StateBag::SetStateVoid(
    v4 + 4,
    (Scaleform::Render::StateData::Interface *)&Scaleform::Render::UserDataState::InterfaceImpl.vfptr,
    (void *)v6);
  if ( !_InterlockedDecrement(v6 + 2) )
    (**(void (__fastcall ***)(volatile signed __int32 *, signed __int64))v8)(v8, 1i64);
}

// File Line: 577
// RVA: 0x997490
Scaleform::Render::State *__fastcall Scaleform::Render::TreeNode::IsBatchingDisabled(Scaleform::Render::TreeNode *this)
{
  Scaleform::Render::State *result; // rax

  result = Scaleform::Render::TreeNode::GetState(this, State_UserData);
  if ( result )
    result = (Scaleform::Render::State *)*(unsigned __int8 *)(result->DataValue + 28);
  return result;
}

// File Line: 593
// RVA: 0x9CB770
Scaleform::Render::TreeNodeArray::ArrayData *__fastcall Scaleform::Render::TreeNodeArray::allocByCapacity(Scaleform::Render::TreeNodeArray *this, unsigned __int64 capacity, unsigned __int64 size)
{
  unsigned __int64 v3; // rbx
  Scaleform::Render::TreeNodeArray::ArrayData *result; // rax

  v3 = size;
  result = (Scaleform::Render::TreeNodeArray::ArrayData *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                            Scaleform::Memory::pGlobalHeap,
                                                            this,
                                                            8 * capacity + 16,
                                                            0i64);
  if ( result )
  {
    result->RefCount = 1;
    result->Size = v3;
  }
  return result;
}

// File Line: 605
// RVA: 0x946BA0
void __fastcall Scaleform::Render::TreeNodeArray::TreeNodeArray(Scaleform::Render::TreeNodeArray *this, Scaleform::Render::TreeNodeArray *src)
{
  *this = *src;
  if ( (_QWORD)src->pNodes[0] & 1 )
  {
    _InterlockedExchangeAdd((volatile signed __int32 *)(src->pData[0] & 0xFFFFFFFFFFFFFFFEui64), 1u);
    this->pData[1] = 0i64;
  }
}

// File Line: 618
// RVA: 0x94E6F0
void __fastcall Scaleform::Render::TreeNodeArray::operator=(Scaleform::Render::TreeNodeArray *this, Scaleform::Render::TreeNodeArray *src)
{
  Scaleform::Render::TreeNodeArray *v2; // rbx
  unsigned __int64 v3; // rdx
  Scaleform::Render::TreeNodeArray *v4; // rdi
  Scaleform::Render::TreeNode *v5; // rsi
  unsigned __int64 v6; // rax

  v2 = src;
  v3 = this->pData[0];
  v4 = this;
  v5 = v2->pNodes[1];
  if ( (_QWORD)v2->pNodes[0] & 1 )
  {
    _InterlockedExchangeAdd((volatile signed __int32 *)(v2->pData[0] & 0xFFFFFFFFFFFFFFFEui64), 1u);
    v5 = 0i64;
  }
  if ( v3 & 1 && !_InterlockedDecrement((volatile signed __int32 *)(v3 & 0xFFFFFFFFFFFFFFFEui64)) )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  v6 = v2->pData[0];
  v4->pData[1] = (unsigned __int64)v5;
  v4->pData[0] = v6;
}

// File Line: 664
// RVA: 0x9948A0
bool __fastcall Scaleform::Render::TreeNodeArray::Insert(Scaleform::Render::TreeNodeArray *this, unsigned __int64 index, Scaleform::Render::TreeNode *node)
{
  unsigned __int64 v3; // rdi
  Scaleform::Render::TreeNode *v4; // rbp
  unsigned __int64 v5; // rsi
  Scaleform::Render::TreeNodeArray *v6; // rbx
  _QWORD *v7; // rax
  unsigned __int64 v8; // rcx
  _QWORD *v9; // rdi
  unsigned __int64 v10; // rdx
  signed __int64 v11; // r15
  signed __int64 v12; // r8
  unsigned __int64 v13; // rdx
  __int64 v14; // rax
  unsigned __int64 v15; // r12
  unsigned __int64 v16; // r14
  unsigned __int64 v17; // r8

  v3 = this->pData[0];
  v4 = node;
  v5 = index;
  v6 = this;
  if ( !this->pData[0] )
  {
    this->pData[0] = (unsigned __int64)node;
    LOBYTE(v7) = 1;
    return (char)v7;
  }
  if ( !((_QWORD)this->pNodes[0] & 1) )
  {
    if ( !this->pData[1] )
    {
      if ( !index )
        this->pData[1] = v3;
      this->pData[index] = (unsigned __int64)node;
      LOBYTE(v7) = 1;
      return (char)v7;
    }
    v7 = (_QWORD *)((__int64 (__fastcall *)(Scaleform::MemoryHeap *, Scaleform::Render::TreeNodeArray *, signed __int64))Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap)(
                     Scaleform::Memory::pGlobalHeap,
                     this,
                     64i64);
    v8 = (unsigned __int64)v7;
    if ( !v7 )
      return (char)v7;
    *(_DWORD *)v7 = 1;
    v7[1] = 3i64;
    if ( v5 )
    {
      if ( v5 != 1 )
      {
        if ( v5 == 2 )
        {
          v7[2] = v6->pData[0];
          v7[3] = v6->pNodes[1];
        }
        goto LABEL_16;
      }
      v7[2] = v6->pData[0];
    }
    else
    {
      v7[3] = v6->pData[0];
    }
    v7[4] = v6->pNodes[1];
LABEL_16:
    v7[v5 + 2] = v4;
    LOBYTE(v7) = 1;
    v6->pData[0] = v8 | 1;
    v6->pData[1] = 6i64;
    return (char)v7;
  }
  v9 = (_QWORD *)(v3 & 0xFFFFFFFFFFFFFFFEui64);
  v10 = v9[1];
  v11 = v10 + 1;
  if ( v10 + 1 > this->pData[1] )
  {
    v15 = (((v10 >> 1) + v10 + 1) & 0xFFFFFFFFFFFFFFFCui64) + 2;
    v7 = (_QWORD *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                     Scaleform::Memory::pGlobalHeap,
                     this,
                     8 * v15 + 16,
                     0i64);
    v16 = (unsigned __int64)v7;
    if ( v7 )
    {
      *(_DWORD *)v7 = 1;
      v7[1] = v11;
      if ( v5 )
        memmove(v7 + 2, v9 + 2, 8 * v5);
      *(_QWORD *)(v16 + 8 * v5 + 16) = v4;
      v17 = v9[1];
      if ( v5 < v17 )
        memmove((void *)(v16 + 8 * (v5 + 3)), &v9[v5 + 2], 8 * (v17 - v5));
      if ( !_InterlockedDecrement((volatile signed __int32 *)v9) )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v9);
      v6->pData[1] = v15;
      LOBYTE(v7) = 1;
      v6->pData[0] = v16 | 1;
    }
  }
  else
  {
    if ( v10 > v5 )
    {
      v12 = (signed __int64)&v9[v10 + 2];
      v13 = v10 - v5;
      do
      {
        v14 = *(_QWORD *)(v12 - 8);
        v12 -= 8i64;
        *(_QWORD *)(v12 + 8) = v14;
        --v13;
      }
      while ( v13 );
    }
    v9[v5 + 2] = v4;
    ++v9[1];
    LOBYTE(v7) = 1;
  }
  return (char)v7;
}

// File Line: 754
// RVA: 0x9A9240
bool __fastcall Scaleform::Render::TreeNodeArray::Remove(Scaleform::Render::TreeNodeArray *this, unsigned __int64 index, unsigned __int64 count)
{
  unsigned __int64 v3; // rbp
  unsigned __int64 v4; // r14
  Scaleform::Render::TreeNodeArray *v5; // rbx
  Scaleform::Render::TreeNode *v6; // rax
  Scaleform::Render::TreeNodeArray::ArrayData *v7; // rax
  _QWORD *v8; // rdi
  unsigned __int64 v9; // rdx
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // rcx
  unsigned __int64 v12; // rsi
  Scaleform::Render::TreeNodeArray::ArrayData *v13; // r15
  unsigned __int64 v14; // r8
  unsigned __int64 v15; // rbp
  signed __int64 v16; // rcx
  unsigned __int64 v17; // r8
  __int64 v18; // rax

  v3 = count;
  v4 = index;
  v5 = this;
  if ( !count )
    goto LABEL_10;
  if ( !((_QWORD)this->pNodes[0] & 1) )
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
  v9 = v8[1] - count;
  if ( v9 > 1 )
  {
    v11 = this->pData[1];
    if ( v11 && (v11 >> 1 < v9 || v11 <= 0xA) )
      v12 = v11;
    else
      v12 = ((v9 + 1) & 0xFFFFFFFFFFFFFFFCui64) + 2;
    if ( v12 == v11 )
    {
      if ( v4 < v9 )
      {
        v15 = 8 * count;
        v16 = (signed __int64)&v8[v4 + 2];
        v17 = v9 - v4;
        do
        {
          v18 = *(_QWORD *)(v16 + v15);
          v16 += 8i64;
          *(_QWORD *)(v16 - 8) = v18;
          --v17;
        }
        while ( v17 );
      }
      v8[1] = v9;
    }
    else
    {
      v7 = Scaleform::Render::TreeNodeArray::allocByCapacity(v5, v12, v9);
      v13 = v7;
      if ( !v7 )
        return (char)v7;
      if ( v4 )
        memmove(v7->pNodes, v8 + 2, 8 * v4);
      v14 = v8[1];
      if ( v4 + v3 < v14 )
        memmove((char *)v13 + 8 * (v4 + 2), &v8[v4 + v3 + 2], 8 * (v14 - v4 - v3));
      if ( !_InterlockedDecrement((volatile signed __int32 *)v8) )
        Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v8);
      v5->pData[0] = (unsigned __int64)v13 | 1;
    }
    v5->pData[1] = v12;
    LOBYTE(v7) = 1;
    return (char)v7;
  }
  if ( v9 == 1 )
  {
    if ( v4 )
      v10 = v8[2];
    else
      v10 = v8[count + 2];
    this->pData[0] = v10;
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
_BOOL8 __fastcall Scaleform::Render::TreeContainer::Insert(Scaleform::Render::TreeContainer *this, unsigned __int64 index, Scaleform::Render::TreeNode *pnode)
{
  unsigned __int64 v3; // rbx
  Scaleform::Render::TreeNode *v4; // rsi
  Scaleform::Render::TreeContainer *v5; // rdi
  Scaleform::Render::TreeNodeArray *v6; // rax
  bool v7; // r9
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v8; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v9; // rcx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v10; // rax

  v3 = index;
  v4 = pnode;
  v5 = this;
  v6 = (Scaleform::Render::TreeNodeArray *)Scaleform::Render::ContextImpl::Entry::getWritableData(
                                             (Scaleform::Render::ContextImpl::Entry *)&this->0,
                                             0x100u);
  v7 = Scaleform::Render::TreeNodeArray::Insert(v6 + 9, v3, v4);
  if ( v7 )
  {
    ++v4->RefCount;
    v8 = &v5->PNode;
    v4->pParent = (Scaleform::Render::ContextImpl::Entry *)&v5->0;
    if ( !v5->PNode.pPrev )
    {
      v9 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(((unsigned __int64)v5 & 0xFFFFFFFFFFFFF000ui64)
                                                                    + 0x18);
      v10 = v9[4].pPrev;
      v9 += 4;
      v8->pPrev = v10;
      v5->PNode.pNext = v9;
      v9->pPrev->pNext = v8;
      v9->pPrev = v8;
    }
  }
  return v7;
}

// File Line: 890
// RVA: 0x9A9150
void __fastcall Scaleform::Render::TreeContainer::Remove(Scaleform::Render::TreeContainer *this, unsigned __int64 index, unsigned __int64 count)
{
  unsigned __int64 v3; // rbp
  unsigned __int64 v4; // r15
  Scaleform::Render::TreeContainer *v5; // rsi
  Scaleform::Render::ContextImpl::EntryData *v6; // rax
  Scaleform::Render::TreeNodeArray *v7; // r14
  Scaleform::Render::ContextImpl::EntryDataVtbl *v8; // rax
  signed __int64 v9; // rbx
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // rdi
  Scaleform::Render::ContextImpl::Entry *v12; // rcx
  bool v13; // zf
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v14; // r8
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v15; // rdx
  Scaleform::Render::ContextImpl::Entry::PropagateNode *v16; // rax

  if ( count )
  {
    v3 = index;
    v4 = count;
    v5 = this;
    v6 = Scaleform::Render::ContextImpl::Entry::getWritableData(
           (Scaleform::Render::ContextImpl::Entry *)&this->0,
           0x200u);
    v7 = (Scaleform::Render::TreeNodeArray *)&v6[9];
    v8 = v6[9].vfptr;
    if ( v8 || v3 )
    {
      if ( (unsigned __int8)v8 & 1 )
        v10 = ((unsigned __int64)v8 & 0xFFFFFFFFFFFFFFFEui64) + 16;
      else
        v10 = (unsigned __int64)v7;
      v9 = v10 + 8 * v3;
    }
    else
    {
      v9 = 0i64;
    }
    v11 = v4;
    do
    {
      --v11;
      *(_QWORD *)(*(_QWORD *)v9 + 32i64) = 0i64;
      v12 = *(Scaleform::Render::ContextImpl::Entry **)v9;
      v13 = *(_QWORD *)(*(_QWORD *)v9 + 8i64) == 1i64;
      --v12->RefCount;
      if ( v13 )
        Scaleform::Render::ContextImpl::Entry::destroyHelper(v12);
      v9 += 8i64;
    }
    while ( v11 );
    v14 = &v5->PNode;
    if ( !v5->PNode.pPrev )
    {
      v15 = *(Scaleform::Render::ContextImpl::Entry::PropagateNode **)(((unsigned __int64)v5 & 0xFFFFFFFFFFFFF000ui64)
                                                                     + 0x18);
      v16 = v15[4].pPrev;
      v15 += 4;
      v14->pPrev = v16;
      v5->PNode.pNext = v15;
      v15->pPrev->pNext = v14;
      v15->pPrev = v14;
    }
    Scaleform::Render::TreeNodeArray::Remove(v7, v3, v4);
  }
}

// File Line: 916
// RVA: 0x9A7F50
void __fastcall Scaleform::Render::TreeContainer::NodeData::ReleaseNodes(Scaleform::Render::TreeContainer::NodeData *this)
{
  unsigned __int64 v1; // rbx
  Scaleform::Render::TreeContainer::NodeData *v2; // rsi
  __int64 v3; // rdi
  Scaleform::Render::TreeNodeArray *v4; // rbx
  Scaleform::Render::ContextImpl::Entry *v5; // rcx
  bool v6; // zf

  v1 = this->Children.pData[0];
  v2 = this;
  if ( v1 )
  {
    v3 = v1 & 1 ? *(_QWORD *)((v1 & 0xFFFFFFFFFFFFFFFEui64) + 8) : (this->Children.pData[1] != 0) + 1i64;
    if ( v3 )
    {
      if ( v1 & 1 )
        v4 = (Scaleform::Render::TreeNodeArray *)((v1 & 0xFFFFFFFFFFFFFFFEui64) + 16);
      else
        v4 = &this->Children;
      do
      {
        --v3;
        *(_QWORD *)(v4->pData[0] + 32) = 0i64;
        v5 = (Scaleform::Render::ContextImpl::Entry *)v4->pData[0];
        v6 = *(_QWORD *)(v4->pData[0] + 8) == 1i64;
        --v5->RefCount;
        if ( v6 )
          Scaleform::Render::ContextImpl::Entry::destroyHelper(v5);
        v4 = (Scaleform::Render::TreeNodeArray *)((char *)v4 + 8);
      }
      while ( v3 );
    }
  }
  if ( (LOBYTE(v2->Flags) >> 4) & 1 )
    Scaleform::Render::TreeNode::removeThisAsMaskOwner((Scaleform::Render::TreeNode::NodeData *)&v2->vfptr);
  Scaleform::Render::StateBag::ReleaseNodes(&v2->States);
}

// File Line: 933
// RVA: 0x9A0950
bool __fastcall Scaleform::Render::TreeContainer::NodeData::PropagateUp(Scaleform::Render::TreeContainer::NodeData *this, Scaleform::Render::ContextImpl::Entry *entry)
{
  unsigned __int64 v2; // r10
  Scaleform::Render::ContextImpl::Entry *v3; // r14
  Scaleform::Render::TreeContainer::NodeData *v4; // rdi
  unsigned __int64 v5; // r11
  unsigned __int64 v6; // r9
  char v7; // bl
  float v8; // xmm6_4
  float v9; // xmm8_4
  float v10; // xmm7_4
  float v11; // xmm9_4
  __int64 v12; // rdx
  float v13; // xmm0_4
  float v14; // xmm1_4
  float v15; // xmm2_4
  float v16; // xmm3_4
  Scaleform::Render::StateData::Interface *v17; // rdx
  Scaleform::Render::StateBag *v18; // rsi
  unsigned __int64 v19; // rax
  unsigned __int64 v20; // r9
  unsigned __int64 v21; // rdx
  _QWORD *v22; // rcx
  _QWORD *v23; // rsi
  __int64 v24; // rbx
  __m128 v25; // xmm1
  __m128 v26; // xmm4
  __m128 v27; // xmm1
  __m128 v28; // xmm4
  __m128 v29; // xmm3
  __m128 v30; // xmm2
  __m128 v31; // xmm0
  __m128 v32; // xmm2
  __m128 v33; // xmm3
  __m128 v34; // xmm0
  __m128 v35; // xmm10
  __m128 v36; // xmm3
  __m128 v37; // xmm10
  float v38; // xmm11_4
  float v39; // xmm12_4
  float v40; // xmm13_4
  Scaleform::Render::ContextImpl::EntryData *v41; // rax
  __int16 v42; // ax
  Scaleform::Render::ContextImpl::EntryData *v43; // rbx
  Scaleform::Render::Rect<float> bounds; // [rsp+18h] [rbp-59h]
  Scaleform::Render::Rect<float> pr; // [rsp+28h] [rbp-49h]
  Scaleform::Render::Rect<float> v47; // [rsp+38h] [rbp-39h]

  v2 = this->Children.pData[0];
  v3 = entry;
  v4 = this;
  if ( v2 )
  {
    if ( (_QWORD)this->Children.pNodes[0] & 1 )
      v5 = *(_QWORD *)((v2 & 0xFFFFFFFFFFFFFFFEui64) + 8);
    else
      v5 = (this->Children.pData[1] != 0) + 1i64;
  }
  else
  {
    v5 = 0i64;
  }
  if ( v2 )
  {
    if ( (_QWORD)this->Children.pNodes[0] & 1 )
      v2 = (v2 & 0xFFFFFFFFFFFFFFFEui64) + 16;
    else
      v2 = (unsigned __int64)&this->Children;
  }
  v6 = 0i64;
  v7 = 1;
  bounds = 0i64;
  LODWORD(v8) = (unsigned __int128)0i64 >> 96;
  LODWORD(v9) = 0i64 >> 63;
  v10 = bounds.y1;
  v11 = 0.0;
  v47 = 0i64;
  pr = 0i64;
  if ( !v5 )
    goto LABEL_44;
  do
  {
    v12 = *(_QWORD *)(*(_QWORD *)((*(_QWORD *)(v2 + 8 * v6) & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                    + 8
                    * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)(*(_QWORD *)(v2 + 8 * v6)
                                                                                          - (*(_QWORD *)(v2 + 8 * v6) & 0xFFFFFFFFFFFFF000ui64)
                                                                                          - 56)
                                                                         * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                     + ((unsigned __int64)((unsigned __int128)((signed __int64)(*(_QWORD *)(v2 + 8 * v6)
                                                                              - (*(_QWORD *)(v2 + 8 * v6) & 0xFFFFFFFFFFFFF000ui64)
                                                                              - 56)
                                                             * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                    + 40);
    if ( *(_BYTE *)(v12 + 10) & 1 )
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
            v11 = *(float *)(v12 + 128);
            v10 = *(float *)(v12 + 132);
            v9 = *(float *)(v12 + 136);
            v7 = 0;
            bounds.x1 = *(float *)(v12 + 128);
            bounds.y1 = v15;
            bounds.x2 = v14;
LABEL_23:
            v8 = v16;
            bounds.y2 = v16;
            goto LABEL_24;
          }
          if ( v11 > v13 )
          {
            v11 = *(float *)(v12 + 128);
            bounds.x1 = *(float *)(v12 + 128);
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
    v40 = pr.y2;
    v39 = pr.x2;
    v38 = pr.y1;
    v37.m128_i32[0] = LODWORD(pr.x1);
    goto LABEL_45;
  }
  v17 = this->States.pInterface;
  v18 = &this->States;
  v47.x1 = v11;
  v47.y1 = v10;
  v47.x2 = v9;
  v47.y2 = v8;
  if ( v17 )
  {
    if ( (unsigned __int8)v17 & 1 )
    {
      if ( ((unsigned __int64)v17 & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A58 )
        goto LABEL_36;
    }
    else
    {
      v19 = 0i64;
      v20 = this->States.DataValue + 4;
      v21 = (unsigned __int64)v17 >> 1;
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
        v18 = (Scaleform::Render::StateBag *)(16 * v19 + v20);
LABEL_36:
        if ( v18 )
        {
          v23 = v18->pData;
          if ( v23 )
          {
            v24 = 0i64;
            if ( *((_DWORD *)v23 + 6) )
            {
              do
              {
                Scaleform::Render::TreeNode::NodeData::expandByFilterBounds(
                  *(Scaleform::Render::Filter **)(v23[2] + 8 * v24),
                  &bounds);
                v24 = (unsigned int)(v24 + 1);
              }
              while ( (unsigned int)v24 < *((_DWORD *)v23 + 6) );
              v8 = bounds.y2;
              v9 = bounds.x2;
              v10 = bounds.y1;
              v11 = bounds.x1;
            }
          }
        }
      }
    }
  }
LABEL_41:
  if ( (v4->Flags >> 9) & 1 )
  {
    Scaleform::Render::Matrix3x4<float>::EncloseTransform(&v4->M34, &pr, &bounds);
    goto LABEL_44;
  }
  v25 = *(__m128 *)&v4->M34.M[0][0];
  v26 = v25;
  v27 = _mm_unpacklo_ps(v25, *(__m128 *)&v4->M34.M[1][0]);
  v28 = _mm_shuffle_ps(v26, *(__m128 *)&v4->M34.M[1][0], 255);
  v29 = _mm_mul_ps(_mm_unpackhi_ps((__m128)bounds, (__m128)bounds), v27);
  v30 = _mm_mul_ps(_mm_unpacklo_ps((__m128)bounds, (__m128)bounds), v27);
  v31 = _mm_unpacklo_ps(v30, v29);
  v32 = _mm_unpackhi_ps(v30, v29);
  v33 = _mm_add_ps(v32, v31);
  v34 = _mm_add_ps(_mm_shuffle_ps(v31, v31, 177), v32);
  v35 = _mm_min_ps(v33, v34);
  v36 = _mm_max_ps(v33, v34);
  v37 = _mm_add_ps(
          _mm_shuffle_ps(
            _mm_min_ps(v35, _mm_shuffle_ps(v35, v35, 177)),
            _mm_max_ps(v36, _mm_shuffle_ps(v36, v36, 177)),
            136),
          _mm_shuffle_ps(v28, v28, 136));
  LODWORD(v38) = (unsigned __int128)_mm_shuffle_ps(v37, v37, 85);
  LODWORD(v39) = (unsigned __int128)_mm_shuffle_ps(v37, v37, 170);
  LODWORD(v40) = (unsigned __int128)_mm_shuffle_ps(v37, v37, 255);
LABEL_45:
  if ( v11 != v4->AproxLocalBounds.x1
    || v9 != v4->AproxLocalBounds.x2
    || v10 != v4->AproxLocalBounds.y1
    || v8 != v4->AproxLocalBounds.y2
    || v37.m128_f32[0] != v4->AproxParentBounds.x1
    || v39 != v4->AproxParentBounds.x2
    || v38 != v4->AproxParentBounds.y1
    || v40 != v4->AproxParentBounds.y2 )
  {
    v43 = Scaleform::Render::ContextImpl::Entry::getWritableData(v3, 9u);
    *(float *)&v43[7].vfptr = v11;
    *((float *)&v43[7].vfptr + 1) = v10;
    *(float *)&v43[7].Type = v9;
    *(float *)(&v43[7].Flags + 1) = v8;
    LODWORD(v43[8].vfptr) = v37.m128_i32[0];
    *((float *)&v43[8].vfptr + 1) = v38;
    *(float *)&v43[8].Type = v39;
    *(float *)(&v43[8].Flags + 1) = v40;
    Scaleform::Render::TreeNode::NodeData::updateOriginalBoundState((Scaleform::Render::TreeNode::NodeData *)v43, &v47);
    if ( v3->pPrev && (_QWORD)v43[9].vfptr & 1 )
      *(_QWORD *)&v43[9].Type = 0i64;
    v42 = v4->Flags & 1;
  }
  else
  {
    if ( v3->pPrev )
    {
      v41 = Scaleform::Render::ContextImpl::Entry::getWritableData(v3, 0);
      if ( (_QWORD)v41[9].vfptr & 1 )
        *(_QWORD *)&v41[9].Type = 0i64;
    }
    LOBYTE(v42) = 0;
  }
  return v42;
}4->Flags 

// File Line: 1061
// RVA: 0x9F8CA0
Scaleform::Render::TreeCacheNode *__fastcall Scaleform::Render::TreeContainer::NodeData::updateCache(Scaleform::Render::TreeContainer::NodeData *this, Scaleform::Render::TreeCacheNode *pparent, Scaleform::Render::TreeCacheNode *pinsert, Scaleform::Render::TreeNode *pnode, unsigned __int16 depth)
{
  Scaleform::Render::TreeNode *v5; // rsi
  Scaleform::Render::TreeCacheNode *v6; // r14
  Scaleform::Render::TreeCacheNode *v7; // rdi
  Scaleform::Render::TreeContainer::NodeData *v8; // rbp
  Scaleform::Render::TreeCacheNode *v9; // rbx
  int v10; // eax
  int v11; // ecx
  unsigned __int16 v12; // dx
  int v13; // ebx
  Scaleform::Render::TreeCacheContainer *v14; // rax
  Scaleform::Render::TreeCacheNode *v15; // rax
  int v17; // [rsp+78h] [rbp+20h]

  v5 = pnode;
  v6 = pinsert;
  v7 = pparent;
  v8 = this;
  v9 = pnode->pRenderer;
  if ( v9 )
    goto LABEL_17;
  if ( pparent )
  {
    v10 = pparent->Flags & 0xC;
    if ( v10 == 12 )
    {
      v11 = 12;
      goto LABEL_8;
    }
  }
  else
  {
    v10 = 4;
  }
  v11 = this->Flags & 0xC;
  if ( !v11 )
    v11 = v10;
LABEL_8:
  v12 = v8->Flags;
  v13 = v11 | v8->Flags & 1;
  if ( ((unsigned __int8)v12 >> 5) & 1 )
    v13 |= 0x60u;
  if ( (v12 >> 9) & 1 )
    v13 |= 0x200u;
  v17 = 71;
  v14 = (Scaleform::Render::TreeCacheContainer *)Scaleform::Memory::pGlobalHeap->vfptr->AllocAutoHeap(
                                                   Scaleform::Memory::pGlobalHeap,
                                                   v7,
                                                   160ui64,
                                                   (Scaleform::AllocInfo *)&v17);
  if ( v14 )
  {
    Scaleform::Render::TreeCacheContainer::TreeCacheContainer(v14, v5, v7->pRenderer2D, v13);
    v9 = v15;
  }
  else
  {
    v9 = 0i64;
  }
  v5->pRenderer = v9;
  if ( !v9 )
    return 0i64;
LABEL_17:
  Scaleform::Render::TreeCacheNode::UpdateInsertIntoParent(
    v9,
    v7,
    v6,
    (Scaleform::Render::TreeNode::NodeData *)&v8->vfptr,
    depth);
  return v9;
}

// File Line: 1090
// RVA: 0x960D50
Scaleform::Render::ContextImpl::Entry *__fastcall Scaleform::Render::TreeContainer::NodeData::CloneCreate(Scaleform::Render::TreeContainer::NodeData *this, Scaleform::Render::ContextImpl::Context *context)
{
  Scaleform::Render::ContextImpl::Context *v2; // rdi
  Scaleform::Render::TreeContainer::NodeData *v3; // rsi
  Scaleform::Render::TreeNode::NodeData *v4; // rax
  Scaleform::Render::TreeNode::NodeData *v5; // rbx
  Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeNode::NodeData> src; // [rsp+50h] [rbp+8h]
  Scaleform::Render::TreeNode::NodeData *v8; // [rsp+58h] [rbp+10h]
  Scaleform::Render::TreeNode::NodeData *v9; // [rsp+60h] [rbp+18h]

  v2 = context;
  v3 = this;
  v4 = (Scaleform::Render::TreeNode::NodeData *)context->pHeap->vfptr->Alloc(context->pHeap, 160ui64, 0i64);
  v5 = v4;
  v8 = v4;
  v9 = v4;
  if ( v4 )
  {
    src.pC = (Scaleform::Render::TreeNode::NodeData *)&v3->vfptr;
    Scaleform::Render::TreeNode::NodeData::NodeData(
      v4,
      (Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeNode::NodeData>)&src);
    v5->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeContainer::NodeData,Scaleform::Render::TreeNode::NodeData>::`vftable;
    v5->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::TreeContainer::NodeData::`vftable;
    *(_QWORD *)&v5[1].Type = 0i64;
    v5[1].vfptr = 0i64;
  }
  return Scaleform::Render::ContextImpl::Context::createEntryHelper(
           v2,
           (Scaleform::Render::ContextImpl::EntryData *)&v5->vfptr);
}

// File Line: 1095
// RVA: 0x960EA0
bool __fastcall Scaleform::Render::TreeContainer::NodeData::CloneInit(Scaleform::Render::TreeContainer::NodeData *this, Scaleform::Render::TreeNode *node, Scaleform::Render::ContextImpl::Context *context)
{
  Scaleform::Render::ContextImpl::Context *v3; // r15
  Scaleform::Render::TreeContainer *v4; // r12
  Scaleform::Render::TreeContainer::NodeData *v5; // rsi
  bool result; // al
  unsigned __int64 *v7; // rsi
  unsigned __int64 v8; // rdi
  unsigned __int64 v9; // rbp
  unsigned __int64 v10; // rcx
  __int64 v11; // rcx
  __int64 v12; // r14
  Scaleform::Render::TreeNode *v13; // rbx
  bool v14; // zf

  v3 = context;
  v4 = (Scaleform::Render::TreeContainer *)node;
  v5 = this;
  result = Scaleform::Render::TreeNode::NodeData::CloneInit(
             (Scaleform::Render::TreeNode::NodeData *)&this->vfptr,
             node,
             context);
  if ( result )
  {
    v7 = (unsigned __int64 *)&v5->Children;
    v8 = 0i64;
    if ( *v7 )
    {
      if ( *(_BYTE *)v7 & 1 )
        v9 = *(_QWORD *)((*v7 & 0xFFFFFFFFFFFFFFFEui64) + 8);
      else
        v9 = (v7[1] != 0) + 1i64;
    }
    else
    {
      v9 = 0i64;
    }
    if ( v9 )
    {
      do
      {
        if ( *(_BYTE *)v7 & 1 )
          v10 = (*v7 & 0xFFFFFFFFFFFFFFFEui64) + 16;
        else
          v10 = (unsigned __int64)v7;
        v11 = *(_QWORD *)(v10 + 8 * v8);
        v12 = *(_QWORD *)(*(_QWORD *)((v11 & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                        + 8
                        * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)(v11
                                                                                              - (v11 & 0xFFFFFFFFFFFFF000ui64)
                                                                                              - 56)
                                                                             * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                         + ((unsigned __int64)((unsigned __int128)((signed __int64)(v11
                                                                                  - (v11 & 0xFFFFFFFFFFFFF000ui64)
                                                                                  - 56)
                                                                 * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                        + 40);
        v13 = (Scaleform::Render::TreeNode *)(*(__int64 (__fastcall **)(__int64, Scaleform::Render::ContextImpl::Context *))(*(_QWORD *)v12 + 64i64))(
                                               v12,
                                               v3);
        if ( v13 )
          (*(void (__fastcall **)(__int64, Scaleform::Render::TreeNode *, Scaleform::Render::ContextImpl::Context *))(*(_QWORD *)v12 + 72i64))(
            v12,
            v13,
            v3);
        Scaleform::Render::TreeContainer::Add(v4, v13);
        if ( v13 )
        {
          v14 = v13->RefCount-- == 1;
          if ( v14 )
            Scaleform::Render::ContextImpl::Entry::destroyHelper((Scaleform::Render::ContextImpl::Entry *)&v13->0);
        }
        ++v8;
      }
      while ( v8 < v9 );
    }
    result = 1;
  }
  return result;
}

// File Line: 1117
// RVA: 0x9B5C80
void __fastcall Scaleform::Render::TreeRoot::SetViewport(Scaleform::Render::TreeRoot *this, Scaleform::Render::Viewport *vp)
{
  Scaleform::Render::Viewport *v2; // rbx
  Scaleform::Render::Viewport *v3; // rax

  v2 = vp;
  if ( *(_OWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8
                             * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                                  * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                              + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                       - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                             + 40)
                 + 160i64) != *(_OWORD *)&vp->BufferWidth
    || *(_OWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8
                             * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                                  * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                              + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                       - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                             + 40)
                 + 176i64) != *(_OWORD *)&vp->Width
    || *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8
                             * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                                  * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                              + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                       - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                             + 40)
                 + 192i64) != *(_QWORD *)&vp->ScissorWidth
    || *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8
                             * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                                  * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                              + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                       - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                             + 40)
                 + 200i64) != vp->Flags )
  {
    v3 = (Scaleform::Render::Viewport *)Scaleform::Render::ContextImpl::Entry::getWritableData(
                                          (Scaleform::Render::ContextImpl::Entry *)&this->0,
                                          0x1000u);
    v3[3].ScissorTop = v2->BufferWidth;
    v3[3].ScissorWidth = v2->BufferHeight;
    v3[3].ScissorHeight = v2->Left;
    v3[3].Flags = v2->Top;
    v3[4].BufferWidth = v2->Width;
    v3[4].BufferHeight = v2->Height;
    v3[4].Left = v2->ScissorLeft;
    v3[4].Top = v2->ScissorTop;
    v3[4].Width = v2->ScissorWidth;
    v3[4].Height = v2->ScissorHeight;
    v3[4].ScissorLeft = v2->Flags;
  }
}

