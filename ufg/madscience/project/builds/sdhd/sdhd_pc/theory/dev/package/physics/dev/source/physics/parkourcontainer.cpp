// File Line: 36
// RVA: 0x9C710
void __fastcall UFG::ParkourContainerBundle::~ParkourContainerBundle(UFG::ParkourContainerBundle *this)
{
  UFG::ParkourContainerBundle *v1; // rdi
  __int64 v2; // rbx
  UFG::qOffset64<UFG::ParkourContainer *> *v3; // rdx
  UFG::qResourceData *v4; // rdx
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *v5; // rdi
  UFG::qResourceHandle *i; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v7; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v8; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v9; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v10; // rax

  v1 = this;
  v2 = 0i64;
  if ( this->mNumContainers )
  {
    do
    {
      v3 = &v1->mContainers[v2];
      if ( v3->mOffset )
        v4 = (UFG::qResourceData *)((char *)v3 + v3->mOffset);
      else
        v4 = 0i64;
      UFG::gParkourContainerInventory->vfptr->Remove((UFG::qResourceInventory *)UFG::gParkourContainerInventory, v4);
      v2 = (unsigned int)(v2 + 1);
    }
    while ( (unsigned int)v2 < v1->mNumContainers );
  }
  v5 = &v1->mResourceHandles;
  for ( i = (UFG::qResourceHandle *)v5->mNode.mNext;
        i != (UFG::qResourceHandle *)v5;
        i = (UFG::qResourceHandle *)v5->mNode.mNext )
  {
    v7 = i->mPrev;
    v8 = i->mNext;
    v7->mNext = v8;
    v8->mPrev = v7;
    i->mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&i->mPrev;
    i->mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)&i->mPrev;
    UFG::qResourceHandle::~qResourceHandle(i);
    operator delete[](i);
  }
  v9 = v5->mNode.mPrev;
  v10 = v5->mNode.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
}

