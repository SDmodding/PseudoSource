// File Line: 52
// RVA: 0x6CAEB0
void __fastcall Scaleform::Render::TreeNode::NodeData::NodeData(Scaleform::Render::TreeNode::NodeData *this, Scaleform::Render::ContextImpl::EntryData::EntryType type)
{
  Scaleform::Render::TreeNode::NodeData *v2; // rdi

  v2 = this;
  this->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::ContextImpl::EntryData::`vftable';
  this->Type = type;
  this->Flags = 1;
  this->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::TreeNode::NodeData::`vftable';
  memset(&this->M34, 0, 0x30ui64);
  v2->M34.M[0][0] = 1.0;
  v2->M34.M[1][1] = 1.0;
  v2->M34.M[2][2] = 1.0;
  v2->States.ArraySize = 0i64;
  v2->States.DataValue = 0i64;
  Scaleform::Render::Cxform::Cxform(&v2->Cx);
  *(_QWORD *)&v2->AproxLocalBounds.x1 = 0i64;
  *(_QWORD *)&v2->AproxLocalBounds.x2 = 0i64;
  *(_QWORD *)&v2->AproxParentBounds.x1 = 0i64;
  *(_QWORD *)&v2->AproxParentBounds.x2 = 0i64;
}

// File Line: 58
// RVA: 0x9400C0
void __fastcall Scaleform::Render::TreeNode::NodeData::NodeData(Scaleform::Render::TreeNode::NodeData *this, Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeNode::NodeData> src)
{
  Scaleform::Render::TreeNode::NodeData *v2; // r9
  Scaleform::Render::ContextImpl::EntryDataVtbl *v3; // rax
  Scaleform::Render::ContextImpl::EntryDataVtbl *v4; // rcx
  Scaleform::Render::ContextImpl::EntryDataVtbl *v5; // rax
  Scaleform::Render::ContextImpl::EntryDataVtbl *v6; // rcx
  float v7; // xmm2_4
  float v8; // xmm1_4
  float v9; // xmm0_4
  float v10; // xmm2_4
  float v11; // xmm1_4
  float v12; // xmm0_4

  v2 = this;
  v3 = src.pC->vfptr;
  this->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::ContextImpl::EntryData::`vftable';
  this->Type = (unsigned __int16)v3->ConstructCopy;
  this->Flags = WORD1(v3->ConstructCopy) & 0xFFCF;
  this->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::TreeNode::NodeData::`vftable';
  v4 = src.pC->vfptr;
  v2->M34.M[0][0] = *(float *)&src.pC->vfptr->CopyTo;
  v2->M34.M[0][1] = *((float *)&v4->CopyTo + 1);
  v2->M34.M[0][2] = *(float *)&v4->ReleaseNodes;
  v2->M34.M[0][3] = *((float *)&v4->ReleaseNodes + 1);
  v2->M34.M[1][0] = *(float *)&v4->Destroy;
  v2->M34.M[1][1] = *((float *)&v4->Destroy + 1);
  v2->M34.M[1][2] = *(float *)&v4->PropagateUp;
  v2->M34.M[1][3] = *((float *)&v4->PropagateUp + 1);
  v2->M34.M[2][0] = *(float *)&v4[1].__vecDelDtor;
  v2->M34.M[2][1] = *((float *)&v4[1].__vecDelDtor + 1);
  v2->M34.M[2][2] = *(float *)&v4[1].ConstructCopy;
  v2->M34.M[2][3] = *((float *)&v4[1].ConstructCopy + 1);
  v2->States.ArraySize = 0i64;
  v2->States.DataValue = 0i64;
  v5 = src.pC->vfptr;
  *(_OWORD *)&v2->Cx.M[0][0] = *(_OWORD *)&src.pC->vfptr[1].Destroy;
  *(_OWORD *)&v2->Cx.M[1][0] = *(_OWORD *)&v5[2].__vecDelDtor;
  v6 = src.pC->vfptr;
  v7 = *((float *)&src.pC->vfptr[2].ReleaseNodes + 1);
  v8 = *(float *)&src.pC->vfptr[2].ReleaseNodes;
  v9 = *((float *)&src.pC->vfptr[2].CopyTo + 1);
  v2->AproxLocalBounds.x1 = *(float *)&src.pC->vfptr[2].CopyTo;
  v2->AproxLocalBounds.y1 = v9;
  v2->AproxLocalBounds.x2 = v8;
  v2->AproxLocalBounds.y2 = v7;
  v10 = *((float *)&v6[2].PropagateUp + 1);
  v11 = *(float *)&v6[2].PropagateUp;
  v12 = *((float *)&v6[2].Destroy + 1);
  v2->AproxParentBounds.x1 = *(float *)&v6[2].Destroy;
  v2->AproxParentBounds.y1 = v12;
  v2->AproxParentBounds.x2 = v11;
  v2->AproxParentBounds.y2 = v10;
}

