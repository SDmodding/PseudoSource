// File Line: 52
// RVA: 0x6CAEB0
void __fastcall Scaleform::Render::TreeNode::NodeData::NodeData(
        Scaleform::Render::TreeNode::NodeData *this,
        Scaleform::Render::ContextImpl::EntryData::EntryType type)
{
  this->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::ContextImpl::EntryData::`vftable;
  this->Type = type;
  this->Flags = 1;
  this->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::TreeNode::NodeData::`vftable;
  memset(&this->M34, 0, sizeof(this->M34));
  this->M34.M[0][0] = 1.0;
  this->M34.M[1][1] = 1.0;
  this->M34.M[2][2] = 1.0;
  this->States.ArraySize = 0i64;
  this->States.DataValue = 0i64;
  Scaleform::Render::Cxform::Cxform(&this->Cx);
  *(_QWORD *)&this->AproxLocalBounds.x1 = 0i64;
  *(_QWORD *)&this->AproxLocalBounds.x2 = 0i64;
  *(_QWORD *)&this->AproxParentBounds.x1 = 0i64;
  *(_QWORD *)&this->AproxParentBounds.x2 = 0i64;
}

// File Line: 58
// RVA: 0x9400C0
void __fastcall Scaleform::Render::TreeNode::NodeData::NodeData(
        Scaleform::Render::TreeNode::NodeData *this,
        Scaleform::Render::ContextImpl::NonlocalCloneArg<Scaleform::Render::TreeNode::NodeData> src)
{
  Scaleform::Render::ContextImpl::EntryDataVtbl *vfptr; // rax
  Scaleform::Render::ContextImpl::EntryDataVtbl *v4; // rcx
  float v5; // xmm2_4
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm2_4
  float v9; // xmm1_4
  float v10; // xmm0_4

  vfptr = src.pC->vfptr;
  this->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::ContextImpl::EntryData::`vftable;
  this->Type = (unsigned __int16)vfptr->ConstructCopy;
  this->Flags = WORD1(vfptr->ConstructCopy) & 0xFFCF;
  this->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::TreeNode::NodeData::`vftable;
  this->M34 = *(Scaleform::Render::Matrix3x4<float> *)&src.pC->vfptr->CopyTo;
  this->States.ArraySize = 0i64;
  this->States.DataValue = 0i64;
  this->Cx = *(Scaleform::Render::Cxform *)&src.pC->vfptr[1].Destroy;
  v4 = src.pC->vfptr;
  v5 = *((float *)&src.pC->vfptr[2].ReleaseNodes + 1);
  v6 = *(float *)&src.pC->vfptr[2].ReleaseNodes;
  v7 = *((float *)&src.pC->vfptr[2].CopyTo + 1);
  this->AproxLocalBounds.x1 = *(float *)&src.pC->vfptr[2].CopyTo;
  this->AproxLocalBounds.y1 = v7;
  this->AproxLocalBounds.x2 = v6;
  this->AproxLocalBounds.y2 = v5;
  v8 = *((float *)&v4[2].PropagateUp + 1);
  v9 = *(float *)&v4[2].PropagateUp;
  v10 = *((float *)&v4[2].Destroy + 1);
  this->AproxParentBounds.x1 = *(float *)&v4[2].Destroy;
  this->AproxParentBounds.y1 = v10;
  this->AproxParentBounds.x2 = v9;
  this->AproxParentBounds.y2 = v8;
}

// File Line: 109
// RVA: 0x92CA50
Scaleform::Render::StateBag *__fastcall Scaleform::Render::TreeNode::NodeData::GetState<Scaleform::Render::ViewMatrix3DState>(
        Scaleform::Render::TreeNode::NodeData *this)
{
  Scaleform::Render::StateData::Interface *pInterface; // rdx
  Scaleform::Render::StateBag *p_States; // rcx
  __int64 v3; // r8
  __int64 v5; // rax
  __int64 v6; // r10
  unsigned __int64 v7; // rdx
  _QWORD *i; // rcx

  pInterface = this->States.pInterface;
  p_States = &this->States;
  v3 = 0i64;
  if ( !pInterface )
    return (Scaleform::Render::StateBag *)v3;
  if ( ((unsigned __int8)pInterface & 1) != 0 )
  {
    if ( ((unsigned __int64)pInterface & 0xFFFFFFFFFFFFFFFEui64) == qword_142451A68 )
      return p_States;
    return (Scaleform::Render::StateBag *)v3;
  }
  v5 = 0i64;
  v6 = p_States->DataValue + 4;
  v7 = (unsigned __int64)pInterface >> 1;
  if ( !v7 )
    return (Scaleform::Render::StateBag *)v3;
  for ( i = (_QWORD *)(p_States->DataValue + 4); *i != qword_142451A68; i += 2 )
  {
    if ( ++v5 >= v7 )
      return 0i64;
  }
  return (Scaleform::Render::StateBag *)(v6 + 16 * v5);
}

