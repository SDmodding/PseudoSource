// File Line: 24
// RVA: 0x14B2E90
__int64 UFG::_dynamic_initializer_for__gAISidewalkInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    &UFG::gAISidewalkInventory,
    "SidewalkInventory",
    0x43E99F7Eu,
    0x2C81C14Bu,
    0,
    0);
  UFG::gAISidewalkInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::AISidewalkInventory::`vftable;
  return atexit((int (__fastcall *)())UFG::_dynamic_atexit_destructor_for__gAISidewalkInventory__);
}

// File Line: 177
// RVA: 0x399630
void __fastcall UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::_Set(
        UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *this,
        unsigned int objUID,
        unsigned int cellUID,
        unsigned __int16 index)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v9; // rax
  UFG::qResourceInventory *v10; // rax
  UFG::qResourceWarehouse *v11; // rax

  this->mPtr = 0i64;
  Inventory = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
  {
    v9 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v9, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(this, Inventory);
  this->mIndex = index;
  this->mObjUID = objUID;
  v10 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
  {
    v11 = UFG::qResourceWarehouse::Instance();
    v10 = UFG::qResourceWarehouse::GetInventory(v11, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v10;
  }
  UFG::qResourceHandle::Init(this, 0x43E99F7Eu, cellUID, v10);
}

// File Line: 188
// RVA: 0x399580
void __fastcall UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game>::_Set(
        UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *this,
        unsigned int objUID,
        unsigned int cellUID)
{
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v7; // rax
  UFG::qResourceInventory *v8; // rax
  UFG::qResourceWarehouse *v9; // rax

  this->mPtr = 0i64;
  Inventory = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    Inventory = UFG::qResourceWarehouse::GetInventory(v7, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = Inventory;
  }
  UFG::qResourceHandle::Close(this, Inventory);
  this->mObjUID = objUID;
  this->mIndex = -1;
  v8 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
  {
    v9 = UFG::qResourceWarehouse::Instance();
    v8 = UFG::qResourceWarehouse::GetInventory(v9, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v8;
  }
  UFG::qResourceHandle::Init(this, 0x43E99F7Eu, cellUID, v8);
}

// File Line: 295
// RVA: 0x32BE80
void __fastcall UFG::AISidewalkSectionResource::AISidewalkSectionResource(UFG::AISidewalkSectionResource *this)
{
  unsigned int i; // edi
  __int64 mOffset; // rax
  char *v4; // rdx
  UFG::qResourceHandle *v5; // rcx
  unsigned int j; // edi
  __int64 v7; // rax
  char *v8; // rdx
  UFG::qResourceHandle *v9; // rcx

  UFG::qResourceData::qResourceData(this);
  for ( i = 0; i < this->mNodeHandleCount; ++i )
  {
    mOffset = this->mNodeHandles.mOffset;
    if ( mOffset )
      v4 = (char *)&this->mNodeHandles + mOffset;
    else
      v4 = 0i64;
    v5 = (UFG::qResourceHandle *)&v4[48 * i];
    if ( v5 )
      UFG::qResourceHandle::qResourceHandle(v5);
  }
  for ( j = 0; j < this->mEdgeHandleCount; ++j )
  {
    v7 = this->mEdgeHandles.mOffset;
    if ( v7 )
      v8 = (char *)&this->mEdgeHandles + v7;
    else
      v8 = 0i64;
    v9 = (UFG::qResourceHandle *)&v8[48 * j];
    if ( v9 )
      UFG::qResourceHandle::qResourceHandle(v9);
  }
}

// File Line: 344
// RVA: 0x368770
void __fastcall UFG::AISidewalkSectionResource::InitHandles(UFG::AISidewalkSectionResource *this)
{
  unsigned int i; // edi
  __int64 mOffset; // rax
  char *v4; // rcx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceHandle *v6; // rbx
  UFG::qResourceWarehouse *v7; // rax
  unsigned int j; // edi
  __int64 v9; // rax
  char *v10; // rcx
  UFG::qResourceInventory *v11; // rax
  UFG::qResourceHandle *v12; // rbx
  UFG::qResourceWarehouse *v13; // rax

  for ( i = 0; i < this->mNodeHandleCount; ++i )
  {
    mOffset = this->mNodeHandles.mOffset;
    if ( mOffset )
      v4 = (char *)&this->mNodeHandles + mOffset;
    else
      v4 = 0i64;
    Inventory = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
    v6 = (UFG::qResourceHandle *)&v4[48 * i];
    if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
    {
      v7 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v7, 0x43E99F7Eu);
      `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Init(v6, 0x43E99F7Eu, v6->mNameUID, Inventory);
  }
  for ( j = 0; j < this->mEdgeHandleCount; ++j )
  {
    v9 = this->mEdgeHandles.mOffset;
    if ( v9 )
      v10 = (char *)&this->mEdgeHandles + v9;
    else
      v10 = 0i64;
    v11 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
    v12 = (UFG::qResourceHandle *)&v10[48 * j];
    if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
    {
      v13 = UFG::qResourceWarehouse::Instance();
      v11 = UFG::qResourceWarehouse::GetInventory(v13, 0x43E99F7Eu);
      `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v11;
    }
    UFG::qResourceHandle::Init(v12, 0x43E99F7Eu, v12->mNameUID, v11);
  }
}

// File Line: 361
// RVA: 0x34F7F0
void __fastcall UFG::AISidewalkSectionResource::CloseHandles(UFG::AISidewalkSectionResource *this)
{
  unsigned int i; // edi
  __int64 mOffset; // rax
  char *v4; // rcx
  UFG::qResourceHandle *v5; // rbx
  UFG::qResourceInventory *Inventory; // rax
  UFG::qResourceWarehouse *v7; // rax
  unsigned int j; // edi
  __int64 v9; // rax
  char *v10; // rcx
  UFG::qResourceHandle *v11; // rbx
  UFG::qResourceInventory *v12; // rax
  UFG::qResourceWarehouse *v13; // rax

  for ( i = 0; i < this->mNodeHandleCount; ++i )
  {
    mOffset = this->mNodeHandles.mOffset;
    if ( mOffset )
      v4 = (char *)&this->mNodeHandles + mOffset;
    else
      v4 = 0i64;
    v5 = (UFG::qResourceHandle *)&v4[48 * i];
    v5[1].mNext = 0i64;
    Inventory = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
    if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
    {
      v7 = UFG::qResourceWarehouse::Instance();
      Inventory = UFG::qResourceWarehouse::GetInventory(v7, 0x43E99F7Eu);
      `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = Inventory;
    }
    UFG::qResourceHandle::Close(v5, Inventory);
  }
  for ( j = 0; j < this->mEdgeHandleCount; ++j )
  {
    v9 = this->mEdgeHandles.mOffset;
    if ( v9 )
      v10 = (char *)&this->mEdgeHandles + v9;
    else
      v10 = 0i64;
    v11 = (UFG::qResourceHandle *)&v10[48 * j];
    v11[1].mNext = 0i64;
    v12 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result;
    if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result )
    {
      v13 = UFG::qResourceWarehouse::Instance();
      v12 = UFG::qResourceWarehouse::GetInventory(v13, 0x43E99F7Eu);
      `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>::`2::result = v12;
    }
    UFG::qResourceHandle::Close(v11, v12);
  }
}

