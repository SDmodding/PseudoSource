// File Line: 171
// RVA: 0x380C70
char __fastcall UFG::Grid<UFG::AISidewalkEdge_Game>::Remove(UFG::Grid<UFG::AISidewalkEdge_Game> *this, UFG::AISidewalkEdge_Game *data, int index)
{
  UFG::Grid<UFG::AISidewalkEdge_Game> *v3; // rbx
  UFG::qList<UFG::qPointerNode<UFG::AISidewalkEdge_Game>,UFG::qPointerNode<UFG::AISidewalkEdge_Game>,1,0> *v4; // rax
  UFG::qList<UFG::qPointerNode<UFG::AISidewalkEdge_Game>,UFG::qPointerNode<UFG::AISidewalkEdge_Game>,1,0> *v5; // rcx
  UFG::AISidewalkEdge_Game *v6; // rdx
  _QWORD *v7; // rax
  UFG::AISidewalkEdge_Game *v8; // rdx
  _QWORD *v9; // rax

  v3 = this;
  v4 = &this->mGridNodes[index];
  v5 = (UFG::qList<UFG::qPointerNode<UFG::AISidewalkEdge_Game>,UFG::qPointerNode<UFG::AISidewalkEdge_Game>,1,0> *)v4->mNode.mPrev;
  if ( (UFG::qList<UFG::qPointerNode<UFG::AISidewalkEdge_Game>,UFG::qPointerNode<UFG::AISidewalkEdge_Game>,1,0> *)v4->mNode.mPrev == v4 )
    return 0;
  while ( (UFG::AISidewalkEdge_Game *)v5[1].mNode.mPrev != data )
  {
    v5 = (UFG::qList<UFG::qPointerNode<UFG::AISidewalkEdge_Game>,UFG::qPointerNode<UFG::AISidewalkEdge_Game>,1,0> *)v5->mNode.mPrev;
    if ( v5 == v4 )
      return 0;
  }
  v6 = (UFG::AISidewalkEdge_Game *)v5->mNode.mPrev;
  v7 = &v5->mNode.mNext->mPrev;
  v6->mpEndNodeHandle.mOffset = (__int64)v7;
  *v7 = v6;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
  v8 = (UFG::AISidewalkEdge_Game *)v5->mNode.mPrev;
  v9 = &v5->mNode.mNext->mPrev;
  v8->mpEndNodeHandle.mOffset = (__int64)v9;
  *v9 = v8;
  v5->mNode.mPrev = &v5->mNode;
  v5->mNode.mNext = &v5->mNode;
  operator delete[](v5);
  --v3->mNodeCount;
  return 1;
}

// File Line: 208
// RVA: 0x33FC90
void __fastcall UFG::Grid<UFG::AISidewalkEdge_Game>::AddAlongSegment(UFG::Grid<UFG::AISidewalkEdge_Game> *this, UFG::AISidewalkEdge_Game *data, float x0, float y0, float x1, float y1)
{
  float v6; // xmm4_4
  float v7; // xmm6_4
  UFG::RoadNetworkSegment *v8; // rbp
  UFG::Grid<UFG::RoadNetworkSegment> *v9; // rdi
  float v10; // xmm7_4
  float v11; // xmm8_4
  float v12; // xmm9_4
  signed int v13; // esi
  signed int v14; // er14
  signed int v15; // er13
  int v16; // ebx
  int v17; // er15
  int v18; // er8
  int v19; // eax
  int v20; // er8
  int v21; // edx
  signed int v22; // eax
  int v23; // esi
  float i; // xmm6_4
  signed int v25; // ebx
  int v26; // eax
  int v27; // esi
  float v28; // xmm7_4
  signed int v29; // er14
  signed int v30; // ebx

  v6 = this->mGridSizeInv;
  v7 = y1;
  v8 = (UFG::RoadNetworkSegment *)data;
  v9 = (UFG::Grid<UFG::RoadNetworkSegment> *)this;
  v10 = x1;
  v11 = y0;
  v12 = x0;
  v13 = (signed int)(float)((float)(x0 - this->mXMin) * v6);
  v14 = (signed int)(float)((float)(x1 - this->mXMin) * v6);
  v15 = (signed int)(float)((float)(y0 - this->mYMin) * v6);
  v16 = v13 + this->mXDim * v15;
  v17 = (signed int)(float)((float)(y1 - this->mYMin) * v6);
  UFG::Grid<UFG::RoadNetworkSegment>::Add(
    (UFG::Grid<UFG::RoadNetworkSegment> *)this,
    (UFG::RoadNetworkSegment *)data,
    v13 + this->mXDim * v15);
  v18 = (signed int)(float)((float)(x1 - v9->mXMin) * v9->mGridSizeInv)
      + v9->mXDim * (signed int)(float)((float)(y1 - v9->mYMin) * v9->mGridSizeInv);
  if ( v18 != v16 )
  {
    UFG::Grid<UFG::RoadNetworkSegment>::Add(v9, v8, v18);
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
          v30 = (signed int)(float)((float)((float)((float)((float)((float)((float)((float)v27 * v9->mGridSize)
                                                                          + v9->mYMin)
                                                                  - v11)
                                                          * v28)
                                                  + v12)
                                          - v9->mXMin)
                                  * v9->mGridSizeInv);
          UFG::Grid<UFG::RoadNetworkSegment>::Add(v9, v8, v30 + v9->mXDim * v29);
          UFG::Grid<UFG::RoadNetworkSegment>::Add(v9, v8, v30 + v27++ * v9->mXDim);
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
        v25 = (signed int)(float)((float)((float)((float)((float)((float)((float)((float)v23 * v9->mGridSize) + v9->mXMin)
                                                                - v12)
                                                        * i)
                                                + v11)
                                        - v9->mYMin)
                                * v9->mGridSizeInv);
        UFG::Grid<UFG::RoadNetworkSegment>::Add(v9, v8, v23 + v25 * v9->mXDim - 1);
        UFG::Grid<UFG::RoadNetworkSegment>::Add(v9, v8, v23 + v25 * v9->mXDim);
      }
    }
  }
}