// File Line: 169
// RVA: 0x8E16C0
bool __fastcall Scaleform::Render::TreeNode::GetViewMatrix3D(
        Scaleform::Render::TreeNode *this,
        Scaleform::Render::Matrix3x4<float> *mat)
{
  Scaleform::Render::State *State; // rax
  float v4; // ebx
  float v5; // ebp
  float v6; // ecx
  float v7; // edx
  float v8; // r8d
  float v9; // r9d
  float v10; // r10d
  float v11; // r11d
  float v12; // esi
  float v13; // edi
  float v14; // r14d

  State = Scaleform::Render::TreeNode::GetState(this, State_ViewMatrix3D);
  if ( State )
  {
    State = (Scaleform::Render::State *)State->pData;
    v4 = *(float *)&State[2].pData;
    v5 = *((float *)&State[3].ArraySize + 1);
    v6 = *(float *)&State[1].pInterface;
    v7 = *((float *)&State[1].ArraySize + 1);
    v8 = *(float *)&State[1].pData;
    v9 = *((float *)&State[1].pArray + 1);
    v10 = *(float *)&State[2].pInterface;
    v11 = *((float *)&State[2].ArraySize + 1);
    v12 = *(float *)&State[3].pInterface;
    v13 = *((float *)&State[2].pArray + 1);
    v14 = *(float *)&State[3].pData;
    LODWORD(State) = HIDWORD(State[3].pArray);
    mat->M[0][0] = v6;
    mat->M[0][1] = v7;
    mat->M[0][2] = v8;
    mat->M[0][3] = v9;
    mat->M[1][0] = v10;
    mat->M[1][1] = v11;
    mat->M[1][2] = v4;
    mat->M[1][3] = v13;
    mat->M[2][0] = v12;
    mat->M[2][1] = v5;
    mat->M[2][2] = v14;
    LODWORD(mat->M[2][3]) = (_DWORD)State;
    LOBYTE(State) = 1;
  }
  return (char)State;
}

// File Line: 180
// RVA: 0x8DC550
bool __fastcall Scaleform::Render::TreeNode::GetProjectionMatrix3D(
        Scaleform::Render::TreeNode *this,
        Scaleform::Render::Matrix4x4<float> *mat)
{
  Scaleform::Render::State *State; // rax
  float v3; // ebx
  float v4; // ebp
  float v5; // edx
  float v6; // r8d
  float v7; // r9d
  float v8; // r10d
  float v9; // r11d
  float v10; // esi
  float v11; // edi
  float v12; // r12d
  float v13; // r13d
  float v14; // r14d
  float v15; // r15d
  float v17; // [rsp+20h] [rbp-48h]
  float v19; // [rsp+88h] [rbp+20h]

  State = Scaleform::Render::TreeNode::GetState(this, State_ProjectionMatrix3D);
  if ( State )
  {
    State = (Scaleform::Render::State *)State->pData;
    v3 = *(float *)&State[2].pData;
    v4 = *((float *)&State[3].ArraySize + 1);
    v5 = *((float *)&State[1].ArraySize + 1);
    v6 = *(float *)&State[1].pData;
    v7 = *((float *)&State[1].pArray + 1);
    v8 = *(float *)&State[2].pInterface;
    v9 = *((float *)&State[2].ArraySize + 1);
    v10 = *(float *)&State[3].pInterface;
    v11 = *((float *)&State[2].pArray + 1);
    v12 = *(float *)&State[4].pInterface;
    v13 = *((float *)&State[4].ArraySize + 1);
    v14 = *(float *)&State[3].pData;
    v15 = *((float *)&State[3].pArray + 1);
    v17 = *((float *)&State[4].pArray + 1);
    v19 = *(float *)&State[4].pData;
    mat->M[0][0] = *(float *)&State[1].pInterface;
    mat->M[0][1] = v5;
    mat->M[0][2] = v6;
    mat->M[0][3] = v7;
    mat->M[1][0] = v8;
    mat->M[1][1] = v9;
    mat->M[1][2] = v3;
    mat->M[1][3] = v11;
    mat->M[2][0] = v10;
    mat->M[2][1] = v4;
    mat->M[2][2] = v14;
    mat->M[2][3] = v15;
    mat->M[3][0] = v12;
    mat->M[3][1] = v13;
    mat->M[3][2] = v19;
    mat->M[3][3] = v17;
    LOBYTE(State) = 1;
  }
  return (char)State;
}

// File Line: 232
// RVA: 0x8DDED0
Scaleform::Render::Rect<float> *__fastcall Scaleform::Render::TreeNode::GetScale9Grid(
        Scaleform::Render::TreeNode *this,
        Scaleform::Render::Rect<float> *result)
{
  Scaleform::Render::State *State; // rax
  Scaleform::Render::Rect<float> v5; // [rsp+20h] [rbp-18h]

  State = Scaleform::Render::TreeNode::GetState(this, State_Scale9);
  if ( State )
    v5 = *(Scaleform::Render::Rect<float> *)(State->DataValue + 16);
  else
    v5 = 0i64;
  *result = v5;
  return result;
}