// File Line: 463
// RVA: 0x33FB00
void __fastcall UFG::AISidewalkInventory::Add(
        UFG::AISidewalkInventory *this,
        UFG::AISidewalkSectionResource *resource_data)
{
  unsigned int i; // r15d
  UFG::qBaseNodeRB *mOffset; // rax
  char *v6; // rsi
  unsigned int v7; // ebx
  char *v8; // rdi
  char *v9; // rcx
  char *v10; // rdx
  char *v11; // rdx
  UFG::AISidewalkEdge_Game *v12; // rdx
  __int64 v13; // rax
  char *v14; // rcx
  __int64 v15; // rcx
  __int64 v16; // r8
  float **v17; // r8
  float **v18; // rax

  if ( resource_data )
    UFG::AISidewalkSectionResource::AISidewalkSectionResource(resource_data);
  UFG::qResourceInventory::Add(this, resource_data);
  UFG::AISidewalkSectionResource::InitHandles(resource_data);
  UFG::AISidewalkGraph::HandleAlteredDataOnAdd(resource_data);
  for ( i = 0; i < resource_data->mNodeCount; ++i )
  {
    mOffset = (UFG::qBaseNodeRB *)resource_data->mNodes.mOffset;
    if ( mOffset )
      v6 = (char *)&resource_data->mNodes + (_QWORD)mOffset;
    else
      v6 = 0i64;
    ++foo_zzzzzz;
    v7 = 0;
    if ( *(_WORD *)&v6[40 * i + 32] )
    {
      v8 = &v6[40 * i + 24];
      do
      {
        v9 = &v8[*(_QWORD *)v8];
        if ( !*(_QWORD *)v8 )
          v9 = 0i64;
        v10 = &v9[8 * v7];
        if ( *(_QWORD *)v10 )
          v11 = &v10[*(_QWORD *)v10];
        else
          v11 = 0i64;
        v12 = (UFG::AISidewalkEdge_Game *)*((_QWORD *)v11 + 5);
        if ( v12 )
        {
          v13 = v12->mpStartNodeHandle.mOffset;
          v14 = (char *)v12 + v12->mpStartNodeHandle.mOffset;
          if ( !v12->mpStartNodeHandle.mOffset )
            v14 = 0i64;
          if ( *((_QWORD *)v14 + 5) )
          {
            v15 = v12->mpEndNodeHandle.mOffset;
            v16 = v15 ? (__int64)&v12->mpEndNodeHandle + v15 : 0i64;
            if ( *(_QWORD *)(v16 + 40) )
            {
              v17 = (float **)((char *)v12 + v13);
              if ( !v13 )
                v17 = 0i64;
              if ( v15 )
                v18 = (float **)((char *)&v12->mpEndNodeHandle + v15);
              else
                v18 = 0i64;
              UFG::Grid<UFG::AISidewalkEdge_Game>::AddAlongSegment(
                gAISidewalkEdgeDataGrid,
                v12,
                *v17[5],
                v17[5][1],
                *v18[5],
                v18[5][1]);
            }
          }
        }
        ++v7;
      }
      while ( v7 < *(unsigned __int16 *)&v6[40 * i + 32] );
    }
  }
}

