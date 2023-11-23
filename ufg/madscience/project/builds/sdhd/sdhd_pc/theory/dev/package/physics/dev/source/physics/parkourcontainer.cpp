// File Line: 36
// RVA: 0x9C710
void __fastcall UFG::ParkourContainerBundle::~ParkourContainerBundle(UFG::ParkourContainerBundle *this)
{
  __int64 i; // rbx
  UFG::qOffset64<UFG::ParkourContainer *> *v3; // rdx
  UFG::qResourceData *v4; // rdx
  UFG::qList<UFG::qResourceHandle,UFG::qResourceHandle,1,0> *p_mResourceHandles; // rdi
  UFG::qResourceHandle *j; // rbx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mPrev; // rdx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *mNext; // rax
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v9; // rcx
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v10; // rax

  for ( i = 0i64; (unsigned int)i < this->mNumContainers; i = (unsigned int)(i + 1) )
  {
    v3 = &this->mContainers[i];
    if ( v3->mOffset )
      v4 = (UFG::qResourceData *)((char *)v3 + v3->mOffset);
    else
      v4 = 0i64;
    UFG::gParkourContainerInventory->vfptr->Remove(UFG::gParkourContainerInventory, v4);
  }
  p_mResourceHandles = &this->mResourceHandles;
  for ( j = (UFG::qResourceHandle *)p_mResourceHandles->mNode.mNext;
        j != (UFG::qResourceHandle *)p_mResourceHandles;
        j = (UFG::qResourceHandle *)p_mResourceHandles->mNode.mNext )
  {
    mPrev = j->mPrev;
    mNext = j->mNext;
    mPrev->mNext = mNext;
    mNext->mPrev = mPrev;
    j->mPrev = j;
    j->mNext = j;
    UFG::qResourceHandle::~qResourceHandle(j);
    operator delete[](j);
  }
  v9 = p_mResourceHandles->mNode.mPrev;
  v10 = p_mResourceHandles->mNode.mNext;
  v9->mNext = v10;
  v10->mPrev = v9;
  p_mResourceHandles->mNode.mPrev = &p_mResourceHandles->mNode;
  p_mResourceHandles->mNode.mNext = &p_mResourceHandles->mNode;
}