// File Line: 107
// RVA: 0xB5930
void __fastcall UFG::ParkourContainer::VisitNodesRecursive(UFG::ParkourContainer *this, UFG::ParkourTreeNode *node, UFG::qVector3 *queryAabbMin, UFG::qVector3 *queryAabbMax, UFG::qVector3 *parentAabbMin, UFG::qVector3 *parentAabbMax, hkArray<UFG::ParkourData *,hkContainerHeapAllocator> *output)
{
  UFG::qVector3 *v7; // rdi
  UFG::qVector3 *v8; // rsi
  UFG::ParkourContainer *v9; // rbp
  unsigned int v10; // er10
  UFG::ParkourTreeNode *v11; // r9
  unsigned int v12; // ebp
  UFG::ParkourData *v13; // rdx
  UFG::qVector3 *v14; // rcx
  __int64 v15; // rax
  float v16; // xmm1_4
  float v17; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm0_4
  float v22; // xmm0_4
  UFG::ParkourData *v23; // rbp
  UFG::qVector3 *v24; // rcx
  __int64 v25; // rax
  float v26; // xmm1_4
  float v27; // xmm1_4
  float v28; // xmm0_4
  float v29; // xmm0_4
  float v30; // xmm1_4
  float v31; // xmm0_4
  float v32; // xmm0_4
  UFG::ParkourData *v33; // [rsp+40h] [rbp-68h]
  UFG::qVector3 v34; // [rsp+48h] [rbp-60h]
  UFG::qVector3 v35; // [rsp+58h] [rbp-50h]
  UFG::qVector3 rightMax; // [rsp+68h] [rbp-40h]
  UFG::qVector3 v37; // [rsp+78h] [rbp-30h]
  UFG::ParkourContainer *v38; // [rsp+B0h] [rbp+8h]
  UFG::ParkourTreeNode *v39; // [rsp+B8h] [rbp+10h]
  unsigned int v40; // [rsp+C8h] [rbp+20h]

  v39 = node;
  v38 = this;
  v7 = queryAabbMax;
  v8 = queryAabbMin;
  v9 = this;
  UFG::ParkourTreeNode::ComputeChildAabbs(node, &v35, &v34, &v37, &rightMax, parentAabbMin, parentAabbMax);
  v10 = 0;
  v40 = 0;
  if ( v35.x > v7->x || v35.y > v7->y || v35.z > v7->z || v34.x < v8->x )
  {
    v11 = v39;
  }
  else
  {
    v11 = v39;
    if ( v34.y >= v8->y && v34.z >= v8->z )
    {
      if ( v39->mFlags & 0x40 )
      {
        v12 = 0;
        if ( v39->mParkourDataCountLeft > 0u )
        {
          do
          {
            v13 = &v38->mParkourData[v12 + v11->mLeftChild];
            v14 = v38->mVertexBuffer;
            v33 = &v38->mParkourData[v12 + v11->mLeftChild];
            v15 = v13->v1;
            v16 = v14[v13->v0].x;
            if ( (v16 >= v8->x || v8->x <= v14[v15].x) && (v16 <= v7->x || v7->x >= v14[v15].x) )
            {
              v17 = v14[v13->v0].y;
              v18 = v8->y;
              if ( v17 >= v18 || v18 <= v14[v15].y )
              {
                v19 = v7->y;
                if ( v17 <= v19 || v19 >= v14[v15].y )
                {
                  v20 = v14[v13->v0].z;
                  v21 = v8->z;
                  if ( v20 >= v21 || v21 <= v14[v15].z )
                  {
                    v22 = v7->z;
                    if ( v20 <= v22 || v22 >= v14[v15].z )
                    {
                      if ( output->m_size == (output->m_capacityAndFlags & 0x3FFFFFFF) )
                      {
                        hkArrayUtil::_reserveMore(
                          (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                          output,
                          8);
                        v11 = v39;
                      }
                      output->m_data[output->m_size++] = v33;
                    }
                  }
                }
              }
            }
            ++v12;
          }
          while ( v12 < (unsigned __int8)v11->mParkourDataCountLeft );
          v10 = 0;
        }
        v9 = v38;
      }
      else
      {
        UFG::ParkourContainer::VisitNodesRecursive(v9, &v9->mNodes[v39->mLeftChild], v8, v7, &v35, &v34, output);
        v11 = v39;
        v10 = 0;
      }
    }
  }
  if ( v37.x <= v7->x
    && v37.y <= v7->y
    && v37.z <= v7->z
    && rightMax.x >= v8->x
    && rightMax.y >= v8->y
    && rightMax.z >= v8->z )
  {
    if ( v11->mFlags < 0 )
    {
      if ( v11->mParkourDataCountRight )
      {
        do
        {
          v23 = &v9->mParkourData[v10 + v11->mRightChild];
          v24 = v38->mVertexBuffer;
          v25 = v23->v1;
          v26 = v24[v23->v0].x;
          if ( (v26 >= v8->x || v8->x <= v24[v25].x) && (v26 <= v7->x || v7->x >= v24[v25].x) )
          {
            v27 = v24[v23->v0].y;
            v28 = v8->y;
            if ( v27 >= v28 || v28 <= v24[v25].y )
            {
              v29 = v7->y;
              if ( v27 <= v29 || v29 >= v24[v25].y )
              {
                v30 = v24[v23->v0].z;
                v31 = v8->z;
                if ( v30 >= v31 || v31 <= v24[v25].z )
                {
                  v32 = v7->z;
                  if ( v30 <= v32 || v32 >= v24[v25].z )
                  {
                    if ( output->m_size == (output->m_capacityAndFlags & 0x3FFFFFFF) )
                    {
                      hkArrayUtil::_reserveMore(
                        (hkMemoryAllocator *)&hkContainerHeapAllocator::s_alloc.vfptr,
                        output,
                        8);
                      v11 = v39;
                      v10 = v40;
                    }
                    output->m_data[output->m_size++] = v23;
                  }
                }
              }
            }
          }
          v9 = v38;
          v40 = ++v10;
        }
        while ( v10 < (unsigned __int8)v11->mParkourDataCountRight );
      }
    }
    else
    {
      UFG::ParkourContainer::VisitNodesRecursive(v9, &v9->mNodes[v11->mRightChild], v8, v7, &v37, &rightMax, output);
    }
  }
}

// File Line: 172
// RVA: 0xA39B0
void __fastcall UFG::ParkourTreeNode::ComputeChildAabbs(UFG::ParkourTreeNode *this, UFG::qVector3 *leftMin, UFG::qVector3 *leftMax, UFG::qVector3 *rightMin, UFG::qVector3 *rightMax, UFG::qVector3 *parentAabbMin, UFG::qVector3 *parentAabbMax)
{
  float v7; // xmm6_4
  float v8; // xmm5_4
  float v9; // xmm4_4
  float v10; // xmm9_4
  float v11; // xmm11_4
  float v12; // xmm12_4
  float v13; // xmm10_4
  float v14; // xmm3_4
  float v15; // xmm8_4

  v7 = parentAabbMin->x;
  v8 = parentAabbMin->y;
  v9 = parentAabbMin->z;
  v10 = (float)((float)(parentAabbMax->x - v7) * (float)((float)(unsigned __int8)this->mExtents[0] * 0.0039215689)) + v7;
  v11 = (float)((float)((float)(unsigned __int8)this->mExtents[1] * 0.0039215689) * (float)(parentAabbMax->y - v8)) + v8;
  v12 = (float)((float)((float)(unsigned __int8)this->mExtents[2] * 0.0039215689) * (float)(parentAabbMax->z - v9)) + v9;
  v13 = (float)((float)(1.0 - (float)((float)(unsigned __int8)this->mExtents[3] * 0.0039215689))
              * (float)(parentAabbMax->x - v7))
      + v7;
  v14 = (float)((float)(1.0 - (float)((float)(unsigned __int8)this->mExtents[4] * 0.0039215689))
              * (float)(parentAabbMax->y - v8))
      + v8;
  v15 = (float)((float)(1.0 - (float)((float)(unsigned __int8)this->mExtents[5] * 0.0039215689))
              * (float)(parentAabbMax->z - v9))
      + v9;
  if ( this->mFlags & 1 )
  {
    leftMin->x = v10;
    rightMin->x = parentAabbMin->x;
  }
  else
  {
    rightMin->x = v10;
    leftMin->x = parentAabbMin->x;
  }
  if ( this->mFlags & 2 )
  {
    leftMin->y = v11;
    rightMin->y = parentAabbMin->y;
  }
  else
  {
    rightMin->y = v11;
    leftMin->y = parentAabbMin->y;
  }
  if ( this->mFlags & 4 )
  {
    leftMin->z = v12;
    rightMin->z = parentAabbMin->z;
  }
  else
  {
    rightMin->z = v12;
    leftMin->z = parentAabbMin->z;
  }
  if ( this->mFlags & 8 )
  {
    leftMax->x = v13;
    rightMax->x = parentAabbMax->x;
  }
  else
  {
    rightMax->x = v13;
    leftMax->x = parentAabbMax->x;
  }
  if ( this->mFlags & 0x10 )
  {
    leftMax->y = v14;
    rightMax->y = parentAabbMax->y;
  }
  else
  {
    rightMax->y = v14;
    leftMax->y = parentAabbMax->y;
  }
  if ( this->mFlags & 0x20 )
  {
    leftMax->z = v15;
    rightMax->z = parentAabbMax->z;
  }
  else
  {
    rightMax->z = v15;
    leftMax->z = parentAabbMax->z;
  }
}

// File Line: 251
// RVA: 0xB4340
bool __fastcall UFG::ParkourContainer::TestOverlap(UFG::ParkourContainer *this, UFG::qVector3 *aabb1Min, UFG::qVector3 *aabb1Max, UFG::qVector3 *aabb2Min, UFG::qVector3 *aabb2Max)
{
  return aabb2Max->x >= aabb1Min->x
      && aabb2Max->y >= aabb1Min->y
      && aabb2Max->z >= aabb1Min->z
      && aabb2Min->x <= aabb1Max->x
      && aabb2Min->y <= aabb1Max->y
      && aabb2Min->z <= aabb1Max->z;
}

// File Line: 279
// RVA: 0x98D80
void __fastcall UFG::ParkourContainerInventory::ParkourContainerInventory(UFG::ParkourContainerInventory *this)
{
  UFG::ParkourContainerInventory *v1; // rbx

  v1 = this;
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&this->vfptr,
    "ParkourContainerInventory",
    0x15E16140u,
    0xBDE53ECA,
    0,
    0);
  v1->vfptr = (UFG::qResourceInventoryVtbl *)&UFG::ParkourContainerInventory::`vftable;
  v1->mAddParkourContainerCallback = 0i64;
  v1->mRemoveParkourContainerCallback = 0i64;
}

// File Line: 285
// RVA: 0x9FCE0
void __fastcall UFG::ParkourContainerInventory::Add(UFG::ParkourContainerInventory *this, UFG::qResourceData *res)
{
  UFG::qResourceData *v2; // rbx
  UFG::ParkourContainerInventory *v3; // rdi
  signed __int64 v4; // rdx
  void (__fastcall *v5)(UFG::ParkourContainer *); // rax

  v2 = res;
  v3 = this;
  if ( res )
  {
    UFG::qResourceData::qResourceData(res);
    *(_QWORD *)&v2[1].mNode.mUID = (char *)v2 + 160;
    v4 = (signed __int64)&v2[1].mDebugName[12 * *(unsigned int *)v2[1].mDebugName + 20];
    v2[1].mResourceHandles.mNode.mPrev = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)v4;
    if ( *(_DWORD *)&v2[1].mDebugName[4] )
      v2[1].mResourceHandles.mNode.mNext = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)(v4 + 6i64 * v2[1].mTypeUID);
  }
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, v2);
  v5 = v3->mAddParkourContainerCallback;
  if ( v5 )
    v5((UFG::ParkourContainer *)v2);
}

// File Line: 300
// RVA: 0xAF550
void __fastcall UFG::ParkourContainerInventory::Remove(UFG::ParkourContainerInventory *this, UFG::qResourceData *resource_data)
{
  void (__fastcall *v2)(UFG::ParkourContainer *); // rax
  UFG::qResourceData *v3; // rbx
  UFG::ParkourContainerInventory *v4; // rdi

  v2 = this->mRemoveParkourContainerCallback;
  v3 = resource_data;
  v4 = this;
  if ( v2 )
    v2((UFG::ParkourContainer *)resource_data);
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&v4->vfptr, v3);
}

// File Line: 314
// RVA: 0x98D30
void __fastcall UFG::ParkourContainerBundleInventory::ParkourContainerBundleInventory(UFG::ParkourContainerBundleInventory *this)
{
  UFG::ParkourContainerBundleInventory *v1; // rbx

  v1 = this;
  UFG::qResourceInventory::qResourceInventory(
    (UFG::qResourceInventory *)&this->vfptr,
    "ParkourContainerBundleInventory",
    0x4558A12Eu,
    0x12D3A53Du,
    0,
    0);
  v1->vfptr = (UFG::qResourceInventoryVtbl *)&UFG::ParkourContainerBundleInventory::`vftable;
}