// File Line: 491
// RVA: 0x380CF0
void __fastcall UFG::AISidewalkInventory::Remove(
        UFG::AISidewalkInventory *this,
        UFG::AISidewalkSectionResource *resource_data)
{
  unsigned int i; // ebx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mOffset; // rax
  char *v6; // rdx
  UFG::AISidewalkEdge_Game *v7; // rdx
  __int64 v8; // rcx
  char *v9; // rax
  __int64 v10; // rax
  __int64 v11; // r8
  float **v12; // r8
  float **v13; // rax
  UFG::qNode<UFG::SidewalkAlteredNodeData,UFG::SidewalkAlteredNodeData> *mNext; // rcx
  UFG::qList<UFG::SidewalkAlteredNodeData,UFG::SidewalkAlteredNodeData,1,0> *v15; // rdx
  UFG::qNode<UFG::SidewalkAlteredNodeData,UFG::SidewalkAlteredNodeData> *v16; // r8
  unsigned int j; // r15d
  UFG::qBaseNodeRB *v18; // rax
  char *v19; // rbp
  unsigned int v20; // ebx
  char *v21; // rdi
  char *v22; // rcx
  char *v23; // rdx
  char *v24; // rdx
  UFG::AISidewalkEdge_Game *v25; // rdx
  __int64 v26; // rax
  char *v27; // rcx
  __int64 v28; // rcx
  __int64 v29; // r8
  float **v30; // r8
  float **v31; // rax
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *p_mResourceHandles; // rdi
  UFG::qResourceHandle *v33; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v35; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v36; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v37; // rax

  for ( i = 0; i < resource_data->mEdgeCount; ++i )
  {
    mOffset = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)resource_data->mEdges.mOffset;
    if ( mOffset )
      v6 = (char *)&resource_data->mEdges + (_QWORD)mOffset;
    else
      v6 = 0i64;
    v7 = (UFG::AISidewalkEdge_Game *)&v6[80 * i];
    v8 = v7->mpStartNodeHandle.mOffset;
    v9 = (char *)v7 + v7->mpStartNodeHandle.mOffset;
    if ( !v7->mpStartNodeHandle.mOffset )
      v9 = 0i64;
    if ( *((_QWORD *)v9 + 5) )
    {
      v10 = v7->mpEndNodeHandle.mOffset;
      v11 = v10 ? (__int64)&v7->mpEndNodeHandle + v10 : 0i64;
      if ( *(_QWORD *)(v11 + 40) )
      {
        v12 = (float **)((char *)v7 + v8);
        if ( !v8 )
          v12 = 0i64;
        if ( v10 )
          v13 = (float **)((char *)&v7->mpEndNodeHandle + v10);
        else
          v13 = 0i64;
        UFG::Grid<UFG::AISidewalkEdge_Game>::RemoveAlongSegment(
          gAISidewalkEdgeDataGrid,
          v7,
          *v12[5],
          v12[5][1],
          *v13[5],
          v13[5][1]);
      }
    }
  }
  mNext = UFG::AISidewalkGraph::sAlteredNodeData.mNode.mNext;
  if ( (UFG::qList<UFG::SidewalkAlteredNodeData,UFG::SidewalkAlteredNodeData,1,0> *)UFG::AISidewalkGraph::sAlteredNodeData.mNode.mNext != &UFG::AISidewalkGraph::sAlteredNodeData )
  {
    do
    {
      v15 = (UFG::qList<UFG::SidewalkAlteredNodeData,UFG::SidewalkAlteredNodeData,1,0> *)mNext->mNext;
      v16 = mNext[3].mNext;
      if ( v16 && LODWORD(mNext[2].mNext) == resource_data->mSectionVisId )
        WORD1(v16[2].mPrev) = BYTE6(mNext[4].mPrev);
      mNext = &v15->mNode;
    }
    while ( v15 != &UFG::AISidewalkGraph::sAlteredNodeData );
  }
  for ( j = 0; j < resource_data->mNodeCount; ++j )
  {
    v18 = (UFG::qBaseNodeRB *)resource_data->mNodes.mOffset;
    if ( v18 )
      v19 = (char *)&resource_data->mNodes + (_QWORD)v18;
    else
      v19 = 0i64;
    v20 = 0;
    if ( *(_WORD *)&v19[40 * j + 32] )
    {
      v21 = &v19[40 * j + 24];
      do
      {
        v22 = &v21[*(_QWORD *)v21];
        if ( !*(_QWORD *)v21 )
          v22 = 0i64;
        v23 = &v22[8 * v20];
        if ( *(_QWORD *)v23 )
          v24 = &v23[*(_QWORD *)v23];
        else
          v24 = 0i64;
        if ( *((unsigned __int16 *)v24 + 16) != -1 || *((_DWORD *)v24 + 9) != -1 )
        {
          v25 = (UFG::AISidewalkEdge_Game *)*((_QWORD *)v24 + 5);
          if ( v25 )
          {
            v26 = v25->mpStartNodeHandle.mOffset;
            v27 = (char *)v25 + v25->mpStartNodeHandle.mOffset;
            if ( !v25->mpStartNodeHandle.mOffset )
              v27 = 0i64;
            if ( *((_QWORD *)v27 + 5) )
            {
              v28 = v25->mpEndNodeHandle.mOffset;
              v29 = v28 ? (__int64)&v25->mpEndNodeHandle + v28 : 0i64;
              if ( *(_QWORD *)(v29 + 40) )
              {
                v30 = (float **)((char *)v25 + v26);
                if ( !v26 )
                  v30 = 0i64;
                if ( v28 )
                  v31 = (float **)((char *)&v25->mpEndNodeHandle + v28);
                else
                  v31 = 0i64;
                UFG::Grid<UFG::AISidewalkEdge_Game>::RemoveAlongSegment(
                  gAISidewalkEdgeDataGrid,
                  v25,
                  *v30[5],
                  v30[5][1],
                  *v31[5],
                  v31[5][1]);
              }
            }
          }
        }
        ++v20;
      }
      while ( v20 < *(unsigned __int16 *)&v19[40 * j + 32] );
    }
  }
  UFG::AISidewalkSectionResource::CloseHandles(resource_data);
  UFG::qResourceInventory::Remove(this, resource_data);
  p_mResourceHandles = &resource_data->mResourceHandles;
  v33 = (UFG::qResourceHandle *)resource_data->mResourceHandles.UFG::qResourceData::mNode.mNext;
  if ( v33 != (UFG::qResourceHandle *)&resource_data->mResourceHandles )
  {
    do
    {
      mPrev = v33->mPrev;
      v35 = v33->mNext;
      mPrev->mNext = v35;
      v35->mPrev = mPrev;
      v33->mPrev = v33;
      v33->mNext = v33;
      UFG::qResourceHandle::~qResourceHandle(v33);
      operator delete[](v33);
      v33 = (UFG::qResourceHandle *)resource_data->mResourceHandles.UFG::qResourceData::mNode.mNext;
    }
    while ( v33 != (UFG::qResourceHandle *)p_mResourceHandles );
  }
  v36 = p_mResourceHandles->mNode.mPrev;
  v37 = resource_data->mResourceHandles.UFG::qResourceData::mNode.mNext;
  v36->mNext = v37;
  v37->mPrev = v36;
  p_mResourceHandles->mNode.mPrev = &p_mResourceHandles->mNode;
  resource_data->mResourceHandles.UFG::qResourceData::mNode.mNext = &resource_data->mResourceHandles.UFG::qResourceData::mNode;
}

