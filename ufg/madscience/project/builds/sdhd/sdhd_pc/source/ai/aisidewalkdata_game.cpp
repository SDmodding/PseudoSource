// File Line: 24
// RVA: 0x14B2E90
__int64 UFG::_dynamic_initializer_for__gAISidewalkInventory__()
{
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&UFG::gAISidewalkInventory.vfptr,
    "SidewalkInventory",
    0x43E99F7Eu,
    0x2C81C14Bu,
    0,
    0);
  UFG::gAISidewalkInventory.vfptr = (UFG::qResourceInventoryVtbl *)&UFG::AISidewalkInventory::`vftable';
  return atexit(UFG::_dynamic_atexit_destructor_for__gAISidewalkInventory__);
}

// File Line: 177
// RVA: 0x399630
void __fastcall UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game>::_Set(UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *this, unsigned int objUID, unsigned int cellUID, unsigned int index)
{
  UFG::qResourceInventory *v4; // rax
  unsigned __int16 v5; // di
  unsigned int v6; // ebp
  unsigned int v7; // esi
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *v8; // rbx
  UFG::qResourceWarehouse *v9; // rax
  UFG::qResourceInventory *v10; // rax
  UFG::qResourceWarehouse *v11; // rax

  this->mPtr = 0i64;
  v4 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
  v5 = index;
  v6 = cellUID;
  v7 = objUID;
  v8 = this;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
  {
    v9 = UFG::qResourceWarehouse::Instance();
    v4 = UFG::qResourceWarehouse::GetInventory(v9, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v4;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v8->mPrev, v4);
  v8->mIndex = v5;
  v8->mObjUID = v7;
  v10 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
  {
    v11 = UFG::qResourceWarehouse::Instance();
    v10 = UFG::qResourceWarehouse::GetInventory(v11, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v10;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v8->mPrev, 0x43E99F7Eu, v6, v10);
}

// File Line: 188
// RVA: 0x399580
void __fastcall UFG::SidewalkCommonHandle<UFG::AISidewalkEdge_Game>::_Set(UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *this, unsigned int objUID, unsigned int cellUID)
{
  UFG::qResourceInventory *v3; // rax
  unsigned int v4; // esi
  unsigned int v5; // edi
  UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *v6; // rbx
  UFG::qResourceWarehouse *v7; // rax
  UFG::qResourceInventory *v8; // rax
  UFG::qResourceWarehouse *v9; // rax

  this->mPtr = 0i64;
  v3 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
  v4 = cellUID;
  v5 = objUID;
  v6 = this;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
  {
    v7 = UFG::qResourceWarehouse::Instance();
    v3 = UFG::qResourceWarehouse::GetInventory(v7, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v3;
  }
  UFG::qResourceHandle::Close((UFG::qResourceHandle *)&v6->mPrev, v3);
  v6->mObjUID = v5;
  v6->mIndex = -1;
  v8 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
  if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
  {
    v9 = UFG::qResourceWarehouse::Instance();
    v8 = UFG::qResourceWarehouse::GetInventory(v9, 0x43E99F7Eu);
    `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v8;
  }
  UFG::qResourceHandle::Init((UFG::qResourceHandle *)&v6->mPrev, 0x43E99F7Eu, v4, v8);
}

// File Line: 295
// RVA: 0x32BE80
void __fastcall UFG::AISidewalkSectionResource::AISidewalkSectionResource(UFG::AISidewalkSectionResource *this)
{
  UFG::AISidewalkSectionResource *v1; // rbx
  unsigned int v2; // edi
  __int64 v3; // rax
  signed __int64 v4; // rdx
  UFG::qResourceHandle *v5; // rcx
  unsigned int v6; // edi
  __int64 v7; // rax
  signed __int64 v8; // rdx
  UFG::qResourceHandle *v9; // rcx

  v1 = this;
  UFG::qResourceData::qResourceData((UFG::qResourceData *)&this->mNode);
  v2 = 0;
  if ( v1->mNodeHandleCount > 0u )
  {
    do
    {
      v3 = v1->mNodeHandles.mOffset;
      if ( v3 )
        v4 = (signed __int64)&v1->mNodeHandles + v3;
      else
        v4 = 0i64;
      v5 = (UFG::qResourceHandle *)(v4 + 48i64 * v2);
      if ( v5 )
        UFG::qResourceHandle::qResourceHandle(v5);
      ++v2;
    }
    while ( v2 < v1->mNodeHandleCount );
  }
  v6 = 0;
  if ( v1->mEdgeHandleCount > 0u )
  {
    do
    {
      v7 = v1->mEdgeHandles.mOffset;
      if ( v7 )
        v8 = (signed __int64)&v1->mEdgeHandles + v7;
      else
        v8 = 0i64;
      v9 = (UFG::qResourceHandle *)(v8 + 48i64 * v6);
      if ( v9 )
        UFG::qResourceHandle::qResourceHandle(v9);
      ++v6;
    }
    while ( v6 < v1->mEdgeHandleCount );
  }
}

