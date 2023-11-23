// File Line: 171
// RVA: 0x380C70
char __fastcall UFG::Grid<UFG::AISidewalkEdge_Game>::Remove(
        UFG::Grid<UFG::AISidewalkEdge_Game> *this,
        UFG::AISidewalkEdge_Game *data,
        int index)
{
  UFG::qList<UFG::qPointerNode<UFG::AISidewalkEdge_Game>,UFG::qPointerNode<UFG::AISidewalkEdge_Game>,1,0> *v4; // rax
  UFG::qList<UFG::qPointerNode<UFG::AISidewalkEdge_Game>,UFG::qPointerNode<UFG::AISidewalkEdge_Game>,1,0> *mPrev; // rcx
  UFG::AISidewalkEdge_Game *v6; // rdx
  _QWORD *p_mPrev; // rax
  UFG::AISidewalkEdge_Game *v8; // rdx
  _QWORD *v9; // rax

  v4 = &this->mGridNodes[index];
  mPrev = (UFG::qList<UFG::qPointerNode<UFG::AISidewalkEdge_Game>,UFG::qPointerNode<UFG::AISidewalkEdge_Game>,1,0> *)v4->mNode.mPrev;
  if ( (UFG::qList<UFG::qPointerNode<UFG::AISidewalkEdge_Game>,UFG::qPointerNode<UFG::AISidewalkEdge_Game>,1,0> *)v4->mNode.mPrev == v4 )
    return 0;
  while ( (UFG::AISidewalkEdge_Game *)mPrev[1].mNode.mPrev != data )
  {
    mPrev = (UFG::qList<UFG::qPointerNode<UFG::AISidewalkEdge_Game>,UFG::qPointerNode<UFG::AISidewalkEdge_Game>,1,0> *)mPrev->mNode.mPrev;
    if ( mPrev == v4 )
      return 0;
  }
  v6 = (UFG::AISidewalkEdge_Game *)mPrev->mNode.mPrev;
  p_mPrev = &mPrev->mNode.mNext->mPrev;
  v6->mpEndNodeHandle.mOffset = (__int64)p_mPrev;
  *p_mPrev = v6;
  mPrev->mNode.mPrev = &mPrev->mNode;
  mPrev->mNode.mNext = &mPrev->mNode;
  v8 = (UFG::AISidewalkEdge_Game *)mPrev->mNode.mPrev;
  v9 = &mPrev->mNode.mNext->mPrev;
  v8->mpEndNodeHandle.mOffset = (__int64)v9;
  *v9 = v8;
  mPrev->mNode.mPrev = &mPrev->mNode;
  mPrev->mNode.mNext = &mPrev->mNode;
  operator delete[](mPrev);
  --this->mNodeCount;
  return 1;
}