// File Line: 518
// RVA: 0x379510
void __fastcall UFG::AISidewalkInventory::OnAttachHandle(
        UFG::AISidewalkInventory *this,
        UFG::qResourceHandle *handle,
        UFG::qResourceData *resource_data)
{
  int mPrev_high; // edi
  __int64 mPrev_low; // rax
  char *v5; // r9
  unsigned int v8; // r11d
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // r8
  __int64 v10; // rdx
  char *v11; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v12; // rcx
  unsigned int v13; // r11d
  UFG::qBaseNodeRB *v14; // r8
  __int64 v15; // rdx
  char *v16; // rcx
  UFG::qBaseNodeRB *v17; // rcx

  mPrev_high = HIDWORD(handle[1].mPrev);
  mPrev_low = LOWORD(handle[1].mPrev);
  v5 = 0i64;
  if ( WORD1(handle[1].mPrev) )
  {
    if ( (_DWORD)mPrev_low == 0xFFFF )
    {
      v8 = HIDWORD(resource_data[1].mNode.mChild[0]);
      mPrev_low = 0i64;
      if ( v8 )
      {
        mPrev = resource_data[1].mResourceHandles.mNode.mPrev;
        v10 = 0i64;
        while ( 1 )
        {
          v11 = mPrev ? (char *)&resource_data[1].mResourceHandles + (_QWORD)mPrev : 0i64;
          if ( *(_DWORD *)&v11[v10 + 16] == mPrev_high )
            break;
          mPrev_low = (unsigned int)(mPrev_low + 1);
          v10 += 80i64;
          if ( (unsigned int)mPrev_low >= v8 )
            goto LABEL_10;
        }
      }
      else
      {
LABEL_10:
        mPrev_low = 0xFFFFFFFFi64;
      }
      LOWORD(handle[1].mPrev) = mPrev_low;
    }
    v12 = resource_data[1].mResourceHandles.mNode.mPrev;
    if ( v12 )
      v5 = (char *)&resource_data[1].mResourceHandles + (_QWORD)v12;
    handle[1].mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v5[80 * mPrev_low];
  }
  else
  {
    if ( (_DWORD)mPrev_low == 0xFFFF )
    {
      v13 = (unsigned int)resource_data[1].mNode.mChild[0];
      mPrev_low = 0i64;
      if ( v13 )
      {
        v14 = resource_data[1].mNode.mChild[1];
        v15 = 0i64;
        while ( 1 )
        {
          v16 = v14 ? (char *)&resource_data[1].mNode.mChild[1] + (_QWORD)v14 : 0i64;
          if ( *(_DWORD *)&v16[v15 + 12] == mPrev_high )
            break;
          mPrev_low = (unsigned int)(mPrev_low + 1);
          v15 += 40i64;
          if ( (unsigned int)mPrev_low >= v13 )
            goto LABEL_23;
        }
      }
      else
      {
LABEL_23:
        mPrev_low = 0xFFFFFFFFi64;
      }
      LOWORD(handle[1].mPrev) = mPrev_low;
    }
    v17 = resource_data[1].mNode.mChild[1];
    if ( v17 )
      v5 = (char *)&resource_data[1].mNode.mChild[1] + (_QWORD)v17;
    handle[1].mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v5[40 * mPrev_low];
  }
}