// File Line: 344
// RVA: 0x368770
void __fastcall UFG::AISidewalkSectionResource::InitHandles(UFG::AISidewalkSectionResource *this)
{
  UFG::AISidewalkSectionResource *v1; // rsi
  unsigned int v2; // edi
  __int64 v3; // rax
  signed __int64 v4; // rcx
  UFG::qResourceInventory *v5; // rax
  UFG::qResourceHandle *v6; // rbx
  UFG::qResourceWarehouse *v7; // rax
  unsigned int v8; // edi
  __int64 v9; // rax
  signed __int64 v10; // rcx
  UFG::qResourceInventory *v11; // rax
  UFG::qResourceHandle *v12; // rbx
  UFG::qResourceWarehouse *v13; // rax

  v1 = this;
  v2 = 0;
  if ( this->mNodeHandleCount > 0u )
  {
    do
    {
      v3 = v1->mNodeHandles.mOffset;
      if ( v3 )
        v4 = (signed __int64)&v1->mNodeHandles + v3;
      else
        v4 = 0i64;
      v5 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
      v6 = (UFG::qResourceHandle *)(v4 + 48i64 * v2);
      if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
      {
        v7 = UFG::qResourceWarehouse::Instance();
        v5 = UFG::qResourceWarehouse::GetInventory(v7, 0x43E99F7Eu);
        `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v5;
      }
      UFG::qResourceHandle::Init(v6, 0x43E99F7Eu, v6->mNameUID, v5);
      ++v2;
    }
    while ( v2 < v1->mNodeHandleCount );
  }
  v8 = 0;
  if ( v1->mEdgeHandleCount > 0u )
  {
    do
    {
      v9 = v1->mEdgeHandles.mOffset;
      if ( v9 )
        v10 = (signed __int64)&v1->mEdgeHandles + v9;
      else
        v10 = 0i64;
      v11 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
      v12 = (UFG::qResourceHandle *)(v10 + 48i64 * v8);
      if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
      {
        v13 = UFG::qResourceWarehouse::Instance();
        v11 = UFG::qResourceWarehouse::GetInventory(v13, 0x43E99F7Eu);
        `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v11;
      }
      UFG::qResourceHandle::Init(v12, 0x43E99F7Eu, v12->mNameUID, v11);
      ++v8;
    }
    while ( v8 < v1->mEdgeHandleCount );
  }
}