// File Line: 109
// RVA: 0x92CA50
Scaleform::Render::StateBag *__fastcall Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::ViewMatrix3DState>(Scaleform::Render::TreeNode::NodeData *this)
{
  Scaleform::Render::StateData::Interface *v1; // rdx
  Scaleform::Render::StateBag *v2; // rcx
  Scaleform::Render::StateBag *v3; // r8
  unsigned __int64 v5; // rax
  signed __int64 v6; // r10
  unsigned __int64 v7; // rdx
  _QWORD *v8; // rcx

  v1 = this->States.pInterface;
  v2 = &this->States;
  v3 = 0i64;
  if ( !v1 )
    return v3;
  if ( (unsigned __int8)v1 & 1 )
  {
    if ( ((unsigned __int64)v1 & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A68 )
      v3 = v2;
    return v3;
  }
  v5 = 0i64;
  v6 = v2->DataValue + 4;
  v7 = (unsigned __int64)v1 >> 1;
  if ( !v7 )
    return v3;
  v8 = (_QWORD *)(v2->DataValue + 4);
  while ( *v8 != qword_142451A68 )
  {
    ++v5;
    v8 += 2;
    if ( v5 >= v7 )
      return 0i64;
  }
  return (Scaleform::Render::StateBag *)(v6 + 16 * v5);
}

// File Line: 169
// RVA: 0x8E16C0
bool __fastcall Scaleform::Render::TreeNode::GetViewMatrix3D(Scaleform::Render::TreeNode *this, Scaleform::Render::Matrix3x4<float> *mat)
{
  Scaleform::Render::Matrix3x4<float> *v2; // r15
  Scaleform::Render::State *v3; // rax
  float v4; // ebx
  float v5; // ebp
  float v6; // ecx
  float v7; // edx
  float v8; // er8
  float v9; // er9
  float v10; // er10
  float v11; // er11
  float v12; // esi
  float v13; // edi
  float v14; // er14

  v2 = mat;
  v3 = Scaleform::Render::TreeNode::GetState(this, State_ViewMatrix3D);
  if ( v3 )
  {
    v3 = (Scaleform::Render::State *)v3->pData;
    v4 = *(float *)&v3[2].pData;
    v5 = *((float *)&v3[3].ArraySize + 1);
    v6 = *(float *)&v3[1].pInterface;
    v7 = *((float *)&v3[1].ArraySize + 1);
    v8 = *(float *)&v3[1].pData;
    v9 = *((float *)&v3[1].pArray + 1);
    v10 = *(float *)&v3[2].pInterface;
    v11 = *((float *)&v3[2].ArraySize + 1);
    v12 = *(float *)&v3[3].pInterface;
    v13 = *((float *)&v3[2].pArray + 1);
    v14 = *(float *)&v3[3].pData;
    LODWORD(v3) = HIDWORD(v3[3].pArray);
    v2->M[0][0] = v6;
    v2->M[0][1] = v7;
    v2->M[0][2] = v8;
    v2->M[0][3] = v9;
    v2->M[1][0] = v10;
    v2->M[1][1] = v11;
    v2->M[1][2] = v4;
    v2->M[1][3] = v13;
    v2->M[2][0] = v12;
    v2->M[2][1] = v5;
    v2->M[2][2] = v14;
    LODWORD(v2->M[2][3]) = (_DWORD)v3;
    LOBYTE(v3) = 1;
  }
  return (char)v3;
}

// File Line: 180
// RVA: 0x8DC550
bool __fastcall Scaleform::Render::TreeNode::GetProjectionMatrix3D(Scaleform::Render::TreeNode *this, Scaleform::Render::Matrix4x4<float> *mat)
{
  Scaleform::Render::State *v2; // rax
  float v3; // ebx
  float v4; // ebp
  float v5; // edx
  float v6; // er8
  float v7; // er9
  float v8; // er10
  float v9; // er11
  float v10; // esi
  float v11; // edi
  float v12; // er12
  float v13; // er13
  float v14; // er14
  float v15; // er15
  float v16; // ecx
  float v17; // ST20_4
  Scaleform::Render::Matrix4x4<float> *v19; // [rsp+78h] [rbp+10h]

  v19 = mat;
  v2 = Scaleform::Render::TreeNode::GetState(this, State_ProjectionMatrix3D);
  if ( v2 )
  {
    v2 = (Scaleform::Render::State *)v2->pData;
    v3 = *(float *)&v2[2].pData;
    v4 = *((float *)&v2[3].ArraySize + 1);
    v5 = *((float *)&v2[1].ArraySize + 1);
    v6 = *(float *)&v2[1].pData;
    v7 = *((float *)&v2[1].pArray + 1);
    v8 = *(float *)&v2[2].pInterface;
    v9 = *((float *)&v2[2].ArraySize + 1);
    v10 = *(float *)&v2[3].pInterface;
    v11 = *((float *)&v2[2].pArray + 1);
    v12 = *(float *)&v2[4].pInterface;
    v13 = *((float *)&v2[4].ArraySize + 1);
    v14 = *(float *)&v2[3].pData;
    v15 = *((float *)&v2[3].pArray + 1);
    v16 = *(float *)&v2[4].pData;
    v17 = *((float *)&v2[4].pArray + 1);
    v19->M[0][0] = *(float *)&v2[1].pInterface;
    v19->M[0][1] = v5;
    v19->M[0][2] = v6;
    v19->M[0][3] = v7;
    v19->M[1][0] = v8;
    v19->M[1][1] = v9;
    v19->M[1][2] = v3;
    v19->M[1][3] = v11;
    v19->M[2][0] = v10;
    v19->M[2][1] = v4;
    v19->M[2][2] = v14;
    v19->M[2][3] = v15;
    v19->M[3][0] = v12;
    v19->M[3][1] = v13;
    v19->M[3][2] = v16;
    v19->M[3][3] = v17;
    LOBYTE(v2) = 1;
  }
  return (char)v2;
}

// File Line: 232
// RVA: 0x8DDED0
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::TreeNode::GetScale9Grid(Scaleform::Render::TreeNode *this, Scaleform::Render::Rect<float> *result)
{
  Scaleform::Render::Rect<float> *v2; // rbx
  Scaleform::Render::State *v3; // rax
  Scaleform::Render::Rect<float> v5; // [rsp+20h] [rbp-18h]

  v2 = result;
  v3 = Scaleform::Render::TreeNode::GetState(this, State_Scale9);
  if ( v3 )
    v5 = *(Scaleform::Render::Rect<float> *)(v3->DataValue + 16);
  else
    v5 = 0i64;
  *v2 = v5;
  return v2;
}

// File Line: 428
// RVA: 0x6D2860
void __fastcall Scaleform::Render::TreeNodeArray::~TreeNodeArray(Scaleform::Render::TreeNodeArray *this)
{
  if ( (_QWORD)this->pNodes[0] & 1 )
  {
    if ( !_InterlockedDecrement((volatile signed __int32 *)(this->pData[0] & 0xFFFFFFFFFFFFFFFEui64)) )
      ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
  }
}

// File Line: 437
// RVA: 0x6F5450
signed __int64 __fastcall Scaleform::Render::TreeNodeArray::GetSize(Scaleform::Render::TreeNodeArray *this)
{
  signed __int64 result; // rax

  result = this->pData[0];
  if ( this->pData[0] )
  {
    if ( result & 1 )
      result = *(_QWORD *)((result & 0xFFFFFFFFFFFFFFFEui64) + 8);
    else
      result = (this->pData[1] != 0) + 1i64;
  }
  return result;
}

// File Line: 528
// RVA: 0x6D78C0
bool __fastcall Scaleform::Render::TreeContainer::Add(Scaleform::Render::TreeContainer *this, Scaleform::Render::TreeNode *node)
{
  Scaleform::Render::TreeNode *v2; // r11
  __int64 v3; // r8
  __int64 v4; // rdx

  v2 = node;
  v3 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8
                 * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                       - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                  + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                           - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                 + 40);
  v4 = *(_QWORD *)(v3 + 144);
  if ( !v4 )
    return Scaleform::Render::TreeContainer::Insert(this, 0i64, v2);
  if ( v4 & 1 )
    return Scaleform::Render::TreeContainer::Insert(this, *(_QWORD *)((v4 & 0xFFFFFFFFFFFFFFFEui64) + 8), v2);
  return Scaleform::Render::TreeContainer::Insert(this, (*(_QWORD *)(v3 + 152) != 0i64) + 1i64, v2);
}