// File Line: 552
// RVA: 0x37B310
void __fastcall UFG::AISidewalkInventory::OnDetachHandle(
        UFG::AISidewalkInventory *this,
        UFG::qResourceHandle *handle,
        UFG::qResourceData *resource_data)
{
  handle[1].mNext = 0i64;
}

// File Line: 648
// RVA: 0x35FC50
UFG::AISidewalkNode_Game *__fastcall UFG::AISidewalkNode_Game::GetFromObjUID_Slow(unsigned int objUID)
{
  Render::SkinningCacheNode *Head; // rdi
  char *v3; // rbx
  UFG::qBaseTreeRB *Next; // rax
  unsigned int mChild1; // r9d
  unsigned int v6; // edx
  UFG::qBaseTreeRB *v7; // r10
  unsigned __int64 mUID; // r8
  __int64 v9; // rcx
  __int64 v10; // rax

  Head = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_1423BAAD0);
  if ( !Head )
    return 0i64;
  v3 = 0i64;
  while ( 1 )
  {
    Next = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_1423BAAD0, (UFG::qBaseNodeRB *)Head);
    mChild1 = (unsigned int)Head[2].mNode.mChild1;
    v6 = 0;
    v7 = Next;
    if ( mChild1 )
      break;
LABEL_10:
    Head = (Render::SkinningCacheNode *)v7;
    if ( !v7 )
      return 0i64;
  }
  mUID = Head[2].mNode.mUID;
  v9 = 0i64;
  while ( 1 )
  {
    v10 = mUID ? (__int64)&Head[2].mNode.mUID + mUID : 0i64;
    if ( *(_DWORD *)(v9 + v10 + 12) == objUID )
      break;
    ++v6;
    v9 += 40i64;
    if ( v6 >= mChild1 )
      goto LABEL_10;
  }
  if ( mUID )
    v3 = (char *)&Head[2].mNode.mUID + mUID;
  return (UFG::AISidewalkNode_Game *)&v3[40 * v6];
}