// File Line: 361
// RVA: 0x34F7F0
void __fastcall UFG::AISidewalkSectionResource::CloseHandles(UFG::AISidewalkSectionResource *this)
{
  UFG::AISidewalkSectionResource *v1; // rsi
  unsigned int v2; // edi
  __int64 v3; // rax
  signed __int64 v4; // rcx
  UFG::qResourceHandle *v5; // rbx
  UFG::qResourceInventory *v6; // rax
  UFG::qResourceWarehouse *v7; // rax
  unsigned int v8; // edi
  __int64 v9; // rax
  signed __int64 v10; // rcx
  UFG::qResourceHandle *v11; // rbx
  UFG::qResourceInventory *v12; // rax
  UFG::qResourceWarehouse *v13; // rax

  v1 = this;
  v2 = 0;
  if ( this->mNodeHandleCount > 0u )
  {
    do
    {
      v3 = v1->mNodeHandles.mOffset;
      if ( v3 )
        v4 = (signed __int64)&v1->mNodeHandles + v3;
      else
        v4 = 0i64;
      v5 = (UFG::qResourceHandle *)(v4 + 48i64 * v2);
      v5[1].mNext = 0i64;
      v6 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
      if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
      {
        v7 = UFG::qResourceWarehouse::Instance();
        v6 = UFG::qResourceWarehouse::GetInventory(v7, 0x43E99F7Eu);
        `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v6;
      }
      UFG::qResourceHandle::Close(v5, v6);
      ++v2;
    }
    while ( v2 < v1->mNodeHandleCount );
  }
  v8 = 0;
  if ( v1->mEdgeHandleCount > 0u )
  {
    do
    {
      v9 = v1->mEdgeHandles.mOffset;
      if ( v9 )
        v10 = (signed __int64)&v1->mEdgeHandles + v9;
      else
        v10 = 0i64;
      v11 = (UFG::qResourceHandle *)(v10 + 48i64 * v8);
      v11[1].mNext = 0i64;
      v12 = `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result;
      if ( !`UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result )
      {
        v13 = UFG::qResourceWarehouse::Instance();
        v12 = UFG::qResourceWarehouse::GetInventory(v13, 0x43E99F7Eu);
        `UFG::qGetResourceInventory<UFG::AISidewalkSectionResource>'::`2'::result = v12;
      }
      UFG::qResourceHandle::Close(v11, v12);
      ++v8;
    }
    while ( v8 < v1->mEdgeHandleCount );
  }
}

// File Line: 463
// RVA: 0x33FB00
void __fastcall UFG::AISidewalkInventory::Add(UFG::AISidewalkInventory *this, UFG::qResourceData *resource_data)
{
  UFG::AISidewalkSectionResource *v2; // r14
  UFG::AISidewalkInventory *v3; // rbx
  unsigned int v4; // er15
  __int64 v5; // rax
  signed __int64 v6; // rsi
  unsigned int v7; // ebx
  _QWORD *v8; // rdi
  char *v9; // rcx
  char *v10; // rdx
  char *v11; // rdx
  UFG::AISidewalkEdge_Game *v12; // rdx
  __int64 v13; // rax
  char *v14; // rcx
  __int64 v15; // rcx
  signed __int64 v16; // r8
  float **v17; // r8
  signed __int64 v18; // rax

  v2 = (UFG::AISidewalkSectionResource *)resource_data;
  v3 = this;
  if ( resource_data )
    UFG::AISidewalkSectionResource::AISidewalkSectionResource((UFG::AISidewalkSectionResource *)resource_data);
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, (UFG::qResourceData *)&v2->mNode);
  UFG::AISidewalkSectionResource::InitHandles(v2);
  UFG::AISidewalkGraph::HandleAlteredDataOnAdd(v2);
  v4 = 0;
  if ( v2->mNodeCount )
  {
    do
    {
      v5 = v2->mNodes.mOffset;
      if ( v5 )
        v6 = (signed __int64)&v2->mNodes + v5;
      else
        v6 = 0i64;
      ++foo_zzzzzz;
      v7 = 0;
      if ( *(_WORD *)(v6 + 40i64 * v4 + 32) > 0u )
      {
        v8 = (_QWORD *)(v6 + 8 * (5i64 * v4 + 3));
        do
        {
          v9 = (char *)v8 + *v8;
          if ( !*v8 )
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
              v16 = (signed __int64)(v15 ? (UFG::qOffset64<UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *> *)((char *)&v12->mpEndNodeHandle + v15) : 0i64);
              if ( *(_QWORD *)(v16 + 40) )
              {
                v17 = (float **)((char *)v12 + v13);
                if ( !v13 )
                  v17 = 0i64;
                if ( v15 )
                  v18 = (signed __int64)&v12->mpEndNodeHandle + v15;
                else
                  v18 = 0i64;
                UFG::Grid<UFG::AISidewalkEdge_Game>::AddAlongSegment(
                  gAISidewalkEdgeDataGrid,
                  v12,
                  *v17[5],
                  v17[5][1],
                  **(float **)(v18 + 40),
                  *(float *)(*(_QWORD *)(v18 + 40) + 4i64));
              }
            }
          }
          ++v7;
        }
        while ( v7 < *(unsigned __int16 *)(v6 + 40i64 * v4 + 32) );
      }
      ++v4;
    }
    while ( v4 < v2->mNodeCount );
  }
}