// File Line: 532
// RVA: 0x7E5F70
Scaleform::Render::TreeNode *__fastcall Scaleform::Render::TreeContainer::GetAt(Scaleform::Render::TreeContainer *this, unsigned __int64 index)
{
  __int64 v2; // rax
  Scaleform::Render::TreeNode *result; // rax

  v2 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8
                 * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                       - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                  + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                           - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                 + 40);
  if ( *(_BYTE *)(v2 + 144) & 1 )
    result = *(Scaleform::Render::TreeNode **)((*(_QWORD *)(v2 + 144) & 0xFFFFFFFFFFFFFFFEui64) + 8 * index + 16);
  else
    result = *(Scaleform::Render::TreeNode **)(v2 + 8 * index + 144);
  return result;
}

// File Line: 536
// RVA: 0x6F53E0
signed __int64 __fastcall Scaleform::Render::TreeContainer::GetSize(Scaleform::Render::TreeContainer *this)
{
  __int64 v1; // rdx
  signed __int64 result; // rax

  v1 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8
                 * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                       - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                  + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                           - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                          * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                 + 40);
  result = *(_QWORD *)(v1 + 144);
  if ( result )
  {
    if ( result & 1 )
      result = *(_QWORD *)((result & 0xFFFFFFFFFFFFFFFEui64) + 8);
    else
      result = (*(_QWORD *)(v1 + 152) != 0i64) + 1i64;
  }
  return result;
}