// File Line: 208
// RVA: 0x33FC90
void __fastcall UFG::Grid<UFG::AISidewalkEdge_Game>::AddAlongSegment(
        UFG::Grid<UFG::AISidewalkEdge_Game> *this,
        UFG::RoadNetworkSegment *data,
        float x0,
        float y0,
        float x1,
        float y1)
{
  float mGridSizeInv; // xmm4_4
  float v7; // xmm6_4
  float v10; // xmm7_4
  float v11; // xmm8_4
  float v12; // xmm9_4
  int v13; // esi
  int v14; // r14d
  int v15; // r13d
  unsigned int v16; // ebx
  int v17; // r15d
  unsigned int v18; // r8d
  int v19; // eax
  int v20; // r8d
  int v21; // edx
  int v22; // eax
  int v23; // esi
  float i; // xmm6_4
  int v25; // ebx
  int v26; // eax
  int v27; // esi
  float v28; // xmm7_4
  int v29; // r14d
  int v30; // ebx

  mGridSizeInv = this->mGridSizeInv;
  v7 = y1;
  v10 = x1;
  v11 = y0;
  v12 = x0;
  v13 = (int)(float)((float)(x0 - this->mXMin) * mGridSizeInv);
  v14 = (int)(float)((float)(x1 - this->mXMin) * mGridSizeInv);
  v15 = (int)(float)((float)(y0 - this->mYMin) * mGridSizeInv);
  v16 = v13 + this->mXDim * v15;
  v17 = (int)(float)((float)(y1 - this->mYMin) * mGridSizeInv);
  UFG::Grid<UFG::RoadNetworkSegment>::Add((UFG::Grid<UFG::RoadNetworkSegment> *)this, data, v16);
  v18 = (int)(float)((float)(x1 - this->mXMin) * this->mGridSizeInv)
      + this->mXDim * (int)(float)((float)(y1 - this->mYMin) * this->mGridSizeInv);
  if ( v18 != v16 )
  {
    UFG::Grid<UFG::RoadNetworkSegment>::Add((UFG::Grid<UFG::RoadNetworkSegment> *)this, data, v18);
    v19 = v17 - v15;
    v20 = v14 - v13;
    if ( v14 - v13 < 0 )
      v20 = v13 - v14;
    v21 = v17 - v15;
    if ( v19 < 0 )
      v21 = v15 - v17;
    if ( v20 <= v21 )
    {
      if ( v19 < 0 )
      {
        v26 = v15;
        v15 = v17;
        v17 = v26;
        v10 = x0;
        v7 = y0;
        v12 = x1;
        v11 = y1;
      }
      v27 = v15 + 1;
      v28 = (float)(v10 - v12) / (float)(v7 - v11);
      if ( v15 + 1 <= v17 )
      {
        v29 = v15;
        do
        {
          v30 = (int)(float)((float)((float)((float)((float)((float)((float)((float)v27 * this->mGridSize) + this->mYMin)
                                                           - v11)
                                                   * v28)
                                           + v12)
                                   - this->mXMin)
                           * this->mGridSizeInv);
          UFG::Grid<UFG::RoadNetworkSegment>::Add(
            (UFG::Grid<UFG::RoadNetworkSegment> *)this,
            data,
            v30 + this->mXDim * v29);
          UFG::Grid<UFG::RoadNetworkSegment>::Add(
            (UFG::Grid<UFG::RoadNetworkSegment> *)this,
            data,
            v30 + v27 * this->mXDim);
          ++v27;
          ++v29;
        }
        while ( v27 <= v17 );
      }
    }
    else
    {
      if ( v14 - v13 < 0 )
      {
        v22 = v13;
        v13 = v14;
        v14 = v22;
        v10 = x0;
        v7 = y0;
        v12 = x1;
        v11 = y1;
      }
      v23 = v13 + 1;
      for ( i = (float)(v7 - v11) / (float)(v10 - v12); v23 <= v14; ++v23 )
      {
        v25 = (int)(float)((float)((float)((float)((float)((float)((float)((float)v23 * this->mGridSize) + this->mXMin)
                                                         - v12)
                                                 * i)
                                         + v11)
                                 - this->mYMin)
                         * this->mGridSizeInv);
        UFG::Grid<UFG::RoadNetworkSegment>::Add(
          (UFG::Grid<UFG::RoadNetworkSegment> *)this,
          data,
          v23 + v25 * this->mXDim - 1);
        UFG::Grid<UFG::RoadNetworkSegment>::Add(
          (UFG::Grid<UFG::RoadNetworkSegment> *)this,
          data,
          v23 + v25 * this->mXDim);
      }
    }
  }
}