// File Line: 275
// RVA: 0x380FE0
__int64 __fastcall UFG::Grid<UFG::AISidewalkEdge_Game>::RemoveAlongSegment(UFG::Grid<UFG::AISidewalkEdge_Game> *this, UFG::AISidewalkEdge_Game *data, float x0, float y0, float x1, float y1)
{
  float v6; // xmm4_4
  float v7; // xmm6_4
  UFG::AISidewalkEdge_Game *v8; // rbp
  UFG::Grid<UFG::AISidewalkEdge_Game> *v9; // rdi
  float v10; // xmm7_4
  float v11; // xmm8_4
  float v12; // xmm9_4
  signed int v13; // esi
  signed int v14; // er14
  signed int v15; // er13
  int v16; // ebx
  int v17; // er12
  unsigned __int8 v18; // r15
  int v19; // er8
  int v20; // eax
  int v21; // er8
  int v22; // edx
  signed int v23; // eax
  int v24; // esi
  float i; // xmm6_4
  signed int v26; // ebx
  int v27; // eax
  int v28; // esi
  float v29; // xmm7_4
  signed int v30; // er14
  signed int v31; // ebx

  v6 = this->mGridSizeInv;
  v7 = y1;
  v8 = data;
  v9 = this;
  v10 = x1;
  v11 = y0;
  v12 = x0;
  v13 = (signed int)(float)((float)(x0 - this->mXMin) * v6);
  v14 = (signed int)(float)((float)(x1 - this->mXMin) * v6);
  v15 = (signed int)(float)((float)(y0 - this->mYMin) * v6);
  v16 = v13 + this->mXDim * v15;
  v17 = (signed int)(float)((float)(y1 - this->mYMin) * v6);
  v18 = UFG::Grid<UFG::AISidewalkEdge_Game>::Remove(this, data, v13 + this->mXDim * v15);
  v19 = (signed int)(float)((float)(x1 - v9->mXMin) * v9->mGridSizeInv)
      + v9->mXDim * (signed int)(float)((float)(y1 - v9->mYMin) * v9->mGridSizeInv);
  if ( v19 != v16 )
  {
    UFG::Grid<UFG::AISidewalkEdge_Game>::Remove(v9, v8, v19);
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
          v31 = (signed int)(float)((float)((float)((float)((float)((float)((float)((float)v28 * v9->mGridSize)
                                                                          + v9->mYMin)
                                                                  - v11)
                                                          * v29)
                                                  + v12)
                                          - v9->mXMin)
                                  * v9->mGridSizeInv);
          UFG::Grid<UFG::AISidewalkEdge_Game>::Remove(v9, v8, v31 + v9->mXDim * v30);
          UFG::Grid<UFG::AISidewalkEdge_Game>::Remove(v9, v8, v31 + v28++ * v9->mXDim);
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
        v26 = (signed int)(float)((float)((float)((float)((float)((float)((float)((float)v24 * v9->mGridSize) + v9->mXMin)
                                                                - v12)
                                                        * i)
                                                + v11)
                                        - v9->mYMin)
                                * v9->mGridSizeInv);
        UFG::Grid<UFG::AISidewalkEdge_Game>::Remove(v9, v8, v24 + v26 * v9->mXDim - 1);
        UFG::Grid<UFG::AISidewalkEdge_Game>::Remove(v9, v8, v24 + v26 * v9->mXDim);
      }
    }
  }
  return v18;
}