// File Line: 563
// RVA: 0x89BFA0
void __fastcall Scaleform::Render::TreeRoot::NodeData::NodeData(Scaleform::Render::TreeRoot::NodeData *this)
{
  Scaleform::Render::TreeRoot::NodeData *v1; // rbx

  v1 = this;
  Scaleform::Render::TreeNode::NodeData::NodeData((Scaleform::Render::TreeNode::NodeData *)&this->vfptr, ET_Root);
  v1->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeContainer::NodeData,Scaleform::Render::TreeNode::NodeData>::`vftable';
  v1->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::TreeContainer::NodeData::`vftable';
  v1->Children.pData[1] = 0i64;
  v1->Children.pData[0] = 0i64;
  v1->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeRoot::NodeData,Scaleform::Render::TreeContainer::NodeData>::`vftable';
  v1->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::TreeRoot::NodeData::`vftable';
  *(_QWORD *)&v1->VP.BufferWidth = 0i64;
  *(_QWORD *)&v1->VP.Left = 0i64;
  v1->VP.Height = 1;
  v1->VP.Width = 1;
  *(_QWORD *)&v1->VP.ScissorWidth = 0i64;
  *(_QWORD *)&v1->VP.ScissorLeft = 0i64;
  *(_QWORD *)&v1->VP.Flags = 0i64;
}

// File Line: 596
// RVA: 0x9063C0
void __fastcall Scaleform::Render::TreeRoot::SetBackgroundColor(Scaleform::Render::TreeRoot *this, Scaleform::Render::Color *color)
{
  if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8
                             * ((unsigned int)((signed __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1] - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                                  * (signed __int128)5270498306774157605i64) >> 64) >> 4)
                              + ((unsigned __int64)((unsigned __int128)((signed __int64)((signed __int64)&this[-1]
                                                                                       - ((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64))
                                                                      * (signed __int128)5270498306774157605i64) >> 64) >> 63))
                             + 40)
                 + 204i64) != color->Raw )
    *(Scaleform::Render::Color *)(&Scaleform::Render::ContextImpl::Entry::getWritableData(
                                     (Scaleform::Render::ContextImpl::Entry *)&this->0,
                                     0x1000u)[12].Flags
                                + 1) = *color;
}