// File Line: 491
// RVA: 0x380CF0
void __fastcall UFG::AISidewalkInventory::Remove(UFG::AISidewalkInventory *this, UFG::qResourceData *resource_data)
{
  UFG::AISidewalkSectionResource *v2; // rsi
  UFG::AISidewalkInventory *v3; // r12
  unsigned int v4; // ebx
  __int64 v5; // rax
  signed __int64 v6; // rdx
  UFG::AISidewalkEdge_Game *v7; // rdx
  __int64 v8; // rcx
  char *v9; // rax
  __int64 v10; // rax
  signed __int64 v11; // r8
  float **v12; // r8
  signed __int64 v13; // rax
  UFG::qNode<UFG::SidewalkAlteredNodeData,UFG::SidewalkAlteredNodeData> *v14; // rcx
  UFG::qList<UFG::SidewalkAlteredNodeData,UFG::SidewalkAlteredNodeData,1,0> *v15; // rdx
  UFG::qNode<UFG::SidewalkAlteredNodeData,UFG::SidewalkAlteredNodeData> *v16; // r8
  unsigned int i; // er15
  __int64 v18; // rax
  signed __int64 v19; // rbp
  unsigned int v20; // ebx
  _QWORD *v21; // rdi
  char *v22; // rcx
  char *v23; // rdx
  char *v24; // rdx
  UFG::AISidewalkEdge_Game *v25; // rdx
  __int64 v26; // rax
  char *v27; // rcx
  __int64 v28; // rcx
  signed __int64 v29; // r8
  float **v30; // r8
  signed __int64 v31; // rax
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v32; // rdi
  UFG::qResourceHandle *v33; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v34; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v35; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v36; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v37; // rax

  v2 = (UFG::AISidewalkSectionResource *)resource_data;
  v3 = this;
  v4 = 0;
  if ( HIDWORD(resource_data[1].mNode.mChild[0]) )
  {
    do
    {
      v5 = v2->mEdges.mOffset;
      if ( v5 )
        v6 = (signed __int64)&v2->mEdges + v5;
      else
        v6 = 0i64;
      v7 = (UFG::AISidewalkEdge_Game *)(80i64 * v4 + v6);
      v8 = v7->mpStartNodeHandle.mOffset;
      v9 = (char *)v7 + v7->mpStartNodeHandle.mOffset;
      if ( !v7->mpStartNodeHandle.mOffset )
        v9 = 0i64;
      if ( *((_QWORD *)v9 + 5) )
      {
        v10 = v7->mpEndNodeHandle.mOffset;
        v11 = (signed __int64)(v10 ? (UFG::qOffset64<UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *> *)((char *)&v7->mpEndNodeHandle + v10) : 0i64);
        if ( *(_QWORD *)(v11 + 40) )
        {
          v12 = (float **)((char *)v7 + v8);
          if ( !v8 )
            v12 = 0i64;
          if ( v10 )
            v13 = (signed __int64)&v7->mpEndNodeHandle + v10;
          else
            v13 = 0i64;
          UFG::Grid<UFG::AISidewalkEdge_Game>::RemoveAlongSegment(
            gAISidewalkEdgeDataGrid,
            v7,
            *v12[5],
            v12[5][1],
            **(float **)(v13 + 40),
            *(float *)(*(_QWORD *)(v13 + 40) + 4i64));
        }
      }
      ++v4;
    }
    while ( v4 < v2->mEdgeCount );
  }
  v14 = UFG::AISidewalkGraph::sAlteredNodeData.mNode.mNext;
  if ( (UFG::qList<UFG::SidewalkAlteredNodeData,UFG::SidewalkAlteredNodeData,1,0> *)UFG::AISidewalkGraph::sAlteredNodeData.mNode.mNext != &UFG::AISidewalkGraph::sAlteredNodeData )
  {
    do
    {
      v15 = (UFG::qList<UFG::SidewalkAlteredNodeData,UFG::SidewalkAlteredNodeData,1,0> *)v14->mNext;
      v16 = v14[3].mNext;
      if ( v16 && LODWORD(v14[2].mNext) == v2->mSectionVisId )
        WORD1(v16[2].mPrev) = BYTE6(v14[4].mPrev);
      v14 = &v15->mNode;
    }
    while ( v15 != &UFG::AISidewalkGraph::sAlteredNodeData );
  }
  for ( i = 0; i < v2->mNodeCount; ++i )
  {
    v18 = v2->mNodes.mOffset;
    if ( v18 )
      v19 = (signed __int64)&v2->mNodes + v18;
    else
      v19 = 0i64;
    v20 = 0;
    if ( *(_WORD *)(v19 + 40i64 * i + 32) > 0u )
    {
      v21 = (_QWORD *)(v19 + 40i64 * i + 24);
      do
      {
        v22 = (char *)v21 + *v21;
        if ( !*v21 )
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
              v29 = (signed __int64)(v28 ? (UFG::qOffset64<UFG::SidewalkCommonHandle<UFG::AISidewalkNode_Game> *> *)((char *)&v25->mpEndNodeHandle + v28) : 0i64);
              if ( *(_QWORD *)(v29 + 40) )
              {
                v30 = (float **)((char *)v25 + v26);
                if ( !v26 )
                  v30 = 0i64;
                if ( v28 )
                  v31 = (signed __int64)&v25->mpEndNodeHandle + v28;
                else
                  v31 = 0i64;
                UFG::Grid<UFG::AISidewalkEdge_Game>::RemoveAlongSegment(
                  gAISidewalkEdgeDataGrid,
                  v25,
                  *v30[5],
                  v30[5][1],
                  **(float **)(v31 + 40),
                  *(float *)(*(_QWORD *)(v31 + 40) + 4i64));
              }
            }
          }
        }
        ++v20;
      }
      while ( v20 < *(unsigned __int16 *)(v19 + 40i64 * i + 32) );
    }
  }
  UFG::AISidewalkSectionResource::CloseHandles(v2);
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&v3->vfptr, (UFG::qResourceData *)&v2->mNode);
  v32 = &v2->mResourceHandles;
  v33 = (UFG::qResourceHandle *)v2->mResourceHandles.mNode.mNext;
  if ( v33 != (UFG::qResourceHandle *)&v2->mResourceHandles )
  {
    do
    {
      v34 = v33->mPrev;
      v35 = v33->mNext;
      v34->mNext = v35;
      v35->mPrev = v34;
      v33->mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v33->mPrev;
      v33->mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&v33->mPrev;
      UFG::qResourceHandle::~qResourceHandle(v33);
      operator delete[](v33);
      v33 = (UFG::qResourceHandle *)v2->mResourceHandles.mNode.mNext;
    }
    while ( v33 != (UFG::qResourceHandle *)v32 );
  }
  v36 = v32->mNode.mPrev;
  v37 = v2->mResourceHandles.mNode.mNext;
  v36->mNext = v37;
  v37->mPrev = v36;
  v32->mNode.mPrev = &v32->mNode;
  v2->mResourceHandles.mNode.mNext = &v2->mResourceHandles.mNode;
}