// File Line: 107
// RVA: 0xB5930
void __fastcall UFG::ParkourContainer::VisitNodesRecursive(
        UFG::ParkourContainer *this,
        UFG::ParkourTreeNode *node,
        UFG::qVector3 *queryAabbMin,
        UFG::qVector3 *queryAabbMax,
        UFG::qVector3 *parentAabbMin,
        UFG::qVector3 *parentAabbMax,
        hkArray<UFG::ParkourData *,hkContainerHeapAllocator> *output)
{
  UFG::ParkourContainer *v9; // rbp
  unsigned int v10; // r10d
  UFG::ParkourTreeNode *v11; // r9
  unsigned int v12; // ebp
  UFG::ParkourData *v13; // rdx
  UFG::qVector3 *mVertexBuffer; // rcx
  __int64 v15; // rax
  float x; // xmm1_4
  float y; // xmm1_4
  float v18; // xmm0_4
  float v19; // xmm0_4
  float z; // xmm1_4
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
  UFG::qVector3 v34; // [rsp+48h] [rbp-60h] BYREF
  UFG::qVector3 v35; // [rsp+58h] [rbp-50h] BYREF
  UFG::qVector3 rightMax; // [rsp+68h] [rbp-40h] BYREF
  UFG::qVector3 v37; // [rsp+78h] [rbp-30h] BYREF
  unsigned int v40; // [rsp+C8h] [rbp+20h]

  v9 = this;
  UFG::ParkourTreeNode::ComputeChildAabbs(node, &v35, &v34, &v37, &rightMax, parentAabbMin, parentAabbMax);
  v10 = 0;
  v40 = 0;
  if ( v35.x > queryAabbMax->x || v35.y > queryAabbMax->y || v35.z > queryAabbMax->z || v34.x < queryAabbMin->x )
  {
    v11 = node;
  }
  else
  {
    v11 = node;
    if ( v34.y >= queryAabbMin->y && v34.z >= queryAabbMin->z )
    {
      if ( (node->mFlags & 0x40) != 0 )
      {
        v12 = 0;
        if ( node->mParkourDataCountLeft )
        {
          do
          {
            v13 = &this->mParkourData[v12 + v11->mLeftChild];
            mVertexBuffer = this->mVertexBuffer;
            v33 = v13;
            v15 = v13->v1;
            x = mVertexBuffer[v13->v0].x;
            if ( (x >= queryAabbMin->x || queryAabbMin->x <= mVertexBuffer[v15].x)
              && (x <= queryAabbMax->x || queryAabbMax->x >= mVertexBuffer[v15].x) )
            {
              y = mVertexBuffer[v13->v0].y;
              v18 = queryAabbMin->y;
              if ( y >= v18 || v18 <= mVertexBuffer[v15].y )
              {
                v19 = queryAabbMax->y;
                if ( y <= v19 || v19 >= mVertexBuffer[v15].y )
                {
                  z = mVertexBuffer[v13->v0].z;
                  v21 = queryAabbMin->z;
                  if ( z >= v21 || v21 <= mVertexBuffer[v15].z )
                  {
                    v22 = queryAabbMax->z;
                    if ( z <= v22 || v22 >= mVertexBuffer[v15].z )
                    {
                      if ( output->m_size == (output->m_capacityAndFlags & 0x3FFFFFFF) )
                      {
                        hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, output, 8);
                        v11 = node;
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
        v9 = this;
      }
      else
      {
        UFG::ParkourContainer::VisitNodesRecursive(
          v9,
          &v9->mNodes[node->mLeftChild],
          queryAabbMin,
          queryAabbMax,
          &v35,
          &v34,
          output);
        v11 = node;
        v10 = 0;
      }
    }
  }
  if ( v37.x <= queryAabbMax->x
    && v37.y <= queryAabbMax->y
    && v37.z <= queryAabbMax->z
    && rightMax.x >= queryAabbMin->x
    && rightMax.y >= queryAabbMin->y
    && rightMax.z >= queryAabbMin->z )
  {
    if ( v11->mFlags < 0 )
    {
      if ( v11->mParkourDataCountRight )
      {
        do
        {
          v23 = &v9->mParkourData[v10 + v11->mRightChild];
          v24 = this->mVertexBuffer;
          v25 = v23->v1;
          v26 = v24[v23->v0].x;
          if ( (v26 >= queryAabbMin->x || queryAabbMin->x <= v24[v25].x)
            && (v26 <= queryAabbMax->x || queryAabbMax->x >= v24[v25].x) )
          {
            v27 = v24[v23->v0].y;
            v28 = queryAabbMin->y;
            if ( v27 >= v28 || v28 <= v24[v25].y )
            {
              v29 = queryAabbMax->y;
              if ( v27 <= v29 || v29 >= v24[v25].y )
              {
                v30 = v24[v23->v0].z;
                v31 = queryAabbMin->z;
                if ( v30 >= v31 || v31 <= v24[v25].z )
                {
                  v32 = queryAabbMax->z;
                  if ( v30 <= v32 || v32 >= v24[v25].z )
                  {
                    if ( output->m_size == (output->m_capacityAndFlags & 0x3FFFFFFF) )
                    {
                      hkArrayUtil::_reserveMore(&hkContainerHeapAllocator::s_alloc, output, 8);
                      v11 = node;
                      v10 = v40;
                    }
                    output->m_data[output->m_size++] = v23;
                  }
                }
              }
            }
          }
          v9 = this;
          v40 = ++v10;
        }
        while ( v10 < (unsigned __int8)v11->mParkourDataCountRight );
      }
    }
    else
    {
      UFG::ParkourContainer::VisitNodesRecursive(
        v9,
        &v9->mNodes[v11->mRightChild],
        queryAabbMin,
        queryAabbMax,
        &v37,
        &rightMax,
        output);
    }
  }
}

// File Line: 172
// RVA: 0xA39B0
void __fastcall UFG::ParkourTreeNode::ComputeChildAabbs(
        UFG::ParkourTreeNode *this,
        UFG::qVector3 *leftMin,
        UFG::qVector3 *leftMax,
        UFG::qVector3 *rightMin,
        UFG::qVector3 *rightMax,
        UFG::qVector3 *parentAabbMin,
        UFG::qVector3 *parentAabbMax)
{
  float y; // xmm5_4
  float z; // xmm4_4
  float v9; // xmm9_4
  float v10; // xmm11_4
  float v11; // xmm12_4
  float v12; // xmm10_4
  float v13; // xmm3_4
  float v14; // xmm8_4

  y = parentAabbMin->y;
  z = parentAabbMin->z;
  v9 = (float)((float)(parentAabbMax->x - parentAabbMin->x)
             * (float)((float)(unsigned __int8)this->mExtents[0] * 0.0039215689))
     + parentAabbMin->x;
  v10 = (float)((float)((float)(unsigned __int8)this->mExtents[1] * 0.0039215689) * (float)(parentAabbMax->y - y)) + y;
  v11 = (float)((float)((float)(unsigned __int8)this->mExtents[2] * 0.0039215689) * (float)(parentAabbMax->z - z)) + z;
  v12 = (float)((float)(1.0 - (float)((float)(unsigned __int8)this->mExtents[3] * 0.0039215689))
              * (float)(parentAabbMax->x - parentAabbMin->x))
      + parentAabbMin->x;
  v13 = (float)((float)(1.0 - (float)((float)(unsigned __int8)this->mExtents[4] * 0.0039215689))
              * (float)(parentAabbMax->y - y))
      + y;
  v14 = (float)((float)(1.0 - (float)((float)(unsigned __int8)this->mExtents[5] * 0.0039215689))
              * (float)(parentAabbMax->z - z))
      + z;
  if ( (this->mFlags & 1) != 0 )
  {
    leftMin->x = v9;
    rightMin->x = parentAabbMin->x;
  }
  else
  {
    rightMin->x = v9;
    leftMin->x = parentAabbMin->x;
  }
  if ( (this->mFlags & 2) != 0 )
  {
    leftMin->y = v10;
    rightMin->y = parentAabbMin->y;
  }
  else
  {
    rightMin->y = v10;
    leftMin->y = parentAabbMin->y;
  }
  if ( (this->mFlags & 4) != 0 )
  {
    leftMin->z = v11;
    rightMin->z = parentAabbMin->z;
  }
  else
  {
    rightMin->z = v11;
    leftMin->z = parentAabbMin->z;
  }
  if ( (this->mFlags & 8) != 0 )
  {
    leftMax->x = v12;
    rightMax->x = parentAabbMax->x;
  }
  else
  {
    rightMax->x = v12;
    leftMax->x = parentAabbMax->x;
  }
  if ( (this->mFlags & 0x10) != 0 )
  {
    leftMax->y = v13;
    rightMax->y = parentAabbMax->y;
  }
  else
  {
    rightMax->y = v13;
    leftMax->y = parentAabbMax->y;
  }
  if ( (this->mFlags & 0x20) != 0 )
  {
    leftMax->z = v14;
    rightMax->z = parentAabbMax->z;
  }
  else
  {
    rightMax->z = v14;
    leftMax->z = parentAabbMax->z;
  }
}

// File Line: 251
// RVA: 0xB4340
bool __fastcall UFG::ParkourContainer::TestOverlap(
        UFG::ParkourContainer *this,
        UFG::qVector3 *aabb1Min,
        UFG::qVector3 *aabb1Max,
        UFG::qVector3 *aabb2Min,
        UFG::qVector3 *aabb2Max)
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
  UFG::qResourceInventory::qResourceInventory(this, "ParkourContainerInventory", 0x15E16140u, 0xBDE53ECA, 0, 0);
  this->vfptr = (UFG::qResourceInventoryVtbl *)&UFG::ParkourContainerInventory::`vftable;
  this->mAddParkourContainerCallback = 0i64;
  this->mRemoveParkourContainerCallback = 0i64;
}

// File Line: 285
// RVA: 0x9FCE0
void __fastcall UFG::ParkourContainerInventory::Add(UFG::ParkourContainerInventory *this, UFG::ParkourContainer *res)
{
  UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *v4; // rdx
  void (__fastcall *mAddParkourContainerCallback)(UFG::ParkourContainer *); // rax

  if ( res )
  {
    UFG::qResourceData::qResourceData(res);
    res->mVertexBuffer = (UFG::qVector3 *)&res[1];
    v4 = (UFG::qNode<UFG::qResourceHandle,UFG::qResourceHandle> *)((char *)&res[1] + 12 * res->mNumVertices);
    res->mParkourData = (UFG::ParkourData *)v4;
    if ( res->mNumNodes )
      res->mNodes = (UFG::ParkourTreeNode *)((char *)v4 + 6 * res->mNumParkourData);
  }
  UFG::qResourceInventory::Add(this, res);
  mAddParkourContainerCallback = this->mAddParkourContainerCallback;
  if ( mAddParkourContainerCallback )
    mAddParkourContainerCallback(res);
}

// File Line: 300
// RVA: 0xAF550
void __fastcall UFG::ParkourContainerInventory::Remove(
        UFG::ParkourContainerInventory *this,
        UFG::ParkourContainer *resource_data)
{
  void (__fastcall *mRemoveParkourContainerCallback)(UFG::ParkourContainer *); // rax

  mRemoveParkourContainerCallback = this->mRemoveParkourContainerCallback;
  if ( mRemoveParkourContainerCallback )
    mRemoveParkourContainerCallback(resource_data);
  UFG::qResourceInventory::Remove(this, resource_data);
}

// File Line: 314
// RVA: 0x98D30
void __fastcall UFG::ParkourContainerBundleInventory::ParkourContainerBundleInventory(
        UFG::ParkourContainerBundleInventory *this)
{
  UFG::qResourceInventory::qResourceInventory(this, "ParkourContainerBundleInventory", 0x4558A12Eu, 0x12D3A53Du, 0, 0);
  this->vfptr = (UFG::qResourceInventoryVtbl *)&UFG::ParkourContainerBundleInventory::`vftable;
}

// File Line: 320
// RVA: 0x9FC40
void __fastcall UFG::ParkourContainerBundleInventory::Add(
        UFG::ParkourContainerBundleInventory *this,
        UFG::qResourceData *res)
{
  __int64 i; // rdi
  UFG::qBaseNodeRB **v5; // rdx
  UFG::qResourceData *v6; // rdx

  if ( res )
  {
    UFG::qResourceData::qResourceData(res);
    res[1].mNode.mChild[0] = (UFG::qBaseNodeRB *)&res[1].mNode.mChild[1];
    for ( i = 0i64; (unsigned int)i < LODWORD(res[1].mNode.mParent); i = (unsigned int)(i + 1) )
    {
      v5 = &res[1].mNode.mChild[0]->mParent + i;
      if ( *v5 )
        v6 = (UFG::qResourceData *)((char *)v5 + (_QWORD)*v5);
      else
        v6 = 0i64;
      UFG::gParkourContainerInventory->vfptr->Add(UFG::gParkourContainerInventory, v6);
    }
  }
  UFG::qResourceInventory::Add(this, res);
}

// File Line: 332
// RVA: 0xAF530
void __fastcall UFG::ParkourContainerBundleInventory::Remove(
        UFG::ParkourContainerBundleInventory *this,
        UFG::ParkourContainerBundle *resource_data)
{
  UFG::qResourceInventory::Remove(this, resource_data);
  UFG::ParkourContainerBundle::~ParkourContainerBundle(resource_data);
}