// File Line: 320
// RVA: 0x9FC40
void __fastcall UFG::ParkourContainerBundleInventory::Add(UFG::ParkourContainerBundleInventory *this, UFG::qResourceData *res)
{
  UFG::qResourceData *v2; // rbx
  UFG::ParkourContainerBundleInventory *v3; // rsi
  __int64 v4; // rdi
  UFG::qBaseNodeRB **v5; // rdx
  UFG::qResourceData *v6; // rdx

  v2 = res;
  v3 = this;
  if ( res )
  {
    UFG::qResourceData::qResourceData(res);
    v2[1].mNode.mChild[0] = (UFG::qBaseNodeRB *)((char *)&v2[1].mNode + 16);
    v4 = 0i64;
    if ( LODWORD(v2[1].mNode.mParent) )
    {
      do
      {
        v5 = &v2[1].mNode.mChild[0]->mParent + v4;
        if ( *v5 )
          v6 = (UFG::qResourceData *)((char *)v5 + (_QWORD)*v5);
        else
          v6 = 0i64;
        UFG::gParkourContainerInventory->vfptr->Add((UFG::qResourceInventory *)UFG::gParkourContainerInventory, v6);
        v4 = (unsigned int)(v4 + 1);
      }
      while ( (unsigned int)v4 < LODWORD(v2[1].mNode.mParent) );
    }
  }
  UFG::qResourceInventory::Add((UFG::qResourceInventory *)&v3->vfptr, v2);
}

// File Line: 332
// RVA: 0xAF530
void __fastcall UFG::ParkourContainerBundleInventory::Remove(UFG::ParkourContainerBundleInventory *this, UFG::qResourceData *resource_data)
{
  UFG::ParkourContainerBundle *v2; // rbx

  v2 = (UFG::ParkourContainerBundle *)resource_data;
  UFG::qResourceInventory::Remove((UFG::qResourceInventory *)&this->vfptr, resource_data);
  UFG::ParkourContainerBundle::~ParkourContainerBundle(v2);
}