// File Line: 518
// RVA: 0x379510
void __fastcall UFG::AISidewalkInventory::OnAttachHandle(UFG::AISidewalkInventory *this, UFG::qResourceHandle *handle, UFG::qResourceData *resource_data)
{
  int v3; // edi
  signed __int64 v4; // rax
  signed __int64 v5; // r9
  UFG::qResourceData *v6; // rbx
  UFG::qResourceHandle *v7; // r10
  unsigned int v8; // er11
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v9; // r8
  __int64 v10; // rdx
  signed __int64 v11; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v12; // rcx
  unsigned int v13; // er11
  UFG::qBaseNodeRB *v14; // r8
  __int64 v15; // rdx
  signed __int64 v16; // rcx
  UFG::qBaseNodeRB *v17; // rcx

  v3 = HIDWORD(handle[1].mPrev);
  v4 = LOWORD(handle[1].mPrev);
  v5 = 0i64;
  v6 = resource_data;
  v7 = handle;
  if ( WORD1(handle[1].mPrev) )
  {
    if ( (_DWORD)v4 == 0xFFFF )
    {
      v8 = HIDWORD(resource_data[1].mNode.mChild[0]);
      v4 = 0i64;
      if ( v8 )
      {
        v9 = resource_data[1].mResourceHandles.mNode.mPrev;
        v10 = 0i64;
        while ( 1 )
        {
          v11 = (signed __int64)(v9 ? (UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *)((char *)&v6[1].mResourceHandles
                                                                                                  + (_QWORD)v9) : 0i64);
          if ( *(_DWORD *)(v10 + v11 + 16) == v3 )
            break;
          v4 = (unsigned int)(v4 + 1);
          v10 += 80i64;
          if ( (unsigned int)v4 >= v8 )
            goto LABEL_10;
        }
      }
      else
      {
LABEL_10:
        v4 = 0xFFFFFFFFi64;
      }
      LOWORD(v7[1].mPrev) = v4;
    }
    v12 = v6[1].mResourceHandles.mNode.mPrev;
    if ( v12 )
      v5 = (signed __int64)&v6[1].mResourceHandles + (_QWORD)v12;
    v7[1].mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)(v5 + 80 * v4);
  }
  else
  {
    if ( (_DWORD)v4 == 0xFFFF )
    {
      v13 = (unsigned int)resource_data[1].mNode.mChild[0];
      v4 = 0i64;
      if ( v13 )
      {
        v14 = resource_data[1].mNode.mChild[1];
        v15 = 0i64;
        while ( 1 )
        {
          v16 = (signed __int64)(v14 ? (UFG::qBaseNodeRB **)((char *)&v6[1].mNode.mChild[1] + (_QWORD)v14) : 0i64);
          if ( *(_DWORD *)(v15 + v16 + 12) == v3 )
            break;
          v4 = (unsigned int)(v4 + 1);
          v15 += 40i64;
          if ( (unsigned int)v4 >= v13 )
            goto LABEL_23;
        }
      }
      else
      {
LABEL_23:
        v4 = 0xFFFFFFFFi64;
      }
      LOWORD(v7[1].mPrev) = v4;
    }
    v17 = v6[1].mNode.mChild[1];
    if ( v17 )
      v5 = (signed __int64)&v6[1].mNode.mChild[1] + (_QWORD)v17;
    v7[1].mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)(v5 + 40 * v4);
  }
}