// File Line: 428
// RVA: 0x6D2860
void __fastcall Scaleform::Render::TreeNodeArray::~TreeNodeArray(Scaleform::Render::TreeNodeArray *this)
{
  if ( ((__int64)this->pNodes[0] & 1) != 0
    && !_InterlockedDecrement((volatile signed __int32 *)(this->pData[0] & 0xFFFFFFFFFFFFFFFEui64)) )
  {
    ((void (__fastcall *)(Scaleform::MemoryHeap *))Scaleform::Memory::pGlobalHeap->vfptr->Free)(Scaleform::Memory::pGlobalHeap);
  }
}

// File Line: 437
// RVA: 0x6F5450
__int64 __fastcall Scaleform::Render::TreeNodeArray::GetSize(Scaleform::Render::TreeNodeArray *this)
{
  __int64 result; // rax

  result = this->pData[0];
  if ( this->pData[0] )
  {
    if ( (result & 1) != 0 )
      return *(_QWORD *)((result & 0xFFFFFFFFFFFFFFFEui64) + 8);
    else
      return (this->pData[1] != 0) + 1i64;
  }
  return result;
}

// File Line: 528
// RVA: 0x6D78C0
bool __fastcall Scaleform::Render::TreeContainer::Add(
        Scaleform::Render::TreeContainer *this,
        Scaleform::Render::TreeNode *node)
{
  __int64 v3; // r8
  __int64 v4; // rdx

  v3 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                 + 40);
  v4 = *(_QWORD *)(v3 + 144);
  if ( !v4 )
    return Scaleform::Render::TreeContainer::Insert(this, 0i64, node);
  if ( (v4 & 1) != 0 )
    return Scaleform::Render::TreeContainer::Insert(this, *(_QWORD *)((v4 & 0xFFFFFFFFFFFFFFFEui64) + 8), node);
  return Scaleform::Render::TreeContainer::Insert(this, (*(_QWORD *)(v3 + 152) != 0i64) + 1i64, node);
}

// File Line: 532
// RVA: 0x7E5F70
Scaleform::Render::TreeNode *__fastcall Scaleform::Render::TreeContainer::GetAt(
        Scaleform::Render::TreeContainer *this,
        unsigned __int64 index)
{
  __int64 v2; // rax

  v2 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                 + 40);
  if ( (*(_BYTE *)(v2 + 144) & 1) != 0 )
    return *(Scaleform::Render::TreeNode **)((*(_QWORD *)(v2 + 144) & 0xFFFFFFFFFFFFFFFEui64) + 8 * index + 16);
  else
    return *(Scaleform::Render::TreeNode **)(v2 + 8 * index + 144);
}

// File Line: 536
// RVA: 0x6F53E0
__int64 __fastcall Scaleform::Render::TreeContainer::GetSize(Scaleform::Render::TreeContainer *this)
{
  __int64 v1; // rdx
  __int64 result; // rax

  v1 = *(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                 + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                 + 40);
  result = *(_QWORD *)(v1 + 144);
  if ( result )
  {
    if ( (result & 1) != 0 )
      return *(_QWORD *)((result & 0xFFFFFFFFFFFFFFFEui64) + 8);
    else
      return (*(_QWORD *)(v1 + 152) != 0i64) + 1i64;
  }
  return result;
}

// File Line: 563
// RVA: 0x89BFA0
void __fastcall Scaleform::Render::TreeRoot::NodeData::NodeData(Scaleform::Render::TreeRoot::NodeData *this)
{
  Scaleform::Render::TreeNode::NodeData::NodeData(this, ET_Root);
  this->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeContainer::NodeData,Scaleform::Render::TreeNode::NodeData>::`vftable;
  this->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::TreeContainer::NodeData::`vftable;
  this->Children.pData[1] = 0i64;
  this->Children.pData[0] = 0i64;
  this->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::ContextImpl::ContextData_ImplMixin<Scaleform::Render::TreeRoot::NodeData,Scaleform::Render::TreeContainer::NodeData>::`vftable;
  this->vfptr = (Scaleform::Render::ContextImpl::EntryDataVtbl *)&Scaleform::Render::TreeRoot::NodeData::`vftable;
  *(_QWORD *)&this->VP.BufferWidth = 0i64;
  *(_QWORD *)&this->VP.Left = 0i64;
  this->VP.Height = 1;
  this->VP.Width = 1;
  *(_QWORD *)&this->VP.ScissorWidth = 0i64;
  *(_QWORD *)&this->VP.ScissorLeft = 0i64;
  *(_QWORD *)&this->VP.Flags = 0i64;
}

// File Line: 596
// RVA: 0x9063C0
void __fastcall Scaleform::Render::TreeRoot::SetBackgroundColor(
        Scaleform::Render::TreeRoot *this,
        Scaleform::Render::Color *color)
{
  if ( *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(((unsigned __int64)this & 0xFFFFFFFFFFFFF000ui64) + 0x20)
                             + 8i64 * (unsigned int)((int)((_DWORD)this - ((unsigned int)this & 0xFFFFF000) - 56) / 56)
                             + 40)
                 + 204i64) != color->Raw )
    *(Scaleform::Render::Color *)(&Scaleform::Render::ContextImpl::Entry::getWritableData(this, 0x1000u)[12].Flags + 1) = *color;
}