// File Line: 822
// RVA: 0x14AECF0
void UFG::_dynamic_initializer_for__ANGLE_THRESHOLD__()
{
  UFG::ANGLE_THRESHOLD = cosf(1.5681783);
}

// File Line: 1043
// RVA: 0x3626C0
UFG::AISidewalkNode_Game *__fastcall UFG::AISidewalkEdge_Game::GetStartNode(UFG::AISidewalkEdge_Game *this)
{
  if ( this->mpStartNodeHandle.mOffset )
    return *(UFG::AISidewalkNode_Game **)((char *)&this->mOutlineVerts[1].x + this->mpStartNodeHandle.mOffset);
  else
    return (UFG::AISidewalkNode_Game *)MEMORY[0x28];
}

// File Line: 1048
// RVA: 0x35F3D0
UFG::AISidewalkNode_Game *__fastcall UFG::AISidewalkEdge_Game::GetEndNode(UFG::AISidewalkEdge_Game *this)
{
  __int64 mOffset; // rax

  mOffset = this->mpEndNodeHandle.mOffset;
  if ( mOffset )
    return *(UFG::AISidewalkNode_Game **)((char *)&this->mOutlineVerts[1].z + mOffset);
  else
    return (UFG::AISidewalkNode_Game *)MEMORY[0x28];
}