// File Line: 552
// RVA: 0x37B310
void __fastcall UFG::AISidewalkInventory::OnDetachHandle(UFG::AISidewalkInventory *this, UFG::qResourceHandle *handle, UFG::qResourceData *resource_data)
{
  handle[1].mNext = 0i64;
}

// File Line: 648
// RVA: 0x35FC50
UFG::AISidewalkNode_Game *__fastcall UFG::AISidewalkNode_Game::GetFromObjUID_Slow(unsigned int objUID)
{
  unsigned int v1; // esi
  Render::SkinningCacheNode *v2; // rdi
  signed __int64 v3; // rbx
  UFG::qBaseTreeRB *v4; // rax
  unsigned int v5; // er9
  unsigned int v6; // edx
  UFG::qBaseTreeRB *v7; // r10
  unsigned __int64 v8; // r8
  __int64 v9; // rcx
  signed __int64 v10; // rax

  v1 = objUID;
  v2 = UFG::qTreeRB64<UFG::tOffset,UFG::tOffset,1>::GetHead(&stru_1423BAAD0);
  if ( !v2 )
    return 0i64;
  v3 = 0i64;
  while ( 1 )
  {
    v4 = UFG::qBaseTreeRB::GetNext((UFG::qBaseTreeRB *)&stru_1423BAAD0, (UFG::qBaseNodeRB *)v2);
    v5 = (unsigned int)v2[2].mNode.mChild1;
    v6 = 0;
    v7 = v4;
    if ( v5 )
      break;
LABEL_10:
    v2 = (Render::SkinningCacheNode *)v7;
    if ( !v7 )
      return 0i64;
  }
  v8 = v2[2].mNode.mUID;
  v9 = 0i64;
  while ( 1 )
  {
    v10 = (signed __int64)(v8 ? (unsigned __int64 *)((char *)&v2[2].mNode.mUID + v8) : 0i64);
    if ( *(_DWORD *)(v9 + v10 + 12) == v1 )
      break;
    ++v6;
    v9 += 40i64;
    if ( v6 >= v5 )
      goto LABEL_10;
  }
  if ( v8 )
    v3 = (signed __int64)&v2[2].mNode.mUID + v8;
  return (UFG::AISidewalkNode_Game *)(v3 + 40i64 * v6);
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
  UFG::AISidewalkNode_Game *result; // rax

  if ( this->mpStartNodeHandle.mOffset )
    result = *(UFG::AISidewalkNode_Game **)((char *)&this->mOutlineVerts[1].x + this->mpStartNodeHandle.mOffset);
  else
    result = (UFG::AISidewalkNode_Game *)MEMORY[0x28];
  return result;
}

// File Line: 1048
// RVA: 0x35F3D0
UFG::AISidewalkNode_Game *__fastcall UFG::AISidewalkEdge_Game::GetEndNode(UFG::AISidewalkEdge_Game *this)
{
  __int64 v1; // rax
  UFG::AISidewalkNode_Game *result; // rax

  v1 = this->mpEndNodeHandle.mOffset;
  if ( v1 )
    result = *(UFG::AISidewalkNode_Game **)((char *)&this->mOutlineVerts[1].z + v1);
  else
    result = (UFG::AISidewalkNode_Game *)MEMORY[0x28];
  return result;
}