// File Line: 275
// RVA: 0x380FE0
__int64 __fastcall UFG::Grid<UFG::AISidewalkEdge_Game>::RemoveAlongSegment(
        UFG::Grid<UFG::AISidewalkEdge_Game> *this,
        UFG::AISidewalkEdge_Game *data,
        float x0,
        float y0,
        float x1,
        float y1)
{
  float mGridSizeInv; // xmm4_4
  float v7; // xmm6_4
  float v10; // xmm7_4
  float v11; // xmm8_4
  float v12; // xmm9_4
  int v13; // esi
  int v14; // r14d
  int v15; // r13d
  int v16; // ebx
  int v17; // r12d
  unsigned __int8 v18; // r15
  int v19; // r8d
  int v20; // eax
  int v21; // r8d
  int v22; // edx
  int v23; // eax
  int v24; // esi
  float i; // xmm6_4
  int v26; // ebx
  int v27; // eax
  int v28; // esi
  float v29; // xmm7_4
  int v30; // r14d
  int v31; // ebx

  mGridSizeInv = this->mGridSizeInv;
  v7 = y1;
  v10 = x1;
  v11 = y0;
  v12 = x0;
  v13 = (int)(float)((float)(x0 - this->mXMin) * mGridSizeInv);
  v14 = (int)(float)((float)(x1 - this->mXMin) * mGridSizeInv);
  v15 = (int)(float)((float)(y0 - this->mYMin) * mGridSizeInv);
  v16 = v13 + this->mXDim * v15;
  v17 = (int)(float)((float)(y1 - this->mYMin) * mGridSizeInv);
  v18 = UFG::Grid<UFG::AISidewalkEdge_Game>::Remove(this, data, v16);
  v19 = (int)(float)((float)(x1 - this->mXMin) * this->mGridSizeInv)
      + this->mXDim * (int)(float)((float)(y1 - this->mYMin) * this->mGridSizeInv);
  if ( v19 != v16 )
  {
    UFG::Grid<UFG::AISidewalkEdge_Game>::Remove(this, data, v19);
    v20 = v17 - v15;
    v21 = v14 - v13;
    if ( v14 - v13 < 0 )
      v21 = v13 - v14;
    v22 = v17 - v15;
    if ( v20 < 0 )
      v22 = v15 - v17;
    if ( v21 <= v22 )
    {
      if ( v20 < 0 )
      {
        v27 = v15;
        v15 = v17;
        v17 = v27;
        v10 = x0;
        v7 = y0;
        v12 = x1;
        v11 = y1;
      }
      v28 = v15 + 1;
      v29 = (float)(v10 - v12) / (float)(v7 - v11);
      if ( v15 + 1 <= v17 )
      {
        v30 = v15;
        do
        {
          v31 = (int)(float)((float)((float)((float)((float)((float)((float)((float)v28 * this->mGridSize) + this->mYMin)
                                                           - v11)
                                                   * v29)
                                           + v12)
                                   - this->mXMin)
                           * this->mGridSizeInv);
          UFG::Grid<UFG::AISidewalkEdge_Game>::Remove(this, data, v31 + this->mXDim * v30);
          UFG::Grid<UFG::AISidewalkEdge_Game>::Remove(this, data, v31 + v28 * this->mXDim);
          ++v28;
          ++v30;
        }
        while ( v28 <= v17 );
      }
    }
    else
    {
      if ( v14 - v13 < 0 )
      {
        v23 = v13;
        v13 = v14;
        v14 = v23;
        v10 = x0;
        v7 = y0;
        v12 = x1;
        v11 = y1;
      }
      v24 = v13 + 1;
      for ( i = (float)(v7 - v11) / (float)(v10 - v12); v24 <= v14; ++v24 )
      {
        v26 = (int)(float)((float)((float)((float)((float)((float)((float)((float)v24 * this->mGridSize) + this->mXMin)
                                                         - v12)
                                                 * i)
                                         + v11)
                                 - this->mYMin)
                         * this->mGridSizeInv);
        UFG::Grid<UFG::AISidewalkEdge_Game>::Remove(this, data, v24 + v26 * this->mXDim - 1);
        UFG::Grid<UFG::AISidewalkEdge_Game>::Remove(this, data, v24 + v26 * this->mXDim);
      }
    }
  }
  return v18;
}

